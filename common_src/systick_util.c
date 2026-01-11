#include <assert.h>
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
    uint32_t result;
    const uint32_t reload_val = 0x00FFFFFF;
    result = SysTick_Config(reload_val);
//    result = SysTick_Config(SystemCoreClock); // 1000 is the number of ticks
//                                              // per second

    assert(result == 0);

    NVIC_SetPriority(SysTick_IRQn, 0); // Set User configured Priority for
                                       // Systick Interrupt, 0 is the interrupt
                                       // priority
}

// Monotonic count of milliseconds
uint32_t systick_millis(void)
{
    return tick/1000;
}

uint32_t systick_microseconds(void)
{
    return tick;
}
