/**
 * \file            lwevt.h
 * \brief           Lightweight event system
 */

/*
 * Copyright (c) 2023 Tilen MAJERLE
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
 * Version:         v0.1.0
 */
#ifndef LWEVT_HDR_H
#define LWEVT_HDR_H

#include <stdint.h>
#include <string.h>
#include "lwevt/lwevt_opt.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \defgroup        LWEVT Lightweight event system
 * \brief           Lightweight event system
 * \{
 */

/**
 * \brief           Event type
 */
typedef enum {

#define LWEVT_TYPE_BASIC(name)     name,
#define LWEVT_TYPE_EXT(name, data) name,
#include "lwevt/lwevt_type.h"
    LWEVT_TYPE_LAST /*!< Last element on the list */
} lwevt_type_t;

/**
 * \brief           Main event structure
 */
typedef struct {
    lwevt_type_t type; /*!< Event type */

    union {
#define LWEVT_TYPE_EXT(name, data) data;
#include "lwevt/lwevt_type.h"
        const unsigned int dummy; /*!< Dummy element if no others are used by user */
    } msg;                        /*!< Message union for extended event types */
} lwevt_t;

/**
 * \brief           Event callback function prototype
 */
typedef void (*lwevt_fn)(lwevt_t* evt);

void lwevt_init(void);
uint8_t lwevt_register(lwevt_fn evt_fn);
lwevt_t* lwevt_get_handle(void);
uint8_t lwevt_dispatch(lwevt_type_t type);
uint8_t lwevt_dispatch_ex(lwevt_t* e, lwevt_type_t type);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWEVT_HDR_H */
