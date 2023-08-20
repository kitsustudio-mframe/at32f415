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
#ifndef USING_CHIP_TMR_CHANNEL
#define USING_CHIP_TMR_CHANNEL
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR_CHANNEL
#include "InputConnected.h"
#include "Select.h"
#undef USING_CHIP_TMR_CHANNEL
#endif

/* ****************************************************************************************
 * End of file
 */
