#include <stdio.h>
#include <string.h>

#include "fsm_lib_hdr.h"
#include "fsm_core.h"

#include "utils.h"

static bool result = 0;

bool ifw_dc_l2cap_parser(struct os_mbuf *rxpdu)
{
    result = IFW_OPERATION_PASS;

    return result;
}
