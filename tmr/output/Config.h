/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_642B4C7D_5802_460E_A9CF_7739BF1A23C2
#define AT32F415_642B4C7D_5802_460E_A9CF_7739BF1A23C2

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./ControlMode.h"
#include "./Polarity.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::output {
  struct Config;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::tmr::output::Config {
  ControlMode outputControlMode; /*!< output channel mode */
  Polarity ocPolarity;           /*!< output channel polarity */
  Polarity occPolarity;          /*!< output channel complementary polarity */
  bool ocIdleState;              /*!< output channel idle state */
  bool occIdleState;             /*!< output channel complementary idle state */
  bool ocOutputState;            /*!< output channel enable */
  bool occOutputState;           /*!< output channel complementary enable */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_642B4C7D_5802_460E_A9CF_7739BF1A23C2 */
