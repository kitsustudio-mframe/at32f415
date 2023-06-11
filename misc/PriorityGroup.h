/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_8F296D44_33E4_40EF_9D27_FD4130C0A1F9
#define CHIP_8F296D44_33E4_40EF_9D27_FD4130C0A1F9

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::misc {
  enum struct PriorityGroup : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::misc::PriorityGroup : uint32_t {
  GROUP0 = 0x7, /**< 0 bits for preemption priority, 4 bits for subpriority */
  GROUP1 = 0x6, /**< 1 bits for preemption priority, 3 bits for subpriority */
  GROUP2 = 0x5, /**< 2 bits for preemption priority, 2 bits for subpriority */
  GROUP3 = 0x4, /**< 3 bits for preemption priority, 1 bits for subpriority */
  GROUP4 = 0x3  /**< 4 bits for preemption priority, 0 bits for subpriority */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_8F296D44_33E4_40EF_9D27_FD4130C0A1F9 */
