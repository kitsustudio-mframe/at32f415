/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./DMA.h"

//-----------------------------------------------------------------------------------------

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
using chip::dma::ChannelRegister;
using chip::dma::DMA;
using chip::dma::Register;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::dma::DMA1 = *reinterpret_cast<Register*>(chip::Processor::BASE_DMA1);
ChannelRegister& chip::dma::DMA1_CHANNEL1 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL1);
ChannelRegister& chip::dma::DMA1_CHANNEL2 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL2);
ChannelRegister& chip::dma::DMA1_CHANNEL3 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL3);
ChannelRegister& chip::dma::DMA1_CHANNEL4 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL4);
ChannelRegister& chip::dma::DMA1_CHANNEL5 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL5);
ChannelRegister& chip::dma::DMA1_CHANNEL6 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL6);
ChannelRegister& chip::dma::DMA1_CHANNEL7 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA1_CHANNEL7);

Register& chip::dma::DMA2 = *reinterpret_cast<Register*>(chip::Processor::BASE_DMA2);
ChannelRegister& chip::dma::DMA2_CHANNEL1 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL1);
ChannelRegister& chip::dma::DMA2_CHANNEL2 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL2);
ChannelRegister& chip::dma::DMA2_CHANNEL3 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL3);
ChannelRegister& chip::dma::DMA2_CHANNEL4 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL4);
ChannelRegister& chip::dma::DMA2_CHANNEL5 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL5);
ChannelRegister& chip::dma::DMA2_CHANNEL6 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL6);
ChannelRegister& chip::dma::DMA2_CHANNEL7 = *reinterpret_cast<ChannelRegister*>(chip::Processor::BASE_DMA2_CHANNEL7);
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
void DMA::reset(ChannelRegister& reg) {
  uint32_t temp = 0;
  reg.ctrl_bit.chen = false;
  reg.ctrl = 0;
  reg.dtcnt = 0;
  reg.paddr = 0;
  reg.maddr = 0;

  temp = reinterpret_cast<uint32_t>(&reg);

  if ((temp & 0x4ff) < 0x408) {
    /* dma1 channel */
    DMA1.clr |= (uint32_t)(0x0f << ((((temp & 0xff) - 0x08) / 0x14) * 4));
  } else if ((temp & 0x4ff) < 0x488) {
    /* dma2 channel */
    DMA2.clr |= (uint32_t)(0x0f << ((((temp & 0xff) - 0x08) / 0x14) * 4));
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void DMA::flexibleConfig(Register& reg, Channel channel, Flexible flexible) {
  if (reg.src_sel1_bit.dma_flex_en == false) {
    reg.src_sel1_bit.dma_flex_en = true;
  }

  switch (channel) {
    case Channel::CHANNEL1:
      reg.src_sel0_bit.ch1_src = static_cast<uint8_t>(flexible);
      break;
    case Channel::CHANNEL2:
      reg.src_sel0_bit.ch2_src = static_cast<uint8_t>(flexible);
      break;
    case Channel::CHANNEL3:
      reg.src_sel0_bit.ch3_src = static_cast<uint8_t>(flexible);
      break;
    case Channel::CHANNEL4:
      reg.src_sel0_bit.ch4_src = static_cast<uint8_t>(flexible);
      break;
    case Channel::CHANNEL5:
      reg.src_sel1_bit.ch5_src = static_cast<uint8_t>(flexible);
      break;
    case Channel::CHANNEL6:
      reg.src_sel1_bit.ch6_src = static_cast<uint8_t>(flexible);
      break;
    case Channel::CHANNEL7:
      reg.src_sel1_bit.ch7_src = static_cast<uint8_t>(flexible);
      break;
    default:
      break;
  }
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void DMA::defaultParaInit(Config& config) {
  config.peripheralBaseAddr = 0x0;
  config.memoryBaseAddr = 0x0;
  config.direction = Direction::PERIPHERAL_TO_MEMORY;
  config.bufferSize = 0x0;
  config.peripheralIncEnable = false;
  config.memoryIncEnable = false;
  config.peripheralDataWidth = PeripheralDataSize::BYTE;
  config.memoryDataWidth = MemoryDataSize::BYTE;
  config.loopModeEnable = false;
  config.priority = PriorityLevel::LOW;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void DMA::init(ChannelRegister& reg, Config& config) {
  /* clear ctrl register dtd bit and m2m bit */
  reg.ctrl &= 0xbfef;
  reg.ctrl |= static_cast<uint16_t>(config.direction);

  reg.ctrl_bit.chpl = static_cast<uint8_t>(config.priority);
  reg.ctrl_bit.mwidth = static_cast<uint8_t>(config.memoryDataWidth);
  reg.ctrl_bit.pwidth = static_cast<uint8_t>(config.peripheralDataWidth);
  reg.ctrl_bit.mincm = config.memoryIncEnable;
  reg.ctrl_bit.pincm = config.peripheralIncEnable;
  reg.ctrl_bit.lm = config.loopModeEnable;
  reg.dtcnt = config.bufferSize;
  reg.paddr = config.peripheralBaseAddr;
  reg.maddr = config.memoryBaseAddr;
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
