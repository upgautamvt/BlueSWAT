// CVE-2020-10068

// #include "../include/ebpf_helper.h"
#include "../include/fsm_for_ebpf.h"

#define LLCP_LENGTH_STATE_REQ 0
#define LLCP_LENGTH_STATE_REQ_ACK_WAIT 1
#define LLCP_LENGTH_STATE_RSP_WAIT 2

uint64_t zephyr_filter(uint8_t *newState)
{
	struct FsmState *fsm = (struct FsmState *)newState;

	// check DLE duplicate requests
	if (!((fsm->dc_param[LLCP_LEN_REQ] == fsm->dc_param[LLCP_LEN_ACK]) &&
		      fsm->dc_param[LLCP_LEN_RSP_TX] ||
	      ((fsm->dc_param[LLCP_LEN_REQ] != fsm->dc_param[LLCP_LEN_ACK]) &&
	       ((((fsm->dc_param[LLCP_LEN_STATE] == LLCP_LENGTH_STATE_REQ) ||
		  (fsm->dc_param[LLCP_LEN_STATE] ==
		   LLCP_LENGTH_STATE_REQ_ACK_WAIT)) &&
		 fsm->dc_param[LLCP_LEN_RSP_TX]) ||
		(fsm->dc_param[LLCP_LEN_STATE] ==
		 LLCP_LENGTH_STATE_RSP_WAIT))))) {
		return IFW_OPERATION_REJECT;
	}

	return IFW_OPERATION_PASS;
}