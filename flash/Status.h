/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_E29E2C8C_9B7E_472F_957C_F9F13E8D7CC7
#define CHIP_E29E2C8C_9B7E_472F_957C_F9F13E8D7CC7

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip ::flash {
  enum struct Status : uint8_t;
}  // namespace chip::flash

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::flash::Status : uint8_t {
  BUSY = 0x00,          /*!< flash status is operate busy */
  PROGRAM_ERROR = 0x01, /*!< flash status is program error */
  EPP_ERROR = 0x02,     /*!< flash status is epp error */
  DONE = 0x03,          /*!< flash status is operate done */
  TIMEOUT = 0x04        /*!< flash status is operate timeout */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_E29E2C8C_9B7E_472F_957C_F9F13E8D7CC7 */
