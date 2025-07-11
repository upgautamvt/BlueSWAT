# Lines added by author
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
    BONDING,
uint8_t ifw_fsm_state_update(uint16_t state, uint16_t type, uint16_t class);
    (ifw_fsm_state_update(state, type, class) == IFW_UPDATE_ERROR)
#define IFW_UPDATE_SUCCESS 0
#define IFW_UPDATE_ERROR 1
    int core_state[IFW_CORE_STATE_NUM];
    int shared_state[IFW_SHARED_STATE_NUM];
    int conn_param[IFW_CONN_PARAM_NUM];
    int dc_param[IFW_DC_PARAM_NUM];
    int spi_param[IFW_SPI_PARAM_NUM];
    int hci_param[IFW_HCI_PARAM_NUM];
int ifw_fsm_check_update(uint16_t state, uint16_t type, uint16_t class);
int ifw_run_verifier(uint16_t type, uint16_t class);
int ifw_fsm_state_update(uint16_t state, uint16_t type, uint16_t class);
typedef enum {
	IFW_BLE_LL_CONNECTION_STATE = 0,
	IFW_BLE_LL_STANDBY_STATE,
	IFW_BLE_LL_ADVERTISING_STATE,
	IFW_BLE_LL_SCANNING_STATE,
	IFW_BLE_LL_INITIATING_STATE,
	IFW_BLE_LL_SYNCHRONIZATION_STATE,
	IFW_BLE_LL_ISOCHRONOUS_BROADCASTING_STATE,

	// end
	IFW_BLE_LL_STATE_NUM,
typedef enum {
	IFW_BLE_SSP = 0,
	IFW_BLE_SC,
	// end
	IFW_BLE_PAIRING_MODE_NUM,
typedef enum {
	IFW_BLE_JUST_WORKS = 0,
	IFW_BLE_OOB,
	IFW_BLE_NUMERIC_COMPAIRISON,
	IFW_BLE_PASSKEY_ENTRY,
	//end
	IFW_BLE_PAIRING_METHOD_NUM,
typedef enum {
	IFW_BLE_ROLE_OBSERVER = 0,
	IFW_BLE_ROLE_BROADCASTER,
	IFW_BLE_ROLE_CENTRAL,
	IFW_BLE_ROLE_PERIPHERAL,
	IFW_BLE_ROLE_INITIATOR,
	IFW_BLE_ROLE_SCANNER,
	IFW_BLE_ROLE_ADVERTISER,

	// end
	IFW_BLE_ROLE_NUM,
typedef enum {
	DISPLAY_ONLY = 0,
	DISPLAY_YESNO,
	KEYBOARD_ONLY,
	NOINPUT_NOOUTPUT,
	KEYBOARD_DISPLAY,
	RESERVED,

	// end
	IFW_IO_CAPACITY_NUM,
enum ifw_core_state_type {
	LL_STATE = 0,
	PAIRING_MODE,
	PAIRING_METHOD,
	BLE_ROLE,
	IO_CAPACITY,

	// end
	IFW_CORE_STATE_NUM,
typedef enum {
	BD_ADDR = 0,
	BONDING,
	// whether peer supports SC
	SC,
	// end
	IFW_SHARED_STATE_NUM,
typedef enum {
	CHANNEL_MAP = 0,
	CHANNEL_HOP,
	SCAN_RSP_LEN,
	LLL_INTERVAL,

	// end
	IFW_CONN_PARAM_NUM,
typedef enum {
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
typedef enum {
	HCI_EVT_LEN = 0,
	HCI_ACL_LEN,
	// end
	IFW_SPI_PARAM_NUM,
typedef enum {
	HCI_CMD_BUF = 0,
	// end
	IFW_HCI_PARAM_NUM,
enum ifw_state_class {
	SHARED = 0,
	CORE,
	CONN,
	DC,
	SPI,
	HCI,

	// end
	IFW_STATE_CLASS_NUM,
struct FsmState {
	int core_state[IFW_CORE_STATE_NUM];
	int shared_state[IFW_SHARED_STATE_NUM];
	int conn_param[IFW_CONN_PARAM_NUM];
	int dc_param[IFW_DC_PARAM_NUM];

	int spi_param[IFW_SPI_PARAM_NUM];
	int hci_param[IFW_HCI_PARAM_NUM];
// firewall macro
#define IFW_OPERATION_PASS 0
#define IFW_OPERATION_REJECT 1

#define IFW_UPDATE_SUCCESS 0
#define IFW_UPDATE_ERROR 1

