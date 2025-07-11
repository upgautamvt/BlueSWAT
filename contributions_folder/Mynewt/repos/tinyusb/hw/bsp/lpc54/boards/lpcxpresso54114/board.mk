# Lines added by author
MCU_VARIANT = LPC54114
MCU_CORE = LPC54114_cm4

CFLAGS += -DCPU_LPC54114J256BD64_cm4
LD_FILE = $(MCU_DIR)/gcc/LPC54114J256_cm4_flash.ld

LIBS += $(TOP)/$(MCU_DIR)/gcc/libpower_cm4_hardabi.a

JLINK_DEVICE = LPC54114J256_M4
PYOCD_TARGET = LPC54114

# flash using pyocd
flash: flash-pyocd
