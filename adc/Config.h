/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_09E1DC08_5A58_4545_8FCE_09117383EA40
#define AT32F415_09E1DC08_5A58_4545_8FCE_09117383EA40

/* ****************************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "DataAlign.h"

/* ****************************************************************************************
 * Namespace
 */
namespace at32f415{
  namespace adc{
    struct Config;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */
struct at32f415::adc::Config{
  uint8_t ordinaryChannelLength;
  DataAlign dataAlign;
  bool sequenceMode;
  bool repeatMode;  
};

/* ****************************************************************************************
 * End of file
 */

#endif /* AT32F415_09E1DC08_5A58_4545_8FCE_09117383EA40 */
