/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_E29E2C8C_9B7E_472F_957C_F9F13E8D7CC7
#define AT32F415_E29E2C8C_9B7E_472F_957C_F9F13E8D7CC7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415 ::flash {
  enum struct Status : uint8_t;
}  // namespace at32f415::flash

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::flash::Status : uint8_t {
  BUSY = 0x00,          /*!< flash status is operate busy */
  PROGRAM_ERROR = 0x01, /*!< flash status is program error */
  EPP_ERROR = 0x02,     /*!< flash status is epp error */
  DONE = 0x03,          /*!< flash status is operate done */
  TIMEOUT = 0x04        /*!< flash status is operate timeout */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_E29E2C8C_9B7E_472F_957C_F9F13E8D7CC7 */
