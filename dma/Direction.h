/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_45CFF4E4_5743_4798_971E_E20FE7BC1234
#define CHIP_45CFF4E4_5743_4798_971E_E20FE7BC1234

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::dma {
  enum struct Direction : uint16_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::dma::Direction : uint16_t {
  PERIPHERAL_TO_MEMORY = 0x0000,  ///< dma data transfer direction:peripheral to memory
  MEMORY_TO_PERIPHERAL = 0x0010,  ///< dma data transfer direction:memory to peripheral
  MEMORY_TO_MEMORY = 0x4000       ///< dma data transfer direction:memory to memory
};
/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_45CFF4E4_5743_4798_971E_E20FE7BC1234 */
