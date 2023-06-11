/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_94A16326_DB1C_4148_AC85_9E762CF1E35B
#define CHIP_94A16326_DB1C_4148_AC85_9E762CF1E35B

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::flash {
  enum struct Timeout : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::flash::Timeout : uint32_t {
  ERASE = 0x40000000,       /*!< internal flash erase operation timeout */
  PROGRAMMING = 0x00100000, /*!< internal flash program operation timeout */
  OPERATION = 0x10000000    /*!< flash common operation timeout */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_94A16326_DB1C_4148_AC85_9E762CF1E35B */
