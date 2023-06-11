/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CoreUSART.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"
#include "mframe.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::core {
  static chip::crm::PeriphClock getPeriphClock(chip::usart::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      case chip::AT32F415::BASE_USART1:
        return crm::PeriphClock::USART1;

      case chip::AT32F415::BASE_USART2:
        return crm::PeriphClock::USART2;

      case chip::AT32F415::BASE_USART3:
        return crm::PeriphClock::USART3;

      case chip::AT32F415::BASE_UART4:
        return crm::PeriphClock::UART4;

      case chip::AT32F415::BASE_UART5:
        return crm::PeriphClock::UART5;
    }

    return crm::PeriphClock::NONE;
  }

  static chip::core::CoreInterrupt::Irq getInterruptService(chip::usart::Register& reg) {
    switch (reinterpret_cast<uint32_t>(&reg)) {
      case chip::AT32F415::BASE_USART1:
        return chip::core::CoreInterrupt::IRQ_USART1;

      case chip::AT32F415::BASE_USART2:
        return chip::core::CoreInterrupt::IRQ_USART2;

      case chip::AT32F415::BASE_USART3:
        return chip::core::CoreInterrupt::IRQ_USART3;

      case chip::AT32F415::BASE_UART4:
        return chip::core::CoreInterrupt::IRQ_UART4;

      case chip::AT32F415::BASE_UART5:
        return chip::core::CoreInterrupt::IRQ_UART5;
    }

    return chip::core::CoreInterrupt::IRQ_MAX_QUANTITY;
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
using chip::core::Core;
using chip::core::CoreUSART;
using chip::crm::CRM;
using chip::usart::DataBit;
using chip::usart::Interrupt;
using chip::usart::StopBit;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

CoreUSART::CoreUSART(chip::usart::Register& reg) : mReg(reg) {
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
 * Public Method <Override>  - mframe::hal::Base
 */

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::deinit(void) {
  if (!this->isInit())
    return false;

  chip::usart::USART::interruptEnable(this->mReg, chip::usart::Interrupt::TDBE, false);
  chip::usart::USART::interruptEnable(this->mReg, chip::usart::Interrupt::RDBF, false);
  Core::interrupt.irqEnable(getInterruptService(this->mReg), false);
  chip::usart::USART::reset(this->mReg);
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

  chip::usart::USART::init(this->mReg, this->mBaudrate, DataBit::BITS8, StopBit::BIT_1_0);

  Core::interrupt.irqEnable(getInterruptService(this->mReg), true);
  chip::usart::USART::interruptEnable(this->mReg, Interrupt::RDBF, true);
  chip::usart::USART::enable(this->mReg, true);
  chip::usart::USART::transmitterEnable(this->mReg, true);
  chip::usart::USART::receiverEnable(this->mReg, true);
  return true;
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool CoreUSART::isInit(void) {
  return CRM::getPeriphClockEnable(chip::core::getPeriphClock(this->mReg));
}

/* ****************************************************************************************
 * Public Method <Override>  - mframe::hal::usart::USART
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

  if (reinterpret_cast<uint32_t>(&this->mReg) == chip::AT32F415::BASE_USART1) {
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
    chip::usart::USART::interruptEnable(this->mReg, chip::usart::Interrupt::TDBE, enable);

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::beginReceiver(bool enable) {
  if (this->isInit())
    chip::usart::USART::interruptEnable(this->mReg, chip::usart::Interrupt::RDBF, enable);

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::setEventTransfer(mframe::hal::usart::EventTransfer* event) {
  if (event)
    this->mEventTransfer = event;

  else
    this->mEventTransfer = this;

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::setEventReceiver(mframe::hal::usart::EventReceiver* event) {
  if (event)
    this->mEventReceiver = event;

  else
    this->mEventReceiver = this;

  return;
}

/* ****************************************************************************************
 * Public Method <Override>  - mframe::hal::InterruptEvent
 */

/** ---------------------------------------------------------------------------------------
 *
 */
void CoreUSART::interruptEvent(void) {
  if (chip::usart::USART::flagGet(this->mReg, chip::usart::Flag::RDBF)) {
    uint16_t readCache = chip::usart::USART::dataReceive(this->mReg);
    this->mEventReceiver->onUartReceiver(static_cast<uint8_t>(readCache));
  }

  // send handle
  if (chip::usart::USART::flagGet(this->mReg, chip::usart::Flag::TDBE)) {
    uint8_t data;

    if (this->mEventTransfer->onUartTransfer(data)) {
      /* Write one byte to the transmit data register */
      chip::usart::USART::dataTransmit(this->mReg, data);

    } else {
      chip::usart::USART::interruptEnable(this->mReg, chip::usart::Interrupt::TDBE, false);
    }
  }
}

/* ****************************************************************************************
 * Public Method <Override>  - mframe::hal::InterruptEvent
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
