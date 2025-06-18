# Lines added by author
_Static_assert(sizeof (struct ble_l2cap_hdr) == BLE_L2CAP_HDR_SZ,
static os_membuf_t ble_l2cap_chan_mem[
    OS_MEMPOOL_SIZE(MYNEWT_VAL(BLE_L2CAP_MAX_CHANS) +
                    MYNEWT_VAL(BLE_L2CAP_COC_MAX_NUM),
                    sizeof (struct ble_l2cap_chan))
];
STATS_SECT_DECL(ble_l2cap_stats) ble_l2cap_stats;
    STATS_NAME(ble_l2cap_stats, chan_create)
    STATS_NAME(ble_l2cap_stats, chan_delete)
    STATS_NAME(ble_l2cap_stats, update_init)
    STATS_NAME(ble_l2cap_stats, update_rx)
    STATS_NAME(ble_l2cap_stats, update_fail)
    STATS_NAME(ble_l2cap_stats, proc_timeout)
    STATS_NAME(ble_l2cap_stats, sig_tx)
    STATS_NAME(ble_l2cap_stats, sig_rx)
    STATS_NAME(ble_l2cap_stats, sm_tx)
    STATS_NAME(ble_l2cap_stats, sm_rx)
    if (chan == NULL) {
void
ble_l2cap_chan_free(struct ble_hs_conn *conn, struct ble_l2cap_chan *chan)
    if (chan == NULL) {
bool
ble_l2cap_is_mtu_req_sent(const struct ble_l2cap_chan *chan)
int
ble_l2cap_parse_hdr(struct os_mbuf *om, int off,
                    struct ble_l2cap_hdr *l2cap_hdr)
    if (rc != 0) {
    if (om == NULL) {
    if (!chan) {
int
ble_l2cap_create_server(uint16_t psm, uint16_t mtu,
                        ble_l2cap_event_fn *cb, void *cb_arg)
int
ble_l2cap_connect(uint16_t conn_handle, uint16_t psm, uint16_t mtu,
                  struct os_mbuf *sdu_rx, ble_l2cap_event_fn *cb, void *cb_arg)
int
ble_l2cap_get_chan_info(struct ble_l2cap_chan *chan, struct ble_l2cap_chan_info *chan_info)
    if (!chan || !chan_info) {
int
ble_l2cap_enhanced_connect(uint16_t conn_handle,
int
ble_l2cap_reconfig(struct ble_l2cap_chan *chans[], uint8_t num, uint16_t new_mtu)
    if (num == 0 || !chans) {
    for (i = 1; i < num; i++) {
        if (conn_handle != chans[i]->conn_handle) {
int
ble_l2cap_disconnect(struct ble_l2cap_chan *chan)
int
ble_l2cap_send(struct ble_l2cap_chan *chan, struct os_mbuf *sdu)
int
ble_l2cap_recv_ready(struct ble_l2cap_chan *chan, struct os_mbuf *sdu_rx)
void
ble_l2cap_remove_rx(struct ble_hs_conn *conn, struct ble_l2cap_chan *chan)
    if (chan->rx_buf == NULL) {
    } else {
    if (len_diff > 0) {
    } else if (len_diff == 0) {
    } else {
    if (chan->scid == BLE_L2CAP_CID_ATT) {
int
ble_l2cap_rx(struct ble_hs_conn *conn,
             struct hci_data_hdr *hci_hdr,
             struct os_mbuf *om,
             ble_l2cap_rx_fn **out_rx_cb,
             int *out_reject_cid)
    switch (pb) {
        if (rc != 0) {
        if (chan == NULL) {
            if (l2cap_hdr.cid != BLE_L2CAP_CID_BLACK_HOLE) {
        if (chan->dcid >= 0x0040 && chan->dcid <= 0x007F && l2cap_hdr.len > chan->my_coc_mps) {
        if (chan->rx_buf != NULL) {
        if (l2cap_hdr.len > ble_l2cap_get_mtu(chan)) {
        if (chan == NULL || chan->rx_buf == NULL) {
    if (rc != 0) {
int
ble_l2cap_tx(struct ble_hs_conn *conn, struct ble_l2cap_chan *chan,
             struct os_mbuf *txom)
    if (txom == NULL) {
    switch (rc) {
int
ble_l2cap_init(void)
                         MYNEWT_VAL(BLE_L2CAP_COC_MAX_NUM),
                         sizeof (struct ble_l2cap_chan),
    if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
    if (rc != 0) {
        STATS_HDR(ble_l2cap_stats), STATS_SIZE_INIT_PARMS(ble_l2cap_stats,
        STATS_SIZE_32), STATS_NAME_INIT_PARMS(ble_l2cap_stats), "ble_l2cap");
    if (rc != 0) {
