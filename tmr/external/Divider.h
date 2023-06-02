/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_6772C9C4_3FE5_49E5_85B2_E68515B5393E
#define AT32F415_6772C9C4_3FE5_49E5_85B2_E68515B5393E

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::external {
  enum struct Divider : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::external::Divider : uint8_t {
  DIV1 = 0x00, /**< tmr external signal frequency divider 1 */
  DIV2 = 0x01, /**< tmr external signal frequency divider 2 */
  DIV4 = 0x02, /**< tmr external signal frequency divider 4 */
  DIV8 = 0x03  /**< tmr external signal frequency divider 8 */
};
/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_6772C9C4_3FE5_49E5_85B2_E68515B5393E */
