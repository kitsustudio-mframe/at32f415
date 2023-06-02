/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_D2E76734_8568_4D65_951F_2DB411686FD2
#define AT32F415_D2E76734_8568_4D65_951F_2DB411686FD2

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./Line.h"
#include "./Mode.h"
#include "./Polarity.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415{
  namespace exint{
    struct Config;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::exint::Config{
  Line line;
  Mode mode;
  Polarity polarity;
  bool enable;
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_D2E76734_8568_4D65_951F_2DB411686FD2 */
