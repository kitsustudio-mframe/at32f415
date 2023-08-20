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
#ifndef USING_CHIP_GPIO
#define USING_CHIP_GPIO
#endif
#endif

/* ****************************************************************************************
 * Include folder
 */
#include "./iomux/package-info.h"

/* ****************************************************************************************
 * Include
 */
#ifdef USING_CHIP_GPIO
#include "./DriveMode.h"
#include "./GPIO.h"
#include "./Mode.h"
#include "./OutputMode.h"
#include "./PinConfig.h"
#include "./Pins.h"
#include "./PinsSource.h"
#include "./PortSource.h"
#include "./PullMode.h"
#include "./Register.h"
#undef USING_CHIP_GPIO
#endif

/* ****************************************************************************************
 * End of file
 */
