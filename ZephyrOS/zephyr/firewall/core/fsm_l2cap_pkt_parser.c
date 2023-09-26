#include <stdio.h>
#include <string.h>

#include "fsm_lib_hdr.h"
#include "fsm_handle.h"

#include "utils.h"

static void ifw_l2cap_chan_recv(struct bt_l2cap_chan *chan,
				struct net_buf *buf);
static void *ifw_net_buf_pull_mem(struct net_buf_simple *buf, size_t len);
static void ifw_smp_ident_addr_info(struct bt_smp *smp, struct net_buf *buf);
static void ifw_bt_smp_recv(struct bt_l2cap_chan *chan, struct net_buf *buf);

extern struct bt_l2cap_chan *bt_l2cap_le_lookup_rx_cid(struct bt_conn *conn,
						       u16_t cid);
extern u8_t get_encryption_key_size(struct bt_smp *smp);

static bool result = 0;

int peek_len_total = 0;

bool ifw_l2cap_packet_parser_recv(struct bt_conn *conn, struct net_buf *buf)
{
	result = IFW_OPERATION_PASS;

	struct bt_l2cap_hdr *hdr;
	struct bt_l2cap_chan *chan;
	u16_t cid;

	hdr = ifw_net_buf_pull_mem(buf, sizeof(*hdr));
	cid = sys_le16_to_cpu(hdr->cid);
	chan = bt_l2cap_le_lookup_rx_cid(conn, cid);

	// DEBUG_LOG("Packet for CID %u len %u", cid, buf->len);

	// ifw_l2cap_chan_recv(chan, buf);
	ifw_bt_smp_recv(chan, buf);

	return result;
}

#ifndef CONTAINER_OF
#define CONTAINER_OF(ptr, type, field)
((type *)(((char *)(ptr)) - offsetof(type, field)))
#endif

	// L2CAP signaling channel
	static void ifw_l2cap_chan_recv(struct bt_l2cap_chan *chan,
					struct net_buf *buf)
{
	struct bt_l2cap *l2cap = CONTAINER_OF(chan, struct bt_l2cap, chan);
	struct bt_l2cap_sig_hdr *hdr;
	u16_t len;

	hdr = ifw_net_buf_pull_mem(buf, sizeof(*hdr));
	len = sys_le16_to_cpu(hdr->len);

	// DEBUG_LOG("Signaling code 0x%02x ident %u len %u", hdr->code,
	// 	  hdr->ident, len);

	switch (hdr->code) {
	case BT_L2CAP_CONN_PARAM_RSP:
		break;
#if defined(CONFIG_BT_L2CAP_DYNAMIC_CHANNEL)
	case BT_L2CAP_LE_CONN_REQ:
		// le_conn_req(l2cap, hdr->ident, buf);
		break;
	case BT_L2CAP_LE_CONN_RSP:
		// le_conn_rsp(l2cap, hdr->ident, buf);
		break;
	case BT_L2CAP_DISCONN_REQ:
		// le_disconn_req(l2cap, hdr->ident, buf);
		break;
	case BT_L2CAP_DISCONN_RSP:
		// le_disconn_rsp(l2cap, hdr->ident, buf);
		break;
	case BT_L2CAP_LE_CREDITS:
		// le_credits(l2cap, hdr->ident, buf);
		break;
	case BT_L2CAP_CMD_REJECT:
		// reject_cmd(l2cap, hdr->ident, buf);
		break;
#else
	case BT_L2CAP_CMD_REJECT:
		/* Ignored */
		break;
#endif /* CONFIG_BT_L2CAP_DYNAMIC_CHANNEL */
	case BT_L2CAP_CONN_PARAM_REQ:
		if (IS_ENABLED(CONFIG_BT_CENTRAL)) {
			// le_conn_param_update_req(l2cap, hdr->ident, buf);
			break;
		}
	/* Fall-through */
	default:
		// DEBUG_LOG("Unknown L2CAP PDU code 0x%02x", hdr->code);
		// l2cap_send_reject(chan->conn, hdr->ident,
		// 		  BT_L2CAP_REJ_NOT_UNDERSTOOD, NULL, 0);
		break;
	}
}

// L2CAP to SMP protocol
static void ifw_bt_smp_recv(struct bt_l2cap_chan *chan, struct net_buf *buf)
{
	struct bt_smp *smp = CONTAINER_OF(chan, struct bt_smp, chan);
	struct bt_smp_hdr *hdr;
	u8_t err;

	hdr = ifw_net_buf_pull_mem(buf, sizeof(*hdr));
	// BT_DBG("Received SMP code 0x%02x len %u", hdr->code, buf->len);

	if (hdr->code == 0x09) {
		ifw_smp_ident_addr_info(smp, buf);
	}
}

static void ifw_smp_ident_addr_info(struct bt_smp *smp, struct net_buf *buf)
{
	struct bt_conn *conn = smp->chan.chan.conn;
	struct bt_smp_ident_addr_info *req = (void *)buf->data;

	u8_t enc_size_bond = get_encryption_key_size(smp);
	u8_t method_bond = smp->method;

	if (bt_addr_le_cmp(&conn->le.dst, &req->addr) != 0) {
		struct bt_keys *keys = bt_keys_find_addr(conn->id, &req->addr);

		// if (keys) {
		// 	if (!update_keys_check(smp, keys)) {
		// 		return BT_SMP_ERR_UNSPECIFIED;
		// 	}

		if (keys) {
			IFW_FSM_CHECK_UPDATE(enc_size_bond, SMP_ENC_SIZE_PREV,
					     DC);
			IFW_FSM_CHECK_UPDATE(method_bond, SMP_METHOD_PREV, DC);

			IFW_FSM_CHECK_UPDATE(keys->keys, SMP_KEYS, DC);
			IFW_FSM_CHECK_UPDATE(keys->enc_size, SMP_ENC_SIZE, DC);
			IFW_FSM_CHECK_UPDATE(keys->flags, SMP_KEYS_FLAGS, DC);

			if (IFW_RUN_VERIFIER(SMP_KEYS, DC)) {
				result = IFW_OPERATION_REJECT;
				return;
			}
		}
	}
}

// peek the data from the beginning of the buffer and return the pointer without modifying the buffer
static void *ifw_net_buf_pull_mem(struct net_buf_simple *buf, size_t len)
{
	void *data_hdr = buf->data;
	void *data = data_hdr + peek_len_total;

	peek_len_total += len;

	return data;
}