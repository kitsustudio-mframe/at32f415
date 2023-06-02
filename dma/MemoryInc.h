/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_1DE1A294_69C3_46A6_A2F3_B1C13F4BC119
#define AT32F415_1DE1A294_69C3_46A6_A2F3_B1C13F4BC119

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
  enum struct MemoryIncrement : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::dma::MemoryIncrement : uint8_t {
  DISABLE = 0x00, /*!< dma memory increment mode disable */
  ENABLE = 0x01   /*!< dma memory increment mode enable */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_1DE1A294_69C3_46A6_A2F3_B1C13F4BC119 */
