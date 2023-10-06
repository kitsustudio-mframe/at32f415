/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_4C72F3F1_6189_4C60_9557_DD5D3F89509E
#define CHIP_4C72F3F1_6189_4C60_9557_DD5D3F89509E

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::dma {
  enum struct RequestSource : uint8_t;
}  // namespace chip::tmr::dma

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::dma::RequestSource : uint8_t {
  CHANNEL = 0x00, /**< tmr dma request source select channel */
  OVERFLOW = 0x01 /**< tmr dma request source select overflow */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_4C72F3F1_6189_4C60_9557_DD5D3F89509E */
