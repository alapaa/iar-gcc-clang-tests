#include <cassert>
#include <cmath>
#include <cstdint>

extern "C" {
#include "perf_meas_loop.h"
}
#include "systick_util.h"

namespace {
double function_using_fpu(double random_arg)
{
    double my_constant = random_arg * 100.0/70.0;
    return sin(random_arg+my_constant); // sin() returns a double. sinf()
                                        // returns float.
}
}

extern "C" {
    double external_result = 0.0; // To prevent gcc from optimizing away unused
                                  // result.

// Run computation for a few seconds in a tight loop.
// Report diff of Cortex-M systicks before and after loop.
uint32_t perf_loop(double random_arg)
{
    systick_setup();

    double result = function_using_fpu(random_arg);

    uint32_t start_timer = systick_microseconds();
    const int kIterations = 100000; // To be adjusted.
    for (int i = 0; i < kIterations; i++) {
        result = function_using_fpu(result);
    }
    external_result = result;
    uint32_t end_timer = systick_microseconds();

    return (uint32_t)(end_timer - start_timer);
}
}
