/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_D2E76734_8568_4D65_951F_2DB411686FD2
#define CHIP_D2E76734_8568_4D65_951F_2DB411686FD2

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/exint/Line.h"
#include "chip_arterytek_at32f415/exint/Mode.h"
#include "chip_arterytek_at32f415/exint/Polarity.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::exint {
  struct Config;
}  // namespace chip::exint

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::exint::Config {
  Line line;
  Mode mode;
  Polarity polarity;
  bool enable;
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_D2E76734_8568_4D65_951F_2DB411686FD2 */
