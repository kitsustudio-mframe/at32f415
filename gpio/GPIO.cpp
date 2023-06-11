/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./GPIO.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */
using chip::gpio::GPIO;

//-----------------------------------------------------------------------------------------
using chip::AT32F415;
using chip::crm::CRM;
using chip::crm::PeriphReset;
using chip::gpio::DriveMode;
using chip::gpio::Mode;
using chip::gpio::OutputMode;
using chip::gpio::PinConfig;
using chip::gpio::Pins;
using chip::gpio::PinsSource;
using chip::gpio::PortSource;
using chip::gpio::PullMode;
using chip::gpio::Register;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::gpio::GPIOA = *reinterpret_cast<Register*>(AT32F415::BASE_GPIOA);
Register& chip::gpio::GPIOB = *reinterpret_cast<Register*>(AT32F415::BASE_GPIOB);
Register& chip::gpio::GPIOC = *reinterpret_cast<Register*>(AT32F415::BASE_GPIOC);
Register& chip::gpio::GPIOD = *reinterpret_cast<Register*>(AT32F415::BASE_GPIOD);
Register& chip::gpio::GPIOF = *reinterpret_cast<Register*>(AT32F415::BASE_GPIOF);
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
void GPIO::reset(Register& reg) {
  uint32_t base = reinterpret_cast<uint32_t>(&reg);

  if (base == AT32F415::BASE_GPIOA) {
    CRM::periphReset(PeriphReset::RESET_GPIOA, true);
    CRM::periphReset(PeriphReset::RESET_GPIOA, false);

  } else if (base == AT32F415::BASE_GPIOB) {
    CRM::periphReset(PeriphReset::RESET_GPIOB, true);
    CRM::periphReset(PeriphReset::RESET_GPIOB, false);

  } else if (base == AT32F415::BASE_GPIOC) {
    CRM::periphReset(PeriphReset::RESET_GPIOC, true);
    CRM::periphReset(PeriphReset::RESET_GPIOC, false);

  } else if (base == AT32F415::BASE_GPIOD) {
    CRM::periphReset(PeriphReset::RESET_GPIOD, true);
    CRM::periphReset(PeriphReset::RESET_GPIOD, false);

  } else if (base == AT32F415::BASE_GPIOF) {
    CRM::periphReset(PeriphReset::RESET_GPIOF, true);
    CRM::periphReset(PeriphReset::RESET_GPIOF, false);
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void GPIO::init(Register& reg, PinConfig& pinConfig) {
  uint32_t temp;
  uint16_t pinx_value, pin_index;

  pin_index = static_cast<uint16_t>(pinConfig.pins);

  /* pinx_value indecate pin grounp bit[3:0] from modey[1:0] confy[1:0] */

  /* pin input analog config */
  if (pinConfig.mode == Mode::ANALOG) {
    pinx_value = 0x00;
  } else if (pinConfig.mode == Mode::INPUT) { /* pin input config */
    pinx_value = static_cast<uint8_t>(pinConfig.pullMode) & 0x0F;

    if (pinConfig.pullMode == PullMode::PULL_UP) {
      reg.scr = pin_index;
    } else if (pinConfig.pullMode == PullMode::PULL_DOWN) {
      reg.clr = pin_index;
    }
  } else {
    pinx_value = (static_cast<uint8_t>(pinConfig.mode) & 0x08) | (static_cast<uint8_t>(pinConfig.outputMode) & 0x04) |
                 (static_cast<uint8_t>(pinConfig.driveMode) & 0x03);
  }

  /* pin 0~7 config */
  if ((static_cast<uint32_t>(pin_index) & (static_cast<uint32_t>(0x00FF))) != 0x00) {
    for (temp = 0; temp < 0x08; temp++) {
      if ((1 << temp) & pin_index) {
        reg.cfglr &= static_cast<uint32_t>(~(0x0F << (temp * 4)));
        reg.cfglr |= static_cast<uint32_t>((pinx_value << (temp * 4)));
      }
    }
  }

  /* pin 8~15 config */
  if (pin_index > 0x00ff) {
    pin_index = pin_index >> 8;

    for (temp = 0; temp < 0x8; temp++) {
      if ((1 << temp) & pin_index) {
        reg.cfghr &= static_cast<uint32_t>(~(0xf << (temp * 4)));
        reg.cfghr |= static_cast<uint32_t>(pinx_value << (temp * 4));
      }
    }
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void GPIO::defaultParaInit(PinConfig& pinConfig) {
  /* reset gpio init structure parameters values */
  pinConfig.pins = static_cast<uint32_t>(Pins::ALL);
  pinConfig.mode = Mode::INPUT;
  pinConfig.outputMode = OutputMode::PUSHPULL;
  pinConfig.pullMode = PullMode::PULL_NONE;
  pinConfig.driveMode = DriveMode::STRONGER;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void GPIO::pinWpConfig(Register& reg, Pins pins) {
  uint32_t temp = 0x00010000;

  temp |= static_cast<uint32_t>(pins);
  /* set wpen bit */
  reg.wpr = temp;
  /* reset wpen bit */
  reg.wpr = static_cast<uint32_t>(pins);
  /* set wpen bit */
  reg.wpr = temp;
  /* read wpen bit*/
  temp = reg.wpr;
  /* read wpen bit*/
  temp = reg.wpr;
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
