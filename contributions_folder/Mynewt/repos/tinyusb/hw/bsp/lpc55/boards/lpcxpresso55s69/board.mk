# Lines added by author
MCU_VARIANT = LPC55S69
MCU_CORE = LPC55S69_cm33_core0
PORT ?= 1

CFLAGS += -DCPU_LPC55S69JBD100_cm33_core0

JLINK_DEVICE = LPC55S69
PYOCD_TARGET = LPC55S69

# flash using pyocd
flash: flash-pyocd
