#include "../../include/fsm_for_ebpf.h"

uint64_t zephyr_filter(uint8_t *newState)
{
    struct FsmState *fsm = (struct FsmState *)newState;

    // Pass verification if it is the first time to connect
    if (fsm->dc_param[SMP_MAX_ENC_SIZE_PREV] == 0)
    {
        return IFW_OPERATION_PASS;
    }

    if (fsm->dc_param[SMP_MAX_ENC_SIZE_PREV] > fsm->dc_param[SMP_MAX_ENC_SIZE])
    {
        return IFW_OPERATION_REJECT;
    }

    return IFW_OPERATION_PASS;
}