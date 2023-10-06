/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_9533A911_1113_4384_8862_5E601DA9C089
#define CHIP_9533A911_1113_4384_8862_5E601DA9C089

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
  enum struct SourceClockCore : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::SourceClockCore : uint8_t {
  CLOCK_HICK = 0x00, /*!< high speed internal clock */
  CLOCK_HEXT = 0x01, /*!< high speed external crystal */
  CLOCK_PLL = 0x02,  /*!< phase locking loop */
  CLOCK_LEXT = 0x03, /*!< low speed external crystal */
  CLOCK_LICK = 0x04  /*!< low speed internal clock */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_9533A911_1113_4384_8862_5E601DA9C089 */
