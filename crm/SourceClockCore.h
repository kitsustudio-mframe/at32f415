/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_9533A911_1113_4384_8862_5E601DA9C089
#define AT32F415_9533A911_1113_4384_8862_5E601DA9C089

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
  enum struct SourceClockCore : uint8_t;
}  // namespace at32f415::crm

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::SourceClockCore : uint8_t {
  CLOCK_HICK = 0x00, /*!< high speed internal clock */
  CLOCK_HEXT = 0x01, /*!< high speed external crystal */
  CLOCK_PLL = 0x02,  /*!< phase locking loop */
  CLOCK_LEXT = 0x03, /*!< low speed external crystal */
  CLOCK_LICK = 0x04  /*!< low speed internal clock */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_9533A911_1113_4384_8862_5E601DA9C089 */
