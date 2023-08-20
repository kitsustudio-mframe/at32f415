/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_22D1950D_0E59_4772_9CB3_21586637F24F
#define CHIP_22D1950D_0E59_4772_9CB3_21586637F24F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../Processor.h"
#include "./BreakDutyConfig.h"
#include "./BreakPolarity.h"
#include "./ClockDivision.h"
#include "./CountMode.h"
#include "./EncoderMode.h"
#include "./EventTrigger.h"
#include "./Flag.h"
#include "./Interrupt.h"
#include "./PolarityActive.h"
#include "./PrimarySelect.h"
#include "./Register.h"
#include "./WriteProtectLevel.h"
#include "./channel/package-info.h"
#include "./dma/package-info.h"
#include "./external/package-info.h"
#include "./input/package-info.h"
#include "./output/package-info.h"
#include "./subordinate/package-info.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr {
  class TMR;
  extern Register& TMR1;
  extern Register& TMR2;
  extern Register& TMR3;
  extern Register& TMR4;
  extern Register& TMR5;
  extern Register& TMR9;
  extern Register& TMR10;
  extern Register& TMR11;
}  // namespace chip::tmr

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::tmr::TMR {
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
  TMR(void) = default;

  virtual ~TMR(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief
   * 比較暫存器地址來源是否相同
   *
   * @param src 比較來源
   * @param dst 比較目標
   * @return true 地址相同
   * @return false 地址不相同
   */
  static inline bool compReg(const Register& src, const Register& dst) {
    return (reinterpret_cast<uint32_t>(&src) == reinterpret_cast<uint32_t>(&dst));
  }

  /**
   * @brief  enable or disable tmr counter
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  newState (TRUE or FALSE)
   */
  static inline void counterEnable(Register& reg, bool newState) {
    /* tmr counter enable  */
    reg.ctrl1_bit.tmren = newState;
  }

  /**
   * @brief  set tmr clock source division
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  clockDivision
   *         this parameter can be one of the following values:
   *         - DIV1
   *         - DIV2
   *         - DIV4
   */
  static inline void clockSourceDivSet(Register& reg, ClockDivision clockDivision) {
    /* set tmr clock source division */
    reg.ctrl1_bit.clkdiv = static_cast<uint8_t>(clockDivision);
  }

  /**
   * @brief  set tmr counter count direction
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  countMode
   *         this parameter can be one of the following values:
   *         - UP
   *         - DOWN
   *         - TWO_WAY_1
   *         - TWO_WAY_2
   *         - TWO_WAY_3
   * @retval none
   */
  static inline void cntDirSet(Register& reg, CountMode countMode) {
    /* set the cnt direct */
    reg.ctrl1_bit.cnt_dir = static_cast<uint8_t>(countMode);
  }

  /**
   * @brief  set tmr counter value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  cntValue (for 16 bit tmr 0x0000~0xFFFF,
   *                        for 32 bit tmr 0x0000_0000~0xFFFF_FFFF)
   * @retval none
   */
  static inline void counterValueSet(Register& reg, uint32_t cntValue) {
    /* set the tmr counter value */
    reg.cval = cntValue;
  }

  /**
   * @brief  get tmr counter value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @retval tmr counter value
   */
  static inline uint32_t counterValueGet(Register& reg) {
    return reg.cval;
  }

  /**
   * @brief  set tmr div value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  divValue (for 16 bit tmr 0x0000~0xFFFF,
   *                        for 32 bit tmr 0x0000_0000~0xFFFF_FFFF)
   * @retval none
   */
  static inline void divValueSet(Register& reg, uint32_t divValue) {
    /* set the tmr div value */
    reg.div = divValue;
  }

  /**
   * @brief  get tmr div value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @retval tmr div value
   */
  static inline uint32_t divValueGet(Register& reg) {
    return reg.div;
  }

  /**
   * @brief  set tmr period value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  prValue: timer period register value of counter
   *                       (for 16 bit tmr 0x0000~0xFFFF,
   *                       for 32 bit tmr 0x0000_0000~0xFFFF_FFFF)
   * @retval none
   */
  static inline void periodValueSet(Register& reg, uint32_t prValue) {
    /* set tmr period value */
    reg.pr = prValue;
  }

  /**
   * @brief  get tmr period value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @retval timer period register value of counter
   *         (for 16 bit tmr 0x0000~0xFFFF, for 32 bit tmr
   *         0x0000_0000~0xFFFF_FFFF)
   */
  static inline uint32_t periodValueGet(Register& reg) {
    return reg.pr;
  }

  /**
   * @brief  enable tmr period buffer
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static void periodBufferEnable(Register& reg, bool newState) {
    /* tmr period buffer set */
    reg.ctrl1_bit.prben = newState;
  }

  /**
   * @brief  enable or disable tmr one cycle mode
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void oneCycleModeEnable(Register& reg, bool newState) {
    /* tmr one cycle mode enable */
    reg.ctrl1_bit.ocmen = newState;
  }

  /**
   * @brief  select tmr the overflow event sources
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void overflowRequestSourceSet(Register& reg, bool newState) {
    reg.ctrl1_bit.ovfs = newState;
  }

  /**
   * @brief  enable or disable tmr overflow event generation
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void overflowEventDisable(Register& reg, bool newState) {
    reg.ctrl1_bit.ovfen = newState;
  }

  /**
   * @brief  select tmr channel1 input
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5
   * @param  inputConnected
   *         this parameter can be one of the following values:
   *         - C1IRAW
   *         - C1IRAW_XOR
   * @retval none
   */
  static void channelInputSelect(Register& reg, channel::InputConnected inputConnected) {
    reg.ctrl2_bit.c1insel = static_cast<uint8_t>(inputConnected);
  }

  /**
   * @brief  select tmr primary mode
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5
   * @param  primary_mode
   *         this parameter can be one of the following values:
   *         - PrimarySelect::RESET
   *         - PrimarySelect::ENABLE
   *         - PrimarySelect::OVERFLOW
   *         - PrimarySelect::COMPARE
   *         - PrimarySelect::C1ORAW
   *         - PrimarySelect::C2ORAW
   *         - PrimarySelect::C3ORAW
   *         - PrimarySelect::C4ORAW
   * @retval none
   */
  static inline void primaryModeSelect(Register& reg, PrimarySelect primaryMode) {
    reg.ctrl2_bit.ptos = static_cast<uint8_t>(primaryMode);
    return;
  }

  /**
   * @brief  select tmr subordinate mode
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @param  subMode
   *         this parameter can be one of the following values:
   *         - subordinate::ModeSelect::DIABLE
   *         - subordinate::ModeSelect::ENCODER_A
   *         - subordinate::ModeSelect::ENCODER_B
   *         - subordinate::ModeSelect::ENCODER_C
   *         - subordinate::ModeSelect::RESET
   *         - subordinate::ModeSelect::HANG
   *         - subordinate::ModeSelect::TRIGGER
   *         - subordinate::ModeSelect::EXTERNAL_CLOCK_A
   * @retval none
   */
  static inline void subModeSelect(Register& reg, subordinate::ModeSelect subMode) {
    reg.stctrl_bit.smsel = static_cast<uint8_t>(subMode);
    return;
  }

  /**
   * @brief  select tmr channel dma
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @param  requestSource
   *         this parameter can be one of the following values:
   *         - dma::RequestSource::CHANNEL
   *         - dma::RequestSource::OVERFLOW
   * @retval none
   */
  static inline void channelDmaSelect(Register& reg, dma::RequestSource requestSource) {
    reg.ctrl2_bit.drs = static_cast<uint8_t>(requestSource);
    return;
  }

  /**
   * @brief  select tmr hall
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void hallSelect(Register& reg, bool newState) {
    reg.ctrl2_bit.ccfs = newState;
    return;
  }

  /**
   * @brief  enable tmr channel buffer
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void channelBufferEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.cbctrl = newState;
    return;
  }

  /**
   * @brief  select tmr sub-trigger
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @param  triggerSelect
   *         this parameter can be one of the following values:
   *         - subordinate::InputSelect::IS0
   *         - subordinate::InputSelect::IS1
   *         - subordinate::InputSelect::IS2
   *         - subordinate::InputSelect::IS3
   *         - subordinate::InputSelect::C1INC
   *         - subordinate::InputSelect::C1DF1
   *         - subordinate::InputSelect::C2DF2
   *         - subordinate::InputSelect::EXTIN
   */
  static inline void triggerInputSelect(Register& reg, subordinate::InputSelect triggerSelect) {
    reg.stctrl_bit.stis = static_cast<uint8_t>(triggerSelect);
  }

  /**
   * @brief  set tmr subordinate synchronization mode
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void subSyncModeSet(Register& reg, bool newState) {
    reg.stctrl_bit.sts = newState;
    return;
  }

  /**
   * @brief  enable or disable tmr dma request
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  dmaRequest
   *         this parameter can be one of the following values:
   *         - dma::Request::OVERFLOW
   *         - dma::Request::C1
   *         - dma::Request::C2
   *         - dma::Request::C3
   *         - dma::Request::C4
   *         - dma::Request::HALL
   *         - dma::Request::TRIGGER
   * @param  newState
   * @retval none
   */
  static inline void dmaRequestEnable(Register& reg, dma::Request dmaRequest, bool newState) {
    if (newState)
      reg.iden |= static_cast<uint8_t>(dmaRequest);

    else
      reg.iden &= ~static_cast<uint8_t>(dmaRequest);

    return;
  }

  /**
   * @brief  enable or disable tmr interrupt
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  interrupt
   *         this parameter can be one of the following values:
   *         - Interrupt::OVF
   *         - Interrupt::C1
   *         - Interrupt::C2
   *         - Interrupt::C3
   *         - Interrupt::C4
   *         - Interrupt::HALL
   *         - Interrupt::TRIGGER
   *         - Interrupt::BRK
   * @param  newState
   * @retval none
   */
  static inline void interruptEnable(Register& reg, Interrupt interrupt, bool newState) {
    if (newState)
      reg.iden |= static_cast<uint32_t>(interrupt);
    else
      reg.iden &= ~static_cast<uint32_t>(interrupt);

    return;
  }

  /**
   * @brief  get tmr flag
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  flag
   *         this parameter can be one of the following values:
   *         - Flag::OVF
   *         - Flag::C1
   *         - Flag::C2
   *         - Flag::C3
   *         - Flag::C4
   *         - Flag::HALL
   *         - Flag::TRIGGER
   *         - Flag::BRK
   *         - Flag::C1_RECAPTURE
   *         - Flag::C2_RECAPTURE
   *         - Flag::C3_RECAPTURE
   *         - Flag::C4_RECAPTURE
   * @retval state of tmr flag
   */
  static inline bool flagGet(Register& reg, Flag flag) {
    return reg.ists & static_cast<uint32_t>(flag);
  }

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  tmr reset by crm reset register
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @retval none
   */
  static void reset(Register& reg);

  /**
   * @brief  init tmr output default para
   * @param  outputStruct
   *         - to the structure of tmr_output_config_type
   * @retval none
   */
  static void outputDefaultParaInit(output::Config& outputStruct);

  /**
   * @brief  init tmr input default para
   * @param  inputStruct
   *         - to the structure of tmr_input_config_type
   * @retval none
   */
  static void inputDefaultParaInit(input::Config& inputStruct);

  /**
   * @brief  init tmr brkdt default para
   * @param  breakDutyConfig
   *         - to the structure of tmr_brkdt_config_type
   * @retval none
   */
  static void brkdtDefaultParaInit(BreakDutyConfig& breakDutyConfig);

  /**
   * @brief  init tmr base
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_pr (for 16 bit tmr 0x0000~0xFFFF,
   *                  for 32 bit tmr 0x0000_0000~0xFFFF_FFFF)
   * @param  tmr_div (timer div value:0x0000~0xFFFF)
   * @retval none
   */
  static void baseInit(Register& reg, uint32_t pr, uint32_t div);

  /**
   * @brief  set the repetition counter register(rpr) value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1
   * @param  tmr_rpr_value (0x00~0xFF)
   * @retval none
   */
  static void repetitionCounterSet(Register& reg, uint8_t rprValue);

  /**
   * @brief  config tmr output channel
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  tmr_output_struct
   *         - to the structure of tmr_output_config_type
   * @retval none
   */
  static void outputChannelConfig(Register& reg, channel::Select channel, output::Config& outputStruct);

  /**
   * @brief  select tmr output channel mode
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  oc_mode
   *         this parameter can be one of the following values:
   *         - TMR_OUTPUT_CONTROL_OFF
   *         - TMR_OUTPUT_CONTROL_HIGH
   *         - TMR_OUTPUT_CONTROL_LOW
   *         - TMR_OUTPUT_CONTROL_SWITCH
   *         - TMR_OUTPUT_CONTROL_FORCE_HIGH
   *         - TMR_OUTPUT_CONTROL_FORCE_LOW
   *         - TMR_OUTPUT_CONTROL_PWM_MODE_A
   *         - TMR_OUTPUT_CONTROL_PWM_MODE_B
   * @retval none
   */
  static void outputChannelModeSelect(Register& reg, channel::Select channel, output::ControlMode ocMode);

  /**
   * @brief  set tmr channel value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  tmr_channel_value (for 16 bit tmr 0x0000~0xFFFF,
   *                       for 32 bit tmr 0x0000_0000~0xFFFF_FFFF)
   * @retval none
   */

  static void channelValueSet(Register& reg, channel::Select channel, uint32_t channelValue);
  /**
   * @brief  get tmr channel value
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @retval tmr channel value
   */
  static uint32_t channelValueGet(Register& reg, channel::Select channel);

  /**
   * @brief  enable tmr output channel buffer
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static void outputChannelBufferEnable(Register& reg, channel::Select channel, bool newState);

  /**
   * @brief  set tmr output channel immediately
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static void outputChannelImmediatelySet(Register& reg, channel::Select channel, bool newState);

  /**
   * @brief  set tmr output channel switch
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static void outputChannelSwitchSet(Register& reg, channel::Select channel, bool newState);

  /**
   * @brief  enable or disable  tmr 32 bit function(plus mode)
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR2, TMR5
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static void bit32FunctionEnable(Register& reg, bool newState);

  /**
   * @brief  init tmr input channel
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  config
   *         - to the structure of tmr_input_config_type
   * @param  divider
   *         this parameter can be one of the following values:
   *         - DIV1
   *         - DIV2
   *         - DIV4
   *         - DIV8
   * @retval none
   */
  static void inputChannelInit(Register& reg, input::Config& config, input::Divider divider);

  /**
   * @brief  tmr channel enable
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL1C
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL2C
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL3C
   *         - channel::Select::CHANNEL4
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static void channelEnable(Register& reg, channel::Select channel, bool newState);

  /**
   * @brief  set tmr input channel filter
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  filterValue (0x0~0xf)
   * @retval none
   */
  static void inputChannelfilterSet(Register& reg, channel::Select channel, uint16_t filterValue);

  /**
   * @brief  config tmr pwm input
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  config
   *         - to the structure of tmr_input_config_type
   * @param  divider
   *         this parameter can be one of the following values:
   *         - input::Divider::DIV1
   *         - input::Divider::DIV2
   *         - input::Divider::DIV4
   *         - input::Divider::DIV8
   * @retval none
   */
  static void pwmInputConfig(Register& reg, input::Config& config, input::Divider divider);

  /**
   * @brief  set tmr input channel divider
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  divider
   *         this parameter can be one of the following values:
   *         - input::Divider::DIV1
   *         - input::Divider::DIV2
   *         - input::Divider::DIV4
   *         - input::Divider::DIV8
   * @retval none
   */
  static void inputChannelDividerSet(Register& reg, channel::Select channel, input::Divider divider);

  /**
   * @brief  clear tmr flag
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  flag
   *         this parameter can be any combination of the following values:
   *         - Flag::OVF
   *         - Flag::C1
   *         - Flag::C2
   *         - Flag::C3
   *         - Flag::C4
   *         - Flag::HALL
   *         - Flag::TRIGGER
   *         - Flag::BRK
   *         - Flag::C1_RECAPTURE
   *         - Flag::C2_RECAPTURE
   *         - Flag::C3_RECAPTURE
   *         - Flag::C4_RECAPTURE
   * @retval none
   */
  static inline void flagClear(Register& reg, Flag flag) {
    reg.ists = ~static_cast<uint32_t>(flag);
    return;
  }

  /**
   * @brief  generate tmr event
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_event
   *         this parameter can be one of the following values:
   *         - EventTrigger::OVERFLOW
   *         - EventTrigger::C1
   *         - EventTrigger::C2
   *         - EventTrigger::C3
   *         - EventTrigger::C4
   *         - EventTrigger::HALL
   *         - EventTrigger::TRIGGER
   *         - EventTrigger::BRK
   * @retval none
   */
  static inline void eventSwTrigger(Register& reg, EventTrigger event) {
    reg.swevt |= static_cast<uint32_t>(event);
    return;
  }

  /**
   * @brief  tmr output enable(oen),this function is important for advtm output enable
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1
   * @param  newState (TRUE or FALSE)
   * @retval none
   */
  static inline void outputEnable(Register& reg, bool newState) {
    reg.brk_bit.oen = newState;
  }

  /**
   * @brief  set tmr select internal clock
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @retval none
   */
  static inline void internalClockSet(Register& reg) {
    reg.stctrl_bit.smsel = static_cast<uint8_t>(subordinate::ModeSelect::DISABLE);
    return;
  }

  /**
   * @brief  set tmr output channel polarity
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   *         - channel::Select::CHANNEL1C
   *         - channel::Select::CHANNEL2C
   *         - channel::Select::CHANNEL3C
   * @param  oc_polarity
   *         this parameter can be one of the following values:
   *         - TMR_POLARITY_ACTIVE_HIGH
   *         - TMR_POLARITY_ACTIVE_LOW
   * @retval none
   */
  static void outputChannelPolaritySet(Register& reg, channel::Select channel, PolarityActive ocPolarity);

  /**
   * @brief  config tmr external clock
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5
   * @param  es_divide
   *         this parameter can be one of the following values:
   *         - external::Divider::DIV1
   *         - external::Divider::DIV2
   *         - external::Divider::DIV4
   *         - external::Divider::DIV8
   * @param  es_polarity
   *         this parameter can be one of the following values:
   *         - external::Polarity::NON_INVERTED
   *         - external::Polarity::INVERTED
   * @param  es_filter (0x0~0xf)
   */
  static void externalClockConfig(Register& reg, external::Divider esDivide, external::Polarity esPolarity, uint16_t esfilter);

  /**
   * @brief  config tmr external clock mode1
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9
   * @param  divide
   *         this parameter can be one of the following values:
   *         - external::Divider::DIV1
   *         - external::Divider::DIV2
   *         - external::Divider::DIV4
   *         - external::Divider::DIV8
   * @param  polarity
   *         this parameter can be one of the following values:
   *         - external::Polarity::NON_INVERTED
   *         - external::Polarity::INVERTED
   * @param  filter (0x0~0xf)
   * @retval none
   */
  static void externalClockMode1Config(Register& reg, external::Divider divider, external::Polarity polarity, uint16_t filter);

  /**
   * @brief  config tmr external clock mode2
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5
   * @param  divider
   *         this parameter can be one of the following values:
   *         - external::Divider::DIV1
   *         - external::Divider::DIV2
   *         - external::Divider::DIV4
   *         - external::Divider::DIV8
   * @param  polarity
   *         this parameter can be one of the following values:
   *         - external::Polarity::NON_INVERTED
   *         - external::Polarity::INVERTED
   * @param  filter (0x0~0xf)
   * @retval none
   */
  static void externalClockMode2Config(Register& reg, external::Divider divider, external::Polarity polarity, uint16_t filter);

  /**
   * @brief  config tmr encoder mode
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5
   * @param  encoder_mode
   *         this parameter can be one of the following values:
   *         - TMR_ENCODER_MODE_A
   *         - TMR_ENCODER_MODE_B
   *         - TMR_ENCODER_MODE_C
   * @param  ic1_polarity
   *         this parameter can be one of the following values:
   *         - TMR_INPUT_RISING_EDGE
   *         - TMR_INPUT_FALLING_EDGE
   *         - TMR_INPUT_BOTH_EDGE
   * @param  ic2_polarity
   *         this parameter can be one of the following values:
   *         - TMR_INPUT_RISING_EDGE
   *         - TMR_INPUT_FALLING_EDGE
   *         - TMR_INPUT_BOTH_EDGE
   * @retval none
   */
  static void encoderModeConfig(Register& reg, EncoderMode encoderMode, input::Polarity ic1Polarity, input::Polarity ic2Polarity);

  /**
   * @brief  set tmr force output
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5, TMR9, TMR10, TMR11
   * @param  tmr_channel
   *         this parameter can be one of the following values:
   *         - channel::Select::CHANNEL1
   *         - channel::Select::CHANNEL2
   *         - channel::Select::CHANNEL3
   *         - channel::Select::CHANNEL4
   * @param  force_output
   *         this parameter can be one of the following values:
   *         - TMR_FORCE_OUTPUT_HIGH
   *         - TMR_FORCE_OUTPUT_LOW
   * @retval none
   */
  static void forceOutputSet(Register& reg, channel::Select channel, output::Force forceOutput);

  /**
   * @brief  config tmr dma control
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1, TMR2, TMR3, TMR4, TMR5
   * @param  dma_length
   *         this parameter can be one of the following values:
   *         - TMR_DMA_TRANSFER_1BYTE
   *         - TMR_DMA_TRANSFER_2BYTES
   *         - TMR_DMA_TRANSFER_3BYTES
   *         ...
   *         - TMR_DMA_TRANSFER_17BYTES
   *         - TMR_DMA_TRANSFER_18BYTES
   * @param  dma_base_address
   *         this parameter can be one of the following values:
   *         - TMR_CTRL1_ADDRESS
   *         - TMR_CTRL2_ADDRESS
   *         - TMR_STCTRL_ADDRESS
   *         - TMR_IDEN_ADDRESS
   *         - TMR_ISTS_ADDRESS
   *         - TMR_SWEVT_ADDRESS
   *         - TMR_CM1_ADDRESS
   *         - TMR_CM2_ADDRESS
   *         - TMR_CCTRL_ADDRESS
   *         - TMR_CVAL_ADDRESS
   *         - TMR_DIV_ADDRESS
   *         - TMR_PR_ADDRESS
   *         - TMR_RPR_ADDRESS
   *         - TMR_C1DT_ADDRESS
   *         - TMR_C2DT_ADDRESS
   *         - TMR_C3DT_ADDRESS
   *         - TMR_C4DT_ADDRESS
   *         - TMR_BRK_ADDRESS
   *         - TMR_DMACTRL_ADDRESS
   * @retval none
   */
  static void dmaControlConfig(Register& reg, dma::TransferLength dmaLength, dma::BaseAddress dmaBaseAddress);

  /**
   * @brief  config tmr break mode and dead-time
   * @param  reg: select the tmr peripheral.
   *         this parameter can be one of the following values:
   *         TMR1
   * @param  brkdt_struct
   *         - to the structure of tmr_brkdt_config_type
   * @retval none
   */
  static void brkdtConfig(Register& reg, BreakDutyConfig& brkdtStruct);

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

#endif /* CHIP_22D1950D_0E59_4772_9CB3_21586637F24F */
