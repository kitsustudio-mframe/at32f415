/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_195A4C0F_3E8E_42C7_9F7D_D1BD64919F2C
#define AT32F415_195A4C0F_3E8E_42C7_9F7D_D1BD64919F2C

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
  enum struct DividerAPB1 : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::DividerAPB1 : uint8_t {
  DIV1 = 0x00, /*!< ahbclk div1 to apb1clk */
  DIV2 = 0x04, /*!< ahbclk div2 to apb1clk */
  DIV4 = 0x05, /*!< ahbclk div4 to apb1clk */
  DIV8 = 0x06, /*!< ahbclk div8 to apb1clk */
  DIV16 = 0x07 /*!< ahbclk div16 to apb1clk */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_195A4C0F_3E8E_42C7_9F7D_D1BD64919F2C */
