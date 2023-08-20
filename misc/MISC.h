/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_8D35ED70_755D_46B9_8B3F_46E016321712
#define CHIP_8D35ED70_755D_46B9_8B3F_46E016321712

/* ****************************************************************************************
 * Include
 */
#include "mframe.h"
#define USING_CHIP_MISC
#include "chip.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace chip::misc {
  class MISC;
}  // namespace chip::misc

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
class chip::misc::MISC : public mframe::lang::Object {
  /* **************************************************************************************
   * Variable <Public>
   */
 public:
  static const uint32_t AIRCR_VECTKEY_MASK = 0x05FA0000;

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
 public:
  MISC(void) = default;

  virtual ~MISC(void) override = default;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */
 public:
  /**
   * @brief  system reset
   * @param  none
   * @retval none
   */
  static void systemReset(void);

  /**
   * @brief  enable nvic irq
   * @param  irqn (IRQn_Type number)
   * @param  preempt_priority: preemptive priority value (starting from 0)
   * @param  sub_priority: subpriority value (starting from 0)
   * @retval none
   */
  static void irqEnable(InterruptService irqn, uint32_t preempt_priority, uint32_t sub_priority);

  /**
   * @brief  disable nvic irq number
   * @param  irqn (IRQn_Type number)
   * @retval none
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
   * @retval none
   */
  static void priorityGroupConfig(PriorityGroup priority_group);

  /**
   * @brief  set the vector table location and offset.
   * @param  base
   *         this parameter can be one of the following values:
   *         - NVIC_VECTTAB_RAM
   *         - NVIC_VECTTAB_FLASH
   * @param  offset (vector table base offset field. this value must be a multiple of 0x200)
   * @retval none
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
   * @retval none
   */
  static void lowpowerModeConfig(LowPowerMode lp_mode, bool newState);

  /**
   * @brief  config systick clock source
   * @param  source
   *         this parameter can be one of the following values:
   *         - SYSTICK_CLOCK_SOURCE_AHBCLK_DIV8
   *         - SYSTICK_CLOCK_SOURCE_AHBCLK_NODIV
   * @retval none
   */
  static void systickClockSourceConfig(SystickClockSource source);

  /**
   * @brief 設定中斷優先權
   *
   * @param irqn
   * @param priority
   */
  static void setInterruptPriority(InterruptService irqn, uint32_t priority);

  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* CHIP_8D35ED70_755D_46B9_8B3F_46E016321712 */
