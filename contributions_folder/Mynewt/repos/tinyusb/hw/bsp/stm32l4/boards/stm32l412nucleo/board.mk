# Lines added by author
CFLAGS += \
  -DSTM32L412xx \

# GCC
GCC_SRC_S += $(ST_CMSIS)/Source/Templates/gcc/startup_stm32l412xx.s
GCC_LD_FILE = $(BOARD_PATH)/STM32L412KBUx_FLASH.ld

# IAR
IAR_SRC_S += $(ST_CMSIS)/Source/Templates/iar/startup_stm32l412xx.s
IAR_LD_FILE = $(ST_CMSIS)/Source/Templates/iar/linker/stm32l412xx_flash.icf

# For flash-jlink target
JLINK_DEVICE = stm32l412kb
