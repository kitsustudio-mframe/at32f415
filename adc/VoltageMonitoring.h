/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_F2772318_31CF_4B73_83BD_A29CF25F94BA
#define AT32F415_F2772318_31CF_4B73_83BD_A29CF25F94BA

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415 {
  namespace adc {
    enum struct VoltageMonitoring : uint32_t;
  }
}  // namespace at32f415

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::VoltageMonitoring : uint32_t {
  SINGLE_ORDINARY = 0x00800200,         /**< voltage_monitoring on a single ordinary channel */
  SINGLE_PREEMPT = 0x00400200,          /**< voltage_monitoring on a single preempt channel */
  SINGLE_ORDINARY_PREEMPT = 0x00C00200, /**< voltage_monitoring on a single ordinary or preempt channel */
  ALL_ORDINARY = 0x00800000,            /**< voltage_monitoring on all ordinary channel */
  ALL_PREEMPT = 0x00400000,             /**< voltage_monitoring on all preempt channel */
  ALL_ORDINARY_PREEMPT = 0x00C00000,    /**< voltage_monitoring on all ordinary and preempt channel */
  NONE = 0x00000000                     /**< no channel guarded by the voltage_monitoring */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_F2772318_31CF_4B73_83BD_A29CF25F94BA */
