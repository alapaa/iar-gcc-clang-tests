#include "bsp_clock_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

void SysTick_Handler(void);

// Must be called before using systick_millis().
void systick_setup();

// Return monotonic clock, milliseconds.
uint32_t systick_millis();

// Return monotonic clock, microseconds.
uint32_t systick_microseconds();
#ifdef __cplusplus
}
#endif
