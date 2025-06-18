# Lines added by author
STAILQ_HEAD(, os_mbuf_pool) g_msys_pool_list =

int
os_mqueue_init(struct os_mqueue *mq, ble_npl_event_fn *ev_cb, void *arg)
    if (mp) {
    if (mp) {
    } else {
int
os_mqueue_put(struct os_mqueue *mq, struct ble_npl_eventq *evq, struct os_mbuf *m)
    if (!OS_MBUF_IS_PKTHDR(m)) {
    if (evq) {
int
os_msys_register(struct os_mbuf_pool *new_pool)
    STAILQ_FOREACH(pool, &g_msys_pool_list, omp_next) {
        if (new_pool->omp_databuf_len > pool->omp_databuf_len) {
    if (pool) {
    } else {
void
os_msys_reset(void)
    STAILQ_FOREACH(pool, &g_msys_pool_list, omp_next) {
        if (dsize <= pool->omp_databuf_len) {
    if (!pool) {

    if (!pool) {
    total_pkthdr_len =  user_hdr_len + sizeof(struct os_mbuf_pkthdr);
    if (!pool) {
int
os_msys_count(void)
    STAILQ_FOREACH(omp, &g_msys_pool_list, omp_next) {
int
os_msys_num_free(void)
    STAILQ_FOREACH(omp, &g_msys_pool_list, omp_next) {

int
os_mbuf_pool_init(struct os_mbuf_pool *omp, struct os_mempool *mp,
                  uint16_t buf_len, uint16_t nbufs)
    if (leadingspace > omp->omp_databuf_len) {
    if (!om) {
    if ((pkthdr_len > omp->omp_databuf_len) || (pkthdr_len > 255)) {
    if (om) {
int
os_mbuf_free(struct os_mbuf *om)
    if (om->om_omp != NULL) {
        if (rc != 0) {
int
os_mbuf_free_chain(struct os_mbuf *om)
    while (om != NULL) {
        if (rc != 0) {
    while (om != NULL) {
int
os_mbuf_append(struct os_mbuf *om, const void *data,  uint16_t len)
    if (om == NULL) {
    while (SLIST_NEXT(last, om_next) != NULL) {
    if (space > 0) {
        if (space > remainder) {
        memcpy(OS_MBUF_DATA(last, uint8_t *) + last->om_len , data, space);
    while (remainder > 0) {
        if (!new) {
    if (OS_MBUF_IS_PKTHDR(om)) {
    if (remainder != 0) {

int
os_mbuf_appendfrom(struct os_mbuf *dst, const struct os_mbuf *src,
                   uint16_t src_off, uint16_t len)
    while (len > 0) {
        if (src_cur_om == NULL) {
        if (rc != 0) {
    for (; om != NULL; om = SLIST_NEXT(om, om_next)) {
        if (head) {
                    OS_MBUF_LEADINGSPACE(om));
            if (!SLIST_NEXT(copy, om_next)) {
        } else {
            if (!head) {
            if (OS_MBUF_IS_PKTHDR(om)) {
                om->om_len);
    while (1) {
        if (cur == NULL) {
            (cur->om_len == off && next == NULL)) {
int
os_mbuf_copydata(const struct os_mbuf *m, int off, int len, void *dst)
    if (!len) {
    while (off > 0) {
        if (!m) {
    while (len > 0 && m != NULL) {
void
os_mbuf_adj(struct os_mbuf *mp, int req_len)
    if (len >= 0) {
        while (m != NULL && len > 0) {
            if (m->om_len <= len) {
            } else {
    } else {
        for (;;) {
        if (m->om_len >= len) {
        for (; m; m = SLIST_NEXT(m, om_next)) {
            if (m->om_len >= count) {
                if (SLIST_NEXT(m, om_next) != NULL) {
int
os_mbuf_cmpf(const struct os_mbuf *om, int off, const void *data, int len)
    if (len <= 0) {
    while (1) {
        if (om == NULL) {
        if (chunk_sz > 0) {
            if (rc != 0) {
        if (data_off == len) {
        if (om == NULL) {
int
os_mbuf_cmpm(const struct os_mbuf *om1, uint16_t offset1,
             const struct os_mbuf *om2, uint16_t offset2,
             uint16_t len)
    while (1) {
        if (bytes_remaining == 0) {
        while (cur1 != NULL && om1_off >= cur1->om_len) {
        while (cur2 != NULL && om2_off >= cur2->om_len) {
        if (cur1 == NULL || cur2 == NULL) {
        if (rc != 0) {
    while (1) {
        if (OS_MBUF_IS_PKTHDR(om)) {
        if (len == 0) {
        if (OS_MBUF_IS_PKTHDR(om)) {
                om->om_pkthdr_len - sizeof (struct os_mbuf_pkthdr));
        } else {
        if (p == NULL) {
        if (OS_MBUF_IS_PKTHDR(om)) {
    if (om == NULL) {
    if (om == NULL) {
int
os_mbuf_copyinto(struct os_mbuf *om, int off, const void *src, int len)
    if (cur == NULL) {
    while (1) {
        if (copylen > 0) {
        if (len == 0) {
        if (next == NULL) {
    if (rc != 0) {
    if (OS_MBUF_IS_PKTHDR(om)) {
void
os_mbuf_concat(struct os_mbuf *first, struct os_mbuf *second)
    while (1) {
        if (next == NULL) {
    if (OS_MBUF_IS_PKTHDR(first)) {
        if (OS_MBUF_IS_PKTHDR(second)) {
        } else {
            for (cur = second; cur != NULL; cur = SLIST_NEXT(cur, om_next)) {
    if (len > om->om_omp->omp_databuf_len) {
    while (SLIST_NEXT(last, om_next) != NULL) {
    if (OS_MBUF_TRAILINGSPACE(last) < len) {
        if (newm == NULL) {
    if (OS_MBUF_IS_PKTHDR(om)) {

    if (om->om_len >= len) {
        SLIST_NEXT(om, om_next)) {
    } else {
        if (len > omp->omp_databuf_len - om->om_pkthdr_len) {
        if (om2 == NULL) {
        if (OS_MBUF_IS_PKTHDR(om)) {
    do {
        if (om->om_len) {
        } else {
    if (len > 0) {
    if (om->om_len != 0) {
    while (cur != NULL && cur->om_len == 0) {
    if (cur == NULL) {
    if (OS_MBUF_LEADINGSPACE(cur) >= om->om_pkthdr_len) {
int
os_mbuf_widen(struct os_mbuf *om, uint16_t off, uint16_t len)
    if (edge_om == NULL) {
    if (OS_MBUF_TRAILINGSPACE(edge_om) >= len) {
        if (OS_MBUF_IS_PKTHDR(om)) {
    while (rem_len > 0) {
        if (cur == NULL) {
        if (first_new == NULL) {
        if (rem_len > OS_MBUF_TRAILINGSPACE(cur)) {
        } else {
        if (prev != NULL) {
    if (rc != 0) {
    if (OS_MBUF_IS_PKTHDR(om)) {
    if (m1 == NULL) {
    if (m2 != NULL) {
    while (1) {
        if (OS_MBUF_LEADINGSPACE(cur)) {
            if (OS_MBUF_IS_PKTHDR(cur)) {
        while (rem_len && next) {
            while (next->om_len == 0) {
                if (next == NULL) {
        if (next == NULL) {
