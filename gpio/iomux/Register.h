/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_29515626_3AE1_42CA_AF12_892D513B6068
#define CHIP_29515626_3AE1_42CA_AF12_892D513B6068

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::gpio::iomux {
  struct Register;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::gpio::iomux::Register {
  /**
   * @brief mux event control register, offset:0x00
   */
  union {
    volatile uint32_t evtout;

    struct {
      volatile uint32_t selpin : 4;     /* [3:0] */
      volatile uint32_t selport : 3;    /* [6:4] */
      volatile uint32_t evoen : 1;      /* [7]   */
      volatile uint32_t reserved1 : 24; /* [31:8] */
    } evtout_bit;
  };

  /**
   * @brief iomux remap register, offset:0x04
   */
  union {
    volatile uint32_t remap;

    struct {
      volatile uint32_t spi1_mux_l : 1;        /* [0] */
      volatile uint32_t i2c1_mux : 1;          /* [1] */
      volatile uint32_t usart1_mux : 1;        /* [2] */
      volatile uint32_t reserved1 : 1;         /* [3] */
      volatile uint32_t usart3_mux : 2;        /* [5:4] */
      volatile uint32_t tmr1_mux : 2;          /* [7:6] */
      volatile uint32_t tmr2_mux : 2;          /* [9:8] */
      volatile uint32_t tmr3_mux : 2;          /* [11:10] */
      volatile uint32_t reserved2 : 1;         /* [12] */
      volatile uint32_t can_mux : 2;           /* [14:13] */
      volatile uint32_t pd01_mux : 1;          /* [15] */
      volatile uint32_t tmr5ch4_mux : 1;       /* [16] */
      volatile uint32_t adc1_extrgpre_mux : 1; /* [17] */
      volatile uint32_t adc1_extrgord_mux : 1; /* [18] */
      volatile uint32_t reserved3 : 5;         /* [23:19] */
      volatile uint32_t swjtag_conf : 3;       /* [26:24] */
      volatile uint32_t reserved4 : 4;         /* [30:27] */
      volatile uint32_t spi1_mux_h : 1;        /* [31] */
    } remap_bit;
  };

  /**
   * @brief mux external interrupt configuration register 1, offset:0x08
   */
  union {
    volatile uint32_t exintc1;

    struct {
      volatile uint32_t exint0 : 4;     /* [3:0] */
      volatile uint32_t exint1 : 4;     /* [7:4] */
      volatile uint32_t exint2 : 4;     /* [11:8] */
      volatile uint32_t exint3 : 4;     /* [15:12] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } exintc1_bit;
  };

  /**
   * @brief mux external interrupt configuration register 2, offset:0x0c
   */
  union {
    volatile uint32_t exintc2;

    struct {
      volatile uint32_t exint4 : 4;     /* [3:0] */
      volatile uint32_t exint5 : 4;     /* [7:4] */
      volatile uint32_t exint6 : 4;     /* [11:8] */
      volatile uint32_t exint7 : 4;     /* [15:12] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } exintc2_bit;
  };

  /**
   * @brief mux external interrupt configuration register 3, offset:0x10
   */
  union {
    volatile uint32_t exintc3;

    struct {
      volatile uint32_t exint8 : 4;     /* [3:0] */
      volatile uint32_t exint9 : 4;     /* [7:4] */
      volatile uint32_t exint10 : 4;    /* [11:8] */
      volatile uint32_t exint11 : 4;    /* [15:12] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } exintc3_bit;
  };

  /**
   * @brief mux external interrupt configuration register 4, offset:0x14
   */
  union {
    volatile uint32_t exintc4;

    struct {
      volatile uint32_t exint12 : 4;    /* [3:0] */
      volatile uint32_t exint13 : 4;    /* [7:4] */
      volatile uint32_t exint14 : 4;    /* [11:8] */
      volatile uint32_t exint15 : 4;    /* [15:12] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } exintc4_bit;
  };

  /**
   * @brief iomux reserved1 register, offset:0x18
   */
  volatile uint32_t reserved1;

  /**
   * @brief iomux remap register 2, offset:0x1C
   */
  union {
    volatile uint32_t remap2;

    struct {
      volatile uint32_t reserved1 : 26; /* [25:0] */
      volatile uint32_t cmp_mux : 2;    /* [27:26] */
      volatile uint32_t reserved2 : 4;  /* [31:28] */
    } remap2_bit;
  };

  /**
   * @brief iomux remap register 3, offset:0x20
   */
  union {
    volatile uint32_t remap3;

    struct {
      volatile uint32_t tmr9_gmux : 4;  /* [3:0] */
      volatile uint32_t tmr10_gmux : 4; /* [7:4] */
      volatile uint32_t tmr11_gmux : 4; /* [11:8] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } remap3_bit;
  };

  /**
   * @brief iomux remap register 4, offset:0x24
   */
  union {
    volatile uint32_t remap4;

    struct {
      volatile uint32_t tmr1_gmux : 4;    /* [3:0] */
      volatile uint32_t tmr2_gmux : 3;    /* [6:4] */
      volatile uint32_t reserved1 : 1;    /* [7] */
      volatile uint32_t tmr3_gmux : 4;    /* [11:8] */
      volatile uint32_t reserved2 : 4;    /* [15:12] */
      volatile uint32_t tmr5_gmux : 3;    /* [18:16] */
      volatile uint32_t tmr5ch4_gmux : 1; /* [19] */
      volatile uint32_t reserved3 : 12;   /* [31:20] */
    } remap4_bit;
  };

  /**
   * @brief iomux remap register 5, offset:0x28
   */
  union {
    volatile uint32_t remap5;

    struct {
      volatile uint32_t reserved1 : 4; /* [3:0] */
      volatile uint32_t i2c1_gmux : 4; /* [7:4] */
      volatile uint32_t i2c2_gmux : 4; /* [11:8] */
      volatile uint32_t reserved2 : 4; /* [15:12] */
      volatile uint32_t spi1_gmux : 4; /* [19:16] */
      volatile uint32_t spi2_gmux : 4; /* [23:20] */
      volatile uint32_t reserved3 : 8; /* [31:24] */
    } remap5_bit;
  };

  /**
   * @brief iomux remap register 6, offset:0x2C
   */
  union {
    volatile uint32_t remap6;

    struct {
      volatile uint32_t can1_gmux : 4;   /* [3:0] */
      volatile uint32_t reserved1 : 4;   /* [7:4] */
      volatile uint32_t sdio1_gmux : 4;  /* [11:8] */
      volatile uint32_t reserved2 : 4;   /* [15:12] */
      volatile uint32_t usart1_gmux : 4; /* [19:16] */
      volatile uint32_t reserved3 : 4;   /* [23:20] */
      volatile uint32_t usart3_gmux : 4; /* [27:24] */
      volatile uint32_t uart4_gmux : 4;  /* [31:28] */
    } remap6_bit;
  };

  /**
   * @brief iomux remap register 7, offset:0x30
   */
  union {
    volatile uint32_t remap7;

    struct {
      volatile uint32_t reserved1 : 4;     /* [3:0] */
      volatile uint32_t adc1_etp_gmux : 1; /* [4] */
      volatile uint32_t adc1_eto_gmux : 1; /* [5] */
      volatile uint32_t reserved2 : 10;    /* [15:6] */
      volatile uint32_t swjtag_gmux : 3;   /* [18:16] */
      volatile uint32_t reserved3 : 1;     /* [19] */
      volatile uint32_t pd01_gmux : 1;     /* [20] */
      volatile uint32_t reserved4 : 11;    /* [31:21] */
    } remap7_bit;
  };

  /**
   * @brief iomux remap register 8, offset:0x34
   */
  union {
    volatile uint32_t remap8;

    struct {
      volatile uint32_t tmr1_bk1_cmp_gmux : 2; /* [1:0] */
      volatile uint32_t tmr1_ch1_cmp_gmux : 2; /* [3:2] */
      volatile uint32_t tmr2_ch4_cmp_gmux : 2; /* [5:4] */
      volatile uint32_t tmr3_ch1_cmp_gmux : 2; /* [7:6] */
      volatile uint32_t reserved1 : 24;        /* [31:8] */
    } remap8_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_29515626_3AE1_42CA_AF12_892D513B6068 */
