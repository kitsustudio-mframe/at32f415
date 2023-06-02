/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_B469E2AD_EF61_4090_AC8F_0954B26CA3CD
#define AT32F415_B469E2AD_EF61_4090_AC8F_0954B26CA3CD

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr {
  enum struct BreakPolarity : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::BreakPolarity : uint8_t {
  ACTIVE_LOW = 0x00, /*!< tmr brk input channel active low */
  ACTIVE_HIGH = 0x01 /*!< tmr brk input channel active high */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_B469E2AD_EF61_4090_AC8F_0954B26CA3CD */
