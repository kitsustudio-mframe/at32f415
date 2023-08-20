/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

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
#undef USING_PROCESSOR_CORE
#endif

#ifdef USING_PROCESSOR_INTERRUPT
#include "./ProcessorInterrupt.h"
#undef USING_PROCESSOR_INTERRUPT
#endif

/* ****************************************************************************************
 * End of file
 */
