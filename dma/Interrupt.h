/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_B1C6C190_DBFB_4931_80D1_08F46B2CFCD7
#define CHIP_B1C6C190_DBFB_4931_80D1_08F46B2CFCD7

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct Interrupt : uint32_t;

  enum_auto_operator(Interrupt, uint32_t)
}  // namespace chip::dma

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::Interrupt : uint32_t {
  FDT = 0x00000002,   ///< dma full data transfer interrupt
  HDT = 0x00000004,   ///< dma half data transfer interrupt
  DTERR = 0x00000008  ///< dma errorr interrupt
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_B1C6C190_DBFB_4931_80D1_08F46B2CFCD7 */
