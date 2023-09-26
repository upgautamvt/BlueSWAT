/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifdef CONFIG_BT_CTLR_ASSERT_HANDLER
void bt_ctlr_assert_handle(char *file, u32_t line);
#define LL_ASSERT(cond)                                                        \
	if (!(cond)) {                                                         \
		bt_ctlr_assert_handle(__FILE__, __LINE__);                     \
	}
#else
#define LL_ASSERT(cond) BT_ASSERT(cond)
#endif

#include "hal/debug_vendor_hal.h"

// IFW below

#define VNAME(name) (#name)
#define IFW_DEBUG_LOG(fmt, ...)                                                \
	printf("[%s:%d:%s] " fmt "\n", __FILE__, __LINE__, __func__,           \
	       ##__VA_ARGS__)

#define IFW_DEBUG_LOG_CHECK_FAILURE(fmt, ...)                                  \
	printf("[%s:%d:%s] Malicious transition detected. " fmt "\n",          \
	       __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#define IFW_DEBUG_LOG_UPDATE_ERROR(fmt, ...)                                   \
	printf("[%s:%d:%s] FSM state update error. " fmt "\n", __FILE__,       \
	       __LINE__, __func__, ##__VA_ARGS__)

#define IFW_DEBUG_LOG_UPDATE_SUCCESS(fmt, ...)                                 \
	printf("[%s:%d:%s] FSM state update success. " fmt "\n", __FILE__,     \
	       __LINE__, __func__, ##__VA_ARGS__)

// IFW above