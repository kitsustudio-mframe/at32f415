/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_586A66CE_8FB1_43F8_976E_A2A6062B11FF
#define AT32F415_586A66CE_8FB1_43F8_976E_A2A6062B11FF

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
  enum struct DividerADC : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::DividerADC : uint8_t {
  DIV2 = 0x00,  /*!< apb2clk div2 to adcclk */
  DIV4 = 0x01,  /*!< apb2clk div4 to adcclk */
  DIV6 = 0x02,  /*!< apb2clk div6 to adcclk */
  DIV8 = 0x03,  /*!< apb2clk div8 to adcclk */
  DIV12 = 0x05, /*!< apb2clk div12 to adcclk */
  DIV16 = 0x07  /*!< apb2clk div16 to adcclk */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_586A66CE_8FB1_43F8_976E_A2A6062B11FF */
