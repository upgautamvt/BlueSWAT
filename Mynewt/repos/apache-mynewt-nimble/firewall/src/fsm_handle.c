#include <stdio.h>

#include "utils.h"
#include "fsm_policy_cache.h"
#include "fsm_lib_hdr.h"

// static void disable_mpu_for_jit()
// {
//     extern void arm_core_mpu_disable();
//     arm_core_mpu_disable();
// }

void ifw_fsm_enable(bool jit)
{
    load_all_policies();

    if (jit)
    {
        // disable_mpu_for_jit();
        set_all_policy_jit_on();
    }

    // IFW_DEBUG_LOG("FSM rules loaded success.");
}
