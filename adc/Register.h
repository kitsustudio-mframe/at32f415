/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F2EEED98_0159_4FDE_B1EC_2B3A67375BC1
#define CHIP_F2EEED98_0159_4FDE_B1EC_2B3A67375BC1

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::adc {
  struct Register;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::adc::Register {
  /**
   * @brief adc sts register, offset:0x00
   */
  union {
    volatile uint32_t sts;

    struct {
      volatile uint32_t vmor : 1;       /* [0] */
      volatile uint32_t cce : 1;        /* [1] */
      volatile uint32_t pcce : 1;       /* [2] */
      volatile uint32_t pccs : 1;       /* [3] */
      volatile uint32_t occs : 1;       /* [4] */
      volatile uint32_t reserved1 : 27; /* [31:5] */
    } sts_bit;
  };

  /**
   * @brief adc ctrl1 register, offset:0x04
   */
  union {
    volatile uint32_t ctrl1;

    struct {
      volatile uint32_t vmcsel : 5;    /* [4:0] */
      volatile uint32_t cceien : 1;    /* [5] */
      volatile uint32_t vmorien : 1;   /* [6] */
      volatile uint32_t pcceien : 1;   /* [7] */
      volatile uint32_t sqen : 1;      /* [8] */
      volatile uint32_t vmsgen : 1;    /* [9] */
      volatile uint32_t pcautoen : 1;  /* [10] */
      volatile uint32_t ocpen : 1;     /* [11] */
      volatile uint32_t pcpen : 1;     /* [12] */
      volatile uint32_t ocpcnt : 3;    /* [15:13] */
      volatile uint32_t reserved1 : 6; /* [21:16] */
      volatile uint32_t pcvmen : 1;    /* [22] */
      volatile uint32_t ocvmen : 1;    /* [23] */
      volatile uint32_t reserved2 : 8; /* [31:24] */
    } ctrl1_bit;
  };

  /**
   * @brief adc ctrl2 register, offset:0x08
   */
  union {
    volatile uint32_t ctrl2;

    struct {
      volatile uint32_t adcen : 1;     /* [0] */
      volatile uint32_t rpen : 1;      /* [1] */
      volatile uint32_t adcal : 1;     /* [2] */
      volatile uint32_t adcalinit : 1; /* [3] */
      volatile uint32_t reserved1 : 4; /* [7:4] */
      volatile uint32_t ocdmaen : 1;   /* [8] */
      volatile uint32_t reserved2 : 2; /* [10:9] */
      volatile uint32_t dtalign : 1;   /* [11] */
      volatile uint32_t pctesel_l : 3; /* [14:12] */
      volatile uint32_t pcten : 1;     /* [15] */
      volatile uint32_t reserved3 : 1; /* [16] */
      volatile uint32_t octesel_l : 3; /* [19:17] */
      volatile uint32_t octen : 1;     /* [20] */
      volatile uint32_t pcswtrg : 1;   /* [21] */
      volatile uint32_t ocswtrg : 1;   /* [22] */
      volatile uint32_t itsrven : 1;   /* [23] */
      volatile uint32_t pctesel_h : 1; /* [24] */
      volatile uint32_t octesel_h : 1; /* [25] */
      volatile uint32_t reserved4 : 6; /* [31:26] */
    } ctrl2_bit;
  };

  /**
   * @brief adc spt1 register, offset:0x0C
   */
  union {
    volatile uint32_t spt1;

    struct {
      volatile uint32_t cspt10 : 3;    /* [2:0] */
      volatile uint32_t cspt11 : 3;    /* [5:3] */
      volatile uint32_t cspt12 : 3;    /* [8:6] */
      volatile uint32_t cspt13 : 3;    /* [11:9] */
      volatile uint32_t cspt14 : 3;    /* [14:12] */
      volatile uint32_t cspt15 : 3;    /* [17:15] */
      volatile uint32_t cspt16 : 3;    /* [20:18] */
      volatile uint32_t cspt17 : 3;    /* [23:21] */
      volatile uint32_t reserved1 : 8; /* [31:24] */
    } spt1_bit;
  };

  /**
   * @brief adc spt2 register, offset:0x10
   */
  union {
    volatile uint32_t spt2;

    struct {
      volatile uint32_t cspt0 : 3;     /* [2:0] */
      volatile uint32_t cspt1 : 3;     /* [5:3] */
      volatile uint32_t cspt2 : 3;     /* [8:6] */
      volatile uint32_t cspt3 : 3;     /* [11:9] */
      volatile uint32_t cspt4 : 3;     /* [14:12] */
      volatile uint32_t cspt5 : 3;     /* [17:15] */
      volatile uint32_t cspt6 : 3;     /* [20:18] */
      volatile uint32_t cspt7 : 3;     /* [23:21] */
      volatile uint32_t cspt8 : 3;     /* [26:24] */
      volatile uint32_t cspt9 : 3;     /* [29:27] */
      volatile uint32_t reserved1 : 2; /* [31:30] */
    } spt2_bit;
  };

  /**
   * @brief adc pcdto1 register, offset:0x14
   */
  union {
    volatile uint32_t pcdto1;

    struct {
      volatile uint32_t pcdto1 : 12;    /* [11:0] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } pcdto1_bit;
  };

  /**
   * @brief adc pcdto2 register, offset:0x18
   */
  union {
    volatile uint32_t pcdto2;

    struct {
      volatile uint32_t pcdto2 : 12;    /* [11:0] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } pcdto2_bit;
  };

  /**
   * @brief adc pcdto3 register, offset:0x1C
   */
  union {
    volatile uint32_t pcdto3;

    struct {
      volatile uint32_t pcdto3 : 12;    /* [11:0] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } pcdto3_bit;
  };

  /**
   * @brief adc pcdto4 register, offset:0x20
   */
  union {
    volatile uint32_t pcdto4;

    struct {
      volatile uint32_t pcdto4 : 12;    /* [11:0] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } pcdto4_bit;
  };

  /**
   * @brief adc vmhb register, offset:0x24
   */
  union {
    volatile uint32_t vmhb;

    struct {
      volatile uint32_t vmhb : 12;      /* [11:0] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } vmhb_bit;
  };

  /**
   * @brief adc vmlb register, offset:0x28
   */
  union {
    volatile uint32_t vmlb;

    struct {
      volatile uint32_t vmlb : 12;      /* [11:0] */
      volatile uint32_t reserved1 : 20; /* [31:12] */
    } vmlb_bit;
  };

  /**
   * @brief adc osq1 register, offset:0x2C
   */
  union {
    volatile uint32_t osq1;

    struct {
      volatile uint32_t osn13 : 5;     /* [4:0] */
      volatile uint32_t osn14 : 5;     /* [9:5] */
      volatile uint32_t osn15 : 5;     /* [14:10] */
      volatile uint32_t osn16 : 5;     /* [19:15] */
      volatile uint32_t oclen : 4;     /* [23:20] */
      volatile uint32_t reserved1 : 8; /* [31:24] */
    } osq1_bit;
  };

  /**
   * @brief adc osq2 register, offset:0x30
   */
  union {
    volatile uint32_t osq2;

    struct {
      volatile uint32_t osn7 : 5;      /* [4:0] */
      volatile uint32_t osn8 : 5;      /* [9:5] */
      volatile uint32_t osn9 : 5;      /* [14:10] */
      volatile uint32_t osn10 : 5;     /* [19:15] */
      volatile uint32_t osn11 : 5;     /* [24:20] */
      volatile uint32_t osn12 : 5;     /* [29:25] */
      volatile uint32_t reserved1 : 2; /* [31:30] */
    } osq2_bit;
  };

  /**
   * @brief adc osq3 register, offset:0x34
   */
  union {
    volatile uint32_t osq3;

    struct {
      volatile uint32_t osn1 : 5;      /* [4:0] */
      volatile uint32_t osn2 : 5;      /* [9:5] */
      volatile uint32_t osn3 : 5;      /* [14:10] */
      volatile uint32_t osn4 : 5;      /* [19:15] */
      volatile uint32_t osn5 : 5;      /* [24:20] */
      volatile uint32_t osn6 : 5;      /* [29:25] */
      volatile uint32_t reserved1 : 2; /* [31:30] */
    } osq3_bit;
  };

  /**
   * @brief adc psq register, offset:0x38
   */
  union {
    volatile uint32_t psq;

    struct {
      volatile uint32_t psn1 : 5;       /* [4:0] */
      volatile uint32_t psn2 : 5;       /* [9:5] */
      volatile uint32_t psn3 : 5;       /* [14:10] */
      volatile uint32_t psn4 : 5;       /* [19:15] */
      volatile uint32_t pclen : 2;      /* [21:20] */
      volatile uint32_t reserved1 : 10; /* [31:22] */
    } psq_bit;
  };

  /**
   * @brief adc pdt1 register, offset:0x3C
   */
  union {
    volatile uint32_t pdt1;

    struct {
      volatile uint32_t pdt1 : 16;      /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } pdt1_bit;
  };

  /**
   * @brief adc pdt2 register, offset:0x40
   */
  union {
    volatile uint32_t pdt2;

    struct {
      volatile uint32_t pdt2 : 16;      /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } pdt2_bit;
  };

  /**
   * @brief adc pdt3 register, offset:0x44
   */
  union {
    volatile uint32_t pdt3;

    struct {
      volatile uint32_t pdt3 : 16;      /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } pdt3_bit;
  };

  /**
   * @brief adc pdt4 register, offset:0x48
   */
  union {
    volatile uint32_t pdt4;

    struct {
      volatile uint32_t pdt4 : 16;      /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } pdt4_bit;
  };

  /**
   * @brief adc odt register, offset:0x4C
   */
  union {
    volatile uint32_t odt;

    struct {
      volatile uint32_t odt : 16;       /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } odt_bit;
  };
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_F2EEED98_0159_4FDE_B1EC_2B3A67375BC1 */
