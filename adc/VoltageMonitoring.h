/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_F2772318_31CF_4B73_83BD_A29CF25F94BA
#define CHIP_F2772318_31CF_4B73_83BD_A29CF25F94BA

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::adc {
  enum struct VoltageMonitoring : uint32_t;
}  // namespace chip::adc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct chip::adc::VoltageMonitoring : uint32_t {
  SINGLE_ORDINARY = 0x00800200,         /**< voltage_monitoring on a single ordinary channel */
  SINGLE_PREEMPT = 0x00400200,          /**< voltage_monitoring on a single preempt channel */
  SINGLE_ORDINARY_PREEMPT = 0x00C00200, /**< voltage_monitoring on a single ordinary or preempt channel */
  ALL_ORDINARY = 0x00800000,            /**< voltage_monitoring on all ordinary channel */
  ALL_PREEMPT = 0x00400000,             /**< voltage_monitoring on all preempt channel */
  ALL_ORDINARY_PREEMPT = 0x00C00000,    /**< voltage_monitoring on all ordinary and preempt channel */
  NONE = 0x00000000                     /**< no channel guarded by the voltage_monitoring */
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_F2772318_31CF_4B73_83BD_A29CF25F94BA */
