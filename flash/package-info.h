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
#ifndef USING_CHIP_FLASH
#define USING_CHIP_FLASH
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */
#include "usd/package-info.h"

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_FLASH
#include "./FLASH.h"
#include "./Flag.h"
#include "./Interrupt.h"
#include "./Register.h"
#include "./Status.h"
#include "./Timeout.h"
#include "./WaitCycle.h"
#undef USING_CHIP_FLASH
#endif

/* ****************************************************************************************
 * End of file
 */
