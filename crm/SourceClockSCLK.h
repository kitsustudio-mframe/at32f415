/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B95B23CD_8D49_44B2_AEDA_DD62559103F2
#define CHIP_B95B23CD_8D49_44B2_AEDA_DD62559103F2

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
  enum struct SourceClockSCLK : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::SourceClockSCLK : uint8_t {
  HICK = 0x00, /*!< select high speed internal clock as sclk */
  HEXT = 0x01, /*!< select high speed external crystal as sclk */
  PLL = 0x02   /*!< select phase locking loop clock as sclk */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_B95B23CD_8D49_44B2_AEDA_DD62559103F2 */
