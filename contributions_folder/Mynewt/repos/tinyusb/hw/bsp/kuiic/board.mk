# Lines added by author
SDK_DIR = hw/mcu/nxp/mcux-sdk
DEPS_SUBMODULES += $(SDK_DIR) tools/uf2

# This board uses TinyUF2 for updates
UF2_FAMILY_ID = 0x7f83e793

CFLAGS += \
  -mthumb \
  -mabi=aapcs \
  -mcpu=cortex-m0plus \
  -DCPU_K32L2B31VLH0A \
  -DCFG_TUSB_MCU=OPT_MCU_K32L2BXX

# mcu driver cause following warnings
CFLAGS += -Wno-error=unused-parameter

MCU_DIR = $(SDK_DIR)/devices/K32L2B31A

# All source paths should be relative to the top level.
LD_FILE = /hw/bsp/$(BOARD)/K32L2B31xxxxA_flash.ld

SRC_C += \
	src/portable/nxp/khci/dcd_khci.c \
	$(MCU_DIR)/system_K32L2B31A.c \
	$(MCU_DIR)/drivers/fsl_clock.c \
	$(SDK_DIR)/drivers/gpio/fsl_gpio.c \
	$(SDK_DIR)/drivers/lpuart/fsl_lpuart.c

INC += \
	$(TOP)/hw/bsp/$(BOARD) \
	$(TOP)/$(SDK_DIR)/CMSIS/Include \
	$(TOP)/$(SDK_DIR)/drivers/smc \
	$(TOP)/$(SDK_DIR)/drivers/common \
	$(TOP)/$(SDK_DIR)/drivers/gpio \
	$(TOP)/$(SDK_DIR)/drivers/port \
	$(TOP)/$(SDK_DIR)/drivers/lpuart \
	$(TOP)/$(MCU_DIR) \
	$(TOP)/$(MCU_DIR)/drivers 

SRC_S += $(MCU_DIR)/gcc/startup_K32L2B31A.S

# For freeRTOS port source
FREERTOS_PORT = ARM_CM0

# For flash-jlink target
JLINK_DEVICE = MKL25Z128xxx4

# For flash-pyocd target
PYOCD_TARGET = K32L2B

# flash using pyocd
flash: flash-pyocd
