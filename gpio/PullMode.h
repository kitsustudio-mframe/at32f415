/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E700C623_D8A5_460D_BE91_21878D4648A3
#define CHIP_E700C623_D8A5_460D_BE91_21878D4648A3

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio {
  enum struct PullMode : uint8_t;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::gpio::PullMode : uint8_t {
  PULL_NONE = 0x0004,  ///< floating for input, no pull for output
  PULL_UP = 0x0018,    ///< pull-up
  PULL_DOWN = 0x0028   ///< pull-down
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_E700C623_D8A5_460D_BE91_21878D4648A3 */
