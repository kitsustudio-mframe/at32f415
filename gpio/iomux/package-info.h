/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Define
 */
#ifdef USING_CHIP_GPIO
#ifndef USING_CHIP_GPIO_IOMUX
#define USING_CHIP_GPIO_IOMUX
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_GPIO_IOMUX
#include "./IOMUX.h"
#include "./PinMap.h"
#include "./Register.h"
#undef USING_CHIP_GPIO_IOMUX
#endif

/* ****************************************************************************************
 * End of file
 */
