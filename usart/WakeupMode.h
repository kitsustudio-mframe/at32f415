/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F71EBA06_E9FF_4F0B_BBB3_96D3798CF1A0
#define CHIP_F71EBA06_E9FF_4F0B_BBB3_96D3798CF1A0

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::usart {
  enum struct WakeupMode : uint8_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::WakeupMode : uint8_t {
  IDLE_FRAME = 0x00, /*!< usart wakeup by idle frame */
  MATCHING_ID = 0x01 /*!< usart wakeup by matching id */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_F71EBA06_E9FF_4F0B_BBB3_96D3798CF1A0 */
