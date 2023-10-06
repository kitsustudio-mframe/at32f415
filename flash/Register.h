/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_DA922D2F_7BEB_4160_9F37_DC1DCB160DBE
#define CHIP_DA922D2F_7BEB_4160_9F37_DC1DCB160DBE

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::flash {
  struct Register;
}

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
struct chip::flash::Register {
  /**
   * @brief flash psr register, offset:0x00
   */
  union {
    volatile uint32_t psr;

    struct {
      volatile uint32_t wtcyc : 3;      /* [2:0] */
      volatile uint32_t hfcyc_en : 1;   /* [3] */
      volatile uint32_t pft_en : 1;     /* [4] */
      volatile uint32_t pft_enf : 1;    /* [5] */
      volatile uint32_t reserved1 : 26; /* [31:6] */
    } psr_bit;
  };

  /**
   * @brief flash unlock register, offset:0x04
   */
  union {
    volatile uint32_t unlock;

    struct {
      volatile uint32_t ukval : 32; /* [31:0] */
    } unlock_bit;
  };

  /**
   * @brief flash usd unlock register, offset:0x08
   */
  union {
    volatile uint32_t usd_unlock;

    struct {
      volatile uint32_t usd_ukval : 32; /* [31:0] */
    } usd_unlock_bit;
  };

  /**
   * @brief flash sts register, offset:0x0C
   */
  union {
    volatile uint32_t sts;

    struct {
      volatile uint32_t obf : 1;        /* [0] */
      volatile uint32_t reserved1 : 1;  /* [1] */
      volatile uint32_t prgmerr : 1;    /* [2] */
      volatile uint32_t reserved2 : 1;  /* [3] */
      volatile uint32_t epperr : 1;     /* [4] */
      volatile uint32_t odf : 1;        /* [5] */
      volatile uint32_t reserved3 : 26; /* [31:6] */
    } sts_bit;
  };

  /**
   * @brief flash ctrl register, offset:0x10
   */
  union {
    volatile uint32_t ctrl;

    struct {
      volatile uint32_t fprgm : 1;      /* [0] */
      volatile uint32_t secers : 1;     /* [1] */
      volatile uint32_t bankers : 1;    /* [2] */
      volatile uint32_t reserved1 : 1;  /* [3] */
      volatile uint32_t usdprgm : 1;    /* [4] */
      volatile uint32_t usders : 1;     /* [5] */
      volatile uint32_t erstr : 1;      /* [6] */
      volatile uint32_t oplk : 1;       /* [7] */
      volatile uint32_t reserved2 : 1;  /* [8] */
      volatile uint32_t usdulks : 1;    /* [9] */
      volatile uint32_t errie : 1;      /* [10] */
      volatile uint32_t reserved3 : 1;  /* [11] */
      volatile uint32_t odfie : 1;      /* [12] */
      volatile uint32_t reserved4 : 3;  /* [15:13] */
      volatile uint32_t fap_hl_dis : 1; /* [16] */
      volatile uint32_t reserved5 : 15; /* [31:17] */
    } ctrl_bit;
  };

  /**
   * @brief flash addr register, offset:0x14
   */
  union {
    volatile uint32_t addr;

    struct {
      volatile uint32_t fa : 32; /* [31:0] */
    } addr_bit;
  };

  /**
   * @brief flash reserved1 register, offset:0x18
   */
  volatile uint32_t reserved1;

  /**
   * @brief flash usd register, offset:0x1C
   */
  union {
    volatile uint32_t usd;

    struct {
      volatile uint32_t usderr : 1;     /* [0] */
      volatile uint32_t fap : 1;        /* [1] */
      volatile uint32_t wdt_ato_en : 1; /* [2] */
      volatile uint32_t depslp_rst : 1; /* [3] */
      volatile uint32_t stdby_rst : 1;  /* [4] */
      volatile uint32_t reserved1 : 5;  /* [9:5] */
      volatile uint32_t user_d0 : 8;    /* [17:10] */
      volatile uint32_t user_d1 : 8;    /* [25:18] */
      volatile uint32_t fap_hl : 1;     /* [26] */
      volatile uint32_t reserved2 : 5;  /* [31:27] */
    } usd_bit;
  };

  /**
   * @brief flash epps register, offset:0x20
   */
  union {
    volatile uint32_t epps;

    struct {
      volatile uint32_t epps : 32; /* [31:0] */
    } epps_bit;
  };

  /**
   * @brief flash reserved2 register, offset:0x70~0x24
   */
  volatile uint32_t reserved2[20];

  /**
   * @brief flash slib_sts0 register, offset:0x74
   */
  union {
    volatile uint32_t slib_sts0;

    struct {
      volatile uint32_t btm_ap_enf : 1;     /* [0] */
      volatile uint32_t reserved1 : 1;      /* [1] */
      volatile uint32_t em_slib_enf : 1;    /* [2] */
      volatile uint32_t slib_enf : 1;       /* [3] */
      volatile uint32_t reserved2 : 12;     /* [15:4] */
      volatile uint32_t em_slib_dat_ss : 8; /* [23:16] */
      volatile uint32_t reserved3 : 8;      /* [31:24] */
    } slib_sts0_bit;
  };

  /**
   * @brief flash slib_sts1 register, offset:0x78
   */
  union {
    volatile uint32_t slib_sts1;

    struct {
      volatile uint32_t slib_ss : 11;     /* [10:0] */
      volatile uint32_t slib_dat_ss : 11; /* [21:11] */
      volatile uint32_t slib_es : 10;     /* [31:22] */
    } slib_sts1_bit;
  };

  /**
   * @brief flash slib_pwd_clr register, offset:0x7C
   */
  union {
    volatile uint32_t slib_pwd_clr;

    struct {
      volatile uint32_t slib_pclr_val : 32; /* [31:0] */
    } slib_pwd_clr_bit;
  };

  /**
   * @brief flash slib_misc_sts register, offset:0x80
   */
  union {
    volatile uint32_t slib_misc_sts;

    struct {
      volatile uint32_t slib_pwd_err : 1; /* [0] */
      volatile uint32_t slib_pwd_ok : 1;  /* [1] */
      volatile uint32_t slib_ulkf : 1;    /* [2] */
      volatile uint32_t reserved1 : 29;   /* [31:3] */
    } slib_misc_sts_bit;
  };

  /**
   * @brief flash crc_addr register, offset:0x84
   */
  union {
    volatile uint32_t crc_addr;

    struct {
      volatile uint32_t crc_addr : 32; /* [31:0] */
    } crc_addr_bit;
  };

  /**
   * @brief flash crc_ctrl register, offset:0x88
   */
  union {
    volatile uint32_t crc_ctrl;

    struct {
      volatile uint32_t crc_sn : 16;    /* [15:0] */
      volatile uint32_t crc_strt : 1;   /* [16] */
      volatile uint32_t reserved1 : 15; /* [31:17] */
    } crc_ctrl_bit;
  };

  /**
   * @brief flash crc_chkr register, offset:0x8C
   */
  union {
    volatile uint32_t crc_chkr;

    struct {
      volatile uint32_t crc_chkr : 32; /* [31:0] */
    } crc_chkr_bit;
  };

  /**
   * @brief flash reserved3 register, offset:0x15C~0x90
   */
  volatile uint32_t reserved3[52];

  /**
   * @brief flash slib_set_pwd register, offset:0x160
   */
  union {
    volatile uint32_t slib_set_pwd;

    struct {
      volatile uint32_t slib_pset_val : 32; /* [31:0] */
    } slib_set_pwd_bit;
  };

  /**
   * @brief flash slib_set_range register, offset:0x164
   */
  union {
    volatile uint32_t slib_set_range;

    struct {
      volatile uint32_t slib_ss_set : 11;  /* [10:0] */
      volatile uint32_t slib_dss_set : 11; /* [21:11] */
      volatile uint32_t slib_es_set : 10;  /* [31:22] */
    } slib_set_range_bit;
  };

  /**
   * @brief flash em_slib_set register, offset:0x168
   */
  union {
    volatile uint32_t em_slib_set;

    struct {
      volatile uint32_t em_slib_set : 16;    /* [15:0] */
      volatile uint32_t em_slib_iss_set : 8; /* [23:16] */
      volatile uint32_t reserved1 : 8;       /* [31:24] */
    } em_slib_set_bit;
  };

  /**
   * @brief flash btm_mode_set register, offset:0x16C
   */
  union {
    volatile uint32_t btm_mode_set;

    struct {
      volatile uint32_t btm_mode_set : 8; /* [7:0] */
      volatile uint32_t reserved1 : 24;   /* [31:8] */
    } btm_mode_set_bit;
  };

  /**
   * @brief flash slib_unlock register, offset:0x170
   */
  union {
    volatile uint32_t slib_unlock;

    struct {
      volatile uint32_t slib_ukval : 32; /* [31:0] */
    } slib_unlock_bit;
  };
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_DA922D2F_7BEB_4160_9F37_DC1DCB160DBE */
