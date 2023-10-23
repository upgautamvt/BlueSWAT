#ifndef FSM_HANDLE_H
#define FSM_HANDLE_H

#include "fsm_core.h"

// whether to use JIT interpretation
#define JIT_OFF 0
#define JIT_ON 1

void ifw_fsm_enable(bool jit);
bool ifw_ll_dc_ctrl_parser(struct ble_ll_conn_sm *connsm, struct os_mbuf *rxpdu);
bool ifw_l2cap_packet_parser(struct os_mbuf *rxpdu);

#define IFW_LL_DC_CTRL_PARSER(connsm, rxpdu) \
    (ifw_ll_dc_ctrl_parser(connsm, rxpdu) == IFW_OPERATION_REJECT)

#define IFW_L2CAP_PACKET_PARSER(rxpdu) \
    (ifw_l2cap_packet_parser(rxpdu) == IFW_OPERATION_REJECT)

#define IFW_FSM_CHECK_UPDATE(state, type, class) \
    (ifw_fsm_check_update(state, type, class) == IFW_UPDATE_ERROR)

#define IFW_RUN_VERIFIER(type, class) \
    (ifw_run_verifier(type, class) == IFW_OPERATION_REJECT)

#define IFW_FSM_STATE_UPDATE(state, type, class) \
    (ifw_fsm_state_update(state, type, class) == IFW_UPDATE_ERROR)

#endif // FSM_HANDLE_H
