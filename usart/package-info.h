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
#ifndef USING_CHIP_USART
#define USING_CHIP_USART
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_USART
#include "BreakBit.h"
#include "ClockLast.h"
#include "ClockPhase.h"
#include "ClockPolarity.h"
#include "DataBit.h"
#include "Flag.h"
#include "HardwareFlow.h"
#include "Interrupt.h"
#include "ParitySelection.h"
#include "Register.h"
#include "StopBit.h"
#include "USART.h"
#include "WakeupMode.h"
#undef USING_CHIP_USART
#endif
/* ****************************************************************************************
 * End of file
 */
