#!/bin/bash
echo "--------- Current commit:"
git log | head -n 6

CC=/home/alapaa/renesas/ra/e2studio_v2025-10_fsp_v6.2.0/toolchains/gcc_arm/arm-gnu-toolchain-13.2.Rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc
echo "Using compiler: "${CC}

PROJDIR=test1_cpp
OUTPUTDIR=/tmp
FILE_NAME_BASE=perf_meas_loop.assemblyoutput
O_0_FILE=${OUTPUTDIR}/${FILE_NAME_BASE}-O0.S
O_s_FILE=${OUTPUTDIR}/${FILE_NAME_BASE}-Os.S
O_2_FILE=${OUTPUTDIR}/${FILE_NAME_BASE}-O2.S

echo "Creating assembler output..."
$CC -I ../${PROJDIR}/ra_gen/  -O0 -fverbose-asm -S perf_meas_loop.cpp -o ${O_0_FILE}
$CC -I ../${PROJDIR}/ra_gen/  -Os -fverbose-asm -S perf_meas_loop.cpp -o ${O_s_FILE}
$CC -I ../${PROJDIR}/ra_gen/  -O2 -fverbose-asm -S perf_meas_loop.cpp -o ${O_2_FILE}
echo "Done!"

echo "Function calls in O0:"
echo egrep "^\s+bl\s+" ${O_0_FILE}
egrep "^\s+bl\s+" ${O_0_FILE}

echo
echo "Function calls in Os:"
echo egrep "^\s+bl\s+" ${O_s_FILE}
egrep "^\s+bl\s+" ${O_s_FILE}

echo
echo "Function calls in O2:"
echo egrep "^\s+bl\s+" ${O_2_FILE}
egrep "^\s+bl\s+" ${O_2_FILE}
