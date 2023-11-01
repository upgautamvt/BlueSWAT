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

#endif
