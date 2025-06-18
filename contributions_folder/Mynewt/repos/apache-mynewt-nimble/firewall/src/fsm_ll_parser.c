# Lines added by author
    MODLOG_DFLT(INFO, "ifw_dc_ll_ctrl_parser invoked here!\n");
        MODLOG_DFLT(INFO, "ifw_adv_ll_parser: channel map: %x\n", chan_map_check);
#include "utils.h"
static bool result = 0;
bool ifw_dc_ll_ctrl_parser(struct ble_ll_conn_sm *connsm, struct os_mbuf *rxpdu)
    result = IFW_OPERATION_PASS;
    MODLOG_DFLT(INFO, "ifw_dc_ll_ctrl_parser invoked here!\n");
    return result;
