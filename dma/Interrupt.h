/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_B1C6C190_DBFB_4931_80D1_08F46B2CFCD7
#define AT32F415_B1C6C190_DBFB_4931_80D1_08F46B2CFCD7

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::dma {
  enum struct Interrupt : uint32_t;

  enum_auto_operator(Interrupt, uint32_t)
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::dma::Interrupt : uint32_t {
  FDT = 0x00000002,   /*!< dma full data transfer interrupt */
  HDT = 0x00000004,   /*!< dma half data transfer interrupt */
  DTERR = 0x00000008 /*!< dma errorr interrupt */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_B1C6C190_DBFB_4931_80D1_08F46B2CFCD7 */
