Performance and code size tests of embedded ARM Cortex-M microcontroller
compilers.

Also, I recommend using the EEBMC site for a database of certified embedded
compiler comparisons, https://www.eembc.org/.

Below, we show the Clang project configuration in Renesas e2studio (Renesas
FSP). The board used for the tests was Renesas RA6E1, which is based on the ARM
Cortex-M33 microcontroller.

Project Summary


Board:  	FPB-RA6E1
Device:  	R7FA6E10F2CFP
Core:  	CM33
Toolchain:  	LLVM for ARM
Toolchain Version:  	18.1.3
FSP Version:  	6.2.0
Project Type:  	Flat
Location:  	${HOME}/e2_studio/workspace/clang_performance_test1

Selected software components

    Arm CMSIS Version 6 - Core (M)  	v6.1.0+fsp.6.2.0
    RA6E1-FPB Board Support Files  	v6.2.0
    Board support package for RA6E1  	v6.2.0
    Board support package for R7FA6E10F2CFP  	v6.2.0
    Board support package for RA6E1 - Events  	v6.2.0
    Board support package for RA6E1 - FSP Data  	v6.2.0
    Board support package for RA6E1 - Linker  	v6.2.0
    Board Support Package Common Files  	v6.2.0
    I/O Port  	v6.2.0
    Simple application that blinks an LED. No RTOS included.  	v6.2.0
    Common source for all template projects.  	v6.2.0
