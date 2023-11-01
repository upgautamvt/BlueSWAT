#include <stdio.h>
#include <string.h>

#include "fsm_lib_hdr.h"
#include "fsm_core.h"

#include "utils.h"

bool ifw_dc_l2cap_parser(struct os_mbuf *rxpdu)
{

    MODLOG_DFLT(INFO, "ifw_dc_l2cap_parser invoked here!\n");

    return IFW_OPERATION_PASS;
}
