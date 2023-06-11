/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_6B227D55_8921_4F5D_9594_8EB250CEBA4F
#define CHIP_6B227D55_8921_4F5D_9594_8EB250CEBA4F

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::tmr {
  enum struct EventTrigger : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::tmr::EventTrigger : uint32_t {
  OVERFLOW = 0x00000001, /*!< tmr event triggered by software of overflow */
  C1 = 0x00000002,       /*!< tmr event triggered by software of channel 1 */
  C2 = 0x00000004,       /*!< tmr event triggered by software of channel 2 */
  C3 = 0x00000008,       /*!< tmr event triggered by software of channel 3 */
  C4 = 0x00000010,       /*!< tmr event triggered by software of channel 4 */
  HALL = 0x00000020,     /*!< tmr event triggered by software of hall */
  TRIGGER = 0x00000040,  /*!< tmr event triggered by software of trigger */
  BRK = 0x00000080       /*!< tmr event triggered by software of brake */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_6B227D55_8921_4F5D_9594_8EB250CEBA4F */
