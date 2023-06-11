/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_3DD54F4F_E32E_4397_8998_8903C4FE0438
#define CHIP_3DD54F4F_E32E_4397_8998_8903C4FE0438

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::usart {
  enum struct Flag : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::Flag : uint32_t {
  PERR = 0x00000001,   ///< usart parity error flag
  FERR = 0x00000002,   ///< usart framing error flag
  NERR = 0x00000004,   ///< usart noise error flag
  ROERR = 0x00000008,  ///< usart receiver overflow error flag
  IDLEF = 0x00000010,  ///< usart idle flag
  RDBF = 0x00000020,   ///< usart receive data buffer full flag
  TDC = 0x00000040,    ///< usart transmit data complete flag
  TDBE = 0x00000080,   ///< usart transmit data buffer empty flag
  BFF = 0x00000100,    ///< usart break frame flag
  CTSCF = 0x00000200   ///< usart cts change flag
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_3DD54F4F_E32E_4397_8998_8903C4FE0438 */
