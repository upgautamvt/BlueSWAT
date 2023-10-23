#include <stdio.h>

#include "fsm_core.h"
#include "fsm_policy_cache.h"
#include "utils.h"

static int ifw_core_state_num[IFW_CORE_STATE_NUM] = {
    IFW_BLE_LL_STATE_NUM,
    IFW_BLE_PAIRING_MODE_NUM,
    IFW_BLE_PAIRING_METHOD_NUM,
    IFW_BLE_ROLE_NUM,
    IFW_IO_CAPACITY_NUM,
};

static struct FsmState curFSMState;
static struct FsmState newFSMState;

bool fsm_new_init = 0;

void ifw_fsm_init()
{
    for (int i = 0; i < IFW_CORE_STATE_NUM; i++)
    {
        // init core state value as its num
        curFSMState.core_state[i] = ifw_core_state_num[i];
    }

    for (int i = 0; i < IFW_SHARED_STATE_NUM; i++)
    {
        // init shared state value as 0
        curFSMState.shared_state[i] = 0;
    }

    for (int i = 0; i < IFW_CONN_PARAM_NUM; i++)
    {
        curFSMState.conn_param[i] = 0;
    }

    for (int i = 0; i < IFW_DC_PARAM_NUM; i++)
    {
        curFSMState.dc_param[i] = 0;
    }

    for (int i = 0; i < IFW_SPI_PARAM_NUM; i++)
    {
        curFSMState.spi_param[i] = 0;
    }

    for (int i = 0; i < IFW_HCI_PARAM_NUM; i++)
    {
        curFSMState.hci_param[i] = 0;
    }

    // IFW_DEBUG_LOG("FSM core init success.");
}

// update new state to FSM
// state: state value, e.g. DISPLAY_YESNO(1)
// type: state type, e.g. IFW_IO_CAPACITY
// class: state class, e.g. core / shared / conn / dc
int ifw_fsm_state_update(uint16_t state, uint16_t type, uint16_t class)
{
    switch (class)
    {
    case SHARED:
        curFSMState.shared_state[type] = state;
        break;

    case CORE:
        curFSMState.core_state[type] = state;
        break;

    case CONN:
        curFSMState.conn_param[type] = state;
        break;

    case DC:
        curFSMState.dc_param[type] = state;
        break;

    case SPI:
        curFSMState.spi_param[type] = state;
        break;

    case HCI:
        curFSMState.hci_param[type] = state;
        break;

    default:
        // IFW_DEBUG_LOG("Unknown state class. State update error.");
        return IFW_UPDATE_ERROR;
    }

    fsm_new_init = 0;

    return IFW_UPDATE_SUCCESS;
}

// update the state machine for checking
// state: state value, e.g. DISPLAY_YESNO(1)
// type: state type, e.g. IFW_IO_CAPACITY
// class: state class, e.g. core / shared / conn / dc
int ifw_fsm_check_update(uint16_t state, uint16_t type, uint16_t class)
{
    if (fsm_new_init)
    {
        newFSMState = curFSMState;
        fsm_new_init = 1;
    }

    switch (class)
    {
    case SHARED:
        // check shared state transition
        if (type >= IFW_SHARED_STATE_NUM)
        {
            return IFW_UPDATE_ERROR;
        }

        newFSMState.shared_state[type] = state;

        break;

    case CORE:
        // check core state transition
        if (type >= IFW_CORE_STATE_NUM ||
            state >= ifw_core_state_num[type])
        {
            return IFW_UPDATE_ERROR;
        }

        newFSMState.core_state[type] = state;

        break;

    case CONN:
        // check conn param
        if (type >= IFW_CONN_PARAM_NUM)
        {
            return IFW_UPDATE_ERROR;
        }

        newFSMState.conn_param[type] = state;

        break;

    case DC:
        // check data connection param
        if (type >= IFW_DC_PARAM_NUM)
        {
            return IFW_UPDATE_ERROR;
        }

        newFSMState.dc_param[type] = state;

        break;

    case SPI:
        // check SPI params
        if (type >= IFW_SPI_PARAM_NUM)
        {
            return IFW_UPDATE_ERROR;
        }

        newFSMState.spi_param[type] = state;

        break;

    case HCI:
        // check SPI params
        if (type >= IFW_HCI_PARAM_NUM)
        {
            return IFW_UPDATE_ERROR;
        }

        newFSMState.hci_param[type] = state;

        break;

    default:
        // IFW_DEBUG_LOG("Unknown state class. Check update error.");
        return IFW_UPDATE_ERROR;
    }

    return IFW_UPDATE_SUCCESS;
}

int ifw_run_verifier(uint16_t type, uint16_t class)
{
    fsm_new_init = 0;

    if (run_fsm_check_policy(type, class, &newFSMState) ==
        IFW_OPERATION_REJECT)
    {
        // IFW_DEBUG_LOG("IFW_OPERATION_REJECT.");

        return IFW_OPERATION_REJECT;
    }

    return IFW_OPERATION_PASS;
}
