/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_794B5884_2258_48B2_B6D7_395FCDCB3388
#define AT32F415_794B5884_2258_48B2_B6D7_395FCDCB3388

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415{
  namespace usart{
    enum struct BreakBit : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::BreakBit : uint8_t{
  BITS10 = 0x00, /*!< usart lin mode berak frame detection 10 bits */
  BITS11 = 0x01  /*!< usart lin mode berak frame detection 11 bits */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_794B5884_2258_48B2_B6D7_395FCDCB3388 */
