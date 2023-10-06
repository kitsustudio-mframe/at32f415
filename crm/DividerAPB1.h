/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_195A4C0F_3E8E_42C7_9F7D_D1BD64919F2C
#define CHIP_195A4C0F_3E8E_42C7_9F7D_D1BD64919F2C

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
  enum struct DividerAPB1 : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::DividerAPB1 : uint8_t {
  DIV1 = 0x00, /*!< ahbclk div1 to apb1clk */
  DIV2 = 0x04, /*!< ahbclk div2 to apb1clk */
  DIV4 = 0x05, /*!< ahbclk div4 to apb1clk */
  DIV8 = 0x06, /*!< ahbclk div8 to apb1clk */
  DIV16 = 0x07 /*!< ahbclk div16 to apb1clk */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_195A4C0F_3E8E_42C7_9F7D_D1BD64919F2C */
