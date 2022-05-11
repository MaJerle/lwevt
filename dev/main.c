/*
 * main.c : Defines the entry point for the console application.
 */

#include <stdio.h>
#include <string.h>
#include "lwevt/lwevt.h"

/* Define event functions */
static void
prv_evt_fn_1(lwevt_t* e) {
    printf("Event fn 1. Event type: %u\r\n", (unsigned)e->type);
}

/* Second event function */
static void
prv_evt_fn_2(lwevt_t* e) {
    printf("Event fn 2. Event type: %u\r\n", (unsigned)e->type);
}

int
main() {
    lwevt_t* evt;
    lwevt_t evt_local;

    /* Initialize event management system */
    lwevt_init();

    /* Set 2 custom functions for event */
    lwevt_register(prv_evt_fn_1);
    lwevt_register(prv_evt_fn_2);
    
    /*
     * Get event handle
     *
     * Set event data
     * 
     * Dispatch event - with defined type
     */
    evt = lwevt_get_handle();
    evt->msg.a.a = 5;
    lwevt_dispatch(LWEVT_TYPE_MY_EXT_1);

    /* Send local event */
    evt_local.msg.a.a = 5;
    lwevt_dispatch_ex(&evt_local, LWEVT_TYPE_MY_EXT_1);
    return 0;
}
