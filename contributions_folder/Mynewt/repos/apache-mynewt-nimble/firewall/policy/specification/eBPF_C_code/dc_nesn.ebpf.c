# Lines added by author
// CVE-2020-10061

// #include "../include/ebpf_helper.h"
#include "../include/fsm_for_ebpf.h"

uint64_t zephyr_filter(uint8_t *newState)
{
	struct FsmState *fsm = (struct FsmState *)newState;

	// check NESN and SN
	if (fsm->dc_param[NESN] == 1 && fsm->dc_param[SN] == 1) {
		return IFW_OPERATION_REJECT;
	}

	return IFW_OPERATION_PASS;
}
