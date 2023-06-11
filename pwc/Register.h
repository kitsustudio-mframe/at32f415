/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_06245A34_8EE0_4CD1_B02E_6E6E21FCF380
#define CHIP_06245A34_8EE0_4CD1_B02E_6E6E21FCF380

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::pwc {
  struct Register;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::pwc::Register {
  /**
   * @brief pwc ctrl register, offset:0x00
   */
  union {
    volatile uint32_t ctrl;

    struct {
      volatile uint32_t vrsel : 1;      /* [0] */
      volatile uint32_t lpsel : 1;      /* [1] */
      volatile uint32_t clswef : 1;     /* [2] */
      volatile uint32_t clsef : 1;      /* [3] */
      volatile uint32_t pvmen : 1;      /* [4] */
      volatile uint32_t pvmsel : 3;     /* [7:5] */
      volatile uint32_t bpwen : 1;      /* [8] */
      volatile uint32_t reserved1 : 23; /* [31:9] */
    } ctrl_bit;
  };

  /**
   * @brief pwc ctrlsts register, offset:0x04
   */
  union {
    volatile uint32_t ctrlsts;

    struct {
      volatile uint32_t swef : 1;       /* [0] */
      volatile uint32_t sef : 1;        /* [1] */
      volatile uint32_t pvmof : 1;      /* [2] */
      volatile uint32_t reserved1 : 5;  /* [7:3] */
      volatile uint32_t swpen : 1;      /* [8] */
      volatile uint32_t reserved2 : 23; /* [31:9] */
    } ctrlsts_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_06245A34_8EE0_4CD1_B02E_6E6E21FCF380 */
