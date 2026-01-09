#!/bin/bash

/home/alapaa/renesas/ra/e2studio_v2025-10_fsp_v6.2.0/toolchains/gcc_arm/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc -I ./ra_gen/  -O0 -fverbose-asm -S src/perf_meas_loop.c -o /tmp/perf_meas_loop.assemblyoutput_mine.O0
/home/alapaa/renesas/ra/e2studio_v2025-10_fsp_v6.2.0/toolchains/gcc_arm/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc -I ./ra_gen/  -Os -fverbose-asm -S src/perf_meas_loop.c -o /tmp/perf_meas_loop.assemblyoutput_mine.Os
/home/alapaa/renesas/ra/e2studio_v2025-10_fsp_v6.2.0/toolchains/gcc_arm/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc -I ./ra_gen/  -O2 -fverbose-asm -S src/perf_meas_loop.c -o /tmp/perf_meas_loop.assemblyoutput_mine.O2
