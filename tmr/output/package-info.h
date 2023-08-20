/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Define
 */
#ifdef USING_CHIP_TMR
#ifndef USING_CHIP_TMR_OUTPUT
#define USING_CHIP_TMR_OUTPUT
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR_OUTPUT
#include "Config.h"
#include "ControlMode.h"
#include "Force.h"
#include "Polarity.h"
#undef USING_CHIP_TMR_OUTPUT
#endif

/* ****************************************************************************************
 * End of file
 */
