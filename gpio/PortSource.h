/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_6FB3DB1D_4754_4992_9404_97CDD6F40B7E
#define CHIP_6FB3DB1D_4754_4992_9404_97CDD6F40B7E

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::gpio {
  enum struct PortSource : uint8_t;
}  // namespace chip::gpio

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::gpio::PortSource : uint8_t {
  PORTA = 0x00,  ///< gpio port source gpioa
  PORTB = 0x01,  ///< gpio port source gpiob
  PORTC = 0x02,  ///< gpio port source gpioc
  PORTD = 0x03,  ///< gpio port source gpiod
  PORTF = 0x05   ///< gpio port source gpiof
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_6FB3DB1D_4754_4992_9404_97CDD6F40B7E */
