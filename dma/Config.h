/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_02655F87_3724_403A_A3F2_CDF651052B8B
#define CHIP_02655F87_3724_403A_A3F2_CDF651052B8B

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../dma/Direction.h"
#include "./../dma/MemoryDataSize.h"
#include "./../dma/PeripheralDataSize.h"
#include "./../dma/PriorityLevel.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  struct Config;
}  // namespace chip::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::dma::Config {
  uint32_t peripheralBaseAddr;             ///< base addrress for peripheral
  uint32_t memoryBaseAddr;                 ///< base addrress for memory
  Direction direction;                     ///< dma transmit direction, peripheral as source or as destnation
  uint16_t bufferSize;                     ///< counter to transfer
  bool peripheralIncEnable;                ///< periphera address increment after one transmit
  bool memoryIncEnable;                    ///< memory address increment after one transmit
  PeripheralDataSize peripheralDataWidth;  ///< peripheral data width for transmit
  MemoryDataSize memoryDataWidth;          ///< memory data width for transmit
  bool loopModeEnable;                     ///< when circular mode enable, buffer size will reload if count to 0
  PriorityLevel priority;                  ///< dma priority can choose from very high, high, dedium or low
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_02655F87_3724_403A_A3F2_CDF651052B8B */
