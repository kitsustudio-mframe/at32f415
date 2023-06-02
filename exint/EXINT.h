/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef AT32F415_E85F45D1_0E3D_4595_8D9F_5B9B06C81722
#define AT32F415_E85F45D1_0E3D_4595_8D9F_5B9B06C81722

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "lang/package-info.h"

//-----------------------------------------------------------------------------------------
#include "./../Chip.h"

#include "./Config.h"
#include "./Line.h"
#include "./Mode.h"
#include "./Polarity.h"
#include "./Register.h"

/* ****************************************************************************************
 * Namespace
 */  
namespace at32f415{
  namespace exint{
    class EXINT;
    extern Register& EXINT0;
  }
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class at32f415::exint::EXINT : public lang::Object{

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 
    EXINT(void);

    virtual ~EXINT(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static Inline>
   */
  public:
    /**
     * @brief  clear exint flag
     * @param  line
     */  
    static inline void flagClear(Line line){
      EXINT0.intsts = static_cast<uint32_t>(line);
    }

    /**
     * @brief  generate exint software interrupt event
     * @param  line
     * @retval none
     */
    static inline void softwareInterruptEventGenerate(Line line){
      EXINT0.swtrg |= static_cast<uint32_t>(line);
    }

    /**
     * @brief  get exint flag
     * @param  exint_line
     * @retval the new state of exint flag.
     */
    static inline bool flagGet(Line line){
      return EXINT0.intsts & static_cast<uint32_t>(line);
    }

    /**
     * @brief  enable or disable exint interrupt
     * @param  line
     * @param  newState: new state of exint interrupt.
     *         this parameter can be: TRUE or FALSE.
     */
    static inline void interruptEnable(Line line, bool newState){
      if(newState)
        EXINT0.inten |= static_cast<uint32_t>(line);
      
      else
        EXINT0.inten &= ~static_cast<uint32_t>(line);

      return;
    }

    /**
     * @brief  enable or disable exint event
     * @param  line
     * @param  newState: new state of exint event.
     *         this parameter can be: TRUE or FALSE.
     */
    static inline void eventEnable(Line line, bool newState){
      if(newState)
        EXINT0.evten |= static_cast<uint32_t>(line);
      
      else
        EXINT0.evten &= ~static_cast<uint32_t>(line);

      return; 
    }

  /* **************************************************************************************
   * Public Method <Static>
   */
  public:
    static void reset(void);
    static void defaultParaInit(Config& config);
    static void init(Config& config);




  /* **************************************************************************************
   * Public Method <Override>
   */

  /* **************************************************************************************
   * Public Method
   */

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */

};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* AT32F415_E85F45D1_0E3D_4595_8D9F_5B9B06C81722 */
