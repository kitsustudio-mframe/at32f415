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
#ifndef USING_CHIP_TMR_INPUT
#define USING_CHIP_TMR_INPUT
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR_INPUT
#include "Config.h"
#include "DirectionMapped.h"
#include "Divider.h"
#include "Polarity.h"
#undef USING_CHIP_TMR_INPUT
#endif

/* ****************************************************************************************
 * End of file
 */
