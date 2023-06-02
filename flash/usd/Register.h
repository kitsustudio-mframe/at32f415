/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_9C4F51D0_DAD5_430D_AAC6_6608AF5E2495
#define AT32F415_9C4F51D0_DAD5_430D_AAC6_6608AF5E2495

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::flash::usd {
  struct Register;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::flash::usd::Register {
  volatile uint16_t fap;
  volatile uint16_t ssb;
  volatile uint16_t data0;
  volatile uint16_t data1;
  volatile uint16_t epp0;
  volatile uint16_t epp1;
  volatile uint16_t epp2;
  volatile uint16_t epp3;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_9C4F51D0_DAD5_430D_AAC6_6608AF5E2495 */
