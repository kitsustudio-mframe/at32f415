/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_8B20CAD2_6A48_4B17_B30B_A6004BDF710C
#define AT32F415_8B20CAD2_6A48_4B17_B30B_A6004BDF710C

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
  enum struct DirectionMapped : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::input::DirectionMapped : uint8_t {
  DIRECT = 0x01,   /*!< channel is configured as input, mapped direct */
  INDIRECT = 0x02, /*!< channel is configured as input, mapped indirect */
  STI = 0x03       /*!< channel is configured as input, mapped trc */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_8B20CAD2_6A48_4B17_B30B_A6004BDF710C */
