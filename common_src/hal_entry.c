/*
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hal_data.h"
#include "perf_meas_loop.h"
#include "integer_perf_loop.h"

extern bsp_leds_t g_bsp_leds;
volatile uint32_t nr_clocks = 0xFFFFAAAA;
//volatile uint64_t result_from_integer_loop = 0xDEADBEEFDEADBEEF;
IAR_NO_INIT uint32_t arr1[kArrSz];
IAR_NO_INIT uint32_t arr2[kArrSz];
IAR_NO_INIT uint32_t result_arr[kArrSz];

/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 *
 **********************************************************************************************************************/
void hal_entry (void)
{
#if BSP_TZ_SECURE_BUILD

    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif

    /* Define the units to be used with the software delay function */
    const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;

    /* Set the blink frequency (must be <= bsp_delay_units / 2) */
    const uint32_t freq_in_hz = 1;

    /* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units / (freq_in_hz * 2);

    /* LED type structure */
    bsp_leds_t leds = g_bsp_leds;

    /* Wake up 2nd core if this is first core and we are inside a multicore project. */
#if (0 == _RA_CORE) && (1 == BSP_MULTICORE_PROJECT) && !BSP_TZ_NONSECURE_BUILD
    R_BSP_SecondaryCoreStart();
#endif

    /* If this board has no LEDs then trap here */
    if (0 == leds.led_count)
    {
        while (1)
        {
            ;                          // There are no LEDs on this board
        }
    }

    /* Holds level to set for pins */

    bsp_io_level_t pin_level = BSP_IO_LEVEL_LOW;


//    volatile double foo = 1234.5678;
//    nr_clocks = perf_loop(foo); // Execute perf loop, measure time.
    for (int i = 0; i < kArrSz; i++) {
        arr1[i] = (uint32_t)i;
        arr2[i] = 2*(uint32_t)i;
    }
    //nr_clocks = integer_perf_loop(arr1, arr2);
    nr_clocks = integer_perf_loop_add_vectors(arr1, arr2, result_arr);
    //assert(nr_clocks != 0);

    while (1)
    {
        /* Enable access to the PFS registers. If using r_ioport module then register protection is automatically
         * handled. This code uses BSP IO functions to show how it is used.
         */
        R_BSP_PinAccessEnable();

#if BSP_NUMBER_OF_CORES == 1

        /* Update all board LEDs */
        for (uint32_t i = 0; i < leds.led_count; i++)
        {
            /* Get pin to toggle */
            uint32_t pin = leds.p_leds[i];

            /* Write to this pin */
            R_BSP_PinWrite((bsp_io_port_pin_t) pin, pin_level);
        }
#else

        /* Update LED that is at the index of this core. */
        R_BSP_PinWrite((bsp_io_port_pin_t) leds.p_leds[_RA_CORE], pin_level);
#endif

        /* Protect PFS registers */
        R_BSP_PinAccessDisable();

        /* Toggle level for next write */
        if (BSP_IO_LEVEL_LOW == pin_level)
        {
            pin_level = BSP_IO_LEVEL_HIGH;
        }
        else
        {
            pin_level = BSP_IO_LEVEL_LOW;
        }

        /* Delay */
        R_BSP_SoftwareDelay(delay, bsp_delay_units);
    }
}
