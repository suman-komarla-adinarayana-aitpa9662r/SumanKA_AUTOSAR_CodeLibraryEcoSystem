
# ARCH defines
ARCH=mpc5xxx
ARCH_FAM=ppc

# CFG (y/n) macros
CFG+=PPC E200Z0 MPC55XX MPC560X MPC560XB MPC5606B MPC5607B BRD_MPC5606B_XPC560B
CFG+=MCU_ARC_CONFIG
CFG+=CREATE_SREC
CFG+=VLE
CFG+=TIMER
CFG+=TIMER_RTC
#CFG+=MCU_ARC_LP
CFG+=OS_SYSTICK2

# What buildable modules does this board have, 
# default or private

# Memory + Peripherals
# MCAL
MOD_AVAIL+=ADC DIO DMA CAN GPT LIN MCU PORT PWM WDG SPI OCU ICU FLS
# Required modules
MOD_USE += MCU KERNEL 

# Default cross compiler
COMPILER?=gcc
# Default cross compiler
COMPILER_FLAVOR=s32_newlib
DEFAULT_CROSS_COMPILE = /c/devtools/Freescale/S32DS_Power_v2017.R1/Cross_Tools/powerpc-eabivle-4_9/bin/powerpc-eabivle-
DEFAULT_CW_COMPILE= /c/devtools/Freescale/cw_mpc5xxx_2.10
DEFAULT_DIAB_COMPILE = /c/devtools/WindRiver/diab/5.9.4.8/WIN32
DEFAULT_GHS_COMPILE = /c/devtools/ghs/comp_201314p

# Defines
def-y += __BIG_ENDIAN__
def-y += SRAM_SIZE=0x18000

# Software floating point, PowerPC No Small-Data ELF EABI Object Format
DIAB_TARGET?=-tPPCE200Z0VFS:simple
GHS_TARGET?=ppc560xb
