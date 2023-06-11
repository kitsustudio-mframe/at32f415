/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F76B7B30_6B70_4CC8_B07D_677B58BE45D5
#define CHIP_F76B7B30_6B70_4CC8_B07D_677B58BE45D5

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
  enum struct Divider : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::input::Divider : uint8_t {
  DIV1 = 0x00, /*!< tmr channel input divider 1 */
  DIV2 = 0x01, /*!< tmr channel input divider 2 */
  DIV4 = 0x02, /*!< tmr channel input divider 4 */
  DIV8 = 0x03  /*!< tmr channel input divider 8 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_F76B7B30_6B70_4CC8_B07D_677B58BE45D5 */
