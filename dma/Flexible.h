/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_A0001227_DBCC_4EB6_82B8_C1BC269AAFEC
#define CHIP_A0001227_DBCC_4EB6_82B8_C1BC269AAFEC

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct Flexible : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::Flexible : uint8_t {
  ADC1 = 0x01,           ///< adc1 flexible request id
  SPI1_RX = 0x09,        ///< spi1_rx flexible request id
  SPI1_TX = 0x0A,        ///< spi1_tx flexible request id
  SPI2_RX = 0x0B,        ///< spi2_rx flexible request id
  SPI2_TX = 0x0C,        ///< spi2_tx flexible request id
  UART1_RX = 0x19,       ///< uart1_rx flexible request id
  UART1_TX = 0x1A,       ///< uart1_tx flexible request id
  UART2_RX = 0x1B,       ///< uart2_rx flexible request id
  UART2_TX = 0x1C,       ///< uart2_tx flexible request id
  UART3_RX = 0x1D,       ///< uart3_rx flexible request id
  UART3_TX = 0x1E,       ///< uart3_tx flexible request id
  UART4_RX = 0x1F,       ///< uart4_rx flexible request id
  UART4_TX = 0x20,       ///< uart4_tx flexible request id
  UART5_RX = 0x21,       ///< uart5_rx flexible request id
  UART5_TX = 0x22,       ///< uart5_tx flexible request id
  I2C1_RX = 0x29,        ///< i2c1_rx flexible request id
  I2C1_TX = 0x2A,        ///< i2c1_tx flexible request id
  I2C2_RX = 0x2B,        ///< i2c2_rx flexible request id
  I2C2_TX = 0x2C,        ///< i2c2_tx flexible request id
  SDIO1 = 0x31,          ///< sdio1 flexible request id
  TMR1_TRIG = 0x35,      ///< tmr1_trig flexible request id
  TMR1_HALL = 0x36,      ///< tmr1_hall flexible request id
  TMR1_OVERFLOW = 0x37,  ///< tmr1_overflow flexible request id
  TMR1_CH1 = 0x38,       ///< tmr1_ch1 flexible request id
  TMR1_CH2 = 0x39,       ///< tmr1_ch2 flexible request id
  TMR1_CH3 = 0x3A,       ///< tmr1_ch3 flexible request id
  TMR1_CH4 = 0x3B,       ///< tmr1_ch4 flexible request id
  TMR2_TRIG = 0x3D,      ///< tmr2_trig flexible request id
  TMR2_OVERFLOW = 0x3F,  ///< tmr2_overflow flexible request id
  TMR2_CH1 = 0x40,       ///< tmr2_ch1 flexible request id
  TMR2_CH2 = 0x41,       ///< tmr2_ch2 flexible request id
  TMR2_CH3 = 0x42,       ///< tmr2_ch3 flexible request id
  TMR2_CH4 = 0x43,       ///< tmr2_ch4 flexible request id
  TMR3_TRIG = 0x45,      ///< tmr3_trig flexible request id
  TMR3_OVERFLOW = 0x47,  ///< tmr3_overflow flexible request id
  TMR3_CH1 = 0x48,       ///< tmr3_ch1 flexible request id
  TMR3_CH2 = 0x49,       ///< tmr3_ch2 flexible request id
  TMR3_CH3 = 0x4A,       ///< tmr3_ch3 flexible request id
  TMR3_CH4 = 0x4B,       ///< tmr3_ch4 flexible request id
  TMR4_TRIG = 0x4D,      ///< tmr4_trig flexible request id
  TMR4_OVERFLOW = 0x4F,  ///< tmr4_overflow flexible request id
  TMR4_CH1 = 0x50,       ///< tmr4_ch1 flexible request id
  TMR4_CH2 = 0x51,       ///< tmr4_ch2 flexible request id
  TMR4_CH3 = 0x52,       ///< tmr4_ch3 flexible request id
  TMR4_CH4 = 0x53,       ///< tmr4_ch4 flexible request id
  TMR5_TRIG = 0x55,      ///< tmr5_trig flexible request id
  TMR5_OVERFLOW = 0x57,  ///< tmr5_overflow flexible request id
  TMR5_CH1 = 0x58,       ///< tmr5_ch1 flexible request id
  TMR5_CH2 = 0x59,       ///< tmr5_ch2 flexible request id
  TMR5_CH3 = 0x5A,       ///< tmr5_ch3 flexible request id
  TMR5_CH4 = 0x5B        ///< tmr5_ch4 flexible request id
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_A0001227_DBCC_4EB6_82B8_C1BC269AAFEC */
