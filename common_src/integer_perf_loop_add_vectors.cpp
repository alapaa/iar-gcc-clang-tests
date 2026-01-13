#include <cassert>
#include <cmath>
#include <cstdint>

extern "C" {
#include "integer_perf_loop.h"
}
#include "systick_util.h"

extern "C" {
// Run computation for a few seconds in a tight loop.
// Report diff of Cortex-M systicks before and after loop.
uint32_t integer_perf_loop_add_vectors(
    const uint32_t arr1[], const uint32_t arr2[], uint32_t result[])
{
    systick_setup();

    uint32_t start_timer = systick_microseconds();
    const int kIterations = 100000; // To be adjusted.
    for (int i = 0; i < kIterations; i++) {
        result[i] = arr1[i]+arr2[i];
    }
    uint32_t end_timer = systick_microseconds();

    return (uint32_t)(end_timer - start_timer);
}
}
