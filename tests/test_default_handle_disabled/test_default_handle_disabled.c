#include <stdint.h>
#include <stdio.h>
#include "lwevt/lwevt.h"
#include "test.h"

static uint32_t call_cnt;
static int last_par1;

static void
prv_evt_fn(lwevt_t* e) {
    ++call_cnt;
    if (e->type == TEST_EVT_EXT_1) {
        last_par1 = e->msg.ext1.par1;
    }
}

int
test_run(void) {
    lwevt_t evt_local = {0};

    lwevt_init();
    TEST_ASSERT(lwevt_register(prv_evt_fn) == 1);

    /*
     * With LWEVT_CFG_ENABLE_DEFAULT_HANDLE == 0, lwevt_get_handle() and lwevt_dispatch()
     * are compiled out - this test only exercises the explicit-handle API and,
     * by compiling successfully, proves the library builds fine in this configuration.
     */
    evt_local.msg.ext1.par1 = 7;
    TEST_ASSERT(lwevt_dispatch_ex(&evt_local, TEST_EVT_EXT_1) == 1);
    TEST_ASSERT(call_cnt == 1);
    TEST_ASSERT(last_par1 == 7);
    TEST_ASSERT(evt_local.type == TEST_EVT_EXT_1);

    printf("All default-handle-disabled tests passed\r\n");
    return 0;
}
