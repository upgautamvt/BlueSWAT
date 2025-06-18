# Lines added by author
#include "fsm_handle.h"
				IFW_FSM_CHECK_UPDATE(len, HCI_EVT_LEN, SPI);
				if (IFW_RUN_VERIFIER(HCI_EVT_LEN, SPI)) {
					BT_ERR("Event too long: %d", len);
					net_buf_unref(buf);
					continue;
				}
				IFW_FSM_CHECK_UPDATE(len, HCI_ACL_LEN, SPI);
				if (IFW_RUN_VERIFIER(HCI_ACL_LEN, SPI)) {
					BT_ERR("Event too long: %d", len);
					net_buf_unref(buf);
					continue;
				}
