/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_EDC53D9A_300D_4493_8005_B0E310CB4C9C
#define CHIP_EDC53D9A_300D_4493_8005_B0E310CB4C9C

/* ****************************************************************************
 * Include
 */

#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct PeripheralDataSize : uint8_t;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::PeripheralDataSize : uint8_t {
  BYTE = 0x00,      ///< dma peripheral databus width 8bit
  HALFWORD = 0x01,  ///< dma peripheral databus width 16bit
  WORD = 0x02       ///< dma peripheral databus width 32bit
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_EDC53D9A_300D_4493_8005_B0E310CB4C9C */
