/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F1CB9A6E_29F9_4893_B6AE_1964BAED990F
#define CHIP_F1CB9A6E_29F9_4893_B6AE_1964BAED990F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------
#include "ControlMode.h"

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr::output {
  enum struct Force : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::output::Force : uint8_t {
  HIGH = static_cast<uint8_t>(ControlMode::FORCE_HIGH), /*!< tmr force output high */
  LOW = static_cast<uint8_t>(ControlMode::FORCE_LOW)    /*!< tmr force output low */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_F1CB9A6E_29F9_4893_B6AE_1964BAED990F */
