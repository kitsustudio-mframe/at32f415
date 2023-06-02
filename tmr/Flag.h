/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_BBD44BB3_537B_4F2D_AC46_178E67949C57
#define AT32F415_BBD44BB3_537B_4F2D_AC46_178E67949C57

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr {
  enum struct Flag : uint32_t;

  static inline Flag operator|(Flag a, Flag b){
    return static_cast<Flag>((static_cast<uint32_t>(a) | static_cast<uint32_t>(b)));
  }

  static inline Flag operator&(const Flag a, const Flag b){
    return static_cast<Flag>((static_cast<uint32_t>(a) & static_cast<uint32_t>(b)));
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::Flag : uint32_t {
  OVF = 0x00000001,          /*!< tmr flag overflow */
  C1 = 0x00000002,           /*!< tmr flag channel 1 */
  C2 = 0x00000004,           /*!< tmr flag channel 2 */
  C3 = 0x00000008,           /*!< tmr flag channel 3 */
  C4 = 0x00000010,           /*!< tmr flag channel 4 */
  HALL = 0x00000020,         /*!< tmr flag hall */
  TRIGGER = 0x00000040,      /*!< tmr flag trigger */
  BRK = 0x00000080,          /*!< tmr flag brake */
  C1_RECAPTURE = 0x00000200, /*!< tmr flag channel 1 recapture */
  C2_RECAPTURE = 0x00000400, /*!< tmr flag channel 2 recapture */
  C3_RECAPTURE = 0x00000800, /*!< tmr flag channel 3 recapture */
  C4_RECAPTURE = 0x00001000 /*!< tmr flag channel 4 recapture */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_BBD44BB3_537B_4F2D_AC46_178E67949C57 */
