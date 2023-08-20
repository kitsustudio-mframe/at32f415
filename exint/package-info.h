/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Define
 */
#ifdef USING_CHIP
#ifndef USING_CHIP_USART
#define USING_CHIP_USART
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_EXINT
#include "Config.h"
#include "EXINT.h"
#include "Line.h"
#include "Mode.h"
#include "Polarity.h"
#include "Register.h"
#undef USING_CHIP_EXINT
#endif
/* ****************************************************************************************
 * End of file
 */
