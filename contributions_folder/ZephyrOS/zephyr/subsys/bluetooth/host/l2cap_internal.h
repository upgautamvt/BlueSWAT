# Lines added by author
#define BT_L2CAP_CID_BR_SIG		0x0001
#define BT_L2CAP_CID_ATT		0x0004
#define BT_L2CAP_CID_LE_SIG		0x0005
#define BT_L2CAP_CID_SMP		0x0006
#define BT_L2CAP_CID_BR_SMP		0x0007
#define BT_L2CAP_PSM_RFCOMM		0x0003
	u8_t  code;
	u8_t  ident;
#define BT_L2CAP_REJ_NOT_UNDERSTOOD	0x0000
#define BT_L2CAP_REJ_MTU_EXCEEDED	0x0001
#define BT_L2CAP_REJ_INVALID_CID	0x0002
#define BT_L2CAP_CMD_REJECT		0x01
	u8_t  data[0];
#define BT_L2CAP_CONN_REQ		0x02
#define BT_L2CAP_CS_NO_INFO		0x0000
#define BT_L2CAP_CS_AUTHEN_PEND		0x0001
#define BT_L2CAP_BR_SUCCESS		0x0000
#define BT_L2CAP_BR_PENDING		0x0001
#define BT_L2CAP_BR_ERR_PSM_NOT_SUPP	0x0002
#define BT_L2CAP_BR_ERR_SEC_BLOCK	0x0003
#define BT_L2CAP_BR_ERR_NO_RESOURCES	0x0004
#define BT_L2CAP_BR_ERR_INVALID_SCID	0x0006
#define BT_L2CAP_BR_ERR_SCID_IN_USE	0x0007

#define BT_L2CAP_CONN_RSP		0x03
#define BT_L2CAP_CONF_SUCCESS		0x0000
#define BT_L2CAP_CONF_UNACCEPT		0x0001
#define BT_L2CAP_CONF_REJECT		0x0002
#define BT_L2CAP_CONF_REQ		0x04
	u8_t  data[0];
#define BT_L2CAP_CONF_RSP		0x05
	u8_t  data[0];
#define BT_L2CAP_CONF_OPT_MTU		0x01
#define BT_L2CAP_CONF_HINT		0x80
#define BT_L2CAP_CONF_MASK		0x7f
#define BT_L2CAP_DISCONN_REQ		0x06
#define BT_L2CAP_DISCONN_RSP		0x07
#define BT_L2CAP_INFO_FEAT_MASK		0x0002
#define BT_L2CAP_INFO_FIXED_CHAN	0x0003
#define BT_L2CAP_INFO_REQ		0x0a
#define BT_L2CAP_INFO_SUCCESS		0x0000
#define BT_L2CAP_INFO_NOTSUPP		0x0001
#define BT_L2CAP_INFO_RSP		0x0b
	u8_t  data[0];
#define BT_L2CAP_CONN_PARAM_REQ		0x12
#define BT_L2CAP_CONN_PARAM_ACCEPTED	0x0000
#define BT_L2CAP_CONN_PARAM_REJECTED	0x0001
#define BT_L2CAP_CONN_PARAM_RSP		0x13
#define BT_L2CAP_LE_CONN_REQ		0x14
#define BT_L2CAP_LE_SUCCESS		0x0000
#define BT_L2CAP_LE_ERR_PSM_NOT_SUPP	0x0002
#define BT_L2CAP_LE_ERR_NO_RESOURCES	0x0004
#define BT_L2CAP_LE_ERR_AUTHENTICATION	0x0005
#define BT_L2CAP_LE_ERR_AUTHORIZATION	0x0006
#define BT_L2CAP_LE_ERR_KEY_SIZE	0x0007
#define BT_L2CAP_LE_ERR_ENCRYPTION	0x0008
#define BT_L2CAP_LE_ERR_INVALID_SCID	0x0009
#define BT_L2CAP_LE_ERR_SCID_IN_USE	0x000A
#define BT_L2CAP_LE_ERR_UNACCEPT_PARAMS	0x000B

#define BT_L2CAP_LE_CONN_RSP		0x15
#define BT_L2CAP_LE_CREDITS		0x16
#define BT_L2CAP_SDU_HDR_LEN		2
#define BT_L2CAP_RX_MTU (CONFIG_BT_RX_BUF_LEN - \
			 BT_HCI_ACL_HDR_SIZE - BT_L2CAP_HDR_SIZE)
	u16_t		cid;
#define BT_L2CAP_CHANNEL_DEFINE(_name, _cid, _accept, _destroy)         \
	const Z_STRUCT_SECTION_ITERABLE(bt_l2cap_fixed_chan, _name) = { \
				.cid = _cid,                            \
				.accept = _accept,                      \
				.destroy = _destroy,                    \
			}
	u16_t		cid;
#define BT_L2CAP_BR_CHANNEL_DEFINE(_name, _cid, _accept)		\
	const Z_STRUCT_SECTION_ITERABLE(bt_l2cap_br_fixed_chan, _name) = { \
				.cid = _cid,			\
				.accept = _accept,		\
			}
#define bt_l2cap_chan_set_state(_chan, _state) \
#define bt_l2cap_create_pdu(_pool, _reserve) \
