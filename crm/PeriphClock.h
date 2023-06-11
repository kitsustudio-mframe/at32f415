/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_4352FAAB_B01A_4B8E_BE3A_39D6B5D93012
#define CHIP_4352FAAB_B01A_4B8E_BE3A_39D6B5D93012

#define ENUM_MAKE_VALUE(reg_offset, bit_num) static_cast<uint32_t>(((reg_offset) << 16) | (bit_num & 0x1F))

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct PeriphClock : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::PeriphClock : uint32_t {
  NONE = 0,
  /* ahb periph */
  DMA1 = ENUM_MAKE_VALUE(0x14, 0),    /**< dma1 periph clock */
  DMA2 = ENUM_MAKE_VALUE(0x14, 1),    /**< dma2 periph clock */
  CRC = ENUM_MAKE_VALUE(0x14, 6),     /**< crc periph clock */
  SDIO1 = ENUM_MAKE_VALUE(0x14, 10),  /**< sdio1 periph clock */
  OTGFS1 = ENUM_MAKE_VALUE(0x14, 12), /**< otgfs1 periph clock */
  IOMUX = ENUM_MAKE_VALUE(0x18, 0),   /**< iomux periph clock */
  GPIOA = ENUM_MAKE_VALUE(0x18, 2),   /**< gpioa periph clock */
  GPIOB = ENUM_MAKE_VALUE(0x18, 3),   /**< gpiob periph clock */
  GPIOC = ENUM_MAKE_VALUE(0x18, 4),   /**< gpioc periph clock */
  GPIOD = ENUM_MAKE_VALUE(0x18, 5),   /**< gpiod periph clock */
  GPIOF = ENUM_MAKE_VALUE(0x18, 7),   /**< gpiof periph clock */
  ADC1 = ENUM_MAKE_VALUE(0x18, 9),    /**< adc1 periph clock */
  TMR1 = ENUM_MAKE_VALUE(0x18, 11),   /**< tmr1 periph clock */
  SPI1 = ENUM_MAKE_VALUE(0x18, 12),   /**< spi1 periph clock */
  USART1 = ENUM_MAKE_VALUE(0x18, 14), /**< usart1 periph clock */
  TMR9 = ENUM_MAKE_VALUE(0x18, 19),   /**< tmr9 periph clock */
  TMR10 = ENUM_MAKE_VALUE(0x18, 20),  /**< tmr10 periph clock */
  TMR11 = ENUM_MAKE_VALUE(0x18, 21),  /**< tmr11 periph clock */
  TMR2 = ENUM_MAKE_VALUE(0x1C, 0),    /**< tmr2 periph clock */
  TMR3 = ENUM_MAKE_VALUE(0x1C, 1),    /**< tmr3 periph clock */
  TMR4 = ENUM_MAKE_VALUE(0x1C, 2),    /**< tmr4 periph clock */
  TMR5 = ENUM_MAKE_VALUE(0x1C, 3),    /**< tmr5 periph clock */
  CMP = ENUM_MAKE_VALUE(0x1C, 9),     /**< cmparator periph clock */
  WWDT = ENUM_MAKE_VALUE(0x1C, 11),   /**< wwdt periph clock */
  SPI2 = ENUM_MAKE_VALUE(0x1C, 14),   /**< spi2 periph clock */
  USART2 = ENUM_MAKE_VALUE(0x1C, 17), /**< usart2 periph clock */
  USART3 = ENUM_MAKE_VALUE(0x1C, 18), /**< usart3 periph clock */
  UART4 = ENUM_MAKE_VALUE(0x1C, 19),  /**< uart4 periph clock */
  UART5 = ENUM_MAKE_VALUE(0x1C, 20),  /**< uart5 periph clock */
  I2C1 = ENUM_MAKE_VALUE(0x1C, 21),   /**< i2c1 periph clock */
  I2C2 = ENUM_MAKE_VALUE(0x1C, 22),   /**< i2c2 periph clock */
  CAN1 = ENUM_MAKE_VALUE(0x1C, 25),   /**< can1 periph clock */
  PWC = ENUM_MAKE_VALUE(0x1C, 28)     /**< pwc periph clock */
};

#undef ENUM_MAKE_VALUE

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_4352FAAB_B01A_4B8E_BE3A_39D6B5D93012 */
