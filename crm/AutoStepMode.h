/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F18F8BD4_E9D2_4511_B13D_11E80B665195
#define CHIP_F18F8BD4_E9D2_4511_B13D_11E80B665195

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
  enum struct AutoStepMode : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::AutoStepMode : uint8_t {
  DISABLE = 0x00, /*!< disable auto step mode */
  ENABLE = 0x03   /*!< enable auto step mode */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_F18F8BD4_E9D2_4511_B13D_11E80B665195 */
