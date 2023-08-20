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
#ifndef USING_CHIP_CRM
#define USING_CHIP_CRM
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_CRM
#include "./AutoStepMode.h"
#include "./CRM.h"
#include "./ClockOutSelect.h"
#include "./CoreClock.h"
#include "./DividerADC.h"
#include "./DividerAHB.h"
#include "./DividerAPB1.h"
#include "./DividerAPB2.h"
#include "./DividerClockOut.h"
#include "./DividerHICK.h"
#include "./DividerUSB.h"
#include "./Flag.h"
#include "./HickFrequencySCLK.h"
#include "./Interrupt.h"
#include "./MultPLL.h"
#include "./PeriphClock.h"
#include "./PeriphClockSleepMode.h"
#include "./PeriphReset.h"
#include "./PostDividerPLL.h"
#include "./ReferenceClockPLL.h"
#include "./Register.h"
#include "./SourceClockCore.h"
#include "./SourceClockERTC.h"
#include "./SourceClockPLL.h"
#include "./SourceClockSCLK.h"
#include "./SourceClockUSB.h"
#undef USING_CHIP_CRM
#endif

/* ****************************************************************************************
 * End of file
 */
