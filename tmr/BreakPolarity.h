/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B469E2AD_EF61_4090_AC8F_0954B26CA3CD
#define CHIP_B469E2AD_EF61_4090_AC8F_0954B26CA3CD

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr {
  enum struct BreakPolarity : uint8_t;
}  // namespace chip::tmr

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::BreakPolarity : uint8_t {
  ACTIVE_LOW = 0x00, /*!< tmr brk input channel active low */
  ACTIVE_HIGH = 0x01 /*!< tmr brk input channel active high */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_B469E2AD_EF61_4090_AC8F_0954B26CA3CD */
