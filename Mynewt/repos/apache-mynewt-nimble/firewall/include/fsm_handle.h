#ifndef FSM_HANDLE_H
#define FSM_HANDLE_H

#include "fsm_lib_hdr.h"

// firewall macro
#define IFW_VERIFICATION_PASS 0
#define IFW_VERIFICATION_REJECT 1

// whether to use JIT interpretation
#define JIT_OFF 0
#define JIT_ON 1

void ifw_fsm_enable(bool jit);
void ifw_fsm_init();

bool ifw_adv_ll_parser(uint8_t ptype, uint8_t *rxbuf, struct ble_mbuf_hdr *hdr);
bool ifw_dc_ll_ctrl_parser(struct ble_ll_conn_sm *connsm, struct os_mbuf *rxpdu);
bool ifw_dc_l2cap_parser(struct os_mbuf *rxpdu);

#define IFW_ADV_LL_PARSER(ptype, rxbuf, hdr) \
    (ifw_adv_ll_parser(ptype, rxbuf, hdr) == IFW_VERIFICATION_REJECT)

#define IFW_DC_LL_CTRL_PARSER(connsm, rxpdu) \
    (ifw_dc_ll_ctrl_parser(connsm, rxpdu) == IFW_VERIFICATION_REJECT)

#define IFW_DC_L2CAP_PARSER(rxpdu) \
    (ifw_dc_l2cap_parser(rxpdu) == IFW_VERIFICATION_REJECT)

#endif // FSM_HANDLE_H
