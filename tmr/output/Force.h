/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_F1CB9A6E_29F9_4893_B6AE_1964BAED990F
#define AT32F415_F1CB9A6E_29F9_4893_B6AE_1964BAED990F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "ControlMode.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::output {
  enum struct Force : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::output::Force : uint8_t {
  HIGH = static_cast<uint8_t>(ControlMode::FORCE_HIGH), /*!< tmr force output high */
  LOW = static_cast<uint8_t>(ControlMode::FORCE_LOW)    /*!< tmr force output low */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_F1CB9A6E_29F9_4893_B6AE_1964BAED990F */
