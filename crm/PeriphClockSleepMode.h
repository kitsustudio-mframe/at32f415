/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_C3472B20_E2B6_4D8C_9FF1_7CE64139E687
#define CHIP_C3472B20_E2B6_4D8C_9FF1_7CE64139E687

#define ENUM_MAKE_VALUE(reg_offset, bit_num) static_cast<uint32_t>(((reg_offset) << 16) | (bit_num & 0x1F))

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
  enum struct PeriphClockSleepMode : uint32_t;
}  // namespace chip::crm

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::crm::PeriphClockSleepMode : uint32_t {
  SRAM = ENUM_MAKE_VALUE(0x14, 2), /*!< sram sleep mode periph clock */
  FLASH = ENUM_MAKE_VALUE(0x14, 4) /*!< flash sleep mode periph clock */
};

#undef ENUM_MAKE_VALUE

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_C3472B20_E2B6_4D8C_9FF1_7CE64139E687 */
