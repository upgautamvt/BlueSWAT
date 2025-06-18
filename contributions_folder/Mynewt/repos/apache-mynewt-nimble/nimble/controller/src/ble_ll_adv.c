# Lines added by author
struct ble_ll_adv_aux {
struct ble_ll_adv_sync {
#define BLE_LL_ADV_SM_FLAG_TX_ADD                   0x0001
#define BLE_LL_ADV_SM_FLAG_RX_ADD                   0x0002
#define BLE_LL_ADV_SM_FLAG_SCAN_REQ_NOTIF           0x0004
#define BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD             0x0008
#define BLE_LL_ADV_SM_FLAG_ACTIVE_CHANSET_MASK      0x0030 /* use helpers! */
#define BLE_LL_ADV_SM_FLAG_ADV_DATA_INCOMPLETE      0x0040
#define BLE_LL_ADV_SM_FLAG_CONFIGURED               0x0080
#define BLE_LL_ADV_SM_FLAG_ADV_RPA_TMO              0x0100
#define BLE_LL_ADV_SM_FLAG_NEW_ADV_DATA             0x0200
#define BLE_LL_ADV_SM_FLAG_NEW_SCAN_RSP_DATA        0x0400
#define BLE_LL_ADV_SM_FLAG_PERIODIC_CONFIGURED      0x0800
#define BLE_LL_ADV_SM_FLAG_PERIODIC_SYNC_SENDING    0x2000
#define BLE_LL_ADV_SM_FLAG_PERIODIC_NEW_DATA        0x4000
#define BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD_ERR         0x8000
    if (!ble_ll_hci_adv_mode_ext()) {
    for (i = 0; i < ARRAY_SIZE(g_ble_ll_adv_sm); i++) {
                (advsm->adv_instance == instance)) {
                          advsm->adva, 1)) {
    } else {
        if (advsm->own_addr_type & 1) {
        } else {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
                              advsm->initiator_addr, 0)) {
        } else {
            if (advsm->peer_addr_type & 1) {
            } else {
void
ble_ll_adv_chk_rpa_timeout(struct ble_ll_adv_sm *advsm)
    if (advsm->own_addr_type < BLE_HCI_ADV_OWN_ADDR_PRIV_PUB) {
    if (advsm->flags & BLE_LL_ADV_SM_FLAG_ADV_RPA_TMO) {
void
ble_ll_adv_rpa_timeout(void)
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
                advsm->own_addr_type > BLE_HCI_ADV_OWN_ADDR_RANDOM) {
    if (advsm->adv_chanmask & 0x01) {
    } else if (advsm->adv_chanmask & 0x02) {
    } else {
    if (advsm->adv_chanmask & 0x04) {
    } else if (advsm->adv_chanmask & 0x02) {
    } else {
    uint8_t     adv_data_len;
    uint8_t     pdulen;
    uint8_t     pdu_type;
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_RX_ADD) {
    } else if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
    } else if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) {
    } else {
    if (advsm->flags & BLE_LL_ADV_SM_FLAG_TX_ADD) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
    if (adv_data_len != 0) {
    if (offset > 245700) {
    } else {
    if (offset > 0x1fff) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) {
    if (AUX_CURRENT(advsm)->sch.enqueued) {
    } else {
    if (connsm) {
        while (LL_TMR_GT(anchor, advsm->periodic_adv_event_start_time)) {
    } else {
        while (LL_TMR_GT(AUX_CURRENT(advsm)->start_time, anchor)) {
    if (offset > 245700) {
        if (offset >= 0x2000) {
            if (connsm) {
            } else {

    } else {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
    if (aux->ext_hdr_flags) {
    if (aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_ADVA_BIT)) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_TX_ADD) {
    if (aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_TARGETA_BIT)) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_RX_ADD) {
    if (aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_DATA_INFO_BIT)) {
    if (aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_AUX_PTR_BIT)) {
        if (!AUX_NEXT(advsm)->sch.enqueued) {
        } else if (advsm->rx_ble_hdr) {
        } else {
    if (aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_SYNC_INFO_BIT)) {
    if (aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_TX_POWER_BIT)) {
    if (aux->data_len) {
    if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_ANON_ADV)) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_TX_ADD) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_RX_ADD) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_INC_TX_PWR) {
    uint8_t     scan_rsp_len;
    uint8_t     pdulen;
    uint8_t     hdr;
    if (advsm->flags & BLE_LL_ADV_SM_FLAG_TX_ADD) {
    if (scan_rsp_len != 0) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
struct aux_conn_rsp_data {
    uint8_t     pdulen;
    uint8_t     ext_hdr_len;
    uint8_t     ext_hdr_flags;
    uint8_t     hdr;
    if (rsp_data->rxadd) {
    if (rsp_data->advsm->flags & BLE_LL_ADV_SM_FLAG_TX_ADD) {
    if (ble_ll_adv_active_chanset_is_pri(advsm)) {
    } else if (ble_ll_adv_active_chanset_is_sec(advsm)) {
    } else {
void
ble_ll_adv_event_rmvd_from_sched(struct ble_ll_adv_sm *advsm)
void
ble_ll_adv_periodic_rmvd_from_sched(struct ble_ll_adv_sm *advsm)
        (advsm->flags & BLE_LL_ADV_SM_FLAG_NEW_SCAN_RSP_DATA)) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
    } else {
    if (rc) {
    if (ble_ll_resolv_enabled()) {
    } else {
            ((advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) ||
             (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE))) {
    } else {
    if (rc) {
    if (advsm->adv_filter_policy != BLE_HCI_ADV_FILT_NONE) {
    } else {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
        } else if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
    } else {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
    } else if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
     ble_phy_mode_set(advsm->sec_phy, advsm->sec_phy);
    if (rc) {
    if (ble_ll_resolv_enabled()) {
    } else {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
    } else if ((advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) &&
               advsm->aux_first_pdu) {
    } else {
    if (rc) {
    if (advsm->adv_filter_policy != BLE_HCI_ADV_FILT_NONE) {
    } else {
    len = BLE_LL_EXT_ADV_HDR_LEN + BLE_LL_EXT_ADV_FLAGS_SIZE
            + BLE_LL_EXT_ADV_DATA_INFO_SIZE;
    if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_ANON_ADV)) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_INC_TX_PWR) {
    if (!(props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE)) {
        !(props & BLE_HCI_LE_SET_EXT_ADV_PROP_ANON_ADV)) {
        !(props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE)) {
        (props & BLE_HCI_LE_SET_EXT_ADV_PROP_INC_TX_PWR)) {
    if (first_pdu && advsm->periodic_adv_active) {
    if (ext_hdr_flags) {
    if (chainable && (rem_data_len > data_len)) {
        if (!ext_hdr_flags) {
    do {
    if (!aux->sch.enqueued) {
    if (!(aux->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_AUX_PTR_BIT))) {
                                      advsm->adv_end_time))) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
                    ble_ll_pdu_us(34 + 14, advsm->sec_phy)  +
    } else if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) {
                                           advsm->sec_phy) +
                    ble_ll_pdu_us(12, advsm->sec_phy)  +
    } else {
        LL_TMR_GT(AUX_CURRENT(advsm)->sch.end_time, advsm->adv_end_time)) {
void
ble_ll_adv_halt(void)
    if (g_ble_ll_cur_adv_sm != NULL) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_SYNC_SENDING) {
        if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY)) {
    } else {
int
ble_ll_adv_set_adv_params(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_adv_params_cp *cmd = (const void *) cmdbuf;
    if (len != sizeof(*cmd)) {
    if (advsm->adv_enabled) {
    switch (cmd->type) {
        props = BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_HD_DIR ;
        props = BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY_LD_DIR ;
    if (!(props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED)) {
                (adv_itvl_min < BLE_HCI_ADV_ITVL_MIN) ||
                (adv_itvl_min > BLE_HCI_ADV_ITVL_MAX) ||
                (adv_itvl_max < BLE_HCI_ADV_ITVL_MIN) ||
                (adv_itvl_max > BLE_HCI_ADV_ITVL_MAX)) {
        (cmd->peer_addr_type > BLE_HCI_ADV_PEER_ADDR_MAX)) {
    if (cmd->own_addr_type > BLE_HCI_ADV_OWN_ADDR_RANDOM) {
    if (cmd->own_addr_type > BLE_HCI_ADV_OWN_ADDR_RANDOM) {
    if (((cmd->chan_map & 0xF8) != 0) || (cmd->chan_map == 0)) {
    if (adv_filter_policy > BLE_HCI_ADV_FILT_MAX) {
    if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
    } else {
    do {
                    !(advsm->flags & BLE_LL_ADV_SM_FLAG_NEW_SCAN_RSP_DATA)) {
    if (advsm->aux_active) {
    if (advsm->flags & BLE_LL_ADV_SM_FLAG_NEW_ADV_DATA) {
        if (advsm->new_adv_data) {
    } else if (advsm->flags & BLE_LL_ADV_SM_FLAG_NEW_SCAN_RSP_DATA) {
    if (advsm->adv_enabled) {
               !(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_SYNC_SENDING)) {
        if (ble_ll_state_get() == BLE_LL_STATE_ADV) {
        if (advsm->conn_comp_ev) {
    if (ble_ll_hci_adv_mode_ext()) {
                                                        advsm->adv_instance, 0,
                                                        advsm->events);
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
    if (advsm->duration) {
                             ble_ll_tmr_u2t(advsm->duration * 10000);
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
                     ble_ll_tmr_u2t(BLE_LL_ADV_STATE_HD_MAX * 1000);
    if (sync->ext_hdr_flags || sync->big) {
    if (sync->ext_hdr_flags) {
    if (sync->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_AUX_PTR_BIT)) {
        if (!SYNC_NEXT(advsm)->sch.enqueued) {
        } else {
    if (sync->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_TX_POWER_BIT)) {
    if (advsm->big) {
                                                  g_ble_ll_sched_offset_ticks,
    if (sync->data_len) {

     ble_phy_mode_set(advsm->sec_phy, advsm->sec_phy);
    if (rc) {
    if (rc) {
        (advsm->periodic_adv_props & BLE_HCI_LE_SET_PERIODIC_ADV_PROP_INC_TX_PWR)) {
    if (sync->ext_hdr_flags || sync->big) {
    if (sync->ext_hdr_flags) {
    if (advsm->big) {
    if ((rem_data_len > sync->data_len)) {
        if (!sync->ext_hdr_flags) {
    if (rc) {
                         void *arg)
    if (!sync->sch.enqueued) {
    if (!(sync->ext_hdr_flags & (1 << BLE_LL_EXT_ADV_AUX_PTR_BIT))) {
                                  advsm->periodic_adv_itvl_ticks))) {
    if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_NEW_DATA)) {
    if (advsm->periodic_sync_active) {
    if (advsm->periodic_new_data) {
    if (sync_next->sch.enqueued) {
                      ble_ll_tmr_u2t(advsm->adv_itvl_usecs + 5000);
    if (!advsm->periodic_adv_active) {
            (advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_SYNC_SENDING)) {
                                  BLE_LL_ADV_SM_FLAG_RX_ADD |
                                  BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD);
    if (!ble_ll_is_valid_own_addr_type(advsm->own_addr_type, random_addr)) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
        if (advsm->conn_comp_ev == NULL) {
            if (!advsm->conn_comp_ev) {
    if ((advsm->own_addr_type & 1) == 0) {
    } else {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
        if (advsm->peer_addr_type & 1) {
    if (advsm->own_addr_type > BLE_HCI_ADV_OWN_ADDR_RANDOM) {
                         (access_addr & 0x0000ffff);
    if (delta < 0) {
    if (advsm->periodic_adv_enabled && !advsm->periodic_adv_active) {
    if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY)) {
int
ble_ll_adv_read_txpwr(uint8_t *rspbuf, uint8_t *rsplen)
    struct ble_hci_le_rd_adv_chan_txpwr_rp *rsp = (void *) rspbuf;
    if (!advsm) {
    if (enable == 1) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_ADV_DATA_INCOMPLETE) {
                (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) &&
                !(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) &&
                SCAN_RSP_DATA_LEN(advsm) == 0) {
        if (duration < 0) {
            if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
            } else {
        if (!advsm->adv_enabled) {
    } else if (enable == 0) {
    } else {
int
ble_ll_hci_adv_set_enable(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_adv_enable_cp *cmd = (const void *) cmdbuf;
    if (len != sizeof(*cmd)) {
    if (new_data) {
        if (om) {
        if (!om) {
    if (OS_MBUF_PKTLEN(om) + datalen > maxlen) {
    if (ret) {
    if (!advsm) {
    if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE)) {
        if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY)) {
    switch (operation) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
            if (datalen > BLE_SCAN_RSP_LEGACY_DATA_MAX_LEN) {
        if (!advsm->scan_rsp_data) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (advsm->adv_enabled) {
        if (!datalen) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (advsm->adv_enabled) {
        if (!datalen) {
    if (advsm->adv_enabled) {
        if (advsm->new_scan_rsp_data) {
        if (!advsm->new_scan_rsp_data) {
                                            advsm->adv_itvl_usecs)) {
    } else {
        if (!advsm->scan_rsp_data) {
                                            advsm->adv_itvl_usecs)) {
int
ble_ll_hci_set_scan_rsp_data(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_scan_rsp_data_cp *cmd = (const void *) cmdbuf;
    if ((len != sizeof(*cmd)) || (cmd->scan_rsp_len > sizeof(cmd->scan_rsp))) {
    if (!advsm) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
            if (ble_ll_hci_adv_mode_ext()) {
    } else {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) {
    switch (operation) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
            if (datalen > BLE_ADV_LEGACY_DATA_MAX_LEN) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (!advsm->adv_enabled || !ADV_DATA_LEN(advsm) || datalen) {
        if (!advsm->adv_data) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (!datalen) {
        if (advsm->adv_enabled) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (advsm->adv_enabled) {
        if (!datalen) {
    if (advsm->adv_enabled) {
        if (advsm->new_adv_data) {
        if (!advsm->new_adv_data) {
                                            advsm->adv_itvl_usecs)) {
    } else {
        if (!advsm->adv_data) {
                                            advsm->adv_itvl_usecs)) {
        }
int
ble_ll_hci_set_adv_data(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_adv_data_cp *cmd = (const void *) cmdbuf;
    if ((len != sizeof(*cmd)) || (cmd->adv_data_len > sizeof(cmd->adv_data))) {
    switch (phy) {
    switch (phy) {
    if (advsm) {
    for (i = 0; i < ARRAY_SIZE(g_ble_ll_adv_sm); i++) {
        if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_CONFIGURED)) {
           /* configured flag is set by caller on success config */
           advsm->adv_instance = instance;
           return advsm;
int
ble_ll_adv_ext_set_param(const uint8_t *cmdbuf, uint8_t len,
                         uint8_t *rspbuf, uint8_t *rsplen)
    const struct ble_hci_le_set_ext_adv_params_cp *cmd = (const void *) cmdbuf;
    struct ble_hci_le_set_ext_adv_params_rp *rsp = (void *) rspbuf;
    if (len != sizeof(*cmd )) {
    if (!advsm) {
    if (advsm->adv_enabled) {
    if (advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_CONFIGURED) {
        if (advsm->periodic_adv_enabled) {
                         BLE_HCI_LE_SET_EXT_ADV_PROP_ANON_ADV)) {
    if (props & ~BLE_HCI_LE_SET_EXT_ADV_PROP_MASK) {
    if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
            SCAN_RSP_DATA_LEN(advsm) > BLE_SCAN_RSP_LEGACY_DATA_MAX_LEN) {
        switch (props) {
    } else {
        if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
        if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
            (props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE)) {
    if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
        if (ADV_DATA_LEN(advsm) || SCAN_RSP_DATA_LEN(advsm)) {
    } else {
                (adv_itvl_min < BLE_HCI_ADV_ITVL_MIN) ||
                (adv_itvl_max < BLE_HCI_ADV_ITVL_MIN)) {
                (adv_itvl_max > BLE_HCI_ADV_ITVL_MAX)) {
    if (((cmd->pri_chan_map & 0xF8) != 0) || (cmd->pri_chan_map == 0)) {
    if (cmd->own_addr_type > BLE_HCI_ADV_OWN_ADDR_MAX) {
    if (cmd->own_addr_type > BLE_HCI_ADV_OWN_ADDR_RANDOM) {
            (cmd->peer_addr_type > BLE_HCI_ADV_PEER_ADDR_MAX)) {
         cmd->filter_policy > BLE_HCI_ADV_FILT_MAX) {
    if (!pri_phy_valid(cmd->pri_phy)) {
            !sec_phy_valid(cmd->sec_phy)) {
    if (cmd->sid > 0x0f) {
    if (cmd->scan_req_notif > 0x01) {
    if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
    } else {
                                        advsm->scan_rsp_data, adv_itvl_usecs)) {
    if (cmd->tx_power == 127) {
    } else {
    if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
    } else if (props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) {
    } else {
    if (cmd->scan_req_notif) {
    } else {
int
ble_ll_adv_ext_set_adv_data(const uint8_t *cmdbuf, uint8_t cmdlen)
    const struct ble_hci_le_set_ext_adv_data_cp *cmd = (const void *) cmdbuf;
    if (cmdlen < sizeof(*cmd )) {
            cmd->adv_data_len > cmdlen - sizeof(*cmd)) {
int
ble_ll_adv_ext_set_scan_rsp(const uint8_t *cmdbuf, uint8_t cmdlen)
    const struct ble_hci_le_set_ext_scan_rsp_data_cp *cmd = (const void *) cmdbuf;
    if (cmdlen < sizeof(*cmd )) {
            cmd->scan_rsp_len > cmdlen - sizeof(*cmd)) {
int
ble_ll_adv_ext_set_enable(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_ext_adv_enable_cp *cmd = (const void *) cmdbuf;
    if (len < sizeof(*cmd)) {
    if (len != 2 + (cmd->num_sets * sizeof(cmd->sets[0]))) {
    if (cmd->num_sets > BLE_ADV_INSTANCES) {
    if (cmd->num_sets == 0) {
        if (cmd->enable) {
        for (i = 0; i < BLE_ADV_INSTANCES; i++) {
    for (i = 0; i < cmd->num_sets; i++) {
        for (j = i + 1; j < cmd->num_sets; j++) {
            if (cmd->sets[i].adv_handle == cmd->sets[j].adv_handle) {
        if (!advsm) {
        if (cmd->enable) {
            if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
                        le16toh(cmd->sets[i].duration) > 128) {
    for (i = 0; i < cmd->num_sets; i++) {
        if (rc) {
int
ble_ll_adv_set_random_addr(const uint8_t *addr, uint8_t instance)
    if (!advsm) {
            (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE)) {
int
ble_ll_adv_hci_set_random_addr(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_adv_set_rnd_addr_cp *cmd = (const void *) cmdbuf;
    if (len != sizeof(*cmd)) {
int
ble_ll_adv_remove(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_remove_adv_set_cp *cmd = (const void *) cmdbuf;
    if (len != sizeof(*cmd)) {
    if (!advsm) {
    if (advsm->adv_enabled) {
    if (advsm->periodic_adv_enabled) {
    if (advsm->periodic_adv_data) {
    if (advsm->adv_data) {
    if (advsm->scan_rsp_data) {
int
ble_ll_adv_clear_all(void)
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (g_ble_ll_adv_sm[i].adv_enabled) {
    if (g_ble_ll_adv_sm[i].periodic_adv_enabled) {
        return BLE_ERR_CMD_DISALLOWED;
    }
        (props & BLE_HCI_LE_SET_PERIODIC_ADV_PROP_INC_TX_PWR)) {
    if (ext_hdr) {
    if (rem_data_len > data_len) {
            /* adjust for flags that needs to be added if AuxPtr is only field
             * in Extended Header
             */
            if (!ext_hdr) {
                hdr_len += BLE_LL_EXT_ADV_FLAGS_SIZE;
                data_len -= BLE_LL_EXT_ADV_FLAGS_SIZE;
            }
            hdr_len += BLE_LL_EXT_ADV_AUX_PTR_SIZE;
            data_len -= BLE_LL_EXT_ADV_AUX_PTR_SIZE;
            /* PDU payload should be full if chained */
            BLE_LL_ASSERT(hdr_len + data_len == BLE_LL_MAX_PAYLOAD_LEN);
    while (offset < payload_len) {
int
ble_ll_adv_periodic_set_param(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_periodic_adv_params_cp *cmd = (const void *) cmdbuf;
    if (len != sizeof(*cmd)) {
    if (!advsm) {
                        BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY)) {
    if (advsm->periodic_adv_enabled) {
            (adv_itvl_min > adv_itvl_max)) {
    if (props & ~BLE_HCI_LE_SET_PERIODIC_ADV_PROP_MASK) {
                                             adv_itvl_max, advsm->sec_phy)) {
int
ble_ll_adv_periodic_set_data(const uint8_t *cmdbuf, uint8_t len)
    const struct ble_hci_le_set_periodic_adv_data_cp *cmd = (const void *) cmdbuf;
    if (len < sizeof(*cmd)) {
            cmd->adv_data_len != len - sizeof(*cmd)) {
    if (!advsm) {
    if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_CONFIGURED)) {
    switch (cmd->operation) {
        if (advsm->periodic_adv_enabled) {
        if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_DATA_INCOMPLETE)) {
        if (!advsm->periodic_adv_data || !cmd->adv_data_len) {
        if (advsm->periodic_adv_enabled) {
        if (!cmd->adv_data_len) {
    if (!new_data) {
                                             advsm->sec_phy)) {
    if (advsm->periodic_adv_active) {
        if (!advsm->periodic_new_data) {
    } else {
        if (!advsm->periodic_adv_data) {
    switch (cmd->operation) {
int
ble_ll_adv_periodic_enable(const uint8_t *cmdbuf, uint8_t len)
    if (len != sizeof(*cmd)) {
    if (!advsm) {
    if (cmd->enable & 0x02) {
    } else if (cmd->enable & 0xfc) {
    if (cmd->enable & 0xfe) {
    if (cmd->enable) {
                            BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY)) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_DATA_INCOMPLETE) {
        if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_CONFIGURED)) {
                                                 advsm->sec_phy)) {
        if (advsm->adv_enabled && !advsm->periodic_adv_active) {
    } else {
    if (!om) {
int
ble_ll_adv_periodic_set_info_transfer(const uint8_t *cmdbuf, uint8_t len,
                                      uint8_t *rspbuf, uint8_t *rsplen)
     struct ble_hci_le_periodic_adv_set_info_transfer_rp *rsp = (void *) rspbuf;
     struct ble_ll_conn_sm *connsm;
     struct ble_ll_adv_sm *advsm;
     uint16_t handle;
     int rc;

     if (len != sizeof(*cmd)) {
         rc = BLE_ERR_INV_HCI_CMD_PARMS;
         goto done;
     }

     advsm = ble_ll_adv_sm_find_configured(cmd->adv_handle);
     if (!advsm) {
         rc = BLE_ERR_UNK_ADV_INDENT;
         goto done;
     }

     if (!advsm->periodic_adv_active) {
         rc = BLE_ERR_CMD_DISALLOWED;
         goto done;
     }

     handle = le16toh(cmd->conn_handle);
     if (handle > 0xeff) {
         rc = BLE_ERR_INV_HCI_CMD_PARMS;
         goto done;
     }

     connsm = ble_ll_conn_find_by_handle(handle);
     if (!connsm) {
         rc = BLE_ERR_UNK_CONN_ID;
         goto done;
     }

     /* TODO should not need to shift
      * byte 3 (0 byte is conn_feature) , bit 1
      *
      * Allow initiate LL procedure only if remote supports it.
      */
     if (!ble_ll_conn_rem_feature_check(connsm, BLE_LL_FEAT_SYNC_TRANS_RECV)) {
         rc = BLE_ERR_UNSUPP_REM_FEATURE;
         goto done;
     }

     rc = ble_ll_adv_periodic_send_sync_ind(advsm, connsm, cmd->service_data);
 done:
     rsp->conn_handle = cmd->conn_handle;
     *rsplen = sizeof(*rsp);
     return rc;
    if (memcmp(advsm->adva, adva, BLE_DEV_ADDR_LEN)) {
    if (pdu_type == BLE_ADV_PDU_TYPE_SCAN_REQ) {
    } else {
    if (rxbuf[0] & BLE_ADV_PDU_HDR_TXADD_MASK) {
    } else {
    if (ble_ll_resolv_enabled()) {
        if (ble_ll_is_rpa(peer, txadd)) {
            if (advsm->adv_rpa_index >= 0) {
                if (chk_wl) {
            } else {
                if (chk_wl) {
        } else {
                rl->rl_has_peer) {
    if (chk_wl && !ble_ll_whitelist_match(peer, peer_addr_type, resolved)) {
    if (pdu_type == BLE_ADV_PDU_TYPE_SCAN_REQ) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_SCAN_REQ_NOTIF) {
        if (!rc) {
    } else if (pdu_type == BLE_ADV_PDU_TYPE_AUX_CONNECT_REQ) {
        if (ble_ll_conn_find_by_peer_addr(peer, peer_addr_type)) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
            if (memcmp(advsm->initiator_addr, peer, BLE_DEV_ADDR_LEN)) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (!rc) {
    if (!(advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY)) {
        if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD)) {
    if (hdr->rxinfo.flags & BLE_MBUF_HDR_F_DEVMATCH) {
        if (rxbuf[0] & BLE_ADV_PDU_HDR_TXADD_MASK) {
        } else {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_DIRECTED) {
            if (resolved) {
                memcmp(advsm->peer_addr, ident_addr, BLE_DEV_ADDR_LEN)) {
    if (valid) {
        if (resolved) {
        if (valid) {
            if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD)) {
        } else if (advsm->flags & BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD) {
int
ble_ll_adv_rx_isr_end(uint8_t pdu_type, struct os_mbuf *rxpdu, int crcok)
    if (rxpdu == NULL) {
    } else {
        if (ble_ll_adv_active_chanset_is_sec(g_ble_ll_cur_adv_sm)) {
        } else {
        if (crcok) {
                (pdu_type == BLE_ADV_PDU_TYPE_CONNECT_IND)) {
        if (rc) {
    if (rc) {
void
ble_ll_adv_rx_pkt_in(uint8_t ptype, uint8_t *rxbuf, struct ble_mbuf_hdr *hdr)
    if (!advsm->adv_enabled) {
    if (BLE_MBUF_HDR_CRC_OK(hdr)) {
        if (ptype == BLE_ADV_PDU_TYPE_CONNECT_IND) {
            if (ble_ll_adv_conn_req_rxd(rxbuf, hdr, advsm)) {
        } else {
                (hdr->rxinfo.flags & BLE_MBUF_HDR_F_SCAN_RSP_TXD)) {
    if (adv_event_over) {
int
ble_ll_adv_rx_isr_start(uint8_t pdu_type)
    if (pdu_type == BLE_ADV_PDU_TYPE_SCAN_REQ) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_SCANNABLE) {
    } else {
        if (pdu_type == BLE_ADV_PDU_TYPE_CONNECT_IND) {
            if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_CONNECTABLE) {
    if (rc < 0) {
    if (!sch->enqueued) {
        if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_HD_DIRECTED) {
        } else {
        if (rc) {
                                                        !advsm->aux_active) {
    if (advsm->props & BLE_HCI_LE_SET_EXT_ADV_PROP_LEGACY) {
        if (advsm->flags & BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD) {
    if (advsm->adv_chan == final_adv_chan) {
        if (advsm->events_max) {
        if (delta_t < 0) {
            while (delta_t < 0) {
    } else {
        if ((mask & advsm->adv_chanmask) == 0) {
                advsm->aux_active &&
                LL_TMR_GT(advsm->adv_pdu_start_time,
                           AUX_CURRENT(advsm)->start_time)) {
        LL_TMR_GEQ(advsm->adv_pdu_start_time, advsm->adv_end_time)) {
                !advsm->aux_active) {
        LL_TMR_GEQ(advsm->adv_pdu_start_time, advsm->adv_end_time)) {
    if (advsm->events_max && (advsm->events >= advsm->events_max)) {
                !advsm->aux_active) {
    if (!resched_pdu) {
    if (rc) {
    if (advsm->aux_dropped) {
    if (advsm->aux_not_scanned) {
    if (advsm->flags & BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD) {
        if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD_ERR)) {
        } else {
                                          BLE_LL_ADV_SM_FLAG_CONN_RSP_TXD_ERR);
    if (aux_next->sch.enqueued) {
        LL_TMR_GEQ(advsm->adv_pdu_start_time, advsm->adv_end_time)) {
    if (advsm->events_max && (advsm->events >= advsm->events_max)) {
    if (BLE_MBUF_HDR_EXT_ADV_SEC(hdr)) {
    } else {
int
ble_ll_adv_can_chg_whitelist(void)
    for (i = 0; i < BLE_ADV_INSTANCES; ++i) {
            (advsm->adv_filter_policy != BLE_HCI_ADV_FILT_NONE)) {
void
ble_ll_adv_send_conn_comp_ev(struct ble_ll_conn_sm *connsm,
                             struct ble_mbuf_hdr *rxhdr)
    if (ble_ll_hci_adv_mode_ext()) {
                                          connsm->conn_handle, advsm->events);
    if (advsm->own_addr_type > BLE_HCI_ADV_OWN_ADDR_RANDOM) {
                                    ble_ll_is_rpa(advsm->adva, 1)) {
void
ble_ll_adv_wfr_timer_exp(void)
void
ble_ll_adv_reset(void)
    for (i = 0; i < BLE_ADV_INSTANCES; ++i) {
    for (i = 0; i < BLE_ADV_INSTANCES; i++) {
        if (g_ble_ll_adv_sm[i].adv_enabled) {
    if (!advsm) {
    if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_CONFIGURED)) {
int
ble_ll_adv_sync_big_add(struct ble_ll_adv_sm *advsm,
                        struct ble_ll_iso_big *big)
    if (!(advsm->flags & BLE_LL_ADV_SM_FLAG_PERIODIC_CONFIGURED)) {
    if (advsm->big && (advsm->big != big)) {
int
ble_ll_adv_sync_big_remove(struct ble_ll_adv_sm *advsm,
                           struct ble_ll_iso_big *big)
    if (advsm->big != big) {
void
ble_ll_adv_init(void)
    for (i = 0; i < BLE_ADV_INSTANCES; ++i) {
