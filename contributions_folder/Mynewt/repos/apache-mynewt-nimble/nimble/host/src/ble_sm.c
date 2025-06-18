# Lines added by author
#define BLE_SM_TIMEOUT_MS             (30000)
static ble_sm_rx_fn * const ble_sm_dispatch[] = {
   [BLE_SM_OP_PAIR_REQ] = ble_sm_pair_req_rx,
   [BLE_SM_OP_PAIR_RSP] = ble_sm_pair_rsp_rx,
   [BLE_SM_OP_PAIR_CONFIRM] = ble_sm_confirm_rx,
   [BLE_SM_OP_PAIR_RANDOM] = ble_sm_random_rx,
   [BLE_SM_OP_PAIR_FAIL] = ble_sm_fail_rx,
   [BLE_SM_OP_ENC_INFO] = ble_sm_enc_info_rx,
   [BLE_SM_OP_MASTER_ID] = ble_sm_master_id_rx,
   [BLE_SM_OP_IDENTITY_INFO] = ble_sm_id_info_rx,
   [BLE_SM_OP_IDENTITY_ADDR_INFO] = ble_sm_id_addr_info_rx,
   [BLE_SM_OP_SIGN_INFO] = ble_sm_sign_info_rx,
   [BLE_SM_OP_SEC_REQ] = ble_sm_sec_req_rx,
   [BLE_SM_OP_PAIR_KEYPRESS_NOTIFY] = ble_sm_rx_noop,
   [BLE_SM_OP_PAIR_PUBLIC_KEY] = ble_sm_sc_public_key_rx,
   [BLE_SM_OP_PAIR_DHKEY_CHECK] = ble_sm_sc_dhkey_check_rx,
   [BLE_SM_OP_PAIR_PUBLIC_KEY] = ble_sm_rx_noop,
   [BLE_SM_OP_PAIR_DHKEY_CHECK] = ble_sm_rx_noop,
static ble_sm_state_fn * const
ble_sm_state_dispatch[BLE_SM_PROC_STATE_CNT] = {
    [BLE_SM_PROC_STATE_PAIR]          = ble_sm_pair_exec,
    [BLE_SM_PROC_STATE_CONFIRM]       = ble_sm_confirm_exec,
    [BLE_SM_PROC_STATE_RANDOM]        = ble_sm_random_exec,
    [BLE_SM_PROC_STATE_LTK_START]     = ble_sm_ltk_start_exec,
    [BLE_SM_PROC_STATE_LTK_RESTORE]   = ble_sm_ltk_restore_exec,
    [BLE_SM_PROC_STATE_ENC_START]     = ble_sm_enc_start_exec,
    [BLE_SM_PROC_STATE_ENC_RESTORE]   = ble_sm_enc_restore_exec,
    [BLE_SM_PROC_STATE_KEY_EXCH]      = ble_sm_key_exch_exec,
    [BLE_SM_PROC_STATE_SEC_REQ]       = ble_sm_sec_req_exec,
    [BLE_SM_PROC_STATE_PUBLIC_KEY]    = ble_sm_sc_public_key_exec,
    [BLE_SM_PROC_STATE_DHKEY_CHECK]   = ble_sm_sc_dhkey_check_exec,
    [BLE_SM_PROC_STATE_PUBLIC_KEY]    = NULL,
    [BLE_SM_PROC_STATE_DHKEY_CHECK]   = NULL,
static os_membuf_t ble_sm_proc_mem[
    OS_MEMPOOL_SIZE(MYNEWT_VAL(BLE_SM_MAX_PROCS),
                    sizeof (struct ble_sm_proc))
];

void
ble_sm_dbg_set_next_pair_rand(uint8_t *next_pair_rand)
void
ble_sm_dbg_set_next_ediv(uint16_t next_ediv)
void
ble_sm_dbg_set_next_master_id_rand(uint64_t next_master_id_rand)
void
ble_sm_dbg_set_next_ltk(uint8_t *next_ltk)
void
ble_sm_dbg_set_next_csrk(uint8_t *next_csrk)
    STAILQ_FOREACH(cur, &ble_sm_procs, next) {
int
ble_sm_num_procs(void)
    STAILQ_FOREACH(proc, &ble_sm_procs, next) {
int
ble_sm_gen_pair_rand(uint8_t *pair_rand)
    if (ble_sm_dbg_next_pair_rand_set) {
    if (rc != 0) {
    if (ble_sm_dbg_next_ediv_set) {
    if (rc != 0) {
    if (ble_sm_dbg_next_master_id_rand_set) {
    if (rc != 0) {
    if (ble_sm_dbg_next_ltk_set) {
    if (rc != 0) {
    if (ble_sm_dbg_next_csrk_set) {
    if (rc != 0) {
    if (op >= sizeof ble_sm_dispatch / sizeof ble_sm_dispatch[0]) {
    if (proc != NULL) {
    if (proc != NULL) {
                         struct ble_sm_proc *prev)
    if (prev == NULL) {
    } else {
    if (conn != NULL) {
        if (authenticated) {
        if (bonded) {
        if (key_size) {
    if (keys->ediv_rand_valid && keys->ltk_valid) {
    if (keys->irk_valid) {
    if (keys->csrk_valid) {
void
ble_sm_ia_ra(struct ble_sm_proc *proc,
             uint8_t *out_iat, uint8_t *out_ia,
             uint8_t *out_rat, uint8_t *out_ra)
    if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
    } else {
    if (proc->peer_keys.addr_valid) {
        if (memcmp(BLE_ADDR_ANY->val, &conn->bhc_peer_rpa_addr.val, 6) != 0) {
            switch (peer_addr.type) {
    } else {
    if (identity_ev) {
    if (conn_handle != proc->conn_handle) {
    if (state != BLE_SM_PROC_STATE_NONE && state != proc->state) {
    if (is_initiator != -1 && is_initiator != proc_is_initiator) {
    STAILQ_FOREACH(proc, &ble_sm_procs, next) {
        if (ble_sm_proc_matches(proc, conn_handle, state, is_initiator)) {
            if (out_prev != NULL) {
    STAILQ_FOREACH(cur, &ble_sm_procs, next) {
    while (proc != NULL) {
        if (time_diff <= 0) {
            if (prev == NULL) {
            } else {
        } else {
            if (time_diff < next_exp_in) {
    return ble_hs_cfg.sm_bonding << 0  |
           ble_hs_cfg.sm_mitm << 2     |
           ble_hs_cfg.sm_sc << 3       |
    if (proc->flags & BLE_SM_PROC_F_SC) {
    } else {
int
ble_sm_ioact_state(uint8_t action)
    switch (action) {
int
ble_sm_proc_can_advance(struct ble_sm_proc *proc)
    if (rc != 0) {
    if (ble_sm_ioact_state(ioact) != proc->state) {
        proc->flags & BLE_SM_PROC_F_ADVANCE_ON_IO) {
    if (!ble_hs_conn_exists(proc->conn_handle)) {
    } else {
    if (cmd) {
        if (rc) {
    if (rc != 0) {
    do {
        switch (rc) {
void
ble_sm_process_result(uint16_t conn_handle, struct ble_sm_result *res,
                      bool tx_fail)
    while (1) {
        if (proc != NULL) {
            if (res->execute) {
            if (res->app_status != 0) {
            if (proc->state == BLE_SM_PROC_STATE_NONE) {
            if (rm) {
            } else {
        if (res->sm_err != 0 && tx_fail) {
            res->app_status != BLE_HS_ENOTCONN) {
        if (proc == NULL) {
        if (res->enc_cb) {
            res->passkey_params.action != BLE_SM_IOACT_NONE) {
        if (res->app_status == 0    &&
            rm                      &&
            proc->flags & BLE_SM_PROC_F_BONDING) {
        if (rm) {
        if (!res->execute) {
    pair_rsp = (struct ble_sm_pair_cmd *) &proc->pair_rsp[1];
    if (proc->flags & BLE_SM_PROC_F_SC) {
    if (rc != 0) {
    if (count < MYNEWT_VAL(BLE_STORE_MAX_BONDS)) {
    if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
    if (proc != NULL) {
        switch (proc->state) {
            if (evt_status == 0) {
                    proc->rx_key_flags == 0) {
            } else {
            if (proc->flags & BLE_SM_PROC_F_AUTHENTICATED) {
            if (proc->flags & BLE_SM_PROC_F_AUTHENTICATED) {
    if (evt_status == 0) {
    if (proc == NULL || proc->state == BLE_SM_PROC_STATE_NONE) {
void
ble_sm_enc_change_rx(const struct ble_hci_ev_enrypt_chg *ev)
void
ble_sm_enc_key_refresh_rx(const struct ble_hci_ev_enc_key_refresh *ev)
    if (value_sec->ediv != ediv || value_sec->rand_num != rand) {
    if (rc != 0) {
    if (le16toh(rsp.conn_handle) != conn_handle) {
    if (rc != 0) {
    if (le16toh(rsp.conn_handle) != conn_handle) {
    if (res->app_status == 0) {
    } else {
    if (value_sec != NULL) {
        if (res->app_status == 0) {
            if (value_sec->authenticated) {
        } else {
    } else {
    if (res->app_status == 0) {
int
ble_sm_ltk_req_rx(const struct ble_hci_ev_le_subev_lt_key_req *ev)
    if (proc == NULL) {
        if (proc == NULL) {
        } else {
    } else if (proc->state == BLE_SM_PROC_STATE_SEC_REQ) {
    } else if (proc->state == BLE_SM_PROC_STATE_LTK_START) {
    } else {
    if (restore) {
    if (proc == NULL) {
    if (res.app_status == 0) {
        if (restore) {
                                            addrs.peer_id_addr.type,
            if (store_rc == 0) {
            } else {
    if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
    } else {
    if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
    } else {
    if (proc->flags & BLE_SM_PROC_F_SC) {
    } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
        if (proc->flags & BLE_SM_PROC_F_SC) {
        } else {
    if (!(proc->flags & BLE_SM_PROC_F_SC)) {
    } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
        if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
        } else {
            if (rc != 0) {
            if (ble_sm_ioact_state(ioact) == proc->state) {
            if (ble_sm_proc_can_advance(proc)) {
    if (proc->flags & BLE_SM_PROC_F_SC) {
    } else {
    pair_req = (struct ble_sm_pair_cmd *) &proc->pair_req[1];
    pair_rsp = (struct ble_sm_pair_cmd *) &proc->pair_rsp[1];
        pair_rsp->authreq & BLE_SM_PAIR_AUTHREQ_SC) {
    if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
    } else {
        pair_rsp->authreq & BLE_SM_PAIR_AUTHREQ_BOND) {
        (init_key_dist == 0 && resp_key_dist == 0)) {
    if (rx_key_dist & BLE_SM_PAIR_KEY_DIST_ENC) {
    if (rx_key_dist & BLE_SM_PAIR_KEY_DIST_ID) {
    if (rx_key_dist & BLE_SM_PAIR_KEY_DIST_SIGN) {
    if (cmd == NULL) {
    if (is_req) {
    } else {
        if (ble_sm_ioact_state(ioact) == proc->state) {
    if (rc != 0) {
    if (res->app_status != 0) {
    if (!is_req) {
    if (!(cmd & BLE_SM_PAIR_AUTHREQ_SC)) {
        if (MYNEWT_VAL(BLE_SM_LEGACY) == 0) {
    if (MYNEWT_VAL(BLE_SM_LVL) >= 3 && !(cmd & BLE_SM_PAIR_AUTHREQ_MITM)) {
    if (res->app_status != 0) {
    if (proc != NULL) {
        if (proc->state != BLE_SM_PROC_STATE_SEC_REQ) {
    if (rc != 0) {
    if (proc != NULL) {
        if (conn->bhc_flags & BLE_HS_CONN_F_MASTER) {
        } else if (MYNEWT_VAL(BLE_SM_LVL) == 1) {
        } else if (req->max_enc_key_size < BLE_SM_PAIR_KEY_SZ_MIN) {
        } else if (req->max_enc_key_size > BLE_SM_PAIR_KEY_SZ_MAX) {
        } else if (MYNEWT_VAL(BLE_SM_SC_ONLY)) {
            if (!(req->authreq & BLE_SM_PAIR_AUTHREQ_SC)) {
            } else if (req->max_enc_key_size != BLE_SM_PAIR_KEY_SZ_MAX) {
        } else if (!ble_sm_verify_auth_requirements(req->authreq)) {
        } else {
    if (res->app_status == 0) {
        if (rc != 0) {
    if (res->app_status != 0) {
    if (proc != NULL) {
        if (rsp->max_enc_key_size < BLE_SM_PAIR_KEY_SZ_MIN) {
        } else if (rsp->max_enc_key_size > BLE_SM_PAIR_KEY_SZ_MAX) {
        } else if (MYNEWT_VAL(BLE_SM_SC_ONLY) && (rsp->max_enc_key_size != BLE_SM_PAIR_KEY_SZ_MAX)) {
            * key size requirements - MITM was checked in last step
            */
        } else if (!ble_sm_verify_auth_requirements(rsp->authreq)) {
        } else {
            if (rc != 0) {
            } else {
                if (ble_sm_ioact_state(ioact) == proc->state) {
                if (ble_sm_proc_can_advance(proc)) {
    if (!cmd) {
    if (rc != 0) {
    if (res->app_status != 0) {
    if (!(conn->bhc_flags & BLE_HS_CONN_F_MASTER)) {
    } else {
    if (res->app_status == 0) {
        if (cmd->authreq & BLE_SM_PAIR_AUTHREQ_BOND) {
        } else {
        if (res->app_status == 0) {
            if (authreq_mitm && !value_sec.authenticated) {
        if (res->app_status == 0) {
        } else {
    if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
    } else {
    if (our_key_dist & BLE_SM_PAIR_KEY_DIST_ENC) {
        if (!enc_info) {
        if (ble_hs_cfg.store_gen_key_cb) {
            if (rc == 0) {
        if (!ltk_gen) {
            if (rc != 0) {
        } else {
        if (rc != 0) {
        if (!master_id) {
        if (!ltk_gen) {
            if (rc != 0) {
            if (rc != 0) {
        } else {
        if (rc != 0) {
    if (our_key_dist & BLE_SM_PAIR_KEY_DIST_ID) {
        if (!id_info) {
        if (rc != 0) {
        if (rc != 0) {
        if (!addr_info) {
        if (rc != 0) {
    if (our_key_dist & BLE_SM_PAIR_KEY_DIST_SIGN) {
        if (!sign_info) {
        if (ble_hs_cfg.store_gen_key_cb) {
            if (rc == 0) {
        } else {
        if (rc != 0) {
            if (rc != 0) {
        } else {
        if (rc != 0) {
    if (proc->flags & BLE_SM_PROC_F_INITIATOR || proc->rx_key_flags == 0) {
    if (proc->rx_key_flags == 0) {
        if (proc->flags & BLE_SM_PROC_F_INITIATOR) {
        } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
    if (res->app_status != 0) {
    if (proc == NULL) {
    } else {
    if (res->app_status == 0) {
        res->sm_err =  cmd->reason;
    while ((proc = STAILQ_FIRST(&exp_list)) != NULL) {
int
ble_sm_pair_initiate(uint16_t conn_handle)
    if (proc != NULL) {
    if (rc != 0) {
    if (proc == NULL) {
    } else {
    if (proc != NULL) {
int
ble_sm_slave_initiate(uint16_t conn_handle)
    if (proc != NULL) {
    } else {
        if (proc == NULL) {
        } else {
    if (proc != NULL) {
int
ble_sm_enc_initiate(uint16_t conn_handle, uint8_t key_size,
                    const uint8_t *ltk, uint16_t ediv,
                    uint64_t rand_val, int auth)
    if (proc != NULL) {
    } else {
        if (proc == NULL) {
        } else {
            if (auth) {
static int
ble_sm_rx(struct ble_l2cap_chan *chan)
    if (conn_handle == BLE_HS_CONN_HANDLE_NONE) {
    if (rc != 0) {
    if (rx_cb != NULL) {
        ble_sm_process_result(conn_handle, &res, op == BLE_SM_OP_PAIR_FAIL ?
                              false : true);
    } else {
int
ble_sm_inject_io(uint16_t conn_handle, struct ble_sm_io *pkey)
    if (proc == NULL) {
    } else if (proc->flags & BLE_SM_PROC_F_IO_INJECTED) {
    } else if ((ble_sm_io_action(proc, &action) == 0) && pkey->action != action) {
    } else if (ble_sm_ioact_state(pkey->action) != proc->state) {
    } else {
        switch (pkey->action) {
                (proc->flags & BLE_SM_PROC_F_ADVANCE_ON_IO)) {
            if (pkey->passkey > 999999) {
            } else {
                    (proc->flags & BLE_SM_PROC_F_ADVANCE_ON_IO)) {
            if (!pkey->numcmp_accept) {
            } else {
                    proc->flags & BLE_SM_PROC_F_ADVANCE_ON_IO) {
                                          (pkey->oob_sc_data.remote != NULL))) {
            } else {
    if (rc != 0) {
void
ble_sm_connection_broken(uint16_t conn_handle)
int
ble_sm_init(void)
                         sizeof (struct ble_sm_proc),
    if (rc != 0) {
    if (!handle) {
    if (cmd == NULL) {
    if (chan == NULL) {
