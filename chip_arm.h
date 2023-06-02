/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_0E9F854C_6838_4F7E_8BC9_D4F028A63E4D
#define AT32F415_0E9F854C_6838_4F7E_8BC9_D4F028A63E4D

#ifdef __cplusplus
extern "C" {
#endif

#if defined (__CC_ARM)
 #pragma anon_unions
#endif

/**
  * @brief configuration of the cortex-m4 processor and core peripherals
  */
#define __CM4_REV                 0x0001U  /*!< core revision r0p1                           */
#define __MPU_PRESENT             1        /*!< mpu present                                  */
#define __NVIC_PRIO_BITS          4        /*!< at32 uses 4 bits for the priority levels     */
#define __Vendor_SysTickConfig    0        /*!< set to 1 if different systick config is used */
#define __FPU_PRESENT             0U       /*!< fpu present                                  */

#include "chip_irqn.h"

/**
  * @}
  */

#include "arm/core_cm4.h"
#include <stdint.h>


#ifdef __cplusplus
}
#endif

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_0E9F854C_6838_4F7E_8BC9_D4F028A63E4D */
