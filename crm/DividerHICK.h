/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_02E406F4_8603_4AF6_920C_FEE572418A63
#define CHIP_02E406F4_8603_4AF6_920C_FEE572418A63

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct DividerHICK : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::DividerHICK : uint8_t {
  DIV6 = 0x00, /*!< high speed internal clock (48 mhz) div6 */
  NODIV = 0x01 /*!< high speed internal clock (48 mhz) no div */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_02E406F4_8603_4AF6_920C_FEE572418A63 */
