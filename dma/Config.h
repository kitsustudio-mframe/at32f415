/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_02655F87_3724_403A_A3F2_CDF651052B8B
#define AT32F415_02655F87_3724_403A_A3F2_CDF651052B8B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "Direction.h"
#include "MemoryDataSize.h"
#include "PeripheralDataSize.h"
#include "PriorityLevel.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::dma {
  struct Config;
}  // namespace at32f415::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::dma::Config {
  uint32_t peripheralBaseAddr;            /*!< base addrress for peripheral */
  uint32_t memoryBaseAddr;                /*!< base addrress for memory */
  Direction direction;                    /*!< dma transmit direction, peripheral as source or as destnation  */
  uint16_t bufferSize;                    /*!< counter to transfer */
  bool peripheralIncEnable;               /*!< periphera address increment after one transmit */
  bool memoryIncEnable;                   /*!< memory address increment after one transmit */
  PeripheralDataSize peripheralDataWidth; /*!< peripheral data width for transmit */
  MemoryDataSize memoryDataWidth;         /*!< memory data width for transmit */
  bool loopModeEnable;                    /*!< when circular mode enable, buffer size will reload if count to 0 */
  PriorityLevel priority;                 /*!< dma priority can choose from very high, high, dedium or low */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_02655F87_3724_403A_A3F2_CDF651052B8B */
