#ifndef FSM_MONITOR_H_
#define FSM_MONITOR_H_

#include <stdint.h>

// firewall macro
#define IFW_OPERATION_PASS 0
#define IFW_OPERATION_REJECT 1

#define IFW_UPDATE_SUCCESS 2
#define IFW_UPDATE_ERROR 3

// BlueSWAT FSM state
typedef enum
{
    IFW_BLE_LL_CONNECTION_STATE = 0,
    IFW_BLE_LL_STANDBY_STATE,
    IFW_BLE_LL_ADVERTISING_STATE,
    IFW_BLE_LL_SCANNING_STATE,
    IFW_BLE_LL_INITIATING_STATE,
    IFW_BLE_LL_SYNCHRONIZATION_STATE,
    IFW_BLE_LL_ISOCHRONOUS_BROADCASTING_STATE,

    // end
    IFW_BLE_LL_STATE_NUM,
} IFW_FSM_LL_STATE;

// pairing mode actually used
typedef enum
{
    IFW_BLE_SSP = 0,
    IFW_BLE_SC,

    // end
    IFW_BLE_PAIRING_MODE_NUM,
} IFW_FSM_PAIRING_MODE;

typedef enum
{
    IFW_BLE_JUST_WORKS = 0,
    IFW_BLE_OOB,
    IFW_BLE_NUMERIC_COMPAIRISON,
    IFW_BLE_PASSKEY_ENTRY,

    // end
    IFW_BLE_PAIRING_METHOD_NUM,
} IFW_FSM_PAIRING_METHOD;

typedef enum
{
    IFW_BLE_ROLE_OBSERVER = 0,
    IFW_BLE_ROLE_BROADCASTER,
    IFW_BLE_ROLE_CENTRAL,
    IFW_BLE_ROLE_PERIPHERAL,
    IFW_BLE_ROLE_INITIATOR,
    IFW_BLE_ROLE_SCANNER,
    IFW_BLE_ROLE_ADVERTISER,

    // end
    IFW_BLE_ROLE_NUM,
} IFW_FSM_BLE_ROLE;

typedef enum
{
    DISPLAY_ONLY = 0,
    DISPLAY_YESNO,
    KEYBOARD_ONLY,
    NOINPUT_NOOUTPUT,
    KEYBOARD_DISPLAY,
    RESERVED,

    // end
    IFW_IO_CAPACITY_NUM,
} IFW_IO_CAPACITY;

// FSM core state index
enum ifw_core_state_type
{
    LL_STATE = 0,
    PAIRING_MODE,
    PAIRING_METHOD,
    BLE_ROLE,
    IO_CAPACITY,

    // end
    IFW_CORE_STATE_NUM,
};

// FSM shared state index
typedef enum
{
    BD_ADDR = 0,
    BONDING = 6,

    // whether peer supports SC
    SC,

    // end
    IFW_SHARED_STATE_NUM,
} IFW_SHARED_STATE;

// FSM conn parameters
typedef enum
{
    CHANNEL_MAP = 0,
    CHANNEL_HOP,
    SCAN_RSP_LEN,
    LLL_INTERVAL,

    // end
    IFW_CONN_PARAM_NUM,
} IFW_CONN_PARAM;

// FSM Data Connection parameters
typedef enum
{
    SN = 0,
    NESN,

    LLCP_LEN_REQ,
    LLCP_LEN_ACK,
    LLCP_LEN_RSP_TX,
    LLCP_LEN_STATE,

    LLCP_CONN_PARAM_REQ,
    LLCP_CONN_PARAM_ACK,
    LLCP_CONN_PARAM_STATE,

    SMP_ENC_SIZE_PREV,
    SMP_METHOD_PREV,
    SMP_KEYS,
    SMP_ENC_SIZE,
    SMP_KEYS_FLAGS,

    // end
    IFW_DC_PARAM_NUM,
} IFW_DC_PARAM;

// FSM param of SPI and BLE
typedef enum
{
    HCI_EVT_LEN = 0,
    HCI_ACL_LEN,

    // end
    IFW_SPI_PARAM_NUM,
} IFW_SPI_PARAM;

// FSM param of HCI core
typedef enum
{
    HCI_CMD_BUF = 0,

    // end
    IFW_HCI_PARAM_NUM,
} IFW_HCI_PARAM;

enum ifw_state_class
{
    SHARED = 0,
    CORE,
    CONN,
    DC,
    SPI,
    HCI,

    // end
    IFW_STATE_CLASS_NUM,
};

// FSM
struct FsmState
{
    uint8_t core_state[IFW_CORE_STATE_NUM];
    uint8_t shared_state[IFW_SHARED_STATE_NUM];
    uint8_t conn_param[IFW_CONN_PARAM_NUM];
    uint8_t dc_param[IFW_DC_PARAM_NUM];

    uint8_t spi_param[IFW_SPI_PARAM_NUM];
    uint8_t hci_param[IFW_HCI_PARAM_NUM];
};

// firewall trace hooks
uint8_t ifw_fsm_check_update(uint16_t state, uint16_t type, uint16_t class);
uint8_t ifw_run_verifier(uint16_t type, uint16_t class);
void ifw_fsm_state_update(uint16_t state, uint16_t type, uint16_t class);

#define IFW_FSM_CHECK_UPDATE(state, type, class) \
    (ifw_fsm_check_update(state, type, class) == IFW_UPDATE_ERROR)

#define IFW_RUN_VERIFIER(type, class) \
    (ifw_run_verifier(type, class) == IFW_UPDATE_ERROR)

#define IFW_FSM_STATE_UPDATE(state, type, class) \
    ifw_fsm_state_update(state, type, class)

#endif // FSM_MONITOR_H_