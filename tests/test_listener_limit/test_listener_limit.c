#include <stdint.h>
#include <stdio.h>
#include "lwevt/lwevt.h"
#include "test.h"

static uint32_t call_cnt;

static void
prv_evt_fn_a(lwevt_t* e) {
    (void)e;
    ++call_cnt;
}

static void
prv_evt_fn_b(lwevt_t* e) {
    (void)e;
    ++call_cnt;
}

static void
prv_evt_fn_c(lwevt_t* e) {
    (void)e;
    ++call_cnt;
}

static void
prv_evt_fn_d(lwevt_t* e) {
    (void)e;
    ++call_cnt;
}

int
test_run(void) {
    lwevt_init();

    /* Listener capacity is configured to 3 for this test (LWEVT_CFG_MAX_EVT_LISTENERS) */
    TEST_ASSERT(lwevt_register(prv_evt_fn_a) == 1);

    /* Re-registering an already-registered function must be rejected and must not consume a slot */
    TEST_ASSERT(lwevt_register(prv_evt_fn_a) == 0);

    /* Add 2 more */
    TEST_ASSERT(lwevt_register(prv_evt_fn_b) == 1);
    TEST_ASSERT(lwevt_register(prv_evt_fn_c) == 1);

    /* 4th distinct listener must be rejected - capacity is full */
    TEST_ASSERT(lwevt_register(prv_evt_fn_d) == 0);

    /* Duplicate rejection must also hold once the list is full */
    TEST_ASSERT(lwevt_register(prv_evt_fn_a) == 0);

    /* Only the 3 distinct listeners must be invoked, each exactly once */
    TEST_ASSERT(lwevt_dispatch(TEST_EVT_BASIC_1) == 1);
    TEST_ASSERT(call_cnt == 3);

    printf("All listener-limit tests passed\r\n");
    return 0;
}
