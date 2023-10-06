/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_65B39894_658F_47A2_A221_09CB611B7538
#define CHIP_65B39894_658F_47A2_A221_09CB611B7538

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::usart {
  enum struct Interrupt : uint32_t;
}  // namespace chip::usart

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::usart::Interrupt : uint32_t {
  IDLE = 0x000C0004, /*!< usart idle interrupt */
  RDBF = 0x000C0005, /*!< usart receive data buffer full interrupt */
  TDC = 0x000C0006,  /*!< usart transmit data complete interrupt */
  TDBE = 0x000C0007, /*!< usart transmit data buffer empty interrupt */
  PERR = 0x000C0008, /*!< usart parity error interrupt */
  BF = 0x00100006,   /*!< usart break frame interrupt */
  ERR = 0x00140000,  /*!< usart error interrupt */
  CTSCF = 0x0014000A /*!< usart cts change interrupt */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_65B39894_658F_47A2_A221_09CB611B7538 */
