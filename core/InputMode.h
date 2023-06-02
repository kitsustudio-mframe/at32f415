/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef CORE_BA1F141E_4C52_4D14_ADD3_852400BDE8F1
#define CORE_BA1F141E_4C52_4D14_ADD3_852400BDE8F1

/* ****************************************************************************************
 * Include
 */
#include "lang/package-info.h" 
#include "hal/package-info.h" 

/* ****************************************************************************************
 * Namespace
 */  

namespace at32f415::core{
  enum struct InputMode : char;
}

/* ****************************************************************************************
 * Class/Interface/Struct
 */  
enum struct at32f415::core::InputMode : char{
  OPEN,
  ANALOG,
  PULLDOWN,
  PULLUP
};

/* *****************************************************************************************
 * End of file
 */ 

#endif/* CORE_BA1F141E_4C52_4D14_ADD3_852400BDE8F1 */
