/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_F45490D9_C595_4C4B_9554_576AB1F0730E
#define AT32F415_F45490D9_C595_4C4B_9554_576AB1F0730E

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
  enum struct PeripheralIncrement : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::dma::PeripheralIncrement : uint8_t {
  DISABLE = 0x00, /*!< dma peripheral increment mode disable */
  ENABLE = 0x01   /*!< dma peripheral increment mode enable */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_F45490D9_C595_4C4B_9554_576AB1F0730E */
