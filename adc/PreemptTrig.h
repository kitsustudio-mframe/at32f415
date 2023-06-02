/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_31932346_BA0F_4C24_B965_FD4A0CEA43DB
#define AT32F415_31932346_BA0F_4C24_B965_FD4A0CEA43DB

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
    enum struct PreemptTrig : uint8_t;
  }
}  // namespace at32f415

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::adc::PreemptTrig : uint8_t {
  TMR1TRGOUT = 0x00,      /**< timer1 trgout event as trigger source of adc1 preempt sequence */
  TMR1CH4 = 0x01,         /**< timer1 ch4 event as trigger source of adc1 preempt sequence */
  TMR2TRGOUT = 0x02,      /**< timer2 trgout event as trigger source of adc1 preempt sequence */
  TMR2CH1 = 0x03,         /**< timer2 ch1 event as trigger source of adc1 preempt sequence */
  TMR3CH4 = 0x04,         /**< timer3 ch4 event as trigger source of adc1 preempt sequence */
  TMR4TRGOUT = 0x05,      /**< timer4 trgout event as trigger source of adc1 preempt sequence */
  EXINT15_TMR1CH4 = 0x06, /**< exint line15/timer1 ch4 event as trigger source of adc1 preempt sequence */
  SOFTWARE = 0x07,        /**< software(PCSWTRG) control bit as trigger source of adc1 preempt sequence */
  TMR1CH1 = 0x0D         /**< timer1 ch1 event as trigger source of adc1 preempt sequence */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_31932346_BA0F_4C24_B965_FD4A0CEA43DB */
