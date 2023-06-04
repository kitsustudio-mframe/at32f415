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
#include "./CoreInterrupt.h"
#include "./CoreUSART.h"
#include "hal/InterruptEvent.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::core {
  static at32f415::crm::PeriphClock getPeriphClock(at32f415::usart::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      case Chip::BASE_USART1:
        return crm::PeriphClock::USART1;

      case Chip::BASE_USART2:
        return crm::PeriphClock::USART2;

      case Chip::BASE_USART3:
        return crm::PeriphClock::USART3;

      case Chip::BASE_UART4:
        return crm::PeriphClock::UART4;

      case Chip::BASE_UART5:
        return crm::PeriphClock::UART5;
    }

    return crm::PeriphClock::NONE;
  }

  static at32f415::core::CoreInterrupt::Irq getInterruptService(at32f415::usart::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      case Chip::BASE_USART1:
        return at32f415::core::CoreInterrupt::IRQ_USART1;

      case Chip::BASE_USART2:
        return at32f415::core::CoreInterrupt::IRQ_USART2;

      case Chip::BASE_USART3:
        return at32f415::core::CoreInterrupt::IRQ_USART3;

      case Chip::BASE_UART4:
        return at32f415::core::CoreInterrupt::IRQ_UART4;

      case Chip::BASE_UART5:
        return at32f415::core::CoreInterrupt::IRQ_UART5;
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
using at32f415::core::Core;
using at32f415::core::CoreUSART;
using at32f415::crm::CRM;
using at32f415::usart::DataBit;
using at32f415::usart::Interrupt;
using at32f415::usart::StopBit;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

CoreUSART::CoreUSART(at32f415::usart::Register& reg) : mReg(reg) {
  this->mBaudrate = 9600;
  return;
}

CoreUSART::~CoreUSART(void) {
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
 * Public Method <Override>  - hal::Base
 */

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::deinit(void) {
  if (!this->isInit())
    return false;
  
  at32f415::usart::USART::interruptEnable(this->mReg, at32f415::usart::Interrupt::TDBE, false);
  at32f415::usart::USART::interruptEnable(this->mReg, at32f415::usart::Interrupt::RDBF, false);
  Core::interrupt.irqEnable(getInterruptService(this->mReg), false);
  at32f415::usart::USART::reset(this->mReg);
  CRM::periphClockEnable(getPeriphClock(this->mReg), false);
  Core::interrupt.setHandler(getInterruptService(this->mReg), nullptr);
  return true;
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::init(void) {
  if (this->isInit())
    return false;

  CRM::periphClockEnable(getPeriphClock(this->mReg), true);
  Core::interrupt.setHandler(getInterruptService(this->mReg), this);

  at32f415::usart::USART::init(this->mReg, this->mBaudrate, DataBit::BITS8, StopBit::BIT_1_0);

  Core::interrupt.irqEnable(getInterruptService(this->mReg), true);
  at32f415::usart::USART::interruptEnable(this->mReg, Interrupt::RDBF, true);
  at32f415::usart::USART::enable(this->mReg, true);
  at32f415::usart::USART::transmitterEnable(this->mReg, true);
  at32f415::usart::USART::receiverEnable(this->mReg, true);
  return true;
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::isInit(void) {
  return CRM::getPeriphClockEnable(at32f415::core::getPeriphClock(this->mReg));
}

/* ****************************************************************************************
 * Public Method <Override>  - hal::usart::USART
 */

/** ---------------------------------------------------------------------------------------
 *
 */
uint32_t CoreUSART::setBaudrate(uint32_t baudrate) {
  this->mBaudrate = baudrate;
  if (this->isInit()) {
    this->deinit();
    this->init();
  }

  return this->getBaudrate();
}
/** ---------------------------------------------------------------------------------------
 *
 */
uint32_t CoreUSART::getBaudrate(void) {
  crm::CoreClock clocks_freq;
  uint32_t apb_clock;
  CRM::clocksFreqGet(clocks_freq);

  if (reinterpret_cast<uint32_t>(&this->mReg) == Chip::BASE_USART1) {
    apb_clock = clocks_freq.apb2_freq;

  } else {
    apb_clock = clocks_freq.apb1_freq;
  }
  return (apb_clock / this->mReg.baudr_bit.div);
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::beginTransfer(bool enable) {
  if (this->isInit())
    at32f415::usart::USART::interruptEnable(this->mReg, at32f415::usart::Interrupt::TDBE, enable);
    
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::beginReceiver(bool enable) {
  if (this->isInit())
    at32f415::usart::USART::interruptEnable(this->mReg, at32f415::usart::Interrupt::RDBF, enable);

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::setEventTransfer(hal::usart::EventTransfer* event) {
  if (event)
    this->mEventTransfer = event;

  else
    this->mEventTransfer = this;

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::setEventReceiver(hal::usart::EventReceiver* event) {
  if (event)
    this->mEventReceiver = event;

  else
    this->mEventReceiver = this;

  return;
}

/* ****************************************************************************************
 * Public Method <Override>  - hal::InterruptEvent
 */

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::interruptEvent(void) {
  if (at32f415::usart::USART::flagGet(this->mReg, at32f415::usart::Flag::RDBF)) {
    uint16_t readCache = at32f415::usart::USART::dataReceive(this->mReg);
    this->mEventReceiver->onUartReceiver(static_cast<uint8_t>(readCache));
  }

  // send handle
  if (at32f415::usart::USART::flagGet(this->mReg, at32f415::usart::Flag::TDBE)) {
    uint8_t data;

    if (this->mEventTransfer->onUartTransfer(data)) {
      /* Write one byte to the transmit data register */
      at32f415::usart::USART::dataTransmit(this->mReg, data);

    } else {
      at32f415::usart::USART::interruptEnable(this->mReg, at32f415::usart::Interrupt::TDBE, false);
    }
  }
}

/* ****************************************************************************************
 * Public Method <Override>  - hal::InterruptEvent
 */

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::onUartReceiver(const uint8_t data) {
  return false;
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::onUartTransfer(uint8_t& data) {
  return false;
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
