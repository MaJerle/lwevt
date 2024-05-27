/**
 * \file            lwevt.c
 * \brief           Lightweight event system
 */

/*
 * Copyright (c) 2024 Tilen MAJERLE
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of LwEVT - Lightweight event manager.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 * Version:         v1.0.0
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "lwevt/lwevt.h"

#if LWEVT_CFG_ENABLE_DEFAULT_HANDLE
static lwevt_t evt;
#endif /* LWEVT_CFG_ENABLE_DEFAULT_HANDLE */
static lwevt_fn evt_fncs[LWEVT_CFG_MAX_EVT_LISTENERS];
static uint32_t evt_fncs_cnt;

/**
 * \brief           Initialize LwEVT module
 */
void
lwevt_init(void) {
#if LWEVT_CFG_ENABLE_DEFAULT_HANDLE
    LWEVT_MEMSET(&evt, 0x00, sizeof(evt));
#endif /* LWEVT_CFG_ENABLE_DEFAULT_HANDLE */
    evt_fncs_cnt = 0;
}

/**
 * \brief           Register new event listener callback to event manager
 * \param           evt_fn: Function to add to list of listeners
 * \return          `1` if added, `0` otherwise
 */
uint8_t
lwevt_register(lwevt_fn evt_fn) {
    /* Add new function to the event system */
    if (evt_fncs_cnt < (sizeof(evt_fncs) / sizeof(evt_fncs[0]))) {
        evt_fncs[evt_fncs_cnt++] = evt_fn;
        return 1;
    }
    return 0;
}

/**
 * \brief           Dispatch event to all registered functions
 *                  using custom event handle object
 * \param           evt_handle: Event handle used as parameter to listeners
 * \param           type: Event type to dispatch
 * \return          `1` if dispatched, `0` otherwise
 */
uint8_t
lwevt_dispatch_ex(lwevt_t* evt_handle, lwevt_type_t type) {
    evt_handle->type = type;

    /* Send event to all registered functions */
    for (size_t idx = 0; idx < evt_fncs_cnt; ++idx) {
        evt_fncs[idx](evt_handle);
    }
    return 1;
}

#if LWEVT_CFG_ENABLE_DEFAULT_HANDLE || __DOXYGEN__

/**
 * \brief           Get default handle object for dispatch purpose
 * \note            Available only when \ref LWEVT_CFG_ENABLE_DEFAULT_HANDLE is enabled
 * \return          Pointer to default event handle
 */
lwevt_t*
lwevt_get_handle(void) {
    return &evt;
}

/**
 * \brief           Dispatch event to all registered functions
 * \note            It uses default event handle as parameter
 * \note            Available only when \ref LWEVT_CFG_ENABLE_DEFAULT_HANDLE is enabled
 * \param[in]       type: Event type to dispatch
 * \return          `1` if dispatched, `0` otherwise
 */
uint8_t
lwevt_dispatch(lwevt_type_t type) {
    return lwevt_dispatch_ex(&evt, type);
}

#endif /* LWEVT_CFG_ENABLE_DEFAULT_HANDLE || __DOXYGEN__ */
