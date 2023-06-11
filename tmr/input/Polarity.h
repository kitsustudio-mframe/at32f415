/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_CBEB6047_0F0D_4A1D_BCA9_9E385EFE5D39
#define CHIP_CBEB6047_0F0D_4A1D_BCA9_9E385EFE5D39

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::input {
  enum struct Polarity : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::input::Polarity : uint8_t {
  RISING_EDGE = 0x00,  /*!< tmr input channel polarity rising */
  FALLING_EDGE = 0x01, /*!< tmr input channel polarity falling */
  BOTH_EDGE = 0x03     /*!< tmr input channel polarity both edge */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_CBEB6047_0F0D_4A1D_BCA9_9E385EFE5D39 */
