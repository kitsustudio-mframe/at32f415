/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_58CF5083_706E_4A10_B60C_0994F1B8798E
#define CHIP_58CF5083_706E_4A10_B60C_0994F1B8798E

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../Processor.h"
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./BreakBit.h"
#include "./ClockLast.h"
#include "./ClockPhase.h"
#include "./ClockPolarity.h"
#include "./DataBit.h"
#include "./Flag.h"
#include "./HardwareFlow.h"
#include "./Interrupt.h"
#include "./ParitySelection.h"
#include "./Register.h"
#include "./StopBit.h"
#include "./WakeupMode.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::usart {
  class USART;
  extern Register& USART1;
  extern Register& USART2;
  extern Register& USART3;
  extern Register& UART4;
  extern Register& UART5;
}  // namespace chip::usart

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::usart::USART : public mframe::lang::Object {
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
  USART(void);

  virtual ~USART(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  enable or disable the specified usart peripheral.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: new state of the usart peripheral.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void enable(Register& reg, bool newState) {
    reg.ctrl1_bit.uen = newState;
    return;
  }

  /**
   * @brief  usart transmitter enable.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: TRUE or FALSE.
   * @retval none
   */
  static inline void transmitterEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.ten = newState;
    return;
  }

  /**
   * @brief  usart receiver enable.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: TRUE or FALSE.
   * @retval none
   */
  static inline void receiverEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.ren = newState;
    return;
  }

  /**
   * @brief  usart enable the ck pin.
   * @note   clock enable are not available for UART4 or UART5.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2 or USART3.
   * @param  new_state: TRUE or FALSE
   * @retval none
   */
  static inline void clockEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.clken = newState;
    return;
  }

  /**
   * @brief  enable or disable the usart's dma transmitter interface.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: new state of the dma request sources.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void dmaTransmitterEnable(Register& reg, bool newState) {
    reg.ctrl3_bit.dmaten = newState;
    return;
  }

  /**
   * @brief  enable or disable the usart's dma receiver interface.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: new state of the dma request sources.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void dmaReceiverEnable(Register& reg, bool newState) {
    reg.ctrl3_bit.dmaren = newState;
    return;
  }

  /**
   * @brief  set the wakeup id of the usart.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  usart_id: the matching id(0x0~0xF).
   * @retval none
   */
  static inline void wakeupIdSet(Register& reg, uint8_t id) {
    reg.ctrl2_bit.id = id;
    return;
  }

  /**
   * @brief  select the usart wakeup method in multi-processor communication.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  wakeup_mode: determines the way to wake up usart method.
   *         this parameter can be one of the following values:
   *         - USART_WAKEUP_BY_IDLE_FRAME
   *         - USART_WAKEUP_BY_MATCHING_ID
   * @retval none
   */
  static inline void wakeupModeSet(Register& reg, WakeupMode wakeupMode) {
    reg.ctrl1_bit.wum = static_cast<uint8_t>(wakeupMode);
    return;
  }

  /**
   * @brief  config the usart in mute mode in multi-processor communication.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: new state of the usart mute mode.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void receiverMuteEnable(Register& reg, bool newState) {
    reg.ctrl1_bit.rm = newState;
    return;
  }

  /**
   * @brief  set the usart break frame bit num.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  break_bit: specifies the break bit num.
   *         this parameter can be one of the following values:
   *         - USART_BREAK_10BITS
   *         - USART_BREAK_11BITS
   * @retval none
   */
  static inline void breakBitNumSet(Register& reg, BreakBit breakBit) {
    reg.ctrl2_bit.bfbn = static_cast<uint8_t>(breakBit);
    return;
  }

  /**
   * @brief  enable or disable the usart lin mode.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  new_state: new state of the usart lin mode.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void linModeEnable(Register& reg, bool newState) {
    reg.ctrl2_bit.linen = newState;
    return;
  }

  /**
   * @brief  transmit single data through the usart peripheral.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  data: the data to transmit.
   * @retval none
   */
  static inline void dataTransmit(Register& reg, uint16_t data) {
    reg.dt = (data & 0x01FF);
    return;
  }

  /**
   * @brief  return the most recent received data by the usart peripheral.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @retval the received data.
   */
  static inline uint16_t dataReceive(Register& reg) {
    return static_cast<uint16_t>(reg.dt);
  }

  /**
   * @brief  transmit break characters.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @retval none
   */
  static inline void breakSend(Register& reg) {
    reg.ctrl1_bit.sbf = true;
    return;
  }

  /**
   * @brief  config the specified usart smartcard guard time.
   * @note   The guard time bits are not available for UART4 or UART5.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2 or USART3.
   * @param  guard_time_val: specifies the guard time (0x00~0xFF).
   * @retval none
   */
  static inline void smartcardGguardTimeSet(Register& reg, uint8_t guardTimeVal) {
    reg.gdiv_bit.scgt = guardTimeVal;
    return;
  }

  /**
   * @brief  config the irda/smartcard division.
   * @note   the division are not available for UART4 or UART5.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2 or USART3.
   * @param  div_val: specifies the division.
   * @retval none
   */
  static inline void irdaSmartcardDivisionSet(Register& reg, uint8_t divVal) {
    reg.gdiv_bit.isdiv = divVal;
    return;
  }

  /**
   * @brief  enable or disable the usart smart card mode.
   * @note   the smart card mode are not available for UART4 or UART5.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2 or USART3.
   * @param  new_state: new state of the smart card mode.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void smartcardModeEnable(Register& reg, bool newState) {
    reg.ctrl3_bit.scmen = newState;
    return;
  }

  /**
   * @brief  enable or disable nack transmission in smartcard mode.
   * @note   the smart card nack are not available for UART4 or UART5.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2 or USART3.
   * @param  new_state: new state of the nack transmission.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void smartcardNackSet(Register& reg, bool newState) {
    reg.ctrl3_bit.scnacken = newState;
    return;
  }

  /**
   * @brief  enable or disable the usart single line bidirectional half-duplex communication.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4 or UART5.
   * @param  new_state: new state of the single line half-duplex select.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void singleLineHalfduplexSelect(Register& reg, bool newState) {
    reg.ctrl3_bit.slben = newState;
    return;
  }

  /**
   * @brief  enable or disable the usart's irda interface.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4 or UART5.
   * @param  new_state: new state of the irda mode.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void irdaModeEnable(Register& reg, bool newState) {
    reg.ctrl3_bit.irdaen = newState;
    return;
  }

  /**
   * @brief  configure the usart's irda low power.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4 or UART5.
   * @param  new_state: new state of the irda mode.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static inline void irdaLowPowerEnable(Register& reg, bool newState) {
    reg.ctrl3_bit.irdalp = newState;
    return;
  }

  /**
   * @brief  check whether the specified usart flag is set or not.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4 or UART5.
   * @param  flag: specifies the flag to check.
   *         this parameter can be one of the following values:
   *         - USART_CTSCF_FLAG: cts change flag (not available for UART4, UART5)
   *         - USART_BFF_FLAG:   break frame flag
   *         - USART_TDBE_FLAG:  transmit data buffer empty flag
   *         - USART_TDC_FLAG:   transmit data complete flag
   *         - USART_RDBF_FLAG:  receive data buffer full flag
   *         - USART_IDLEF_FLAG: idle flag
   *         - USART_ROERR_FLAG: receiver overflow error flag
   *         - USART_NERR_FLAG:  noise error flag
   *         - USART_FERR_FLAG:  framing error flag
   *         - USART_PERR_FLAG:  parity error flag
   * @retval the new state of usart_flag (SET or RESET).
   */
  static inline bool flagGet(Register& reg, Flag flag) {
    if (reg.sts & static_cast<uint32_t>(flag))
      return true;

    return false;
  }

  /**
   * @brief  clear the usart's pending flags.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4 or UART5.
   * @param  flag: specifies the flag to clear.
   *         this parameter can be any combination of the following values:
   *         - USART_CTSCF_FLAG: (not available for UART4 or UART5).
   *         - USART_BFF_FLAG:
   *         - USART_TDC_FLAG:
   *         - USART_RDBF_FLAG:
   * @note
   *         - USART_PERR_FLAG, USART_FERR_FLAG, USART_NERR_FLAG, USART_ROERR_FLAG and USART_IDLEF_FLAG are cleared by software
   *           sequence: a read operation to usart sts register (usart_flag_get())
   *           followed by a read operation to usart dt register (usart_data_receive()).
   *         - USART_RDBF_FLAG can be also cleared by a read to the usart dt register(usart_data_receive()).
   *         - USART_TDC_FLAG can be also cleared by software sequence: a read operation to usart sts register (usart_flag_get())
   *           followed by a write operation to usart dt register (usart_data_transmit()).
   *         - USART_TDBE_FLAG is cleared only by a write to the usart dt register(usart_data_transmit()).
   * @retval none
   */
  static inline void flagClear(Register& reg, uint32_t flag) {
    reg.sts = ~flag;
    return;
  }

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  deinitialize the usart peripheral registers to their default reset values.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @retval none
   */
  static void reset(Register& reg);

  /**
   * @brief  initialize the usart peripheral according to the specified parameters.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  baud_rate: configure the usart communication baud rate.
   * @param  data_bit: data bits transmitted or received in a frame
   *         this parameter can be one of the following values:
   *         - USART_DATA_8BITS
   *         - USART_DATA_9BITS.
   * @param  stop_bit: stop bits transmitted
   *         this parameter can be one of the following values:
   *         - USART_STOP_1_BIT
   *         - USART_STOP_0_5_BIT.
   *         - USART_STOP_2_BIT
   *         - USART_STOP_1_5_BIT.
   * @retval none
   */
  static void init(Register& reg, uint32_t baudrate, DataBit dataBit, StopBit stopBit);

  /**
   * @brief  usart parity selection config.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  parity: select the none, odd or even parity.
   *         this parameter can be one of the following values:
   *         - USART_PARITY_NONE
   *         - USART_PARITY_EVEN.
   *         - USART_PARITY_ODD
   * @retval none
   */
  static void paritySelectionConfig(Register& reg, ParitySelection parity);

  /**
   * @brief  usart clock config.
   * @note   clock config are not available for UART4 or UART5.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2 or USART3.
   * @param  clk_pol: polarity of the clock output on the ck pin.
   *         this parameter can be one of the following values:
   *         - USART_CLOCK_POLARITY_LOW
   *         - USART_CLOCK_POLARITY_HIGH
   * @param  clk_pha: phase of the clock output on the ck pin.
   *         this parameter can be one of the following values:
   *         - USART_CLOCK_PHASE_1EDGE
   *         - USART_CLOCK_PHASE_2EDGE
   * @param  clk_lb: whether the clock pulse of the last data bit transmitted (MSB) is outputted on the ck pin.
   *         this parameter can be one of the following values:
   *         - USART_CLOCK_LAST_BIT_NONE
   *         - USART_CLOCK_LAST_BIT_OUTPUT
   * @retval none
   */
  static void clockConfig(Register& reg, ClockPolarity clockPolarity, ClockPhase clockPhase, ClockLast clk_lb);

  /**
   * @brief  enable or disable the specified usart interrupts.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3, UART4, or UART5.
   * @param  usart_int: specifies the USART interrupt sources to be enabled or disabled.
   *         this parameter can be one of the following values:
   *         - USART_IDLE_INT:  idle interrupt
   *         - USART_RDBF_INT:  rdbf interrupt
   *         - USART_TDC_INT:   tdc interrupt
   *         - USART_TDBE_INT:  tdbe interrupt
   *         - USART_PERR_INT:  perr interrupt
   *         - USART_BF_INT:    break frame interrupt
   *         - USART_ERR_INT:   err interrupt
   *         - USART_CTSCF_INT: ctscf interrupt
   * @param  new_state: new state of the specified usart interrupts.
   *         this parameter can be: TRUE or FALSE.
   * @retval none
   */
  static void interruptEnable(Register& reg, Interrupt interrupt, bool newState);

  /**
   * @brief  configure the usart's hardware flow control.
   * @param  usart_x: select the usart or the uart peripheral.
   *         this parameter can be one of the following values:
   *         USART1, USART2, USART3
   * @param  flow_state: specifies the hardware flow control.
   *         this parameter can be one of the following values:
   *         - USART_HARDWARE_FLOW_NONE
   *         - USART_HARDWARE_FLOW_RTS,
   *         - USART_HARDWARE_FLOW_CTS,
   *         - USART_HARDWARE_FLOW_RTS_CTS
   * @retval none
   */
  static void hardwareFlowControlSet(Register& reg, HardwareFlow hardwareFlow);

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

#endif /* CHIP_58CF5083_706E_4A10_B60C_0994F1B8798E */
