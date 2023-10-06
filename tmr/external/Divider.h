/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_6772C9C4_3FE5_49E5_85B2_E68515B5393E
#define CHIP_6772C9C4_3FE5_49E5_85B2_E68515B5393E

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::external {
  enum struct Divider : uint8_t;
}  // namespace chip::tmr::external

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::external::Divider : uint8_t {
  DIV1 = 0x00, /**< tmr external signal frequency divider 1 */
  DIV2 = 0x01, /**< tmr external signal frequency divider 2 */
  DIV4 = 0x02, /**< tmr external signal frequency divider 4 */
  DIV8 = 0x03  /**< tmr external signal frequency divider 8 */
};
/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_6772C9C4_3FE5_49E5_85B2_E68515B5393E */
