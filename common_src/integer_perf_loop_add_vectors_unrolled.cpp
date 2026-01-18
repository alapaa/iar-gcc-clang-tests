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
uint32_t integer_perf_loop_add_vectors_unrolled(
    const uint32_t arr1[], const uint32_t arr2[], uint32_t result[])
{
    systick_setup();

    uint32_t start_timer = systick_microseconds();
    const int kIterations = kArrSz;
    for (int i = 0; i < kIterations; i += 4) {
        result[i] = arr1[i]+arr2[i];
        result[i+1] = arr1[i+1]+arr2[i+1];
        result[i+2] = arr1[i+2]+arr2[i+2];
        result[i+3] = arr1[i+3]+arr2[i+3];
    }
    uint32_t end_timer = systick_microseconds();

    return (uint32_t)(end_timer - start_timer);
}
}
