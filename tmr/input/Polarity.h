/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_CBEB6047_0F0D_4A1D_BCA9_9E385EFE5D39
#define AT32F415_CBEB6047_0F0D_4A1D_BCA9_9E385EFE5D39

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::input {
  enum struct Polarity : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::input::Polarity : uint8_t {
  RISING_EDGE = 0x00,  /*!< tmr input channel polarity rising */
  FALLING_EDGE = 0x01, /*!< tmr input channel polarity falling */
  BOTH_EDGE = 0x03     /*!< tmr input channel polarity both edge */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_CBEB6047_0F0D_4A1D_BCA9_9E385EFE5D39 */
