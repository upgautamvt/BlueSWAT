# Lines added by author
static void
ble_ll_tx_pkt_in(void)
// #include "fsm_handle.h"
        // MODLOG_DFLT(INFO, "ble_ll_rx_pkt_in: drain\n");

#define BLE_LL_S_NCA                    ((uint64_t)1 << 0)
#define BLE_LL_S_SA                     ((uint64_t)1 << 1)
#define BLE_LL_S_NCA                    ((uint64_t)0 << 0)
#define BLE_LL_S_SA                     ((uint64_t)0 << 1)
#define BLE_LL_S_CA                     ((uint64_t)1 << 2)
#define BLE_LL_S_HDCA                   ((uint64_t)1 << 3)
#define BLE_LL_S_CA                     ((uint64_t)0 << 2)
#define BLE_LL_S_HDCA                   ((uint64_t)0 << 3)
#define BLE_LL_S_PS                     ((uint64_t)1 << 4)
#define BLE_LL_S_AS                     ((uint64_t)1 << 5)
#define BLE_LL_S_PS                     ((uint64_t)0 << 4)
#define BLE_LL_S_AS                     ((uint64_t)0 << 5)
#define BLE_LL_S_INIT                   ((uint64_t)1 << 6)
#define BLE_LL_S_INIT                   ((uint64_t)0 << 6)
#define BLE_LL_S_PERIPH                 ((uint64_t)1 << 7)
#define BLE_LL_S_PERIPH                  ((uint64_t)0 << 7)
#define BLE_LL_S_NCA_PS                 ((uint64_t)1 << 8)
#define BLE_LL_S_SA_PS                  ((uint64_t)1 << 9)
#define BLE_LL_S_NCA_PS                 ((uint64_t)0 << 8)
#define BLE_LL_S_SA_PS                  ((uint64_t)0 << 9)
#define BLE_LL_S_CA_PS                  ((uint64_t)1 << 10)
#define BLE_LL_S_HDCA_PS                ((uint64_t)1 << 11)
#define BLE_LL_S_CA_PS                  ((uint64_t)0 << 10)
#define BLE_LL_S_HDCA_PS                ((uint64_t)0 << 11)
#define BLE_LL_S_NCA_AS                 ((uint64_t)1 << 12)
#define BLE_LL_S_SA_AS                  ((uint64_t)1 << 13)
#define BLE_LL_S_NCA_AS                 ((uint64_t)0 << 12)
#define BLE_LL_S_SA_AS                  ((uint64_t)0 << 13)
#define BLE_LL_S_CA_AS                  ((uint64_t)1 << 14)
#define BLE_LL_S_HDCA_AS                ((uint64_t)1 << 15)
#define BLE_LL_S_CA_AS                  ((uint64_t)0 << 14)
#define BLE_LL_S_HDCA_AS                ((uint64_t)0 << 15)
#define BLE_LL_S_NCA_INIT               ((uint64_t)1 << 16)
#define BLE_LL_S_SA_INIT                ((uint64_t)1 << 17)
#define BLE_LL_S_NCA_CENTRAL            ((uint64_t)1 << 18)
#define BLE_LL_S_SA_CENTRAL             ((uint64_t)1 << 19)
#define BLE_LL_S_NCA_INIT               ((uint64_t)0 << 16)
#define BLE_LL_S_SA_INIT                ((uint64_t)0 << 17)
#define BLE_LL_S_NCA_CENTRAL             ((uint64_t)0 << 18)
#define BLE_LL_S_SA_CENTRAL              ((uint64_t)0 << 19)
#define BLE_LL_S_NCA_PERIPH             ((uint64_t)1 << 20)
#define BLE_LL_S_SA_PERIPH               ((uint64_t)1 << 21)
#define BLE_LL_S_NCA_PERIPH              ((uint64_t)0 << 20)
#define BLE_LL_S_SA_PERIPH               ((uint64_t)0 << 21)
#define BLE_LL_S_PS_INIT                ((uint64_t)0 << 22)
#define BLE_LL_S_AS_INIT                ((uint64_t)0 << 23)
#define BLE_LL_S_PS_CENTRAL             ((uint64_t)1 << 24)
#define BLE_LL_S_AS_CENTRAL             ((uint64_t)1 << 25)
#define BLE_LL_S_PS_INIT                ((uint64_t)0 << 22)
#define BLE_LL_S_AS_INIT                ((uint64_t)0 << 23)
#define BLE_LL_S_PS_CENTRAL              ((uint64_t)0 << 24)
#define BLE_LL_S_AS_CENTRAL              ((uint64_t)0 << 25)
#define BLE_LL_S_PS_PERIPH              ((uint64_t)1 << 26)
#define BLE_LL_S_AS_PERIPH              ((uint64_t)1 << 27)
#define BLE_LL_S_PS_PERIPH               ((uint64_t)0 << 26)
#define BLE_LL_S_AS_PERIPH               ((uint64_t)0 << 27)
#define BLE_LL_S_INIT_CENTRAL           ((uint64_t)1 << 28)
#define BLE_LL_S_INIT_CENTRAL            ((uint64_t)0 << 28)
#define BLE_LL_S_LDCA                   ((uint64_t)1 << 29)
#define BLE_LL_S_LDCA                   ((uint64_t)0 << 29)
#define BLE_LL_S_LDCA_PS                ((uint64_t)1 << 30)
#define BLE_LL_S_LDCA_AS                ((uint64_t)1 << 31)
#define BLE_LL_S_LDCA_PS                ((uint64_t)0 << 30)
#define BLE_LL_S_LDCA_AS                ((uint64_t)0 << 31)
#define BLE_LL_S_CA_INIT                ((uint64_t)1 << 32)
#define BLE_LL_S_HDCA_INIT              ((uint64_t)1 << 33)
#define BLE_LL_S_LDCA_INIT              ((uint64_t)1 << 34)
#define BLE_LL_S_CA_CENTRAL             ((uint64_t)1 << 35)
#define BLE_LL_S_HDCA_CENTRAL           ((uint64_t)1 << 36)
#define BLE_LL_S_LDCA_CENTRAL           ((uint64_t)1 << 37)
#define BLE_LL_S_CA_INIT                ((uint64_t)0 << 32)
#define BLE_LL_S_HDCA_INIT              ((uint64_t)0 << 33)
#define BLE_LL_S_LDCA_INIT              ((uint64_t)0 << 34)
#define BLE_LL_S_CA_CENTRAL              ((uint64_t)0 << 35)
#define BLE_LL_S_HDCA_CENTRAL            ((uint64_t)0 << 36)
#define BLE_LL_S_LDCA_CENTRAL            ((uint64_t)0 << 37)
#define BLE_LL_S_CA_PERIPH              ((uint64_t)1 << 38)
#define BLE_LL_S_HDCA_PERIPH            ((uint64_t)1 << 39)
#define BLE_LL_S_LDCA_PERIPH            ((uint64_t)1 << 40)
#define BLE_LL_S_CA_PERIPH               ((uint64_t)0 << 38)
#define BLE_LL_S_HDCA_PERIPH             ((uint64_t)0 << 39)
#define BLE_LL_S_LDCA_PERIPH             ((uint64_t)0 << 40)
#define BLE_LL_S_INIT_PERIPH            ((uint64_t)1 << 41)
#define BLE_LL_S_INIT_PERIPH             ((uint64_t)0 << 41)
#endif

#define BLE_LL_SUPPORTED_STATES             \
(                                           \
    BLE_LL_S_NCA                    |       \
    BLE_LL_S_SA                     |       \
    BLE_LL_S_CA                     |       \
    BLE_LL_S_HDCA                   |       \
    BLE_LL_S_PS                     |       \
    BLE_LL_S_AS                     |       \
    BLE_LL_S_INIT                   |       \
    BLE_LL_S_PERIPH                  |       \
    BLE_LL_S_NCA_PS                 |       \
    BLE_LL_S_SA_PS                  |       \
    BLE_LL_S_CA_PS                  |       \
    BLE_LL_S_HDCA_PS                |       \
    BLE_LL_S_NCA_AS                 |       \
    BLE_LL_S_SA_AS                  |       \
    BLE_LL_S_CA_AS                  |       \
    BLE_LL_S_HDCA_AS                |       \
    BLE_LL_S_NCA_INIT               |       \
    BLE_LL_S_SA_INIT                |       \
    BLE_LL_S_NCA_CENTRAL             |       \
    BLE_LL_S_SA_CENTRAL              |       \
    BLE_LL_S_NCA_PERIPH              |       \
    BLE_LL_S_SA_PERIPH               |       \
    BLE_LL_S_PS_INIT                |       \
    BLE_LL_S_AS_INIT                |       \
    BLE_LL_S_PS_CENTRAL              |       \
    BLE_LL_S_AS_CENTRAL              |       \
    BLE_LL_S_PS_PERIPH               |       \
    BLE_LL_S_AS_PERIPH               |       \
    BLE_LL_S_INIT_CENTRAL            |       \
    BLE_LL_S_LDCA                   |       \
    BLE_LL_S_LDCA_PS                |       \
    BLE_LL_S_LDCA_AS                |       \
    BLE_LL_S_CA_INIT                |       \
    BLE_LL_S_HDCA_INIT              |       \
    BLE_LL_S_LDCA_INIT              |       \
    BLE_LL_S_CA_CENTRAL              |       \
    BLE_LL_S_HDCA_CENTRAL            |       \
    BLE_LL_S_LDCA_CENTRAL            |       \
    BLE_LL_S_CA_PERIPH               |       \
    BLE_LL_S_HDCA_PERIPH             |       \
    BLE_LL_S_LDCA_PERIPH             |       \
    BLE_LL_S_INIT_PERIPH)
STATS_SECT_DECL(ble_ll_stats) ble_ll_stats;
    STATS_NAME(ble_ll_stats, hci_cmds)
    STATS_NAME(ble_ll_stats, hci_cmd_errs)
    STATS_NAME(ble_ll_stats, hci_events_sent)
    STATS_NAME(ble_ll_stats, bad_ll_state)
    STATS_NAME(ble_ll_stats, bad_acl_hdr)
    STATS_NAME(ble_ll_stats, no_bufs)
    STATS_NAME(ble_ll_stats, rx_adv_pdu_crc_ok)
    STATS_NAME(ble_ll_stats, rx_adv_pdu_crc_err)
    STATS_NAME(ble_ll_stats, rx_adv_bytes_crc_ok)
    STATS_NAME(ble_ll_stats, rx_adv_bytes_crc_err)
    STATS_NAME(ble_ll_stats, rx_data_pdu_crc_ok)
    STATS_NAME(ble_ll_stats, rx_data_pdu_crc_err)
    STATS_NAME(ble_ll_stats, rx_data_bytes_crc_ok)
    STATS_NAME(ble_ll_stats, rx_data_bytes_crc_err)
    STATS_NAME(ble_ll_stats, rx_adv_malformed_pkts)
    STATS_NAME(ble_ll_stats, rx_adv_ind)
    STATS_NAME(ble_ll_stats, rx_adv_direct_ind)
    STATS_NAME(ble_ll_stats, rx_adv_nonconn_ind)
    STATS_NAME(ble_ll_stats, rx_adv_ext_ind)
    STATS_NAME(ble_ll_stats, rx_scan_reqs)
    STATS_NAME(ble_ll_stats, rx_scan_rsps)
    STATS_NAME(ble_ll_stats, rx_connect_reqs)
    STATS_NAME(ble_ll_stats, rx_scan_ind)
    STATS_NAME(ble_ll_stats, rx_aux_connect_rsp)
    STATS_NAME(ble_ll_stats, adv_txg)
    STATS_NAME(ble_ll_stats, adv_late_starts)
    STATS_NAME(ble_ll_stats, adv_resched_pdu_fail)
    STATS_NAME(ble_ll_stats, adv_drop_event)
    STATS_NAME(ble_ll_stats, sched_state_conn_errs)
    STATS_NAME(ble_ll_stats, sched_state_adv_errs)
    STATS_NAME(ble_ll_stats, scan_starts)
    STATS_NAME(ble_ll_stats, scan_stops)
    STATS_NAME(ble_ll_stats, scan_req_txf)
    STATS_NAME(ble_ll_stats, scan_req_txg)
    STATS_NAME(ble_ll_stats, scan_rsp_txg)
    STATS_NAME(ble_ll_stats, aux_missed_adv)
    STATS_NAME(ble_ll_stats, aux_scheduled)
    STATS_NAME(ble_ll_stats, aux_received)
    STATS_NAME(ble_ll_stats, aux_fired_for_read)
    STATS_NAME(ble_ll_stats, aux_allocated)
    STATS_NAME(ble_ll_stats, aux_freed)
    STATS_NAME(ble_ll_stats, aux_sched_cb)
    STATS_NAME(ble_ll_stats, aux_conn_req_tx)
    STATS_NAME(ble_ll_stats, aux_conn_rsp_tx)
    STATS_NAME(ble_ll_stats, aux_conn_rsp_err)
    STATS_NAME(ble_ll_stats, aux_scan_req_tx)
    STATS_NAME(ble_ll_stats, aux_scan_rsp_err)
    STATS_NAME(ble_ll_stats, aux_chain_cnt)
    STATS_NAME(ble_ll_stats, aux_chain_err)
    STATS_NAME(ble_ll_stats, aux_scan_drop)
    STATS_NAME(ble_ll_stats, adv_evt_dropped)
    STATS_NAME(ble_ll_stats, scan_timer_stopped)
    STATS_NAME(ble_ll_stats, scan_timer_restarted)
    STATS_NAME(ble_ll_stats, periodic_adv_drop_event)
    STATS_NAME(ble_ll_stats, periodic_chain_drop_event)
    STATS_NAME(ble_ll_stats, sync_event_failed)
    STATS_NAME(ble_ll_stats, sync_received)
    STATS_NAME(ble_ll_stats, sync_chain_failed)
    STATS_NAME(ble_ll_stats, sync_missed_err)
    STATS_NAME(ble_ll_stats, sync_crc_err)
    STATS_NAME(ble_ll_stats, sync_rx_buf_err)
    STATS_NAME(ble_ll_stats, sync_scheduled)
    STATS_NAME(ble_ll_stats, sched_state_sync_errs)
    STATS_NAME(ble_ll_stats, sched_invalid_pdu)
    switch (pdu_type) {
                     sizeof(struct ble_mbuf_hdr)) & 3) == 0,
    if (!om_ret) {
    while (rem_len > 0) {
        if (!om_next) {
int
ble_ll_is_rpa(const uint8_t *addr, uint8_t addr_type)
    if (addr_type && ((addr[5] & 0xc0) == 0x40)) {
    } else {
int
ble_ll_addr_is_id(uint8_t *addr, uint8_t addr_type)
int
ble_ll_addr_subtype(const uint8_t *addr, uint8_t addr_type)
    if (!addr_type) {
    switch (addr[5] >> 6) {
    for (i = 0; i < BLE_DEV_ADDR_LEN; ++i) {
        if (addr[i]) {
int
ble_ll_is_valid_random_addr(const uint8_t *addr)
    for (i = 0; i < (BLE_DEV_ADDR_LEN -1); ++i) {
    if ((sum == 0) || (sum == ((5*255) + 0x3f))) {
    if (addr_type == 0xc0) {
    } else if (addr_type == 0x40) {
        if ((sum == 0) || (sum == (255 + 255 + 0x3f))) {
    } else if (addr_type == 0) {
        if (!memcmp(g_dev_addr, addr, BLE_DEV_ADDR_LEN)) {
    } else {
int
ble_ll_is_valid_own_addr_type(uint8_t own_addr_type, const uint8_t *random_addr)
    switch (own_addr_type) {
int
ble_ll_set_public_addr(const uint8_t *addr)
int
ble_ll_set_random_addr(const uint8_t *cmdbuf, uint8_t len, bool hci_adv_ext)
    const struct ble_hci_le_set_rand_addr_cp *cmd = (const void *) cmdbuf;
    if (len < sizeof(*cmd)) {
    if (g_ble_ll_conn_create_sm.connsm) {
    if (ble_ll_scan_enabled()){
    if (!hci_adv_ext && ble_ll_adv_enabled()) {
int
ble_ll_is_our_devaddr(uint8_t *addr, int addr_type)
    if (addr_type) {
    } else {
    if (!memcmp(our_addr, addr, BLE_DEV_ADDR_LEN)) {
uint8_t*
    if (addr_type) {
void
ble_ll_wfr_timer_exp(void *arg)
    if (!rx_start) {
        switch (lls) {
    while (STAILQ_FIRST(&g_ble_ll_data.ll_tx_pkt_q)) {
        if ((pkthdr->omp_len != length) || (pb > 0x1000) || (length == 0)) {
    if (!connection_data) {
    if (crcok) {
        if (connection_data) {
        } else {
    } else {
        if (connection_data) {
        } else {
    while (STAILQ_FIRST(&g_ble_ll_data.ll_rx_pkt_q)) {
        switch (BLE_MBUF_HDR_RX_STATE(ble_hdr)) {
        if (m) {
void
ble_ll_rx_pdu_in(struct os_mbuf *rxpdu)
void
ble_ll_acl_data_in(struct os_mbuf *txpkt)
void
ble_ll_data_buffer_overflow(void)
void
ble_ll_hw_error(void)
    if (ble_ll_hci_ev_hw_err(BLE_HW_ERR_HCI_SYNC_LOSS)) {
                         ble_npl_time_ms_to_ticks32(50));
int
ble_ll_rx_start(uint8_t *rxbuf, uint8_t chan, struct ble_mbuf_hdr *rxhdr)
    switch (g_ble_ll_data.ll_state) {
int
ble_ll_rx_end(uint8_t *rxbuf, struct ble_mbuf_hdr *rxhdr)
    if (BLE_MBUF_HDR_RX_STATE(rxhdr) == BLE_LL_STATE_EXTERNAL) {
    if (BLE_MBUF_HDR_RX_STATE(rxhdr) == BLE_LL_STATE_DTM) {
    if (BLE_MBUF_HDR_RX_STATE(rxhdr) == BLE_LL_STATE_CONNECTION) {
    if (BLE_MBUF_HDR_RX_STATE(rxhdr) == BLE_LL_STATE_SYNC) {
    if (crcok) {
        switch (pdu_type) {
            if (len != BLE_SCAN_REQ_LEN) {
            if ((len < BLE_DEV_ADDR_LEN) || (len > BLE_ADV_SCAN_IND_MAX_LEN)) {
            if (len != BLE_CONNECT_REQ_LEN) {
        if (badpkt) {
    switch (BLE_MBUF_HDR_RX_STATE(rxhdr)) {
        if (!badpkt) {
            if (rxpdu) {
        if (!badpkt) {
            if (rxpdu) {
        if (!badpkt) {
            if (rxpdu) {
    if (rxpdu) {
void
ble_ll_task(void *arg)
    while (1) {
void
ble_ll_state_set(uint8_t ll_state)
    if (ll_state == BLE_LL_STATE_STANDBY) {
void
ble_ll_event_add(struct ble_npl_event *ev)
void
ble_ll_event_remove(struct ble_npl_event *ev)
int
ble_ll_set_host_feat(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_host_feature_cp *cmd = (const void *) cmdbuf;
    if (len != sizeof(*cmd)) {
    if (!SLIST_EMPTY(&g_ble_ll_conn_active_list)) {
    if ((cmd->bit_num > 0x3F) || (cmd->bit_val > 1)) {
    if (!(mask & BLE_LL_HOST_CONTROLLED_FEATURES)) {
    if (cmd->bit_val == 0) {
    } else {
    while (STAILQ_FIRST(pktq)) {
void
ble_ll_mbuf_init(struct os_mbuf *m, uint8_t pdulen, uint8_t hdr)
int
ble_ll_reset(void)

    if (usecs < header_tx_time) {
    if (phy_mode == BLE_PHY_MODE_1M) {
    } else if (phy_mode == BLE_PHY_MODE_2M) {
    } else if (phy_mode == BLE_PHY_MODE_CODED_125KBPS) {
    } else if (phy_mode == BLE_PHY_MODE_CODED_500KBPS) {
    } else {
void
ble_ll_assert(const char *file, unsigned line)
    if (hal_debugger_connected()) {
    while (1);
    if (ble_ll_is_addr_empty(g_dev_addr)) {
        for (i = 0; i < BLE_DEV_ADDR_LEN; i++) {
        if (ble_ll_is_addr_empty(g_dev_addr)) {
            if (!rc) {
/*
 * For non-Mynewt OS it is required that OS creates task for LL and run LL
 * routine which is wrapped by nimble_port_ll_task_func().
 */
int
ble_transport_to_ll_cmd_impl(void *buf)
int
ble_transport_to_ll_acl_impl(struct os_mbuf *om)
int
ble_transport_to_ll_iso_impl(struct os_mbuf *om)
void
ble_transport_ll_init(void)
int
ble_ll_tx_power_round(int tx_power)
void
ble_ll_tx_power_set(int tx_power)
    if (g_ble_ll_tx_power_phy_current == tx_power) {
int
ble_ll_is_busy(unsigned int flags)
    if (ble_ll_sync_enabled()) {
    if (ble_ll_adv_enabled()) {
    if (ble_ll_scan_enabled()) {
    if (g_ble_ll_conn_create_sm.connsm) {
    if (!(flags & BLE_LL_BUSY_EXCLUDE_CONNECTIONS)) {
        STAILQ_FOREACH(cur, &g_ble_ll_conn_free_list, free_stqe) {
        if (i < MYNEWT_VAL(BLE_MAX_CONNECTIONS)) {
