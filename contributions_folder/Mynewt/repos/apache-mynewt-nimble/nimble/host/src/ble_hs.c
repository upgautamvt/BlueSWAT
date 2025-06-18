# Lines added by author
#define BLE_HS_HCI_EVT_COUNT    (MYNEWT_VAL(BLE_TRANSPORT_EVT_COUNT) + \
                                 MYNEWT_VAL(BLE_TRANSPORT_EVT_DISCARDABLE_COUNT))
static os_membuf_t ble_hs_hci_os_event_buf[
    OS_MEMPOOL_SIZE(BLE_HS_HCI_EVT_COUNT, sizeof (struct ble_npl_event))
];
#define BLE_HS_SYNC_RETRY_TIMEOUT_MS    100 /* ms */
STATS_SECT_DECL(ble_hs_stats) ble_hs_stats;
    STATS_NAME(ble_hs_stats, conn_create)
    STATS_NAME(ble_hs_stats, conn_delete)
    STATS_NAME(ble_hs_stats, hci_cmd)
    STATS_NAME(ble_hs_stats, hci_event)
    STATS_NAME(ble_hs_stats, hci_invalid_ack)
    STATS_NAME(ble_hs_stats, hci_unknown_event)
    STATS_NAME(ble_hs_stats, hci_timeout)
    STATS_NAME(ble_hs_stats, reset)
    STATS_NAME(ble_hs_stats, sync)
    STATS_NAME(ble_hs_stats, pvcy_add_entry)
    STATS_NAME(ble_hs_stats, pvcy_add_entry_fail)
void
ble_hs_evq_set(struct ble_npl_eventq *evq)
int
ble_hs_locked_by_cur_task(void)
    if (!ble_npl_os_started()) {
int
ble_hs_is_parent_task(void)
void
ble_hs_lock_nested(void)
    if (!ble_npl_os_started()) {
void
ble_hs_unlock_nested(void)
    if (!ble_npl_os_started()) {
void
ble_hs_lock(void)
    if (!ble_npl_os_started()) {
void
ble_hs_unlock(void)
    if (!ble_npl_os_started()) {
void
ble_hs_process_rx_data_queue(void)
    while ((om = ble_mqueue_get(&ble_hs_rx_q)) != NULL) {
    while ((omp = STAILQ_FIRST(&conn->bhc_tx_q)) != NULL) {
        if (rc == BLE_HS_EAGAIN) {
void
ble_hs_wakeup_tx(void)
         conn = SLIST_NEXT(conn, bhc_next)) {
        if (conn->bhc_flags & BLE_HS_CONN_F_TX_FRAG) {
            if (rc != 0) {
         conn = SLIST_NEXT(conn, bhc_next)) {
        if (rc != 0) {
    while ((om = ble_mqueue_get(&ble_hs_rx_q)) != NULL) {
int
ble_hs_is_enabled(void)
int
ble_hs_synced(void)
    if (rc == 0) {
    } else {
    if (rc == 0) {
        if (rc != 0) {
        if (ble_hs_cfg.sync_cb != NULL) {
    if (ble_hs_cfg.reset_cb != NULL && ble_hs_reset_reason != 0) {
    switch (ble_hs_sync_state) {

    if (!ble_hs_is_enabled()) {
    } else {
    if (ticks_from_now == BLE_HS_FOREVER) {
            ((ble_npl_stime_t)(abs_time -
                               ble_npl_callout_get_ticks(&ble_hs_timer))) < 0) {
void
ble_hs_timer_resched(void)
void
ble_hs_sched_start(void)
void
ble_hs_enqueue_hci_event(uint8_t *hci_evt)
    if (ev == NULL) {
    } else {
void
ble_hs_notifications_sched(void)
    if (!ble_npl_os_started()) {
void
ble_hs_sched_reset(int reason)
void
ble_hs_hw_error(uint8_t hw_code)
int
ble_hs_start(void)
    switch (ble_hs_enabled_state) {
    if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
int
ble_hs_tx_data(struct os_mbuf *om)
void
ble_hs_init(void)
                         sizeof (struct ble_npl_event), ble_hs_hci_os_event_buf,
        STATS_HDR(ble_hs_stats), STATS_SIZE_INIT_PARMS(ble_hs_stats,
        STATS_SIZE_32), STATS_NAME_INIT_PARMS(ble_hs_stats), "ble_hs");
int
ble_transport_to_hs_evt_impl(void *buf)
int
ble_transport_to_hs_acl_impl(struct os_mbuf *om)
int
ble_transport_to_hs_iso_impl(struct os_mbuf *om)
void
ble_transport_hs_init(void)
