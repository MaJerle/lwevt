/**
 * \file            lwevt_opts.h
 * \brief           LwEVT configuration file for test_default_handle_disabled
 */
#ifndef LWEVT_HDR_OPTS_H
#define LWEVT_HDR_OPTS_H

/* Disable default handle - only lwevt_dispatch_ex must be available in this test */
#define LWEVT_CFG_ENABLE_DEFAULT_HANDLE 0

#endif /* LWEVT_HDR_OPTS_H */
