# Lines added by author
CFLAGS += -DSTM32F411xE

# GCC
GCC_SRC_S += $(ST_CMSIS)/Source/Templates/gcc/startup_stm32f411xe.s
GCC_LD_FILE = $(BOARD_PATH)/STM32F411VETx_FLASH.ld

# IAR
IAR_SRC_S += $(ST_CMSIS)/Source/Templates/iar/startup_stm32f411xe.s
IAR_LD_FILE = $(ST_CMSIS)/Source/Templates/iar/linker/stm32f411xe_flash.icf

# For flash-jlink target
JLINK_DEVICE = stm32f411ve

# flash target using on-board stlink
flash: flash-stlink
