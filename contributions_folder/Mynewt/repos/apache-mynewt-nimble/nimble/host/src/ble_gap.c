# Lines added by author
#define BLE_GAP_OP_NULL             0
#define BLE_GAP_OP_M_DISC           1
#define BLE_GAP_OP_M_CONN           2
#define BLE_GAP_OP_S_ADV            1
#define BLE_GAP_OP_S_PERIODIC_ADV   2
#define BLE_GAP_OP_SYNC             1
#define BLE_GAP_CANCEL_RETRY_TIMEOUT_MS         100 /* ms */
#define BLE_GAP_UPDATE_TIMEOUT_MS               40000 /* ms */
struct ble_gap_master_state {
    uint8_t exp_set:1;
    union {
        struct {
            uint8_t using_wl:1;
            uint8_t our_addr_type:2;
            uint8_t cancel:1;
        struct {
            uint8_t limited:1;
struct ble_gap_sync_state {
struct ble_gap_slave_state {
    unsigned int our_addr_type:2;
    unsigned int preempted:1;  /** Set to 1 if advertising was preempted. */
    unsigned int connectable:1;
    unsigned int configured:1; /** If instance is configured */
    unsigned int scannable:1;
    unsigned int directed:1;
    unsigned int high_duty_directed:1;
    unsigned int legacy_pdu:1;
    unsigned int rnd_addr_set:1;
    unsigned int periodic_configured:1;
    uint8_t      periodic_op;
/* timer is used only with legacy advertising */
    unsigned int exp_set:1;
struct ble_gap_update_entry {
    SLIST_ENTRY(ble_gap_update_entry) next;
struct ble_gap_snapshot {
static os_membuf_t ble_gap_update_entry_mem[
                        OS_MEMPOOL_SIZE(MYNEWT_VAL(BLE_GAP_MAX_PENDING_CONN_PARAM_UPDATE),
                                        sizeof (struct ble_gap_update_entry))];
STATS_SECT_DECL(ble_gap_stats) ble_gap_stats;
    STATS_NAME(ble_gap_stats, wl_set)
    STATS_NAME(ble_gap_stats, wl_set_fail)
    STATS_NAME(ble_gap_stats, adv_stop)
    STATS_NAME(ble_gap_stats, adv_stop_fail)
    STATS_NAME(ble_gap_stats, adv_start)
    STATS_NAME(ble_gap_stats, adv_start_fail)
    STATS_NAME(ble_gap_stats, adv_set_data)
    STATS_NAME(ble_gap_stats, adv_set_data_fail)
    STATS_NAME(ble_gap_stats, adv_rsp_set_data)
    STATS_NAME(ble_gap_stats, adv_rsp_set_data_fail)
    STATS_NAME(ble_gap_stats, discover)
    STATS_NAME(ble_gap_stats, discover_fail)
    STATS_NAME(ble_gap_stats, initiate)
    STATS_NAME(ble_gap_stats, initiate_fail)
    STATS_NAME(ble_gap_stats, terminate)
    STATS_NAME(ble_gap_stats, terminate_fail)
    STATS_NAME(ble_gap_stats, cancel)
    STATS_NAME(ble_gap_stats, cancel_fail)
    STATS_NAME(ble_gap_stats, update)
    STATS_NAME(ble_gap_stats, update_fail)
    STATS_NAME(ble_gap_stats, connect_mst)
    STATS_NAME(ble_gap_stats, connect_slv)
    STATS_NAME(ble_gap_stats, disconnect)
    STATS_NAME(ble_gap_stats, rx_disconnect)
    STATS_NAME(ble_gap_stats, rx_update_complete)
    STATS_NAME(ble_gap_stats, rx_adv_report)
    STATS_NAME(ble_gap_stats, rx_conn_complete)
    STATS_NAME(ble_gap_stats, discover_cancel)
    STATS_NAME(ble_gap_stats, discover_cancel_fail)
    STATS_NAME(ble_gap_stats, security_initiate)
    STATS_NAME(ble_gap_stats, security_initiate_fail)
int
ble_gap_dbg_update_active(uint16_t conn_handle)
    if (duration_ms == BLE_HS_FOREVER) {
    } else {
    if (peer_addr != NULL) {
    for (i = 0; i < white_list_count; i++, addr++) {
    if (direct_addr) {
    if (conn->bhc_flags & BLE_HS_CONN_F_MASTER) {
    } else {
    if (conn != NULL) {
    if (conn == NULL) {
    } else {
int
ble_gap_conn_find(uint16_t handle, struct ble_gap_conn_desc *out_desc)
    if (conn != NULL && out_desc != NULL) {
    if (conn == NULL) {
    } else {
int
ble_gap_conn_find_by_addr(const ble_addr_t *addr,
                          struct ble_gap_conn_desc *out_desc)
    if (!ble_hs_is_enabled()) {
    if (conn != NULL && out_desc != NULL) {
    if (conn == NULL) {
int
ble_gap_conn_find_handle_by_addr(const ble_addr_t *addr, uint16_t *out_conn_handle)
    if (conn != NULL) {
    } else {
    if (conn == NULL) {
struct foreach_handle_cb_arg {
void
ble_gap_conn_foreach_handle(ble_gap_conn_foreach_handle_fn *cb, void *arg)
    if (conn != NULL) {
    } else {
    if (conn == NULL) {
    } else {
int
ble_gap_set_priv_mode(const ble_addr_t *peer_addr, uint8_t priv_mode)
    if (!ble_hs_is_enabled()) {
int
ble_gap_read_le_phy(uint16_t conn_handle, uint8_t *tx_phy, uint8_t *rx_phy)
    if (!ble_hs_is_enabled()) {
    if (conn == NULL) {
    if (rc != 0) {
    if (le16toh(rsp.conn_handle) != conn_handle) {
int
ble_gap_set_prefered_default_le_phy(uint8_t tx_phys_mask, uint8_t rx_phys_mask)
                        BLE_HCI_LE_PHY_CODED_PREF_MASK)) {
                        BLE_HCI_LE_PHY_CODED_PREF_MASK)) {
    if (!ble_hs_is_enabled()) {
    if (tx_phys_mask == 0) {
    } else {
    if (rx_phys_mask == 0) {
    } else {
                            &cmd, sizeof(cmd), NULL, 0);
int
ble_gap_set_prefered_le_phy(uint16_t conn_handle, uint8_t tx_phys_mask,
                   uint8_t rx_phys_mask, uint16_t phy_opts)
    if (!ble_hs_is_enabled()) {
    if (conn == NULL) {
                        BLE_HCI_LE_PHY_CODED_PREF_MASK)) {
                        BLE_HCI_LE_PHY_CODED_PREF_MASK)) {
    if (phy_opts > BLE_HCI_LE_PHY_CODED_S8_PREF) {
    if (tx_phys_mask == 0) {
    } else {
    if (rx_phys_mask == 0) {
    } else {
    if (cb != NULL) {
    } else {
        if (event->type == BLE_GAP_EVENT_CONN_UPDATE_REQ) {
    if (rc != 0) {
    if (rc != 0) {
    if (ble_gap_master.preempted_op != BLE_GAP_OP_NULL) {
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (ble_gap_slave[i].preempted) {
    if (!out_state) {
    if (reset_state) {
    if (cb != NULL) {
    if (ble_gap_has_client(&state)) {
    } else {
    if (state.cb != NULL) {
        if (state.conn.cancel) {
        } else {
    if (ble_gap_has_client(&state)) {
    if (ble_gap_has_client(&state)) {
    if (status == BLE_HS_ETIMEOUT) {
    if (ble_gap_master.op == BLE_GAP_OP_NULL || !ble_gap_master.exp_set) {
    if (ticks > 0) {
    if (ble_gap_slave[0].op == BLE_GAP_OP_NULL || !ble_gap_slave[0].exp_set) {
    if (ticks > 0) {
    SLIST_FOREACH(entry, &ble_gap_update_entries, next) {
        if (ticks <= 0) {
        if (ticks < best_ticks) {
    if (out_ticks_from_now != NULL) {

    switch (ble_gap_master.op) {
    if (rc != 0) {
    if (entry != NULL) {
    ble_hs_flow_connection_broken(conn_handle);;
void
ble_gap_rx_disconn_complete(const struct ble_hci_ev_disconn_cmp *ev)
    if (ev->status == 0) {
    } else {
void
ble_gap_rx_update_complete(const struct ble_hci_ev_le_subev_conn_upd_complete *ev)
    if (conn != NULL) {
        switch (ev->status) {
            if (entry != NULL && !(conn->bhc_flags & BLE_HS_CONN_F_MASTER)) {
    if (l2cap_params.itvl_min == 0) {
    if (l2cap_params.itvl_min != 0) {
        if (rc == 0) {
        } else {
    } else {
    if (call_cb) {
int
ble_gap_master_in_progress(void)
    if (instance >= BLE_ADV_INSTANCES) {
void
ble_gap_reset_state(int reason)
    while (1) {
        if (conn_handle == BLE_HS_CONN_HANDLE_NONE) {
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (ble_gap_adv_active_instance(i)) {
    if (ble_gap_adv_active_instance(0)) {
    switch (ble_gap_master.op) {
    if (rc == 0) {
    if (instance >= BLE_ADV_INSTANCES) {
       rc = BLE_HS_ENOENT;
    } else if (!ble_gap_adv_active_instance(instance)) {
    } else {
        if (ble_gap_slave[instance].connectable) {
        } else {
    if (rc == 0) {
    if (ble_gap_master.op != BLE_GAP_OP_M_DISC) {
    if (ble_gap_master.disc.limited) {
            !(flags->value[0] & BLE_HS_ADV_F_DISC_LTD)) {
void
ble_gap_rx_adv_report(struct ble_gap_disc_desc *desc)
    if (ble_gap_rx_adv_report_sanity_check(desc->data, desc->length_data)) {
void
ble_gap_rx_le_scan_timeout(void)
void
ble_gap_rx_ext_adv_report(struct ble_gap_ext_disc_desc *desc)
    if (ble_gap_rx_adv_report_sanity_check(desc->data, desc->length_data)) {
void
ble_gap_rx_adv_set_terminated(const struct ble_hci_ev_le_subev_adv_set_terminated *ev)
    if (ev->status) {
    } else {
void
ble_gap_rx_scan_req_rcvd(const struct ble_hci_ev_le_subev_scan_req_rcvd *ev)
    if (cb != NULL) {
void
ble_gap_rx_peroidic_adv_sync_estab(const struct ble_hci_ev_le_subev_periodic_adv_sync_estab *ev)
    if (!ev->status) {
    } else {
    if (cb) {
void
ble_gap_rx_periodic_adv_rpt(const struct ble_hci_ev_le_subev_periodic_adv_rpt *ev)
    if (psync) {
    if (!psync || !cb) {
     cb(&event, cb_arg);
void
ble_gap_rx_periodic_adv_sync_lost(const struct ble_hci_ev_le_subev_periodic_adv_sync_lost *ev)
    if (cb) {
void
ble_gap_rx_le_pathloss_threshold(const struct ble_hci_ev_le_subev_path_loss_threshold *ev)
void
ble_gap_rx_transmit_power_report(const struct ble_hci_ev_le_subev_transmit_power_report *ev)
    if (!rc) {
void
ble_gap_rx_periodic_adv_sync_transfer(const struct ble_hci_ev_le_subev_periodic_adv_sync_transfer *ev)
    if (!conn || !conn->psync) {
        if (!ev->status) {
    if (ev->status) {
    } else {
void
ble_gap_rx_biginfo_adv_rpt(const struct ble_hci_ev_le_subev_biginfo_adv_report *ev)
    if (psync) {
    if (cb) {
void
ble_gap_rx_subrate_change(const struct ble_hci_ev_le_subev_subrate_change *ev)
int
ble_gap_rx_conn_complete(struct ble_gap_conn_complete *evt, uint8_t instance)
    if (evt->status != BLE_ERR_SUCCESS) {
        switch (evt->status) {
            if (ble_gap_adv_active()) {
            if (ble_gap_master_in_progress()) {
                if (ble_gap_master.preempted_op == BLE_GAP_OP_M_CONN) {
                } else {
                             "complete event: %u", evt->status);
    if (ble_hs_atomic_conn_flags(evt->connection_handle, NULL) == 0) {
    switch (evt->role) {
        if (rc != 0) {
        if (rc != 0) {
    if (evt->role == BLE_HCI_LE_CONN_COMPLETE_ROLE_MASTER) {
    } else {
    if (memcmp(BLE_ADDR_ANY->val, evt->peer_rpa, 6) == 0) {
        if (BLE_ADDR_IS_RPA(&conn->bhc_peer_addr)) {
    } else {
void
ble_gap_rx_rd_rem_sup_feat_complete(const struct ble_hci_ev_le_subev_rd_rem_used_feat *ev)
    if ((conn != NULL) && (ev->status == 0)) {
int
ble_gap_rx_l2cap_update_req(uint16_t conn_handle,
                            struct ble_gap_upd_params *params)
void
ble_gap_rx_phy_update_complete(const struct ble_hci_ev_le_subev_phy_update_complete *ev)
    if (ticks_until_exp != 0) {
    switch (ble_gap_master.op) {
        if (rc != 0) {
        } else {
        if (rc != 0) {
    if (ticks_until_exp != 0) {
    if (rc != 0) {
    do {
        if (ticks_until_exp == 0) {
        } else {
        if (entry != NULL) {
int
ble_gap_set_event_cb(uint16_t conn_handle, ble_gap_event_fn *cb, void *cb_arg)
    if (conn != NULL) {
    if (conn == NULL) {
    if (addr->type > BLE_ADDR_RANDOM) {
                             NULL, 0, NULL, 0 );
int
ble_gap_wl_set(const ble_addr_t *addrs, uint8_t white_list_count)
    if (!ble_hs_is_enabled()) {
    for (i = 0; i < white_list_count; i++) {
            addrs[i].type != BLE_ADDR_RANDOM) {
    if (ble_gap_wl_busy()) {
    if (rc != 0) {
    for (i = 0; i < white_list_count; i++) {
        if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
    if (!active) {
    } else {
    if (rc != 0) {
int
ble_gap_adv_stop(void)
    if (!ble_hs_is_enabled()) {
    switch (adv_params->conn_mode) {
        if (adv_params->disc_mode == BLE_GAP_DISC_MODE_NON) {
        } else {
        if (adv_params->high_duty_cycle) {
        } else {
    switch (conn_mode) {
    if ((adv_params->itvl_min == 0) && (adv_params->itvl_max == 0)) {
    } else {
    if (peer_addr == NULL) {
    if (adv_params->channel_map == 0) {
    } else {
    if (adv_params == NULL) {
    if (own_addr_type > BLE_HCI_ADV_OWN_ADDR_MAX) {
    if (adv_params->disc_mode >= BLE_GAP_DISC_MODE_MAX) {
    if (ble_gap_slave[0].op != BLE_GAP_OP_NULL) {
    switch (adv_params->conn_mode) {
        if (adv_params->high_duty_cycle) {
        if (adv_params->high_duty_cycle) {
        if (!ble_hs_conn_can_alloc()) {
        if (peer_addr == NULL) {
            peer_addr->type != BLE_ADDR_RANDOM_ID) {
        if (!ble_hs_conn_can_alloc()) {
int
ble_gap_adv_start(uint8_t own_addr_type, const ble_addr_t *direct_addr,
                  int32_t duration_ms,
                  const struct ble_gap_adv_params *adv_params,
                  ble_gap_event_fn *cb, void *cb_arg)
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
    if (duration_ms != BLE_HS_FOREVER) {
        if (rc != 0) {
    if (ble_gap_is_preempted()) {
    if (rc != 0) {
    if (adv_params->conn_mode != BLE_GAP_CONN_MODE_NON) {
    } else {
    if (rc != 0) {
    if (rc != 0) {
    if (duration_ms != BLE_HS_FOREVER) {
    if (rc != 0) {
int
ble_gap_adv_set_data(const uint8_t *data, int data_len)
    if (!ble_hs_is_enabled()) {
            (data_len > BLE_HCI_MAX_ADV_DATA_LEN)) {
int
ble_gap_adv_rsp_set_data(const uint8_t *data, int data_len)
    if (!ble_hs_is_enabled()) {
            (data_len > BLE_HCI_MAX_SCAN_RSP_DATA_LEN)) {
int
ble_gap_adv_set_fields(const struct ble_hs_adv_fields *adv_fields)
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
    if (rc != 0) {
int
ble_gap_adv_rsp_set_fields(const struct ble_hs_adv_fields *rsp_fields)
    if (rc != 0) {
    if (rc != 0) {
int
ble_gap_adv_active(void)
    if (params->connectable) {
    if (params->scannable) {
    if (params->directed) {
    if (params->high_duty_directed) {
    if (params->anonymous) {
    if (params->include_tx_power) {
    if (params->legacy_pdu) {
        switch (cmd.props) {
            case BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_IND:
            case BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_LD_DIR:
            case BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_HD_DIR:
            case BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_SCAN:
            case BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_NONCONN:
                break;
            default:
                return BLE_HS_EINVAL;
    if (params->itvl_min == 0 && params->itvl_max == 0) {
    } else {
    if (params->channel_map == 0) {
    } else {
    if (params->legacy_pdu) {
    } else {
    if (rc != 0) {
    if (selected_tx_power) {
    if (!params) {
    if (params->own_addr_type > BLE_HCI_ADV_OWN_ADDR_MAX) {
    if (params->connectable && !ble_hs_conn_can_alloc()) {
    if (params->legacy_pdu) {
        if (params->anonymous || params->include_tx_power) {
    if (params->directed) {
        if (params->scannable && params->connectable) {
    if (!params->legacy_pdu) {
        if (params->connectable && params->scannable) {
        if (params->high_duty_directed) {
int
ble_gap_ext_adv_configure(uint8_t instance,
                          const struct ble_gap_ext_adv_params *params,
                          int8_t *selected_tx_power,
                          ble_gap_event_fn *cb, void *cb_arg)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (rc) {
    if (ble_gap_adv_active_instance(instance)) {
    if (rc) {
    if (rc != 0) {
int
ble_gap_ext_adv_set_addr(uint8_t instance, const ble_addr_t *addr)
    if (instance >= BLE_ADV_INSTANCES || addr->type != BLE_ADDR_RANDOM) {
    if (!ble_hs_is_enabled()) {
int
ble_gap_ext_adv_start(uint8_t instance, int duration, int max_events)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (!ble_gap_slave[instance].configured) {
    if (ble_gap_slave[instance].op != BLE_GAP_OP_NULL) {
        return  BLE_HS_EALREADY;
            ((duration == 0) || (duration > 128)) ) {
    switch (ble_gap_slave[instance].our_addr_type) {
        if (ble_gap_slave[instance].rnd_addr_set) {
        if (rc) {
    if (!ble_gap_slave[instance].rnd_addr_set) {
        switch (ble_gap_slave[instance].our_addr_type) {
            if (rc != 0) {
            if (rc != 0) {
    cmd = (void *) buf;
    if (rc != 0) {
    if (!ble_gap_slave[instance].configured) {
    cmd = (void *) buf;
    if (rc != 0) {
    if (!active) {
    } else {
int
ble_gap_ext_adv_stop(uint8_t instance)
    if (instance >= BLE_ADV_INSTANCES) {

    if (!ble_gap_slave[instance].configured) {
    if (ble_gap_slave[instance].legacy_pdu && ble_gap_slave[instance].directed) {
    if (ble_gap_slave[instance].legacy_pdu) {
        if (len > BLE_HS_ADV_MAX_SZ) {
    if (ble_gap_slave[instance].op == BLE_GAP_OP_S_ADV) {
        if (len > min(MYNEWT_VAL(BLE_EXT_ADV_MAX_SIZE), 251)) {
    if (ble_gap_slave[instance].scannable) {
    static uint8_t buf[sizeof(struct ble_hci_le_set_ext_adv_data_cp) + \
    static uint8_t buf[sizeof(struct ble_hci_le_set_ext_adv_data_cp) + \
    opcode =  BLE_HCI_OP(BLE_HCI_OGF_LE, opcode);
    if (len <= BLE_HCI_MAX_EXT_ADV_DATA_LEN) {
    do {
        if (rc) {
int
ble_gap_ext_adv_set_data(uint8_t instance, struct os_mbuf *data)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
ble_gap_ext_adv_rsp_set_validate(uint8_t instance,  struct os_mbuf *data)
    if (!ble_gap_slave[instance].configured) {
    if (ble_gap_slave[instance].directed && ble_gap_slave[instance].connectable) {
    if (!ble_gap_slave[instance].scannable) {
    if (ble_gap_slave[instance].legacy_pdu) {
        if (len > BLE_HS_ADV_MAX_SZ) {
    if (ble_gap_slave[instance].op == BLE_GAP_OP_S_ADV) {
        if (len > min(MYNEWT_VAL(BLE_EXT_ADV_MAX_SIZE), 251)) {
int
ble_gap_ext_adv_rsp_set_data(uint8_t instance, struct os_mbuf *data)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
int
ble_gap_ext_adv_remove(uint8_t instance)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (!ble_gap_slave[instance].configured) {
    if (ble_gap_slave[instance].op == BLE_GAP_OP_S_ADV) {
    if (rc != 0) {
int
ble_gap_ext_adv_clear(void)
    if (!ble_hs_is_enabled()) {
    for (instance = 0; instance < BLE_ADV_INSTANCES; instance++) {
        if ((ble_gap_slave[instance].op == BLE_GAP_OP_S_ADV)) {
        if (ble_gap_slave[instance].periodic_op == BLE_GAP_OP_S_PERIODIC_ADV) {
    if (rc != 0) {
    if (params->itvl_min == 0 && params->itvl_max == 0) {

    } else {
    if (params->include_tx_power) {
    } else {
        const struct ble_gap_periodic_adv_params *params)
    if (!params) {
    if (params->itvl_min && params->itvl_min < 6) {
    if (params->itvl_max && params->itvl_max < 6) {
            return BLE_HS_EINVAL;
int
ble_gap_periodic_adv_configure(uint8_t instance,
        const struct ble_gap_periodic_adv_params *params)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (rc) {
    if (!ble_gap_slave[instance].configured) {
    if (ble_gap_slave[instance].periodic_op == BLE_GAP_OP_S_PERIODIC_ADV) {
    if (rc) {
int
ble_gap_periodic_adv_start(uint8_t instance)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (!ble_gap_slave[instance].periodic_configured) {
    if (rc != 0) {
    struct ble_hci_le_set_periodic_adv_data_cp *cmd = (void *) buf;
    struct ble_hci_le_set_periodic_adv_data_cp *cmd = (void *) buf;
    if (len <= BLE_HCI_MAX_PERIODIC_ADV_DATA_LEN) {
    if (ble_gap_slave[instance].periodic_op == BLE_GAP_OP_S_PERIODIC_ADV) {
    do{
        if (rc) {
    if (!ble_gap_slave[instance].configured) {
    if (ble_gap_slave[instance].legacy_pdu) {
int
ble_gap_periodic_adv_set_data(uint8_t instance, struct os_mbuf *data)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
    if (rc != 0) {
int
ble_gap_periodic_adv_stop(uint8_t instance)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (cb) {
int
ble_gap_periodic_adv_sync_create(const ble_addr_t *addr, uint8_t adv_sid,
                                 const struct ble_gap_periodic_sync_params *params,
                                 ble_gap_event_fn *cb, void *cb_arg)
    if (addr && (addr->type > BLE_ADDR_RANDOM)) {
    if (adv_sid > 0x0f) {
            (params->sync_timeout < 0x0A)) {
    if (!ble_hs_is_enabled()) {
    if (ble_gap_sync.op == BLE_GAP_OP_SYNC) {
    if (ble_hs_periodic_sync_find(addr, adv_sid)) {
    if (!psync) {
    if (addr) {
    } else {
    if (!rc) {
    } else {
int
ble_gap_periodic_adv_sync_create_cancel(void)
    if (ble_gap_sync.op != BLE_GAP_OP_SYNC) {
int
ble_gap_periodic_adv_sync_terminate(uint16_t sync_handle)
    if (!ble_hs_is_enabled()) {
    if (ble_gap_sync.op == BLE_GAP_OP_SYNC) {
    if (!psync) {
    if (rc == 0) {
int
ble_gap_periodic_adv_sync_reporting(uint16_t sync_handle, bool enable)
    if (!ble_hs_is_enabled()) {
    if (ble_gap_sync.op == BLE_GAP_OP_SYNC) {
    if (!psync) {
int
ble_gap_periodic_adv_sync_transfer(uint16_t sync_handle, uint16_t conn_handle,
                                   uint16_t service_data)
    if (!ble_hs_is_enabled()) {
    if (!conn) {
    if (!psync) {
    if (!rc) {
int
ble_gap_periodic_adv_sync_set_info(uint8_t instance, uint16_t conn_handle,
                                   uint16_t service_data)
    if (instance >= BLE_ADV_INSTANCES) {
    if (!ble_hs_is_enabled()) {
    if (ble_gap_slave[instance].periodic_op != BLE_GAP_OP_S_PERIODIC_ADV) {
    if (!conn) {
    if (!rc) {
    if (!rc) {
int
ble_gap_periodic_adv_sync_receive(uint16_t conn_handle,
                                  const struct ble_gap_periodic_sync_params *params,
                                  ble_gap_event_fn *cb, void *cb_arg)
    if (!ble_hs_is_enabled()) {
    if (!conn) {
    if (params) {
        if (conn->psync) {
        if (!conn->psync) {
        if (rc) {
        } else {
    } else {
        if (!conn->psync) {
        if (!rc) {
int
ble_gap_add_dev_to_periodic_adv_list(const ble_addr_t *peer_addr,
                                     uint8_t adv_sid)
    if ((peer_addr->type > BLE_ADDR_RANDOM) || (adv_sid > 0x0f)) {
    if (!ble_hs_is_enabled()) {
int
ble_gap_rem_dev_from_periodic_adv_list(const ble_addr_t *peer_addr, uint8_t adv_sid)
    if ((peer_addr->type > BLE_ADDR_RANDOM) || (adv_sid > 0x0f)) {
    if (!ble_hs_is_enabled()) {
int
ble_gap_clear_periodic_adv_list(void)
int
ble_gap_read_periodic_adv_list_size(uint8_t *per_adv_list_size)
    if (rc != 0) {
                       const struct ble_hs_hci_ext_scan_param *uncoded_params,
                       const struct ble_hs_hci_ext_scan_param *coded_params)
    if (own_addr_type > BLE_HCI_ADV_OWN_ADDR_MAX) {
    if (filter_policy > BLE_HCI_SCAN_FILT_MAX) {
    cmd = (void *) buf;
    if (uncoded_params) {
    if (coded_params) {
    if (!cmd->phys) {
    if (disc_params->passive) {
    } else {
    if (!ble_gap_disc_active()) {
    if (rc != 0) {
    if (rc != 0) {
int
ble_gap_disc_cancel(void)
    if (!ble_hs_is_enabled()) {
    if (own_addr_type > BLE_HCI_ADV_OWN_ADDR_MAX) {
    if (ble_gap_conn_active()) {
    if (ble_gap_disc_active()) {
    if (!ble_hs_is_enabled()) {
    if (ble_gap_is_preempted()) {
   if (disc_params->scan_itvl == 0) {
        if (limited) {
        } else {
    if (disc_params->scan_window == 0) {
        if (limited) {
        } else {
    if (params->passive) {
        hci_params->scan_type =  BLE_HCI_SCAN_TYPE_PASSIVE;
    } else {
int
ble_gap_ext_disc(uint8_t own_addr_type, uint16_t duration, uint16_t period,
                 uint8_t filter_duplicates, uint8_t filter_policy,
                 uint8_t limited,
                 const struct ble_gap_ext_disc_params *uncoded_params,
                 const struct ble_gap_ext_disc_params *coded_params,
                 ble_gap_event_fn *cb, void *cb_arg)
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
    if (uncoded_params) {
        if (!uncoded_params->passive) {
            if (rc != 0) {
    if (coded_params) {
        if (!coded_params->passive) {
            if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
   if (disc_params->itvl == 0) {
        if (disc_params->limited) {
        } else {
    if (disc_params->window == 0) {
        if (disc_params->limited) {
        } else {
    if (disc_params == NULL) {
        (disc_params->itvl < disc_params->window)) {
    if (disc_params->filter_policy > BLE_HCI_SCAN_FILT_MAX) {
int
ble_gap_disc(uint8_t own_addr_type, int32_t duration_ms,
             const struct ble_gap_disc_params *disc_params,
             ble_gap_event_fn *cb, void *cb_arg)
    if (!ble_hs_is_enabled()) {
    if (duration_ms == BLE_HS_FOREVER) {
    } else if (duration_ms == 0) {
    return ble_gap_ext_disc(own_addr_type, duration_ms/10, 0,
                          disc_params->filter_duplicates,
                          disc_params->filter_policy, disc_params->limited,
                          &p, NULL, cb, cb_arg);
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
    if (duration_ms == 0) {
    if (duration_ms != BLE_HS_FOREVER) {
        if (rc != 0) {
    if (!params.passive) {
        if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
    if (duration_ms != BLE_HS_FOREVER) {
    if (rc != 0) {
int
ble_gap_disc_active(void)
    if (peer_addr == NULL) {
    } else {
int
ble_gap_set_default_subrate(uint16_t subrate_min, uint16_t subrate_max, uint16_t max_latency,
                            uint16_t cont_num, uint16_t supervision_tmo)
int
ble_gap_subrate_req(uint16_t conn_handle, uint16_t subrate_min, uint16_t subrate_max,
                    uint16_t max_latency, uint16_t cont_num,
                    uint16_t supervision_tmo)
    if (phy != BLE_HCI_LE_PHY_2M) {
            (params->scan_itvl < params->scan_window)) {
        /* Check connection interval min */
        (params->itvl_min > BLE_HCI_CONN_ITVL_MAX)) {
        (params->itvl_max < params->itvl_min)) {
    if (params->latency > BLE_HCI_CONN_LATENCY_MAX) {
        (params->supervision_timeout > BLE_HCI_CONN_SPVN_TIMEOUT_MAX)) {
    if (params->min_ce_len > params->max_ce_len) {
    if (own_addr_type > BLE_HCI_ADV_OWN_ADDR_MAX) {
                    BLE_HCI_LE_PHY_CODED_PREF_MASK)) {
    cmd = (void *) buf;
    if (peer_addr == NULL) {
    } else {
        if (peer_addr->type > BLE_HCI_CONN_PEER_ADDR_MAX) {
    if (phy_mask & BLE_GAP_LE_PHY_1M_MASK) {
        if (rc) {
    if (phy_mask & BLE_GAP_LE_PHY_2M_MASK) {
        if (rc) {
    if (phy_mask & BLE_GAP_LE_PHY_CODED_MASK) {
        if (rc) {
                                       cmd, len, NULL, 0);
int
ble_gap_ext_connect(uint8_t own_addr_type, const ble_addr_t *peer_addr,
                int32_t duration_ms, uint8_t phy_mask,
                const struct ble_gap_conn_params *phy_1m_conn_params,
                const struct ble_gap_conn_params *phy_2m_conn_params,
                const struct ble_gap_conn_params *phy_coded_conn_params,
                ble_gap_event_fn *cb, void *cb_arg)
    if (ble_gap_conn_active()) {
    if (ble_gap_disc_active()) {
    if (!ble_hs_is_enabled()) {
    if (ble_gap_is_preempted()) {
    if (!ble_hs_conn_can_alloc()) {
        peer_addr->type != BLE_ADDR_RANDOM_ID) {
    if ((phy_mask & BLE_GAP_LE_PHY_1M_MASK) && phy_1m_conn_params == NULL) {
    if ((phy_mask & BLE_GAP_LE_PHY_2M_MASK) && phy_2m_conn_params == NULL) {
        phy_coded_conn_params == NULL) {
    if (duration_ms == 0) {
    if (duration_ms != BLE_HS_FOREVER) {
        if (rc != 0) {
    if (ble_hs_conn_find_by_addr(peer_addr) != NULL) {
    if (rc != 0) {
    if (rc != 0) {
    if (duration_ms != BLE_HS_FOREVER) {
    if (rc != 0) {

int
ble_gap_connect(uint8_t own_addr_type, const ble_addr_t *peer_addr,
                int32_t duration_ms,
                const struct ble_gap_conn_params *conn_params,
                ble_gap_event_fn *cb, void *cb_arg)
    if (ble_gap_conn_active()) {
    if (ble_gap_disc_active()) {
    if (!ble_hs_is_enabled()) {
    if (ble_gap_is_preempted()) {
    if (!ble_hs_conn_can_alloc()) {
        peer_addr->type != BLE_ADDR_RANDOM_ID) {
    if (conn_params == NULL) {
    if (duration_ms == 0) {
    if (duration_ms != BLE_HS_FOREVER) {
        if (rc != 0) {
    if (ble_hs_conn_find_by_addr(peer_addr) != NULL) {
    if (rc != 0) {
    if (rc != 0) {
    if (duration_ms != BLE_HS_FOREVER) {
    if (rc != 0) {

int
ble_gap_conn_active(void)
int
ble_gap_terminate_with_conn(struct ble_hs_conn *conn, uint8_t hci_reason)
    if (conn->bhc_flags & BLE_HS_CONN_F_TERMINATING) {
                     conn->bhc_handle, hci_reason);
                                      &cmd, sizeof(cmd), NULL, 0);
    if (rc != 0) {
int
ble_gap_terminate(uint16_t conn_handle, uint8_t hci_reason)
    if (!ble_hs_is_enabled()) {
    if (conn == NULL) {
    if (rc != 0) {
    if (rc != 0) {
    if (!ble_gap_conn_active()) {
    if (rc != 0) {
    if (rc != 0) {
int
ble_gap_conn_cancel(void)
    if (!ble_hs_is_enabled()) {

    if (entry != NULL) {
    if (entry != NULL) {
    SLIST_FOREACH(entry, &ble_gap_update_entries, next) {
        if (entry->conn_handle == conn_handle) {
    if (out_prev != NULL) {
    if (entry != NULL) {
        if (prev == NULL) {
        } else {
    if (entry != NULL) {
        if (status != 0) {
                                     &cmd, sizeof(cmd), NULL, 0);
void
ble_gap_rx_param_req(const struct ble_hci_ev_le_subev_rem_conn_param_req *ev)
    if (rc == 0) {
        if (rc != 0) {
    } else {
                                        &cmd, sizeof(cmd), NULL, 0);
    if (params->itvl_min > params->itvl_max) {
    if (params->itvl_min < 0x0006 || params->itvl_max > 0x0C80) {
    if (params->latency > 0x01F3) {
                   (((1 + params->latency) * params->itvl_max) / 4)) {
int
ble_gap_update_params(uint16_t conn_handle,
                      const struct ble_gap_upd_params *params)
    if (!ble_gap_validate_conn_params(params)) {
    if (!ble_hs_is_enabled()) {
    if (conn == NULL) {
    if (dup != NULL) {
    if (entry == NULL) {
            !(conn->bhc_flags & BLE_HS_CONN_F_MASTER)) {
    } else {
    if (!l2cap_update) {
    } else {
                                              ble_gap_update_l2cap_cb, NULL);
    if (rc == 0) {
    } else {
int
ble_gap_set_data_len(uint16_t conn_handle, uint16_t tx_octets,
                     uint16_t tx_time)
int
ble_gap_read_sugg_def_data_len(uint16_t *out_sugg_max_tx_octets,
                               uint16_t *out_sugg_max_tx_time)
int
ble_gap_write_sugg_def_data_len(uint16_t sugg_max_tx_octets,
                                uint16_t sugg_max_tx_time)
* $security                                                                  *
*****************************************************************************/
int
ble_gap_security_initiate(uint16_t conn_handle)
    if (!ble_hs_is_enabled()) {
    if (conn != NULL) {
    if (conn == NULL) {
    if (conn_flags & BLE_HS_CONN_F_MASTER) {
        if (rc == 0 && value_sec.ltk_present) {
            if (rc != 0) {
        } else {
            if (rc != 0) {
    } else {
        if (rc != 0) {
    if (rc != 0) {
int
ble_gap_pair_initiate(uint16_t conn_handle)
    if (!ble_hs_is_enabled()) {
int
ble_gap_encryption_initiate(uint16_t conn_handle,
                            uint8_t key_size,
                            const uint8_t *ltk,
                            uint16_t ediv,
                            uint64_t rand_val,
                            int auth)
    if (!ble_hs_is_enabled()) {
    if (rc != 0) {
    if (!(conn_flags & BLE_HS_CONN_F_MASTER)) {
int
ble_gap_unpair(const ble_addr_t *peer_addr)
    if (!ble_hs_is_enabled()) {
    if (ble_addr_cmp(peer_addr, BLE_ADDR_ANY) == 0) {
    if (conn != NULL) {
int
ble_gap_unpair_oldest_peer(void)
    if (!ble_hs_is_enabled()) {
            &oldest_peer_id_addr, &num_peers, 1);
    if (rc != 0) {
    if (num_peers == 0) {
    if (rc != 0) {
int
ble_gap_unpair_oldest_except(const ble_addr_t *peer_addr)
    if (!ble_hs_is_enabled()) {
            &peer_id_addrs[0], &num_peers, MYNEWT_VAL(BLE_STORE_MAX_BONDS));
    if (rc != 0) {
    if (num_peers == 0) {
    for (i = 0; i < num_peers; i++) {
        if (ble_addr_cmp(peer_addr, &peer_id_addrs[i]) != 0) {
    if (i >= num_peers) {
void
ble_gap_passkey_event(uint16_t conn_handle,
                      struct ble_gap_passkey_params *passkey_params)
void
ble_gap_enc_event(uint16_t conn_handle, int status,
                  int security_restored, int bonded)
    if (status != 0) {
    if (security_restored) {
    if (bonded) {
void
ble_gap_identity_event(uint16_t conn_handle, const ble_addr_t *peer_id_addr)
int
ble_gap_repeat_pairing_event(const struct ble_gap_repeat_pairing *rp)
void
ble_gap_pairing_complete_event(uint16_t conn_handle, int status)
int
ble_gap_conn_rssi(uint16_t conn_handle, int8_t *out_rssi)
    if (!ble_hs_is_enabled()) {
void
ble_gap_notify_rx_event(uint16_t conn_handle, uint16_t attr_handle,
                        struct os_mbuf *om, int is_indication)
void
ble_gap_notify_tx_event(int status, uint16_t conn_handle, uint16_t attr_handle,
                        int is_indication)
void
ble_gap_subscribe_event(uint16_t conn_handle, uint16_t attr_handle,
                        uint8_t reason,
                        uint8_t prev_notify, uint8_t cur_notify,
                        uint8_t prev_indicate, uint8_t cur_indicate)
                      reason == BLE_GAP_SUBSCRIBE_REASON_TERM  ||
void
ble_gap_mtu_event(uint16_t conn_handle, uint16_t cid, uint16_t mtu)
void
ble_gap_vs_hci_event(const void *buf, uint8_t len)
void
ble_gap_preempt_no_lock(void)
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (rc == 0) {
    if (rc == 0) {
    if (rc == 0) {
    if (rc == 0) {
void
ble_gap_preempt(void)
    if (!ble_gap_is_preempted()) {
void
ble_gap_preempt_done(void)
    static struct {
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (ble_gap_slave[i].preempted) {
    if (ble_gap_master.preempted_op == BLE_GAP_OP_M_DISC) {
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (slaves[i].cb) {
    if (disc_preempted) {
int
ble_gap_event_listener_register(struct ble_gap_event_listener *listener,
                                ble_gap_event_fn *fn, void *arg)
    SLIST_FOREACH(evl, &ble_gap_event_listener_list, link) {
        if (evl == listener) {
    if (!evl) {
        if (fn) {
        } else {
    } else {
int
ble_gap_event_listener_unregister(struct ble_gap_event_listener *listener)
    SLIST_FOREACH(evl, &ble_gap_event_listener_list, link) {
        if (evl == listener) {
    if (!evl) {
    } else {
    SLIST_FOREACH(evl, &ble_gap_event_listener_list, link) {
int
ble_gap_init(void)
                         sizeof (struct ble_gap_update_entry),
    switch (rc) {
        STATS_HDR(ble_gap_stats), STATS_SIZE_INIT_PARMS(ble_gap_stats,
        STATS_SIZE_32), STATS_NAME_INIT_PARMS(ble_gap_stats), "ble_gap");
    if (rc != 0) {
int
ble_gap_enh_read_transmit_power_level(uint16_t conn_handle, uint8_t phy, uint8_t *out_status, uint8_t *out_phy ,
				      uint8_t *out_curr_tx_power_level, uint8_t *out_max_tx_power_level)
    if (rc!=0) {
int
ble_gap_read_remote_transmit_power_level(uint16_t conn_handle,
				      uint8_t phy)
int
ble_gap_set_path_loss_reporting_param(uint16_t conn_handle,
				      uint8_t high_threshold,
				      uint8_t high_hysteresis,
				      uint8_t low_threshold,
				      uint8_t low_hysteresis,
				      uint16_t min_time_spent)
int
ble_gap_set_path_loss_reporting_enable(uint16_t conn_handle,
				       uint8_t enable)
int
ble_gap_set_transmit_power_reporting_enable(uint16_t conn_handle,
					    uint8_t local_enable,
					    uint8_t remote_enable)
