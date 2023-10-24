// CVE-2020-10065

#include "stdio.h"

// #include "../include/ebpf_helper.h"
#include "../include/fsm_for_ebpf.h"

#define BT_BUF_RX_SIZE 76
#define HCI_EVT 0x04

struct net_buf_simple {
	u8_t *data;
	u16_t len;
	u16_t size;
	u8_t *__buf;
};

size_t net_buf_simple_headroom(struct net_buf_simple *buf)
{
	return buf->data - buf->__buf;
}

size_t net_buf_simple_tailroom(struct net_buf_simple *buf)
{
	return buf->size - net_buf_simple_headroom(buf) - buf->len;
}

uint64_t zephyr_filter(uint8_t *newState)
{
	struct FsmState *fsm = (struct FsmState *)newState;

	// check SPI HCI_EVT length
	if (fsm->spi_param[HCI_EVT_LEN] > BT_BUF_RX_SIZE) {
		return IFW_OPERATION_REJECT;
	}

	return IFW_OPERATION_PASS;
}