#include <stdio.h>

#include "utils.h"
#include "include/fsm_policy_cache.h"
// #include "fsm_lib_hdr.h"

static void disable_mpu_for_jit()
{
	extern void arm_core_mpu_disable();
	arm_core_mpu_disable();
}

void ifw_fsm_enable(bool jit)
{
	load_all_policies();

	if (jit) {
		disable_mpu_for_jit();
		set_all_policy_jit_on();
	}

	// IFW_DEBUG_LOG("FSM rules loaded success.");
}

// handle in ull.c to reset the connection
// extern void ll_rx_put(memq_link_t *link, void *rx);

// /**
//  * @brief Permit another loop in the controller thread (prio_recv_thread)
//  * @details Execution context: ULL mayfly
//  */
// extern void ll_rx_sched(void);

// static void ll_rx_put_sched(memq_link_t *link, void *rx)
// {
// 	ll_rx_put(link, rx);
// 	ll_rx_sched();
// }

// TODO
// reset the handle after rx packet drop
// void ifw_invalid_release(struct ull_hdr *hdr, struct lll_conn *lll,
// 			 memq_link_t *link, struct node_rx_hdr *rx)
// {
// 	/* Reset the advertising disabled callback */
// 	hdr->disabled_cb = NULL;

// 	/* Let the advertiser continue with connectable advertising */
// 	lll->slave.initiated = 0U;

// 	/* Mark for buffer for release */
// 	rx->type = NODE_RX_TYPE_DC_PDU_RELEASE;

// 	/* Enqueue connection or CSA event to be release */
// 	ll_rx_put_sched(link, rx);
// }