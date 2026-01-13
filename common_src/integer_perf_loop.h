#ifdef __cplusplus
extern "C" {
#endif
#define kArrSz 10000
extern uint64_t u64_external_result;
uint32_t integer_perf_loop(uint32_t arr1[], uint32_t arr2[]);
uint32_t integer_perf_loop_add_vectors(
    const uint32_t arr1[], const uint32_t arr2[], uint32_t result[]);
#ifdef __cplusplus
}
#endif
