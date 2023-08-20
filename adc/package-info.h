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
#ifndef USING_CHIP_ADC
#define USING_CHIP_ADC
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_ADC
#include "./ADC.h"
#include "./Channel.h"
#include "./Config.h"
#include "./DataAlign.h"
#include "./Flag.h"
#include "./Interrupt.h"
#include "./OrdinaryTrig.h"
#include "./PreemptChannel.h"
#include "./PreemptTrig.h"
#include "./Register.h"
#include "./SampleTime.h"
#include "./VoltageMonitoring.h"
#undef USING_CHIP_ADC
#endif
/* ****************************************************************************************
 * End of file
 */
