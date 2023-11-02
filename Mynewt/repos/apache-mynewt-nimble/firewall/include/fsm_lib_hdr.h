#ifndef FSM_LIB_HDR_H_
#define FSM_LIB_HDR_H_

#include "modlog/modlog.h"

// for ll packet parser
#include "controller/ble_ll_conn.h"
#include "os/os_mbuf.h"
#include "nimble/ble.h"
#include "controller/ble_ll.h"

#define IFW_BLE_LL_PDU_HDR_LEN (2)
#define IFW_BLE_DEV_ADDR_LEN (6) /* bytes */
#define IFW_BLE_LL_CONN_REQ_ADVA_OFF (IFW_BLE_LL_PDU_HDR_LEN + IFW_BLE_DEV_ADDR_LEN)

// for L2CAP packet parser

// for SMP parser
#include "os/queue.h"
#include "host/ble_hs.h"

typedef uint8_t ifw_ble_l2cap_chan_flags;
typedef int ifw_ble_l2cap_rx_fn(struct ble_l2cap_chan *chan);

struct ifw_ble_l2cap_chan
{
    SLIST_ENTRY(ble_l2cap_chan)
    next;
    uint16_t conn_handle;
    uint16_t dcid;
    uint16_t scid;

    /* Unions just to avoid confusion on MPS/MTU.
     * In CoC context, L2CAP MTU is MPS
     */
    union
    {
        uint16_t my_mtu;
        uint16_t my_coc_mps;
    };

    union
    {
        uint16_t peer_mtu;
        uint16_t peer_coc_mps;
    };

    ifw_ble_l2cap_chan_flags flags;

    struct os_mbuf *rx_buf;
    uint16_t rx_len; /* Length of current reassembled rx packet. */

    ifw_ble_l2cap_rx_fn *rx_fn;
};

struct ifw_ble_sm_pair_cmd
{
    uint8_t io_cap;
    uint8_t oob_data_flag;
    uint8_t authreq;
    uint8_t max_enc_key_size;
    uint8_t init_key_dist;
    uint8_t resp_key_dist;
} __attribute__((packed));

#endif
