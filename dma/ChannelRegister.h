/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F464D371_68CB_46D5_8719_AF6A6CF427D6
#define CHIP_F464D371_68CB_46D5_8719_AF6A6CF427D6

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  struct ChannelRegister;
}  // namespace chip::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::dma::ChannelRegister {
  /**
   * @brief dma ctrl register, offset:0x08+20*(x-1) x=1...7
   */
  union {
    volatile uint32_t ctrl;

    struct {
      volatile uint32_t chen : 1;       /* [0] */
      volatile uint32_t fdtien : 1;     /* [1] */
      volatile uint32_t hdtien : 1;     /* [2] */
      volatile uint32_t dterrien : 1;   /* [3] */
      volatile uint32_t dtd : 1;        /* [4] */
      volatile uint32_t lm : 1;         /* [5] */
      volatile uint32_t pincm : 1;      /* [6] */
      volatile uint32_t mincm : 1;      /* [7] */
      volatile uint32_t pwidth : 2;     /* [9:8] */
      volatile uint32_t mwidth : 2;     /* [11:10] */
      volatile uint32_t chpl : 2;       /* [13:12] */
      volatile uint32_t m2m : 1;        /* [14] */
      volatile uint32_t reserved1 : 17; /* [31:15] */
    } ctrl_bit;
  };

  /**
   * @brief dma dtcnt register, offset:0x0C+20*(x-1) x=1...7
   */
  union {
    volatile uint32_t dtcnt;

    struct {
      volatile uint32_t cnt : 16;       /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } dtcnt_bit;
  };

  /**
   * @brief dma cpba register, offset:0x10+20*(x-1) x=1...7
   */
  union {
    volatile uint32_t paddr;

    struct {
      volatile uint32_t paddr : 32; /* [31:0] */
    } paddr_bit;
  };

  /**
   * @brief dma cmba register, offset:0x14+20*(x-1) x=1...7
   */
  union {
    volatile uint32_t maddr;

    struct {
      volatile uint32_t maddr : 32; /* [31:0] */
    } maddr_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_F464D371_68CB_46D5_8719_AF6A6CF427D6 */
