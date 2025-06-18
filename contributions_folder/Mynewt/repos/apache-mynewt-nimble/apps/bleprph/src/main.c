# Lines added by author
static int
main_fn(int argc, char **argv)
    MODLOG_DFLT(INFO, "bleprph starting\n");

    MODLOG_DFLT(INFO, "Hello, world!\n");

// BlueSWAT header
#include "fsm_core.h"
static void
bleprph_advertise(void)
        MODLOG_DFLT(INFO, "subscribe event; conn_handle=%d attr_handle=%d "
        MODLOG_DFLT(INFO, "mtu update event; conn_handle=%d cid=%d mtu=%d\n",
                "encrypted=%d authenticated=%d bonded=%d\n",
    if (rc != 0) {
        BLE_UUID16_INIT(GATT_SVR_SVC_ALERT_UUID)
    };
    if (rc != 0) {
    if (rc != 0) {
static int
bleprph_gap_event(struct ble_gap_event *event, void *arg)
    switch (event->type) {
        if (event->connect.status == 0) {
        if (event->connect.status != 0) {
        if (rc == 0) {
    while (1) {
int
main(int argc, char **argv)
    extern void bsim_init(int argc, char** argv, void *main_fn);
