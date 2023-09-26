/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 * Copyright (c) 2016 Vinayak Kariappa Chettimada
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CCM_H_
#define CCM_H_

struct ccm {
	u8_t key[16];
	u64_t counter;
	u8_t direction : 1;
	u8_t resv1 : 7;
	u8_t iv[8];
} __packed;

#endif
