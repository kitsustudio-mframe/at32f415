/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "./../chip_arm.h"
#include "./../crm/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./PWC.h"

/* ****************************************************************************************
 * Macro
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wswitch-enum"

/* ****************************************************************************************
 * Using
 */

//-----------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------
using chip::crm::CRM;
using chip::crm::PeriphReset;
using chip::pwc::PWC;
using chip::pwc::Register;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::pwc::PWC0 = *reinterpret_cast<Register*>(chip::AT32F415::BASE_PWC);

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
void PWC::reset(void) {
  CRM::periphReset(PeriphReset::RESET_PWC, true);
  CRM::periphReset(PeriphReset::RESET_PWC, false);
}

/** ---------------------------------------------------------------------------------------
 *
 */
void PWC::sleepModeEnter(SleepEnter sleepEnter) {
  SCB->SCR &= (uint32_t)~0x4;
  if (sleepEnter == SleepEnter::WFE) {
    __SEV();
    __WFE();
    __WFE();

  } else if (sleepEnter == SleepEnter::WFI) {
    __WFI();
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void PWC::deepSleepModeEnter(DeepSleepEnter deepSleepEnter) {
  SCB->SCR |= 0x04;
  if (deepSleepEnter == DeepSleepEnter::WFE) {
    __SEV();
    __WFE();
    __WFE();

  } else if (deepSleepEnter == DeepSleepEnter::WFI) {
    __WFI();
  }
  SCB->SCR &= ~static_cast<uint32_t>(0x00000004);
}

/** ---------------------------------------------------------------------------------------
 *
 */
void PWC::standbyModeEnter(void) {
  PWC0.ctrl_bit.clswef = true;
  PWC0.ctrl_bit.lpsel = true;
  SCB->SCR |= 0x04;

#if defined(__CC_ARM)
  __force_stores();
#endif
  __WFI();
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

#pragma clang diagnostic pop
/* ****************************************************************************************
 * End of file
 */
