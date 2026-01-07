#include "bsp_clock_cfg.h"

void SysTick_Handler(void);

// Must be called before using systick_millis().
void systick_setup(void);

// Return monotonic clock, milliseconds.
uint32_t systick_millis(void);
