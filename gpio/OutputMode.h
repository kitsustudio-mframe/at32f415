/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_9ADA95FA_B26A_487D_8F47_F3E14B56951E
#define CHIP_9ADA95FA_B26A_487D_8F47_F3E14B56951E

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
  enum struct OutputMode : uint8_t;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::gpio::OutputMode : uint8_t {
  PUSHPULL = 0x00, /*!< output push-pull */
  OPENDRAIN = 0x04 /*!< output open-drain */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_9ADA95FA_B26A_487D_8F47_F3E14B56951E */
