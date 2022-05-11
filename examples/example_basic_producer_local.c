#include "lwevt/lwevt.h"

void
produce() {
    lwevt_t* evt_global;
    lwevt_t evt_local;

    /*
     * Send event using global handle
     * Thread safety has to be ensured in multi-threading environments
     */
    evt_global = lwevt_get_handle();
    evt_global->msg.ext1.par1 = 10; /* Some value */
    evt_global->msg.ext1.par2 = 12; /* Some value */
    lwevt_dispatch(LWEVT_TYPE_MY_EXT_1);

    /*
     * Send event usin local handle
     * No need to ensure thread safety
     */
    evt_local.msg.ext1.par1 = 10;   /* Some value */
    evt_local.msg.ext1.par2 = 12;   /* Some value */
    lwevt_dispatch(LWEVT_TYPE_MY_EXT_1);
    return 0;
}
