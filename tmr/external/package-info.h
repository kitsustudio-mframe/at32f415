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
#ifndef USING_CHIP_TMR_EXTERNAL
#define USING_CHIP_TMR_EXTERNAL
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR_EXTERNAL
#include "Divider.h"
#include "Polarity.h"
#undef USING_CHIP_TMR_EXTERNAL
#endif

/* ****************************************************************************************
 * End of file
 */
