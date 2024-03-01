/**
 * \file            lwevt_opt.h
 * \brief           LwEVT options
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
#ifndef LWEVT_OPT_HDR_H
#define LWEVT_OPT_HDR_H

/* Uncomment to ignore user options (or set macro in compiler flags) */
/* #define LWEVT_IGNORE_USER_OPTS */

/* Include application options */
#ifndef LWEVT_IGNORE_USER_OPTS
#include "lwevt_opts.h"
#endif /* LWEVT_IGNORE_USER_OPTS */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \defgroup        LWEVT_OPT Configuration
 * \brief           Default configuration setup
 * \{
 */

/**
 * \brief           Memory set function
 * 
 * \note            Function footprint is the same as \ref memset
 */
#ifndef LWEVT_MEMSET
#define LWEVT_MEMSET(dst, val, len) memset((dst), (val), (len))
#endif

/**
 * \brief           Maximum number of event listeners that can receive info on event dispatch
 * 
 * It defines size of array for function pointers
 */
#ifndef LWEVT_CFG_MAX_EVT_LISTENERS
#define LWEVT_CFG_MAX_EVT_LISTENERS 8
#endif

/**
 * \brief           Enables `1` or disables `0` creation of default event handle
 * 
 * When enabled, user can use \ref lwevt_get_handle and \ref lwevt_dispatch functions
 * to operate on defualt handle.
 * 
 * When disabled, user must create event handle before every dispatch,
 * and is only able to use \ref lwevt_dispatch_ex function
 */
#ifndef LWEVT_CFG_ENABLE_DEFAULT_HANDLE
#define LWEVT_CFG_ENABLE_DEFAULT_HANDLE 1
#endif

/**
 * \}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWEVT_OPT_HDR_H */
