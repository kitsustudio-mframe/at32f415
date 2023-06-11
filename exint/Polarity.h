/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E273F0C2_78A9_4140_AF73_F9C9EA058BB1
#define CHIP_E273F0C2_78A9_4140_AF73_F9C9EA058BB1

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::exint {
  enum struct Polarity : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::exint::Polarity : uint8_t {
  RISING = 0x00,   ///< external interrupt line rising trigger mode
  FALLING = 0x01,  ///< external interrupt line falling trigger mode
  BOTH = 0x02      ///< external interrupt line both rising and falling trigger mode
};
/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_E273F0C2_78A9_4140_AF73_F9C9EA058BB1 */
