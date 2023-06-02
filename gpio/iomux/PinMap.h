/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_420C8F3F_A9F2_485D_92F4_A52DD7B2420B
#define AT32F415_420C8F3F_A9F2_485D_92F4_A52DD7B2420B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Macro
 */
#define IOMUX_MAKE_VALUE(reg_offset, bit_addr ,bit_num, bit_val) \
        static_cast<uint32_t>(((reg_offset) << 24) | ((bit_addr) << 16) | ((bit_num) << 8) | (bit_val))

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::gpio::iomux{
  enum struct PinMap : uint32_t;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::gpio::iomux::PinMap : uint32_t{
  MAP2_CMP_01          = IOMUX_MAKE_VALUE(0x1C, 26, 2, 0x01), /*!< cmp1_out connect pa6, cmp2_out connect pa7 */
  MAP2_CMP_10          = IOMUX_MAKE_VALUE(0x1C, 26, 2, 0x02), /*!< cmp1_out connect pa11, cmp2_out connect pa12 */
              
  MAP3_TMR9            = IOMUX_MAKE_VALUE(0x20,  0, 4, 0x02), /*!< tmr9_ch1(pb14),  tmr9_ch2(pb15) */
  MAP3_TMR10           = IOMUX_MAKE_VALUE(0x20,  4, 4, 0x02), /*!< tmr10_ch1(pa6) */
  MAP3_TMR11           = IOMUX_MAKE_VALUE(0x20,  8, 4, 0x02), /*!< tmr11_ch1(pa7) */
    
  MAP4_TMR1_0001       = IOMUX_MAKE_VALUE(0x24,  0, 4, 0x01), /*!< tmr1_ext(pa12), tmr1_ch1(pa8), tmr1_ch2(pa9), tmr1_ch3(pa10), tmr1_ch4(pa11), tmr1_brkin(pa6), tmr1_ch1c(pa7), tmr1_ch2c(pb0), tmr1_ch3c(pb1) */
  MAP4_TMR1_0010       = IOMUX_MAKE_VALUE(0x24,  0, 4, 0x02), /*!< tmr1_ext(pa0),  tmr1_ch1(pc6), tmr1_ch2(pc7), tmr1_ch3(pc8), tmr1_ch4(pc9), tmr1_brkin(pa6), tmr1_ch1c(pa7), tmr1_ch2c(pb0), tmr1_ch3c(pb1) */
  MAP4_TMR2_001        = IOMUX_MAKE_VALUE(0x24,  4, 3, 0x01), /*!< tmr2_ch1_ext(pa15), tmr2_ch2(pb3), tmr2_ch3(pa2),  tmr2_ch4(pa3) */
  MAP4_TMR2_010        = IOMUX_MAKE_VALUE(0x24,  4, 3, 0x02), /*!< tmr2_ch1_ext(pa0),  tmr2_ch2(pa1), tmr2_ch3(pb10), tmr2_ch4(pb11) */
  MAP4_TMR2_011        = IOMUX_MAKE_VALUE(0x24,  4, 3, 0x03), /*!< tmr2_ch1_ext(pa15), tmr2_ch2(pb3), tmr2_ch3(pb10), tmr2_ch4(pb11) */
  MAP4_TMR3_0010       = IOMUX_MAKE_VALUE(0x24,  8, 4, 0x02), /*!< tmr3_ch1(pb4), tmr3_ch2(pb5), tmr3_ch3(pb0), tmr3_ch4(pb1) */
  MAP4_TMR3_0011       = IOMUX_MAKE_VALUE(0x24,  8, 4, 0x03), /*!< tmr3_ch1(pc6), tmr3_ch2(pc7), tmr3_ch3(pc8), tmr3_ch4(pc9) */
  MAP4_TMR5_001        = IOMUX_MAKE_VALUE(0x24, 16, 3, 0x01), /*!< tmr5_ch1(pf4), tmr5_ch2(pf5), tmr5_ch3(pa2), tmr5_ch4(pa3) */
  MAP4_TMR5CH4         = IOMUX_MAKE_VALUE(0x24, 19, 1, 0x01), /*!< lick connected to tmr5_ch4 input capture for calibration */
    
  MAP5_I2C1_0001       = IOMUX_MAKE_VALUE(0x28,  4, 4, 0x01), /*!< i2c1_scl(pb8), i2c1_sda(pb9), i2c1_smba(pb5) */
  MAP5_I2C1_0010       = IOMUX_MAKE_VALUE(0x28,  4, 4, 0x02), /*!< i2c1_scl(pf6), i2c1_sda(pf7), i2c1_smba(pb5) */
  MAP5_I2C2_0001       = IOMUX_MAKE_VALUE(0x28,  8, 4, 0x01), /*!< i2c2_scl(pa8), i2c2_sda(pc9), i2c2_smba(pa9) */
  MAP5_I2C2_0010       = IOMUX_MAKE_VALUE(0x28,  8, 4, 0x02), /*!< i2c2_scl(pa8), i2c2_sda(pb4), i2c2_smba(pa9) */
  MAP5_I2C2_0011       = IOMUX_MAKE_VALUE(0x28,  8, 4, 0x03), /*!< i2c2_scl(pf6), i2c2_sda(pf7), i2c2_smba(pa9) */
  MAP5_SPI1_0001       = IOMUX_MAKE_VALUE(0x28, 16, 4, 0x01), /*!< spi1_cs/i2s1_ws(pa15), spi1_sck/i2s1_ck(pb3), spi1_miso(pb4), spi1_mosi/i2s1_sd(pb5), i2s1_mck(pb6) */
  MAP5_SPI2_0001       = IOMUX_MAKE_VALUE(0x28, 20, 4, 0x01), /*!< spi2_cs/i2s2_ws(pa15), spi2_sck/i2s2_ck(pb3), spi2_miso(pb4), spi2_mosi/i2s2_sd(pb5), i2s2_mck(pc7) */
    
  MAP6_CAN1_0010       = IOMUX_MAKE_VALUE(0x2C,  0, 4, 0x02), /*!< can_rx(pb8),   can_tx(pb9) */
  MAP6_SDIO1_0100      = IOMUX_MAKE_VALUE(0x2C,  8, 4, 0x04), /*!< sdio1_ck(pc4), sdio1_cmd(pc5), sdio1_d0(pc0), sdio1_d1(pc1), sdio1_d2(pc2), sdio1_d3(pc3), sdio1_d4(pa4), sdio1_d5(pa5), sdio1_d6(pa6), sdio1_d7(pa7) */
  MAP6_SDIO1_0101      = IOMUX_MAKE_VALUE(0x2C,  8, 4, 0x05), /*!< sdio1_ck(pc4), sdio1_cmd(pc5), sdio1_d0(pa4), sdio1_d1(pa5), sdio1_d2(pa6), sdio1_d3(pa7) */
  MAP6_SDIO1_0110      = IOMUX_MAKE_VALUE(0x2C,  8, 4, 0x06), /*!< sdio1_ck(pa2), sdio1_cmd(pa3), sdio1_d0(pc0), sdio1_d1(pc1), sdio1_d2(pc2), sdio1_d3(pc3), sdio1_d4(pa4), sdio1_d5(pa5), sdio1_d6(pa6), sdio1_d7(pa7) */
  MAP6_SDIO1_0111      = IOMUX_MAKE_VALUE(0x2C,  8, 4, 0x07), /*!< sdio1_ck(pa2), sdio1_cmd(pa3), sdio1_d0(pa4), sdio1_d1(pa5), sdio1_d2(pa6), sdio1_d3(pa7) */
  MAP6_USART1_0001     = IOMUX_MAKE_VALUE(0x2C, 16, 4, 0x01), /*!< usart1_tx(pb6), usart1_rx(pb7) */
  MAP6_USART3_0001     = IOMUX_MAKE_VALUE(0x2C, 24, 4, 0x01), /*!< usart3_tx(pc10), usart3_rx(pc11), usart3_ck(pc12), usart3_cts(pb13), usart3_rts(pb14) */
  MAP6_USART3_0010     = IOMUX_MAKE_VALUE(0x2C, 24, 4, 0x02), /*!< usart3_tx(pa7),  usart3_rx(pa6),  usart3_ck(pa5), usart3_cts(pb1), usart3_rts(pb0) */
  MAP6_UART4_0001      = IOMUX_MAKE_VALUE(0x2C, 28, 4, 0x01), /*!< uart4_tx(pf4),   uart4_rx(pf5) */
    
  MAP7_ADC1_ETP        = IOMUX_MAKE_VALUE(0x30,  4, 1, 0x01), /*!< adc1 external trigger preempted conversion muxing */
  MAP7_ADC1_ETO        = IOMUX_MAKE_VALUE(0x30,  5, 1, 0x01), /*!< adc1 external trigger ordinary conversion muxing */
  MAP7_SWJTAG_001      = IOMUX_MAKE_VALUE(0x30, 16, 3, 0x01), /*!< full swj enabled  (jtag-dp  +  sw-dp)  but without jtrst */
  MAP7_SWJTAG_010      = IOMUX_MAKE_VALUE(0x30, 16, 3, 0x02), /*!< jtag-dp disabled and sw-dp enabled */
  MAP7_SWJTAG_100      = IOMUX_MAKE_VALUE(0x30, 16, 3, 0x04), /*!< full swj disabled  (jtag-dp  +  sw-dp) */
  MAP7_PD01            = IOMUX_MAKE_VALUE(0x30, 20, 1, 0x01), /*!< pd0/pd1 mapping on osc_in/osc_out */

  MAP8_TMR1_BK1_CMP_10 = IOMUX_MAKE_VALUE(0x34,  0, 2, 0x02), /*!< cmp tmr1_bpr1 connect tmr1 bk1 */
  MAP8_TMR1_BK1_CMP_11 = IOMUX_MAKE_VALUE(0x34,  0, 2, 0x03), /*!< cmp tmr1_bpr1 and io connect tmr1 bk1 */
  MAP8_TMR1_CH1_CMP_10 = IOMUX_MAKE_VALUE(0x34,  2, 2, 0x02), /*!< cmp connect tmr1 ch1 */
  MAP8_TMR1_CH1_CMP_11 = IOMUX_MAKE_VALUE(0x34,  2, 2, 0x03), /*!< cmp and io connect tmr1 ch1 */
  MAP8_TMR2_CH4_CMP_10 = IOMUX_MAKE_VALUE(0x34,  4, 2, 0x02), /*!< cmp connect tmr2 ch4 */
  MAP8_TMR2_CH4_CMP_11 = IOMUX_MAKE_VALUE(0x34,  4, 2, 0x03), /*!< cmp and io connect tmr2 ch4 */
  MAP8_TMR3_CH1_CMP_10 = IOMUX_MAKE_VALUE(0x34,  6, 2, 0x02), /*!< cmp connect tmr3 ch1 */
  MAP8_TMR3_CH1_CMP_11 = IOMUX_MAKE_VALUE(0x34,  6, 2, 0x03) /*!< cmp and io connect tmr3 ch1 */
};

#undef IOMUX_MAKE_VALUE
/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_420C8F3F_A9F2_485D_92F4_A52DD7B2420B */
