/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#define USING_CHIP_CRM
#include "chip.h"

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
#include "./USART.h"

/* ****************************************************************************************
 * Macro
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wswitch-enum"

#define getBase(x) reinterpret_cast<uint32_t>(&x)

#define REG8(addr) *(volatile uint8_t*)(addr)
#define REG16(addr) *(volatile uint16_t*)(addr)
#define REG32(addr) *(volatile uint32_t*)(addr)

#define PERIPH_REG(periph_base, value) REG32((periph_base + (value >> 16)))
#define PERIPH_REG_BIT(value) (0x1U << (value & 0x1F))

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using chip::crm::CoreClock;
using chip::crm::CRM;
using chip::crm::PeriphReset;
using chip::usart::Register;
using chip::usart::USART;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::usart::USART1 = *reinterpret_cast<Register*>(chip::Processor::BASE_USART1);
Register& chip::usart::USART2 = *reinterpret_cast<Register*>(chip::Processor::BASE_USART2);
Register& chip::usart::USART3 = *reinterpret_cast<Register*>(chip::Processor::BASE_USART3);
Register& chip::usart::UART4 = *reinterpret_cast<Register*>(chip::Processor::BASE_UART4);
Register& chip::usart::UART5 = *reinterpret_cast<Register*>(chip::Processor::BASE_UART5);
/* ****************************************************************************************
 * Construct Method
 */

/** ---------------------------------------------------------------------------------------
 *
 */
USART::USART(void) {
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
USART::~USART(void) {
  return;
}
/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/** ---------------------------------------------------------------------------------------
 *
 */
void USART::reset(Register& reg) {
  if (getBase(reg) == Processor::BASE_USART1) {
    CRM::periphReset(PeriphReset::RESET_USART1, true);
    CRM::periphReset(PeriphReset::RESET_USART1, false);

  } else if (getBase(reg) == Processor::BASE_USART2) {
    CRM::periphReset(PeriphReset::RESET_USART2, true);
    CRM::periphReset(PeriphReset::RESET_USART2, false);

  } else if (getBase(reg) == Processor::BASE_USART3) {
    CRM::periphReset(PeriphReset::RESET_USART3, true);
    CRM::periphReset(PeriphReset::RESET_USART3, false);

  } else if (getBase(reg) == Processor::BASE_UART4) {
    CRM::periphReset(PeriphReset::RESET_UART4, true);
    CRM::periphReset(PeriphReset::RESET_UART4, false);
  } else if (getBase(reg) == Processor::BASE_UART5) {
    CRM::periphReset(PeriphReset::RESET_UART5, true);
    CRM::periphReset(PeriphReset::RESET_UART5, false);
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void USART::init(Register& reg, uint32_t baudrate, DataBit dataBit, StopBit stopBit) {
  CoreClock clocks_freq;
  uint32_t apb_clock, temp_val;
  CRM::clocksFreqGet(clocks_freq);

  if (getBase(reg) == Processor::BASE_USART1) {
    apb_clock = clocks_freq.apb2_freq;

  } else {
    apb_clock = clocks_freq.apb1_freq;
  }

  temp_val = (apb_clock * 10 / baudrate);

  if ((temp_val % 10) < 5) {
    temp_val = (temp_val / 10);

  } else {
    temp_val = (temp_val / 10) + 1;
  }
  reg.baudr_bit.div = temp_val;
  reg.ctrl1_bit.dbn = static_cast<uint8_t>(dataBit);
  reg.ctrl2_bit.stopbn = static_cast<uint8_t>(stopBit);
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void USART::paritySelectionConfig(Register& reg, ParitySelection parity) {
  if (parity == ParitySelection::NONE) {
    reg.ctrl1_bit.psel = false;
    reg.ctrl1_bit.pen = false;
  } else if (parity == ParitySelection::EVEN) {
    reg.ctrl1_bit.psel = false;
    reg.ctrl1_bit.pen = true;
  } else if (parity == ParitySelection::ODD) {
    reg.ctrl1_bit.psel = true;
    reg.ctrl1_bit.pen = true;
  }

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void USART::clockConfig(Register& reg, ClockPolarity clockPolarity, ClockPhase clockPhase, ClockLast clockLast) {
  reg.ctrl2_bit.clkpol = static_cast<uint8_t>(clockPolarity);
  reg.ctrl2_bit.clkpha = static_cast<uint8_t>(clockPhase);
  reg.ctrl2_bit.lbcp = static_cast<uint8_t>(clockLast);
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void USART::interruptEnable(Register& reg, Interrupt interrupt, bool newState) {
  uint32_t usartInt = static_cast<uint32_t>(interrupt);

  if (newState == true)
    PERIPH_REG(getBase(reg), usartInt) |= PERIPH_REG_BIT(usartInt);

  else
    PERIPH_REG(getBase(reg), usartInt) &= ~PERIPH_REG_BIT(usartInt);

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void USART::hardwareFlowControlSet(Register& reg, HardwareFlow hardwareFlow) {
  switch (hardwareFlow) {
    //---------------------------------------------------------------------------------
    case HardwareFlow::NONE:
      reg.ctrl3_bit.rtsen = false;
      reg.ctrl3_bit.ctsen = false;
      break;
    //---------------------------------------------------------------------------------
    case HardwareFlow::RTS:
      reg.ctrl3_bit.rtsen = true;
      reg.ctrl3_bit.ctsen = false;
      break;
    //---------------------------------------------------------------------------------
    case HardwareFlow::CTS:
      reg.ctrl3_bit.rtsen = false;
      reg.ctrl3_bit.ctsen = true;
      break;
    //---------------------------------------------------------------------------------
    case HardwareFlow::RTS_CTS:
      reg.ctrl3_bit.rtsen = true;
      reg.ctrl3_bit.ctsen = true;
      break;
  }

  return;
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

#pragma clang diagnostic pop
/* ****************************************************************************************
 * End of file
 */
