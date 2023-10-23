#include <stdio.h>

#include "fsm_core.h"
#include "fsm_policy_cache.h"
#include "fsm_lib_hdr.h"
#include "fsm_handle.h"

#include "utils.h"

static int run_LL_PKT_PARSER(memq_link_t *link, struct node_rx_hdr *rx);

int total = 0;

void test_all_mem()
{
    DEBUG_LOG("Test all policy for mem inspection.");

    int result;
    struct FsmState testFSM = {0};

    // result = run_fsm_check_policy(CHANNEL_MAP, CONN, &testFSM);
    // result = run_fsm_check_policy(CHANNEL_HOP, CONN, &testFSM);
    // result = run_fsm_check_policy(NESN, DC, &testFSM);
    // result = run_fsm_check_policy(HCI_ACL_LEN, SPI, &testFSM);
    // result = run_fsm_check_policy(HCI_EVT_LEN, SPI, &testFSM);
    // result = run_fsm_check_policy(SCAN_RSP_LEN, CONN, &testFSM);
    // result = run_fsm_check_policy(LLCP_LEN_REQ, DC, &testFSM);
    result = run_fsm_check_policy(LLCP_CONN_PARAM_REQ, DC, &testFSM);
    // result = run_fsm_check_policy(LLL_INTERVAL, CONN, &testFSM);
    // result = run_fsm_check_policy(SMP_KEYS, DC, &testFSM);
}

void test_local_conn_chan_map()
{
    DEBUG_LOG("Test PID_conn_chan_map policy Locally.");

    int result;
    struct FsmState testFSM = {0};

    // set invalid field
    testFSM.conn_param[CHANNEL_MAP] = 0;

    result = run_fsm_check_policy(CHANNEL_MAP, CONN, &testFSM);
    if (result == IFW_OPERATION_REJECT)
    {
        DEBUG_LOG("Invalid transition detected.");
    }

    testFSM.conn_param[CHANNEL_MAP] = 3;

    result = run_fsm_check_policy(CHANNEL_MAP, CONN, &testFSM);
    if (result == IFW_OPERATION_REJECT)
    {
        DEBUG_LOG("Invalid transition detected.");
    }

    DEBUG_LOG("Test complete.");
}

void test_local_conn_chan_hop()
{
    DEBUG_LOG("Test PID_conn_chan_hop policy Locally.");

    int result;
    struct FsmState testFSM = {0};

    // set invalid field
    testFSM.conn_param[CHANNEL_HOP] = 20;

    result = run_fsm_check_policy(CHANNEL_HOP, CONN, &testFSM);
    if (result == IFW_OPERATION_REJECT)
    {
        DEBUG_LOG("Invalid transition detected.");
    }

    // set valid field
    testFSM.conn_param[CHANNEL_HOP] = 10;

    result = run_fsm_check_policy(CHANNEL_HOP, CONN, &testFSM);
    if (result == IFW_OPERATION_REJECT)
    {
        DEBUG_LOG("Invalid transition detected.");
    }

    DEBUG_LOG("Test complete.");
}

void test_local_ebpf_helper()
{
    DEBUG_LOG("Test PID_ebpf_helper_test locally.");

    int result;
    struct FsmState testFSM = {0};

    // set invalid field
    testFSM.dc_param[NESN] = 0;

    result = run_fsm_check_policy(NESN, DC, &testFSM);
    if (result == IFW_OPERATION_REJECT)
    {
        DEBUG_LOG("Invalid transition detected.");
    }
}

static inline void fill_struct(void *data, int len)
{
    for (int i = 0; i < len; i++)
    {
        *((uint8_t *)data + i) = i;
    }
}

int N = 1000;
int spd[1000] = {0};
int spd_min = 0;
int spd_max = 0;
int spd_total = 0;
int spd_avg = 0;
int spd_med = 0;
double spd_var = 0;

void quick_sort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivot = arr[left];
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
        {
            j--;
        }
        arr[i] = arr[j];
        while (i < j && arr[i] <= pivot)
        {
            i++;
        }
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    quick_sort(arr, left, i - 1);
    quick_sort(arr, i + 1, right);
}

static void construct_LL_packet()
{
    DEBUG_LOG("------- Test LL packet parser --------\n");

    // construct Bluetooth packets
    memq_link_t *link;

    char ble_packet[256] = {0};
    char param_mem[64] = {0};
    struct lll_conn data = {0};

    struct node_rx_hdr *rx = ble_packet;

    struct node_rx_ftr *rx_ftr = &rx->rx_ftr;
    rx_ftr->param = param_mem;

    struct node_rx_ftr *ftr = &rx->rx_ftr;
    struct lll_conn *lll = *((struct lll_conn **)((u8_t *)ftr->param +
                                                  sizeof(struct lll_hdr)));

    *(volatile uint32_t **)((uint8_t *)param_mem + sizeof(struct lll_hdr)) =
        (uint32_t)&data;
    struct pdu_adv *pdu_adv = (void *)((struct node_rx_pdu *)rx)->pdu;
    fill_struct(pdu_adv, 50);

    for (int i = 0; i < N; i++)
    {
        rx->type = sys_rand32_get() % 16;
        // lll->role = sys_rand32_get() % 2;

        spd[i] = run_LL_PKT_PARSER(link, rx);

        spd_total += spd[i];
    }
}

static int run_LL_PKT_PARSER(memq_link_t *link, struct node_rx_hdr *rx)
{
    total = 0;

    reset_timer_tick();

    int starti = get_cur_tick();
    IFW_LL_PACKET_PARSER(link, rx);
    total = get_cur_tick() - starti;

    return total;
}

static int run_L2CAP_PKT_PARSER(struct bt_conn *conn, struct net_buf *buf)
{
    total = 0;

    reset_timer_tick();

    int starti = get_cur_tick();
    IFW_L2CAP_PACKET_PARSER(conn, buf);
    total = get_cur_tick() - starti;

    return total;
}

static void construct_L2CAP_pkt()
{
    DEBUG_LOG("------- Test L2CAP packet parser --------\n");

    u8_t data[50] = {0};
    u8_t data_smp[50] = {0};
    char conn_pyd[160] = {0};
    char buf_pyd[24] = {0};

    // u8_t *temp;

    struct bt_conn *conn = conn_pyd;
    struct net_buf *buf = buf_pyd;
    struct bt_l2cap_hdr *hdr = data;
    struct bt_smp_hdr *hdr_smp = data_smp;

    DEBUG_LOG("Sizeof bt_l2cap_hdr: %d\n", sizeof(struct bt_l2cap_hdr));
    DEBUG_LOG("Sizeof bt_smp_hdr: %d\n", sizeof(struct bt_smp_hdr));
    DEBUG_LOG("Sizeof _slist: %d\n", sizeof(struct _slist));

    fill_struct(data, 50);
    fill_struct(data_smp, 50);

    buf->data = hdr_smp;
    buf->data -= sizeof(*hdr);
    buf->data = hdr;
    // // (u8_t *)(buf->data + sizeof(*hdr)) = hdr_smp;

    // temp = buf->data + sizeof(*hdr);
    // *temp = hdr_smp;

    buf->len = sizeof(*hdr) + sizeof(*hdr_smp);

    for (int i = 0; i < N; i++)
    {
        hdr->cid = sys_rand32_get() % 4;
        hdr_smp->code = sys_rand32_get() % 16;

        DEBUG_LOG("CID: %d, CID_new: %d, CODE: %d\n", hdr->cid,
                  sys_le16_to_cpu(hdr->cid), hdr_smp->code);

        spd[i] = run_L2CAP_PKT_PARSER(conn, buf);

        spd_total += spd[i];
    }
}

void test_runtime_overhead()
{
    construct_LL_packet();
    // construct_L2CAP_pkt();

    quick_sort(spd, 0, N - 1);

    spd_avg = spd_total / N;
    spd_med = spd[N / 2];
    spd_min = spd[0];
    spd_max = spd[N - 1];

    for (int i = 0; i < N; i++)
    {
        spd_var += (tick_to_us(spd[i]) - tick_to_us(spd_avg)) *
                   (tick_to_us(spd[i]) - tick_to_us(spd_avg));
    }

    DEBUG_LOG("Avg: %d ticks, %f us\n", spd_avg, tick_to_us(spd_avg));
    DEBUG_LOG("Min: %d ticks, %f us\n", spd_min, tick_to_us(spd_min));
    DEBUG_LOG("Max: %d ticks, %f us\n", spd_max, tick_to_us(spd_max));
    DEBUG_LOG("Med: %d ticks, %f us\n", spd_med, tick_to_us(spd_med));
    DEBUG_LOG("Var: %f\n", spd_var / N);
}
