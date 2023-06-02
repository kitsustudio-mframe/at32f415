/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_58DEB161_8573_4457_9D6E_DC1A1F86B999
#define AT32F415_58DEB161_8573_4457_9D6E_DC1A1F86B999

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
    enum struct ClockLast : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::ClockLast : uint8_t{
  NONE   = 0x00, /*!< usart clock pulse of the last data bit is not outputted */
  OUTPUT = 0x01  /*!< usart clock pulse of the last data bit is outputted */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_58DEB161_8573_4457_9D6E_DC1A1F86B999 */
