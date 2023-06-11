/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_CFAE91AC_7EBB_431D_BBA3_C82F4F0B1405
#define CHIP_CFAE91AC_7EBB_431D_BBA3_C82F4F0B1405

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
  enum struct Regulator : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::pwc::Regulator : uint8_t {
  ON = 0x00,       /**< voltage regulator state on when deepsleep mode */
  LOW_POWER = 0x01 /**< voltage regulator state low power when deepsleep mode */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_CFAE91AC_7EBB_431D_BBA3_C82F4F0B1405 */
