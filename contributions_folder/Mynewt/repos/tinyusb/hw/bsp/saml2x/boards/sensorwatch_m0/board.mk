# Lines added by author
CFLAGS += -D__SAML22J18A__ -DCFG_EXAMPLE_VIDEO_READONLY

SAML_VARIANT = saml22

# All source paths should be relative to the top level.
LD_FILE = $(BOARD_PATH)/$(BOARD).ld

# For flash-jlink target
JLINK_DEVICE = ATSAML22J18

flash: flash-bossac
