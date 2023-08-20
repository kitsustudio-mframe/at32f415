/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./EXINT.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */
using chip::exint::EXINT;

//-----------------------------------------------------------------------------------------
using chip::Processor;
using chip::exint::Config;
using chip::exint::Line;
using chip::exint::Mode;
using chip::exint::Polarity;
using chip::exint::Register;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::exint::EXINT0 = *reinterpret_cast<Register*>(Processor::BASE_EXINT);
/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/** ---------------------------------------------------------------------------------------
 *
 */
void EXINT::reset(void) {
  EXINT0.inten = 0x00000000;
  EXINT0.polcfg1 = 0x00000000;
  EXINT0.polcfg2 = 0x00000000;
  EXINT0.evten = 0x00000000;
  EXINT0.intsts = 0x007FFFFF;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void EXINT::defaultParaInit(Config& config) {
  config.enable = false;
  config.line = Line::NONE;
  config.polarity = Polarity::FALLING;
  config.mode = Mode::EVENT;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void EXINT::init(Config& config) {
  uint32_t lineIndex = 0;
  lineIndex = static_cast<uint32_t>(config.line);

  EXINT0.inten &= ~lineIndex;
  EXINT0.evten &= ~lineIndex;

  if (config.enable != false) {
    if (config.mode == Mode::INTERRUPUT)
      EXINT0.inten |= lineIndex;

    else
      EXINT0.evten |= lineIndex;

    EXINT0.polcfg1 &= ~lineIndex;
    EXINT0.polcfg2 &= ~lineIndex;

    if (config.polarity == Polarity::RISING) {
      EXINT0.polcfg1 |= lineIndex;

    } else if (config.polarity == Polarity::FALLING) {
      EXINT0.polcfg2 |= lineIndex;

    } else {
      EXINT0.polcfg1 |= lineIndex;
      EXINT0.polcfg2 |= lineIndex;
    }
  }
}

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
