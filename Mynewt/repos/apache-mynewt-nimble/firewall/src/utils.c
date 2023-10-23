#include "utils.h"
#include <stdint.h>

static uint32_t ticks_per_us = 1000;

#define DEV_NRF52840
#ifdef DEV_NRF52840
#define SYSCoreClock 64000000 // 64mhz

#define COREDEBUG_DEMCR  (volatile uint32_t *) (0xE000EDFC)
#define DWT_CTRL (volatile uint32_t *) (0xE0001000) // page e156
#define DWT_CYCCNT (volatile uint32_t *) (0xE0001004) // page e156
#define MSK_DEMCR_TRCENA (1 << 24) // page 464
#define MSK_DWT_CYCCNTENA (1 << 0) // page e159

static inline void dwt_init(void) {
	ticks_per_us = SYSCoreClock / 1000000;
	*COREDEBUG_DEMCR |= MSK_DEMCR_TRCENA;
	*DWT_CYCCNT = 0;
	*DWT_CTRL |= MSK_DWT_CYCCNTENA;
}

static inline void dwt_deinit(void) {
	*DWT_CTRL &= ~MSK_DWT_CYCCNTENA;
	*DWT_CYCCNT = 0;
	*COREDEBUG_DEMCR &= ~MSK_DEMCR_TRCENA;
}

static inline uint32_t dwt_get_counter(void) {
	return *DWT_CYCCNT;
}

#else

static inline void dwt_init() {
}

static inline void dwt_deinit() {
}

static inline uint32_t dwt_get_counter() {
	return 0;
}

#endif

void reset_timer_tick(void) {
	dwt_init();
}

int get_cur_tick(void) {
	return dwt_get_counter();
}

float tick_to_us(int tick) {
	return tick / (float) ticks_per_us;
}