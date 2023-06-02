/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_2A0293E8_2933_45E8_A8BA_1BE822371639
#define AT32F415_2A0293E8_2933_45E8_A8BA_1BE822371639

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
  enum struct CountMode : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::CountMode : uint8_t {
  UP = 0x00,        /*!< tmr counter mode up */
  DOWN = 0x01,      /*!< tmr counter mode down */
  TWO_WAY_1 = 0x02, /*!< tmr counter mode two way 1 */
  TWO_WAY_2 = 0x04, /*!< tmr counter mode two way 2 */
  TWO_WAY_3 = 0x06  /*!< tmr counter mode two way 3 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_2A0293E8_2933_45E8_A8BA_1BE822371639 */
