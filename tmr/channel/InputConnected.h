/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_8DDF2B25_5E4D_4A00_96E7_D27DBE17C4F7
#define CHIP_8DDF2B25_5E4D_4A00_96E7_D27DBE17C4F7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::channel {
  enum struct InputConnected : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::channel::InputConnected : uint8_t {
  C1IRAW = 0x00,    /*!< channel1 pins is only connected to C1IRAW input */
  C1IRAW_XOR = 0x01 /*!< channel1/2/3 pins are connected to C1IRAW input after xored */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_8DDF2B25_5E4D_4A00_96E7_D27DBE17C4F7 */
