/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./ADC.h"

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
using chip::adc::ADC;
using chip::adc::Register;
using chip::crm::CRM;
using chip::crm::PeriphReset;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::adc::ADC1 = *reinterpret_cast<Register*>(chip::AT32F415::BASE_ADC1);

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
void ADC::reset(Register& reg) {
  if (reinterpret_cast<uint32_t>(&reg) == chip::AT32F415::BASE_ADC1) {
    CRM::periphReset(PeriphReset::RESET_ADC1, true);
    CRM::periphReset(PeriphReset::RESET_ADC1, false);
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::baseDefaultParaInit(Config& config) {
  config.sequenceMode = false;
  config.repeatMode = false;
  config.dataAlign = DataAlign::RIGHT;
  config.ordinaryChannelLength = 1;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::baseConfig(Register& reg, Config& baseStruct) {
  reg.ctrl1_bit.sqen = baseStruct.sequenceMode;
  reg.ctrl2_bit.rpen = baseStruct.repeatMode;
  reg.ctrl2_bit.dtalign = static_cast<uint8_t>(baseStruct.dataAlign);
  reg.osq1_bit.oclen = baseStruct.ordinaryChannelLength;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::voltageMonitorEnable(Register& reg, VoltageMonitoring voltageMonitoring) {
  reg.ctrl1_bit.ocvmen = false;
  reg.ctrl1_bit.pcvmen = false;
  reg.ctrl1_bit.vmsgen = false;
  reg.ctrl1 |= static_cast<uint32_t>(voltageMonitoring);
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::voltageMonitorThresholdValueSet(Register& reg, uint16_t highThreshold, uint16_t lowThreshold) {
  reg.vmhb_bit.vmhb = highThreshold;
  reg.vmlb_bit.vmlb = lowThreshold;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::preemptChannelSet(Register& reg, Channel channel, uint8_t sequence, SampleTime sampleTime) {
  uint16_t sequence_index = 0;
  switch (channel) {
    case Channel::CHANNEL0:
      reg.spt2_bit.cspt0 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL1:
      reg.spt2_bit.cspt1 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL2:
      reg.spt2_bit.cspt2 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL3:
      reg.spt2_bit.cspt3 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL4:
      reg.spt2_bit.cspt4 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL5:
      reg.spt2_bit.cspt5 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL6:
      reg.spt2_bit.cspt6 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL7:
      reg.spt2_bit.cspt7 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL8:
      reg.spt2_bit.cspt8 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL9:
      reg.spt2_bit.cspt9 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL10:
      reg.spt1_bit.cspt10 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL11:
      reg.spt1_bit.cspt11 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL12:
      reg.spt1_bit.cspt12 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL13:
      reg.spt1_bit.cspt13 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL14:
      reg.spt1_bit.cspt14 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL15:
      reg.spt1_bit.cspt15 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL16:
      reg.spt1_bit.cspt16 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL17:
      reg.spt1_bit.cspt17 = static_cast<uint8_t>(sampleTime);
      break;
    default:
      break;
  }

  sequence_index = sequence + 3 - reg.psq_bit.pclen;
  switch (sequence_index) {
    case 1:
      reg.psq_bit.psn1 = static_cast<uint8_t>(channel);
      break;
    case 2:
      reg.psq_bit.psn2 = static_cast<uint8_t>(channel);
      break;
    case 3:
      reg.psq_bit.psn3 = static_cast<uint8_t>(channel);
      break;
    case 4:
      reg.psq_bit.psn4 = static_cast<uint8_t>(channel);
      break;
    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::ordinaryChannelSet(Register& reg, Channel channel, uint8_t sequence, SampleTime sampleTime) {
  switch (channel) {
    case Channel::CHANNEL0:
      reg.spt2_bit.cspt0 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL1:
      reg.spt2_bit.cspt1 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL2:
      reg.spt2_bit.cspt2 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL3:
      reg.spt2_bit.cspt3 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL4:
      reg.spt2_bit.cspt4 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL5:
      reg.spt2_bit.cspt5 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL6:
      reg.spt2_bit.cspt6 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL7:
      reg.spt2_bit.cspt7 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL8:
      reg.spt2_bit.cspt8 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL9:
      reg.spt2_bit.cspt9 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL10:
      reg.spt1_bit.cspt10 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL11:
      reg.spt1_bit.cspt11 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL12:
      reg.spt1_bit.cspt12 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL13:
      reg.spt1_bit.cspt13 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL14:
      reg.spt1_bit.cspt14 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL15:
      reg.spt1_bit.cspt15 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL16:
      reg.spt1_bit.cspt16 = static_cast<uint8_t>(sampleTime);
      break;
    case Channel::CHANNEL17:
      reg.spt1_bit.cspt17 = static_cast<uint8_t>(sampleTime);
      break;
    default:
      break;
  }

  switch (sequence) {
    case 1:
      reg.osq3_bit.osn1 = static_cast<uint8_t>(channel);
      break;
    case 2:
      reg.osq3_bit.osn2 = static_cast<uint8_t>(channel);
      break;
    case 3:
      reg.osq3_bit.osn3 = static_cast<uint8_t>(channel);
      break;
    case 4:
      reg.osq3_bit.osn4 = static_cast<uint8_t>(channel);
      break;
    case 5:
      reg.osq3_bit.osn5 = static_cast<uint8_t>(channel);
      break;
    case 6:
      reg.osq3_bit.osn6 = static_cast<uint8_t>(channel);
      break;
    case 7:
      reg.osq2_bit.osn7 = static_cast<uint8_t>(channel);
      break;
    case 8:
      reg.osq2_bit.osn8 = static_cast<uint8_t>(channel);
      break;
    case 9:
      reg.osq2_bit.osn9 = static_cast<uint8_t>(channel);
      break;
    case 10:
      reg.osq2_bit.osn10 = static_cast<uint8_t>(channel);
      break;
    case 11:
      reg.osq2_bit.osn11 = static_cast<uint8_t>(channel);
      break;
    case 12:
      reg.osq2_bit.osn12 = static_cast<uint8_t>(channel);
      break;
    case 13:
      reg.osq1_bit.osn13 = static_cast<uint8_t>(channel);
      break;
    case 14:
      reg.osq1_bit.osn14 = static_cast<uint8_t>(channel);
      break;
    case 15:
      reg.osq1_bit.osn15 = static_cast<uint8_t>(channel);
      break;
    case 16:
      reg.osq1_bit.osn16 = static_cast<uint8_t>(channel);
      break;
    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::ordinaryConversionTriggerSet(Register& reg, OrdinaryTrig ordinaryTrig, bool newState) {
  if (static_cast<uint8_t>(ordinaryTrig) > 7) {
    reg.ctrl2_bit.octesel_h = 1;
    reg.ctrl2_bit.octesel_l = static_cast<uint8_t>(ordinaryTrig) & 0x7;
  } else {
    reg.ctrl2_bit.octesel_h = 0;
    reg.ctrl2_bit.octesel_l = static_cast<uint8_t>(ordinaryTrig) & 0x7;
  }
  reg.ctrl2_bit.octen = newState;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::preemptConversionTriggerSet(Register& reg, PreemptTrig preemptTrig, bool newState) {
  if (static_cast<uint8_t>(preemptTrig) > 7) {
    reg.ctrl2_bit.pctesel_h = 1;
    reg.ctrl2_bit.pctesel_l = static_cast<uint8_t>(preemptTrig) & 0x7;
  } else {
    reg.ctrl2_bit.pctesel_h = 0;
    reg.ctrl2_bit.pctesel_l = static_cast<uint8_t>(preemptTrig) & 0x7;
  }
  reg.ctrl2_bit.pcten = newState;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void ADC::preemptOffsetValueSet(Register& reg, PreemptChannel preemptChannel, uint16_t offsetValue) {
  switch (preemptChannel) {
    case PreemptChannel::CHANNEL1:
      reg.pcdto1_bit.pcdto1 = offsetValue;
      break;

    case PreemptChannel::CHANNEL2:
      reg.pcdto2_bit.pcdto2 = offsetValue;
      break;

    case PreemptChannel::CHANNEL3:
      reg.pcdto3_bit.pcdto3 = offsetValue;
      break;

    case PreemptChannel::CHANNEL4:
      reg.pcdto4_bit.pcdto4 = offsetValue;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
uint16_t ADC::preemptConversionDataGet(Register& reg, PreemptChannel preemptChannel) {
  uint16_t preempt_conv_data_index = 0;

  switch (preemptChannel) {
    case PreemptChannel::CHANNEL1:
      preempt_conv_data_index = static_cast<uint16_t>(reg.pdt1_bit.pdt1);
      break;

    case PreemptChannel::CHANNEL2:
      preempt_conv_data_index = static_cast<uint16_t>(reg.pdt2_bit.pdt2);
      break;

    case PreemptChannel::CHANNEL3:
      preempt_conv_data_index = static_cast<uint16_t>(reg.pdt3_bit.pdt3);
      break;

    case PreemptChannel::CHANNEL4:
      preempt_conv_data_index = static_cast<uint16_t>(reg.pdt4_bit.pdt4);
      break;

    default:
      break;
  }

  return preempt_conv_data_index;
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
