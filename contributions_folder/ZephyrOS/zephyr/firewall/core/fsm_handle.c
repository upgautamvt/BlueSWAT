# Lines added by author
#include "fsm_lib_hdr.h"
extern void ll_rx_put(memq_link_t *link, void *rx);
/**
 * @brief Permit another loop in the controller thread (prio_recv_thread)
 * @details Execution context: ULL mayfly
 */
extern void ll_rx_sched(void);
static void ll_rx_put_sched(memq_link_t *link, void *rx)
{
	ll_rx_put(link, rx);
	ll_rx_sched();
}
