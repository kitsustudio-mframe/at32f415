/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_462C81B7_74E4_4843_8A57_037F2CC42D32
#define AT32F415_462C81B7_74E4_4843_8A57_037F2CC42D32

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::misc {
  enum struct SystickClockSource : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::misc::SystickClockSource : uint32_t {
  AHBCLK_DIV8 = 0x00000000, /**< systick clock source from core clock div8 */
  AHBCLK_NODIV = 0x00000004 /**< systick clock source from core clock */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_462C81B7_74E4_4843_8A57_037F2CC42D32 */
