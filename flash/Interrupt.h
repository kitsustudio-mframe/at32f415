/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_CAEF0E6F_94B5_4E6C_892F_A651AF251462
#define CHIP_CAEF0E6F_94B5_4E6C_892F_A651AF251462

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::flash {
  enum struct Interrupt : uint32_t;
  enum_auto_operator(Interrupt, uint32_t)
}  // namespace chip::flash

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::flash::Interrupt : uint32_t {
  ERR = 0x00000001, /*!< flash error interrupt */
  ODF = 0x00000002  /*!< flash operate done interrupt */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_CAEF0E6F_94B5_4E6C_892F_A651AF251462 */
