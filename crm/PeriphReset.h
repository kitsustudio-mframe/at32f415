/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_6ABEDCA8_70D3_4EDF_8FA3_9EED1BB3001C
#define CHIP_6ABEDCA8_70D3_4EDF_8FA3_9EED1BB3001C

#define ENUM_MAKE_VALUE(reg_offset, bit_num) static_cast<uint32_t>(((reg_offset) << 16) | (bit_num & 0x1F))

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip ::crm {
  enum struct PeriphReset : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::PeriphReset : uint32_t {
  RESET_OTGFS1 = ENUM_MAKE_VALUE(0x28, 12), /*!< otgfs1 periph reset */
  RESET_IOMUX = ENUM_MAKE_VALUE(0x0C, 0),   /*!< iomux periph reset */
  RESET_EXINT = ENUM_MAKE_VALUE(0x0C, 1),   /*!< exint periph reset */
  RESET_GPIOA = ENUM_MAKE_VALUE(0x0C, 2),   /*!< gpioa periph reset */
  RESET_GPIOB = ENUM_MAKE_VALUE(0x0C, 3),   /*!< gpiob periph reset */
  RESET_GPIOC = ENUM_MAKE_VALUE(0x0C, 4),   /*!< gpioc periph reset */
  RESET_GPIOD = ENUM_MAKE_VALUE(0x0C, 5),   /*!< gpiod periph reset */
  RESET_GPIOF = ENUM_MAKE_VALUE(0x0C, 7),   /*!< gpiof periph reset */
  RESET_ADC1 = ENUM_MAKE_VALUE(0x0C, 9),    /*!< adc1 periph reset */
  RESET_TMR1 = ENUM_MAKE_VALUE(0x0C, 11),   /*!< tmr1 periph reset */
  RESET_SPI1 = ENUM_MAKE_VALUE(0x0C, 12),   /*!< spi2 periph reset */
  RESET_USART1 = ENUM_MAKE_VALUE(0x0C, 14), /*!< usart1 periph reset */
  RESET_TMR9 = ENUM_MAKE_VALUE(0x0C, 19),   /*!< tmr9 periph reset */
  RESET_TMR10 = ENUM_MAKE_VALUE(0x0C, 20),  /*!< tmr10 periph reset */
  RESET_TMR11 = ENUM_MAKE_VALUE(0x0C, 21),  /*!< tmr11 periph reset */
  RESET_TMR2 = ENUM_MAKE_VALUE(0x10, 0),    /*!< tmr2 periph reset */
  RESET_TMR3 = ENUM_MAKE_VALUE(0x10, 1),    /*!< tmr3 periph reset */
  RESET_TMR4 = ENUM_MAKE_VALUE(0x10, 2),    /*!< tmr4 periph reset */
  RESET_TMR5 = ENUM_MAKE_VALUE(0x10, 3),    /*!< tmr5 periph reset */
  RESET_CMP = ENUM_MAKE_VALUE(0x10, 9),     /*!< comparator periph reset */
  RESET_WWDT = ENUM_MAKE_VALUE(0x10, 11),   /*!< wwdt periph reset */
  RESET_SPI2 = ENUM_MAKE_VALUE(0x10, 14),   /*!< spi2 periph reset */
  RESET_USART2 = ENUM_MAKE_VALUE(0x10, 17), /*!< usart2 periph reset */
  RESET_USART3 = ENUM_MAKE_VALUE(0x10, 18), /*!< usart3 periph reset */
  RESET_UART4 = ENUM_MAKE_VALUE(0x10, 19),  /*!< uart4 periph reset */
  RESET_UART5 = ENUM_MAKE_VALUE(0x10, 20),  /*!< uart5 periph reset */
  RESET_I2C1 = ENUM_MAKE_VALUE(0x10, 21),   /*!< i2c1 periph reset */
  RESET_I2C2 = ENUM_MAKE_VALUE(0x10, 22),   /*!< i2c2 periph reset */
  RESET_CAN1 = ENUM_MAKE_VALUE(0x10, 25),   /*!< can1 periph reset */
  RESET_PWC = ENUM_MAKE_VALUE(0x10, 28)     /*!< pwc periph reset */
};

#undef ENUM_MAKE_VALUE

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_6ABEDCA8_70D3_4EDF_8FA3_9EED1BB3001C */
