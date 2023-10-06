/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_462C81B7_74E4_4843_8A57_037F2CC42D32
#define CHIP_462C81B7_74E4_4843_8A57_037F2CC42D32

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::misc {
  enum struct SystickClockSource : uint32_t;
}  // namespace chip::misc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::misc::SystickClockSource : uint32_t {
  AHBCLK_DIV8 = 0x00000000, /**< systick clock source from core clock div8 */
  AHBCLK_NODIV = 0x00000004 /**< systick clock source from core clock */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_462C81B7_74E4_4843_8A57_037F2CC42D32 */
