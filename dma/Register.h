/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_49023B13_D982_482E_84C3_8DAD8B6AA9EA
#define CHIP_49023B13_D982_482E_84C3_8DAD8B6AA9EA

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  struct Register;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::dma::Register {
  /**
   * @brief dma sts register, offset:0x00
   */
  union {
    volatile uint32_t sts;

    struct {
      volatile uint32_t gf1 : 1;       /* [0] */
      volatile uint32_t fdtf1 : 1;     /* [1] */
      volatile uint32_t hdtf1 : 1;     /* [2] */
      volatile uint32_t dterrf1 : 1;   /* [3] */
      volatile uint32_t gf2 : 1;       /* [4] */
      volatile uint32_t fdtf2 : 1;     /* [5] */
      volatile uint32_t hdtf2 : 1;     /* [6] */
      volatile uint32_t dterrf2 : 1;   /* [7] */
      volatile uint32_t gf3 : 1;       /* [8] */
      volatile uint32_t fdtf3 : 1;     /* [9] */
      volatile uint32_t hdtf3 : 1;     /* [10] */
      volatile uint32_t dterrf3 : 1;   /* [11] */
      volatile uint32_t gf4 : 1;       /* [12] */
      volatile uint32_t fdtf4 : 1;     /* [13] */
      volatile uint32_t hdtf4 : 1;     /* [14] */
      volatile uint32_t dterrf4 : 1;   /* [15] */
      volatile uint32_t gf5 : 1;       /* [16] */
      volatile uint32_t fdtf5 : 1;     /* [17] */
      volatile uint32_t hdtf5 : 1;     /* [18] */
      volatile uint32_t dterrf5 : 1;   /* [19] */
      volatile uint32_t gf6 : 1;       /* [20] */
      volatile uint32_t fdtf6 : 1;     /* [21] */
      volatile uint32_t hdtf6 : 1;     /* [22] */
      volatile uint32_t dterrf6 : 1;   /* [23] */
      volatile uint32_t gf7 : 1;       /* [24] */
      volatile uint32_t fdtf7 : 1;     /* [25] */
      volatile uint32_t hdtf7 : 1;     /* [26] */
      volatile uint32_t dterrf7 : 1;   /* [27] */
      volatile uint32_t reserved1 : 4; /* [31:28] */
    } sts_bit;
  };

  /**
   * @brief dma clr register, offset:0x04
   */
  union {
    volatile uint32_t clr;

    struct {
      volatile uint32_t gfc1 : 1;      /* [0] */
      volatile uint32_t fdtfc1 : 1;    /* [1] */
      volatile uint32_t hdtfc1 : 1;    /* [2] */
      volatile uint32_t dterrfc1 : 1;  /* [3] */
      volatile uint32_t gfc2 : 1;      /* [4] */
      volatile uint32_t fdtfc2 : 1;    /* [5] */
      volatile uint32_t hdtfc2 : 1;    /* [6] */
      volatile uint32_t dterrfc2 : 1;  /* [7] */
      volatile uint32_t gfc3 : 1;      /* [8] */
      volatile uint32_t fdtfc3 : 1;    /* [9] */
      volatile uint32_t hdtfc3 : 1;    /* [10] */
      volatile uint32_t dterrfc3 : 1;  /* [11] */
      volatile uint32_t gfc4 : 1;      /* [12] */
      volatile uint32_t fdtfc4 : 1;    /* [13] */
      volatile uint32_t hdtfc4 : 1;    /* [14] */
      volatile uint32_t dterrfc4 : 1;  /* [15] */
      volatile uint32_t gfc5 : 1;      /* [16] */
      volatile uint32_t fdtfc5 : 1;    /* [17] */
      volatile uint32_t hdtfc5 : 1;    /* [18] */
      volatile uint32_t dterrfc5 : 1;  /* [19] */
      volatile uint32_t gfc6 : 1;      /* [20] */
      volatile uint32_t fdtfc6 : 1;    /* [21] */
      volatile uint32_t hdtfc6 : 1;    /* [22] */
      volatile uint32_t dterrfc6 : 1;  /* [23] */
      volatile uint32_t gfc7 : 1;      /* [24] */
      volatile uint32_t fdtfc7 : 1;    /* [25] */
      volatile uint32_t hdtfc7 : 1;    /* [26] */
      volatile uint32_t dterrfc7 : 1;  /* [27] */
      volatile uint32_t reserved1 : 4; /* [31:28] */
    } clr_bit;
  };
  /**
   * @brief reserved, offset:0x08~0x9C
   */
  volatile uint32_t reserved1[38];
  /**
   * @brief dma src_sel0 register, offset:0xA0
   */
  union {
    volatile uint32_t src_sel0;

    struct {
      volatile uint32_t ch1_src : 8; /* [7:0] */
      volatile uint32_t ch2_src : 8; /* [15:8] */
      volatile uint32_t ch3_src : 8; /* [23:16] */
      volatile uint32_t ch4_src : 8; /* [31:24] */
    } src_sel0_bit;
  };

  /**
   * @brief dma src_sel1 register, offset:0xA4
   */
  union {
    volatile uint32_t src_sel1;

    struct {
      volatile uint32_t ch5_src : 8;     /* [7:0] */
      volatile uint32_t ch6_src : 8;     /* [15:8] */
      volatile uint32_t ch7_src : 8;     /* [23:16] */
      volatile uint32_t dma_flex_en : 1; /* [24] */
      volatile uint32_t reserved1 : 7;   /* [31:25] */
    } src_sel1_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_49023B13_D982_482E_84C3_8DAD8B6AA9EA */
