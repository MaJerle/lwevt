#include "lwevt/lwevt.h"

/* Define event functions */
static void
prv_evt_fn(lwevt_t* e) {
    printf("Event type: %u\r\n", (unsigned)e->type);
    switch (e->type) {
        case LWEVT_TYPE_MY_BASIC_1: {
            printf("Basic event type - no data\r\n");
            break;
        }
        case LWEVT_TYPE_MY_EXT_1: {
            printf("Extended event type - with data: par1: %d, par2: %d\r\n",
                (int)e->msg.ext1.par1, (int)e->msg.ext1.par2);
            break;
        }
        default:
            break;
    }
}

int
main() {
    lwevt_t* evt;

    /* Initialize event management system = must be called only once in the application  */
    lwevt_init();

    /* Set 2 custom functions for event */
    lwevt_register(prv_evt_fn);

    /* Do nothing - events are handled in callback function */

    return 0;
}
