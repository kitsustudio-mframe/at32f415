/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_9777FF87_DD0B_49AD_86E1_7C26D8D2C829
#define AT32F415_9777FF87_DD0B_49AD_86E1_7C26D8D2C829

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr::output {
  enum struct ControlMode : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::output::ControlMode : uint8_t {
  OFF = 0x00,        /*!< tmr output control mode off */
  HIGH = 0x01,       /*!< tmr output control mode high */
  LOW = 0x02,        /*!< tmr output control mode low */
  SWITCH = 0x03,     /*!< tmr output control mode switch */
  FORCE_LOW = 0x04,  /*!< tmr output control mode force low */
  FORCE_HIGH = 0x05, /*!< tmr output control mode force high */
  PWM_MODE_A = 0x06, /*!< tmr output control mode pwm a */
  PWM_MODE_B = 0x07  /*!< tmr output control mode pwm b */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_9777FF87_DD0B_49AD_86E1_7C26D8D2C829 */
