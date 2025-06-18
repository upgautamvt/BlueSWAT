# Lines added by author
	// for (int i = 0; i < IFW_SHARED_STATE_NUM; i++) {
	// 	// init shared state value as 0
	// 	curFSMState.shared_state[i] = 0;
	// }
	// for (int i = 0; i < IFW_CONN_PARAM_NUM; i++) {
	// 	curFSMState.conn_param[i] = 0;
	// }
	// for (int i = 0; i < IFW_DC_PARAM_NUM; i++) {
	// 	curFSMState.dc_param[i] = 0;
	// }
	// for (int i = 0; i < IFW_SPI_PARAM_NUM; i++) {
	// 	curFSMState.spi_param[i] = 0;
	// }
	// for (int i = 0; i < IFW_HCI_PARAM_NUM; i++) {
	// 	curFSMState.hci_param[i] = 0;
	// }
	// IFW_DEBUG_LOG("FSM core init success.");
	for (int i = 0; i < IFW_SHARED_STATE_NUM; i++) {
		// init shared state value as 0
		curFSMState.shared_state[i] = 0;
	}
	for (int i = 0; i < IFW_CONN_PARAM_NUM; i++) {
		curFSMState.conn_param[i] = 0;
	}
	for (int i = 0; i < IFW_DC_PARAM_NUM; i++) {
		curFSMState.dc_param[i] = 0;
	}
	for (int i = 0; i < IFW_SPI_PARAM_NUM; i++) {
		curFSMState.spi_param[i] = 0;
	}
	for (int i = 0; i < IFW_HCI_PARAM_NUM; i++) {
		curFSMState.hci_param[i] = 0;
	}
		if (type >= IFW_SHARED_STATE_NUM) {
			return IFW_UPDATE_ERROR;
		}
		if (type >= IFW_CORE_STATE_NUM ||
		    state >= ifw_core_state_num[type]) {
			return IFW_UPDATE_ERROR;
		}
		if (type >= IFW_CONN_PARAM_NUM) {
			return IFW_UPDATE_ERROR;
		}
		if (type >= IFW_DC_PARAM_NUM) {
			return IFW_UPDATE_ERROR;
		}
		if (type >= IFW_SPI_PARAM_NUM) {
			return IFW_UPDATE_ERROR;
		}
		if (type >= IFW_HCI_PARAM_NUM) {
			return IFW_UPDATE_ERROR;
		}
