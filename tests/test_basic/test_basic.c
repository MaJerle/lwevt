#include <stdint.h>
#include <stdio.h>
#include "lwevt/lwevt.h"
#include "test.h"

static uint32_t fn1_call_cnt, fn2_call_cnt;
static lwevt_type_t fn1_last_type, fn2_last_type;
static int ext1_par1, ext1_par2;

static void
prv_evt_fn1(lwevt_t* e) {
    ++fn1_call_cnt;
    fn1_last_type = e->type;
    if (e->type == TEST_EVT_EXT_1) {
        ext1_par1 = e->msg.ext1.par1;
        ext1_par2 = e->msg.ext1.par2;
    }
}

static void
prv_evt_fn2(lwevt_t* e) {
    ++fn2_call_cnt;
    fn2_last_type = e->type;
}

int
test_run(void) {
    lwevt_t* evt;
    lwevt_t evt_local = {0};

    /* Init must reset internal state, even before anything else was registered */
    lwevt_init();

    /* No listeners registered yet - dispatch must not crash and must call nobody */
    TEST_ASSERT(lwevt_dispatch(TEST_EVT_BASIC_1) == 1);
    TEST_ASSERT(fn1_call_cnt == 0);
    TEST_ASSERT(fn2_call_cnt == 0);

    /* Register 2 listeners */
    TEST_ASSERT(lwevt_register(prv_evt_fn1) == 1);
    TEST_ASSERT(lwevt_register(prv_evt_fn2) == 1);

    /* Dispatch basic event through default handle - both listeners must fire once */
    evt = lwevt_get_handle();
    TEST_ASSERT(evt != NULL);
    TEST_ASSERT(lwevt_dispatch(TEST_EVT_BASIC_1) == 1);
    TEST_ASSERT(fn1_call_cnt == 1);
    TEST_ASSERT(fn2_call_cnt == 1);
    TEST_ASSERT(fn1_last_type == TEST_EVT_BASIC_1);
    TEST_ASSERT(fn2_last_type == TEST_EVT_BASIC_1);

    /* Dispatch extended event with data - data set before dispatch must reach listener */
    evt = lwevt_get_handle();
    evt->msg.ext1.par1 = 11;
    evt->msg.ext1.par2 = 22;
    TEST_ASSERT(lwevt_dispatch(TEST_EVT_EXT_1) == 1);
    TEST_ASSERT(fn1_call_cnt == 2);
    TEST_ASSERT(fn2_call_cnt == 2);
    TEST_ASSERT(ext1_par1 == 11);
    TEST_ASSERT(ext1_par2 == 22);

    /* Dispatch through a local, user-provided handle instead of the default one */
    evt_local.msg.ext1.par1 = 33;
    evt_local.msg.ext1.par2 = 44;
    TEST_ASSERT(lwevt_dispatch_ex(&evt_local, TEST_EVT_EXT_1) == 1);
    TEST_ASSERT(fn1_call_cnt == 3);
    TEST_ASSERT(fn2_call_cnt == 3);
    TEST_ASSERT(ext1_par1 == 33);
    TEST_ASSERT(ext1_par2 == 44);
    TEST_ASSERT(evt_local.type == TEST_EVT_EXT_1);

    /* Re-init must drop previously registered listeners */
    lwevt_init();
    TEST_ASSERT(lwevt_dispatch(TEST_EVT_BASIC_2) == 1);
    TEST_ASSERT(fn1_call_cnt == 3); /* Unchanged - listeners are gone after re-init */
    TEST_ASSERT(fn2_call_cnt == 3);

    /* NULL handle passed to dispatch_ex must be rejected, not dereferenced */
    TEST_ASSERT(lwevt_dispatch_ex(NULL, TEST_EVT_BASIC_1) == 0);

    /* Registering the same function twice must not duplicate it in the listener list */
    lwevt_init();
    fn1_call_cnt = 0;
    TEST_ASSERT(lwevt_register(prv_evt_fn1) == 1);
    TEST_ASSERT(lwevt_register(prv_evt_fn1) == 0);
    TEST_ASSERT(lwevt_dispatch(TEST_EVT_BASIC_1) == 1);
    TEST_ASSERT(fn1_call_cnt == 1); /* Called once, not twice */

    /* Registering a NULL function must be rejected */
    TEST_ASSERT(lwevt_register(NULL) == 0);

    printf("All basic tests passed\r\n");
    return 0;
}
