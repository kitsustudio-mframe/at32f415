/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_8D35ED70_755D_46B9_8B3F_46E016321712
#define CHIP_8D35ED70_755D_46B9_8B3F_46E016321712

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415/misc/InterruptService.h"
#include "chip_arterytek_at32f415/misc/LowPowerMode.h"
#include "chip_arterytek_at32f415/misc/MISC.h"
#include "chip_arterytek_at32f415/misc/PriorityGroup.h"
#include "chip_arterytek_at32f415/misc/SystickClockSource.h"

/* ****************************************************************************
 * Namespace
 */
namespace chip::misc {
  class MISC;
}  // namespace chip::misc

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::misc::MISC : public mframe::lang::Object {
  /* **************************************************************************
   * Variable
   */
 public:
  static const uint32_t AIRCR_VECTKEY_MASK = 0x05FA0000;

  /* **************************************************************************
   * Abstract method
   */

  /* **************************************************************************
   * Construct Method
   */
 public:
  /**
   * @brief Construct a new MISC object
   *
   */
  MISC(void) = default;

  /**
   * @brief Destroy the MISC object
   *
   */
  virtual ~MISC(void) override = default;

  /* **************************************************************************
   * Operator Method
   */

  /* **************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************
   * Public Method
   */

  /* **************************************************************************
   * Protected Method
   */

  /* **************************************************************************
   * Private Method
   */

  /* **************************************************************************
   * Static Variable
   */

  /* **************************************************************************
   * Static Method
   */
 public:
  /**
   * @brief  system reset
   * @param  none
   * @return none
   */
  static void systemReset(void);

  /**
   * @brief  enable nvic irq
   * @param  irqn (IRQn_Type number)
   * @param  preempt_priority: preemptive priority value (starting from 0)
   * @param  sub_priority: subpriority value (starting from 0)
   * @return none
   */
  static void irqEnable(InterruptService irqn, uint32_t preempt_priority, uint32_t sub_priority);

  /**
   * @brief  disable nvic irq number
   * @param  irqn (IRQn_Type number)
   * @return none
   */
  static void irqDisable(InterruptService irqn);

  /**
   * @brief  config nvic priority group
   * @param  priority_group
   *         this parameter can be one of the following values:
   *         - NVIC_PRIORITY_GROUP_0
   *         - NVIC_PRIORITY_GROUP_1
   *         - NVIC_PRIORITY_GROUP_2
   *         - NVIC_PRIORITY_GROUP_3
   *         - NVIC_PRIORITY_GROUP_4
   * @return none
   */
  static void priorityGroupConfig(PriorityGroup priority_group);

  /**
   * @brief  set the vector table location and offset.
   * @param  base
   *         this parameter can be one of the following values:
   *         - NVIC_VECTTAB_RAM
   *         - NVIC_VECTTAB_FLASH
   * @param  offset (vector table base offset field. this value must be a multiple of 0x200)
   * @return none
   */
  static void vectorTableSet(uint32_t base, uint32_t offset);

  /**
   * @brief  config nvic lowpower mode
   * @param  lp_mode
   *         this parameter can be one of the following values:
   *         - NVIC_LP_SEVONPEND
   *         - NVIC_LP_SLEEPDEEP
   *         - NVIC_LP_SLEEPONEXIT
   * @param  new_state (new state of lp condition. ENABLE or DISABLE)
   * @return none
   */
  static void lowpowerModeConfig(LowPowerMode lp_mode, bool newState);

  /**
   * @brief  config systick clock source
   * @param  source
   *         this parameter can be one of the following values:
   *         - SYSTICK_CLOCK_SOURCE_AHBCLK_DIV8
   *         - SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV
   * @return none
   */
  static void systickClockSourceConfig(SystickClockSource source);

  /**
   * @brief 設定中斷優先權
   *
   * @param irqn
   * @param priority
   */
  static void setInterruptPriority(InterruptService irqn, uint32_t priority);
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_8D35ED70_755D_46B9_8B3F_46E016321712 */
