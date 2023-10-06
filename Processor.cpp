/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "Processor.h"

//-----------------------------------------------------------------------------
#include "chip_arterytek_at32f415\ProcessorCore.h"
#include "chip_arterytek_at32f415\crm\CRM.h"

/* ****************************************************************************
 * Macro
 */
#define VECT_TAB_OFFSET 0x0 /*!< vector table base offset field. this value must be a multiple of 0x200. */

/* ****************************************************************************
 * Using
 */
using chip::Processor;

//-----------------------------------------------------------------------------
using namespace chip::crm;

/* ****************************************************************************
 * Static Variable
 */
uint32_t Processor::systemCoreClock = CRM::HICK_VALUE;
uint32_t Processor::systemCoreClockHz = CRM::HICK_VALUE;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-variable-declarations"
uint32_t SystemCoreClock = CRM::HICK_VALUE;
#pragma clang diagnostic pop

/* ****************************************************************************
 * Legacy Function
 */
extern "C" void SystemInit(void) {
  chip::Processor::systemInit();
  return;
}

/* ****************************************************************************
 * Construct Method
 */

//-----------------------------------------------------------------------------
Processor::Processor(void) {
  return;
}

//-----------------------------------------------------------------------------
Processor::~Processor(void) {
  return;
}

/* ****************************************************************************
 * Operator Method
 */

//-----------------------------------------------------------------------------
void Processor::systemInit(void) {
  /* reset the crm clock configuration to the default reset state(for debug purpose) */
  /* set hicken bit */
  CRM0.ctrl_bit.hicken = true;

  /* wait hick stable */
  while (CRM0.ctrl_bit.hickstbl != true) {
  }

  /* hick used as system clock */
  CRM0.cfg_bit.sclksel = static_cast<uint8_t>(crm::SourceClockSCLK::HICK);

  /* wait sclk switch status */
  while (CRM0.cfg_bit.sclksts != static_cast<uint8_t>(crm::SourceClockSCLK::HICK)) {
  }

  /* reset cfg register, include sclk switch, ahbdiv, apb1div, apb2div, adcdiv,
     clkout pllrcs, pllhextdiv, pllmult, usbdiv and pllrange bits */
  CRM0.cfg = 0;

  /* reset pllfr, pllms, pllns and pllfref bits */
  CRM0.pll = (0x00001F10U);

  /* reset hexten, hextbyps, cfden and pllen bits */
  CRM0.ctrl &= ~(0x010D0000U);

  /* reset clkout[3], usbbufs, hickdiv, clkoutdiv */
  CRM0.misc1 = 0x00100000;

  /* disable all interrupts enable and clear pending bits  */
  CRM0.clkint = 0x009F0000;

#ifdef VECT_TAB_SRAM
  SCB->VTOR = BASE_SRAM | VECT_TAB_OFFSET; /* vector table relocation in internal sram. */
#else
  SCB->VTOR = BASE_FLASH | VECT_TAB_OFFSET; /* vector table relocation in internal flash. */
#endif
}

//-----------------------------------------------------------------------------
void Processor::systemCoreClockUpdate(void) {
  uint32_t pll_mult = 0, pll_mult_h = 0, pll_clock_source = 0, temp = 0, divValue = 0;
  uint32_t pllrcsfreq = 0, pll_ms = 0, pll_ns = 0, pll_fr = 0;
  crm::SourceClockSCLK sclk_source;

  static const uint8_t systemDivTableAHB[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};

  /* get sclk source */
  sclk_source = crm::CRM::sysclkSwitchStatusGet();

  switch (sclk_source) {
    case crm::SourceClockSCLK::HICK:
      if (((CRM0.misc2_bit.hick_to_sclk) != false) && ((CRM0.misc1_bit.hickdiv) != false))
        systemCoreClock = crm::CRM::HICK_VALUE * 6;
      else
        systemCoreClock = crm::CRM::HICK_VALUE;
      break;
    case crm::SourceClockSCLK::HEXT:
      systemCoreClock = crm::CRM::HEXT_VALUE;
      break;
    case crm::SourceClockSCLK::PLL:
      pll_clock_source = CRM0.cfg_bit.pllrcs;
      if (CRM0.pll_bit.pllcfgen == false) {
        /* get multiplication factor */
        pll_mult = CRM0.cfg_bit.pllmult_l;
        pll_mult_h = CRM0.cfg_bit.pllmult_h;
        /* process high bits */
        if ((pll_mult_h != 0U) || (pll_mult == 15U)) {
          pll_mult += ((16U * pll_mult_h) + 1U);
        } else {
          pll_mult += 2U;
        }

        if (pll_clock_source == 0x00) {
          /* hick divided by 2 selected as pll clock entry */
          systemCoreClock = (crm::CRM::HICK_VALUE >> 1) * pll_mult;
        } else {
          /* hext selected as pll clock entry */
          if (CRM0.cfg_bit.pllhextdiv != false) {
            /* hext clock divided by 2 */
            systemCoreClock = (crm::CRM::HEXT_VALUE / 2) * pll_mult;
          } else {
            systemCoreClock = crm::CRM::HEXT_VALUE * pll_mult;
          }
        }
      } else {
        pll_ms = CRM0.pll_bit.pllms;
        pll_ns = CRM0.pll_bit.pllns;
        pll_fr = CRM0.pll_bit.pllfr;

        if (pll_clock_source == 0x00) {
          /* hick divided by 2 selected as pll clock entry */
          pllrcsfreq = (crm::CRM::HICK_VALUE >> 1);
        } else {
          /* hext selected as pll clock entry */
          if (CRM0.cfg_bit.pllhextdiv != false) {
            /* hext clock divided by 2 */
            pllrcsfreq = (crm::CRM::HEXT_VALUE / 2);
          } else {
            pllrcsfreq = crm::CRM::HEXT_VALUE;
          }
        }
        systemCoreClock = (pllrcsfreq * pll_ns) / (pll_ms * (0x1 << pll_fr));
      }
      break;
    default:
      systemCoreClock = crm::CRM::HICK_VALUE;
      break;
  }

  /* compute sclk, ahbclk frequency */
  /* get ahb division */
  temp = CRM0.cfg_bit.ahbdiv;
  divValue = systemDivTableAHB[temp];
  systemCoreClockHz = systemCoreClock;
  /* ahbclk frequency */
  systemCoreClock = systemCoreClock >> divValue;
  SystemCoreClock = systemCoreClock;
}

/* ****************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************
 * Public Method
 */

/* ****************************************************************************
 * Protected Method
 */

/* ****************************************************************************
 * Private Method
 */

/* ****************************************************************************
 * End of file
 */
