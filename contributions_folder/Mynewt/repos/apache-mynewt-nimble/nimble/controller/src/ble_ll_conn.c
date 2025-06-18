# Lines added by author
        MODLOG_DFLT(INFO, "Rx'd ctrl PDU; opcode=%d\n", rxbuf[2] & 0x3f);
        MODLOG_DFLT(INFO, "Rx'd data PDU; llid=%d, len=%d\n", llid, acl_len);
static int
ble_ll_conn_tx_pdu(struct ble_ll_conn_sm *connsm)
        // LL control packet
        MODLOG_DFLT(INFO, "Rx'd ctrl PDU; opcode=%d\n", rxbuf[2] & 0x3f); // the opcode is calculated by Copilot, may not be correct
        if (IFW_DC_LL_CTRL_PARSER(connsm, rxpdu) == IFW_VERIFICATION_REJECT)
        if (IFW_DC_L2CAP_PARSER(rxpdu) == IFW_VERIFICATION_REJECT)
        if (IFW_DC_LL_CTRL_PARSER(connsm, rxpdu) == IFW_OPERATION_REJECT)
        if (IFW_DC_L2CAP_PARSER(rxpdu) == IFW_OPERATION_REJECT)
        if (IFW_LL_DC_CTRL_PARSER(connsm, rxpdu) == IFW_OPERATION_REJECT)
        if (IFW_L2CAP_PACKET_PARSER(rxpdu) == IFW_OPERATION_REJECT)
    #error "Maximum # of connections is 254"
    STATS_SECT_ENTRY(cant_set_sched)
    STATS_SECT_ENTRY(conn_ev_late)
    STATS_SECT_ENTRY(wfr_expirations)
    STATS_SECT_ENTRY(handle_not_found)
    STATS_SECT_ENTRY(no_conn_sm)
    STATS_SECT_ENTRY(no_free_conn_sm)
    STATS_SECT_ENTRY(rx_data_pdu_no_conn)
    STATS_SECT_ENTRY(rx_data_pdu_bad_aa)
    STATS_SECT_ENTRY(periph_rxd_bad_conn_req_params)
    STATS_SECT_ENTRY(periph_ce_failures)
    STATS_SECT_ENTRY(data_pdu_rx_dup)
    STATS_SECT_ENTRY(data_pdu_txg)
    STATS_SECT_ENTRY(data_pdu_txf)
    STATS_SECT_ENTRY(conn_req_txd)
    STATS_SECT_ENTRY(l2cap_enqueued)
    STATS_SECT_ENTRY(rx_ctrl_pdus)
    STATS_SECT_ENTRY(rx_l2cap_pdus)
    STATS_SECT_ENTRY(rx_l2cap_bytes)
    STATS_SECT_ENTRY(rx_malformed_ctrl_pdus)
    STATS_SECT_ENTRY(rx_bad_llid)
    STATS_SECT_ENTRY(tx_ctrl_pdus)
    STATS_SECT_ENTRY(tx_ctrl_bytes)
    STATS_SECT_ENTRY(tx_l2cap_pdus)
    STATS_SECT_ENTRY(tx_l2cap_bytes)
    STATS_SECT_ENTRY(tx_empty_pdus)
    STATS_SECT_ENTRY(mic_failures)
    STATS_SECT_ENTRY(sched_start_in_idle)
    STATS_SECT_ENTRY(sched_end_in_idle)
    STATS_SECT_ENTRY(conn_event_while_tmo)
STATS_SECT_DECL(ble_ll_conn_stats) ble_ll_conn_stats;
    STATS_NAME(ble_ll_conn_stats, cant_set_sched)
    STATS_NAME(ble_ll_conn_stats, conn_ev_late)
    STATS_NAME(ble_ll_conn_stats, wfr_expirations)
    STATS_NAME(ble_ll_conn_stats, handle_not_found)
    STATS_NAME(ble_ll_conn_stats, no_conn_sm)
    STATS_NAME(ble_ll_conn_stats, no_free_conn_sm)
    STATS_NAME(ble_ll_conn_stats, rx_data_pdu_no_conn)
    STATS_NAME(ble_ll_conn_stats, rx_data_pdu_bad_aa)
    STATS_NAME(ble_ll_conn_stats, periph_rxd_bad_conn_req_params)
    STATS_NAME(ble_ll_conn_stats, periph_ce_failures)
    STATS_NAME(ble_ll_conn_stats, data_pdu_rx_dup)
    STATS_NAME(ble_ll_conn_stats, data_pdu_txg)
    STATS_NAME(ble_ll_conn_stats, data_pdu_txf)
    STATS_NAME(ble_ll_conn_stats, conn_req_txd)
    STATS_NAME(ble_ll_conn_stats, l2cap_enqueued)
    STATS_NAME(ble_ll_conn_stats, rx_ctrl_pdus)
    STATS_NAME(ble_ll_conn_stats, rx_l2cap_pdus)
    STATS_NAME(ble_ll_conn_stats, rx_l2cap_bytes)
    STATS_NAME(ble_ll_conn_stats, rx_malformed_ctrl_pdus)
    STATS_NAME(ble_ll_conn_stats, rx_bad_llid)
    STATS_NAME(ble_ll_conn_stats, tx_ctrl_pdus)
    STATS_NAME(ble_ll_conn_stats, tx_ctrl_bytes)
    STATS_NAME(ble_ll_conn_stats, tx_l2cap_pdus)
    STATS_NAME(ble_ll_conn_stats, tx_l2cap_bytes)
    STATS_NAME(ble_ll_conn_stats, tx_empty_pdus)
    STATS_NAME(ble_ll_conn_stats, mic_failures)
    STATS_NAME(ble_ll_conn_stats, sched_start_in_idle)
    STATS_NAME(ble_ll_conn_stats, sched_end_in_idle)
    STATS_NAME(ble_ll_conn_stats, conn_event_while_tmo)
struct ble_ll_conn_cth_flow {
    if (!cth->num_buffers) {
    if (cth->num_buffers > cth->max_buffers) {
    if (connsm->cth_flow_pending < credits) {
    } else {
    if (!hci_ev) {
void
ble_ll_conn_cth_flow_set_buffers(uint16_t num_buffers)
bool
ble_ll_conn_cth_flow_enable(bool enabled)
    if (cth->enabled == enabled) {
    if (!SLIST_EMPTY(&g_ble_ll_conn_active_list)) {
void
ble_ll_conn_cth_flow_process_cmd(const uint8_t *cmdbuf)
    if (cmd->length != sizeof(cp->handles) + cp->handles * sizeof(cp->h[0])) {
    for (i = 0; i < cp->handles; i++) {
        if (connsm) {
    if (SLIST_FIRST(&g_ble_ll_conn_css_list) == connsm) {
    } else {
        SLIST_FOREACH(e, &g_ble_ll_conn_css_list, css_sle) {
            if (e == connsm) {
    if (SLIST_EMPTY(&g_ble_ll_conn_css_list)) {
    SLIST_FOREACH(e, &g_ble_ll_conn_css_list, css_sle) {
        if (e->css_slot_idx > connsm->css_slot_idx) {
    if (found_to_insert) {
        if (e_insert_after) {
        } else {
    } else {
void
ble_ll_conn_css_set_next_slot(uint16_t slot_idx)
    if (g_ble_ll_conn_css_next_slot != BLE_LL_CONN_CSS_NO_SLOT) {
    SLIST_FOREACH(connsm, &g_ble_ll_conn_css_list, css_sle) {
            (connsm->css_slot_idx_pending != slot_idx)) {
    if (slot_idx >= ble_ll_sched_css_get_period_slots()) {
int
ble_ll_conn_css_is_slot_busy(uint16_t slot_idx)
    if (g_ble_ll_conn_css_next_slot == slot_idx) {
    SLIST_FOREACH(connsm, &g_ble_ll_conn_css_list, css_sle) {
            (connsm->css_slot_idx_pending == slot_idx)) {
int
ble_ll_conn_css_move(struct ble_ll_conn_sm *connsm, uint16_t slot_idx)
    if (slot_diff < 0) {
    if (offset >= 0xffff) {
    if (!rc) {
    SLIST_FOREACH(connsm, &g_ble_ll_conn_active_list, act_sle) {
            !((connsm->peer_addr_type ^ addr_type) & 1)) {
    if ((pref_mask & BLE_PHY_MASK_2M) && (curr_mask != BLE_PHY_MASK_2M)) {
    if ((curr_mask & pref_mask) == 0) {
int
ble_ll_conn_phy_update_if_needed(struct ble_ll_conn_sm *connsm)
                                       CONN_CUR_RX_PHY_MASK(connsm))) {
void
ble_ll_conn_itvl_to_ticks(uint32_t itvl, uint32_t *itvl_ticks,
                          uint8_t *itvl_usecs)
    if ((llid == BLE_LL_LLID_DATA_FRAG) && (rxbuf[1] == 0)) {
    } else {
int
ble_ll_conn_is_lru(struct ble_ll_conn_sm *s1, struct ble_ll_conn_sm *s2)
    if (LL_TMR_LT(s1->last_scheduled, s2->last_scheduled)) {
    } else {
    if (g_ble_ll_conn_cur_sm) {
    } else {
    if (connsm) {
    if ((handle != 0) && (handle <= MYNEWT_VAL(BLE_MAX_CONNECTIONS))) {
        if (connsm->conn_state == BLE_LL_CONN_STATE_IDLE) {
    if (connsm) {
    } else {
    if (curchan > BLE_PHY_NUM_DATA_CHANS) {
    if (conn->chan_map[curchan >> 3] & bitpos) {
    if (conn->flags.csa2) {
    while (latency > 0) {
void
ble_ll_conn_wfr_timer_exp(void)
        g_ble_ll_sched_offset_ticks;
    if (connsm->max_ce_len_ticks) {
        if (LL_TMR_LT(connsm->anchor_point + connsm->max_ce_len_ticks, ce_end)) {
    if (ble_ll_sched_next_time(&next_sched_time)) {
        if (LL_TMR_LT(next_sched_time, ce_end)) {
    if (connsm->flags.encrypt_ltk_req) {
        if (ble_ll_hci_ev_ltk_req(connsm)) {
    if (connsm->flags.conn_update_host_w4event) {
        if (IS_PENDING_CTRL_PROC(connsm, BLE_LL_CTRL_PROC_CONN_UPDATE)) {
        } else {
            if (IS_PENDING_CTRL_PROC(connsm, BLE_LL_CTRL_PROC_CONN_PARAM_REQ)) {
    if (connsm->flags.phy_update_host_w4event) {
        if (!ble_ll_hci_ev_phy_update(connsm, BLE_ERR_SUCCESS)) {
    if (connsm->flags.subrate_ind_txd) {
    if (connsm->phy_tx_transition) {
    } else {
    if (connsm->flags.encrypted) {
    if (ret > connsm->eff_max_tx_octets) {
    if (ret > max_pyld_len) {
    if (connsm->flags.terminate_ind_rxd) {
    if (!connsm->cur_tx_pdu && !connsm->flags.empty_pdu_txd && !pkthdr) {
    if (!connsm->cur_tx_pdu && !connsm->flags.empty_pdu_txd) {
             CONN_IS_PERIPHERAL(connsm))) {
            if (!ble_ll_ctrl_enc_allowed_pdu_tx(pkthdr)) {
            if (nextpkthdr && !ble_ll_ctrl_enc_allowed_pdu_tx(nextpkthdr)
                && (CONN_IS_CENTRAL(connsm) ||
                    !ble_ll_ctrl_is_start_enc_rsp(m))) {
        if (llid == BLE_LL_LLID_CTRL) {
        } else {
    } else {
        if (connsm->cur_tx_pdu) {
            if (cur_offset == 0) {
            if (connsm->enc_data.enc_state > CONN_ENC_S_ENCRYPTED) {
                if (nextpkthdr && !ble_ll_ctrl_enc_allowed_pdu_tx(nextpkthdr)
                    && (CONN_IS_CENTRAL(connsm) ||
                        !ble_ll_ctrl_is_start_enc_rsp(connsm->cur_tx_pdu))) {
        } else {
            if (connsm->enc_data.enc_state > CONN_ENC_S_ENCRYPTED) {
                if (nextpkthdr && !ble_ll_ctrl_enc_allowed_pdu_tx(nextpkthdr)) {
    if (nextpkthdr || ((cur_offset + cur_txlen) < pktlen)) {
        if ((cur_offset + cur_txlen) < pktlen) {
        } else {
        if (next_txlen > connsm->eff_max_tx_octets) {
        if (connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
        if (LL_TMR_LT(ble_ll_tmr_get() + ticks, next_event_time)) {
    if (connsm->flags.empty_pdu_txd) {
    if (connsm->tx_seqnum) {
    if (md) {
    if (connsm->next_exp_seqnum) {
         !ble_ll_ctrl_is_terminate_ind(hdr_byte, m->om_data[0]))) {
    } else {
    if (llid == BLE_LL_LLID_CTRL) {
    } else {
    if (is_ctrl && (opcode == BLE_LL_CTRL_START_ENC_RSP)) {
        if (txend_func == NULL) {
    } else if (is_ctrl && (opcode == BLE_LL_CTRL_START_ENC_REQ)) {
        if (txend_func == NULL) {
        } else {
    } else if (is_ctrl && (opcode == BLE_LL_CTRL_PAUSE_ENC_RSP)) {
        switch (connsm->conn_role) {
            if (txend_func == NULL) {
            } else {
    } else {
        if (connsm->flags.encrypted) {
            if (txend_func == NULL) {
    if (!rc) {
        if (connsm->flags.empty_pdu_txd) {
            if (connsm->flags.terminate_ind_rxd) {
        } else if ((hdr_byte & BLE_LL_DATA_HDR_LLID_MASK) == BLE_LL_LLID_CTRL) {
        } else {
    if (connsm->conn_state == BLE_LL_CONN_STATE_IDLE) {
    switch (connsm->conn_role) {
        if (!rc) {
            if (connsm->flags.encrypted) {
            } else {
            if (!rc) {
            } else {
        } else {
        if (connsm->flags.encrypted) {
        } else {
        if (rc) {
        } else {
    if (rc == BLE_LL_SCHED_STATE_DONE) {
    if (connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
        if (!txpdu) {
            if (pkthdr) {
        } else {
        if (txpdu) {
            if (rem_bytes > connsm->eff_max_tx_octets) {
        } else {
        if ((usecs + add_usecs) >= allowed_usecs) {
void
ble_ll_conn_auth_pyld_timer_cb(struct ble_npl_event *ev)
void
ble_ll_conn_auth_pyld_timer_start(struct ble_ll_conn_sm *connsm)
void
ble_ll_conn_central_init(struct ble_ll_conn_sm *connsm,
                         struct ble_ll_conn_create_scan *cc_scan,
                         struct ble_ll_conn_create_params *cc_params)
int
ble_ll_conn_set_data_len(struct ble_ll_conn_sm *connsm,
                         uint16_t tx_octets, uint16_t tx_time,
                         uint16_t rx_octets, uint16_t rx_time)
    if (!ble_ll_conn_rem_feature_check(connsm, BLE_LL_FEAT_LE_CODED_PHY)) {
    if (connsm->max_tx_time != tx_time) {
    if (connsm->max_tx_octets != tx_octets) {
    if (rx_time && (connsm->max_rx_time != rx_time)) {
    if (rx_octets && (connsm->max_rx_octets != rx_octets)) {
    if (init_dle) {

    if (phy == BLE_PHY_CODED) {
    } else {
    if (chsel) {
                              (connsm->access_addr & 0x0000ffff);
void
ble_ll_conn_sm_new(struct ble_ll_conn_sm *connsm)
        (connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL)) {
void
ble_ll_conn_update_eff_data_len(struct ble_ll_conn_sm *connsm)
    if (connsm->phy_data.cur_rx_phy == BLE_PHY_CODED) {
    if (eff_time != connsm->eff_max_rx_time) {
    if (connsm->phy_data.cur_tx_phy == BLE_PHY_CODED) {
    if (eff_time != connsm->eff_max_tx_time) {
    if (eff_bytes != connsm->eff_max_rx_octets) {
    if (eff_bytes != connsm->eff_max_tx_octets) {
    if (ota_max_rx_time_calc) {
    if (send_event) {
void
ble_ll_conn_end(struct ble_ll_conn_sm *connsm, uint8_t ble_err)
    if (g_ble_ll_conn_cur_sm == connsm) {
        (connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL)) {
        if (connsm == g_ble_ll_conn_css_ref) {
    if (connsm->cur_tx_pdu) {
    while (1) {
        if (!pkthdr) {
        connsm->flags.features_rxd) {
    if (connsm->flags.features_host_req) {
                    connsm->flags.terminate_ind_rxd)) {
void
ble_ll_conn_get_anchor(struct ble_ll_conn_sm *connsm, uint16_t conn_event,
                       uint32_t *anchor, uint8_t *anchor_usecs)
    if ((int16_t)(conn_event - connsm->event_cntr) < 0) {
    } else {
int
ble_ll_conn_move_anchor(struct ble_ll_conn_sm *connsm, uint16_t offset)
        IS_PENDING_CTRL_PROC(connsm, BLE_LL_CTRL_PROC_CONN_UPDATE)) {
    if (connsm->disconnect_reason && !connsm->flags.terminate_started) {
    if (connsm->flags.terminate_started && CONN_IS_PERIPHERAL(connsm)) {
    if (connsm->has_nonempty_pdu) {
    } else if (connsm->event_cntr == connsm->subrate_base_event) {
    if (connsm->cont_num_left > 0) {
    if (next_is_subrated) {
        if (use_periph_latency) {
        if (connsm->flags.subrate_trans) {
            while (INT16_LTE(trans_next_event_cntr, connsm->event_cntr)) {
            if (INT16_LT(trans_next_event_cntr, next_event_cntr)) {
    } else {

        (connsm->subrate_factor > 1)) {
        if (connsm->event_cntr == subrate_conn_upd_event_cntr) {
        if (INT16_GT(next_event_cntr, subrate_conn_upd_event_cntr)) {
         connsm->subrate_factor == next_event_cntr)) {
        connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
        if (g_ble_ll_conn_css_ref != connsm) {
    if (!skip_anchor_calc) {
        if (event_cntr_diff == 1) {
        } else {
        (connsm->event_cntr == connsm->conn_update_req.instant)) {
            (connsm->supervision_tmo != upd->timeout)) {
        if (connsm->conn_itvl != upd->interval) {
            connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
            if (connsm->css_slot_idx_pending < connsm->css_slot_idx) {
            if (anchor_calc_for_css) {
        if (connsm->conn_param_req.handle != 0) {
        if (upd->winoffset != 0) {
        ((int16_t)(connsm->chanmap_instant - connsm->event_cntr) <= 0)) {
    if (anchor_calc_for_css) {
        (connsm->event_cntr == connsm->phy_instant)) {
        if (connsm->phy_data.new_tx_phy) {
                                ble_ll_phy_to_phy_mode(connsm->phy_data.cur_tx_phy,
                                                   connsm->phy_data.pref_opts);
        if (connsm->phy_data.new_rx_phy) {
                                ble_ll_phy_to_phy_mode(connsm->phy_data.cur_rx_phy,
                                                   connsm->phy_data.pref_opts);
            !ble_ll_conn_rem_feature_check(connsm, BLE_LL_FEAT_LE_CODED_PHY)) {
    if (connsm->flags.terminate_started) {
        if ((int32_t)(connsm->terminate_timeout - connsm->anchor_point) <= 0) {
        connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
    } else {
                                     BLE_LL_SCHED_USECS_PER_SLOT);
    if (connsm->conn_role == BLE_LL_CONN_ROLE_PERIPHERAL) {
        max_ww = (connsm->conn_itvl * (BLE_LL_CONN_ITVL_USECS/2)) - BLE_LL_IFS;
        if (cur_ww >= max_ww) {
    if (connsm->conn_role == BLE_LL_CONN_ROLE_PERIPHERAL) {
                                       rxhdr->rxinfo.phy_mode);
        if (rxhdr->rxinfo.channel < BLE_PHY_NUM_DATA_CHANS) {
            switch (rxhdr->rxinfo.phy) {
                                             BLE_LL_SCHED_USECS_PER_SLOT +
                                             connsm->periph_cur_tx_win_usecs) + 1;
        while (ble_ll_sched_conn_periph_new(connsm)) {
            if (ble_ll_conn_next_event(connsm)) {
    if (rc) {
        if (!ble_ll_conn_phy_update_if_needed(connsm)) {
        switch (connsm->conn_role) {
            if (ble_ll_sched_css_is_enabled()) {
         connsm->flags.terminate_ind_rxd_acked)) {
        if (connsm->flags.terminate_ind_txd) {
        } else {
            if (ble_err == 0) {
    if (connsm->flags.pkt_rxd) {
    if (ble_ll_conn_next_event(connsm)) {
    while (ble_ll_sched_conn_reschedule(connsm)) {
        if (ble_ll_conn_next_event(connsm)) {
    if (connsm->conn_state == BLE_LL_CONN_STATE_CREATED) {
    } else {
    if ((int32_t)(connsm->anchor_point - connsm->last_rxd_pdu_cputime) >= tmo) {
        connsm->flags.features_rxd) {
void
ble_ll_conn_prepare_connect_ind(struct ble_ll_conn_sm *connsm,
                                struct ble_ll_scan_pdu_data *pdu_data,
                                struct ble_ll_scan_addr_data *addrd,
                                uint8_t channel)
    if (channel >= BLE_PHY_NUM_DATA_CHANS) {
    if (addrd->adva_type) {
    if (addrd->targeta) {
        if (addrd->targeta_resolved) {
            if (connsm->own_addr_type > BLE_OWN_ADDR_RANDOM) {
            } else {
                if ((connsm->own_addr_type & 1) == 0) {
                } else {
        } else {
            if (addrd->targeta_type) {
        if (addrd->targeta_type) {
    } else {
        if ((connsm->own_addr_type & 1) == 0) {
        } else {
    /* XXX: do this ahead of time? Calculate the local rpa I mean */
            (addrd->rpa_index >= 0)) {
            if (rl->rl_has_local) {
        if (addr) {
void
ble_ll_conn_event_halt(void)
    if (g_ble_ll_conn_cur_sm) {
int
ble_ll_conn_send_connect_req(struct os_mbuf *rxpdu,
                             struct ble_ll_scan_addr_data *addrd,
                             uint8_t ext)
    if (ext) {
    if (ble_ll_sched_conn_central_new(connsm, rxhdr, 0)) {
    if (rc) {
    if (ext) {
void
ble_ll_conn_send_connect_req_cancel(void)
    if (addrd->adva_resolved) {
    } else {
    if (addrd->targeta_resolved) {
void
ble_ll_conn_created_on_legacy(struct os_mbuf *rxpdu,
                              struct ble_ll_scan_addr_data *addrd,
                              uint8_t *targeta)
void
ble_ll_conn_created_on_aux(struct os_mbuf *rxpdu,
                           struct ble_ll_scan_addr_data *addrd,
                           uint8_t *targeta)
void
ble_ll_conn_timeout(struct ble_ll_conn_sm *connsm, uint8_t ble_err)
    if (g_ble_ll_conn_cur_sm == connsm) {
    if (was_current) {
int
ble_ll_conn_rx_isr_start(struct ble_mbuf_hdr *rxhdr, uint32_t aa)
    if (connsm) {
        if (aa != connsm->access_addr) {
        if (connsm->flags.periph_set_last_anchor) {
void
ble_ll_conn_rx_data_pdu(struct os_mbuf *rxpdu, struct ble_mbuf_hdr *hdr)
    if (!connsm) {
       STATS_INC(ble_ll_conn_stats, no_conn_sm);
       goto conn_rx_data_pdu_end;
    if (BLE_MBUF_HDR_MIC_FAILURE(hdr)) {
        if (rxd_sn != connsm->last_rxd_sn) {
    if ((llid == 0) || ((acl_len == 0) && (llid != BLE_LL_LLID_DATA_FRAG))) {
         CONN_IS_PERIPHERAL(connsm))) {
        if (!ble_ll_ctrl_enc_allowed_pdu_rx(rxpdu)) {
        connsm->flags.le_ping_supp && (acl_len != 0)) {
    if (connsm->conn_role == BLE_LL_CONN_ROLE_PERIPHERAL) {
        if (hdr_byte & BLE_LL_DATA_HDR_NESN_MASK) {
    if (rxd_sn == connsm->last_rxd_sn) {
       STATS_INC(ble_ll_conn_stats, data_pdu_rx_dup);
       goto conn_rx_data_pdu_end;
   }
    if ((llid == BLE_LL_LLID_DATA_FRAG) && (acl_len == 0)) {
    if (llid == BLE_LL_LLID_CTRL) {
        if (ble_ll_ctrl_rx_pdu(connsm, rxpdu)) {
    } else {
    if (hdr->rxinfo.flags & BLE_MBUF_HDR_F_CONN_CREDIT_INT) {
    if (hdr->rxinfo.flags & BLE_MBUF_HDR_F_CONN_CREDIT) {
int
ble_ll_conn_rx_isr_end(uint8_t *rxbuf, struct ble_mbuf_hdr *rxhdr)
    if (!BLE_MBUF_HDR_CRC_OK(rxhdr)) {
    if (alloc_rxpdu && BLE_LL_LLID_IS_DATA(hdr_byte) && (rx_pyld_len > 0)) {
        if (hci_ipc_get(HCI_IPC_TYPE_ACL)) {
        } else {
        BLE_LL_LLID_IS_DATA(hdr_byte) && (rx_pyld_len > 0)) {
        if (ble_ll_conn_cth_flow_alloc_credit(connsm)) {
        } else {
    if (alloc_rxpdu) {
    if (!connsm) {
    if (!BLE_MBUF_HDR_CRC_OK(rxhdr)) {
        if (connsm->cons_rxd_bad_crc >= 2) {
        } else {
            switch (connsm->conn_role) {
    } else {
        if (BLE_LL_LLID_IS_CTRL(hdr_byte)) {
        if (rxpdu && ((hdr_sn && conn_nesn) || (!hdr_sn && !conn_nesn))) {
            if (connsm->flags.encrypted && !ble_ll_conn_is_empty_pdu(rxbuf)) {
        if (connsm->flags.empty_pdu_txd || connsm->cur_tx_pdu) {
            if ((hdr_nesn && conn_sn) || (!hdr_nesn && !conn_sn)) {
            } else {
                if (connsm->flags.empty_pdu_txd) {
                if (txpdu) {
                    if (connsm->enc_data.tx_encrypted) {
                    if ((txhdr->txinfo.hdr_byte & BLE_LL_DATA_HDR_LLID_MASK)
                        == BLE_LL_LLID_CTRL) {
                        if (rc) {
                        } else {
                    if (txhdr->txinfo.offset >= OS_MBUF_PKTLEN(txpdu)) {
                        if (txhdr->txinfo.pyld_len != 0) {
                            if (connsm->completed_pkts > 2) {
                    } else {
                            (opcode == BLE_LL_CTRL_PHY_UPDATE_IND)) {
                                    ble_ll_ctrl_phy_tx_transition_get(rxbuf[3]);
chk_rx_terminate_ind:
            (rx_pyld_len == (1 + BLE_LL_CTRL_TERMINATE_IND_LEN))) {
        switch (connsm->conn_role) {
    if (rx_pyld_len && connsm->flags.encrypted) {
    if (reply && ble_ll_conn_can_send_next_pdu(connsm, begtime, add_usecs)) {
    if (rxpdu) {
    if (rc) {
void
ble_ll_conn_enqueue_pkt(struct ble_ll_conn_sm *connsm, struct os_mbuf *om,
                        uint8_t hdr_byte, uint16_t length)
    if (hdr_byte == BLE_LL_LLID_CTRL) {
    if (connsm->enc_data.enc_state > CONN_ENC_S_ENCRYPTED) {
        if (llid == BLE_LL_LLID_CTRL) {
            switch (om->om_data[0]) {
                if (connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
                if (connsm->enc_data.enc_state == CONN_ENC_S_PAUSED) {
    if (lifo) {
    } else {
void
ble_ll_conn_tx_pkt_in(struct os_mbuf *om, uint16_t handle, uint16_t length)
    if (connsm) {
        if (pb == 0) {
        } else {
    } else {
void
ble_ll_conn_chan_map_update(void)
    SLIST_FOREACH(connsm, &g_ble_ll_conn_active_list, act_sle) {
        if (connsm->conn_role == BLE_LL_CONN_ROLE_CENTRAL) {
int
ble_ll_conn_periph_start(uint8_t *rxbuf, uint8_t pat, struct ble_mbuf_hdr *rxhdr,
                         bool force_csa2)
    SLIST_FOREACH(connsm, &g_ble_ll_conn_active_list, act_sle) {
        if (!memcmp(&connsm->peer_addr, inita, BLE_DEV_ADDR_LEN)) {
            if (rxbuf[0] & BLE_ADV_PDU_HDR_TXADD_MASK) {
                if (connsm->peer_addr_type & 1) {
            } else {
                if ((connsm->peer_addr_type & 1) == 0) {
    if (connsm == NULL) {
        (connsm->hop_inc < 5) || (connsm->hop_inc > 16)) {
    if ((connsm->supervision_tmo * 10000) <= temp ) {
    if (temp > 8) {
    if (connsm->tx_win_size > temp) {
    if (connsm->chan_map_used < 2) {
    if (!rc) {
int
ble_ll_conn_subrate_req_hci(struct ble_ll_conn_sm *connsm,
                            struct ble_ll_conn_subrate_req_params *srp)
        (srp->supervision_tmo < 0x000a) || (srp->supervision_tmo > 0x0c80)) {
    if (srp->subrate_max * (srp->max_latency + 1) > 500) {
    if (t1 > t2) {
    if (srp->subrate_max < srp->subrate_min) {
    if (srp->cont_num >= srp->subrate_max) {
                                       BLE_LL_FEAT_CONN_SUBRATING_HOST)) {
    if (connsm->cur_ctrl_proc == BLE_LL_CTRL_PROC_CONN_PARAM_REQ) {
    switch (connsm->conn_role) {

int
ble_ll_conn_subrate_req_llcp(struct ble_ll_conn_sm *connsm,
                             struct ble_ll_conn_subrate_req_params *srp)
        (srp->supervision_tmo < 0x000a) || (srp->supervision_tmo > 0x0c80)) {
    if (connsm->cur_ctrl_proc == BLE_LL_CTRL_PROC_CONN_PARAM_REQ) {
          (srp->max_latency + 1)) * 2 >= srp->supervision_tmo *
                                         BLE_HCI_CONN_SPVN_TMO_UNITS * 1000)) {
void
ble_ll_conn_subrate_set(struct ble_ll_conn_sm *connsm,
                        struct ble_ll_conn_subrate_params *sp)
    if (send_ev) {
void
ble_ll_conn_module_reset(void)
    if (g_ble_ll_conn_cur_sm) {
    if (g_ble_ll_conn_comp_ev) {
    while (1) {
        if (!connsm) {
void
ble_ll_conn_module_init(void)
    for (i = 0; i < MYNEWT_VAL(BLE_MAX_CONNECTIONS); ++i) {
