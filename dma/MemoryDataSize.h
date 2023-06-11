/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_7A509210_CF37_4865_AC85_FD8ACA9C7F2B
#define CHIP_7A509210_CF37_4865_AC85_FD8ACA9C7F2B

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct MemoryDataSize : uint8_t;
}  // namespace chip::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::MemoryDataSize : uint8_t {
  BYTE = 0x00,      ///< dma memory databus width 8bit
  HALFWORD = 0x01,  ///< dma memory databus width 16bit
  WORD = 0x02       ///< dma memory databus width 32bit
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_7A509210_CF37_4865_AC85_FD8ACA9C7F2B */
