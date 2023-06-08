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
#include "./../Chip.h"
#include "./Core.h"
#include "at32f415/core/CoreTimer.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::core {
  static at32f415::crm::PeriphClock getPeriphClock(at32f415::tmr::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      //------------------------------------------
      case Chip::BASE_TMR1:
        return at32f415::crm::PeriphClock::TMR1;

      //------------------------------------------
      case Chip::BASE_TMR2:
        return at32f415::crm::PeriphClock::TMR2;

      //------------------------------------------
      case Chip::BASE_TMR3:
        return at32f415::crm::PeriphClock::TMR3;

      //------------------------------------------
      case Chip::BASE_TMR4:
        return at32f415::crm::PeriphClock::TMR4;

      //------------------------------------------
      case Chip::BASE_TMR5:
        return at32f415::crm::PeriphClock::TMR5;

      //------------------------------------------
      case Chip::BASE_TMR9:
        return at32f415::crm::PeriphClock::TMR9;

      //------------------------------------------
      case Chip::BASE_TMR10:
        return at32f415::crm::PeriphClock::TMR10;

      //------------------------------------------
      case Chip::BASE_TMR11:
        return at32f415::crm::PeriphClock::TMR11;
    }

    return at32f415::crm::PeriphClock::NONE;
  }

  static at32f415::core::CoreInterrupt::Irq getInterruptService(at32f415::tmr::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      //------------------------------------------
      case Chip::BASE_TMR1:
        return at32f415::core::CoreInterrupt::IRQ_TMR1;

      //------------------------------------------
      case Chip::BASE_TMR2:
        return at32f415::core::CoreInterrupt::IRQ_TMR2;

      //------------------------------------------
      case Chip::BASE_TMR3:
        return at32f415::core::CoreInterrupt::IRQ_TMR3;

      //------------------------------------------
      case Chip::BASE_TMR4:
        return at32f415::core::CoreInterrupt::IRQ_TMR4;

      //------------------------------------------
      case Chip::BASE_TMR5:
        return at32f415::core::CoreInterrupt::IRQ_TMR5;

      //------------------------------------------
      case Chip::BASE_TMR9:
        return at32f415::core::CoreInterrupt::IRQ_TMR9;

      //------------------------------------------
      case Chip::BASE_TMR10:
        return at32f415::core::CoreInterrupt::IRQ_TMR10;

      //------------------------------------------
      case Chip::BASE_TMR11:
        return at32f415::core::CoreInterrupt::IRQ_TMR11;
    }

    return at32f415::core::CoreInterrupt::IRQ_MAX_QUANTITY;
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
using at32f415::core::CoreTimer;
using at32f415::crm::CRM;
using at32f415::tmr::TMR;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */
//-----------------------------------------------------------------------------------------
CoreTimer::CoreTimer(at32f415::tmr::Register& reg) : mReg(reg) {
  this->mEventCancel = nullptr;
  this->mEventTrigger = nullptr;
  return;
}

//-----------------------------------------------------------------------------------------
CoreTimer::~CoreTimer(void) {
  this->cancel();
  this->deinit();
  this->mEventCancel = nullptr;
  this->mEventTrigger = nullptr;
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
bool CoreTimer::deinit(void) {
  if (!this->isInit())
    return false;

  Core::interrupt.irqEnable(getInterruptService(this->mReg), false);
  Core::interrupt.setHandler(getInterruptService(this->mReg), nullptr);
  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::init(void) {
  if (this->isInit())
    return false;

  CRM::periphClockEnable(getPeriphClock(this->mReg), true);
  Core::interrupt.setHandler(getInterruptService(this->mReg), this);
  return false;
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::isInit(void) {
  return CRM::getPeriphClockEnable(getPeriphClock(this->mReg));
}

/* ****************************************************************************************
 * Public Method <Override> - hal::timer::Timer
 */

//-----------------------------------------------------------------------------------------
void CoreTimer::cancel(void) {
  Core::interrupt.irqEnable(getInterruptService(this->mReg), false);
  TMR::interruptEnable(this->mReg, at32f415::tmr::Interrupt::OVF, false);
  this->mEventCancel->onTimerCancel();
  return;
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::isBusy(void) {
  return this->mReg.swevt_bit.ovfswtr;
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::isDone(void) {
  if (this->mReg.ists_bit.ovfif) {
    this->mReg.ists_bit.ovfif = false;
    return true;
  }
  return false;
}

//-----------------------------------------------------------------------------------------
void CoreTimer::waitDone(void) {
  while (this->mReg.ists_bit.ovfif) {
  }
  this->mReg.ists_bit.ovfif = false;
  return;
}

//-----------------------------------------------------------------------------------------
uint32_t CoreTimer::getTimerClock(void) {
  return Core::getSystemCoreClock();
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::startAtTick(uint32_t tick) {
  if (this->isBusy())
    return false;

  this->resetTick(tick);

  TMR::cntDirSet(this->mReg, at32f415::tmr::CountMode::UP);
  TMR::clockSourceDivSet(this->mReg, at32f415::tmr::ClockDivision::DIV1);

  TMR::interruptEnable(this->mReg, tmr::Interrupt::OVF, true);
  TMR::counterEnable(this->mReg, true);
  Core::interrupt.irqEnable(getInterruptService(this->mReg), true);
  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::startAtTime(float second) {
  at32f415::crm::CoreClock coreClock;
  at32f415::crm::CRM::clocksFreqGet(coreClock);
  
  uint32_t sourceClock = coreClock.apb2_freq;

  switch (reinterpret_cast<uint32_t>(&this->mReg)) {
    //------------------------------------------
    case Chip::BASE_TMR1:
      sourceClock = coreClock.apb2_freq;
      break;

    //------------------------------------------
    case Chip::BASE_TMR2:
      sourceClock = coreClock.apb1_freq;
      break;
    //------------------------------------------
    case Chip::BASE_TMR3:
      sourceClock = coreClock.apb1_freq;
      break;

    //------------------------------------------
    case Chip::BASE_TMR4:
      sourceClock = coreClock.apb1_freq;
      break;

    //------------------------------------------
    case Chip::BASE_TMR5:
      sourceClock = coreClock.apb1_freq;
      break;

    //------------------------------------------
    case Chip::BASE_TMR9:
      sourceClock = coreClock.apb2_freq;
      break;

    //------------------------------------------
    case Chip::BASE_TMR10:
      sourceClock = coreClock.apb2_freq;
      break;

    //------------------------------------------
    case Chip::BASE_TMR11:
      sourceClock = coreClock.apb2_freq;
      break;
  }

  return this->startAtTick(static_cast<uint32_t>(static_cast<float>(sourceClock) * second));
}

//-----------------------------------------------------------------------------------------
bool CoreTimer::startAtHertz(float hertz) {
  return this->startAtTime(1.0f / hertz);
}

//-----------------------------------------------------------------------------------------
void CoreTimer::resetTick(uint32_t tick) {
  uint32_t div = 1 + (tick >> 16);
  uint32_t period = (tick / div);
  TMR::baseInit(this->mReg, period, div);
}

//-----------------------------------------------------------------------------------------
void CoreTimer::CoreTimer::setEventTrigger(hal::timer::EventTrigger* event) {
  if (event == nullptr)
    this->mEventTrigger = this;

  else
    this->mEventTrigger = event;

  return;
}

//-----------------------------------------------------------------------------------------
void CoreTimer::setEventCancel(hal::timer::EventCancel* event) {
  if (event == nullptr)
    this->mEventCancel = this;

  else {
    this->mEventCancel = event;
    if (this->isBusy())
      TMR::interruptEnable(this->mReg, tmr::Interrupt::OVF, true);
  }

  return;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::InterruptEvent
 */

//-----------------------------------------------------------------------------------------
void CoreTimer::interruptEvent(void) {
  if (TMR::flagGet(this->mReg, at32f415::tmr::Flag::OVF) == false)
    return;

  TMR::flagClear(this->mReg, at32f415::tmr::Flag::OVF);

  this->mEventTrigger->onTimerTrigger();
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::timer::EventCancel
 */

//-----------------------------------------------------------------------------------------
void CoreTimer::onTimerCancel(void) {
  return;
}

/* ****************************************************************************************
 * Public Method <Override> - hal::timer::EventTrigger
 */

//-----------------------------------------------------------------------------------------
void CoreTimer::onTimerTrigger(void) {
  TMR::interruptEnable(this->mReg, at32f415::tmr::Interrupt::OVF, false);
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
