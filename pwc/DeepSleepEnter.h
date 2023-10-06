/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_4880F19E_D918_472A_B649_19E40FC6E120
#define CHIP_4880F19E_D918_472A_B649_19E40FC6E120

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
  enum struct DeepSleepEnter : uint8_t;
}  // namespace chip::pwc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::pwc::DeepSleepEnter : uint8_t {
  WFI = 0x00,  ///< use wfi enter deepsleep mode
  WFE = 0x01   ///< use wfe enter deepsleep mode
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_4880F19E_D918_472A_B649_19E40FC6E120 */
