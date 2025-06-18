# Lines added by author
static struct {
    if (tx_ringbuf_head == tx_ringbuf_tail) {
            tx_ringbuf_tail) {
        if (os_started()) {
    while (len--) {
    switch (failed_hdr->opcode) {
    if (*cnt < UINT8_MAX) {
    struct ble_monitor_hdr *hdr = (struct ble_monitor_hdr *) rtt_pktbuf;
    if (!discard) {
    if (rtt_pktbuf_pos < sizeof(hdr->data_len) + hdr->data_len) {
    if (!discard) {
    if (ret > 0) {
    } else {
    if (rtt_drops.dropped) {
    hdr.hdr_len  = hdr_len;
    hdr.opcode   = htole16(opcode);
    hdr.flags    = 0;
    if (rtt_drops.dropped) {
static FILE *btmon = (FILE *) &(struct File) {
    .vmt = &(struct File_methods) {
void
ble_monitor_init(void)
    ble_monitor_new_index(0, (uint8_t[6]){ }, "nimble0");
int
ble_monitor_send(uint16_t opcode, const void *data, size_t len)
int
ble_monitor_send_om(uint16_t opcode, const struct os_mbuf *om)
    while (om_tmp) {
    while (om) {
int
ble_monitor_new_index(uint8_t bus, uint8_t *addr, const char *name)
int
ble_monitor_log(int level, const char *fmt, ...)
    switch (level) {
    do {
        len =  vasprintf(&tmp, fmt, va);
int
ble_monitor_out(int c)
    if (c != '\n') {
        if (len < sizeof(buf) - 1) {
int
ble_transport_to_ll_cmd(void *buf)
    ble_monitor_send(BLE_MONITOR_OPCODE_COMMAND_PKT, buf, cmd->length +
                                                          sizeof(*cmd));
int
ble_transport_to_ll_acl(struct os_mbuf *om)
int
ble_transport_to_ll_iso(struct os_mbuf *om)
int
ble_transport_to_hs_acl(struct os_mbuf *om)
int
ble_transport_to_hs_evt(void *buf)
    ble_monitor_send(BLE_MONITOR_OPCODE_EVENT_PKT, buf, ev->length +
                                                        sizeof(*ev));
int
ble_transport_to_hs_iso(struct os_mbuf *om)
