# Lines added by author
CFLAGS += -DSTM32H743xx -DHSE_VALUE=8000000

# Default is HS port
PORT ?= 1

# Use Timer module for ULPI PHY reset
CFLAGS += -DHAL_TIM_MODULE_ENABLED
SRC_C += \
  $(ST_HAL_DRIVER)/Src/stm32$(ST_FAMILY)xx_hal_tim.c \
  $(ST_HAL_DRIVER)/Src/stm32$(ST_FAMILY)xx_hal_tim_ex.c

# GCC
GCC_SRC_S += $(ST_CMSIS)/Source/Templates/gcc/startup_stm32h743xx.s
GCC_LD_FILE = $(BOARD_PATH)/STM32H743IITX_FLASH.ld

# IAR
IAR_SRC_S += $(ST_CMSIS)/Source/Templates/iar/startup_stm32h743xx.s
IAR_LD_FILE = $(ST_CMSIS)/Source/Templates/iar/linker/stm32h743xx_flash.icf

# For flash-jlink target
JLINK_DEVICE = stm32h743ii

# flash target using jlink
flash: flash-jlink
