#ifdef __cplusplus
extern "C" {
#endif
#define kArrSz 10000
#ifdef __IAR_SYSTEMS_ICC__
#define IAR_NO_INIT __no_init
#else
#define IAR_NO_INIT
#endif
extern uint64_t u64_external_result;
uint32_t integer_perf_loop_add_vectors(
    const uint32_t arr1[], const uint32_t arr2[], uint32_t result[]);
uint32_t integer_perf_loop_add_vectors_unrolled(
    const uint32_t arr1[], const uint32_t arr2[], uint32_t result[]);
#ifdef __cplusplus
}
#endif
