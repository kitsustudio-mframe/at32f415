/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_268F6D7A_A882_4DAE_B476_D87D575EEC0A
#define CHIP_268F6D7A_A882_4DAE_B476_D87D575EEC0A

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::flash::usd {
  enum struct Key : uint16_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::flash::usd::Key : uint16_t {
  WDT_ATO_DISABLE = 0x0001,  ///< wdt auto start disabled
  WDT_ATO_ENABLE = 0x0000,   ///< wdt auto start enabled
  DEPSLP_NO_RST = 0x0002,    ///< no reset generated when entering in deepsleep
  DEPSLP_RST = 0x0000,       ///< reset generated when entering in deepsleep
  STDBY_NO_RST = 0x0004,     ///< no reset generated when entering in standby
  STDBY_RST = 0x0000         ///< reset generated when entering in standby
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_268F6D7A_A882_4DAE_B476_D87D575EEC0A */
