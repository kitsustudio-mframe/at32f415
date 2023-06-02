/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_979E472A_3462_4CA6_8D4A_6FCA41DFC757
#define AT32F415_979E472A_3462_4CA6_8D4A_6FCA41DFC757

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
    enum struct ClockPhase : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::ClockPhase : uint8_t{
  EDGE1 = 0x00, /*!< usart data capture is done on the clock leading edge */
  EDGE2 = 0x01  /*!< usart data capture is done on the clock trailing edge */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_979E472A_3462_4CA6_8D4A_6FCA41DFC757 */
