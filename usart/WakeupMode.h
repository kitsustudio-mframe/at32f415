/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_F71EBA06_E9FF_4F0B_BBB3_96D3798CF1A0
#define AT32F415_F71EBA06_E9FF_4F0B_BBB3_96D3798CF1A0

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
    enum struct WakeupMode : uint8_t;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::usart::WakeupMode : uint8_t{
  IDLE_FRAME  = 0x00, /*!< usart wakeup by idle frame */
  MATCHING_ID = 0x01  /*!< usart wakeup by matching id */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_F71EBA06_E9FF_4F0B_BBB3_96D3798CF1A0 */
