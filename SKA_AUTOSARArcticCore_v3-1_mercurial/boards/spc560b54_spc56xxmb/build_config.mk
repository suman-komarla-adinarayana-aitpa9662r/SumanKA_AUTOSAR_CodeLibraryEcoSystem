
# ARCH defines
ARCH=mpc5xxx
ARCH_FAM=ppc

# CFG (y/n) macros
CFG=PPC E200Z0 MPC55XX MPC560X MPC560XB SPC560B54 BRD_SPC560B54_SPC56XXMB
CFG+=MCU_ARC_CONFIG
CFG+=CREATE_SREC
CFG+=VLE


# What buildable modules does this board have, 
# default or private

# MCAL
MOD_AVAIL+=ADC DIO DMA CAN GPT LIN MCU PORT PWM WDG FLS SPI
# Required modules
MOD_USE += MCU KERNEL

# Default cross compiler
COMPILER?=cw
# Default cross compiler
COMPILER_FLAVOR=s32_newlib
DEFAULT_CROSS_COMPILE = /c/devtools/Freescale/S32DS_Power_v2017.R1/Cross_Tools/powerpc-eabivle-4_9/bin/powerpc-eabivle-
DEFAULT_CW_COMPILE= /c/devtools/Freescale/cw_mpc5xxx_2.10
DEFAULT_DIAB_COMPILE = /c/devtools/WindRiver/diab/5.9.3.0/WIN32
DEFAULT_GHS_COMPILE = /c/devtools/ghs/comp_201314p

# Defines
def-y += SRAM_SIZE=0x10000

# Software floating point, PowerPC No Small-Data ELF EABI Object Format
DIAB_TARGET?=-tPPCE200Z0VFS:simple
GHS_TARGET?=ppc560xb

