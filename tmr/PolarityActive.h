/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_B1B3CAC0_C245_4FE8_B8EF_738FF4EFED56
#define AT32F415_B1B3CAC0_C245_4FE8_B8EF_738FF4EFED56

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415::tmr {
  enum struct PolarityActive : uint8_t;
}

/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
enum struct at32f415::tmr::PolarityActive : uint8_t {
  HIGH = 0x00, /*!< tmr polarity active high */
  LOW = 0x01,  /*!< tmr polarity active low */
  BOTH = 0x02  /*!< tmr polarity active both high ande low */
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_B1B3CAC0_C245_4FE8_B8EF_738FF4EFED56 */
