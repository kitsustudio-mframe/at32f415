/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_A345644A_1226_43CE_B779_7922F19F7A7D
#define CHIP_A345644A_1226_43CE_B779_7922F19F7A7D

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio {
  struct Register;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief
 * type define gpio register all
 *
 */
struct chip::gpio::Register {
  /**
   * @brief gpio cfglr register, offset:0x00
   */
  union {
    volatile uint32_t cfglr;

    struct {
      volatile uint32_t iomc0 : 2; /* [1:0] */
      volatile uint32_t iofc0 : 2; /* [3:2] */
      volatile uint32_t iomc1 : 2; /* [5:4] */
      volatile uint32_t iofc1 : 2; /* [7:6] */
      volatile uint32_t iomc2 : 2; /* [9:8] */
      volatile uint32_t iofc2 : 2; /* [11:10] */
      volatile uint32_t iomc3 : 2; /* [13:12] */
      volatile uint32_t iofc3 : 2; /* [15:14] */
      volatile uint32_t iomc4 : 2; /* [17:16] */
      volatile uint32_t iofc4 : 2; /* [19:18] */
      volatile uint32_t iomc5 : 2; /* [21:20] */
      volatile uint32_t iofc5 : 2; /* [23:22] */
      volatile uint32_t iomc6 : 2; /* [25:24] */
      volatile uint32_t iofc6 : 2; /* [27:26] */
      volatile uint32_t iomc7 : 2; /* [29:28] */
      volatile uint32_t iofc7 : 2; /* [31:30] */
    } cfglr_bit;
  };

  /**
   * @brief gpio cfghr register, offset:0x04
   */
  union {
    volatile uint32_t cfghr;

    struct {
      volatile uint32_t iomc8 : 2;  /* [1:0] */
      volatile uint32_t iofc8 : 2;  /* [3:2] */
      volatile uint32_t iomc9 : 2;  /* [5:4] */
      volatile uint32_t iofc9 : 2;  /* [7:6] */
      volatile uint32_t iomc10 : 2; /* [9:8] */
      volatile uint32_t iofc10 : 2; /* [11:10] */
      volatile uint32_t iomc11 : 2; /* [13:12] */
      volatile uint32_t iofc11 : 2; /* [15:14] */
      volatile uint32_t iomc12 : 2; /* [17:16] */
      volatile uint32_t iofc12 : 2; /* [19:18] */
      volatile uint32_t iomc13 : 2; /* [21:20] */
      volatile uint32_t iofc13 : 2; /* [23:22] */
      volatile uint32_t iomc14 : 2; /* [25:24] */
      volatile uint32_t iofc14 : 2; /* [27:26] */
      volatile uint32_t iomc15 : 2; /* [29:28] */
      volatile uint32_t iofc15 : 2; /* [31:30] */
    } cfghr_bit;
  };

  /**
   * @brief gpio idt register, offset:0x08
   */
  union {
    volatile uint32_t idt;

    struct {
      volatile uint32_t idt0 : 1;       /* [0] */
      volatile uint32_t idt1 : 1;       /* [1] */
      volatile uint32_t idt2 : 1;       /* [2] */
      volatile uint32_t idt3 : 1;       /* [3] */
      volatile uint32_t idt4 : 1;       /* [4] */
      volatile uint32_t idt5 : 1;       /* [5] */
      volatile uint32_t idt6 : 1;       /* [6] */
      volatile uint32_t idt7 : 1;       /* [7] */
      volatile uint32_t idt8 : 1;       /* [8] */
      volatile uint32_t idt9 : 1;       /* [9] */
      volatile uint32_t idt10 : 1;      /* [10] */
      volatile uint32_t idt11 : 1;      /* [11] */
      volatile uint32_t idt12 : 1;      /* [12] */
      volatile uint32_t idt13 : 1;      /* [13] */
      volatile uint32_t idt14 : 1;      /* [14] */
      volatile uint32_t idt15 : 1;      /* [15] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } idt_bit;
  };

  /**
   * @brief gpio odt register, offset:0x0C
   */
  union {
    volatile uint32_t odt;

    struct {
      volatile uint32_t odt0 : 1;       /* [0] */
      volatile uint32_t odt1 : 1;       /* [1] */
      volatile uint32_t odt2 : 1;       /* [2] */
      volatile uint32_t odt3 : 1;       /* [3] */
      volatile uint32_t odt4 : 1;       /* [4] */
      volatile uint32_t odt5 : 1;       /* [5] */
      volatile uint32_t odt6 : 1;       /* [6] */
      volatile uint32_t odt7 : 1;       /* [7] */
      volatile uint32_t odt8 : 1;       /* [8] */
      volatile uint32_t odt9 : 1;       /* [9] */
      volatile uint32_t odt10 : 1;      /* [10] */
      volatile uint32_t odt11 : 1;      /* [11] */
      volatile uint32_t odt12 : 1;      /* [12] */
      volatile uint32_t odt13 : 1;      /* [13] */
      volatile uint32_t odt14 : 1;      /* [14] */
      volatile uint32_t odt15 : 1;      /* [15] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } odt_bit;
  };

  /**
   * @brief gpio scr register, offset:0x10
   */
  union {
    volatile uint32_t scr;

    struct {
      volatile uint32_t iosb0 : 1;  /* [0] */
      volatile uint32_t iosb1 : 1;  /* [1] */
      volatile uint32_t iosb2 : 1;  /* [2] */
      volatile uint32_t iosb3 : 1;  /* [3] */
      volatile uint32_t iosb4 : 1;  /* [4] */
      volatile uint32_t iosb5 : 1;  /* [5] */
      volatile uint32_t iosb6 : 1;  /* [6] */
      volatile uint32_t iosb7 : 1;  /* [7] */
      volatile uint32_t iosb8 : 1;  /* [8] */
      volatile uint32_t iosb9 : 1;  /* [9] */
      volatile uint32_t iosb10 : 1; /* [10] */
      volatile uint32_t iosb11 : 1; /* [11] */
      volatile uint32_t iosb12 : 1; /* [12] */
      volatile uint32_t iosb13 : 1; /* [13] */
      volatile uint32_t iosb14 : 1; /* [14] */
      volatile uint32_t iosb15 : 1; /* [15] */
      volatile uint32_t iocb0 : 1;  /* [16] */
      volatile uint32_t iocb1 : 1;  /* [17] */
      volatile uint32_t iocb2 : 1;  /* [18] */
      volatile uint32_t iocb3 : 1;  /* [19] */
      volatile uint32_t iocb4 : 1;  /* [20] */
      volatile uint32_t iocb5 : 1;  /* [21] */
      volatile uint32_t iocb6 : 1;  /* [22] */
      volatile uint32_t iocb7 : 1;  /* [23] */
      volatile uint32_t iocb8 : 1;  /* [24] */
      volatile uint32_t iocb9 : 1;  /* [25] */
      volatile uint32_t iocb10 : 1; /* [26] */
      volatile uint32_t iocb11 : 1; /* [27] */
      volatile uint32_t iocb12 : 1; /* [28] */
      volatile uint32_t iocb13 : 1; /* [29] */
      volatile uint32_t iocb14 : 1; /* [30] */
      volatile uint32_t iocb15 : 1; /* [31] */
    } scr_bit;
  };

  /**
   * @brief gpio clr register, offset:0x14
   */
  union {
    volatile uint32_t clr;

    struct {
      volatile uint32_t iocb0 : 1;      /* [0] */
      volatile uint32_t iocb1 : 1;      /* [1] */
      volatile uint32_t iocb2 : 1;      /* [2] */
      volatile uint32_t iocb3 : 1;      /* [3] */
      volatile uint32_t iocb4 : 1;      /* [4] */
      volatile uint32_t iocb5 : 1;      /* [5] */
      volatile uint32_t iocb6 : 1;      /* [6] */
      volatile uint32_t iocb7 : 1;      /* [7] */
      volatile uint32_t iocb8 : 1;      /* [8] */
      volatile uint32_t iocb9 : 1;      /* [9] */
      volatile uint32_t iocb10 : 1;     /* [10] */
      volatile uint32_t iocb11 : 1;     /* [11] */
      volatile uint32_t iocb12 : 1;     /* [12] */
      volatile uint32_t iocb13 : 1;     /* [13] */
      volatile uint32_t iocb14 : 1;     /* [14] */
      volatile uint32_t iocb15 : 1;     /* [15] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } clr_bit;
  };

  /**
   * @brief gpio wpr register, offset:0x18
   */
  union {
    volatile uint32_t wpr;

    struct {
      volatile uint32_t wpen0 : 1;      /* [0] */
      volatile uint32_t wpen1 : 1;      /* [1] */
      volatile uint32_t wpen2 : 1;      /* [2] */
      volatile uint32_t wpen3 : 1;      /* [3] */
      volatile uint32_t wpen4 : 1;      /* [4] */
      volatile uint32_t wpen5 : 1;      /* [5] */
      volatile uint32_t wpen6 : 1;      /* [6] */
      volatile uint32_t wpen7 : 1;      /* [7] */
      volatile uint32_t wpen8 : 1;      /* [8] */
      volatile uint32_t wpen9 : 1;      /* [9] */
      volatile uint32_t wpen10 : 1;     /* [10] */
      volatile uint32_t wpen11 : 1;     /* [11] */
      volatile uint32_t wpen12 : 1;     /* [12] */
      volatile uint32_t wpen13 : 1;     /* [13] */
      volatile uint32_t wpen14 : 1;     /* [14] */
      volatile uint32_t wpen15 : 1;     /* [15] */
      volatile uint32_t wpseq : 1;      /* [16] */
      volatile uint32_t reserved1 : 15; /* [31:17] */
    } wpr_bit;
  };
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_A345644A_1226_43CE_B779_7922F19F7A7D */
