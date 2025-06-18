# Lines added by author
#include "fsm_handle.h"
static inline void ifw_conn_setup(memq_link_t *link, struct node_rx_hdr *rx);
static inline void ifw_peripheral_setup(memq_link_t *link,
					struct node_rx_hdr *rx,
					struct node_rx_ftr *ftr,
					struct lll_conn *lll);
static inline void ifw_central_setup(memq_link_t *link, struct node_rx_hdr *rx,
				     struct node_rx_ftr *ftr,
				     struct lll_conn *lll);
static inline void ifw_conn_rx(memq_link_t *link, struct node_rx_pdu **rx);
static inline void ifw_ctrl_rx(memq_link_t *link, struct node_rx_pdu **rx,
			       struct pdu_data *pdu_rx, struct ll_conn *conn);
static inline uint8_t ifw_count_one(uint8_t *octets);

bool ifw_ll_packet_parser_rx(memq_link_t *link, struct node_rx_hdr *rx)
	result = IFW_OPERATION_PASS;

	switch (rx->type) {
	case NODE_RX_TYPE_EVENT_DONE:
		// Signals completion of RX event

		return IFW_OPERATION_PASS;

	case NODE_RX_TYPE_CONNECTION:
		// rx is Adv Channel Packet

		// IFW_DEBUG_LOG();
		ifw_conn_setup(link, rx);

		break;

	case NODE_RX_TYPE_DC_PDU:
		// rx is Data Channel Packet

		ifw_conn_rx(link, (void *)&rx);

		break;

		// default:
		// DEBUG_LOG("No state to update.");
	}
	return result;

static inline void ifw_conn_setup(memq_link_t *link, struct node_rx_hdr *rx)
{
	struct node_rx_ftr *ftr;
	struct lll_conn *lll;

	ftr = &(rx->rx_ftr);

	lll = *((struct lll_conn **)((u8_t *)ftr->param +
				     sizeof(struct lll_hdr)));

	switch (lll->role) {
	case 0:
		ifw_central_setup(link, rx, ftr, lll);

		IFW_FSM_CHECK_UPDATE(IFW_BLE_ROLE_CENTRAL, BLE_ROLE, CORE);

		if (IFW_RUN_VERIFIER(BLE_ROLE, CORE)) {
			result = IFW_OPERATION_REJECT;
			return;
		}

		break;

	case 1:
		ifw_peripheral_setup(link, rx, ftr, lll);

		IFW_FSM_CHECK_UPDATE(IFW_BLE_ROLE_PERIPHERAL, BLE_ROLE, CORE);

		if (IFW_RUN_VERIFIER(BLE_ROLE, CORE)) {
			result = IFW_OPERATION_REJECT;
			return;
		}

		break;

		// default:
		// IFW_DEBUG_LOG("Unknown role type.");
	}
}

static inline void ifw_peripheral_setup(memq_link_t *link,
					struct node_rx_hdr *rx,
					struct node_rx_ftr *ftr,
					struct lll_conn *lll)
{
	struct pdu_adv *pdu_adv;

	pdu_adv = (void *)((struct node_rx_pdu *)rx)->pdu;

	memcpy(&lll->crc_init[0], &pdu_adv->connect_ind.crc_init[0], 3);
	memcpy(&lll->access_addr[0], &pdu_adv->connect_ind.access_addr[0], 4);
	memcpy(&lll->data_chan_map[0], &pdu_adv->connect_ind.chan_map[0],
	       sizeof(lll->data_chan_map));

	lll->data_chan_count = ifw_count_one(&lll->data_chan_map[0]);

	IFW_FSM_CHECK_UPDATE(lll->data_chan_count, CHANNEL_MAP, CONN);

	if (IFW_RUN_VERIFIER(CHANNEL_MAP, CONN)) {
		result = IFW_OPERATION_REJECT;
		return;
	}

	lll->data_chan_hop = pdu_adv->connect_ind.hop;

	IFW_FSM_CHECK_UPDATE(lll->data_chan_hop, CHANNEL_HOP, CONN);

	if (IFW_RUN_VERIFIER(CHANNEL_HOP, CONN)) {
		result = IFW_OPERATION_REJECT;
		return;
	}

	lll->interval = sys_le16_to_cpu(pdu_adv->connect_ind.interval);

	IFW_FSM_CHECK_UPDATE(lll->interval, LLL_INTERVAL, CONN);

	if (IFW_RUN_VERIFIER(LLL_INTERVAL, CONN)) {
		result = IFW_OPERATION_REJECT;
		return;
	}
}

static inline void ifw_central_setup(memq_link_t *link, struct node_rx_hdr *rx,
				     struct node_rx_ftr *ftr,
				     struct lll_conn *lll)
{
}

int count = 0;

static inline void ifw_conn_rx(memq_link_t *link, struct node_rx_pdu **rx)
{
	struct pdu_data *pdu_rx;
	struct ll_conn *conn;

	pdu_rx = (void *)(*rx)->pdu;

	// Mitigate CVE-2020-10061: Check Anchor point DC packet
	if (count == 0) {
		count++;

		IFW_FSM_CHECK_UPDATE(pdu_rx->nesn, NESN, DC);
		IFW_FSM_CHECK_UPDATE(pdu_rx->sn, SN, DC);

		if (IFW_RUN_VERIFIER(NESN, DC)) {
			result = IFW_OPERATION_REJECT;
			return;
		}
	}

	switch (pdu_rx->ll_id) {
		// check LLID here

	case PDU_DATA_LLID_CTRL: {
		ifw_ctrl_rx(link, rx, pdu_rx, conn);
	}

	case PDU_DATA_LLID_DATA_CONTINUE:
	case PDU_DATA_LLID_DATA_START:
	case PDU_DATA_LLID_RESV:
	default:
		break;
	}

	return;
}

extern void *mem_acquire(void **mem_head);

static inline void ifw_ctrl_rx(memq_link_t *link, struct node_rx_pdu **rx,
			       struct pdu_data *pdu_rx, struct ll_conn *conn)
{
	u8_t opcode;
	opcode = pdu_rx->llctrl.opcode;

	struct node_tx *tx = NULL;

	switch (opcode) {
	case PDU_DATA_LLCTRL_TYPE_LENGTH_REQ:

		/* Check for free ctrl tx PDU */
		if (pdu_rx->llctrl.opcode == PDU_DATA_LLCTRL_TYPE_LENGTH_REQ) {
			tx = mem_acquire(&mem_conn_tx_ctrl.free);
			if (!tx) {
				return -ENOBUFS;
			}
		}

		IFW_FSM_CHECK_UPDATE(conn->llcp_length.req, LLCP_LEN_REQ, DC);
		IFW_FSM_CHECK_UPDATE(conn->llcp_length.ack, LLCP_LEN_ACK, DC);
		IFW_FSM_CHECK_UPDATE(tx, LLCP_LEN_RSP_TX, DC);
		IFW_FSM_CHECK_UPDATE(conn->llcp_length.state, LLCP_LEN_STATE,
				     DC);

		if (IFW_RUN_VERIFIER(LLCP_LEN_REQ, DC)) {
			result = IFW_OPERATION_REJECT;
			return;
		}

		break;

	case PDU_DATA_LLCTRL_TYPE_CONN_PARAM_REQ:

		// // IFW_DEBUG_LOG();

		if (conn->lll.role) {
			IFW_FSM_CHECK_UPDATE(conn->llcp_conn_param.req,
					     LLCP_CONN_PARAM_REQ, DC);
			IFW_FSM_CHECK_UPDATE(conn->llcp_conn_param.ack,
					     LLCP_CONN_PARAM_ACK, DC);
			IFW_FSM_CHECK_UPDATE(conn->llcp_conn_param.state,
					     LLCP_CONN_PARAM_STATE, DC);

			if (IFW_RUN_VERIFIER(LLCP_CONN_PARAM_REQ, DC)) {
				result = IFW_OPERATION_REJECT;
				return;
			}
		}
		break;
	}

	return;
}

static inline uint8_t ifw_count_one(uint8_t *octets)
{
	u8_t one_count = 0U;
	int octets_len = 5;

	while (octets_len--) {
		u8_t bite;

		bite = *octets;
		while (bite) {
			bite &= (bite - 1);
			one_count++;
		}
		octets++;
	}

	return one_count;
}
