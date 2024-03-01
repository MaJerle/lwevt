/**
 * \file            lwevt_type.h
 * \brief           LwEVT types main file
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

/**
 * \ingroup         LWEVT
 * \brief           Defines basic event type with respective name, only
 * 
 * Basic events do not have possibility to send data to application
 * 
 * `#define LWEVT_TYPE_BASIC(MY_EVENT_NAME)`
 */
#ifndef LWEVT_TYPE_BASIC
#define LWEVT_TYPE_BASIC(name)
#endif

/**
 * \ingroup         LWEVT
 * \brief           Defines extended event type with possibily to send data
 * 
 * Data C-type has to be declared for proper use case
 * 
 * `#define LWEVT_TYPE_EXT(MY_EVENT_NAME, struct {int par1; int par2;} my_event_name;)`
 */
#ifndef LWEVT_TYPE_EXT
#define LWEVT_TYPE_EXT(name, data)
#endif

/* Include user types */
#include "lwevt_types.h"

/* Undefine type back - after use */
#undef LWEVT_TYPE_BASIC
#undef LWEVT_TYPE_EXT
