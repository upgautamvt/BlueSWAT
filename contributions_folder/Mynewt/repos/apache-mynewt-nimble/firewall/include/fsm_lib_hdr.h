# Lines added by author
// for ll data ctrl packet parser
#include <sys/byteorder.h>
// for ll packet parser
#include "include/zephyr/types.h"
#include "subsys/bluetooth/controller/hal/ccm.h"
#include "subsys/bluetooth/controller/util/memq.h"
#include "subsys/bluetooth/controller/ll_sw/lll.h"
#include "subsys/bluetooth/controller/ll_sw/lll_conn.h"
#include "subsys/bluetooth/controller/ll_sw/pdu.h"
#include "subsys/bluetooth/controller/ll_sw/ull_conn_types.h"
#ifndef BT_L2CAP_HDR_
#define BT_L2CAP_HDR_
struct bt_l2cap_hdr {
	uint16_t len;
	uint16_t cid;
} __attribute__((packed));

#ifndef BT_L2CAP_SIG_HDR_
#define BT_L2CAP_SIG_HDR_
struct bt_l2cap_sig_hdr {
	u8_t code;
	u8_t ident;
	u16_t len;
} __packed;
#endif

// // for L2CAP packet parser
#define BT_L2CAP_CMD_REJECT 0x01
#define BT_L2CAP_DISCONN_REQ 0x06
#define BT_L2CAP_DISCONN_RSP 0x07
#define BT_L2CAP_INFO_RSP 0x0b
#define BT_L2CAP_CONN_PARAM_REQ 0x12
#define BT_L2CAP_CONN_PARAM_RSP 0x13
#define BT_L2CAP_LE_CONN_REQ 0x14
#define BT_L2CAP_LE_CONN_RSP 0x15
#define BT_L2CAP_LE_CREDITS 0x16

#include "include/kernel.h"
#include "include/sys/slist.h"
#include "include/bluetooth/addr.h"

#include "include/net/buf.h"
#include "include/bluetooth/l2cap.h"

#include "subsys/bluetooth/host/smp.h"
#include "subsys/bluetooth/host/keys.h"
#include "subsys/bluetooth/host/conn_internal.h"

// #include "subsys/bluetooth/host/l2cap_internal.h"

#include "subsys/bluetooth/controller/ll_sw/ull_conn.h"

#include "errno.h"

#endif
