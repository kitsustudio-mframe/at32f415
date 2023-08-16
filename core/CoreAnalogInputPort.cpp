/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CoreAnalogInputPort.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"
#include "mframe.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using chip::core::CoreAnalogInputPort;
using namespace chip::dma;
using namespace chip::adc;
using namespace chip::crm;
using chip::adc::ADC1;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
CoreAnalogInputPort::CoreAnalogInputPort(void) {
  return;
}

//-----------------------------------------------------------------------------------------
CoreAnalogInputPort::~CoreAnalogInputPort(void) {
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
 * Public Method <Override> - mframe::hal::AnalogInputPort
 */

//-----------------------------------------------------------------------------------------
int CoreAnalogInputPort::read(int channel) {
  if ((channel >= 16) || (channel < 0))
    return -1;

  return this->mResult[channel];
}

//-----------------------------------------------------------------------------------------
int CoreAnalogInputPort::getConvertLevel(void) {
  return 12;
}

/* ****************************************************************************************
 * Public Method <Override> - mframe::hal::Base
 */

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::deinit(void) {
  if (this->isInit())
    return false;

  crm::CRM::periphClockEnable(crm::PeriphClock::ADC1, false);
  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::init(void) {
  int i;
  adc::Config config;

  crm::CRM::periphClockEnable(crm::PeriphClock::ADC1, true);
  crm::CRM::adcClockDivSet(crm::DividerADC::DIV6);

  adc::ADC::baseDefaultParaInit(config);

  ADC1.ctrl1_bit.sqen = false;
  ADC1.ctrl2_bit.rpen = false;
  ADC1.ctrl2_bit.dtalign = static_cast<uint8_t>(DataAlign::RIGHT);
  ADC1.osq1_bit.oclen = 0;

  config.sequenceMode = false;
  config.repeatMode = false;
  config.dataAlign = DataAlign::RIGHT;
  config.ordinaryChannelLength = 0;

  for (i = 0; i < 16; ++i) {
    ADC::ordinaryChannelSet(ADC1, static_cast<adc::Channel>(i), static_cast<uint8_t>(i + 1), SampleTime::CYCLE_239_5);
  }

  ADC::ordinaryConversionTriggerSet(ADC1, OrdinaryTrig::SOFTWARE, true);

  ADC::enable(ADC1, true);

  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::isInit(void) {
  return chip::crm::CRM::getPeriphClockEnable(crm::PeriphClock::ADC1);
}

/* ****************************************************************************************
 * Public Method
 */

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::setSampleTime(int channel, chip::adc::SampleTime sampleTime) {
  ADC::ordinaryChannelSet(ADC1, static_cast<adc::Channel>(channel), static_cast<uint8_t>(channel + 1), SampleTime::CYCLE_239_5);
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::calibration(void) {
  if (!adc::ADC1.ctrl2_bit.adcen)
    return false;

  adc::ADC::calibrationInit(ADC1);
  while (adc::ADC::calibrationInitStatusGet(ADC1)){
  }

  adc::ADC::calibrationStart(ADC1);
  while (adc::ADC::calibrationStatusGet(ADC1)) {
  }

  adc::ADC::ordinarySoftwareTriggerEnable(ADC1, true);
  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::enable(void) {
  if (!this->isInit())
    return false;

  ADC1.ctrl2_bit.adcen = true;
  return ADC1.ctrl2_bit.adcen;
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::disable(void) {
  if (!this->isInit())
    return false;

  ADC1.ctrl2_bit.adcen = false;
  return !ADC1.ctrl2_bit.adcen;
}
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
