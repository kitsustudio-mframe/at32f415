/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_3F07BCED_1BDB_450C_9DC6_557296927147
#define CHIP_3F07BCED_1BDB_450C_9DC6_557296927147

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/tmr/channel/Select.h"
#include "chip_arterytek_at32f415/tmr/input/DirectionMapped.h"
#include "chip_arterytek_at32f415/tmr/input/Polarity.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::input {
  struct Config;
}  // namespace chip::tmr::input

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::tmr::input::Config {
  channel::Select channelSelect;               /*!< tmr input channel select */
  input::Polarity inputPolarity;               /*!< tmr input polarity select */
  input::DirectionMapped inputDirectionMapped; /*!< tmr channel mapped direct or indirect */
  uint8_t inputFilterValue;                    /*!< tmr channel filter value */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_3F07BCED_1BDB_450C_9DC6_557296927147 */
