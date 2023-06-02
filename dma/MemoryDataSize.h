/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_7A509210_CF37_4865_AC85_FD8ACA9C7F2B
#define AT32F415_7A509210_CF37_4865_AC85_FD8ACA9C7F2B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::dma {
  enum struct MemoryDataSize : uint8_t;
}  // namespace at32f415::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::dma::MemoryDataSize : uint8_t {
  BYTE = 0x00,     /*!< dma memory databus width 8bit */
  HALFWORD = 0x01, /*!< dma memory databus width 16bit */
  WORD = 0x02      /*!< dma memory databus width 32bit */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_7A509210_CF37_4865_AC85_FD8ACA9C7F2B */
