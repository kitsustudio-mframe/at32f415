/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_94A16326_DB1C_4148_AC85_9E762CF1E35B
#define AT32F415_94A16326_DB1C_4148_AC85_9E762CF1E35B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::flash {
  enum struct Timeout : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::flash::Timeout : uint32_t {
  ERASE = 0x40000000,       /*!< internal flash erase operation timeout */
  PROGRAMMING = 0x00100000, /*!< internal flash program operation timeout */
  OPERATION = 0x10000000   /*!< flash common operation timeout */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_94A16326_DB1C_4148_AC85_9E762CF1E35B */
