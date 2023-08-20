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
#ifndef USING_CHIP_TMR_SUBORDINATE
#define USING_CHIP_TMR_SUBORDINATE
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR_SUBORDINATE
#include "InputSelect.h"
#include "ModeSelect.h"
#undef USING_CHIP_TMR_SUBORDINATE
#endif

/* ****************************************************************************************
 * End of file
 */
