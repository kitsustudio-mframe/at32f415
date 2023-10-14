/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_046BB99C_B4E1_4688_B3BD_014FD9291302
#define CHIP_046BB99C_B4E1_4688_B3BD_014FD9291302

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/adc/ADC.h"
#include "chip_arterytek_at32f415/adc/Channel.h"
#include "chip_arterytek_at32f415/adc/Config.h"
#include "chip_arterytek_at32f415/adc/DataAlign.h"
#include "chip_arterytek_at32f415/adc/Flag.h"
#include "chip_arterytek_at32f415/adc/Interrupt.h"
#include "chip_arterytek_at32f415/adc/OrdinaryTrig.h"
#include "chip_arterytek_at32f415/adc/PreemptChannel.h"
#include "chip_arterytek_at32f415/adc/PreemptTrig.h"
#include "chip_arterytek_at32f415/adc/Register.h"
#include "chip_arterytek_at32f415/adc/SampleTime.h"
#include "chip_arterytek_at32f415/adc/VoltageMonitoring.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::adc {
  class ADC;
  extern Register& ADC1;
}  // namespace chip::adc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::adc::ADC {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new ADC object
   *
   */
  ADC(void) = default;

  /**
   * @brief Destroy the ADC object
   *
   */
  virtual ~ADC(void) = default;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief  enable or disable the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param newState new state of a/d converter.
   *        note:after adc ready,user set adcen bit will cause ordinary conversion
   */
  static inline void enable(Register& reg, bool newState) {
    ADC1.ctrl2_bit.adcen = newState;
    return;
  }

  /**
   * @brief enable or disable the adc dma transfer.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   * @param newState new state of the adc dma transfer.
   */
  static void dmaModeEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.ocdmaen = newState;
    return;
  }

  /**
   * @brief enable or disable the specified adc interrupts.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param interrupt specifies the adc interrupt sources to be enabled or disabled.
   *        該參數可以是以下值之一:
   *        - Interrupt::VMOR
   *        - Interrupt::CCE
   *        - Interrupt::PCCE
   *
   * @param newState new state of the specified adc interrupts.
   */
  static void interruptEnable(Register& reg, Interrupt interrupt, bool newState) {
    if (newState)
      reg.ctrl1 |= static_cast<uint32_t>(interrupt);
    else
      reg.ctrl1 &= ~static_cast<uint32_t>(interrupt);

    return;
  }

  /**
   * @brief  initialize calibration register of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *         該參數可以是以下值之一:
   *         ADC1.
   */
  static void calibrationInit(Register& reg) {
    reg.ctrl2_bit.adcalinit = true;
    return;
  }

  /**
   * @brief get calibration register's initialize status of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @return the new state of reset calibration register status(SET or RESET).
   */
  static bool calibrationInitStatusGet(Register& reg) {
    return reg.ctrl2_bit.adcalinit;
  }

  /**
   * @brief start calibration process of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   */
  static void calibrationStart(Register& reg) {
    reg.ctrl2_bit.adcal = true;
    return;
  }

  /**
   * @brief get calibration status of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @return the new state of calibration status(SET or RESET).
   */
  static bool calibrationStatusGet(Register& reg) {
    return reg.ctrl2_bit.adcal;
  }

  /**
   * @brief select the voltage monitoring's channel of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param channel select the channel.
   *        該參數可以是以下值之一:
   *        - Channel::CHANNEL0
   *        - Channel::CHANNEL1
   *        - Channel::CHANNEL2
   *        - Channel::CHANNEL3
   *        - Channel::CHANNEL4
   *        - Channel::CHANNEL5
   *        - Channel::CHANNEL6
   *        - Channel::CHANNEL7
   *        - Channel::CHANNEL8
   *        - Channel::CHANNEL9
   *        - Channel::CHANNEL10
   *        - Channel::CHANNEL11
   *        - Channel::CHANNEL12
   *        - Channel::CHANNEL13
   *        - Channel::CHANNEL14
   *        - Channel::CHANNEL15
   *        - Channel::CHANNEL16
   *        - Channel::CHANNEL17
   */
  static void voltageMonitorSingleChannelSelect(Register& reg, Channel channel) {
    reg.ctrl1_bit.vmcsel = static_cast<uint8_t>(channel);
    return;
  }

  /**
   * @brief set preempt channel lenghth of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param channelLenght: set the adc preempt channel lenghth.
   *        this parameter can be:
   *        - (0x1~0x4)
   */
  static void preemptChannelLengthSet(Register& reg, uint8_t channelLenght) {
    reg.psq_bit.pclen = channelLenght - 1;
    return;
  }

  /**
   * @brief set partitioned mode channel count of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *         該參數可以是以下值之一:
   *         ADC1.
   *
   * @param channelCount 配置 adc 分區模式通道數。
   *        這個參數可以是:
   *        - (0x1~0x8)
   */
  static void ordinaryPartCountSet(Register& reg, uint8_t channelCount) {
    reg.ctrl1_bit.ocpcnt = channelCount - 1;
    return;
  }
  /**
   * @brief enable or disable the partitioned mode on ordinary channel of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param newState new state of ordinary channel's partitioned mode.
   */
  static void ordinaryPartModeEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.ocpen = newState;
    return;
  }

  /**
   * @brief enable or disable the partitioned mode on preempt channel of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param newState new state of preempt channel's partitioned mode.
   */
  static void preemptPartModeEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.pcpen = newState;
    return;
  }

  /**
   * @brief enable or disable automatic preempt group conversion of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param newState new state of automatic preempt group conversion.
   */
  static void preemptAutoModeEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.pcautoen = newState;
    return;
  }

  /**
   * @brief enable or disable the temperature sensor and vintrv channel.
   *
   * @param newState new state of Internal temperature sensor and vintrv.
   *        note:this bit is present only in adc1
   */
  static void tempersensorVintrvEnable(bool newState) {
    ADC1.ctrl2_bit.itsrven = newState;
    return;
  }

  /**
   * @brief enable or disable ordinary software start conversion of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param newState new state of ordinary software start conversion.
   */
  static void ordinarySoftwareTriggerEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.ocswtrg = newState;
    return;
  }

  /**
   * @brief get ordinary software start conversion status of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @return the new state of ordinary software start conversion status(SET or RESET).
   */
  static bool ordinarySoftwareTriggerStatusGet(Register& reg) {
    return reg.ctrl2_bit.ocswtrg;
  }

  /**
   * @brief enable or disable preempt software start conversion of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param newState new state of preempt software start conversion.
   */
  static void preemptSoftwareTriggerEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.pcswtrg = newState;
    return;
  }

  /**
   * @brief get preempt software start conversion status of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @return the new state of preempt software start conversion status(SET or RESET).
   */
  static bool preemptSoftwareTriggerStatusGet(Register& reg) {
    return reg.ctrl2_bit.pcswtrg;
  }

  /**
   * @brief return the last conversion data for ordinary channel of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @return the last conversion data for ordinary channel.
   *
   */
  static uint16_t ordinaryConversionDataGet(Register& reg) {
    return static_cast<uint16_t>(reg.odt_bit.odt);
  }

  /**
   * @brief get flag of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param flag: select the adc flag.
   *        該參數可以是以下值之一:
   *        - Flag::VMOR
   *        - Flag::CCE
   *        - Flag::PCCE
   *        - Flag::PCCS(no interrupt associated)
   *        - Flag::OCCS(no interrupt associated)
   *
   * @return the new state of adc flag status(SET or RESET).
   */
  static bool flagGet(Register& reg, Flag flag) {
    return reg.sts & static_cast<uint8_t>(flag);
  }

  /**
   * @brief clear flag of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param flag: select the adc flag.
   *        this parameter can be any combination of the following values:
   *        - VMOR
   *        - CCE(also can clear by reading the reg.odt)
   *        - PCCE
   *        - PCCS
   *        - OCCS
   */
  static void flagClear(Register& reg, Flag flag) {
    reg.sts = ~static_cast<uint32_t>(flag);
    return;
  }

  /**
   * @brief deinitialize the adc peripheral registers to their default reset values.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   */
  static void reset(Register& reg);

  /**
   * @brief adc base default para init.
   *
   * @param baseStruct
   */
  static void baseDefaultParaInit(Config& baseStruct);

  /**
   * @brief initialize the adc peripheral according to the specified parameters.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param baseStruct
   */
  static void baseConfig(Register& reg, Config& baseStruct);

  /**
   * @brief enable or disable the voltage monitoring on single/all ordinary or preempt channels of the specified adc peripheral.
   * @param reg 選擇adc外設。.
   *         該參數可以是以下值之一:
   *         ADC1.
   * @param voltageMonitoring choose the adc_voltage_monitoring config.
   *        該參數可以是以下值之一:
   *        - VoltageMonitoring::SINGLE_ORDINARY
   *        - VoltageMonitoring::SINGLE_PREEMPT
   *        - VoltageMonitoring::SINGLE_ORDINARY_PREEMPT
   *        - VoltageMonitoring::ALL_ORDINARY
   *        - VoltageMonitoring::ALL_PREEMPT
   *        - VoltageMonitoring::ALL_ORDINARY_PREEMPT
   *        - VoltageMonitoring::NONE
   */
  static void voltageMonitorEnable(Register& reg, VoltageMonitoring voltageMonitoring);

  /**
   * @brief set voltage monitoring's high and low thresholds value of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param highThreshold voltage monitoring's high thresholds value.
   *        this parameter can be:
   *        - (0x000~0xFFF)
   *
   * @param lowThreshold voltage monitoring's low thresholds value.
   *        this parameter can be:
   *        - (0x000~0xFFF)
   */
  static void voltageMonitorThresholdValueSet(Register& reg, uint16_t highThreshold, uint16_t lowThreshold);

  /**
   * @brief configure preempt channel's corresponding rank in the sequencer and sample time of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param channel select the channel.
   *        該參數可以是以下值之一:
   *        - Channel::CHANNEL0
   *        - Channel::CHANNEL1
   *        - Channel::CHANNEL2
   *        - Channel::CHANNEL3
   *        - Channel::CHANNEL4
   *        - Channel::CHANNEL5
   *        - Channel::CHANNEL6
   *        - Channel::CHANNEL7
   *        - Channel::CHANNEL8
   *        - Channel::CHANNEL9
   *        - Channel::CHANNEL10
   *        - Channel::CHANNEL11
   *        - Channel::CHANNEL12
   *        - Channel::CHANNEL13
   *        - Channel::CHANNEL14
   *        - Channel::CHANNEL15
   *        - Channel::CHANNEL16
   *        - Channel::CHANNEL17
   *
   * @param sequence set rank in the preempt group sequencer.
   *        this parameter must be:
   *        - between 1 to 4
   *
   * @param sampleTime config the sampletime of adc channel.
   *        該參數可以是以下值之一:
   *        - SampleTime::CYCLE_1_5
   *        - SampleTime::CYCLE_7_5
   *        - SampleTime::CYCLE_13_5
   *        - SampleTime::CYCLE_28_5
   *        - SampleTime::CYCLE_41_5
   *        - SampleTime::CYCLE_55_5
   *        - SampleTime::CYCLE_71_5
   *        - SampleTime::CYCLE_239_5
   */
  static void preemptChannelSet(Register& reg, Channel channel, uint8_t sequence, SampleTime sampleTime);

  /**
   * @brief enable or disable the ordinary channel's external trigger and
   *        set external trigger event of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param ordinaryTrig select the external trigger event.
   *        該參數可以是以下值之一:
   *        - OrdinaryTrig::TMR1CH1
   *        - OrdinaryTrig::TMR1CH2
   *        - OrdinaryTrig::TMR1CH3
   *        - OrdinaryTrig::TMR2CH2
   *        - OrdinaryTrig::TMR3TRGOUT
   *        - OrdinaryTrig::TMR4CH4
   *        - OrdinaryTrig::EXINT11_TMR1TRGOUT
   *        - OrdinaryTrig::SOFTWARE
   *        - OrdinaryTrig::TMR1TRGOUT
   *
   * @param newState new state of ordinary channel's external trigger.
   */
  static void ordinaryConversionTriggerSet(Register& reg, OrdinaryTrig ordinaryTrig, bool newState);

  /**
   * @brief  configure preempt channel's corresponding rank in the sequencer and sample time of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param channel select the channel.
   *        該參數可以是以下值之一:
   *        - Channel::CHANNEL0
   *        - Channel::CHANNEL1
   *        - Channel::CHANNEL2
   *        - Channel::CHANNEL3
   *        - Channel::CHANNEL4
   *        - Channel::CHANNEL5
   *        - Channel::CHANNEL6
   *        - Channel::CHANNEL7
   *        - Channel::CHANNEL8
   *        - Channel::CHANNEL9
   *        - Channel::CHANNEL10
   *        - Channel::CHANNEL11
   *        - Channel::CHANNEL12
   *        - Channel::CHANNEL13
   *        - Channel::CHANNEL14
   *        - Channel::CHANNEL15
   *        - Channel::CHANNEL16
   *        - Channel::CHANNEL17
   *
   * @param sequence set rank in the preempt group sequencer.
   *        this parameter must be:
   *        - between 1 to 4
   *
   * @param sampleTime config the sampletime of adc channel.
   *        該參數可以是以下值之一:
   *        - ADC_SAMPLETIME_1_5
   *        - ADC_SAMPLETIME_7_5
   *        - ADC_SAMPLETIME_13_5
   *        - ADC_SAMPLETIME_28_5
   *        - ADC_SAMPLETIME_41_5
   *        - ADC_SAMPLETIME_55_5
   *        - ADC_SAMPLETIME_71_5
   *        - ADC_SAMPLETIME_239_5
   */
  static void ordinaryChannelSet(Register& reg, Channel channel, uint8_t sequence, SampleTime sampleTime);

  /**
   * @brief  configure preempt channel's sample time of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param channel select the channel.
   *        該參數可以是以下值之一:
   *        - Channel::CHANNEL0
   *        - Channel::CHANNEL1
   *        - Channel::CHANNEL2
   *        - Channel::CHANNEL3
   *        - Channel::CHANNEL4
   *        - Channel::CHANNEL5
   *        - Channel::CHANNEL6
   *        - Channel::CHANNEL7
   *        - Channel::CHANNEL8
   *        - Channel::CHANNEL9
   *        - Channel::CHANNEL10
   *        - Channel::CHANNEL11
   *        - Channel::CHANNEL12
   *        - Channel::CHANNEL13
   *        - Channel::CHANNEL14
   *        - Channel::CHANNEL15
   *        - Channel::CHANNEL16
   *        - Channel::CHANNEL17
   *
   * @param sampleTime config the sampletime of adc channel.
   *        該參數可以是以下值之一:
   *        - ADC_SAMPLETIME_1_5
   *        - ADC_SAMPLETIME_7_5
   *        - ADC_SAMPLETIME_13_5
   *        - ADC_SAMPLETIME_28_5
   *        - ADC_SAMPLETIME_41_5
   *        - ADC_SAMPLETIME_55_5
   *        - ADC_SAMPLETIME_71_5
   *        - ADC_SAMPLETIME_239_5
   */
  static void setChannelSampleTime(Register& reg, Channel channel, SampleTime sampleTime);

  /**
   * @brief enable or disable the preempt channel's external trigger and
   *        set external trigger event of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param preemptTrig select the external trigger event.
   *        該參數可以是以下值之一:
   *        - PreemptTrig::TMR1TRGOUT
   *        - PreemptTrig::TMR1CH4
   *        - PreemptTrig::TMR2TRGOUT
   *        - PreemptTrig::TMR2CH1
   *        - PreemptTrig::TMR3CH4
   *        - PreemptTrig::TMR4TRGOUT
   *        - PreemptTrig::EXINT15_TMR1CH4
   *        - PreemptTrig::SOFTWARE
   *        - PreemptTrig::TMR1CH1
   *
   * @param newState new state of preempt channel's external trigger.
   */
  static void preemptConversionTriggerSet(Register& reg, PreemptTrig preemptTrig, bool newState);

  /**
   * @brief  set preempt channel's conversion value offset of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *        該參數可以是以下值之一:
   *        ADC1.
   *
   * @param preemptChannel: select the preempt channel.
   *        該參數可以是以下值之一:
   *        - PreemptChannel::CHANNEL_1
   *        - PreemptChannel::CHANNEL_2
   *        - PreemptChannel::CHANNEL_3
   *        - PreemptChannel::CHANNEL_4
   *
   * @param offsetValue: set the adc preempt channel's conversion value offset.
   *         this parameter can be:
   *         - (0x000~0xFFF)
   */
  static void preemptOffsetValueSet(Register& reg, PreemptChannel preemptChannel, uint16_t offsetValue);

  /**
   * @brief return the conversion data for selection preempt channel of the specified adc peripheral.
   *
   * @param reg 選擇adc外設。.
   *         該參數可以是以下值之一:
   *         ADC1.
   *
   * @param preemptChannel select the preempt channel.
   *        該參數可以是以下值之一:
   *        - PreemptChannel::CHANNEL1
   *        - PreemptChannel::CHANNEL2
   *        - PreemptChannel::CHANNEL3
   *        - PreemptChannel::CHANNEL4
   *
   * @return the conversion data for selection preempt channel.   */
  static uint16_t preemptConversionDataGet(Register& reg, PreemptChannel preemptChannel);
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_046BB99C_B4E1_4688_B3BD_014FD9291302 */
