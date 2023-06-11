/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_54980748_854D_4A68_9002_38AD9DC09064
#define CHIP_54980748_854D_4A68_9002_38AD9DC09064

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::channel {
  enum struct Select : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::channel::Select : uint8_t {
  CHANNEL1 = 0x00,  /**< tmr channel select channel 1 */
  CHANNEL1C = 0x01, /**< tmr channel select channel 1 complementary */
  CHANNEL2 = 0x02,  /**< tmr channel select channel 2 */
  CHANNEL2C = 0x03, /**< tmr channel select channel 2 complementary */
  CHANNEL3 = 0x04,  /**< tmr channel select channel 3 */
  CHANNEL3C = 0x05, /**< tmr channel select channel 3 complementary */
  CHANNEL4 = 0x06   /**< tmr channel select channel 4 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_54980748_854D_4A68_9002_38AD9DC09064 */
