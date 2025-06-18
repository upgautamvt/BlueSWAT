# Lines added by author
uint8_t ifw_fsm_state_update(uint16_t state, uint16_t type, uint16_t class)
        return IFW_UPDATE_ERROR;
    return IFW_UPDATE_SUCCESS;
        // IFW_DEBUG_LOG("IFW_OPERATION_REJECT.");

int ifw_fsm_state_update(uint16_t state, uint16_t type, uint16_t class)
        // IFW_DEBUG_LOG("Unknown state class. State update error.");
// update the state machine for checking
int ifw_fsm_check_update(uint16_t state, uint16_t type, uint16_t class)
        // IFW_DEBUG_LOG("Unknown state class. Check update error.");
    return IFW_UPDATE_SUCCESS;
int ifw_run_verifier(uint16_t type, uint16_t class)
