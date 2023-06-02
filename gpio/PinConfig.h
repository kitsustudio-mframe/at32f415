/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_79C67E64_6C39_487F_8D8E_F301F919801A
#define AT32F415_79C67E64_6C39_487F_8D8E_F301F919801A

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "DriveMode.h"
#include "Mode.h"
#include "OutputMode.h"
#include "PullMode.h"
#include "Pins.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415{
  namespace gpio{
    struct PinConfig;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::gpio::PinConfig{
  uint32_t pins;          ///< pins number selection
  OutputMode outputMode; ///< output type selection
  PullMode pullMode;     ///< pull type selection
  Mode mode;             ///< mode selection
  DriveMode driveMode;   ///< drive strength selection
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_79C67E64_6C39_487F_8D8E_F301F919801A */
