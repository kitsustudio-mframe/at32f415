/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */

/* ****************************************************************************************
 * Include
 */
#include "./CRM.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Macro
 */
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wold-style-cast"
#pragma clang diagnostic ignored "-Wswitch-enum"
#pragma clang diagnostic ignored "-Wcovered-switch-default"

#define REG32(addr) *(volatile uint32_t*)(addr)

#define PERIPH_REG(periph_base, value) REG32((periph_base + (value >> 16)))
#define PERIPH_REG_BIT(value) (0x1U << (value & 0x1F))

#define CRM_REG(value) PERIPH_REG(Processor::BASE_CRM, value)
#define CRM_REG_BIT(value) PERIPH_REG_BIT(value)

/* ****************************************************************************************
 * Using
 */
using chip::crm::CRM;

//-----------------------------------------------------------------------------------------
using chip::crm::Register;

/* ****************************************************************************************
 * Variable <Static>
 */
Register& chip::crm::CRM0 = *reinterpret_cast<Register*>(chip::Processor::BASE_CRM);

/* ****************************************************************************************
 * Construct Method
 */

/* ****************************************************************************************
 * Operator Method
 */

/* ****************************************************************************************
 * Public Method <Static>
 */

/* ****************************************************************************************
 * Public Method <Override>
 */

/* ****************************************************************************************
 * Public Method
 */

/* ****************************************************************************************
 * Protected Method <Static>
 */

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::reset(void) {
  /* reset the crm clock configuration to the default reset state(for debug purpose) */
  /* set hicken bit */
  CRM0.ctrl_bit.hicken = true;

  /* wait hick stable */
  while (CRM0.ctrl_bit.hickstbl != true) {
  }

  /* hick used as system clock */
  CRM0.cfg_bit.sclksel = static_cast<uint8_t>(SourceClockSCLK::HICK);

  /* wait sclk switch status */
  while (CRM0.cfg_bit.sclksts != static_cast<uint8_t>(SourceClockSCLK::HICK)) {
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
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool CRM::flagGet(Flag flag) {
  uint32_t f = static_cast<uint32_t>(flag);
  if ((CRM_REG(f) & CRM_REG_BIT(f)) != CRM_REG_BIT(f))
    return false;

  return true;
}

/** ---------------------------------------------------------------------------------------
 *
 */
bool CRM::hextStableWait(void) {
  uint32_t stable_cnt = 0;

  while ((flagGet(Flag::HEXT_STABLE) != true) && (stable_cnt < HEXT_STARTUP_TIMEOUT)) {
    stable_cnt++;
  }

  return flagGet(Flag::HEXT_STABLE);
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::hickClockCalibrationSet(uint8_t caliValue) {
  /* enable write hick calibration */
  CRM0.misc1_bit.hickcal_key = 0x5A;

  /* write hick calibration value */
  CRM0.ctrl_bit.hickcal = caliValue;

  /* disable write hick calibration */
  CRM0.misc1_bit.hickcal_key = 0x0;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::periphClockEnable(PeriphClock value, bool newState) {
  uint32_t v = static_cast<uint32_t>(value);
  /* enable periph clock */
  if (newState)
    CRM_REG(v) |= CRM_REG_BIT(v);

  /* disable periph clock */
  else
    CRM_REG(v) &= ~(CRM_REG_BIT(v));

  return;
}
/** ---------------------------------------------------------------------------------------
 *
 */
bool CRM::getPeriphClockEnable(PeriphClock value) {
  uint32_t v = static_cast<uint32_t>(value);
  return CRM_REG(v) & CRM_REG_BIT(v);
}
/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::periphReset(PeriphReset value, bool newState) {
  uint32_t v = static_cast<uint32_t>(value);
  /* enable periph reset */
  if (newState == true)
    CRM_REG(v) |= (CRM_REG_BIT(v));

  /* disable periph reset */
  else
    CRM_REG(v) &= ~(CRM_REG_BIT(v));

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::periphSleepModeClockEnable(PeriphClockSleepMode value, bool newState) {
  uint32_t v = static_cast<uint32_t>(value);
  /* enable periph clock in sleep mode */
  if (newState == true)
    CRM_REG(v) |= (CRM_REG_BIT(v));

  /* disable perph clock in sleep mode */
  else
    CRM_REG(v) &= ~(CRM_REG_BIT(v));
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::clockSourceEnable(SourceClockCore source, bool newState) {
  switch (source) {
    case SourceClockCore::CLOCK_HICK:
      CRM0.ctrl_bit.hicken = newState;
      break;

    case SourceClockCore::CLOCK_HEXT:
      CRM0.ctrl_bit.hexten = newState;
      break;

    case SourceClockCore::CLOCK_PLL:
      CRM0.ctrl_bit.pllen = newState;
      break;

    case SourceClockCore::CLOCK_LEXT:
      CRM0.bpdc_bit.lexten = newState;
      break;

    case SourceClockCore::CLOCK_LICK:
      CRM0.ctrlsts_bit.licken = newState;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::flagClear(Flag flag) {
  switch (flag) {
    case Flag::NRST_RESET:
    case Flag::POR_RESET:
    case Flag::SW_RESET:
    case Flag::WDT_RESET:
    case Flag::WWDT_RESET:
    case Flag::LOWPOWER_RESET:
    case Flag::ALL_RESET:
      CRM0.ctrlsts_bit.rstfc = true;
      break;

    case Flag::LICK_READY_INT:
      CRM0.clkint_bit.lickstblfc = true;
      break;

    case Flag::LEXT_READY_INT:
      CRM0.clkint_bit.lextstblfc = true;
      break;

    case Flag::HICK_READY_INT:
      CRM0.clkint_bit.hickstblfc = true;
      break;

    case Flag::HEXT_READY_INT:
      CRM0.clkint_bit.hextstblfc = true;
      break;

    case Flag::PLL_READY_INT:
      CRM0.clkint_bit.pllstblfc = true;
      break;

    case Flag::CLOCK_FAILURE_INT:
      CRM0.clkint_bit.cfdfc = true;
      break;

    default:
      break;
  }
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::adcClockDivSet(DividerADC divValue) {
  uint8_t v = static_cast<uint8_t>(divValue);

  CRM0.cfg_bit.adcdiv_l = v & 0x03;
  CRM0.cfg_bit.adcdiv_h = (v >> 2) & 0x01;

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::usbClockDivSet(DividerUSB divValue) {
  uint8_t v = static_cast<uint8_t>(divValue);

  CRM0.cfg_bit.usbdiv_l = v & 0x03;
  CRM0.cfg_bit.usbdiv_h = (v >> 2) & 0x01;

  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::pllConfig(SourceClockPLL clockSource, MultPLL multValue) {
  uint32_t pllrcfreq = 0;
  ReferenceClockPLL pllfref = ReferenceClockPLL::REF_4M;

  /* config pll clock source */
  if (clockSource == SourceClockPLL::HICK) {
    CRM0.cfg_bit.pllrcs = false;
    pllrcfreq = (HICK_VALUE / 2);
  } else {
    CRM0.cfg_bit.pllrcs = true;
    if (SourceClockPLL::HEXT == clockSource) {
      pllrcfreq = HEXT_VALUE;
      CRM0.cfg_bit.pllhextdiv = false;
    } else {
      pllrcfreq = (HEXT_VALUE / 2);
      CRM0.cfg_bit.pllhextdiv = true;
    }
  }

  if ((pllrcfreq > 3900000U) && (pllrcfreq < 5000000U)) {
    pllfref = ReferenceClockPLL::REF_4M;
  } else if ((pllrcfreq > 5200000U) && (pllrcfreq < 6250000U)) {
    pllfref = ReferenceClockPLL::REF_6M;
  } else if ((pllrcfreq > 7812500U) && (pllrcfreq < 8330000U)) {
    pllfref = ReferenceClockPLL::REF_8M;
  } else if ((pllrcfreq > 8330000U) && (pllrcfreq < 12500000U)) {
    pllfref = ReferenceClockPLL::REF_12M;
  } else if ((pllrcfreq > 15625000U) && (pllrcfreq < 20830000U)) {
    pllfref = ReferenceClockPLL::REF_16M;
  } else if ((pllrcfreq > 20830000U) && (pllrcfreq < 31255000U)) {
    pllfref = ReferenceClockPLL::REF_25M;
  }

  /* config pll multiplication factor */
  CRM0.cfg_bit.pllmult_l = (static_cast<uint8_t>(multValue) & 0x0F);
  CRM0.cfg_bit.pllmult_h = ((static_cast<uint8_t>(multValue) & 0x30) >> 4);

  /* config pll fref */
  CRM0.pll_bit.pllfref = static_cast<uint8_t>(pllfref);
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::pllConfig2(SourceClockPLL clockSource, uint16_t pllNs, uint16_t pllMs, PostDividerPLL pllFr) {
  /* config pll clock source */
  if (clockSource == SourceClockPLL::HICK) {
    CRM0.cfg_bit.pllrcs = false;
  } else {
    CRM0.cfg_bit.pllrcs = true;
    if (clockSource == SourceClockPLL::HEXT) {
      CRM0.cfg_bit.pllhextdiv = false;
    } else {
      CRM0.cfg_bit.pllhextdiv = true;
    }
  }

  /* config pll multiplication factor */
  CRM0.pll_bit.pllns = pllNs;
  CRM0.pll_bit.pllms = pllMs;
  CRM0.pll_bit.pllfr = static_cast<uint8_t>(pllFr);

  CRM0.pll_bit.pllcfgen = true;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::clocksFreqGet(CoreClock& coreClock) {
  uint32_t pll_mult = 0, pll_mult_h = 0, pll_clock_source = 0, temp = 0, div_value = 0;
  uint32_t pllrcsfreq = 0, pll_ms = 0, pll_ns = 0, pll_fr = 0;
  SourceClockSCLK sclk_source;

  static const uint8_t sclk_ahb_div_table[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
  static const uint8_t ahb_apb1_div_table[8] = {0, 0, 0, 0, 1, 2, 3, 4};
  static const uint8_t ahb_apb2_div_table[8] = {0, 0, 0, 0, 1, 2, 3, 4};
  static const uint8_t adc_div_table[8] = {2, 4, 6, 8, 2, 12, 8, 16};

  /* get sclk source */
  sclk_source = sysclkSwitchStatusGet();

  switch (sclk_source) {
    case SourceClockSCLK::HICK:
      if (((CRM0.misc2_bit.hick_to_sclk) != false) && ((CRM0.misc1_bit.hickdiv) != false))
        coreClock.sclk_freq = HICK_VALUE * 6;
      else
        coreClock.sclk_freq = HICK_VALUE;
      break;
    case SourceClockSCLK::HEXT:
      coreClock.sclk_freq = HEXT_VALUE;
      break;
    case SourceClockSCLK::PLL:
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
          coreClock.sclk_freq = (HICK_VALUE >> 1) * pll_mult;
        } else {
          /* hext selected as pll clock entry */
          if (CRM0.cfg_bit.pllhextdiv != false) {
            /* hext clock divided by 2 */
            coreClock.sclk_freq = (HEXT_VALUE / 2) * pll_mult;
          } else {
            coreClock.sclk_freq = HEXT_VALUE * pll_mult;
          }
        }
      } else {
        pll_ms = CRM0.pll_bit.pllms;
        pll_ns = CRM0.pll_bit.pllns;
        pll_fr = CRM0.pll_bit.pllfr;

        if (pll_clock_source == 0x00) {
          /* hick divided by 2 selected as pll clock entry */
          pllrcsfreq = (HICK_VALUE >> 1);
        } else {
          /* hext selected as pll clock entry */
          if (CRM0.cfg_bit.pllhextdiv != false) {
            /* hext clock divided by 2 */
            pllrcsfreq = (HEXT_VALUE / 2);
          } else {
            pllrcsfreq = HEXT_VALUE;
          }
        }
        coreClock.sclk_freq = static_cast<uint32_t>((static_cast<uint64_t>(pllrcsfreq) * pll_ns) / (pll_ms * (0x1 << pll_fr)));
      }
      break;
    default:
      coreClock.sclk_freq = HICK_VALUE;
      break;
  }

  /* compute sclk, ahbclk, abp1clk apb2clk and adcclk frequencies */
  /* get ahb division */
  temp = CRM0.cfg_bit.ahbdiv;
  div_value = sclk_ahb_div_table[temp];
  /* ahbclk frequency */
  coreClock.ahb_freq = coreClock.sclk_freq >> div_value;

  /* get apb1 division */
  temp = CRM0.cfg_bit.apb1div;
  div_value = ahb_apb1_div_table[temp];
  /* apb1clk frequency */
  coreClock.apb1_freq = coreClock.ahb_freq >> div_value;

  /* get apb2 division */
  temp = CRM0.cfg_bit.apb2div;
  div_value = ahb_apb2_div_table[temp];
  /* apb2clk frequency */
  coreClock.apb2_freq = coreClock.ahb_freq >> div_value;

  /* get adc division */
  temp = CRM0.cfg_bit.adcdiv_h;
  temp = ((temp << 2) | (CRM0.cfg_bit.adcdiv_l));
  div_value = adc_div_table[temp];
  /* adcclk clock frequency */
  coreClock.adc_freq = coreClock.apb2_freq / div_value;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::clockOutSet(ClockOutSelect clkout) {
  CRM0.cfg_bit.clkout_sel = static_cast<uint8_t>(clkout) & 0x7;
  CRM0.misc1_bit.clkout_sel = (static_cast<uint8_t>(clkout) >> 3) & 0x1;
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::hickSclkFrequencySelect(HickFrequencySCLK value) {
  hickDividerSelect(DividerHICK::NODIV);
  CRM0.misc2_bit.hick_to_sclk = static_cast<uint8_t>(value);
  return;
}

/** ---------------------------------------------------------------------------------------
 *
 */
void CRM::usbClockSourceSelect(SourceClockUSB value) {
  if (value == SourceClockUSB::HICK)
    hickSclkFrequencySelect(HickFrequencySCLK::HICK_48MHZ);

  CRM0.misc2_bit.hick_to_usb = static_cast<uint8_t>(value);
  return;
}
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
