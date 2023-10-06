/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_1F7543BF_F95D_4B1A_A576_310CB6389B8D
#define CHIP_1F7543BF_F95D_4B1A_A576_310CB6389B8D

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
  enum struct SourceClockPLL : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::SourceClockPLL : uint8_t {
  HICK = 0x00,    /*!< high speed internal clock as pll reference clock source */
  HEXT = 0x01,    /*!< high speed external crystal as pll reference clock source */
  HEXT_DIV = 0x02 /*!< high speed external crystal div as pll reference clock source */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_1F7543BF_F95D_4B1A_A576_310CB6389B8D */
