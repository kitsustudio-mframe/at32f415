/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_8F296D44_33E4_40EF_9D27_FD4130C0A1F9
#define AT32F415_8F296D44_33E4_40EF_9D27_FD4130C0A1F9

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::misc {
  enum struct PriorityGroup : uint32_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::misc::PriorityGroup : uint32_t {
  GROUP0 = 0x7, /**< 0 bits for preemption priority, 4 bits for subpriority */
  GROUP1 = 0x6, /**< 1 bits for preemption priority, 3 bits for subpriority */
  GROUP2 = 0x5, /**< 2 bits for preemption priority, 2 bits for subpriority */
  GROUP3 = 0x4, /**< 3 bits for preemption priority, 1 bits for subpriority */
  GROUP4 = 0x3  /**< 4 bits for preemption priority, 0 bits for subpriority */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_8F296D44_33E4_40EF_9D27_FD4130C0A1F9 */
