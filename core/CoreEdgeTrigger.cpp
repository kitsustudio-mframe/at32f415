/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CoreEdgeTrigger.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"
#include "mframe.h"

/* ****************************************************************************************
 * namesapce;
 */
namespace chip::core {
  static uint32_t coreEdgeTriggerLevel = 0x00000000U;

  static void coreEdgeTriggerResetPeriph(uint32_t mask) {
    chip::exint::EXINT0.intsts |= static_cast<uint32_t>(mask);
    mask = ~mask;

    chip::exint::EXINT0.inten &= static_cast<uint32_t>(mask);
    chip::exint::EXINT0.evten &= static_cast<uint32_t>(mask);
    chip::exint::EXINT0.polcfg1 &= static_cast<uint32_t>(mask);
    chip::exint::EXINT0.polcfg2 &= static_cast<uint32_t>(mask);

    return;
  }

  static chip::core::CoreInterrupt::Irq getInterruptService(chip::exint::Line line) {
    switch (line) {
      //------------------------------------------
      case chip::exint::Line::LINE0:
        return chip::core::CoreInterrupt::IRQ_EXINT0;

      //------------------------------------------
      case chip::exint::Line::LINE1:
        return chip::core::CoreInterrupt::IRQ_EXINT1;

      //------------------------------------------
      case chip::exint::Line::LINE2:
        return chip::core::CoreInterrupt::IRQ_EXINT2;

      //------------------------------------------
      case chip::exint::Line::LINE3:
        return chip::core::CoreInterrupt::IRQ_EXINT3;

      //------------------------------------------
      case chip::exint::Line::LINE4:
        return chip::core::CoreInterrupt::IRQ_EXINT4;

      //------------------------------------------
      case chip::exint::Line::LINE5:
        return chip::core::CoreInterrupt::IRQ_EXINT5;

      //------------------------------------------
      case chip::exint::Line::LINE6:
        return chip::core::CoreInterrupt::IRQ_EXINT6;

      //------------------------------------------
      case chip::exint::Line::LINE7:
        return chip::core::CoreInterrupt::IRQ_EXINT7;

      //------------------------------------------
      case chip::exint::Line::LINE8:
        return chip::core::CoreInterrupt::IRQ_EXINT8;

      //------------------------------------------
      case chip::exint::Line::LINE9:
        return chip::core::CoreInterrupt::IRQ_EXINT9;

      //------------------------------------------
      case chip::exint::Line::LINE10:
        return chip::core::CoreInterrupt::IRQ_EXINT10;

      //------------------------------------------
      case chip::exint::Line::LINE11:
        return chip::core::CoreInterrupt::IRQ_EXINT11;

      //------------------------------------------
      case chip::exint::Line::LINE12:
        return chip::core::CoreInterrupt::IRQ_EXINT12;

      //------------------------------------------
      case chip::exint::Line::LINE13:
        return chip::core::CoreInterrupt::IRQ_EXINT13;

      //------------------------------------------
      case chip::exint::Line::LINE14:
        return chip::core::CoreInterrupt::IRQ_EXINT14;

      //------------------------------------------
      case chip::exint::Line::LINE15:
        return chip::core::CoreInterrupt::IRQ_EXINT15;

      //------------------------------------------
      case chip::exint::Line::LINE16:
        return chip::core::CoreInterrupt::IRQ_PVM;

      //------------------------------------------
      case chip::exint::Line::LINE17:
        return chip::core::CoreInterrupt::IRQ_ERTC_WKUP;

      //------------------------------------------
      case chip::exint::Line::LINE18:
        return chip::core::CoreInterrupt::IRQ_OTGFS_WAKE;

      //------------------------------------------
      case chip::exint::Line::LINE19:
        return chip::core::CoreInterrupt::IRQ_CMP1;

      //------------------------------------------
      case chip::exint::Line::LINE20:
        return chip::core::CoreInterrupt::IRQ_CMP2;

      //------------------------------------------
      case chip::exint::Line::LINE21:
        return chip::core::CoreInterrupt::IRQ_ERTC_ALARM;

      //------------------------------------------
      case chip::exint::Line::LINE22:
        return chip::core::CoreInterrupt::IRQ_ERTC_WKUP;

      default:
        return chip::core::CoreInterrupt::IRQ_MAX_QUANTITY;
    }
  }
}  // namespace chip::core

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using chip::core::CoreEdgeTrigger;
using chip::exint::EXINT0;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CoreEdgeTrigger::CoreEdgeTrigger(chip::exint::Line line) {
  this->mEventFall = nullptr;
  this->mEventRise = nullptr;
  this->mLine = line;
  this->mStatusFall = false;
  this->mStatusRise = false;
  return;
}

//-----------------------------------------------------------------------------------------
CoreEdgeTrigger::~CoreEdgeTrigger(void) {
  this->enableAll(false);
  this->deinit();
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override> - mframe::hal::Base
 */

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::deinit(void) {
  if (!this->isInit())
    return false;

  coreEdgeTriggerResetPeriph(static_cast<uint32_t>(this->mLine));

  Core::interrupt.irqEnable(getInterruptService(this->mLine), false);
  Core::interrupt.setHandler(getInterruptService(this->mLine), nullptr);

  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::init(void) {
  if (this->isInit())
    return false;

  coreEdgeTriggerResetPeriph(static_cast<uint32_t>(this->mLine));

  Core::interrupt.setHandler(getInterruptService(this->mLine), this);
  Core::interrupt.irqEnable(getInterruptService(this->mLine), true);

  // enable exint line interrupt flag;
  EXINT0.inten |= static_cast<uint32_t>(this->mLine);

  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::isInit(void) {
  return (EXINT0.inten & static_cast<uint32_t>(this->mLine));
}

/* ****************************************************************************************
 * Public Method <Override> - mframe::hal::trigger::EdgeTrigger
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::enableAll(bool enable) {
  if (enable)
    coreEdgeTriggerLevel |= static_cast<uint32_t>(this->mLine);
  else
    coreEdgeTriggerLevel &= ~static_cast<uint32_t>(this->mLine);
}

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::enableFall(bool enable) {
  if (enable) {
    // if rise event is enable
    if (EXINT0.polcfg1 & static_cast<uint32_t>(this->mLine)) {
      coreEdgeTriggerLevel |= static_cast<uint32_t>(this->mLine);

    } else {
      // enable fall event
      EXINT0.polcfg2 |= static_cast<uint32_t>(this->mLine);
    }
  } else {
    // if event rise fall also enable
    if (coreEdgeTriggerLevel & static_cast<uint32_t>(this->mLine)) {
      // disable both edge event
      coreEdgeTriggerLevel &= ~static_cast<uint32_t>(this->mLine);

      // if now waitting for event rise
      if (EXINT0.polcfg2 & static_cast<uint32_t>(this->mLine)) {
        // disable rise event
        EXINT0.polcfg2 &= ~static_cast<uint32_t>(this->mLine);

        // enable fall event
        EXINT0.polcfg1 |= static_cast<uint32_t>(this->mLine);
      }
    } else {
      // disable fall event
      EXINT0.polcfg2 &= ~static_cast<uint32_t>(this->mLine);
    }
  }

  return;
}

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::enableRise(bool enable) {
  if (enable) {
    // if fall event is enable
    if (EXINT0.polcfg2 & static_cast<uint32_t>(this->mLine)) {
      coreEdgeTriggerLevel |= static_cast<uint32_t>(this->mLine);

    } else {
      // enable fall event
      EXINT0.polcfg1 |= static_cast<uint32_t>(this->mLine);
    }
  } else {
    // if event rise fall also enable
    if (coreEdgeTriggerLevel & static_cast<uint32_t>(this->mLine)) {
      // disable both edge event
      coreEdgeTriggerLevel &= ~static_cast<uint32_t>(this->mLine);

      // if now waitting for event rise
      if (EXINT0.polcfg1 & static_cast<uint32_t>(this->mLine)) {
        // disable rise event
        EXINT0.polcfg1 &= ~static_cast<uint32_t>(this->mLine);

        // enable fall event
        EXINT0.polcfg2 |= static_cast<uint32_t>(this->mLine);
      }

    } else {
      // disable rise event
      EXINT0.polcfg1 &= ~static_cast<uint32_t>(this->mLine);
    }
  }

  return;
}

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::setEventRise(mframe::hal::trigger::EventRise* event) {
  if (event)
    this->mEventRise = event;

  else
    this->mEventRise = this;

  return;
}

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::setEventFall(mframe::hal::trigger::EventFall* event) {
  if (event)
    this->mEventFall = event;

  else
    this->mEventFall = this;

  return;
}

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::readRise(void) {
  if (this->mStatusRise) {
    this->mStatusRise = false;
    return true;
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::readFall(void) {
  if (this->mStatusFall) {
    this->mStatusFall = false;
    return true;
  }

  return false;
}

/* ****************************************************************************************
 * Public Method <Override> - mframe::hal::InterruptEvent
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::interruptEvent(void) {
  uint32_t mask = static_cast<uint32_t>(this->mLine);
  if (EXINT0.polcfg1 & mask) {
    if (coreEdgeTriggerLevel & mask) {
      EXINT0.polcfg1 &= ~mask;
      EXINT0.polcfg2 |= mask;
    }

    this->mEventRise->onEdgeTriggerRise();

  } else if (EXINT0.polcfg2 & mask) {
    if (coreEdgeTriggerLevel & mask) {
      EXINT0.polcfg2 &= ~mask;
      EXINT0.polcfg1 |= mask;
    }

    this->mEventFall->onEdgeTriggerFall();
  }

  EXINT0.intsts |= mask;
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - mframe::hal::trigger::EventFall
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::onEdgeTriggerFall(void) {
  this->mStatusFall = true;
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - mframe::hal::trigger::EventRise
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::onEdgeTriggerRise(void) {
  this->mStatusRise = true;
  return;
}

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
