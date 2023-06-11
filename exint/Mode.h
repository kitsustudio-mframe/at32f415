/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_6774CA30_BDEC_4755_BBFA_92A3A853634E
#define CHIP_6774CA30_BDEC_4755_BBFA_92A3A853634E

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::exint {
  enum struct Mode : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::exint::Mode : uint8_t {
  INTERRUPUT = 0x00,  ///< external interrupt line interrupt mode
  EVENT = 0x01        ///< external interrupt line event mode
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_6774CA30_BDEC_4755_BBFA_92A3A853634E */
