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
#ifndef USING_CHIP_TMR_DMA
#define USING_CHIP_TMR_DMA
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_TMR_DMA
#include "BaseAddress.h"
#include "Request.h"
#include "RequestSource.h"
#include "TransferLength.h"
#undef USING_CHIP_TMR_DMA
#endif

/* ****************************************************************************************
 * End of file
 */
