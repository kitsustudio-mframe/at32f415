/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_2459E0F8_02DB_41E9_B4DB_BCEFF9B591EE
#define CHIP_2459E0F8_02DB_41E9_B4DB_BCEFF9B591EE

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct DividerAHB : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::DividerAHB : uint8_t {
  DIV1 = 0x00,   /*!< sclk div1 to ahbclk */
  DIV2 = 0x08,   /*!< sclk div2 to ahbclk */
  DIV4 = 0x09,   /*!< sclk div4 to ahbclk */
  DIV8 = 0x0A,   /*!< sclk div8 to ahbclk */
  DIV16 = 0x0B,  /*!< sclk div16 to ahbclk */
  DIV64 = 0x0C,  /*!< sclk div64 to ahbclk */
  DIV128 = 0x0D, /*!< sclk div128 to ahbclk */
  DIV256 = 0x0E, /*!< sclk div256 to ahbclk */
  DIV512 = 0x0F  /*!< sclk div512 to ahbclk */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_2459E0F8_02DB_41E9_B4DB_BCEFF9B591EE */
