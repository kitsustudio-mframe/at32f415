/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_1F7543BF_F95D_4B1A_A576_310CB6389B8D
#define AT32F415_1F7543BF_F95D_4B1A_A576_310CB6389B8D

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
  enum struct SourceClockPLL : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::SourceClockPLL : uint8_t {
  HICK = 0x00,    /*!< high speed internal clock as pll reference clock source */
  HEXT = 0x01,    /*!< high speed external crystal as pll reference clock source */
  HEXT_DIV = 0x02 /*!< high speed external crystal div as pll reference clock source */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_1F7543BF_F95D_4B1A_A576_310CB6389B8D */
