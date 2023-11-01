#include <stdio.h>
#include <string.h>

#include "fsm_lib_hdr.h"
#include "fsm_core.h"
#include "utils.h"

bool ifw_dc_ll_ctrl_parser(struct ble_ll_conn_sm *connsm, struct os_mbuf *rxpdu)
{
    MODLOG_DFLT(INFO, "ifw_dc_ll_ctrl_parser invoked here!\n");

    return IFW_OPERATION_PASS;
}

bool ifw_adv_ll_parser(uint8_t ptype, uint8_t *rxbuf, struct ble_mbuf_hdr *hdr)
{
    uint8_t *dptr;
    uint8_t chan_map[BLE_LL_CHAN_MAP_LEN];
    uint16_t chan_map_check;

    // MODLOG_DFLT(INFO, "ifw_adv_ll_parser invoked here!\n");

    /* Set the pointer at the start of the connection data */
    dptr = rxbuf + IFW_BLE_LL_CONN_REQ_ADVA_OFF + IFW_BLE_DEV_ADDR_LEN;

    if (ptype == BLE_ADV_PDU_TYPE_CONNECT_IND)
    {
        memcpy(&chan_map, dptr + 16, BLE_LL_CHAN_MAP_LEN);
        chan_map_check = (uint16_t)(chan_map[1] << 8 | chan_map[0]);

        if (IFW_FSM_CHECK_UPDATE(chan_map_check, CHANNEL_MAP, CONN))
        {
            MODLOG_DFLT(INFO, "Invalid channel map detected! Abort!\n");
            return IFW_OPERATION_REJECT;
        }

        MODLOG_DFLT(INFO, "ifw_adv_ll_parser: channel map: %x\n", chan_map_check);
    }

    return IFW_OPERATION_PASS;
}
