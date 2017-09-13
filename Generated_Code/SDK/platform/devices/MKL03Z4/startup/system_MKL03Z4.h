/*
** ###################################################################
**     Processors:         MKL03Z4
**
**
**     Abstract:
**         Provides a system configuration function and a global variable that
**         contains the system frequency. It configures the device and initializes
**         the oscillator (PLL) that is part of the microcontroller device.
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
**
** ###################################################################
*/



/*!
 * @file MKL03Z4
 * @brief Device specific configuration file for MKL03Z4 (header file)
 *
 * Provides a system configuration function and a global variable that contains
 * the system frequency. It configures the device and initializes the oscillator
 * (PLL) that is part of the microcontroller device.
 */

#ifndef SYSTEM_MKL03Z4_H_
#define SYSTEM_MKL03Z4_H_                     /**< Symbol preventing repeated inclusion */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifndef DISABLE_WDOG
  #define DISABLE_WDOG                 1
#endif

#define ACK_ISOLATION                  0

/* Index of selected clock configuration */
#ifndef CLOCK_SETUP
  #define CLOCK_SETUP   1
#endif

/* MCG_Lite mode constants */

#define MCG_MODE_LIRC_8M               0U
#define MCG_MODE_HIRC                  1U
#define MCG_MODE_LIRC_2M               2U
#define MCG_MODE_EXT                   3U

/* Predefined clock setups
   0 ... Default part configuration
         Multipurpose Clock Generator Lite (MCG_Lite) in LIRC_8M mode.
         Reference clock source for MCG_Lite module: Low internal clock (8MHz)
         Core clock = 4MHz
         Bus clock  = 2MHz
   1 ... Maximum achievable clock frequency configuration
         Multipurpose Clock Generator Lite (MCG_Lite) in HIRC mode.
         Reference clock source for MCG_Lite module: High internal clock
         Core clock = 48MHz
         Bus clock  = 24MHz
   2 ... Chip internally clocked, ready for Very Low Power Run mode
         Multipurpose Clock Generator Lite (MCG_Lite) in LIRC_8M mode.
         Reference clock source for MCG_Lite module: Low internal clock (8MHz)
         Core clock = 4MHz
         Bus clock  = 0.8MHz
   3 ... Chip externally clocked, ready for Very Low Power Run mode
         Multipurpose Clock Generator Lite (MCG_Lite) in EXT mode.
         Reference clock source for MCG_Lite module: External
         Core clock = 0.032768MHz
         Bus clock  = 0.032768MHz
 */
 
/* Define clock source values */   
#define CPU_XTAL_CLK_HZ                32768u              /* Value of the external crystal or oscillator clock frequency in Hz */
#define CPU_INT_FAST_CLK_HZ            48000000u           /* Value of the fast internal oscillator clock frequency in Hz  */
#define CPU_INT_IRC_CLK_HZ             48000000u           /* Value of the 48M internal oscillator clock frequency in Hz  */

/* Low power mode enable */
/* SMC_PMPROT: AVLP=1,AVLLS=1 */
#define SYSTEM_SMC_PMPROT_VALUE        0x22U               /* SMC_PMPROT */

#ifdef CLOCK_SETUP  
#if (CLOCK_SETUP == 0)
  #define DEFAULT_SYSTEM_CLOCK         4000000u            /* Default System clock value */
  #define CPU_INT_SLOW_CLK_HZ          8000000u            /* Value of the slow internal oscillator clock frequency in Hz  */
  #define MCG_MODE                     MCG_MODE_LIRC_8M    /* Clock generator mode */
  /* MCG_C1: CLKS=1,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x42U               /* MCG_C1 */
  /* MCG_C2: EREFS0=1,IRCS=1 */
  #define MCG_C2_VALUE                 0x05U               /* MCG_C2 */
  /* MCG_SC: FCRDIV=0 */
  #define MCG_SC_VALUE                 0x00U               /* MCG_SC */
  /* MCG_MC: HIRCEN=0,LIRC_DIV2=0 */
  #define MCG_MC_VALUE                 0x00U               /* MCG_MC */  
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=1,OUTDIV4=1 */
  #define SYSTEM_SIM_CLKDIV1_VALUE     0x10010000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: OSC32KSEL=0,OSC32KOUT=0 */
  #define SYSTEM_SIM_SOPT1_VALUE       0x00U               /* SIM_SOPT1 */
/* SIM_SOPT2: LPUART0SRC=0,TPMSRC=3,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SYSTEM_SIM_SOPT2_VALUE       0x03000000U         /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 1)
  #define DEFAULT_SYSTEM_CLOCK         48000000u           /* Default System clock value */
  #define CPU_INT_SLOW_CLK_HZ          8000000u            /* Value of the slow internal oscillator clock frequency in Hz  */
  #define MCG_MODE                     MCG_MODE_HIRC       /* Clock generator mode */
  /* MCG_C1: CLKS=0,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x02U               /* MCG_C1 */
  /* MCG_C2: EREFS0=1,IRCS=1 */
  #define MCG_C2_VALUE                 0x05U               /* MCG_C2 */
  /* MCG_SC: FCRDIV=1 */
  #define MCG_SC_VALUE                 0x02U               /* MCG_SC */
  /* MCG_MC: HIRCEN=1,LIRC_DIV2=0 */
  #define MCG_MC_VALUE                 0x80U               /* MCG_MC */  
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=0,OUTDIV4=1 */
  #define SYSTEM_SIM_CLKDIV1_VALUE     0x00010000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: OSC32KSEL=0,OSC32KOUT=0 */
  #define SYSTEM_SIM_SOPT1_VALUE       0x00U               /* SIM_SOPT1 */
/* SIM_SOPT2: LPUART0SRC=0,TPMSRC=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SYSTEM_SIM_SOPT2_VALUE       0x00U               /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 2)
  #define DEFAULT_SYSTEM_CLOCK         4000000u            /* Default System clock value */
  #define CPU_INT_SLOW_CLK_HZ          8000000u            /* Value of the slow internal oscillator clock frequency in Hz  */
  #define MCG_MODE                     MCG_MODE_LIRC_8M    /* Clock generator mode */
  /* MCG_C1: CLKS=1,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x42U               /* MCG_C1 */
  /* MCG_C2: EREFS0=1,IRCS=1 */
  #define MCG_C2_VALUE                 0x05U               /* MCG_C2 */
  /* MCG_SC: FCRDIV=1 */
  #define MCG_SC_VALUE                 0x02U               /* MCG_SC */
  /* MCG_MC: HIRCEN=0,LIRC_DIV2=0 */
  #define MCG_MC_VALUE                 0x00U               /* MCG_MC */  
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=0,OUTDIV4=4 */
  #define SYSTEM_SIM_CLKDIV1_VALUE     0x00040000U         /* SIM_CLKDIV1 */
/* SIM_SOPT1: OSC32KSEL=0,OSC32KOUT=0 */
  #define SYSTEM_SIM_SOPT1_VALUE       0x00U               /* SIM_SOPT1 */
/* SIM_SOPT2: LPUART0SRC=0,TPMSRC=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SYSTEM_SIM_SOPT2_VALUE       0x00U               /* SIM_SOPT2 */
#elif (CLOCK_SETUP == 3)
  #define DEFAULT_SYSTEM_CLOCK         32768u              /* Default System clock value */
  #define CPU_INT_SLOW_CLK_HZ          8000000u            /* Value of the slow internal oscillator clock frequency in Hz  */
  #define MCG_MODE                     MCG_MODE_EXT        /* Clock generator mode */
  /* MCG_C1: CLKS=2,IRCLKEN=1,IREFSTEN=0 */
  #define MCG_C1_VALUE                 0x82U               /* MCG_C1 */
  /* MCG_C2: EREFS0=1,IRCS=1 */
  #define MCG_C2_VALUE                 0x05U               /* MCG_C2 */
  /* MCG_SC: FCRDIV=1 */
  #define MCG_SC_VALUE                 0x02U               /* MCG_SC */
  /* MCG_MC: HIRCEN=0,LIRC_DIV2=0 */
  #define MCG_MC_VALUE                 0x00U               /* MCG_MC */  
/* OSC_CR: ERCLKEN=1,EREFSTEN=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  #define OSC_CR_VALUE                 0x80U               /* OSC_CR */
/* SMC_PMCTRL: RUNM=0,STOPA=0,STOPM=0 */
  #define SMC_PMCTRL_VALUE             0x00U               /* SMC_PMCTRL */
/* SIM_CLKDIV1: OUTDIV1=0,OUTDIV4=0 */
  #define SYSTEM_SIM_CLKDIV1_VALUE     0x00U               /* SIM_CLKDIV1 */
/* SIM_SOPT1: OSC32KSEL=0,OSC32KOUT=0 */
  #define SYSTEM_SIM_SOPT1_VALUE       0x00U               /* SIM_SOPT1 */
/* SIM_SOPT2: LPUART0SRC=0,TPMSRC=0,CLKOUTSEL=0,RTCCLKOUTSEL=0 */
  #define SYSTEM_SIM_SOPT2_VALUE       0x00U               /* SIM_SOPT2 */
#endif
#endif  /* CLOCK_SETUP */   
/**
 * @brief System clock frequency (core clock)
 *
 * The system clock frequency supplied to the SysTick timer and the processor
 * core clock. This variable can be used by the user application to setup the
 * SysTick timer or configure other parameters. It may also be used by debugger to
 * query the frequency of the debug timer or configure the trace clock speed
 * SystemCoreClock is initialized with a correct predefined value.
 */
extern uint32_t SystemCoreClock;

/**
 * @brief Setup the microcontroller system.
 *
 * Typically this function configures the oscillator that is part of the
 * microcontroller device. For systems with variable clock speed it also updates
 * the variable SystemCoreClock. SystemInit is called from startup_device file.
 */
void SystemInit (void);

/**
 * @brief Updates the SystemCoreClock variable.
 *
 * It must be called whenever the core clock is changed during program
 * execution. SystemCoreClockUpdate() evaluates the clock register settings and calculates
 * the current core clock.
 */
void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif  /* #if !defined(SYSTEM_MKL03Z4_H_) */
        
        
        
        
        
        
