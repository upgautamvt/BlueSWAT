# Lines added by author
#define BLE_HCI_EDTT_NONE        0x00
#define BLE_HCI_EDTT_CMD         0x01
#define BLE_HCI_EDTT_ACL         0x02
#define BLE_HCI_EDTT_EVT         0x04
struct ble_hci_edtt_pkt {
    STAILQ_ENTRY(ble_hci_edtt_pkt) next;
    for (i = 0; i < len; i++) {
    if (fptr) {
    if (fptr) {
    int flen = (int) strlen(MYNEWT_VAL(EDTT_HCI_LOG_FILE)) + 7;
    char *fpath = (char *) calloc(flen, sizeof(char));
    if (OS_MBUF_PKTLEN(om) == 0) {
int
ble_transport_to_hs_evt_impl(void *buf)
int
ble_transport_to_hs_acl_impl(struct os_mbuf *om)
void
ble_transport_hs_init(void)

    if (size > 0) {
        edtt_read((uint8_t *) buffer, size, EDTTT_BLOCK);
    edtt_write((uint8_t *) &response, sizeof(response), EDTTT_BLOCK);
    edtt_write((uint8_t *) &size, sizeof(size), EDTTT_BLOCK);
    edtt_write((uint8_t *) &le_error, sizeof(le_error), EDTTT_BLOCK);
send_hci_cmd_to_ctrl(uint16_t opcode, uint8_t param_len, uint16_t response) {
    if (buf != NULL) {
        if (param_len) {
            edtt_read((uint8_t *) buf->data, param_len, EDTTT_BLOCK);
        if (err) {
    } else {
    edtt_write((uint8_t *) &response, sizeof(response), EDTTT_BLOCK);
    edtt_write((uint8_t *) &size, sizeof(size), EDTTT_BLOCK);
    if (size > 0) {
    struct ble_hci_ev_command_complete *evt_cc = (void *) evt->data;
    if (evt_cc->opcode == 0) {
    } else if (evt_cc->opcode == waiting_opcode) {
        edtt_write((uint8_t *) &response, sizeof(response), EDTTT_BLOCK);
        edtt_write((uint8_t *) &size, sizeof(size), EDTTT_BLOCK);
        edtt_write((uint8_t *) &evt_cc->status, sizeof(evt_cc->status), EDTTT_BLOCK);
        edtt_write((uint8_t *) &evt_cc->return_params, size - sizeof(evt_cc->status), EDTTT_BLOCK);
    } else {
                             " expected 0x(%04x)", evt_cc->opcode, waiting_opcode);
    struct ble_hci_ev_command_status *evt_cs = (void *) evt->data;
    if (opcode == waiting_opcode) {
        edtt_write((uint8_t *) &response, sizeof(response), EDTTT_BLOCK);
        edtt_write((uint8_t *) &size, sizeof(size), EDTTT_BLOCK);
        edtt_write((uint8_t *) &evt_cs->status, sizeof(evt_cs->status), EDTTT_BLOCK);
        edtt_write((uint8_t *) &evt_cs->num_packets, size - sizeof(evt_cs->status), EDTTT_BLOCK);
    } else {
                             " expected 0x(%04x)", opcode, waiting_opcode);

    while (1) {
        if (pkt->type == BLE_HCI_EDTT_EVT) {
            switch (evt->opcode) {
                if (evt_ncp->completed[0].packets == 0) {
                } else {
        } else if (pkt->type == BLE_HCI_EDTT_ACL) {
    while ((pkt = (void *)os_eventq_get_no_wait(&edtt_q_event))) {
    pkt = (void*)os_eventq_get(&edtt_q_event);
    if (pkt) {
    } else {
    while (count--) {
    struct has_event_resp {
        .count = edtt_q_event_count
    };
    if (size > 0) {
    edtt_write((uint8_t *) &le_response, sizeof(le_response), EDTTT_BLOCK);
    while ((pkt = (void *)os_eventq_get_no_wait(&edtt_q_data))) {
    struct has_data_resp {
        .empty = 0
    };
    if (size > 0) {
    if (edtt_q_data.evq_list.stqh_first == NULL) {
    edtt_write((uint8_t *) &le_response, sizeof(le_response), EDTTT_BLOCK);
    if (pkt) {
        while (om != NULL) {
    } else {
    struct data_write_resp {
        .status = 0
    };
    if (size >= sizeof(hdr)) {
        if (om) {
            if (size >= hdr.hdh_len) {
            if (err) {
        } else {
    } else {
    edtt_write((uint8_t *) &response, sizeof(response), EDTTT_BLOCK);
    if (hci_ev) {
        ev = (void *) hci_ev->data;
        ble_hci_edtt_cmdevt_tx((uint8_t *) hci_ev, BLE_HCI_EDTT_EVT);
edtt_poller(void *arg) {
    while (1) {
        edtt_read((uint8_t *) &command, sizeof(command), EDTTT_BLOCK);
        edtt_read((uint8_t *) &size, sizeof(size), EDTTT_BLOCK);
        switch (command) {
            case CMD_ECHO_REQ:
                echo(size);
                break;
            case CMD_FLUSH_EVENTS_REQ:
                flush_events(size);
                break;
            case CMD_HAS_EVENT_REQ:
                has_event(size);
                break;
            case CMD_GET_EVENT_REQ: {
                uint8_t multiple;

                edtt_read((uint8_t *) &multiple, sizeof(multiple), EDTTT_BLOCK);
                if (multiple)
                    get_events(--size);
                else
                    get_event(--size);
                break;
            case CMD_LE_FLUSH_DATA_REQ:
                le_flush_data(size);
                break;
            case CMD_LE_DATA_READY_REQ:
                le_data_ready(size);
                break;
            case CMD_LE_DATA_WRITE_REQ:
                le_data_write(size);
                break;
            case CMD_LE_DATA_READ_REQ:
                le_data_read(size);
                break;
            case CMD_WRITE_BD_ADDR_REQ:
                edtt_read((uint8_t *) &opcode, sizeof(opcode), EDTTT_BLOCK);

                if (opcode == BT_HCI_OP_VS_WRITE_BD_ADDR) {
                    edtt_read((uint8_t *) &bdaddr, sizeof(bdaddr), EDTTT_BLOCK);
                    ble_ll_set_public_addr(bdaddr);
                    fake_write_bd_addr_cc();
                } else {
                    assert(0);
                }
                break;
            default:
                if (size >= 2) {
                    edtt_read((uint8_t *) &opcode, sizeof(opcode), EDTTT_BLOCK);
                    send_hci_cmd_to_ctrl(opcode, size - 2, command + 1);
                }
int
edtt_init(void)
void
ble_hci_edtt_init(void)
