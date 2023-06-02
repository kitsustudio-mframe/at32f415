/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../crm/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./Core.h"
#include "./CoreEdgeTrigger.h"

/* ****************************************************************************************
 * namesapce;
 */
namespace at32f415::core {
  static uint32_t coreEdgeTriggerLevel = 0x00000000U;

  static void coreEdgeTriggerResetPeriph(uint32_t mask) {
    at32f415::exint::EXINT0.intsts |= static_cast<uint32_t>(mask);
    mask = ~mask;

    at32f415::exint::EXINT0.inten &= static_cast<uint32_t>(mask);
    at32f415::exint::EXINT0.evten &= static_cast<uint32_t>(mask);
    at32f415::exint::EXINT0.polcfg1 &= static_cast<uint32_t>(mask);
    at32f415::exint::EXINT0.polcfg2 &= static_cast<uint32_t>(mask);

    return;
  }

  static at32f415::core::CoreInterrupt::Irq getInterruptService(at32f415::exint::Line line) {
    switch (line) {
      //------------------------------------------
      case at32f415::exint::Line::LINE0:
        return at32f415::core::CoreInterrupt::IRQ_EXINT0;

      //------------------------------------------
      case at32f415::exint::Line::LINE1:
        return at32f415::core::CoreInterrupt::IRQ_EXINT1;

      //------------------------------------------
      case at32f415::exint::Line::LINE2:
        return at32f415::core::CoreInterrupt::IRQ_EXINT2;

      //------------------------------------------
      case at32f415::exint::Line::LINE3:
        return at32f415::core::CoreInterrupt::IRQ_EXINT3;

      //------------------------------------------
      case at32f415::exint::Line::LINE4:
        return at32f415::core::CoreInterrupt::IRQ_EXINT4;

      //------------------------------------------
      case at32f415::exint::Line::LINE5:
        return at32f415::core::CoreInterrupt::IRQ_EXINT5;

      //------------------------------------------
      case at32f415::exint::Line::LINE6:
        return at32f415::core::CoreInterrupt::IRQ_EXINT6;

      //------------------------------------------
      case at32f415::exint::Line::LINE7:
        return at32f415::core::CoreInterrupt::IRQ_EXINT7;

      //------------------------------------------
      case at32f415::exint::Line::LINE8:
        return at32f415::core::CoreInterrupt::IRQ_EXINT8;

      //------------------------------------------
      case at32f415::exint::Line::LINE9:
        return at32f415::core::CoreInterrupt::IRQ_EXINT9;

      //------------------------------------------
      case at32f415::exint::Line::LINE10:
        return at32f415::core::CoreInterrupt::IRQ_EXINT10;

      //------------------------------------------
      case at32f415::exint::Line::LINE11:
        return at32f415::core::CoreInterrupt::IRQ_EXINT11;

      //------------------------------------------
      case at32f415::exint::Line::LINE12:
        return at32f415::core::CoreInterrupt::IRQ_EXINT12;

      //------------------------------------------
      case at32f415::exint::Line::LINE13:
        return at32f415::core::CoreInterrupt::IRQ_EXINT13;

      //------------------------------------------
      case at32f415::exint::Line::LINE14:
        return at32f415::core::CoreInterrupt::IRQ_EXINT14;

      //------------------------------------------
      case at32f415::exint::Line::LINE15:
        return at32f415::core::CoreInterrupt::IRQ_EXINT15;

      //------------------------------------------
      case at32f415::exint::Line::LINE16:
        return at32f415::core::CoreInterrupt::IRQ_PVM;

      //------------------------------------------
      case at32f415::exint::Line::LINE17:
        return at32f415::core::CoreInterrupt::IRQ_ERTC_WKUP;

      //------------------------------------------
      case at32f415::exint::Line::LINE18:
        return at32f415::core::CoreInterrupt::IRQ_OTGFS_WAKE;

      //------------------------------------------
      case at32f415::exint::Line::LINE19:
        return at32f415::core::CoreInterrupt::IRQ_CMP1;

      //------------------------------------------
      case at32f415::exint::Line::LINE20:
        return at32f415::core::CoreInterrupt::IRQ_CMP2;

      //------------------------------------------
      case at32f415::exint::Line::LINE21:
        return at32f415::core::CoreInterrupt::IRQ_ERTC_ALARM;

      //------------------------------------------
      case at32f415::exint::Line::LINE22:
        return at32f415::core::CoreInterrupt::IRQ_ERTC_WKUP;
      
      default:
        return at32f415::core::CoreInterrupt::IRQ_MAX_QUANTITY;
    }
    
  }
}  // namespace at32f415::core

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using at32f415::core::CoreEdgeTrigger;
using at32f415::exint::EXINT0;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CoreEdgeTrigger::CoreEdgeTrigger(at32f415::exint::Line line) {
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
 * Public Method <Override> - hal::Base
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
 * Public Method <Override> - hal::trigger::EdgeTrigger
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
void CoreEdgeTrigger::setEventRise(hal::trigger::EventRise* event) {
  if(event)
    this->mEventRise = event;

  else
    this->mEventRise = this;

  return;
}

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::setEventFall(hal::trigger::EventFall* event) {
  if(event)
    this->mEventFall = event;

  else
    this->mEventFall = this;

  return;
}

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::readRise(void) {
  if(this->mStatusRise){
    this->mStatusRise = false;
    return true;
  }

  return false;
}

//-----------------------------------------------------------------------------------------
bool CoreEdgeTrigger::readFall(void) {
  if(this->mStatusFall){
    this->mStatusFall = false;
    return true;
  }

  return false;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::InterruptEvent
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::interruptEvent(void) {
  uint32_t mask = static_cast<uint32_t>(this->mLine);
  if(EXINT0.polcfg1 & mask){

    if(coreEdgeTriggerLevel & mask){
      EXINT0.polcfg1 &= ~mask;
      EXINT0.polcfg2 |= mask;
    }
    
    this->mEventRise->onEdgeTriggerRise();

  }else if(EXINT0.polcfg2 & mask){
    if(coreEdgeTriggerLevel & mask){
      EXINT0.polcfg2 &= ~mask;
      EXINT0.polcfg1 |= mask;
    }

    this->mEventFall->onEdgeTriggerFall();
  }

  EXINT0.intsts |= mask;
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::trigger::EventFall
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::onEdgeTriggerFall(void){
  this->mStatusFall = true;
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::trigger::EventRise
 */

//-----------------------------------------------------------------------------------------
void CoreEdgeTrigger::onEdgeTriggerRise(void){
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
