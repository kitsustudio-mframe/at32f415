/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_9FFF35CD_8553_43AD_9E6C_30B44A70D2F0
#define AT32F415_9FFF35CD_8553_43AD_9E6C_30B44A70D2F0

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::crm {
  struct Register;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::crm::Register {
  /**
   * @brief crm ctrl register, offset:0x00
   */
  union {
    volatile uint32_t ctrl;

    struct {
      volatile uint32_t hicken : 1;    /* [0] */
      volatile uint32_t hickstbl : 1;  /* [1] */
      volatile uint32_t hicktrim : 6;  /* [7:2] */
      volatile uint32_t hickcal : 8;   /* [15:8] */
      volatile uint32_t hexten : 1;    /* [16] */
      volatile uint32_t hextstbl : 1;  /* [17] */
      volatile uint32_t hextbyps : 1;  /* [18] */
      volatile uint32_t cfden : 1;     /* [19] */
      volatile uint32_t reserved1 : 4; /* [23:20] */
      volatile uint32_t pllen : 1;     /* [24] */
      volatile uint32_t pllstbl : 1;   /* [25] */
      volatile uint32_t reserved2 : 6; /* [31:26] */

    } ctrl_bit;
  };

  /**
   * @brief crm cfg register, offset:0x04
   */
  union {
    volatile uint32_t cfg;

    struct {
      volatile uint32_t sclksel : 2;    /* [1:0] */
      volatile uint32_t sclksts : 2;    /* [3:2] */
      volatile uint32_t ahbdiv : 4;     /* [7:4] */
      volatile uint32_t apb1div : 3;    /* [10:8] */
      volatile uint32_t apb2div : 3;    /* [13:11] */
      volatile uint32_t adcdiv_l : 2;   /* [15:14] */
      volatile uint32_t pllrcs : 1;     /* [16] */
      volatile uint32_t pllhextdiv : 1; /* [17] */
      volatile uint32_t pllmult_l : 4;  /* [21:18] */
      volatile uint32_t usbdiv_l : 2;   /* [23:22] */
      volatile uint32_t clkout_sel : 3; /* [26:24] */
      volatile uint32_t usbdiv_h : 1;   /* [27] */
      volatile uint32_t adcdiv_h : 1;   /* [28] */
      volatile uint32_t pllmult_h : 2;  /* [30:29] */
      volatile uint32_t reserved1 : 1;  /* [31] */

    } cfg_bit;
  };

  /**
   * @brief crm clkint register, offset:0x08
   */
  union {
    volatile uint32_t clkint;

    struct {
      volatile uint32_t lickstblf : 1;   /* [0] */
      volatile uint32_t lextstblf : 1;   /* [1] */
      volatile uint32_t hickstblf : 1;   /* [2] */
      volatile uint32_t hextstblf : 1;   /* [3] */
      volatile uint32_t pllstblf : 1;    /* [4] */
      volatile uint32_t reserved1 : 2;   /* [6:5] */
      volatile uint32_t cfdf : 1;        /* [7] */
      volatile uint32_t lickstblien : 1; /* [8] */
      volatile uint32_t lextstblien : 1; /* [9] */
      volatile uint32_t hickstblien : 1; /* [10] */
      volatile uint32_t hextstblien : 1; /* [11] */
      volatile uint32_t pllstblien : 1;  /* [12] */
      volatile uint32_t reserved2 : 3;   /* [15:13] */
      volatile uint32_t lickstblfc : 1;  /* [16] */
      volatile uint32_t lextstblfc : 1;  /* [17] */
      volatile uint32_t hickstblfc : 1;  /* [18] */
      volatile uint32_t hextstblfc : 1;  /* [19] */
      volatile uint32_t pllstblfc : 1;   /* [20] */
      volatile uint32_t reserved3 : 2;   /* [22:21] */
      volatile uint32_t cfdfc : 1;       /* [23] */
      volatile uint32_t reserved4 : 8;   /* [31:24] */
    } clkint_bit;
  };

  /**
   * @brief crm apb2rst register, offset:0x0C
   */
  union {
    volatile uint32_t apb2rst;

    struct {
      volatile uint32_t iomuxrst : 1;   /* [0] */
      volatile uint32_t exintrst : 1;   /* [1] */
      volatile uint32_t gpioarst : 1;   /* [2] */
      volatile uint32_t gpiobrst : 1;   /* [3] */
      volatile uint32_t gpiocrst : 1;   /* [4] */
      volatile uint32_t gpiodrst : 1;   /* [5] */
      volatile uint32_t reserved1 : 1;  /* [6] */
      volatile uint32_t gpiofrst : 1;   /* [7] */
      volatile uint32_t reserved2 : 1;  /* [8] */
      volatile uint32_t adc1rst : 1;    /* [9] */
      volatile uint32_t reserved3 : 1;  /* [10] */
      volatile uint32_t tmr1rst : 1;    /* [11] */
      volatile uint32_t spi1rst : 1;    /* [12] */
      volatile uint32_t reserved4 : 1;  /* [13] */
      volatile uint32_t usart1rst : 1;  /* [14] */
      volatile uint32_t reserved5 : 4;  /* [18:15] */
      volatile uint32_t tmr9rst : 1;    /* [19] */
      volatile uint32_t tmr10rst : 1;   /* [20] */
      volatile uint32_t tmr11rst : 1;   /* [21] */
      volatile uint32_t reserved6 : 10; /* [31:22] */
    } apb2rst_bit;
  };

  /**
   * @brief crm apb1rst register, offset:0x10
   */
  union {
    volatile uint32_t apb1rst;

    struct {
      volatile uint32_t tmr2rst : 1;   /* [0] */
      volatile uint32_t tmr3rst : 1;   /* [1] */
      volatile uint32_t tmr4rst : 1;   /* [2] */
      volatile uint32_t tmr5rst : 1;   /* [3] */
      volatile uint32_t reserved1 : 5; /* [8:4] */
      volatile uint32_t cmprst : 1;    /* [9] */
      volatile uint32_t reserved2 : 1; /* [10] */
      volatile uint32_t wwdtrst : 1;   /* [11] */
      volatile uint32_t reserved3 : 2; /* [13:12] */
      volatile uint32_t spi2rst : 1;   /* [14] */
      volatile uint32_t reserved4 : 2; /* [16:15] */
      volatile uint32_t usart2rst : 1; /* [17] */
      volatile uint32_t usart3rst : 1; /* [18] */
      volatile uint32_t uart4rst : 1;  /* [19] */
      volatile uint32_t uart5rst : 1;  /* [20] */
      volatile uint32_t i2c1rst : 1;   /* [21] */
      volatile uint32_t i2c2rst : 1;   /* [22] */
      volatile uint32_t reserved5 : 2; /* [24:23] */
      volatile uint32_t can1rst : 1;   /* [25] */
      volatile uint32_t reserved6 : 2; /* [27:26] */
      volatile uint32_t pwcrst : 1;    /* [28] */
      volatile uint32_t reserved7 : 3; /* [31:29] */
    } apb1rst_bit;
  };

  /**
   * @brief crm ahben register, offset:0x14
   */
  union {
    volatile uint32_t ahben;

    struct {
      volatile uint32_t dma1en : 1;     /* [0] */
      volatile uint32_t dma2en : 1;     /* [1] */
      volatile uint32_t sramen : 1;     /* [2] */
      volatile uint32_t reserved1 : 1;  /* [3] */
      volatile uint32_t flashen : 1;    /* [4] */
      volatile uint32_t reserved2 : 1;  /* [5] */
      volatile uint32_t crcen : 1;      /* [6] */
      volatile uint32_t reserved3 : 3;  /* [9:7] */
      volatile uint32_t sdio1en : 1;    /* [10] */
      volatile uint32_t reserved4 : 1;  /* [11] */
      volatile uint32_t usben : 1;      /* [12] */
      volatile uint32_t reserved5 : 19; /* [31:13] */
    } ahben_bit;
  };

  /**
   * @brief crm apb2en register, offset:0x18
   */
  union {
    volatile uint32_t apb2en;

    struct {
      volatile uint32_t iomuxen : 1;    /* [0] */
      volatile uint32_t reserved1 : 1;  /* [1] */
      volatile uint32_t gpioaen : 1;    /* [2] */
      volatile uint32_t gpioben : 1;    /* [3] */
      volatile uint32_t gpiocen : 1;    /* [4] */
      volatile uint32_t gpioden : 1;    /* [5] */
      volatile uint32_t reserved2 : 1;  /* [6] */
      volatile uint32_t gpiofen : 1;    /* [7] */
      volatile uint32_t reserved3 : 1;  /* [8] */
      volatile uint32_t adc1en : 1;     /* [9] */
      volatile uint32_t reserved4 : 1;  /* [10] */
      volatile uint32_t tmr1en : 1;     /* [11] */
      volatile uint32_t spi1en : 1;     /* [12] */
      volatile uint32_t reserved5 : 1;  /* [13] */
      volatile uint32_t usart1en : 1;   /* [14] */
      volatile uint32_t reserved6 : 4;  /* [18:15] */
      volatile uint32_t tmr9en : 1;     /* [19] */
      volatile uint32_t tmr10en : 1;    /* [20] */
      volatile uint32_t tmr11en : 1;    /* [21] */
      volatile uint32_t reserved7 : 10; /* [31:22] */
    } apb2en_bit;
  };

  /**
   * @brief crm apb1en register, offset:0x1C
   */
  union {
    volatile uint32_t apb1en;

    struct {
      volatile uint32_t tmr2en : 1;    /* [0] */
      volatile uint32_t tmr3en : 1;    /* [1] */
      volatile uint32_t tmr4en : 1;    /* [2] */
      volatile uint32_t tmr5en : 1;    /* [3] */
      volatile uint32_t reserved1 : 5; /* [8:4] */
      volatile uint32_t cmpen : 1;     /* [9] */
      volatile uint32_t reserved2 : 1; /* [10] */
      volatile uint32_t wwdten : 1;    /* [11] */
      volatile uint32_t reserved3 : 2; /* [13:12] */
      volatile uint32_t spi2en : 1;    /* [14] */
      volatile uint32_t reserved4 : 2; /* [16:15] */
      volatile uint32_t usart2en : 1;  /* [17] */
      volatile uint32_t usart3en : 1;  /* [18] */
      volatile uint32_t uart4en : 1;   /* [19] */
      volatile uint32_t uart5en : 1;   /* [20] */
      volatile uint32_t i2c1en : 1;    /* [21] */
      volatile uint32_t i2c2en : 1;    /* [22] */
      volatile uint32_t reserved5 : 2; /* [24:23] */
      volatile uint32_t can1en : 1;    /* [25] */
      volatile uint32_t reserved6 : 1; /* [26] */
      volatile uint32_t bpren : 1;     /* [27] */
      volatile uint32_t pwcen : 1;     /* [28] */
      volatile uint32_t reserved7 : 2; /* [31:29] */
    } apb1en_bit;
  };

  /**
   * @brief crm bpdc register, offset:0x20
   */
  union {
    volatile uint32_t bpdc;

    struct {
      volatile uint32_t lexten : 1;     /* [0] */
      volatile uint32_t lextstbl : 1;   /* [1] */
      volatile uint32_t lextbyps : 1;   /* [2] */
      volatile uint32_t reserved1 : 5;  /* [7:3] */
      volatile uint32_t ertcsel : 2;    /* [9:8] */
      volatile uint32_t reserved2 : 5;  /* [14:10] */
      volatile uint32_t ertcen : 1;     /* [15] */
      volatile uint32_t bpdrst : 1;     /* [16] */
      volatile uint32_t reserved3 : 15; /* [31:17] */
    } bpdc_bit;
  };

  /**
   * @brief crm ctrlsts register, offset:0x24
   */
  union {
    volatile uint32_t ctrlsts;

    struct {
      volatile uint32_t licken : 1;     /* [0] */
      volatile uint32_t lickstbl : 1;   /* [1] */
      volatile uint32_t reserved1 : 22; /* [23:2] */
      volatile uint32_t rstfc : 1;      /* [24] */
      volatile uint32_t reserved2 : 1;  /* [25] */
      volatile uint32_t nrstf : 1;      /* [26] */
      volatile uint32_t porrstf : 1;    /* [27] */
      volatile uint32_t swrstf : 1;     /* [28] */
      volatile uint32_t wdtrstf : 1;    /* [29] */
      volatile uint32_t wwdtrstf : 1;   /* [30] */
      volatile uint32_t lprstf : 1;     /* [31] */
    } ctrlsts_bit;
  };

  /**
   * @brief crm ahbrst register, offset:0x28
   */
  union {
    volatile uint32_t ahbrst;

    struct {
      volatile uint32_t reserved1 : 12; /* [11:0] */
      volatile uint32_t usbrst : 1;     /* [12] */
      volatile uint32_t reserved2 : 19; /* [31:13] */
    } ahbrst_bit;
  };

  /**
   * @brief crm pll register, offset:0x2C
   */
  union {
    volatile uint32_t pll;

    struct {
      volatile uint32_t pllfr : 3;     /* [2:0] */
      volatile uint32_t reserved1 : 1; /* [3] */
      volatile uint32_t pllms : 4;     /* [7:4] */
      volatile uint32_t pllns : 9;     /* [16:8] */
      volatile uint32_t reserved2 : 7; /* [23:17] */
      volatile uint32_t pllfref : 3;   /* [26:24] */
      volatile uint32_t reserved3 : 4; /* [30:27] */
      volatile uint32_t pllcfgen : 1;  /* [31] */
    } pll_bit;
  };

  /**
   * @brief crm misc1 register, offset:0x30
   */
  union {
    volatile uint32_t misc1;

    struct {
      volatile uint32_t hickcal_key : 8; /* [7:0] */
      volatile uint32_t reserved1 : 8;   /* [15:8] */
      volatile uint32_t clkout_sel : 1;  /* [16] */
      volatile uint32_t reserved2 : 7;   /* [23:17] */
      volatile uint32_t usbbufs : 1;     /* [24] */
      volatile uint32_t hickdiv : 1;     /* [25] */
      volatile uint32_t reserved3 : 2;   /* [27:26] */
      volatile uint32_t clkoutdiv : 4;   /* [31:28] */
    } misc1_bit;
  };

  /**
   * @brief crm reserved2 register, offset:0x40~0x34
   */
  volatile uint32_t reserved2[4];

  /**
   * @brief crm otg_extctrl register, offset:0x44
   */
  union {
    volatile uint32_t otg_extctrl;

    struct {
      volatile uint32_t reserved1 : 30; /* [29:0] */
      volatile uint32_t usbdivrst : 1;  /* [30] */
      volatile uint32_t ep3_rmpen : 1;  /* [31] */
    } otg_extctrl_bit;
  };

  /**
   * @brief crm reserved3 register, offset:0x50~0x48
   */
  volatile uint32_t reserved3[3];

  /**
   * @brief crm misc2 register, offset:0x54
   */
  union {
    volatile uint32_t misc2;

    struct {
      volatile uint32_t reserved1 : 4;    /* [3:0] */
      volatile uint32_t auto_step_en : 2; /* [5:4] */
      volatile uint32_t reserved2 : 2;    /* [7:6] */
      volatile uint32_t hick_to_usb : 1;  /* [8] */
      volatile uint32_t hick_to_sclk : 1; /* [9] */
      volatile uint32_t reserved3 : 22;   /* [31:10] */
    } misc2_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_9FFF35CD_8553_43AD_9E6C_30B44A70D2F0 */
