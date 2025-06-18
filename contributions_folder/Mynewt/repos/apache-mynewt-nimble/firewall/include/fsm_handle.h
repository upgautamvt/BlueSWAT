# Lines added by author
#include "fsm_core.h"
    (ifw_dc_ll_ctrl_parser(connsm, rxpdu) == IFW_OPERATION_REJECT)
    (ifw_dc_l2cap_parser(rxpdu) == IFW_OPERATION_REJECT)

#define IFW_FSM_CHECK_UPDATE(state, type, class) \
    (ifw_fsm_check_update(state, type, class) == IFW_UPDATE_ERROR)

#define IFW_RUN_VERIFIER(type, class) \
    (ifw_run_verifier(type, class) == IFW_OPERATION_REJECT)

#define IFW_FSM_STATE_UPDATE(state, type, class) \
    (ifw_fsm_state_update(state, type, class) == IFW_UPDATE_ERROR)
bool ifw_ll_dc_ctrl_parser(struct ble_ll_conn_sm *connsm, struct os_mbuf *rxpdu);
bool ifw_l2cap_packet_parser(struct os_mbuf *rxpdu);
#define IFW_LL_DC_CTRL_PARSER(connsm, rxpdu) \
    (ifw_ll_dc_ctrl_parser(connsm, rxpdu) == IFW_OPERATION_REJECT)
#define IFW_L2CAP_PACKET_PARSER(rxpdu) \
    (ifw_l2cap_packet_parser(rxpdu) == IFW_OPERATION_REJECT)
    (ifw_l2cap_packet_parser_recv(rxpdu) == IFW_OPERATION_REJECT)
#endif // FSM_HANDLE_H
#define IFW_LL_PACKET_PARSER(link, rx)                                         \
	(ifw_ll_packet_parser_rx(link, rx) == IFW_OPERATION_REJECT)
#define IFW_L2CAP_PACKET_PARSER(conn, buf)                                     \
	(ifw_l2cap_packet_parser_recv(conn, buf) == IFW_OPERATION_REJECT)
// #define IFW_INVALID_RELEASE(hdr, lll, link, rx)                                \
// 	ifw_invalid_release(hdr, lll, link, rx)
#define IFW_FSM_CHECK_UPDATE(state, type, class)                               \
	(ifw_fsm_check_update(state, type, class) == IFW_UPDATE_ERROR)
#define IFW_RUN_VERIFIER(type, class)                                          \
	(ifw_run_verifier(type, class) == IFW_OPERATION_REJECT)

#define IFW_FSM_STATE_UPDATE(state, type, class)                               \
	(ifw_fsm_state_update(state, type, class) == IFW_UPDATE_ERROR)

// extern void bt_le_adv_resume(void);
// extern void ll_reset(void);
