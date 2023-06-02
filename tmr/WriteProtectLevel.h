/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_CDF2738E_B93B_4027_A364_2F322C348AF2
#define AT32F415_CDF2738E_B93B_4027_A364_2F322C348AF2

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
  enum struct WriteProtectLevel : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::WriteProtectLevel : uint8_t {
  OFF = 0x00,     /*!< tmr write protect off */
  LEVEL_3 = 0x01, /*!< tmr write protect level 3 */
  LEVEL_2 = 0x02, /*!< tmr write protect level 2 */
  LEVEL_1 = 0x03  /*!< tmr write protect level 1 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_CDF2738E_B93B_4027_A364_2F322C348AF2 */
