# Lines added by author
enum fsm_policy_tag {
	PID_conn_chan_map,
	PID_conn_chan_hop,
	// PID_ebpf_helper_test,
	PID_dc_nesn,
	PID_spi_acl_len,
	PID_spi_evt_len,
	PID_scan_rsp_len,
	PID_llcp_len_req,
	PID_llcp_conn_param_req,
	PID_lll_interval,
	PID_smp_ident_check,

	// FSM policy num
	PID_NUM,
struct fsm_policy_list {
	struct fsm_policy_list *policy_next;
	int index; // ebpf policy index, eg. PID_conn_chan_map
struct fsm_policy_manager {
	struct fsm_policy_list *policy[IFW_STATE_CLASS_NUM][IFW_DC_PARAM_NUM];
struct policy_cache {
	int size;
	uint8_t *code;
	// whether to use JIT interpretation for eBPF code
	bool jit;
