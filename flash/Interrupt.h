/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_CAEF0E6F_94B5_4E6C_892F_A651AF251462
#define AT32F415_CAEF0E6F_94B5_4E6C_892F_A651AF251462

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
  enum struct Interrupt : uint32_t;

  static inline Interrupt operator|(const Interrupt a, const Interrupt b){
    return static_cast<Interrupt>((static_cast<uint32_t>(a) | static_cast<uint32_t>(b)));
  }

  static inline Interrupt operator&(const Interrupt a, const Interrupt b){
    return static_cast<Interrupt>((static_cast<uint32_t>(a) & static_cast<uint32_t>(b)));
  }
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::flash::Interrupt : uint32_t {
  ERR = 0x00000001, /*!< flash error interrupt */
  ODF = 0x00000002 /*!< flash operate done interrupt */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_CAEF0E6F_94B5_4E6C_892F_A651AF251462 */
