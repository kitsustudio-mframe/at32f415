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

//-----------------------------------------------------------------------------------------
#include "./TMR.h"

#include "./../crm/package-info.h"

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
using chip::tmr::Register;
using chip::tmr::TMR;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::tmr::TMR1 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR1);
Register& chip::tmr::TMR2 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR2);
Register& chip::tmr::TMR3 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR3);
Register& chip::tmr::TMR4 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR4);
Register& chip::tmr::TMR5 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR5);
Register& chip::tmr::TMR9 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR9);
Register& chip::tmr::TMR10 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR10);
Register& chip::tmr::TMR11 = *reinterpret_cast<Register*>(chip::Processor::BASE_TMR11);
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
void TMR::reset(Register& reg) {
  if (compReg(reg, TMR1)) {
    CRM::periphReset(PeriphReset::RESET_TMR1, true);
    CRM::periphReset(PeriphReset::RESET_TMR1, false);

  } else if (compReg(reg, TMR2)) {
    CRM::periphReset(PeriphReset::RESET_TMR2, true);
    CRM::periphReset(PeriphReset::RESET_TMR2, false);

  } else if (compReg(reg, TMR3)) {
    CRM::periphReset(PeriphReset::RESET_TMR3, true);
    CRM::periphReset(PeriphReset::RESET_TMR3, false);

  } else if (compReg(reg, TMR4)) {
    CRM::periphReset(PeriphReset::RESET_TMR4, true);
    CRM::periphReset(PeriphReset::RESET_TMR4, false);

  } else if (compReg(reg, TMR5)) {
    CRM::periphReset(PeriphReset::RESET_TMR5, true);
    CRM::periphReset(PeriphReset::RESET_TMR5, false);

  } else if (compReg(reg, TMR9)) {
    CRM::periphReset(PeriphReset::RESET_TMR9, true);
    CRM::periphReset(PeriphReset::RESET_TMR9, false);

  } else if (compReg(reg, TMR10)) {
    CRM::periphReset(PeriphReset::RESET_TMR10, true);
    CRM::periphReset(PeriphReset::RESET_TMR10, false);

  } else if (compReg(reg, TMR11)) {
    CRM::periphReset(PeriphReset::RESET_TMR11, true);
    CRM::periphReset(PeriphReset::RESET_TMR11, false);
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputDefaultParaInit(output::Config& outputStruct) {
  outputStruct.outputControlMode = output::ControlMode::OFF;
  outputStruct.ocIdleState = false;
  outputStruct.occIdleState = false;
  outputStruct.ocPolarity = output::Polarity::ACTIVE_HIGH;
  outputStruct.occPolarity = output::Polarity::ACTIVE_HIGH;
  outputStruct.ocOutputState = false;
  outputStruct.occOutputState = false;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::inputDefaultParaInit(input::Config& inputStruct) {
  inputStruct.channelSelect = channel::Select::CHANNEL1;
  inputStruct.inputPolarity = input::Polarity::RISING_EDGE;
  inputStruct.inputDirectionMapped = input::DirectionMapped::DIRECT;
  inputStruct.inputFilterValue = 0x0;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::brkdtDefaultParaInit(BreakDutyConfig& breakDutyConfig) {
  breakDutyConfig.deadtime = 0x0;
  breakDutyConfig.breakPolarity = BreakPolarity::ACTIVE_LOW;
  breakDutyConfig.writeProtectLevel = WriteProtectLevel::OFF;
  breakDutyConfig.autoOutputEnable = false;
  breakDutyConfig.fcsoenState = false;
  breakDutyConfig.fcsodisState = false;
  breakDutyConfig.brkEnable = false;
  return;
}
/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::baseInit(Register& reg, uint32_t pr, uint32_t div) {
  /* set the pr value */
  reg.pr = pr;

  /* set the div value */
  reg.div = div;

  /* trigger the overflow event to immediately reload pr value and div value */
  reg.swevt_bit.ovfswtr = true;

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::repetitionCounterSet(Register& reg, uint8_t rprValue) {
  /* set the repetition counter value */
  if (compReg(reg, TMR1))
    reg.rpr_bit.rpr = rprValue;
}
/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputChannelConfig(Register& reg, channel::Select channel, output::Config& config) {
  uint16_t index = 0;
  uint16_t index_c = 0;

  /* get channel idle state bit position in ctrl2 register */
  index = static_cast<uint16_t>(config.ocIdleState << (8 + static_cast<uint8_t>(channel)));

  /* get channel complementary idle state bit position in ctrl2 register */
  index_c = static_cast<uint16_t>(config.occIdleState << (9 + static_cast<uint8_t>(channel)));

  if (compReg(reg, TMR1)) {
    /* set output channel complementary idle state */
    reg.ctrl2 &= ~index_c;
    reg.ctrl2 |= index_c;
  }

  /* set output channel idle state */
  reg.ctrl2 &= ~index;
  reg.ctrl2 |= index;

  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_output_bit.c1octrl = static_cast<uint8_t>(config.outputControlMode);
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_output_bit.c2octrl = static_cast<uint8_t>(config.outputControlMode);
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_output_bit.c3octrl = static_cast<uint8_t>(config.outputControlMode);
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_output_bit.c4octrl = static_cast<uint8_t>(config.outputControlMode);
      break;

    default:
      break;
  }

  /* get channel polarity bit position in cctrl register */
  index = static_cast<uint16_t>(static_cast<uint16_t>(config.ocPolarity) << ((static_cast<uint8_t>(channel) * 2) + 1));

  /* get channel complementary polarity bit position in cctrl register */
  index_c = static_cast<uint16_t>(static_cast<uint16_t>(config.ocPolarity) << ((static_cast<uint8_t>(channel) * 2) + 3));

  if (compReg(reg, TMR1)) {
    /* set output channel complementary polarity */
    reg.cctrl &= ~index_c;
    reg.cctrl |= index_c;
  }

  /* set output channel polarity */
  reg.cctrl &= ~index;
  reg.cctrl |= index;

  /* get channel enable bit position in cctrl register */
  index = static_cast<uint16_t>(config.ocOutputState << (static_cast<uint8_t>(channel) * 2));

  /* get channel complementary enable bit position in cctrl register */
  index_c = static_cast<uint16_t>(config.occOutputState << ((static_cast<uint8_t>(channel) * 2) + 2));

  if (compReg(reg, TMR1)) {
    /* set output channel complementary enable bit */
    reg.cctrl &= ~index_c;
    reg.cctrl |= index_c;
  }

  /* set output channel enable bit */
  reg.cctrl &= ~index;
  reg.cctrl |= index;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputChannelModeSelect(Register& reg, channel::Select channel, output::ControlMode ocMode) {
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_output_bit.c1octrl = static_cast<uint8_t>(ocMode);
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_output_bit.c2octrl = static_cast<uint8_t>(ocMode);
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_output_bit.c3octrl = static_cast<uint8_t>(ocMode);
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_output_bit.c4octrl = static_cast<uint8_t>(ocMode);
      break;

    default:
      break;
  }
}
/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::channelValueSet(Register& reg, channel::Select channel, uint32_t channelValue) {
  /* set tmr channel value */
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.c1dt = channelValue;
      break;

    case channel::Select::CHANNEL2:
      reg.c2dt = channelValue;
      break;

    case channel::Select::CHANNEL3:
      reg.c3dt = channelValue;
      break;

    case channel::Select::CHANNEL4:
      reg.c4dt = channelValue;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
uint32_t TMR::channelValueGet(Register& reg, channel::Select channel) {
  uint32_t result = 0;

  /* get tmr channel value */
  switch (channel) {
    case channel::Select::CHANNEL1:
      result = reg.c1dt;
      break;

    case channel::Select::CHANNEL2:
      result = reg.c2dt;
      break;

    case channel::Select::CHANNEL3:
      result = reg.c3dt;
      break;

    case channel::Select::CHANNEL4:
      result = reg.c4dt;
      break;

    default:
      break;
  }

  return result;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputChannelBufferEnable(Register& reg, channel::Select channel, bool newState) {
  /* get tmr channel value */
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_output_bit.c1oben = newState;
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_output_bit.c2oben = newState;
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_output_bit.c3oben = newState;
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_output_bit.c4oben = newState;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputChannelImmediatelySet(Register& reg, channel::Select channel, bool newState) {
  /* get tmr channel value */
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_output_bit.c1oien = newState;
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_output_bit.c2oien = newState;
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_output_bit.c3oien = newState;
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_output_bit.c4oien = newState;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputChannelSwitchSet(Register& reg, channel::Select channel, bool newState) {
  /* get tmr channel value */
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_output_bit.c1osen = newState;
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_output_bit.c2osen = newState;
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_output_bit.c3osen = newState;
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_output_bit.c4osen = newState;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::bit32FunctionEnable(Register& reg, bool newState) {
  /* tmr 32 bit function(plus mode) enable,only for TMR2/TMR5 */
  if (compReg(reg, TMR2) || compReg(reg, TMR5))
    reg.ctrl1_bit.pmen = newState;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::inputChannelInit(Register& reg, input::Config& config, input::Divider divider) {
  switch (config.channelSelect) {
    case channel::Select::CHANNEL1:
      reg.cctrl_bit.c1p = static_cast<uint32_t>(config.inputPolarity);
      reg.cctrl_bit.c1cp = (static_cast<uint8_t>(config.inputPolarity) & 0x2) >> 1;
      reg.cm1_input_bit.c1c = static_cast<uint8_t>(config.inputDirectionMapped);
      reg.cm1_input_bit.c1df = config.inputFilterValue;
      reg.cm1_input_bit.c1idiv = static_cast<uint8_t>(divider);
      reg.cctrl_bit.c1en = true;
      break;

    case channel::Select::CHANNEL2:
      reg.cctrl_bit.c2p = static_cast<uint32_t>(config.inputPolarity);
      reg.cctrl_bit.c2cp = (static_cast<uint8_t>(config.inputPolarity) & 0x2) >> 1;
      reg.cm1_input_bit.c2c = static_cast<uint8_t>(config.inputDirectionMapped);
      reg.cm1_input_bit.c2df = config.inputFilterValue;
      reg.cm1_input_bit.c2idiv = static_cast<uint8_t>(divider);
      reg.cctrl_bit.c2en = true;
      break;

    case channel::Select::CHANNEL3:
      reg.cctrl_bit.c3p = static_cast<uint32_t>(config.inputPolarity);
      reg.cctrl_bit.c3cp = (static_cast<uint8_t>(config.inputPolarity) & 0x2) >> 1;
      reg.cm2_input_bit.c3c = static_cast<uint8_t>(config.inputDirectionMapped);
      reg.cm2_input_bit.c3df = config.inputFilterValue;
      reg.cm2_input_bit.c3idiv = static_cast<uint8_t>(divider);
      reg.cctrl_bit.c3en = true;
      break;

    case channel::Select::CHANNEL4:
      reg.cctrl_bit.c4p = static_cast<uint32_t>(config.inputPolarity);
      reg.cm2_input_bit.c4c = static_cast<uint8_t>(config.inputPolarity);
      reg.cm2_input_bit.c4df = config.inputFilterValue;
      reg.cm2_input_bit.c4idiv = static_cast<uint8_t>(divider);
      reg.cctrl_bit.c4en = true;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::channelEnable(Register& reg, channel::Select channel, bool newState) {
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cctrl_bit.c1en = newState;
      break;

    case channel::Select::CHANNEL1C:
      reg.cctrl_bit.c1cen = newState;
      break;

    case channel::Select::CHANNEL2:
      reg.cctrl_bit.c2en = newState;
      break;

    case channel::Select::CHANNEL2C:
      reg.cctrl_bit.c2cen = newState;
      break;

    case channel::Select::CHANNEL3:
      reg.cctrl_bit.c3en = newState;
      break;

    case channel::Select::CHANNEL3C:
      reg.cctrl_bit.c3cen = newState;
      break;

    case channel::Select::CHANNEL4:
      reg.cctrl_bit.c4en = newState;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::inputChannelfilterSet(Register& reg, channel::Select channel, uint16_t filterValue) {
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_input_bit.c1df = filterValue;
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_input_bit.c2df = filterValue;
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_input_bit.c3df = filterValue;
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_input_bit.c4df = filterValue;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::pwmInputConfig(Register& reg, input::Config& config, input::Divider divider) {
  switch (config.channelSelect) {
    case channel::Select::CHANNEL1:
      if (config.inputPolarity == input::Polarity::RISING_EDGE) {
        /* set channel polarity */
        reg.cctrl_bit.c1p = static_cast<uint8_t>(input::Polarity::RISING_EDGE);
        reg.cctrl_bit.c2p = static_cast<uint8_t>(input::Polarity::FALLING_EDGE);
      } else if (config.inputPolarity == input::Polarity::FALLING_EDGE) {
        /* set channel polarity */
        reg.cctrl_bit.c1p = static_cast<uint8_t>(input::Polarity::FALLING_EDGE);
        reg.cctrl_bit.c2p = static_cast<uint8_t>(input::Polarity::RISING_EDGE);
      }

      if (config.inputDirectionMapped == input::DirectionMapped::DIRECT) {
        /* ic1 is mapped on ti1 */
        reg.cm1_input_bit.c1c = static_cast<uint8_t>(input::DirectionMapped::DIRECT);

        /* ic1 is mapped on ti2 */
        reg.cm1_input_bit.c2c = static_cast<uint8_t>(input::DirectionMapped::INDIRECT);
      } else if (config.inputDirectionMapped == input::DirectionMapped::INDIRECT) {
        /* ic1 is mapped on ti1 */
        reg.cm1_input_bit.c1c = static_cast<uint8_t>(input::DirectionMapped::INDIRECT);

        /* ic1 is mapped on ti2 */
        reg.cm1_input_bit.c2c = static_cast<uint8_t>(input::DirectionMapped::DIRECT);
      }

      /* set input ch1 and ch2 filter value*/
      reg.cm1_input_bit.c1df = config.inputFilterValue;
      reg.cm1_input_bit.c2df = config.inputFilterValue;

      /*set input ch1 and ch2 divider value*/
      reg.cm1_input_bit.c1idiv = static_cast<uint8_t>(divider);
      reg.cm1_input_bit.c2idiv = static_cast<uint8_t>(divider);

      reg.cctrl_bit.c1en = true;
      reg.cctrl_bit.c2en = true;
      break;

    case channel::Select::CHANNEL2:
      if (config.inputPolarity == input::Polarity::RISING_EDGE) {
        /* set channel polarity */
        reg.cctrl_bit.c2p = static_cast<uint8_t>(input::Polarity::RISING_EDGE);
        reg.cctrl_bit.c1p = static_cast<uint8_t>(input::Polarity::FALLING_EDGE);
      } else if (config.inputPolarity == input::Polarity::FALLING_EDGE) {
        /* set channel polarity */
        reg.cctrl_bit.c2p = static_cast<uint8_t>(input::Polarity::FALLING_EDGE);
        reg.cctrl_bit.c1p = static_cast<uint8_t>(input::Polarity::RISING_EDGE);
      }

      if (config.inputDirectionMapped == input::DirectionMapped::DIRECT) {
        /* set mapped direct */
        reg.cm1_input_bit.c2c = static_cast<uint8_t>(input::DirectionMapped::DIRECT);
        reg.cm1_input_bit.c1c = static_cast<uint8_t>(input::DirectionMapped::INDIRECT);
      } else if (config.inputDirectionMapped == input::DirectionMapped::INDIRECT) {
        /* set mapped direct */
        reg.cm1_input_bit.c2c = static_cast<uint8_t>(input::DirectionMapped::INDIRECT);
        reg.cm1_input_bit.c1c = static_cast<uint8_t>(input::DirectionMapped::DIRECT);
      }

      /* set input ch1 and ch2 filter value*/
      reg.cm1_input_bit.c1df = config.inputFilterValue;
      reg.cm1_input_bit.c2df = config.inputFilterValue;

      /*set input ch1 and ch2 divider value*/
      reg.cm1_input_bit.c1idiv = static_cast<uint8_t>(divider);
      reg.cm1_input_bit.c2idiv = static_cast<uint8_t>(divider);

      reg.cctrl_bit.c1en = true;
      reg.cctrl_bit.c2en = true;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::inputChannelDividerSet(Register& reg, channel::Select channel, input::Divider divider) {
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_input_bit.c1idiv = static_cast<uint8_t>(divider);
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_input_bit.c2idiv = static_cast<uint8_t>(divider);
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_input_bit.c3idiv = static_cast<uint8_t>(divider);
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_input_bit.c4idiv = static_cast<uint8_t>(divider);
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::outputChannelPolaritySet(Register& reg, channel::Select channel, PolarityActive ocPolarity) {
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cctrl_bit.c1p = static_cast<uint32_t>(ocPolarity);
      break;

    case channel::Select::CHANNEL2:
      reg.cctrl_bit.c2p = static_cast<uint32_t>(ocPolarity);
      break;

    case channel::Select::CHANNEL3:
      reg.cctrl_bit.c3p = static_cast<uint32_t>(ocPolarity);
      break;

    case channel::Select::CHANNEL4:
      reg.cctrl_bit.c4p = static_cast<uint32_t>(ocPolarity);
      break;

    case channel::Select::CHANNEL1C:
      reg.cctrl_bit.c1cp = static_cast<uint32_t>(ocPolarity);
      break;

    case channel::Select::CHANNEL2C:
      reg.cctrl_bit.c2cp = static_cast<uint32_t>(ocPolarity);
      break;

    case channel::Select::CHANNEL3C:
      reg.cctrl_bit.c3cp = static_cast<uint32_t>(ocPolarity);
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::externalClockConfig(Register& reg, external::Divider divider, external::Polarity polarity, uint16_t filter) {
  reg.stctrl_bit.esdiv = static_cast<uint8_t>(divider);
  reg.stctrl_bit.esp = static_cast<uint8_t>(polarity);
  reg.stctrl_bit.esf = filter;
  return;
}
/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::externalClockMode1Config(Register& reg, external::Divider divider, external::Polarity polarity, uint16_t filter) {
  externalClockConfig(reg, divider, polarity, filter);
  reg.stctrl_bit.smsel = static_cast<uint8_t>(subordinate::ModeSelect::EXTERNAL_CLOCK_A);
  reg.stctrl_bit.stis = static_cast<uint8_t>(subordinate::InputSelect::EXTIN);
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::externalClockMode2Config(Register& reg, external::Divider divider, external::Polarity polarity, uint16_t filter) {
  externalClockConfig(reg, divider, polarity, filter);
  reg.stctrl_bit.ecmben = true;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::encoderModeConfig(Register& reg, EncoderMode encoderMode, input::Polarity ic1Polarity, input::Polarity ic2Polarity) {
  reg.stctrl_bit.smsel = static_cast<uint8_t>(encoderMode);

  /* set ic1 polarity */
  reg.cctrl_bit.c1p = (static_cast<uint8_t>(ic1Polarity) & 0x1);
  reg.cctrl_bit.c1cp = (static_cast<uint8_t>(ic1Polarity) >> 1);
  /* set ic1 as input channel */
  reg.cm1_input_bit.c1c = static_cast<uint8_t>(input::DirectionMapped::DIRECT);

  /* set ic2 polarity */
  reg.cctrl_bit.c2p = (static_cast<uint8_t>(ic2Polarity) & 0x1);
  reg.cctrl_bit.c2cp = (static_cast<uint8_t>(ic2Polarity) >> 1);
  /* set ic2 as input channel */
  reg.cm1_input_bit.c2c = static_cast<uint8_t>(input::DirectionMapped::DIRECT);

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::forceOutputSet(Register& reg, channel::Select channel, output::Force forceOutput) {
  switch (channel) {
    case channel::Select::CHANNEL1:
      reg.cm1_output_bit.c1octrl = static_cast<uint8_t>(forceOutput);
      break;

    case channel::Select::CHANNEL2:
      reg.cm1_output_bit.c2octrl = static_cast<uint8_t>(forceOutput);
      break;

    case channel::Select::CHANNEL3:
      reg.cm2_output_bit.c3octrl = static_cast<uint8_t>(forceOutput);
      break;

    case channel::Select::CHANNEL4:
      reg.cm2_output_bit.c4octrl = static_cast<uint8_t>(forceOutput);
      break;

    default:
      break;
  }
}
/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::dmaControlConfig(Register& reg, dma::TransferLength dmaLength, dma::BaseAddress dmaBaseAddress) {
  reg.dmactrl_bit.dtb = static_cast<uint8_t>(dmaLength);
  reg.dmactrl_bit.addr = static_cast<uint16_t>(dmaBaseAddress);
  return;
}
/** ---------------------------------------------------------------------------------------
 *
 */
void TMR::brkdtConfig(Register& reg, BreakDutyConfig& brkdtStruct) {
  reg.brk_bit.brken = brkdtStruct.brkEnable;
  reg.brk_bit.dtc = brkdtStruct.deadtime;
  reg.brk_bit.fcsodis = brkdtStruct.fcsodisState;
  reg.brk_bit.fcsoen = brkdtStruct.fcsoenState;
  reg.brk_bit.brkv = static_cast<uint8_t>(brkdtStruct.breakPolarity);
  reg.brk_bit.aoen = brkdtStruct.autoOutputEnable;
  reg.brk_bit.wpc = static_cast<uint8_t>(brkdtStruct.writeProtectLevel);
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
