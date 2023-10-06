/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E708045B_10A5_4791_B027_CDA6B47A5A87
#define CHIP_E708045B_10A5_4791_B027_CDA6B47A5A87

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::tmr {
  struct Register;
}  // namespace chip::tmr

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::tmr::Register {
  /**
   * @brief tmr ctrl1 register, offset:0x00
   */
  union {
    volatile uint32_t ctrl1;

    struct {
      volatile uint32_t tmren : 1;      /* [0] */
      volatile uint32_t ovfen : 1;      /* [1] */
      volatile uint32_t ovfs : 1;       /* [2] */
      volatile uint32_t ocmen : 1;      /* [3] */
      volatile uint32_t cnt_dir : 3;    /* [6:4] */
      volatile uint32_t prben : 1;      /* [7] */
      volatile uint32_t clkdiv : 2;     /* [9:8] */
      volatile uint32_t pmen : 1;       /* [10] */
      volatile uint32_t reserved1 : 21; /* [31:11] */
    } ctrl1_bit;
  };

  /**
   * @brief tmr ctrl2 register, offset:0x04
   */
  union {
    volatile uint32_t ctrl2;

    struct {
      volatile uint32_t cbctrl : 1;     /* [0] */
      volatile uint32_t reserved1 : 1;  /* [1] */
      volatile uint32_t ccfs : 1;       /* [2] */
      volatile uint32_t drs : 1;        /* [3] */
      volatile uint32_t ptos : 3;       /* [6:4] */
      volatile uint32_t c1insel : 1;    /* [7] */
      volatile uint32_t c1ios : 1;      /* [8] */
      volatile uint32_t c1cios : 1;     /* [9] */
      volatile uint32_t c2ios : 1;      /* [10] */
      volatile uint32_t c2cios : 1;     /* [11] */
      volatile uint32_t c3ios : 1;      /* [12] */
      volatile uint32_t c3cios : 1;     /* [13] */
      volatile uint32_t c4ios : 1;      /* [14] */
      volatile uint32_t reserved2 : 17; /* [31:15] */
    } ctrl2_bit;
  };

  /**
   * @brief tmr smc register, offset:0x08
   */
  union {
    volatile uint32_t stctrl;

    struct {
      volatile uint32_t smsel : 3;      /* [2:0] */
      volatile uint32_t reserved1 : 1;  /* [3] */
      volatile uint32_t stis : 3;       /* [6:4] */
      volatile uint32_t sts : 1;        /* [7] */
      volatile uint32_t esf : 4;        /* [11:8] */
      volatile uint32_t esdiv : 2;      /* [13:12] */
      volatile uint32_t ecmben : 1;     /* [14] */
      volatile uint32_t esp : 1;        /* [15] */
      volatile uint32_t reserved2 : 16; /* [31:16] */
    } stctrl_bit;
  };

  /**
   * @brief tmr die register, offset:0x0C
   */
  union {
    volatile uint32_t iden;

    struct {
      volatile uint32_t ovfien : 1;     /* [0] */
      volatile uint32_t c1ien : 1;      /* [1] */
      volatile uint32_t c2ien : 1;      /* [2] */
      volatile uint32_t c3ien : 1;      /* [3] */
      volatile uint32_t c4ien : 1;      /* [4] */
      volatile uint32_t hallien : 1;    /* [5] */
      volatile uint32_t tien : 1;       /* [6] */
      volatile uint32_t brkie : 1;      /* [7] */
      volatile uint32_t ovfden : 1;     /* [8] */
      volatile uint32_t c1den : 1;      /* [9] */
      volatile uint32_t c2den : 1;      /* [10] */
      volatile uint32_t c3den : 1;      /* [11] */
      volatile uint32_t c4den : 1;      /* [12] */
      volatile uint32_t hallde : 1;     /* [13] */
      volatile uint32_t tden : 1;       /* [14] */
      volatile uint32_t reserved1 : 17; /* [31:15] */
    } iden_bit;
  };

  /**
   * @brief tmr ists register, offset:0x10
   */
  union {
    volatile uint32_t ists;

    struct {
      volatile uint32_t ovfif : 1;      /* [0] */
      volatile uint32_t c1if : 1;       /* [1] */
      volatile uint32_t c2if : 1;       /* [2] */
      volatile uint32_t c3if : 1;       /* [3] */
      volatile uint32_t c4if : 1;       /* [4] */
      volatile uint32_t hallif : 1;     /* [5] */
      volatile uint32_t trgif : 1;      /* [6] */
      volatile uint32_t brkif : 1;      /* [7] */
      volatile uint32_t reserved1 : 1;  /* [8] */
      volatile uint32_t c1rf : 1;       /* [9] */
      volatile uint32_t c2rf : 1;       /* [10] */
      volatile uint32_t c3rf : 1;       /* [11] */
      volatile uint32_t c4rf : 1;       /* [12] */
      volatile uint32_t reserved2 : 19; /* [31:13] */
    } ists_bit;
  };

  /**
   * @brief tmr eveg register, offset:0x14
   */
  union {
    volatile uint32_t swevt;

    struct {
      volatile uint32_t ovfswtr : 1;   /* [0] */
      volatile uint32_t c1swtr : 1;    /* [1] */
      volatile uint32_t c2swtr : 1;    /* [2] */
      volatile uint32_t c3swtr : 1;    /* [3] */
      volatile uint32_t c4swtr : 1;    /* [4] */
      volatile uint32_t hallswtr : 1;  /* [5] */
      volatile uint32_t trgswtr : 1;   /* [6] */
      volatile uint32_t brkswtr : 1;   /* [7] */
      volatile uint32_t reserved : 24; /* [31:8] */
    } swevt_bit;
  };

  /**
   * @brief tmr ccm1 register, offset:0x18
   */
  union {
    volatile uint32_t cm1;

    /**
     * @brief channel mode
     */
    struct {
      volatile uint32_t c1c : 2;        /* [1:0] */
      volatile uint32_t c1oien : 1;     /* [2] */
      volatile uint32_t c1oben : 1;     /* [3] */
      volatile uint32_t c1octrl : 3;    /* [6:4] */
      volatile uint32_t c1osen : 1;     /* [7] */
      volatile uint32_t c2c : 2;        /* [9:8] */
      volatile uint32_t c2oien : 1;     /* [10] */
      volatile uint32_t c2oben : 1;     /* [11] */
      volatile uint32_t c2octrl : 3;    /* [14:12] */
      volatile uint32_t c2osen : 1;     /* [15] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } cm1_output_bit;

    /**
     * @brief input capture mode
     */
    struct {
      volatile uint32_t c1c : 2;        /* [1:0] */
      volatile uint32_t c1idiv : 2;     /* [3:2] */
      volatile uint32_t c1df : 4;       /* [7:4] */
      volatile uint32_t c2c : 2;        /* [9:8] */
      volatile uint32_t c2idiv : 2;     /* [11:10] */
      volatile uint32_t c2df : 4;       /* [15:12] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } cm1_input_bit;
  };

  /**
   * @brief tmr ccm2 register, offset:0x1C
   */
  union {
    volatile uint32_t cm2;

    /**
     * @brief channel mode
     */
    struct {
      volatile uint32_t c3c : 2;        /* [1:0] */
      volatile uint32_t c3oien : 1;     /* [2] */
      volatile uint32_t c3oben : 1;     /* [3] */
      volatile uint32_t c3octrl : 3;    /* [6:4] */
      volatile uint32_t c3osen : 1;     /* [7] */
      volatile uint32_t c4c : 2;        /* [9:8] */
      volatile uint32_t c4oien : 1;     /* [10] */
      volatile uint32_t c4oben : 1;     /* [11] */
      volatile uint32_t c4octrl : 3;    /* [14:12] */
      volatile uint32_t c4osen : 1;     /* [15] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } cm2_output_bit;

    /**
     * @brief input capture mode
     */
    struct {
      volatile uint32_t c3c : 2;        /* [1:0] */
      volatile uint32_t c3idiv : 2;     /* [3:2] */
      volatile uint32_t c3df : 4;       /* [7:4] */
      volatile uint32_t c4c : 2;        /* [9:8] */
      volatile uint32_t c4idiv : 2;     /* [11:10] */
      volatile uint32_t c4df : 4;       /* [15:12] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } cm2_input_bit;
  };

  /**
   * @brief tmr cce register, offset:0x20
   */
  union {
    uint32_t cctrl;
    struct {
      volatile uint32_t c1en : 1;       /* [0] */
      volatile uint32_t c1p : 1;        /* [1] */
      volatile uint32_t c1cen : 1;      /* [2] */
      volatile uint32_t c1cp : 1;       /* [3] */
      volatile uint32_t c2en : 1;       /* [4] */
      volatile uint32_t c2p : 1;        /* [5] */
      volatile uint32_t c2cen : 1;      /* [6] */
      volatile uint32_t c2cp : 1;       /* [7] */
      volatile uint32_t c3en : 1;       /* [8] */
      volatile uint32_t c3p : 1;        /* [9] */
      volatile uint32_t c3cen : 1;      /* [10] */
      volatile uint32_t c3cp : 1;       /* [11] */
      volatile uint32_t c4en : 1;       /* [12] */
      volatile uint32_t c4p : 1;        /* [13] */
      volatile uint32_t reserved1 : 18; /* [31:14] */
    } cctrl_bit;
  };

  /**
   * @brief tmr cnt register, offset:0x24
   */
  union {
    volatile uint32_t cval;

    struct {
      volatile uint32_t cval : 32; /* [31:0] */
    } cval_bit;
  };

  /**
   * @brief tmr div, offset:0x28
   */
  union {
    volatile uint32_t div;

    struct {
      volatile uint32_t div : 16;       /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } div_bit;
  };

  /**
   * @brief tmr pr register, offset:0x2C
   */
  union {
    volatile uint32_t pr;

    struct {
      volatile uint32_t pr : 32; /* [31:0] */
    } pr_bit;
  };

  /**
   * @brief tmr rpr register, offset:0x30
   */
  union {
    volatile uint32_t rpr;

    struct {
      volatile uint32_t rpr : 8;        /* [7:0] */
      volatile uint32_t reserved1 : 24; /* [31:8] */
    } rpr_bit;
  };

  /**
   * @brief tmr c1dt register, offset:0x34
   */
  union {
    uint32_t c1dt;

    struct {
      volatile uint32_t c1dt : 32; /* [31:0] */
    } c1dt_bit;
  };

  /**
   * @brief tmr c2dt register, offset:0x38
   */
  union {
    uint32_t c2dt;

    struct {
      volatile uint32_t c2dt : 32; /* [31:0] */
    } c2dt_bit;
  };

  /**
   * @brief tmr c3dt register, offset:0x3C
   */
  union {
    volatile uint32_t c3dt;

    struct {
      volatile uint32_t c3dt : 32; /* [31:0] */
    } c3dt_bit;
  };

  /**
   * @brief tmr c4dt register, offset:0x40
   */
  union {
    volatile uint32_t c4dt;

    struct {
      volatile uint32_t c4dt : 32; /* [31:0] */
    } c4dt_bit;
  };

  /**
   * @brief tmr brk register, offset:0x44
   */
  union {
    volatile uint32_t brk;

    struct {
      volatile uint32_t dtc : 8;        /* [7:0] */
      volatile uint32_t wpc : 2;        /* [9:8] */
      volatile uint32_t fcsodis : 1;    /* [10] */
      volatile uint32_t fcsoen : 1;     /* [11] */
      volatile uint32_t brken : 1;      /* [12] */
      volatile uint32_t brkv : 1;       /* [13] */
      volatile uint32_t aoen : 1;       /* [14] */
      volatile uint32_t oen : 1;        /* [15] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } brk_bit;
  };
  /**
   * @brief tmr dmactrl register, offset:0x48
   */
  union {
    volatile uint32_t dmactrl;

    struct {
      volatile uint32_t addr : 5;       /* [4:0] */
      volatile uint32_t reserved1 : 3;  /* [7:5] */
      volatile uint32_t dtb : 5;        /* [12:8] */
      volatile uint32_t reserved2 : 19; /* [31:13] */
    } dmactrl_bit;
  };

  /**
   * @brief tmr dmadt register, offset:0x4C
   */
  union {
    volatile uint32_t dmadt;

    struct {
      volatile uint32_t dmadt : 16;     /* [15:0] */
      volatile uint32_t reserved1 : 16; /* [31:16] */
    } dmadt_bit;
  };
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_E708045B_10A5_4791_B027_CDA6B47A5A87 */
