/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_9240E19E_FF55_46E1_BDEE_160881F1F22F
#define CHIP_9240E19E_FF55_46E1_BDEE_160881F1F22F

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::pwc {
  enum struct SleepEnter : uint8_t;
}  // namespace chip::pwc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::pwc::SleepEnter : uint8_t {
  WFI = 0x00,  ///< use wfi enter sleep mode
  WFE = 0x01   ///< use wfe enter sleep mode
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_9240E19E_FF55_46E1_BDEE_160881F1F22F */
