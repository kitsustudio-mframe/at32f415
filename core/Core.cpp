/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./Core.h"

//-----------------------------------------------------------------------------------------
#include "chip.h"
#include "mframe.h"

/* ****************************************************************************************
 * Using
 */
using namespace chip::core;
using namespace chip::crm;

//-----------------------------------------------------------------------------------------

using chip::flash::FLASH;
using chip::flash::WaitCycle;

/* ****************************************************************************************
 * Extern
 */

/* ****************************************************************************************
 * Variable <Static>
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wexit-time-destructors"

CoreInterrupt Core::interrupt = CoreInterrupt();

CoreIomux Core::iomux = CoreIomux();

CoreGeneralPort Core::gpioa = CoreGeneralPort(chip::gpio::GPIOA);
CoreGeneralPort Core::gpiob = CoreGeneralPort(chip::gpio::GPIOB);
CoreGeneralPort Core::gpioc = CoreGeneralPort(chip::gpio::GPIOC);
CoreGeneralPort Core::gpiod = CoreGeneralPort(chip::gpio::GPIOD);
CoreGeneralPort Core::gpiof = CoreGeneralPort(chip::gpio::GPIOF);

#pragma clang diagnostic pop
/* ****************************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------------------
Core::Core(void) {
  return;
}

//-----------------------------------------------------------------------------------------
Core::~Core(void) {
  return;
}

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

//-----------------------------------------------------------------------------------------
uint32_t Core::getSystemCoreClock(void) {
  return AT32F415::systemCoreClockHz;
}

//-----------------------------------------------------------------------------------------
bool Core::setSystemCoreClock(uint32_t mhz) {
  if ((mhz > 256) || (mhz < 16))
    return false;

  if (mhz & 0x00000003)
    return false;

  /* config flash psr register */
  if (mhz <= 128)
    FLASH::psrSet(static_cast<WaitCycle>((mhz - 1) >> 5));

  else
    FLASH::psrSet(WaitCycle::WAIT_CYCLE4);

  /* reset crm */
  CRM::reset();

  /* enable hick */
  CRM::clockSourceEnable(SourceClockCore::CLOCK_HICK, true);

  /* wait till hick is ready */
  while (CRM::flagGet(Flag::HICK_STABLE) != true) {
  }

  /* config pll clock resource */
  if (mhz <= 60)
    CRM::pllConfig(SourceClockPLL::HICK, static_cast<MultPLL>((mhz >> 2) - 2));

  else
    CRM::pllConfig(SourceClockPLL::HICK, static_cast<MultPLL>((mhz >> 2) - 1));

  /* enable pll */
  CRM::clockSourceEnable(SourceClockCore::CLOCK_PLL, true);

  /* wait till pll is ready */
  while (CRM::flagGet(Flag::PLL_STABLE) != true) {
  }

  if (mhz <= 150) {
    CRM::ahbDivSet(DividerAHB::DIV1);

    if (mhz <= 75) {
      CRM::apb2DivSet(DividerAPB2::DIV1);
      CRM::apb1DivSet(DividerAPB1::DIV1);
    } else {
      CRM::apb2DivSet(DividerAPB2::DIV2);
      CRM::apb1DivSet(DividerAPB1::DIV2);
    }
  } else {
    CRM::ahbDivSet(DividerAHB::DIV2);
    CRM::apb2DivSet(DividerAPB2::DIV2);
    CRM::apb1DivSet(DividerAPB1::DIV2);
  }

  /* enable auto step mode */
  CRM::autoStepModeEnable(true);

  /* select pll as system clock source */
  CRM::sysclkSwitch(SourceClockSCLK::PLL);

  /* wait till pll is used as system clock source */
  while (CRM::sysclkSwitchStatusGet() != SourceClockSCLK::PLL) {
  }

  /* disable auto step mode */
  CRM::autoStepModeEnable(false);

  /* config usbclk from hick48 */
  CRM::usbClockSourceSelect(SourceClockUSB::HICK);

  /* update system_core_clock global variable */
  AT32F415::systemCoreClockUpdate();

  return true;
}

//-----------------------------------------------------------------------------------------
void Core::defaultSetup(void){
  Core::setSystemCoreClock(144);
  Core::iomux.init();
  Core::gpioa.init();
  Core::gpiob.init();
  Core::gpioc.init();
  Core::gpiod.init();
  Core::gpiof.init();
  Core::iomux.remapSWDIO(CoreIomux::MapSWDIO::JTAGDISABLE);
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
