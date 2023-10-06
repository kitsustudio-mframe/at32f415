/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_42E31C46_1237_45CA_A025_FCF8AB2F4BA5
#define CHIP_42E31C46_1237_45CA_A025_FCF8AB2F4BA5

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
  enum struct SourceClockERTC : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::SourceClockERTC : uint8_t {
  CLOCK_NOCLK = 0x00,   /*!< no clock as ertc clock source */
  CLOCK_LEXT = 0x01,    /*!< low speed external crystal as ertc clock source */
  CLOCK_LICK = 0x02,    /*!< low speed internal clock as ertc clock source */
  CLOCK_HEXT_DIV = 0x03 /*!< high speed external crystal div as ertc clock source */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_42E31C46_1237_45CA_A025_FCF8AB2F4BA5 */
