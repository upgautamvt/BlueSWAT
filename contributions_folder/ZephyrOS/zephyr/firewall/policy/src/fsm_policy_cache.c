# Lines added by author
// #include "ebpf_bytecode/conn_chan_map.h"
	// ADD_POLICY(conn_chan_map, CONN, CHANNEL_MAP);
#include "ebpf_bytecode/conn_chan_map.h"
#include "ebpf_bytecode/conn_chan_hop.h"
	ADD_POLICY(conn_chan_map, CONN, CHANNEL_MAP);
	ADD_POLICY(conn_chan_hop, CONN, CHANNEL_HOP);
#include "ebpf_bytecode/dc_nesn.h"
#include "ebpf_bytecode/spi_evt_len.h"
#include "ebpf_bytecode/spi_acl_len.h"
#include "ebpf_bytecode/scan_rsp_len.h"
#include "ebpf_bytecode/llcp_len_req.h"
#include "ebpf_bytecode/llcp_conn_param_req.h"
#include "ebpf_bytecode/lll_interval.h"
#include "ebpf_bytecode/smp_ident_check.h"
	// ADD_POLICY(conn_chan_hop, CONN, CHANNEL_HOP);
	ADD_POLICY(conn_chan_hop, CONN, CHANNEL_HOP);
	ADD_POLICY(dc_nesn, DC, NESN);
	ADD_POLICY(spi_acl_len, SPI, HCI_ACL_LEN);
	ADD_POLICY(spi_evt_len, SPI, HCI_EVT_LEN);
	ADD_POLICY(scan_rsp_len, CONN, SCAN_RSP_LEN);
	ADD_POLICY(llcp_len_req, DC, LLCP_LEN_REQ);
	ADD_POLICY(llcp_conn_param_req, DC, LLCP_CONN_PARAM_REQ);
	ADD_POLICY(lll_interval, CONN, LLL_INTERVAL);
	ADD_POLICY(smp_ident_check, DC, SMP_KEYS);
	switch (class) {
	case CORE:
		if (!(core_policy_mask & (1 << type))) {
			return IFW_OPERATION_PASS;
		}
		break;
	case SHARED:
		if (!(shared_policy_mask & (1 << type))) {
			return IFW_OPERATION_PASS;
		}
		break;
	case CONN:
		if (!(conn_policy_mask & (1 << type))) {
			return IFW_OPERATION_PASS;
		}
		break;
	case DC:
		if (!(dc_policy_mask & (1 << type))) {
			return IFW_OPERATION_PASS;
		}
		break;
	case SPI:
		if (!(spi_policy_mask & (1 << type))) {
			return IFW_OPERATION_PASS;
		}
		break;
	case HCI:
		if (!(hci_policy_mask & (1 << type))) {
			return IFW_OPERATION_PASS;
		}
		break;
	}
