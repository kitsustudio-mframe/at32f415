/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_CD1272B1_5F21_42FF_AC61_8C8167F08483
#define CHIP_CD1272B1_5F21_42FF_AC61_8C8167F08483

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::crm {
  enum struct ClockOutSelect : uint8_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::ClockOutSelect : uint8_t {
  SELECT_NOCLK = 0x00,     /*!< output no clock to clkout pin */
  SELECT_LICK = 0x02,      /*!< output low speed internal clock to clkout pin */
  SELECT_LEXT = 0x03,      /*!< output low speed external crystal to clkout pin */
  SELECT_SCLK = 0x04,      /*!< output system clock to clkout pin */
  SELECT_HICK = 0x05,      /*!< output high speed internal clock to clkout pin */
  SELECT_HEXT = 0x06,      /*!< output high speed external crystal to clkout pin */
  SELECT_PLL_DIV_2 = 0x07, /*!< output phase locking loop clock div2 to clkout pin */
  SELECT_PLL_DIV_4 = 0x0C, /*!< output phase locking loop clock div4 to clkout pin */
  SELECT_USB = 0x0D,       /*!< output usbclk to clkout pin */
  SELECT_ADC = 0x0E        /*!< output adcclk to clkout pin */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_CD1272B1_5F21_42FF_AC61_8C8167F08483 */
