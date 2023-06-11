/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_AD76D602_9981_4567_8C97_75ED53749791
#define CHIP_AD76D602_9981_4567_8C97_75ED53749791

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct Interrupt : uint32_t;

  enum_auto_operator(Interrupt, uint32_t)
}  // namespace chip::crm

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::Interrupt : uint32_t {
  LICK_STABLE = 0x00000100,  /**< low speed internal clock stable interrupt */
  LEXT_STABLE = 0x00000200,  /**< low speed external crystal stable interrupt */
  HICK_STABLE = 0x00000400,  /**< high speed internal clock stable interrupt */
  HEXT_STABLE = 0x00000800,  /**< high speed external crystal stable interrupt */
  PLL_STABLE = 0x00001000,   /**< phase locking loop stable interrupt */
  CLOCK_FAILURE = 0x00800000 /**< clock failure interrupt */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_AD76D602_9981_4567_8C97_75ED53749791 */
