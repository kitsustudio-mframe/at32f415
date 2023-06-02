/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_1FCECA8D_6871_4C31_9451_F47CA5ACD37A
#define AT32F415_1FCECA8D_6871_4C31_9451_F47CA5ACD37A

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::flash {
  enum struct Flag : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::flash::Flag : uint32_t {
  FLASH_OBF_FLAG = 0x00000001,     /*!< flash operate busy flag */
  FLASH_ODF_FLAG = 0x00000020,     /*!< flash operate done flag */
  FLASH_PRGMERR_FLAG = 0x00000004, /*!< flash program error flag */
  FLASH_EPPERR_FLAG = 0x00000010,  /*!< flash erase/program protection error flag */
  FLASH_USDERR_FLAG = 0x40000001  /*!< flash user system data error flag */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_1FCECA8D_6871_4C31_9451_F47CA5ACD37A */
