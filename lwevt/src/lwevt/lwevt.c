/**
 * \file            lwevt.c
 * \brief           Lightweight event system
 */

/*
 * Copyright (c) 2022 Tilen MAJERLE
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
 * This file is part of LwEVT - Lightweight event system library.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 * Version:         $_version_$
 */
#include <string.h>
#include "lwevt/lwevt.h"

static lwevt_t evt;
static lwevt_fn evt_fncs[LWEVT_CFG_MAX_EVT_LISTENERS];
static uint32_t evt_fncs_cnt;

/**
 * \brief           Initialize LwEVT module
 */
void
lwevt_init(void) {
    memset(&evt, 0x00, sizeof(evt));
    evt_fncs_cnt = 0;
}

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
 * \param[in]       type: Event type to dispatch
 * \return          `1` if dispatched, `0` otherwise
 */
uint8_t
lwevt_dispatch(lwevt_type_t type) {
    evt.type = type;

    /* Send event to all registered functions */
    for (size_t i = 0; i < evt_fncs_cnt; ++i) {
        evt_fncs[i](&evt);
    }
    return 1;
}

lwevt_t*
lwevt_get_handle(void) {
    return &evt;
}
