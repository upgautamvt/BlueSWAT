# Lines added by author
#include <stdio.h>

#include "utils.h"
#include "fsm_policy_cache.h"
#include "fsm_lib_hdr.h"

#define IFW_POLICY_ADD_SUCCESS 0
#define IFW_POLICY_ADD_FAIL 1

#define IFW_POLICY_REMOVE_SUCCESS 0
#define IFW_POLICY_REMOVE_FAIL 1

// static void disable_mpu_for_jit()
// {
//     extern void arm_core_mpu_disable();
//     arm_core_mpu_disable();
// }

struct fsm_policy
{
    uint8_t *policy;
    uint16_t len;

    uint16_t type;
    uint16_t class;
};

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

bool ifw_add_policy(struct fsm_policy policy, void *dst)
{

    return IFW_POLICY_ADD_SUCCESS;
}

bool ifw_remove_policy()
{
    return IFW_POLICY_REMOVE_SUCCESS;
}
static void disable_mpu_for_jit()
{
    extern void arm_core_mpu_disable();
    arm_core_mpu_disable();
}
        disable_mpu_for_jit();
