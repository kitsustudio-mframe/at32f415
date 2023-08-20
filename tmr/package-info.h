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
#ifndef USING_CHIP_TMR
#define USING_CHIP_TMR
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */
#include "channel/package-info.h"
#include "dma/package-info.h"
#include "external/package-info.h"
#include "input/package-info.h"
#include "output/package-info.h"
#include "subordinate/package-info.h"

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR
#include "BreakDutyConfig.h"
#include "BreakPolarity.h"
#include "ClockDivision.h"
#include "CountMode.h"
#include "EncoderMode.h"
#include "EventTrigger.h"
#include "Flag.h"
#include "Interrupt.h"
#include "PolarityActive.h"
#include "PrimarySelect.h"
#include "Register.h"
#include "TMR.h"
#include "WriteProtectLevel.h"
#undef USING_CHIP_TMR
#endif

/* ****************************************************************************************
 * End of file
 */
