# Lines added by author
DEPS_SUBMODULES += lib/FreeRTOS-Kernel

include ../../../tools/top.mk
include ../../make.mk

FREERTOS_SRC = lib/FreeRTOS-Kernel
FREERTOS_PORTABLE_SRC= $(FREERTOS_SRC)/portable/$(if $(USE_IAR),IAR,GCC)/$(FREERTOS_PORT)

INC += \
	src \
	src/FreeRTOSConfig \
	$(TOP)/hw \
	$(TOP)/$(FREERTOS_SRC)/include \
	$(TOP)/$(FREERTOS_PORTABLE_SRC)
	
# Example source
EXAMPLE_SOURCE = \
	src/freertos_hook.c \
	src/main.c \
	src/msc_disk.c \
	src/usb_descriptors.c

SRC_C += $(addprefix $(CURRENT_PATH)/, $(EXAMPLE_SOURCE))

# FreeRTOS source, all files in port folder
SRC_C += \
	$(FREERTOS_SRC)/list.c \
	$(FREERTOS_SRC)/queue.c \
	$(FREERTOS_SRC)/tasks.c \
	$(FREERTOS_SRC)/timers.c \
	$(subst ../../../,,$(wildcard ../../../$(FREERTOS_PORTABLE_SRC)/*.c))

SRC_S += \
	$(subst ../../../,,$(wildcard ../../../$(FREERTOS_PORTABLE_SRC)/*.s))

# include heap manage if configSUPPORT_DYNAMIC_ALLOCATION = 1
# SRC_C += $(FREERTOS_SRC)/portable/MemMang/heap_1.c
# CFLAGS += -Wno-error=sign-compare

# Suppress FreeRTOSConfig.h warnings
GCC_CFLAGS += -Wno-error=redundant-decls

# Suppress FreeRTOS source warnings
GCC_CFLAGS += -Wno-error=cast-qual

# FreeRTOS (lto + Os) linker issue
LDFLAGS += -Wl,--undefined=vTaskSwitchContext

include ../../rules.mk
