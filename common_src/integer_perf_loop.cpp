#include <cassert>
#include <cmath>
#include <cstdint>

extern "C" {
#include "integer_perf_loop.h"
}
#include "systick_util.h"

extern "C" {
uint64_t u64_external_result = 0; // To prevent gcc from optimizing away
                                  // unused result.

// Run computation for a few seconds in a tight loop.
// Report diff of Cortex-M systicks before and after loop.
uint32_t integer_perf_loop(uint32_t arr1[], uint32_t arr2[])
{
    uint64_t result = 0;
    systick_setup();

    uint32_t start_timer = systick_microseconds();
    const int kIterations = kArrSz;
    for (int i = 0; i < kIterations; i++) {
        result += arr1[i]*arr2[i];
    }
    u64_external_result = result;
    uint32_t end_timer = systick_microseconds();

    return (uint32_t)(end_timer - start_timer);
}
}
