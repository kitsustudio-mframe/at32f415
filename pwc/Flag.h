/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_EA3E5010_99D4_4A84_8A26_3B49EE700AA7
#define CHIP_EA3E5010_99D4_4A84_8A26_3B49EE700AA7

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::pwc {
  enum struct Flag : uint32_t;
}  // namespace chip::pwc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::pwc::Flag : uint32_t {
  WAKEUP = 0x00000001,     ///< wakeup flag
  STANDBY = 0x00000002,    ///< standby flag
  PVM_OUTPUT = 0x00000004  ///< pvm output flag
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_EA3E5010_99D4_4A84_8A26_3B49EE700AA7 */
