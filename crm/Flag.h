/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_BD79F8B0_71DA_4448_AE77_182EA72B16D9
#define CHIP_BD79F8B0_71DA_4448_AE77_182EA72B16D9

#define ENUM_MAKE_VALUE(reg_offset, bit_num) static_cast<uint32_t>(((reg_offset) << 16) | (bit_num & 0x1F))

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct Flag : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::Flag : uint32_t {
  HICK_STABLE = ENUM_MAKE_VALUE(0x00, 1),      /**< high speed internal clock stable flag */
  HEXT_STABLE = ENUM_MAKE_VALUE(0x00, 17),     /**< high speed external crystal stable flag */
  PLL_STABLE = ENUM_MAKE_VALUE(0x00, 25),      /**< phase locking loop stable flag */
  LEXT_STABLE = ENUM_MAKE_VALUE(0x20, 1),      /**< low speed external crystal stable flag */
  LICK_STABLE = ENUM_MAKE_VALUE(0x24, 1),      /**< low speed internal clock stable flag */
  ALL_RESET = ENUM_MAKE_VALUE(0x24, 24),       /**< all reset flag */
  NRST_RESET = ENUM_MAKE_VALUE(0x24, 26),      /**< nrst pin reset flag */
  POR_RESET = ENUM_MAKE_VALUE(0x24, 27),       /**< power on reset flag */
  SW_RESET = ENUM_MAKE_VALUE(0x24, 28),        /**< software reset flag */
  WDT_RESET = ENUM_MAKE_VALUE(0x24, 29),       /**< watchdog timer reset flag */
  WWDT_RESET = ENUM_MAKE_VALUE(0x24, 30),      /**< window watchdog timer reset flag */
  LOWPOWER_RESET = ENUM_MAKE_VALUE(0x24, 31),  /**< low-power reset flag */
  LICK_READY_INT = ENUM_MAKE_VALUE(0x08, 0),   /**< low speed internal clock stable interrupt ready flag */
  LEXT_READY_INT = ENUM_MAKE_VALUE(0x08, 1),   /**< low speed external crystal stable interrupt ready flag */
  HICK_READY_INT = ENUM_MAKE_VALUE(0x08, 2),   /**< high speed internal clock stable interrupt ready flag */
  HEXT_READY_INT = ENUM_MAKE_VALUE(0x08, 3),   /**< high speed external crystal stable interrupt ready flag */
  PLL_READY_INT = ENUM_MAKE_VALUE(0x08, 4),    /**< phase locking loop stable interrupt ready flag */
  CLOCK_FAILURE_INT = ENUM_MAKE_VALUE(0x08, 7) /**< clock failure interrupt ready flag */
};

#undef ENUM_MAKE_VALUE

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_BD79F8B0_71DA_4448_AE77_182EA72B16D9 */
