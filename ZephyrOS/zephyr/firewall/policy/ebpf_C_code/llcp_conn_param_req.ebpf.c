// CVE-2021-3430

// #include "../include/ebpf_helper.h"
#include "../include/fsm_for_ebpf.h"

#define LLCP_CPR_STATE_REQ 0
#define LLCP_CPR_STATE_RSP_WAIT 4

uint64_t zephyr_filter(uint8_t *newState)
{
	struct FsmState *fsm = (struct FsmState *)newState;

	// check DLE duplicate requests
	if (!((fsm->dc_param[LLCP_CONN_PARAM_REQ] ==
	       fsm->dc_param[LLCP_CONN_PARAM_ACK]) ||
	      (fsm->dc_param[LLCP_CONN_PARAM_STATE] == LLCP_CPR_STATE_REQ) ||
	      (fsm->dc_param[LLCP_CONN_PARAM_STATE] ==
	       LLCP_CPR_STATE_RSP_WAIT))) {
		return IFW_OPERATION_REJECT;
	}

	return IFW_OPERATION_PASS;
}