/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_AE2F3F22_F1D1_4EA6_9AC6_3EC869CD2257
#define CHIP_AE2F3F22_F1D1_4EA6_9AC6_3EC869CD2257

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio {
  enum struct Pins : uint16_t;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * GPIO pins number definition
 *
 */
enum struct chip::gpio::Pins : uint16_t {
  PINS0 = 0x0001,   ///< gpio pins number 0
  PINS1 = 0x0002,   ///< gpio pins number 1
  PINS2 = 0x0004,   ///< gpio pins number 2
  PINS3 = 0x0008,   ///< gpio pins number 3
  PINS4 = 0x0010,   ///< gpio pins number 4
  PINS5 = 0x0020,   ///< gpio pins number 5
  PINS6 = 0x0040,   ///< gpio pins number 6
  PINS7 = 0x0080,   ///< gpio pins number 7
  PINS8 = 0x0100,   ///< gpio pins number 8
  PINS9 = 0x0200,   ///< gpio pins number 9
  PINS10 = 0x0400,  ///< gpio pins number 10
  PINS11 = 0x0800,  ///< gpio pins number 11
  PINS12 = 0x1000,  ///< gpio pins number 12
  PINS13 = 0x2000,  ///< gpio pins number 13
  PINS14 = 0x4000,  ///< gpio pins number 14
  PINS15 = 0x8000,  ///< gpio pins number 15
  ALL = 0xFFFF      ///< gpio all pins
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_AE2F3F22_F1D1_4EA6_9AC6_3EC869CD2257 */
