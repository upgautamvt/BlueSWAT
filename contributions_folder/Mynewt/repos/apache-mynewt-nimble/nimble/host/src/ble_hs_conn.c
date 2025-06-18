# Lines added by author
#define BLE_HS_CONN_MIN_CHANS       3
static os_membuf_t ble_hs_conn_elem_mem[
    OS_MEMPOOL_SIZE(MYNEWT_VAL(BLE_MAX_CONNECTIONS),
                    sizeof (struct ble_hs_conn))
];
int
ble_hs_conn_can_alloc(void)
    SLIST_FOREACH(chan, &conn->bhc_channels, next) {
        if (chan->scid == cid) {
        if (chan->scid > cid) {
    SLIST_FOREACH(chan, &conn->bhc_channels, next) {
        if (chan->dcid == cid) {
bool
ble_hs_conn_chan_exist(struct ble_hs_conn *conn, struct ble_l2cap_chan *chan)
    SLIST_FOREACH(tmp, &conn->bhc_channels, next) {
        if (chan == tmp) {
int
ble_hs_conn_chan_insert(struct ble_hs_conn *conn, struct ble_l2cap_chan *chan)
    SLIST_FOREACH(cur, &conn->bhc_channels, next) {
        if (cur->scid == chan->scid) {
        if (cur->scid > chan->scid) {
    if (prev == NULL) {
    } else {
struct ble_hs_conn *
ble_hs_conn_alloc(uint16_t conn_handle)
    if (conn == NULL) {
    if (chan == NULL) {
    if (rc != 0) {
    if (chan == NULL) {
    if (rc != 0) {
    if (chan == NULL) {
    if (rc != 0) {
    if (rc != 0) {
void
ble_hs_conn_delete_chan(struct ble_hs_conn *conn, struct ble_l2cap_chan *chan)
    if (conn->bhc_rx_chan == chan) {
void
ble_hs_conn_foreach(ble_hs_conn_foreach_fn *cb, void *arg)
    SLIST_FOREACH(conn, &ble_hs_conns, bhc_next) {
        if (cb(conn, arg) != 0) {
void
ble_hs_conn_free(struct ble_hs_conn *conn)
    if (conn == NULL) {
    while ((chan = SLIST_FIRST(&conn->bhc_channels)) != NULL) {
    while ((omp = STAILQ_FIRST(&conn->bhc_tx_q)) != NULL) {
void
ble_hs_conn_insert(struct ble_hs_conn *conn)
void
ble_hs_conn_remove(struct ble_hs_conn *conn)
    SLIST_FOREACH(conn, &ble_hs_conns, bhc_next) {
        if (conn->bhc_handle == conn_handle) {
    if (!addr) {
    SLIST_FOREACH(conn, &ble_hs_conns, bhc_next) {
        if (BLE_ADDR_IS_RPA(addr)) {
            if (ble_addr_cmp(&conn->bhc_peer_rpa_addr, addr) == 0) {
        } else {
            if (ble_addr_cmp(&conn->bhc_peer_addr, addr) == 0) {
            if (conn->bhc_peer_addr.type < BLE_OWN_ADDR_RPA_PUBLIC_DEFAULT) {
            if (ble_addr_cmp(&addrs.peer_id_addr, addr) == 0) {
    SLIST_FOREACH(conn, &ble_hs_conns, bhc_next) {
        if (i == idx) {
int
ble_hs_conn_exists(uint16_t conn_handle)
void
ble_hs_conn_addrs(const struct ble_hs_conn *conn,
                  struct ble_hs_conn_addrs *addrs)
            addrs->our_id_addr.type == BLE_ADDR_RANDOM) {
    } else {
    if (memcmp(conn->bhc_our_rpa_addr.val, ble_hs_conn_null_addr, 6) == 0) {
    } else {
    switch (conn->bhc_peer_addr.type) {
    for (;;) {
        SLIST_FOREACH(conn, &ble_hs_conns, bhc_next) {
            if (!(conn->bhc_flags & BLE_HS_CONN_F_TERMINATING)) {
                if (conn->bhc_rx_chan != NULL) {
                    if (time_diff <= 0) {
                    if (time_diff < next_exp_in) {
                if (time_diff <= 0) {
                if (time_diff < next_exp_in) {
        if (conn_handle != BLE_HS_CONN_HANDLE_NONE) {
int
ble_hs_conn_init(void)
                         sizeof (struct ble_hs_conn),
    if (rc != 0) {
