/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_5CD8C65D_9F6C_443F_BBDE_F0DEEC68232B
#define AT32F415_5CD8C65D_9F6C_443F_BBDE_F0DEEC68232B

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
  enum struct Interrupt : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::Interrupt : uint32_t {
  OVF = 0x00000001,     /*!< tmr interrupt overflow */
  C1 = 0x00000002,      /*!< tmr interrupt channel 1 */
  C2 = 0x00000004,      /*!< tmr interrupt channel 2 */
  C3 = 0x00000008,      /*!< tmr interrupt channel 3 */
  C4 = 0x00000010,      /*!< tmr interrupt channel 4 */
  HALL = 0x00000020,    /*!< tmr interrupt hall */
  TRIGGER = 0x00000040, /*!< tmr interrupt trigger */
  BRK = 0x00000080      /*!< tmr interrupt brake */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_5CD8C65D_9F6C_443F_BBDE_F0DEEC68232B */
