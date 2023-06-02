/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_33E6D863_9441_49A3_9F18_FBB07603C8AE
#define AT32F415_33E6D863_9441_49A3_9F18_FBB07603C8AE

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
  enum struct ClockDivision : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::ClockDivision : uint8_t {
  DIV1 = 0x00, /*!< tmr clock division 1 */
  DIV2 = 0x01, /*!< tmr clock division 2 */
  DIV4 = 0x02  /*!< tmr clock division 4 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_33E6D863_9441_49A3_9F18_FBB07603C8AE */
