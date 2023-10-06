/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_642B4C7D_5802_460E_A9CF_7739BF1A23C2
#define CHIP_642B4C7D_5802_460E_A9CF_7739BF1A23C2

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------

#include "mframe.h"

//-----------------------------------------------------------------------------
#include "ControlMode.h"
#include "Polarity.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr::output {
  struct Config;
}  // namespace chip::tmr::output

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::tmr::output::Config {
  ControlMode outputControlMode; /*!< output channel mode */
  Polarity ocPolarity;           /*!< output channel polarity */
  Polarity occPolarity;          /*!< output channel complementary polarity */
  bool ocIdleState;              /*!< output channel idle state */
  bool occIdleState;             /*!< output channel complementary idle state */
  bool ocOutputState;            /*!< output channel enable */
  bool occOutputState;           /*!< output channel complementary enable */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_642B4C7D_5802_460E_A9CF_7739BF1A23C2 */
