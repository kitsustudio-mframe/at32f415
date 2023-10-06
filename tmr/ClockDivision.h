/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_33E6D863_9441_49A3_9F18_FBB07603C8AE
#define CHIP_33E6D863_9441_49A3_9F18_FBB07603C8AE

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
  enum struct ClockDivision : uint8_t;
}  // namespace chip::tmr

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::ClockDivision : uint8_t {
  DIV1 = 0x00, /*!< tmr clock division 1 */
  DIV2 = 0x01, /*!< tmr clock division 2 */
  DIV4 = 0x02  /*!< tmr clock division 4 */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_33E6D863_9441_49A3_9F18_FBB07603C8AE */
