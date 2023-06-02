/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_FD19DA17_734B_4865_A1C7_5A1CB8FCA964
#define AT32F415_FD19DA17_734B_4865_A1C7_5A1CB8FCA964

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
  enum struct PriorityLevel : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::dma::PriorityLevel : uint8_t {
  LOW = 0x00,      /*!< dma channel priority: low */
  MEDIUM = 0x01,   /*!< dma channel priority: mediue */
  HIGH = 0x02,     /*!< dma channel priority: high */
  VERY_HIGH = 0x03 /*!< dma channel priority: very high */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_FD19DA17_734B_4865_A1C7_5A1CB8FCA964 */
