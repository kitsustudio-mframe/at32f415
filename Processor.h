/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_08B26F72_625B_46CB_93E9_99DE461036F7
#define CHIP_08B26F72_625B_46CB_93E9_99DE461036F7

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip {
  class Processor;
}  // namespace chip

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::Processor : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 private:
  /**
   * @brief Construct a new Processor object
   *
   */
  Processor(void);

  /**
   * @brief Destroy the Processor object
   *
   */
  virtual ~Processor(void) override;

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
 public:
  static const uint32_t BASE_FLASH = 0x08000000;   ///< Flash Base
  static const uint32_t BASE_SPIM = 0x08400000;    ///< SPIM Base
  static const uint32_t BASE_USD = 0x1FFFF800;     ///< USD Base
  static const uint32_t BASE_SRAM = 0x20000000;    ///< SRAM Base
  static const uint32_t BASE_PERIPH = 0x40000000;  ///< Peripherals Base
  static const uint32_t BASE_DEGUB = 0xE0042000;   ///< Debug Base

  static const uint32_t BASE_APB1PERIPH = (BASE_PERIPH + 0x00000);  ///< Advanced Peripheral Bus 1 Base
  static const uint32_t BASE_APB2PERIPH = (BASE_PERIPH + 0x10000);  ///< Advanced Peripheral Bus 2 Base
  static const uint32_t BASE_AHBPERIPH = (BASE_PERIPH + 0x20000);   ///< Advanced High-performance Bus Base

  /* apb1 bus base address */
  static const uint32_t BASE_TMR2 = (BASE_APB1PERIPH + 0x0000);    ///< BASE_TMR2
  static const uint32_t BASE_TMR3 = (BASE_APB1PERIPH + 0x0400);    ///< BASE_TMR3
  static const uint32_t BASE_TMR4 = (BASE_APB1PERIPH + 0x0800);    ///< BASE_TMR4
  static const uint32_t BASE_TMR5 = (BASE_APB1PERIPH + 0x0C00);    ///< BASE_TMR5
  static const uint32_t BASE_CMP = (BASE_APB1PERIPH + 0x2400);     ///< BASE_CMP
  static const uint32_t BASE_ERTC = (BASE_APB1PERIPH + 0x2800);    ///< BASE_ERTC
  static const uint32_t BASE_WWDT = (BASE_APB1PERIPH + 0x2C00);    ///< BASE_WWDT
  static const uint32_t BASE_WDT = (BASE_APB1PERIPH + 0x3000);     ///< BASE_WDT
  static const uint32_t BASE_SPI2 = (BASE_APB1PERIPH + 0x3800);    ///< BASE_SPI2
  static const uint32_t BASE_USART2 = (BASE_APB1PERIPH + 0x4400);  ///< BASE_USART2
  static const uint32_t BASE_USART3 = (BASE_APB1PERIPH + 0x4800);  ///< BASE_USART3
  static const uint32_t BASE_UART4 = (BASE_APB1PERIPH + 0x4C00);   ///< BASE_UART4
  static const uint32_t BASE_UART5 = (BASE_APB1PERIPH + 0x5000);   ///< BASE_UART5
  static const uint32_t BASE_I2C1 = (BASE_APB1PERIPH + 0x5400);    ///< BASE_I2C1
  static const uint32_t BASE_I2C2 = (BASE_APB1PERIPH + 0x5800);    ///< BASE_I2C2
  static const uint32_t BASE_CAN1 = (BASE_APB1PERIPH + 0x6400);    ///< BASE_CAN1
  static const uint32_t BASE_PWC = (BASE_APB1PERIPH + 0x7000);     ///< BASE_PWC
  /* apb2 bus base address */
  static const uint32_t BASE_IOMUX = (BASE_APB2PERIPH + 0x0000);   ///< BASE_IOMUX
  static const uint32_t BASE_EXINT = (BASE_APB2PERIPH + 0x0400);   ///< BASE_EXINT
  static const uint32_t BASE_GPIOA = (BASE_APB2PERIPH + 0x0800);   ///< BASE_GPIOA
  static const uint32_t BASE_GPIOB = (BASE_APB2PERIPH + 0x0C00);   ///< BASE_GPIOB
  static const uint32_t BASE_GPIOC = (BASE_APB2PERIPH + 0x1000);   ///< BASE_GPIOC
  static const uint32_t BASE_GPIOD = (BASE_APB2PERIPH + 0x1400);   ///< BASE_GPIOD
  static const uint32_t BASE_GPIOF = (BASE_APB2PERIPH + 0x1C00);   ///< BASE_GPIOF
  static const uint32_t BASE_ADC1 = (BASE_APB2PERIPH + 0x2400);    ///< BASE_ADC1
  static const uint32_t BASE_TMR1 = (BASE_APB2PERIPH + 0x2C00);    ///< BASE_TMR1
  static const uint32_t BASE_SPI1 = (BASE_APB2PERIPH + 0x3000);    ///< BASE_SPI1
  static const uint32_t BASE_USART1 = (BASE_APB2PERIPH + 0x3800);  ///< BASE_USART1
  static const uint32_t BASE_TMR9 = (BASE_APB2PERIPH + 0x4C00);    ///< BASE_TMR9
  static const uint32_t BASE_TMR10 = (BASE_APB2PERIPH + 0x5000);   ///< BASE_TMR10
  static const uint32_t BASE_TMR11 = (BASE_APB2PERIPH + 0x5400);   ///< BASE_TMR11
  static const uint32_t BASE_SDIO1 = (BASE_APB2PERIPH + 0x8000);   ///< BASE_SDIO1

  /* ahb bus base address */
  static const uint32_t BASE_DMA1 = (BASE_AHBPERIPH + 0x0000);           ///< BASE_DMA1
  static const uint32_t BASE_DMA1_CHANNEL1 = (BASE_AHBPERIPH + 0x0008);  ///< BASE_DMA1_CHANNEL1
  static const uint32_t BASE_DMA1_CHANNEL2 = (BASE_AHBPERIPH + 0x001C);  ///< BASE_DMA1_CHANNEL2
  static const uint32_t BASE_DMA1_CHANNEL3 = (BASE_AHBPERIPH + 0x0030);  ///< BASE_DMA1_CHANNEL3
  static const uint32_t BASE_DMA1_CHANNEL4 = (BASE_AHBPERIPH + 0x0044);  ///< BASE_DMA1_CHANNEL4
  static const uint32_t BASE_DMA1_CHANNEL5 = (BASE_AHBPERIPH + 0x0058);  ///< BASE_DMA1_CHANNEL5
  static const uint32_t BASE_DMA1_CHANNEL6 = (BASE_AHBPERIPH + 0x006C);  ///< BASE_DMA1_CHANNEL6
  static const uint32_t BASE_DMA1_CHANNEL7 = (BASE_AHBPERIPH + 0x0080);  ///< BASE_DMA1_CHANNEL7
  static const uint32_t BASE_DMA2 = (BASE_AHBPERIPH + 0x0400);           ///< BASE_DMA2
  static const uint32_t BASE_DMA2_CHANNEL1 = (BASE_AHBPERIPH + 0x0408);  ///< BASE_DMA2_CHANNEL1
  static const uint32_t BASE_DMA2_CHANNEL2 = (BASE_AHBPERIPH + 0x041C);  ///< BASE_DMA2_CHANNEL2
  static const uint32_t BASE_DMA2_CHANNEL3 = (BASE_AHBPERIPH + 0x0430);  ///< BASE_DMA2_CHANNEL3
  static const uint32_t BASE_DMA2_CHANNEL4 = (BASE_AHBPERIPH + 0x0444);  ///< BASE_DMA2_CHANNEL4
  static const uint32_t BASE_DMA2_CHANNEL5 = (BASE_AHBPERIPH + 0x0458);  ///< BASE_DMA2_CHANNEL5
  static const uint32_t BASE_DMA2_CHANNEL6 = (BASE_AHBPERIPH + 0x046C);  ///< BASE_DMA2_CHANNEL6
  static const uint32_t BASE_DMA2_CHANNEL7 = (BASE_AHBPERIPH + 0x0480);  ///< BASE_DMA2_CHANNEL7
  static const uint32_t BASE_CRM = (BASE_AHBPERIPH + 0x1000);            ///< BASE_CRM
  static const uint32_t BASE_FLASH_REG = (BASE_AHBPERIPH + 0x2000);      ///< BASE_FLASH_REG
  static const uint32_t BASE_CRC = (BASE_AHBPERIPH + 0x3000);            ///< BASE_CRC
  static const uint32_t BASE_OTGFS1 = (BASE_PERIPH + 0x10000000);        ///< BASE_OTGFS1

  static uint32_t systemCoreClock;
  static uint32_t systemCoreClockHz;

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief  setup the microcontroller system
   *         initialize the flash interface.
   * @note   this function should be used only after reset.
   */
  static void systemInit(void);

  /**
   * @brief  update SystemCoreClock variable according to clock register values.
   *         the SystemCoreClock variable contains the core clock (hclk), it can
   *         be used by the user application to setup the systick timer or configure
   *         other parameters.
   */
  static void systemCoreClockUpdate(void);
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_08B26F72_625B_46CB_93E9_99DE461036F7 */
