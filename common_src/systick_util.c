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
    const uint32_t ONE_MILLION = 1000000;
    const uint32_t HUNDRED_THOUSAND = 100000;
    const uint32_t reload_val = SystemCoreClock; // 200E6 on RA6E1.
    result = SysTick_Config(reload_val/ONE_MILLION); // The fcn argument is the number
                                         // of ticks between two interrupts.
                                         // See https://arm-software.github.io/CMSIS_5/Core/html/group__SysTick__gr.html

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
