/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_DEB133D1_D421_4981_87F6_34A2047C78C4
#define CHIP_DEB133D1_D421_4981_87F6_34A2047C78C4

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::exint {
  enum struct Line : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::exint::Line : uint32_t {
  NONE = 0x00000000,    ///< none
  LINE0 = 0x00000001,   ///< external interrupt line 0
  LINE1 = 0x00000002,   ///< external interrupt line 1
  LINE2 = 0x00000004,   ///< external interrupt line 2
  LINE3 = 0x00000008,   ///< external interrupt line 3
  LINE4 = 0x00000010,   ///< external interrupt line 4
  LINE5 = 0x00000020,   ///< external interrupt line 5
  LINE6 = 0x00000040,   ///< external interrupt line 6
  LINE7 = 0x00000080,   ///< external interrupt line 7
  LINE8 = 0x00000100,   ///< external interrupt line 8
  LINE9 = 0x00000200,   ///< external interrupt line 9
  LINE10 = 0x00000400,  ///< external interrupt line 10
  LINE11 = 0x00000800,  ///< external interrupt line 11
  LINE12 = 0x00001000,  ///< external interrupt line 12
  LINE13 = 0x00002000,  ///< external interrupt line 13
  LINE14 = 0x00004000,  ///< external interrupt line 14
  LINE15 = 0x00008000,  ///< external interrupt line 15
  LINE16 = 0x00010000,  ///< external interrupt line 16 connected to the pvm output
  LINE17 = 0x00020000,  ///< external interrupt line 17 connected to the rtc alarm event
  LINE18 = 0x00040000,  ///< external interrupt line 18 connected to the otg fs wakeup from suspend event
  LINE19 = 0x00080000,  ///< external interrupt line 19 connected to the comp1
  LINE20 = 0x00100000,  ///< external interrupt line 20 connected to the comp1
  LINE21 = 0x00200000,  ///< external interrupt line 21 connected to the rtc temper and timestamp event
  LINE22 = 0x00400000   ///< external interrupt line 22 connected to the rtc wakeup event
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_DEB133D1_D421_4981_87F6_34A2047C78C4 */
