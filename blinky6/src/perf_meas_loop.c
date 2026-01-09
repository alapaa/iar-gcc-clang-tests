#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include "perf_meas_loop.h"
#include "systick_util.h"

double function_using_fpu(double random_arg)
{
    double my_constant = random_arg * 100.0/70.0;
    return sin(random_arg+my_constant); // sin() returns a double. sinf()
                                        // returns float.
}

// Run computation for a few seconds in a tight loop.
// Report diff of Cortex MCU timer register before and after loop.
uint32_t perf_loop(double random_arg)
{
    systick_setup();

//    srand(37); // Seed the random number generator
//    double random_arg = rand()*2*M_PI/RAND_MAX;
    double result = function_using_fpu(random_arg);

    // documentation
    // ra/e2studio_v2025-10_fsp_v6.2.0/fsp_documentation/v6.2.0/fsp_user_manual_v6.2.0/index.html

    volatile uint32_t start_timer = systick_millis(); // Read timer value (processor time)
    const int kIterations = 300000; // To be adjusted.
    for (int i = 0; i < kIterations; i++) {
        result = function_using_fpu(result);
    }
    volatile uint32_t end_timer = systick_millis(); // Read timer value

    assert(end_timer >= start_timer);

    return (uint32_t)(end_timer - start_timer);
}
