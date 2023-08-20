/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F4FCF7C7_7A29_4865_BF90_32ED6A92AF8E
#define CHIP_F4FCF7C7_7A29_4865_BF90_32ED6A92AF8E

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../Processor.h"
#include "./../dma/Channel.h"
#include "./../dma/ChannelRegister.h"
#include "./../dma/Config.h"
#include "./../dma/Direction.h"
#include "./../dma/Flag.h"
#include "./../dma/Flexible.h"
#include "./../dma/Interrupt.h"
#include "./../dma/MemoryDataSize.h"
#include "./../dma/MemoryInc.h"
#include "./../dma/PeripheralDataSize.h"
#include "./../dma/PeripheralInc.h"
#include "./../dma/PriorityLevel.h"
#include "./../dma/Register.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  class DMA;
  extern Register& DMA1;
  extern ChannelRegister& DMA1_CHANNEL1;
  extern ChannelRegister& DMA1_CHANNEL2;
  extern ChannelRegister& DMA1_CHANNEL3;
  extern ChannelRegister& DMA1_CHANNEL4;
  extern ChannelRegister& DMA1_CHANNEL5;
  extern ChannelRegister& DMA1_CHANNEL6;
  extern ChannelRegister& DMA1_CHANNEL7;

  extern Register& DMA2;
  extern ChannelRegister& DMA2_CHANNEL1;
  extern ChannelRegister& DMA2_CHANNEL2;
  extern ChannelRegister& DMA2_CHANNEL3;
  extern ChannelRegister& DMA2_CHANNEL4;
  extern ChannelRegister& DMA2_CHANNEL5;
  extern ChannelRegister& DMA2_CHANNEL6;
  extern ChannelRegister& DMA2_CHANNEL7;
}  // namespace chip::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::dma::DMA {
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
  DMA(void) = default;

  virtual ~DMA(void) = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
 public:
  /**
   * @brief  set the number of data to be transferred
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1_CHANNEL1
   *         - DMA1_CHANNEL2
   *         - DMA1_CHANNEL3
   *         - DMA1_CHANNEL4
   *         - DMA1_CHANNEL5
   *         - DMA1_CHANNEL6
   *         - DMA1_CHANNEL7
   *         - DMA2_CHANNEL1
   *         - DMA2_CHANNEL2
   *         - DMA2_CHANNEL3
   *         - DMA2_CHANNEL4
   *         - DMA2_CHANNEL5
   *         - DMA2_CHANNEL6
   *         - DMA2_CHANNEL7
   * @param  data_number: the number of data to be transferred(0x0000~0xFFFF)
   *         transfer.
   * @retval none.
   */
  static void dataNumberSet(ChannelRegister& reg, uint16_t dataNumber) {
    reg.dtcnt = dataNumber;
    return;
  }

  /**
   * @brief  get number of data from dtcnt register
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1_CHANNEL1
   *         - DMA1_CHANNEL2
   *         - DMA1_CHANNEL3
   *         - DMA1_CHANNEL4
   *         - DMA1_CHANNEL5
   *         - DMA1_CHANNEL6
   *         - DMA1_CHANNEL7
   *         - DMA2_CHANNEL1
   *         - DMA2_CHANNEL2
   *         - DMA2_CHANNEL3
   *         - DMA2_CHANNEL4
   *         - DMA2_CHANNEL5
   *         - DMA2_CHANNEL6
   *         - DMA2_CHANNEL7
   * @retval the number of data.
   */
  static inline uint16_t dataNumberGet(ChannelRegister& reg) {
    return static_cast<uint16_t>(reg.dtcnt);
  }

  /**
   * @brief  enable or disable dma interrupt
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1_CHANNEL1
   *         - DMA1_CHANNEL2
   *         - DMA1_CHANNEL3
   *         - DMA1_CHANNEL4
   *         - DMA1_CHANNEL5
   *         - DMA1_CHANNEL6
   *         - DMA1_CHANNEL7
   *         - DMA2_CHANNEL1
   *         - DMA2_CHANNEL2
   *         - DMA2_CHANNEL3
   *         - DMA2_CHANNEL4
   *         - DMA2_CHANNEL5
   *         - DMA2_CHANNEL6
   *         - DMA2_CHANNEL7
   * @param  dma_int:
   *         this parameter can be any combination of the following values:
   *         - DMA_FDT_INT
   *         - DMA_HDT_INT
   *         - DMA_DTERR_INT
   * @param  new_state (TRUE or FALSE)
   * @retval none
   */
  static void inline interruptEnable(ChannelRegister& reg, Interrupt interrupt, bool newState) {
    if (newState)
      reg.ctrl |= static_cast<uint32_t>(interrupt);
    else
      reg.ctrl &= ~static_cast<uint32_t>(interrupt);

    return;
  }

  /**
   * @brief  enable or disable dma channely
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1_CHANNEL1
   *         - DMA1_CHANNEL2
   *         - DMA1_CHANNEL3
   *         - DMA1_CHANNEL4
   *         - DMA1_CHANNEL5
   *         - DMA1_CHANNEL6
   *         - DMA1_CHANNEL7
   *         - DMA2_CHANNEL1
   *         - DMA2_CHANNEL2
   *         - DMA2_CHANNEL3
   *         - DMA2_CHANNEL4
   *         - DMA2_CHANNEL5
   *         - DMA2_CHANNEL6
   *         - DMA2_CHANNEL7
   * @param  new_state (TRUE or FALSE)
   * @retval None
   */
  static inline void channelEnable(ChannelRegister& reg, bool newState) {
    reg.ctrl_bit.chen = newState;
    return;
  }

  /**
   * @brief  get dma flag
   * @param  dmax_flag
   *         this parameter can be one of the following values:
   *         - DMA1_GL1        - DMA1_FDT1        - DMA1_HDT1        - DMA1_DTERR1
   *         - DMA1_GL2        - DMA1_FDT2        - DMA1_HDT2        - DMA1_DTERR2
   *         - DMA1_GL3        - DMA1_FDT3        - DMA1_HDT3        - DMA1_DTERR3
   *         - DMA1_GL4        - DMA1_FDT4        - DMA1_HDT4        - DMA1_DTERR4
   *         - DMA1_GL5        - DMA1_FDT5        - DMA1_HDT5        - DMA1_DTERR5
   *         - DMA1_GL6        - DMA1_FDT6        - DMA1_HDT6        - DMA1_DTERR6
   *         - DMA1_GL7        - DMA1_FDT7        - DMA1_HDT7        - DMA1_DTERR7
   *         - DMA2_GL1        - DMA2_FDT1        - DMA2_HDT1        - DMA2_DTERR1
   *         - DMA2_GL2        - DMA2_FDT2        - DMA2_HDT2        - DMA2_DTERR2
   *         - DMA2_GL3        - DMA2_FDT3        - DMA2_HDT3        - DMA2_DTERR3
   *         - DMA2_GL4        - DMA2_FDT4        - DMA2_HDT4        - DMA2_DTERR4
   *         - DMA2_GL5        - DMA2_FDT5        - DMA2_HDT5        - DMA2_DTERR5
   *         - DMA2_GL6        - DMA2_FDT6        - DMA2_HDT6        - DMA2_DTERR6
   *         - DMA2_GL7        - DMA2_FDT7        - DMA2_HDT7        - DMA2_DTERR7
   * @retval state of dma flag
   */
  static inline bool flagGet(Flag flag) {
    if ((flag & Flag::DMA2_MARK) == Flag::DMA2_MARK)
      return (DMA2.sts & static_cast<uint32_t>(flag));

    else
      return (DMA1.sts & static_cast<uint32_t>(flag));
  }

  /**
   * @brief  clear dma flag
   * @param  dmax_flag
   *         this parameter can be one of the following values:
   *         - DMA1_GL1        - DMA1_FDT1        - DMA1_HDT1        - DMA1_DTERR1
   *         - DMA1_GL2        - DMA1_FDT2        - DMA1_HDT2        - DMA1_DTERR2
   *         - DMA1_GL3        - DMA1_FDT3        - DMA1_HDT3        - DMA1_DTERR3
   *         - DMA1_GL4        - DMA1_FDT4        - DMA1_HDT4        - DMA1_DTERR4
   *         - DMA1_GL5        - DMA1_FDT5        - DMA1_HDT5        - DMA1_DTERR5
   *         - DMA1_GL6        - DMA1_FDT6        - DMA1_HDT6        - DMA1_DTERR6
   *         - DMA1_GL7        - DMA1_FDT7        - DMA1_HDT7        - DMA1_DTERR7
   *         - DMA2_GL1        - DMA2_FDT1        - DMA2_HDT1        - DMA2_DTERR1
   *         - DMA2_GL2        - DMA2_FDT2        - DMA2_HDT2        - DMA2_DTERR2
   *         - DMA2_GL3        - DMA2_FDT3        - DMA2_HDT3        - DMA2_DTERR3
   *         - DMA2_GL4        - DMA2_FDT4        - DMA2_HDT4        - DMA2_DTERR4
   *         - DMA2_GL5        - DMA2_FDT5        - DMA2_HDT5        - DMA2_DTERR5
   *         - DMA2_GL6        - DMA2_FDT6        - DMA2_HDT6        - DMA2_DTERR6
   *         - DMA2_GL7        - DMA2_FDT7        - DMA2_HDT7        - DMA2_DTERR7
   * @retval none
   */
  static inline void flagClear(Flag flag) {
    if ((flag & Flag::DMA2_MARK) == Flag::DMA2_MARK)
      DMA2.clr = (static_cast<uint32_t>(flag) & 0x0FFFFFFF);

    else
      DMA1.clr = static_cast<uint32_t>(flag);

    return;
  }
  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  reset the dmax channely registers.
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1_CHANNEL1
   *         - DMA1_CHANNEL2
   *         - DMA1_CHANNEL3
   *         - DMA1_CHANNEL4
   *         - DMA1_CHANNEL5
   *         - DMA1_CHANNEL6
   *         - DMA1_CHANNEL7
   *         - DMA2_CHANNEL1
   *         - DMA2_CHANNEL2
   *         - DMA2_CHANNEL3
   *         - DMA2_CHANNEL4
   *         - DMA2_CHANNEL5
   *         - DMA2_CHANNEL6
   *         - DMA2_CHANNEL7
   * @retval none
   */
  static void reset(ChannelRegister& reg);

  /**
   * @brief  dma init config with its default value.
   * @param  config : pointer to a dma_init_type structure which will
   *         be initialized.
   * @retval none
   */
  static void defaultParaInit(Config& config);

  /**
   * @brief  dma init
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1_CHANNEL1
   *         - DMA1_CHANNEL2
   *         - DMA1_CHANNEL3
   *         - DMA1_CHANNEL4
   *         - DMA1_CHANNEL5
   *         - DMA1_CHANNEL6
   *         - DMA1_CHANNEL7
   *         - DMA2_CHANNEL1
   *         - DMA2_CHANNEL2
   *         - DMA2_CHANNEL3
   *         - DMA2_CHANNEL4
   *         - DMA2_CHANNEL5
   *         - DMA2_CHANNEL6
   *         - DMA2_CHANNEL7
   * @param  dma_initstruct : pointer to a dma_init_type structure.
   * @retval none
   */
  static void init(ChannelRegister& reg, Config& config);

  /**
   * @brief  initialize the reg flexible function according to the specified parameters.
   * @param  reg:
   *         this parameter can be one of the following values:
   *         - DMA1
   *         - DMA2
   * @param  flex_channelx:
   *         this parameter can be one of the following values:
   *         - Channel::CHANNEL1
   *         - Channel::CHANNEL2
   *         - Channel::CHANNEL3
   *         - Channel::CHANNEL4
   *         - Channel::CHANNEL5
   *         - Channel::CHANNEL6
   *         - Channel::CHANNEL7
   * @param  flexible_request: every peripheral have specified hardware_id.
   *         this parameter can be one of the following values:
   *         - Flexible::ADC1         - Flexible::SPI1_RX      - Flexible::SPI1_TX      - Flexible::SPI2_RX
   *         - Flexible::SPI2_TX      - Flexible::UART1_RX     - Flexible::UART1_TX     - Flexible::UART2_RX
   *         - Flexible::UART2_TX     - Flexible::UART3_RX     - Flexible::UART3_TX     - Flexible::UART4_RX
   *         - Flexible::UART4_TX     - Flexible::UART5_RX     - Flexible::UART5_TX     - Flexible::I2C1_RX
   *         - Flexible::I2C1_TX      - Flexible::I2C2_RX      - Flexible::I2C2_TX      - Flexible::SDIO1
   *         - Flexible::TMR1_TRIG    - Flexible::TMR1_HALL    - Flexible::TMR1_OVERFLOW- Flexible::TMR1_CH1
   *         - Flexible::TMR1_CH2     - Flexible::TMR1_CH3     - Flexible::TMR1_CH4     - Flexible::TMR2_TRIG
   *         - Flexible::TMR2_OVERFLOW- Flexible::TMR2_CH1     - Flexible::TMR2_CH2     - Flexible::TMR2_CH3
   *         - Flexible::TMR2_CH4     - Flexible::TMR3_TRIG    - Flexible::TMR3_OVERFLOW- Flexible::TMR3_CH1
   *         - Flexible::TMR3_CH2     - Flexible::TMR3_CH3     - Flexible::TMR3_CH4     - Flexible::TMR4_TRIG
   *         - Flexible::TMR4_OVERFLOW- Flexible::TMR4_CH1     - Flexible::TMR4_CH2     - Flexible::TMR4_CH3
   *         - Flexible::TMR4_CH4     - Flexible::TMR5_TRIG    - Flexible::TMR5_OVERFLOW- Flexible::TMR5_CH1
   *         - Flexible::TMR5_CH2     - Flexible::TMR5_CH3     - Flexible::TMR5_CH4
   * @retval none
   */
  static void flexibleConfig(Register& reg, Channel channel, Flexible flexible);

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

#endif /* CHIP_F4FCF7C7_7A29_4865_BF90_32ED6A92AF8E */
