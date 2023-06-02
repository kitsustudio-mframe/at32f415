/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_02E406F4_8603_4AF6_920C_FEE572418A63
#define AT32F415_02E406F4_8603_4AF6_920C_FEE572418A63

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::crm {
  enum struct DividerHICK : uint8_t;
}  // namespace at32f415::crm

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::DividerHICK : uint8_t {
  DIV6 = 0x00, /*!< high speed internal clock (48 mhz) div6 */
  NODIV = 0x01 /*!< high speed internal clock (48 mhz) no div */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_02E406F4_8603_4AF6_920C_FEE572418A63 */
