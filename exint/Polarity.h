/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_E273F0C2_78A9_4140_AF73_F9C9EA058BB1
#define AT32F415_E273F0C2_78A9_4140_AF73_F9C9EA058BB1

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::exint{
  enum struct Polarity : uint8_t;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::exint::Polarity : uint8_t{
  RISING   = 0x00, ///< external interrupt line rising trigger mode
  FALLING  = 0x01, ///< external interrupt line falling trigger mode
  BOTH     = 0x02  ///< external interrupt line both rising and falling trigger mode
};
/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_E273F0C2_78A9_4140_AF73_F9C9EA058BB1 */
