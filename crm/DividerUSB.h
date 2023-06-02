/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_04795175_3A50_4091_9B63_43A5AC99343C
#define AT32F415_04795175_3A50_4091_9B63_43A5AC99343C

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
  enum struct DividerUSB : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::DividerUSB : uint8_t {
  DIV1_5 = 0x00, /*!< pllclk div1.5 to usbclk */
  DIV1 = 0x01,   /*!< pllclk div1 to usbclk */
  DIV2_5 = 0x02, /*!< pllclk div2.5 to usbclk */
  DIV2 = 0x03,   /*!< pllclk div2 to usbclk */
  DIV3_5 = 0x04, /*!< pllclk div3.5 to usbclk */
  DIV3 = 0x05,   /*!< pllclk div3 to usbclk */
  DIV4 = 0x06    /*!< pllclk div4 to usbclk */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_04795175_3A50_4091_9B63_43A5AC99343C */
