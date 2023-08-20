/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_5EEBC672_C525_4154_B02C_876E00D786B8
#define CHIP_5EEBC672_C525_4154_B02C_876E00D786B8

/* ****************************************************************************************
 * Include folder
 */
#include "./adc/package-info.h"
#include "./crm/package-info.h"
#include "./dma/package-info.h"
#include "./exint/package-info.h"
#include "./flash/package-info.h"
#include "./gpio/package-info.h"
#include "./misc/package-info.h"
#include "./pwc/package-info.h"
#include "./tmr/package-info.h"
#include "./usart/package-info.h"

/* ****************************************************************************************
 * Include
 */
#include "./Processor.h"

#ifdef USING_PROCESSOR_CORE
#include "./ProcessorCore.h"
#endif

#ifdef USING_PROCESSOR_INTERRUPT
#include "./ProcessorInterrupt.h"
#endif

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_5EEBC672_C525_4154_B02C_876E00D786B8 */
