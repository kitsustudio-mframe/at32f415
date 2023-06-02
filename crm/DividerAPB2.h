/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_29A9E83A_0264_4E3C_A69B_0CFAE46A8478
#define AT32F415_29A9E83A_0264_4E3C_A69B_0CFAE46A8478

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
  enum struct DividerAPB2 : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::DividerAPB2 : uint8_t {
  DIV1 = 0x00, /*!< ahbclk div1 to apb2clk */
  DIV2 = 0x04, /*!< ahbclk div2 to apb2clk */
  DIV4 = 0x05, /*!< ahbclk div4 to apb2clk */
  DIV8 = 0x06, /*!< ahbclk div8 to apb2clk */
  DIV16 = 0x07 /*!< ahbclk div16 to apb2clk */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_29A9E83A_0264_4E3C_A69B_0CFAE46A8478 */
