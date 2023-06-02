/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_EDC70A94_923D_49D6_A20D_E60F8A0E649B
#define AT32F415_EDC70A94_923D_49D6_A20D_E60F8A0E649B

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::crm {
  enum struct PostDividerPLL : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::crm::PostDividerPLL : uint8_t {
  DIV1 = 0x00,  /*!< pll post-division div1 */
  DIV2 = 0x01,  /*!< pll post-division div2 */
  DIV4 = 0x02,  /*!< pll post-division div4 */
  DIV8 = 0x03,  /*!< pll post-division div8 */
  DIV16 = 0x04, /*!< pll post-division div16 */
  DIV32 = 0x05  /*!< pll post-division div32 */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_EDC70A94_923D_49D6_A20D_E60F8A0E649B */
