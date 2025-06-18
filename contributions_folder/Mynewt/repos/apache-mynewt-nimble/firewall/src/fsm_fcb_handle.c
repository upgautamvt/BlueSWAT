# Lines added by author
#include <stdio.h>

#include "utils.h"
#include "fsm_policy_cache.h"
#include "fsm_lib_hdr.h"
#include "fcb/fcb.h"

#define IFW_POLICY_ADD_SUCCESS 0
#define IFW_POLICY_ADD_FAIL 1

#define IFW_POLICY_REMOVE_SUCCESS 0
#define IFW_POLICY_REMOVE_FAIL 1

#define IFW_MAGIC_NUMBER 0x12345678
#define IFW_SECTOR_CNT 2
#define IFW_F_VERSION 1

struct fsm_policy
{
    const void *policy;
    const unsigned char *index;
    uint16_t len;

    uint16_t type;
    uint16_t class;
};

struct fcb *ifw_fcb_ptr;
struct fcb ifw_fcb;

struct flash_area ifw_fcb_area[] = {[0] = {
                                        .fa_device_id = 0,
                                        .fa_off = 0,
                                        .fa_size = 0x4000, /* 16K */
                                    },
                                    [1] = {.fa_device_id = 0, .fa_off = 0x4000, .fa_size = 0x4000}};

int ifw_fcb_init()
{
    int rc;

    ifw_fcb_ptr = &ifw_fcb;
    memset(ifw_fcb_ptr, 0, sizeof(*ifw_fcb_ptr));

    ifw_fcb_ptr->f_sectors = ifw_fcb_area;
    ifw_fcb_ptr->f_magic = IFW_MAGIC_NUMBER;
    ifw_fcb_ptr->f_version = IFW_F_VERSION;
    ifw_fcb_ptr->f_sector_cnt = IFW_SECTOR_CNT;

    rc = fcb_init(ifw_fcb_ptr);
    if (rc)
    {
        return rc;
    }

    return 0;
}

int ifw_fcb_add_policy(struct fsm_policy *policy)
{
    struct fcb_entry loc;
    int rc;

    rc = fcb_append(ifw_fcb_ptr, policy->len, &loc);
    if (rc)
    {
        return rc;
    }

    rc = flash_area_write(loc.fe_area, loc.fe_data_off, policy->policy, policy->len);
    if (rc)
    {
        return rc;
    }

    rc = fcb_append_finish(ifw_fcb_ptr, &loc);
    if (rc)
    {
        return rc;
    }

    return IFW_POLICY_ADD_SUCCESS;
}

bool ifw_fcb_remove_policy()
{

    return IFW_POLICY_REMOVE_SUCCESS;
}

static new_policy_count = 0;

struct policy_cache_new
{
    int size;
    uint8_t *code;

    // whether to use JIT interpretation for eBPF code
    bool jit;
};

// bool ifw_add_policy(struct fsm_policy policy, void *dst)
// {
//     int pid = 0;

//     new_policy_count++;

//     struct policy_cache_new *policy_arr_new = my_os_malloc(new_policy_count * sizeof(struct policy_cache_new));

//     pid = PID_##policy.index;
//     policy_arr_new[pid].size = policy.len;
//     policy_arr_new[pid].code = policy.policy;
//     policy_arr_new[pid].jit = false;
//     register_policy(policy.class, policy.type, pid);

//     return IFW_POLICY_ADD_SUCCESS;
// }

bool ifw_remove_policy()
{
    return IFW_POLICY_REMOVE_SUCCESS;
}
