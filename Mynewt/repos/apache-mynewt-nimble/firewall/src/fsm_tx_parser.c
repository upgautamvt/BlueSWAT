#include <stdio.h>
#include <string.h>

#include "fsm_lib_hdr.h"
#include "fsm_core.h"
#include "utils.h"

void ifw_ll_tx_parser(struct ble_mbuf_hdr *ble_hdr, struct os_mbuf *m, struct ble_ll_conn_sm *connsm)
{
    // MODLOG_DFLT(INFO, "ifw_ll_tx_parser invoked here!\n");

    uint8_t llid;
    uint16_t cur_offset;
    uint8_t cur_txlen;
    uint16_t next_txlen;
    uint8_t opcode;
    uint16_t pktlen;
    int is_ctrl;

    llid = ble_hdr->txinfo.hdr_byte & BLE_LL_DATA_HDR_LLID_MASK;
    if (llid == BLE_LL_LLID_CTRL)
    {
        is_ctrl = 1;
        opcode = m->om_data[0];
    }
    else
    {
        is_ctrl = 0;
        opcode = 0;
    }

    IFW_FSM_STATE_UPDATE(is_ctrl, TX_IS_CTRL, CONN);
    IFW_FSM_STATE_UPDATE(opcode, TX_OPCODE, CONN);

    pktlen = OS_MBUF_PKTLEN(m);

    cur_txlen = ble_hdr->txinfo.pyld_len;
    cur_offset = ble_hdr->txinfo.offset;

    if ((cur_offset + cur_txlen) < pktlen)
    {
        next_txlen = pktlen - (cur_offset + cur_txlen);
    }
    else
    {
        next_txlen = connsm->eff_max_tx_octets;
    }
    if (next_txlen > connsm->eff_max_tx_octets)
    {
        next_txlen = connsm->eff_max_tx_octets;
    }

    return;
}