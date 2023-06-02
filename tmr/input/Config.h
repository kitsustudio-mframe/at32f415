/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_3F07BCED_1BDB_450C_9DC6_557296927147
#define AT32F415_3F07BCED_1BDB_450C_9DC6_557296927147

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./../channel/Select.h"
#include "./../input/DirectionMapped.h"
#include "./../input/Polarity.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::input {
  struct Config;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::tmr::input::Config {
  channel::Select channelSelect;               /*!< tmr input channel select */
  input::Polarity inputPolarity;               /*!< tmr input polarity select */
  input::DirectionMapped inputDirectionMapped; /*!< tmr channel mapped direct or indirect */
  uint8_t inputFilterValue;                    /*!< tmr channel filter value */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_3F07BCED_1BDB_450C_9DC6_557296927147 */
