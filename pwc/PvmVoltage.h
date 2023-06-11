/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_A1509F76_D764_443D_91AC_A52D865473C1
#define CHIP_A1509F76_D764_443D_91AC_A52D865473C1

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
  enum struct PvmVoltage : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::pwc::PvmVoltage : uint8_t {
  VOLTAGE_2V3 = 0x01, /**< power voltage monitoring boundary 2.3v */
  VOLTAGE_2V4 = 0x02, /**< power voltage monitoring boundary 2.4v */
  VOLTAGE_2V5 = 0x03, /**< power voltage monitoring boundary 2.5v */
  VOLTAGE_2V6 = 0x04, /**< power voltage monitoring boundary 2.6v */
  VOLTAGE_2V7 = 0x05, /**< power voltage monitoring boundary 2.7v */
  VOLTAGE_2V8 = 0x06, /**< power voltage monitoring boundary 2.8v */
  VOLTAGE_2V9 = 0x07  /**< power voltage monitoring boundary 2.9v */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_A1509F76_D764_443D_91AC_A52D865473C1 */
