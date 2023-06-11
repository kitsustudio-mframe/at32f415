/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_895FED70_2682_4530_9863_24DD063C34C8
#define CHIP_895FED70_2682_4530_9863_24DD063C34C8

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "./../chip_irqn.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::misc {
  enum struct InterruptService : int;
}  // namespace chip::misc

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::misc::InterruptService : int {
  /******  cortex-m4 processor exceptions numbers ***************************************************/
  Reset = Reset_IRQn,                       /*!< 1 reset vector, invoked on power up and warm reset   */
  NonMaskableInt = NonMaskableInt_IRQn,     /*!< 2 non maskable interrupt                             */
  HardFault = HardFault_IRQn,               /*!< 3 hard fault, all classes of fault                   */
  MemoryManagement = MemoryManagement_IRQn, /*!< 4 cortex-m4 memory management interrupt              */
  BusFault = BusFault_IRQn,                 /*!< 5 cortex-m4 bus fault interrupt                      */
  UsageFault = UsageFault_IRQn,             /*!< 6 cortex-m4 usage fault interrupt                    */
  SVCall = SVCall_IRQn,                     /*!< 11 cortex-m4 sv call interrupt                       */
  DebugMonitor = DebugMonitor_IRQn,         /*!< 12 cortex-m4 debug monitor interrupt                 */
  PendSV = PendSV_IRQn,                     /*!< 14 cortex-m4 pend sv interrupt                       */
  SysTick = SysTick_IRQn,                   /*!< 15 cortex-m4 system tick interrupt                   */

  /******  at32 specific interrupt numbers *********************************************************/
  WWDT = WWDT_IRQn,                   /*!< window watchdog timer interrupt                      */
  PVM = PVM_IRQn,                     /*!< pvm through exint line detection interrupt           */
  TAMP_STAMP = TAMP_STAMP_IRQn,       /*!< tamper and timestamp interrupts through the exint line */
  ERTC_WKUP = ERTC_WKUP_IRQn,         /*!< ertc wakeup through the exint line                   */
  FLASH = FLASH_IRQn,                 /*!< flash global interrupt                               */
  CRM = CRM_IRQn,                     /*!< crm global interrupt                                 */
  EXINT0 = EXINT0_IRQn,               /*!< external line0 interrupt                             */
  EXINT1 = EXINT1_IRQn,               /*!< external line1 interrupt                             */
  EXINT2 = EXINT2_IRQn,               /*!< external line2 interrupt                             */
  EXINT3 = EXINT3_IRQn,               /*!< external line3 interrupt                             */
  EXINT4 = EXINT4_IRQn,               /*!< external line4 interrupt                             */
  DMA1_Channel1 = DMA1_Channel1_IRQn, /*!< dma1 channel 1 global interrupt                      */
  DMA1_Channel2 = DMA1_Channel2_IRQn, /*!< dma1 channel 2 global interrupt                      */
  DMA1_Channel3 = DMA1_Channel3_IRQn, /*!< dma1 channel 3 global interrupt                      */
  DMA1_Channel4 = DMA1_Channel4_IRQn, /*!< dma1 channel 4 global interrupt                      */
  DMA1_Channel5 = DMA1_Channel5_IRQn, /*!< dma1 channel 5 global interrupt                      */
  DMA1_Channel6 = DMA1_Channel6_IRQn, /*!< dma1 channel 6 global interrupt                      */
  DMA1_Channel7 = DMA1_Channel7_IRQn, /*!< dma1 channel 7 global interrupt                      */

  ADC1 = ADC1_IRQn,                               /*!< adc1 global interrupt                                */
  CAN1_TX = CAN1_TX_IRQn,                         /*!< can1 tx interrupts                                   */
  CAN1_RX0 = CAN1_RX0_IRQn,                       /*!< can1 rx0 interrupts                                  */
  CAN1_RX1 = CAN1_RX1_IRQn,                       /*!< can1 rx1 interrupt                                   */
  CAN1_SE = CAN1_SE_IRQn,                         /*!< can1 se interrupt                                    */
  EXINT9_5 = EXINT9_5_IRQn,                       /*!< external line[9:5] interrupts                        */
  TMR1_BRK_TMR9 = TMR1_BRK_TMR9_IRQn,             /*!< tmr1 brake interrupt                                 */
  TMR1_OVF_TMR10 = TMR1_OVF_TMR10_IRQn,           /*!< tmr1 overflow interrupt                              */
  TMR1_TRG_HALL_TMR11 = TMR1_TRG_HALL_TMR11_IRQn, /*!< tmr1 trigger and hall interrupt                      */
  TMR1_CH = TMR1_CH_IRQn,                         /*!< tmr1 channel interrupt                               */
  TMR2_GLOBAL = TMR2_GLOBAL_IRQn,                 /*!< tmr2 global interrupt                                */
  TMR3_GLOBAL = TMR3_GLOBAL_IRQn,                 /*!< tmr3 global interrupt                                */
  TMR4_GLOBAL = TMR4_GLOBAL_IRQn,                 /*!< tmr4 global interrupt                                */
  I2C1_EVT = I2C1_EVT_IRQn,                       /*!< i2c1 event interrupt                                 */
  I2C1_ERR = I2C1_ERR_IRQn,                       /*!< i2c1 error interrupt                                 */
  I2C2_EVT = I2C2_EVT_IRQn,                       /*!< i2c2 event interrupt                                 */
  I2C2_ERR = I2C2_ERR_IRQn,                       /*!< i2c2 error interrupt                                 */
  SPI1 = SPI1_IRQn,                               /*!< spi1 global interrupt                                */
  SPI2 = SPI2_IRQn,                               /*!< spi2 global interrupt                                */
  USART1 = USART1_IRQn,                           /*!< usart1 global interrupt                              */
  USART2 = USART2_IRQn,                           /*!< usart2 global interrupt                              */
  USART3 = USART3_IRQn,                           /*!< usart3 global interrupt                              */
  EXINT15_10 = EXINT15_10_IRQn,                   /*!< external line[15:10] interrupts                      */
  ERTCAlarm = ERTCAlarm_IRQn,                     /*!< ertc alarm through exint line interrupt              */
  OTGFS1_WKUP = OTGFS1_WKUP_IRQn,                 /*!< otgfs1 wakeup from suspend through exint line interrupt */
  SDIO1 = SDIO1_IRQn,                             /*!< sdio1 global interrupt                               */
  TMR5_GLOBAL = TMR5_GLOBAL_IRQn,                 /*!< tmr5 global interrupt                                */
  UART4 = UART4_IRQn,                             /*!< uart4 global interrupt                               */
  UART5 = UART5_IRQn,                             /*!< uart5 global interrupt                               */
  DMA2_Channel1 = DMA2_Channel1_IRQn,             /*!< dma2 channel 1 global interrupt                      */
  DMA2_Channel2 = DMA2_Channel2_IRQn,             /*!< dma2 channel 2 global interrupt                      */
  DMA2_Channel3 = DMA2_Channel3_IRQn,             /*!< dma2 channel 3 global interrupt                      */
  DMA2_Channel4_5 = DMA2_Channel4_5_IRQn,         /*!< dma2 channel 4 and channel 5 global interrupt        */
  OTGFS1 = OTGFS1_IRQn,                           /*!< otgfs1 global interrupt                              */
  CMP1 = CMP1_IRQn,                               /*!< comparator1 global interrupt                         */
  CMP2 = CMP2_IRQn,                               /*!< comparator2 global interrupt                         */
  DMA2_Channel6_7 = DMA2_Channel6_7_IRQn          /*!< dma2 channel 6 and channel 7 global interrupt        */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_895FED70_2682_4530_9863_24DD063C34C8 */
