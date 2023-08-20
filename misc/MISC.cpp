/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./MISC.h"
//-----------------------------------------------------------------------------------------

#define USING_PROCESSOR_CORE
#include "chip.h"

/* ****************************************************************************************
 * Macro
 */

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using chip::misc::MISC;

/* ****************************************************************************************
 * Variable <Static>
 */

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/** ---------------------------------------------------------------------------------------
 *
 */
void MISC::systemReset(void) {
  NVIC_SystemReset();
}

/** ---------------------------------------------------------------------------------------
 *
 */
void MISC::irqEnable(InterruptService irqn, uint32_t preempt_priority, uint32_t sub_priority) {
  uint32_t temp_priority = 0;

  /* encode priority */
  temp_priority = NVIC_EncodePriority(NVIC_GetPriorityGrouping(), preempt_priority, sub_priority);
  /* set priority */
  NVIC_SetPriority(static_cast<IRQn_Type>(irqn), temp_priority);
  /* enable irqn */
  NVIC_EnableIRQ(static_cast<IRQn_Type>(irqn));
}

/** ---------------------------------------------------------------------------------------
 *
 */
void MISC::irqDisable(InterruptService irqn) {
  NVIC_DisableIRQ(static_cast<IRQn_Type>(irqn));
}

/** ---------------------------------------------------------------------------------------
 *
 */
void MISC::priorityGroupConfig(PriorityGroup priority_group) {
  /* set the prigroup[10:8] bits according to nvic_prioritygroup value */
  NVIC_SetPriorityGrouping(static_cast<uint32_t>(priority_group));
}

/** ---------------------------------------------------------------------------------------
 *
 */
void MISC::vectorTableSet(uint32_t base, uint32_t offset) {
  SCB->VTOR = base | (offset & static_cast<uint32_t>(0x1FFFFF80));
}

/** ---------------------------------------------------------------------------------------
 *
 */
void MISC::lowpowerModeConfig(LowPowerMode lp_mode, bool newState) {
  if (newState != false)
    SCB->SCR |= static_cast<uint32_t>(lp_mode);

  else
    SCB->SCR &= static_cast<uint32_t>(~static_cast<uint32_t>(lp_mode));

  return;
}

//-----------------------------------------------------------------------------------------
void MISC::systickClockSourceConfig(SystickClockSource source) {
  if (source == SystickClockSource::AHBCLK_NODIV)
    SysTick->CTRL |= static_cast<uint32_t>(SystickClockSource::AHBCLK_NODIV);

  else
    SysTick->CTRL &= ~static_cast<uint32_t>(SystickClockSource::AHBCLK_NODIV);
}

//-----------------------------------------------------------------------------------------
void MISC::setInterruptPriority(InterruptService irqn, uint32_t priority) {
  NVIC_SetPriority(static_cast<IRQn_Type>(irqn), priority);
  return;
}
/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/* ****************************************************************************************
 * Protected Method <Override>
 */

/* ****************************************************************************************
 * Protected Method
 */

/* ****************************************************************************************
 * Private Method
 */

/* ****************************************************************************************
 * End of file
 */
