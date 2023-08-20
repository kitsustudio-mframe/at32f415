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
#ifndef USING_CHIP_MISC
#define USING_CHIP_MISC
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_MISC
#include "InterruptService.h"
#include "LowPowerMode.h"
#include "MISC.h"
#include "PriorityGroup.h"
#include "SystickClockSource.h"
#undef USING_CHIP_MISC
#endif

/* ****************************************************************************************
 * End of file
 */
