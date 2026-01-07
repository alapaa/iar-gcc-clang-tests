#include <stdint.h>

#include "bsp_api.h"
#include "systick_util.h"

static uint32_t tick;

void SysTick_Handler(void)
{
    tick++;
}

void systick_setup(void)
{
    SysTick_Config(SystemCoreClock / 1000); // 1000 is the number of ticks per
                                            // second

    NVIC_SetPriority(SysTick_IRQn, 0); // Set User configured Priority for
                                       // Systick Interrupt, 0 is the interrupt
                                       // priority
}

// Monotonic count of milliseconds
uint32_t systick_millis(void)
{
    return tick;
}
