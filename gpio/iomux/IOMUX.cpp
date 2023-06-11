/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./IOMUX.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"

/* ****************************************************************************************
 * Macro
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wswitch-enum"

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using chip::crm::CRM;
using chip::crm::PeriphReset;
using chip::gpio::iomux::IOMUX;
using chip::gpio::iomux::Register;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::gpio::iomux::IOMUX0 = *reinterpret_cast<Register*>(chip::AT32F415::BASE_IOMUX);

/* ****************************************************************************************
 * Construct Method
 */
IOMUX::IOMUX(void) {
  return;
}

IOMUX::~IOMUX(void) {
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
void IOMUX::iomuxReset(void) {
  CRM::periphReset(PeriphReset::RESET_IOMUX, true);
  CRM::periphReset(PeriphReset::RESET_IOMUX, false);
}

/** ---------------------------------------------------------------------------------------
 *
 */
void IOMUX::eventOutputConfig(PortSource portSource, PinsSource pinsSource) {
  uint32_t tmpreg = 0x00;

  tmpreg = IOMUX0.evtout;

  /* clear the port[6:4] and pin[3:0] bits */
  tmpreg &= 0x80;
  tmpreg |= (static_cast<uint32_t>(portSource) << 0x04);
  tmpreg |= static_cast<uint32_t>(pinsSource);
  IOMUX0.evtout = tmpreg;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void IOMUX::exintLineConfig(PortSource portSource, PinsSource pinsSource) {
  uint32_t tmp = 0x00;
  tmp = ((uint32_t)0x0F) << (0x04 * (static_cast<uint8_t>(pinsSource) & (uint8_t)0x03));

  switch (static_cast<uint8_t>(pinsSource) >> 0x02) {
    case 0:
      IOMUX0.exintc1 &= ~tmp;
      IOMUX0.exintc1 |= ((static_cast<uint32_t>(portSource)) << (0x04 * (static_cast<uint8_t>(pinsSource) & (uint8_t)0x03)));
      break;
    case 1:
      IOMUX0.exintc2 &= ~tmp;
      IOMUX0.exintc2 |= ((static_cast<uint32_t>(portSource)) << (0x04 * (static_cast<uint8_t>(pinsSource) & (uint8_t)0x03)));
      break;
    case 2:
      IOMUX0.exintc3 &= ~tmp;
      IOMUX0.exintc3 |= ((static_cast<uint32_t>(portSource)) << (0x04 * (static_cast<uint8_t>(pinsSource) & (uint8_t)0x03)));
      break;
    case 3:
      IOMUX0.exintc4 &= ~tmp;
      IOMUX0.exintc4 |= ((static_cast<uint32_t>(portSource)) << (0x04 * (static_cast<uint8_t>(pinsSource) & (uint8_t)0x03)));
      break;
    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void IOMUX::pinRemapConfig(PinMap pinMap, bool newState) {
  uint32_t reg_addr, remap_mask;
  uint8_t bit_offset, bit_num, bit_val;

  /* get register address, bit offset, bit number and remap value */
  reg_addr = AT32F415::BASE_IOMUX + (static_cast<uint32_t>(pinMap) >> 24);
  bit_offset = (static_cast<uint32_t>(pinMap) >> 16) & 0xFF;
  bit_num = (static_cast<uint32_t>(pinMap) >> 8) & 0xFF;
  bit_val = static_cast<uint32_t>(pinMap) & 0xFF;

  /* get remap mask value */
  remap_mask = 0xFFFFFFFF << (32 - bit_num - bit_offset);
  remap_mask = remap_mask >> (32 - bit_num - bit_offset);
  remap_mask = remap_mask >> bit_offset;
  remap_mask = remap_mask << bit_offset;

  /* clear remap value */
  *(uint32_t*)reg_addr &= ~remap_mask;

  if (newState != false) {
    /* set remap value */
    *(uint32_t*)reg_addr |= (uint32_t)(bit_val << bit_offset);
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

#pragma clang diagnostic pop
/* ****************************************************************************************
 * End of file
 */
