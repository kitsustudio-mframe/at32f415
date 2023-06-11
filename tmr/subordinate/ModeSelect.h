/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_D44FCB04_69D0_4E5E_A8D7_88BCFB506302
#define CHIP_D44FCB04_69D0_4E5E_A8D7_88BCFB506302

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::subordinate {
  enum struct ModeSelect : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::subordinate::ModeSelect : uint8_t {
  DISABLE = 0x00,         /*!< subordinate mode disable */
  ENCODER_A = 0x01,       /*!< subordinate mode select encoder mode a */
  ENCODER_B = 0x02,       /*!< subordinate mode select encoder mode b */
  ENCODER_C = 0x03,       /*!< subordinate mode select encoder mode c */
  RESET = 0x04,           /*!< subordinate mode select reset */
  HANG = 0x05,            /*!< subordinate mode select hang */
  TRIGGER = 0x06,         /*!< subordinate mode select trigger */
  EXTERNAL_CLOCK_A = 0x07 /*!< subordinate mode external clock mode a */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_D44FCB04_69D0_4E5E_A8D7_88BCFB506302 */
