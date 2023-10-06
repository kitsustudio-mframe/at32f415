/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Define
 */

/* ****************************************************************************************
 * Include folder
 */
#include "adc/package-info.h"
#include "crm/package-info.h"
#include "dma/package-info.h"
#include "exint/package-info.h"
#include "flash/package-info.h"
#include "gpio/package-info.h"
#include "misc/package-info.h"
#include "pwc/package-info.h"
#include "tmr/package-info.h"
#include "usart/package-info.h"

/* ****************************************************************************************
 * Include
 */

#include "Processor.h"

#ifdef using_chip_ProcessorCore
#undef using_chip_ProcessorCore
#include "ProcessorCore.h"
#endif

#ifdef using_chip_ProcessorInterrupt
#undef using_chip_ProcessorInterrupt
#include "ProcessorInterrupt.h"
#endif

/* ****************************************************************************************
 * End of file
 */
