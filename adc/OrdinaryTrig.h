/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_2A037C27_4332_4AEC_A571_04F9B4524BD8
#define AT32F415_2A037C27_4332_4AEC_A571_04F9B4524BD8

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
    enum struct OrdinaryTrig : uint8_t;
  }
}  // namespace at32f415

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::OrdinaryTrig : uint8_t {
  TMR1CH1 = 0x00,            /**< timer1 ch1 event as trigger source of adc1 ordinary sequence */
  TMR1CH2 = 0x01,            /**< timer1 ch2 event as trigger source of adc1 ordinary sequence */
  TMR1CH3 = 0x02,            /**< timer1 ch3 event as trigger source of adc1 ordinary sequence */
  TMR2CH2 = 0x03,            /**< timer2 ch2 event as trigger source of adc1 ordinary sequence */
  TMR3TRGOUT = 0x04,         /**< timer3 trgout event as trigger source of adc1 ordinary sequence */
  TMR4CH4 = 0x05,            /**< timer4 ch4 event as trigger source of adc1 ordinary sequence */
  EXINT11_TMR1TRGOUT = 0x06, /**< exint line11/timer1 trgout event as trigger source of adc1 ordinary sequence */
  SOFTWARE = 0x07,           /**< software(OCSWTRG) control bit as trigger source of adc1 ordinary sequence */
  TMR1TRGOUT = 0x0D         /**< timer1 trgout event as trigger source of adc1 ordinary sequence */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_2A037C27_4332_4AEC_A571_04F9B4524BD8 */
