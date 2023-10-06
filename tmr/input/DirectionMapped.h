/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_8B20CAD2_6A48_4B17_B30B_A6004BDF710C
#define CHIP_8B20CAD2_6A48_4B17_B30B_A6004BDF710C

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::input {
  enum struct DirectionMapped : uint8_t;
}  // namespace chip::tmr::input

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::input::DirectionMapped : uint8_t {
  DIRECT = 0x01,   /*!< channel is configured as input, mapped direct */
  INDIRECT = 0x02, /*!< channel is configured as input, mapped indirect */
  STI = 0x03       /*!< channel is configured as input, mapped trc */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_8B20CAD2_6A48_4B17_B30B_A6004BDF710C */
