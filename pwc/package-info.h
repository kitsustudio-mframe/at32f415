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
#ifndef USING_CHIP_PWC
#define USING_CHIP_PWC
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_PWC
#include "DeepSleepEnter.h"
#include "Flag.h"
#include "PWC.h"
#include "PvmVoltage.h"
#include "Register.h"
#include "Regulator.h"
#include "SleepEnter.h"
#undef USING_CHIP_PWC
#endif

/* ****************************************************************************************
 * End of file
 */
