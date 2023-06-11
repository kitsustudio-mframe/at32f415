/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_046BB99C_B4E1_4688_B3BD_014FD9291302
#define CHIP_046BB99C_B4E1_4688_B3BD_014FD9291302

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../AT32F415.h"
#include "./../adc/Channel.h"
#include "./../adc/Config.h"
#include "./../adc/DataAlign.h"
#include "./../adc/Flag.h"
#include "./../adc/Interrupt.h"
#include "./../adc/OrdinaryTrig.h"
#include "./../adc/PreemptChannel.h"
#include "./../adc/PreemptTrig.h"
#include "./../adc/Register.h"
#include "./../adc/SampleTime.h"
#include "./../adc/VoltageMonitoring.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::adc {
  class ADC;
  extern Register& ADC1;
}  // namespace chip::adc

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::adc::ADC {
  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  ADC(void) = default;

  virtual ~ADC(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  enable or disable the specified adc peripheral.
   * @param  x: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  new_state: new state of a/d converter.
   *         this parameter can be: TRUE or FALSE.
   *         note:after adc ready,user set adcen bit will cause ordinary conversion
   * @retval none
   */
  static inline void enable(Register& reg, bool newState) {
    ADC1.ctrl2_bit.adcen = newState;
    return;
  }

  /**
   * @brief  enable or disable the adc dma transfer.
   * @param  x: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  newState: new state of the adc dma transfer.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static void dmaModeEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.ocdmaen = newState;
    return;
  }

  /**
   * @brief  enable or disable the specified adc interrupts.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  int: specifies the adc interrupt sources to be enabled or disabled.
   *         this parameter can be one of the following values:
   *         - VMOR_INT
   *         - CCE_INT
   *         - PCCE_INT
   * @param  newState: new state of the specified adc interrupts.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
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
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval none
   */
  static void calibrationInit(Register& reg) {
    reg.ctrl2_bit.adcalinit = true;
    return;
  }

  /**
   * @brief  get calibration register's initialize status of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval the new state of reset calibration register status(SET or RESET).
   */
  static bool calibrationInitStatusGet(Register& reg) {
    return reg.ctrl2_bit.adcalinit;
  }

  /**
   * @brief  start calibration process of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval none
   */
  static void calibrationStart(Register& reg) {
    reg.ctrl2_bit.adcal = true;
    return;
  }

  /**
   * @brief  get calibration status of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval the new state of calibration status(SET or RESET).
   */
  static bool calibrationStatusGet(Register& reg) {
    return reg.ctrl2_bit.adcal;
  }

  /**
   * @brief  select the voltage monitoring's channel of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  channel: select the channel.
   *         this parameter can be one of the following values:
   *         - CHANNEL_0    - CHANNEL_1    - CHANNEL_2    - CHANNEL_3
   *         - CHANNEL_4    - CHANNEL_5    - CHANNEL_6    - CHANNEL_7
   *         - CHANNEL_8    - CHANNEL_9    - CHANNEL_10   - CHANNEL_11
   *         - CHANNEL_12   - CHANNEL_13   - CHANNEL_14   - CHANNEL_15
   *         - CHANNEL_16   - CHANNEL_17
   * @retval none
   */
  static void voltageMonitorSingleChannelSelect(Register& reg, Channel channel) {
    reg.ctrl1_bit.vmcsel = static_cast<uint8_t>(channel);
    return;
  }

  /**
   * @brief  set preempt channel lenghth of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  channel_lenght: set the adc preempt channel lenghth.
   *         this parameter can be:
   *         - (0x1~0x4)
   * @retval none
   */
  static void preemptChannelLengthSet(Register& reg, uint8_t channelLenght) {
    reg.psq_bit.pclen = channelLenght - 1;
    return;
  }

  /**
   * @brief  set partitioned mode channel count of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  channel_count: configure the adc partitioned mode channel count.
   *         this parameter can be:
   *         - (0x1~0x8)
   * @retval none
   */
  static void ordinaryPartCountSet(Register& reg, uint8_t channelCount) {
    reg.ctrl1_bit.ocpcnt = channelCount - 1;
    return;
  }
  /**
   * @brief  enable or disable the partitioned mode on ordinary channel of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  newState: new state of ordinary channel's partitioned mode.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void ordinaryPartModeEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.ocpen = newState;
    return;
  }

  /**
   * @brief  enable or disable the partitioned mode on preempt channel of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  newState: new state of preempt channel's partitioned mode.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void preemptPartModeEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.pcpen = newState;
    return;
  }

  /**
   * @brief  enable or disable automatic preempt group conversion of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  newState: new state of automatic preempt group conversion.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void preemptAutoModeEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.pcautoen = newState;
    return;
  }

  /**
   * @brief  enable or disable the temperature sensor and vintrv channel.
   * @param  newState: new state of Internal temperature sensor and vintrv.
   *         this parameter can be: true or FALSE.
   *         note:this bit is present only in adc1
   * @retval none
   */
  static void tempersensorVintrvEnable(bool newState) {
    ADC1.ctrl2_bit.itsrven = newState;
    return;
  }

  /**
   * @brief  enable or disable ordinary software start conversion of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  newState: new state of ordinary software start conversion.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void ordinarySoftwareTriggerEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.ocswtrg = newState;
    return;
  }

  /**
   * @brief  get ordinary software start conversion status of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval the new state of ordinary software start conversion status(SET or RESET).
   */
  static bool ordinarySoftwareTriggerStatusGet(Register& reg) {
    return reg.ctrl2_bit.ocswtrg;
  }

  /**
   * @brief  enable or disable preempt software start conversion of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  newState: new state of preempt software start conversion.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void preemptSoftwareTriggerEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.pcswtrg = newState;
    return;
  }

  /**
   * @brief  get preempt software start conversion status of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval the new state of preempt software start conversion status(SET or RESET).
   */
  static bool preemptSoftwareTriggerStatusGet(Register& reg) {
    return reg.ctrl2_bit.pcswtrg;
  }

  /**
   * @brief  return the last conversion data for ordinary channel of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval the last conversion data for ordinary channel.
   */
  static uint16_t ordinaryConversionDataGet(Register& reg) {
    return static_cast<uint16_t>(reg.odt_bit.odt);
  }

  /**
   * @brief  get flag of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  flag: select the adc flag.
   *         this parameter can be one of the following values:
   *         - VMOR
   *         - CCE
   *         - PCCE
   *         - PCCS(no interrupt associated)
   *         - OCCS(no interrupt associated)
   * @retval the new state of adc flag status(SET or RESET).
   */
  static bool flagGet(Register& reg, Flag flag) {
    return reg.sts & static_cast<uint8_t>(flag);
  }

  /**
   * @brief  clear flag of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  flag: select the adc flag.
   *         this parameter can be any combination of the following values:
   *         - VMOR
   *         - CCE(also can clear by reading the reg.odt)
   *         - PCCE
   *         - PCCS
   *         - OCCS
   * @retval none
   */
  static void flagClear(Register& reg, Flag flag) {
    reg.sts = ~static_cast<uint32_t>(flag);
    return;
  }
  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  deinitialize the adc peripheral registers to their default reset values.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @retval none
   */
  static void reset(Register& reg);

  /**
   * @brief  adc base default para init.
   * @param  sequence_mode: set the state of adc sequence mode.
   *         this parameter can be:true or FALSE
   * @param  repeat_mode: set the state of adc repeat conversion mode.
   *         this parameter can be:true or FALSE
   * @param  data_align: set the state of adc data alignment.
   *         this parameter can be one of the following values:
   *         - ADC_RIGHT_ALIGNMENT
   *         - ADC_LEFT_ALIGNMENT
   * @param  ordinary_channel_length: configure the adc ordinary channel sequence length.
   *         this parameter can be:
   *         - (0x1~0xf)
   * @retval none
   */
  static void baseDefaultParaInit(Config& baseStruct);

  /**
   * @brief  initialize the adc peripheral according to the specified parameters.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  sequence_mode: set the state of adc sequence mode.
   *         this parameter can be:true or FALSE
   * @param  repeat_mode: set the state of adc repeat conversion mode.
   *         this parameter can be:true or FALSE
   * @param  data_align: set the state of adc data alignment.
   *         this parameter can be one of the following values:
   *         - ADC_RIGHT_ALIGNMENT
   *         - ADC_LEFT_ALIGNMENT
   * @param  ordinary_channel_length: configure the adc ordinary channel sequence length.
   *         this parameter can be:
   *         - (0x1~0xf)
   * @retval none
   */
  static void baseConfig(Register& reg, Config& baseStruct);

  /**
   * @brief  enable or disable the voltage monitoring on single/all ordinary or preempt channels of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_voltage_monitoring: choose the adc_voltage_monitoring config.
   *         this parameter can be one of the following values:
   *         - ADC_VMONITOR_SINGLE_ORDINARY
   *         - ADC_VMONITOR_SINGLE_PREEMPT
   *         - ADC_VMONITOR_SINGLE_ORDINARY_PREEMPT
   *         - ADC_VMONITOR_ALL_ORDINARY
   *         - ADC_VMONITOR_ALL_PREEMPT
   *         - ADC_VMONITOR_ALL_ORDINARY_PREEMPT
   *         - ADC_VMONITOR_NONE
   * @retval none
   */
  static void voltageMonitorEnable(Register& reg, VoltageMonitoring voltageMonitoring);

  /**
   * @brief  set voltage monitoring's high and low thresholds value of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_high_threshold: voltage monitoring's high thresholds value.
   *         this parameter can be:
   *         - (0x000~0xFFF)
   * @param  adc_low_threshold: voltage monitoring's low thresholds value.
   *         this parameter can be:
   *         - (0x000~0xFFF)
   * @retval none
   */
  static void voltageMonitorThresholdValueSet(Register& reg, uint16_t highThreshold, uint16_t lowThreshold);

  /**
   * @brief  configure preempt channel's corresponding rank in the sequencer and sample time of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_channel: select the channel.
   *         this parameter can be one of the following values:
   *         - ADC_CHANNEL_0    - ADC_CHANNEL_1    - ADC_CHANNEL_2    - ADC_CHANNEL_3
   *         - ADC_CHANNEL_4    - ADC_CHANNEL_5    - ADC_CHANNEL_6    - ADC_CHANNEL_7
   *         - ADC_CHANNEL_8    - ADC_CHANNEL_9    - ADC_CHANNEL_10   - ADC_CHANNEL_11
   *         - ADC_CHANNEL_12   - ADC_CHANNEL_13   - ADC_CHANNEL_14   - ADC_CHANNEL_15
   *         - ADC_CHANNEL_16   - ADC_CHANNEL_17
   * @param  adc_sequence: set rank in the preempt group sequencer.
   *         this parameter must be:
   *         - between 1 to 4
   * @param  adc_sampletime: config the sampletime of adc channel.
   *         this parameter can be one of the following values:
   *         - ADC_SAMPLETIME_1_5
   *         - ADC_SAMPLETIME_7_5
   *         - ADC_SAMPLETIME_13_5
   *         - ADC_SAMPLETIME_28_5
   *         - ADC_SAMPLETIME_41_5
   *         - ADC_SAMPLETIME_55_5
   *         - ADC_SAMPLETIME_71_5
   *         - ADC_SAMPLETIME_239_5
   * @retval none
   */
  static void preemptChannelSet(Register& reg, Channel channel, uint8_t sequence, SampleTime sampleTime);

  /**
   * @brief  enable or disable the ordinary channel's external trigger and
   *         set external trigger event of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_ordinary_trig: select the external trigger event.
   *         this parameter can be one of the following values:
   *         adc1
   *         - ADC12_ORDINARY_TRIG_TMR1CH1     - ADC12_ORDINARY_TRIG_TMR1CH2  - ADC12_ORDINARY_TRIG_TMR1CH3             - ADC12_ORDINARY_TRIG_TMR2CH2
   *         - ADC12_ORDINARY_TRIG_TMR3TRGOUT  - ADC12_ORDINARY_TRIG_TMR4CH4  - ADC12_ORDINARY_TRIG_EXINT11_TMR1TRGOUT  - ADC12_ORDINARY_TRIG_SOFTWARE
   *         - ADC12_ORDINARY_TRIG_TMR1TRGOUT
   * @param  newState: new state of ordinary channel's external trigger.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void ordinaryConversionTriggerSet(Register& reg, OrdinaryTrig ordinaryTrig, bool newState);

  /**
   * @brief  configure preempt channel's corresponding rank in the sequencer and sample time of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  channel: select the channel.
   *         this parameter can be one of the following values:
   *         - ADC_CHANNEL_0    - ADC_CHANNEL_1    - ADC_CHANNEL_2    - ADC_CHANNEL_3
   *         - ADC_CHANNEL_4    - ADC_CHANNEL_5    - ADC_CHANNEL_6    - ADC_CHANNEL_7
   *         - ADC_CHANNEL_8    - ADC_CHANNEL_9    - ADC_CHANNEL_10   - ADC_CHANNEL_11
   *         - ADC_CHANNEL_12   - ADC_CHANNEL_13   - ADC_CHANNEL_14   - ADC_CHANNEL_15
   *         - ADC_CHANNEL_16   - ADC_CHANNEL_17
   * @param  sequence: set rank in the preempt group sequencer.
   *         this parameter must be:
   *         - between 1 to 4
   * @param  sampleTime: config the sampletime of adc channel.
   *         this parameter can be one of the following values:
   *         - ADC_SAMPLETIME_1_5
   *         - ADC_SAMPLETIME_7_5
   *         - ADC_SAMPLETIME_13_5
   *         - ADC_SAMPLETIME_28_5
   *         - ADC_SAMPLETIME_41_5
   *         - ADC_SAMPLETIME_55_5
   *         - ADC_SAMPLETIME_71_5
   *         - ADC_SAMPLETIME_239_5
   * @retval none
   */
  static void ordinaryChannelSet(Register& reg, Channel channel, uint8_t sequence, SampleTime sampleTime);

  /**
   * @brief  enable or disable the preempt channel's external trigger and
   *         set external trigger event of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_preempt_trig: select the external trigger event.
   *         this parameter can be one of the following values:
   *         adc1
   *         - ADC12_PREEMPT_TRIG_TMR1TRGOUT  - ADC12_PREEMPT_TRIG_TMR1CH4     - ADC12_PREEMPT_TRIG_TMR2TRGOUT      - ADC12_PREEMPT_TRIG_TMR2CH1
   *         - ADC12_PREEMPT_TRIG_TMR3CH4     - ADC12_PREEMPT_TRIG_TMR4TRGOUT  - ADC12_PREEMPT_TRIG_EXINT15_TMR1CH4 - ADC12_PREEMPT_TRIG_SOFTWARE
   *         - ADC12_PREEMPT_TRIG_TMR1CH1
   * @param  newState: new state of preempt channel's external trigger.
   *         this parameter can be: true or FALSE.
   * @retval none
   */
  static void preemptConversionTriggerSet(Register& reg, PreemptTrig preemptTrig, bool newState);

  /**
   * @brief  set preempt channel's conversion value offset of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_preempt_channel: select the preempt channel.
   *         this parameter can be one of the following values:
   *         - ADC_PREEMPT_CHANNEL_1
   *         - ADC_PREEMPT_CHANNEL_2
   *         - ADC_PREEMPT_CHANNEL_3
   *         - ADC_PREEMPT_CHANNEL_4
   * @param  adc_offset_value: set the adc preempt channel's conversion value offset.
   *         this parameter can be:
   *         - (0x000~0xFFF)
   * @retval none
   */
  static void preemptOffsetValueSet(Register& reg, PreemptChannel preemptChannel, uint16_t offsetValue);

  /**
   * @brief  return the conversion data for selection preempt channel of the specified adc peripheral.
   * @param  reg: select the adc peripheral.
   *         this parameter can be one of the following values:
   *         ADC1.
   * @param  adc_preempt_channel: select the preempt channel.
   *         this parameter can be one of the following values:
   *         - ADC_PREEMPTED_CHANNEL_1
   *         - ADC_PREEMPTED_CHANNEL_2
   *         - ADC_PREEMPTED_CHANNEL_3
   *         - ADC_PREEMPTED_CHANNEL_4
   * @retval the conversion data for selection preempt channel.
   */
  static uint16_t preemptConversionDataGet(Register& reg, PreemptChannel preemptChannel);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_046BB99C_B4E1_4688_B3BD_014FD9291302 */
