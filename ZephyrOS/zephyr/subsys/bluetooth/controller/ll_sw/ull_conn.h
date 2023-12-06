// IFW below

#ifndef ULL_CONN_H
#define ULL_CONN_H

#include <zephyr/types.h>
// #include "fsm_lib_hdr.h"

#ifndef CONFIG_BT_CTLR_LLCP_CONN
#define CONFIG_BT_CTLR_LLCP_CONN 1
#endif

#ifndef MROUND
#define MROUND(x) (((u32_t)(x) + 3) & (~((u32_t)3)))
#endif

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#endif

#define CONN_TX_CTRL_BUFFERS (4 * CONFIG_BT_CTLR_LLCP_CONN)
#define CONN_TX_CTRL_BUF_SIZE                                                  \
	MROUND(offsetof(struct node_tx, pdu) +                                 \
	       offsetof(struct pdu_data, llctrl) +                             \
	       sizeof(struct pdu_data_llctrl))

struct MEM_CONN_TX_CTRL {
	void *free;
	u8_t pool[CONN_TX_CTRL_BUF_SIZE * CONN_TX_CTRL_BUFFERS];
};

extern struct MEM_CONN_TX_CTRL mem_conn_tx_ctrl;

#endif

// IFW above