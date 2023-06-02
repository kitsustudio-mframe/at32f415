/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_074A0DD1_CB6E_4CE0_8AC2_F216AFFACA2E
#define AT32F415_074A0DD1_CB6E_4CE0_8AC2_F216AFFACA2E

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr {
  enum struct PrimarySelect : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::PrimarySelect : uint8_t {
  RESET = 0x00,    /*!< tmr primary mode select reset */
  ENABLE = 0x01,   /*!< tmr primary mode select enable */
  OVERFLOW = 0x02, /*!< tmr primary mode select overflow */
  COMPARE = 0x03,  /*!< tmr primary mode select compare */
  C1ORAW = 0x04,   /*!< tmr primary mode select c1oraw */
  C2ORAW = 0x05,   /*!< tmr primary mode select c2oraw */
  C3ORAW = 0x06,   /*!< tmr primary mode select c3oraw */
  C4ORAW = 0x07    /*!< tmr primary mode select c4oraw */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_074A0DD1_CB6E_4CE0_8AC2_F216AFFACA2E */
