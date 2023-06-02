/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_6A2F9514_AD1E_45B1_A4DB_CECEE6A9BC55
#define AT32F415_6A2F9514_AD1E_45B1_A4DB_CECEE6A9BC55

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"
//-----------------------------------------------------------------------------------------

#include "BreakPolarity.h"
#include "WriteProtectLevel.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr {
  struct BreakDutyConfig;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::tmr::BreakDutyConfig {
  uint8_t deadtime;                    /*!< dead-time generator setup */
  BreakPolarity breakPolarity;         /*!< tmr brake polarity */
  WriteProtectLevel writeProtectLevel; /*!< write protect configuration */
  bool autoOutputEnable;             /*!< automatic output enable */
  bool fcsoenState;                   /*!< frozen channel status when output enable */
  bool fcsodisState;                  /*!< frozen channel status when output disable */
  bool brkEnable;                     /*!< tmr brk enale */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_6A2F9514_AD1E_45B1_A4DB_CECEE6A9BC55 */
