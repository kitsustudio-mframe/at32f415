/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 *
 * SPDX-License-Identifier: MIT
 */
#ifndef CHIP_EA8F81C9_71FB_4890_AE44_662EFB67D038
#define CHIP_EA8F81C9_71FB_4890_AE44_662EFB67D038

/* ****************************************************************************
 * Include
 */

//-----------------------------------------------------------------------------
#include "mframe.h"

//-----------------------------------------------------------------------------

/* ****************************************************************************
 * Namespace
 */
namespace chip::exint {
  struct Register;
}  // namespace chip::exint

/* ****************************************************************************
 * Class/Interface/Struct/Enum
 */

/**
 * @brief 外部中斷/事件控制器(EXINT)
 * # EXINT介紹
 *
 * EXINT共計有23條中斷線EXINT_LINE[22:0]，每條中斷線均支持通過邊沿檢測觸發和軟件觸發來產生
 * 中斷或事件。EXINT可以根據軟件配置，獨立的使能或禁止中斷或事件，並採取不同的邊沿檢測方式（檢
 * 測上升沿或檢測下降沿或同時檢測上升沿和下降沿）以及觸發方式（邊沿檢測觸發或軟件觸發或邊沿檢測
 * 和軟件同時觸發）響應觸發源獨立的產生中斷或事件。
 *
 *
 * #### EXINT 控制器的主要特性
 * - 中斷線0~15所映射的IO可以獨立的配置
 * - 每個中斷線都有獨立的觸發方式選擇
 * - 每個中斷都有獨立的使能位
 * - 每個事件都有獨立的使能位
 * - 共23個可獨立產生和清除的軟件觸發
 * - 每個中斷都有獨立的狀態位
 * - 每個中斷都可以被獨立的清除
 *
 * ---
 *
 * # 功能描述和配置流程
 * EXINT共計有23條中斷線EXINT_LINE[19:0]，可以通過邊沿檢測的方式分別檢測來自GPIO的外部中
 * 斷源以及包括PVM輸出，ERTC鬧鐘事件，OTGFS喚醒事件，CMP1喚醒事件，CMP2喚醒事件，ERTC
 * 入侵和時間戳事件以及ERTC喚醒事件共七種芯片內部的中斷源，其中來自GPIO的中斷源可以通過軟
 * 件編程配置IOMUX中的複用外部中斷配置寄存器x（IOMUX_EXINTCx）靈活的選擇，需要注意的是這
 * 些輸入源是互斥的，例如EXINT_LINE0只能選擇PA0/PB0/PC0/PD0...中的某一個，而不能同時選擇PA0
 * 和PB0作為輸入源。
 *
 * EXINT支持多種邊沿檢測方式，每條中斷線可以通過軟件編程配置極性配置寄存器1（EXINT_POLCFG1）
 * 和極性配置寄存器2（EXINT_POLCFG2）獨立的選擇上升沿檢測或下降沿檢測或同時進行上升沿和下降
 * 沿檢測，中斷線上檢測到的有效邊沿觸發可以用於產生事件或中斷。
 *
 * EXINT支持獨立的軟件觸發產生中斷或事件，即除了來自中斷線上的有效邊沿外，用戶可以通過軟件編
 * 程配置軟件觸發寄存器（EXINT_SWTRG）對應位來產生對應的中斷或事件。
 *
 * EXINT具備獨立的中斷和事件使能位，用戶可以通過軟件編程配置中斷使能寄存器（EXINT_INTEN）和
 * 事件使能寄存器（EXINT_EVTEN）來使能或關閉對應的中斷或事件，這意味著無論是通過邊沿檢測還是
 * 軟件觸發產生中斷或事件，都需要提前使能對應的中斷或事件。
 *
 * EXINT具備獨立的中斷狀態位，用戶可以通過中斷狀態寄存器（EXINT_INTSTS）讀取對應的中斷狀態
 * 並通過對該寄存器相應位寫1來清除已置位的狀態標誌。
 *
 * #### 中斷初始化流程
 *  - 選擇中斷源，即配置復用外部中斷配置寄存器x（IOMUX_EXINTCx）(如果需要使用
 * GPIO作為中斷源需要該步驟)
 *
 *  - 選擇觸發方式，即配置極性配置寄存器1（EXINT_POLCFG1）和極性配置寄存器2
 * （EXINT_POLCFG2）
 *
 *  - 使能中斷或事件，即配置中斷使能寄存器（EXINT_INTEN）和事件使能寄存器
 * （EXINT_EVTEN）
 *
 *  - 產生軟件觸發，即配置軟件觸發寄存器（EXINT_SWTRG）產生軟件觸發（此步驟僅
 * 適用於需軟件觸發產生中斷的應用）
 *
 * #### 中斷清除流程
 *  - 清除標誌，即對中斷狀態寄存器（EXINT_INTSTS）對應位寫1來清除已產生的中
 * 斷，同時該操作會同步清除軟件觸發寄存器（EXINT_SWTRG）中的對應位。
 */
struct chip::exint::Register {
  union {
    /**
     * @brief 中斷使能寄存器 (EXINT_INTEN), offset:0x00
     *
     * 偏移位置：0x00
     * 復位值：0x0000 0000
     */
    volatile uint32_t inten;

    /**
     * @brief 中斷使能寄存器 位元訪問模式
     *
     * 線x上的中斷使能/禁止位
     *
     * - 0：禁止中斷請求；
     * - 1：使能中斷請求。
     */
    struct {
      /**
       * @brief 線x上的中斷使能/禁止位 (Interrupt enable or disable on line x) [22:0] <RW>
       *
       * - 0：禁止中斷請求；
       * - 1：使能中斷請求。
       */
      volatile uint32_t intenx : 23;

      /**
       * @brief 保留位 [31:23] <RESD>
       *
       */
      volatile uint32_t reserved1 : 9;
    } inten_bit;
  };

  union {
    /**
     * @brief 事件使能寄存器 (EXINT_EVTEN), offset:0x04
     *
     * 線x上的事件使能/禁止位
     *
     * - 0：禁止事件請求；
     * - 1：使能事件請求。
     *
     * 偏移位置：0x04
     *
     * 復位值：0x0000 0000
     */
    volatile uint32_t evten;

    /**
     * @brief 事件使能寄存器 位元訪問模式
     *
     */
    struct {
      /**
       * @brief 線x上的事件使能/禁止位 (Event enable or disable on line x)
       *
       * - 0：禁止事件請求；
       * - 1：使能事件請求。
       */
      volatile uint32_t evtenx : 23; /* [22:0] */

      /**
       * @brief 保留位 [31:23] <RESD>
       *
       */
      volatile uint32_t reserved1 : 9;

    } evten_bit;
  };

  union {
    /**
     * @brief 極性配置寄存器1 (EXINT_POLCFG1), offset:0x08
     *
     * 這些位用於選擇線x由上升沿觸發中斷和事件。
     * - 0：禁止上升沿觸發；
     * - 1：使能上升沿觸發。
     *
     * 偏移位置：0x08
     * 復位值：0x0000 0000
     */
    volatile uint32_t polcfg1;

    /**
     * @brief 極性配置寄存器1 位元訪問模式
     *
     */
    struct {
      /**
       * @brief 線x上的上升沿觸發事件配置位 (Rising polarity configuration bit of line x) [22:0] <RW>
       *
       * 這些位用於選擇線x由上升沿觸發中斷和事件。
       * - 0：禁止上升沿觸發；
       * - 1：使能上升沿觸發。
       */
      volatile uint32_t rpx : 23;

      /**
       * @brief 保留位 [31:23] <RESD>
       *
       */
      volatile uint32_t reserved1 : 9;
    } polcfg1_bit;
  };

  union {
    /**
     * @brief 極性配置寄存器1 (EXINT_POLCFG2), offset:0x0C
     *
     * 這些位用於選擇線x由下降沿觸發中斷和事件。
     *
     * - 0：禁止下降沿觸發；
     * - 1：允許下降沿觸發。
     *
     * 偏移位置：0x0C
     * 復位值：0x0000 0000
     */
    volatile uint32_t polcfg2;

    /**
     * @brief 極性配置寄存器1 位元訪問模式
     *
     */
    struct {
      /**
       * @brief 線x上的下降沿觸發事件配置位 (Falling polarity event configuration bit of line x) [22:0] <RW>
       *
       * 這些位用於選擇線x由下降沿觸發中斷和事件。
       *
       * - 0：禁止下降沿觸發；
       * - 1：允許下降沿觸發。
       */
      volatile uint32_t fpx : 23;

      /**
       * @brief 保留位 [31:23] <RESD>
       *
       */
      volatile uint32_t reserved1 : 9;
    } polcfg2_bit;
  };

  union {
    /**
     * @brief 軟件觸發寄存器 (EXINT_SWTRG), offset:0x10
     *
     * 當中斷使能寄存器（EXINT_INTEN）中的對應位為 1，
     * 則軟件寫此位硬件將自動置起中斷狀態寄存器(EXINT_INTSTS)中的對應位並產生中斷。
     *
     * 當事件使能寄存器（EXINT_EVTEN）中的對應位為 1，
     * 則軟件寫此位硬件將自動產生對應中斷線上的的事件。
     *
     * - 0：默認值；
     * - 1：產生軟件觸發。
     *
     * 注：通過清除中斷狀態寄存器(EXINT_INTSTS)的對應位(寫入1)，可以清除該位為 0。
     *
     * 偏移位置：0x10
     * 復位值：0x0000 0000
     */
    volatile uint32_t swtrg;

    /**
     * @brief 軟件觸發寄存器 位元訪問模式
     *
     */
    struct {
      /**
       * @brief 軟件觸發線 x (Software triggle on line x) [22:0] <RW>
       *
       * 當中斷使能寄存器（EXINT_INTEN）中的對應位為 1，
       * 則軟件寫此位硬件將自動置起中斷狀態寄存器(EXINT_INTSTS)中的對應位並產生中斷。
       *
       * 當事件使能寄存器（EXINT_EVTEN）中的對應位為 1，
       * 則軟件寫此位硬件將自動產生對應中斷線上的的事件。
       *
       * - 0：默認值；
       * - 1：產生軟件觸發。
       *
       * 注：通過清除中斷狀態寄存器(EXINT_INTSTS)的對應位(寫入1)，可以清除該位為 0。
       */
      volatile uint32_t swtx : 23;

      /**
       * @brief 保留位 [31:23] <RESD>
       *
       */
      volatile uint32_t reserved1 : 9;
    } swtrg_bit;
  };

  union {
    /**
     * @brief 中斷狀態寄存器 (EXINT_INTSTS), offset:0x14
     *
     * 線x狀態位 (Line x state bit)
     *
     * - 0：沒有發生中斷；
     * - 1：發生了中斷。
     *
     * 注：在該位中寫入’1’可以清除它。
     *
     * 偏移位置：0x14
     * 復位值：0x0000 0000
     */
    volatile uint32_t intsts;

    /**
     * @brief 中斷狀態寄存器 位元訪問模式
     *
     */
    struct {
      /**
       * @brief 線x狀態位 (Line x state bit) [22:0] <RW>
       *
       * - 0：沒有發生中斷；
       * - 1：發生了中斷。
       *
       * 注：在該位中寫入’1’可以清除它。
       */
      volatile uint32_t linex : 23;

      /**
       * @brief 保留位 [31:23] <RESD>
       *
       */
      volatile uint32_t reserved1 : 9;
    } intsts_bit;
  };
};

/* ****************************************************************************
 * End of file
 */

#endif /* CHIP_EA8F81C9_71FB_4890_AE44_662EFB67D038 */
