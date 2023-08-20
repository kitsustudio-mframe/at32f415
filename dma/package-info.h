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
#ifndef USING_CHIP_DMA
#define USING_CHIP_DMA
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_DMA
#include "./Channel.h"
#include "./ChannelRegister.h"
#include "./Config.h"
#include "./DMA.h"
#include "./Direction.h"
#include "./Flag.h"
#include "./Flexible.h"
#include "./Interrupt.h"
#include "./MemoryDataSize.h"
#include "./MemoryInc.h"
#include "./PeripheralDataSize.h"
#include "./PeripheralInc.h"
#include "./PriorityLevel.h"
#include "./Register.h"
#undef USING_CHIP_DMA
#endif

/* ****************************************************************************************
 * End of file
 */
