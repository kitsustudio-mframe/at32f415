/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CORE_D7A70DEF_54B9_45EC_A30E_DB857A71334B
#define CORE_D7A70DEF_54B9_45EC_A30E_DB857A71334B

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */

namespace chip::core {
  enum struct OutputMode : char;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */
enum struct chip::core::OutputMode : char {
  SPEED_2M,
  SPEED_10M,
  SPEED_50M
};

/* *****************************************************************************************
 * End of file
 */

#endif /* CORE_D7A70DEF_54B9_45EC_A30E_DB857A71334B */
