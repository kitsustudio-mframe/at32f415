/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_C4BA386E_6625_4C98_A615_98BAB7CD67A2
#define CHIP_C4BA386E_6625_4C98_A615_98BAB7CD67A2

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::external {
  enum struct Polarity : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::external::Polarity : uint8_t {
  NON_INVERTED = 0x00, /*!< tmr external signal polarity non-inerted */
  INVERTED = 0x01      /*!< tmr external signal polarity inerted */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_C4BA386E_6625_4C98_A615_98BAB7CD67A2 */
