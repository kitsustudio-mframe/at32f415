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
  if((channel >= 16) || (channel < 0))
    return -1;

  return this->mValue[channel];
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
  if(this->isInit())
    return false;

  crm::CRM::periphClockEnable(crm::PeriphClock::ADC1, false);
  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::init(void) {
  if(true){
    dma::Config config;

    crm::CRM::periphClockEnable(crm::PeriphClock::DMA1, true);
    dma::DMA::reset(dma::DMA1_CHANNEL1);
    dma::DMA::defaultParaInit(config);
    config.bufferSize = 16;
    config.direction = dma::Direction::PERIPHERAL_TO_MEMORY;
    config.memoryIncEnable = true;
    config.peripheralBaseAddr = reinterpret_cast<uint32_t>(&adc::ADC1.odt);
    config.peripheralDataWidth = dma::PeripheralDataSize::HALFWORD;
    config.peripheralIncEnable = false;
    config.priority = dma::PriorityLevel::HIGH;
    config.loopModeEnable = true;

    dma::DMA::init(dma::DMA1_CHANNEL1, config);
    dma::DMA::channelEnable(dma::DMA1_CHANNEL1, true);
  }
  
  if(true){
    int i;
    adc::Config config;
    
    crm::CRM::periphClockEnable(crm::PeriphClock::ADC1, true);
    crm::CRM::adcClockDivSet(crm::DividerADC::DIV6);
    
    adc::ADC::baseDefaultParaInit(config);

    config.sequenceMode = true;
    config.repeatMode = true;
    config.dataAlign = adc::DataAlign::RIGHT;
    config.ordinaryChannelLength = 16;

    adc::ADC::baseConfig(adc::ADC1, config);
    
    for(i=0; i<16; ++i){
      adc::ADC::ordinaryChannelSet(ADC1, static_cast<adc::Channel>(i), static_cast<uint8_t>(i+1), adc::SampleTime::CYCLE_239_5);
    }

    adc::ADC::ordinaryConversionTriggerSet(adc::ADC1, adc::OrdinaryTrig::SOFTWARE, true);
    adc::ADC::dmaModeEnable(ADC1, true);

    adc::ADC::enable(ADC1, true);
    adc::ADC::calibrationInit(ADC1);
    while(adc::ADC::calibrationInitStatusGet(ADC1));
    adc::ADC::calibrationStart(ADC1);
    while(adc::ADC::calibrationStatusGet(ADC1));
  }

  adc::ADC::ordinarySoftwareTriggerEnable(ADC1, true);
  return true;
}

//-----------------------------------------------------------------------------------------
bool CoreAnalogInputPort::isInit(void) {
  return chip::crm::CRM::getPeriphClockEnable(crm::PeriphClock::ADC1);
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
