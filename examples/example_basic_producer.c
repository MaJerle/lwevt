#include "lwevt/lwevt.h"

void
produce() {
    lwevt_t* evt;

    /* Initialize event management system = must be called only once in the application */
    lwevt_init();
    
    /*
     * Get event handle, set event data and dispatch event
     *
     * Send basic event - without any data
     */
    evt = lwevt_get_handle();
    lwevt_dispatch(LWEVT_TYPE_MY_BASIC_1);

    /*
     * Get event handle, set event data and dispatch event
     *
     * Send extended event - with data
     */
    evt = lwevt_get_handle();
    evt->msg.ext1.par1 = 10;    /* Some value */
    evt->msg.ext1.par2 = 12;    /* Some value */
    lwevt_dispatch(LWEVT_TYPE_MY_EXT_1);
    return 0;
}
