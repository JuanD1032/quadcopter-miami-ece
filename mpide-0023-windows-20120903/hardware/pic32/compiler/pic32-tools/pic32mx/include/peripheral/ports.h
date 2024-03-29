/******************************************************************************
 *
 *                  IO PORT Library definitions
 *
 ******************************************************************************
 * FileName:        ports.h
 * Dependencies:
 * Processor:       PIC32 family
 *
 * Complier:        MPLAB C32
 *                  MPLAB IDE
 * Company:         Microchip Technology Inc..
 *
 * Software License Agreement
 *
 * The software supplied herewith by Microchip Technology Incorporated
 * (the �Company�) for its PIC32 Microcontroller is intended
 * and supplied to you, the Company�s customer, for use solely and
 * exclusively on Microchip PIC32 Microcontroller products.
 * The software is owned by the Company and/or its supplier, and is
 * protected under applicable copyright laws. All rights are reserved.
 * Any use in violation of the foregoing restrictions may subject the
 * user to criminal sanctions under applicable laws, as well as to
 * civil liability for the breach of the terms and conditions of this
 * license.
 *
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *
 * $Id: ports.h,v 1.3 2006/11/10 16:22:47 C11842 Exp $
 *
 * $Name:  $
 *
 *****************************************************************************/

#ifndef _PORTS_H_
#define _PORTS_H_

#include <p32xxxx.h>
#include <peripheral/int.h>
#include <peripheral/SPI_Port_Mappings.h>
#include <peripheral/Ethernet_Port_Mappings.h>

/******************************************************************************
 * Parameter values to be used with ConfigINTx() & SetPriorityINTx()
 *****************************************************************************/
// Interrupt enable/disable values
#define EXT_INT_ENABLE          (1 << 15)
#define EXT_INT_DISABLE         (0)         /* Default */

// Interrupt edge modes - must be any one value only
#define RISING_EDGE_INT         (1 << 3)
#define FALLING_EDGE_INT        (0)         /* Default */

// Priority values - must be any one value only
#define EXT_INT_PRI_7         (7) //Priority 7
#define EXT_INT_PRI_6         (6) //Priority 6
#define EXT_INT_PRI_5         (5) //Priority 5
#define EXT_INT_PRI_4         (4) //Priority 4
#define EXT_INT_PRI_3         (3) //Priority 3
#define EXT_INT_PRI_2         (2) //Priority 2
#define EXT_INT_PRI_1         (1) //Priority 1
#define EXT_INT_PRI_0         (0) //Priority Default

/******************************************************************************
 * <combinewith ConfigINT1, ConfigINT2, ConfigINT3, ConfigINT4>
 *
 * External INTx Control Function
 *
 * Function:        void ConfigINTx(unsigned int config)
 *
 * Description:     This macro configures an external interrupt as follows:
 *                  1. clears the INTx interrupt flag
 *                  2. sets the INTx priority
 *                  3. sets the INTx edge selection (rising or falling)
 *                  4. enables the INTx interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          config: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         ConfigINT0(EXT_INT_PRI_1 | RISING_EDGE_INT | EXT_INT_ENABLE)
 *
 *****************************************************************************/
#define ConfigINT0(config)  (mINT0ClearIntFlag(), mINT0SetIntPriority((config) & 7),\
        mINT0SetEdgeMode(((config) >> 3) & 1), mINT0IntEnable((config) >> 15))

#define ConfigINT1(config)  (mINT1ClearIntFlag(), mINT1SetIntPriority((config) & 7),\
        mINT1SetEdgeMode(((config) >> 3) & 1), mINT1IntEnable((config) >> 15))

#define ConfigINT2(config)  (mINT2ClearIntFlag(), mINT2SetIntPriority((config) & 7),\
        mINT2SetEdgeMode(((config) >> 3) & 1), mINT2IntEnable((config) >> 15))

#define ConfigINT3(config)  (mINT3ClearIntFlag(), mINT3SetIntPriority((config) & 7),\
        mINT3SetEdgeMode(((config) >> 3) & 1), mINT3IntEnable((config) >> 15))

#define ConfigINT4(config)  (mINT4ClearIntFlag(), mINT4SetIntPriority((config) & 7),\
        mINT4SetEdgeMode(((config) >> 3) & 1), mINT4IntEnable((config) >> 15))


/******************************************************************************
 * <combinewith SetPriorityInt1, SetPriorityInt2, SetPriorityInt3, SetPriorityInt4,
 * SetPriorityINT0, SetPriorityINT1, SetPriorityINT2, SetPriorityINT3, SetPriorityINT4>
 *
 * External INTx Control Function
 *
 * Function:        void SetPriorityINTx(unsigned int priority)
 *
 * Description:     This macro sets the priority for an External interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          priority: A Priority value
 *
 * Output:          None
 *
 * Example:         SetPriorityInt0(EXT_INT_PRI_5)
 *
 *****************************************************************************/
#define SetPriorityInt0             SetPriorityINT0
#define SetPriorityInt1             SetPriorityINT1
#define SetPriorityInt2             SetPriorityINT2
#define SetPriorityInt3             SetPriorityINT3
#define SetPriorityInt4             SetPriorityINT4

#define SetPriorityINT0(priority)   (mINT0SetIntPriority(priority))
#define SetPriorityINT1(priority)   (mINT1SetIntPriority(priority))
#define SetPriorityINT2(priority)   (mINT2SetIntPriority(priority))
#define SetPriorityINT3(priority)   (mINT3SetIntPriority(priority))
#define SetPriorityINT4(priority)   (mINT4SetIntPriority(priority))


/******************************************************************************
 * Sub-priority values to be used with SetSubPriorityIntx
 *****************************************************************************/
#define EXT_INT_SUB_PRI_3           (3 << 4) //sub priority 3
#define EXT_INT_SUB_PRI_2           (2 << 4) //sub priority 2
#define EXT_INT_SUB_PRI_1           (1 << 4) //sub priority 1
#define EXT_INT_SUB_PRI_0           (0 << 4) //sub priority default

/******************************************************************************
 * <combinewith SetSubPriorityINT1, SetSubPriorityINT2, SetSubPriorityINT3, SetSubPriorityINT4>
 *
 * External INTx Control Function
 *
 * Function:        void SetSubPriorityINTx(unsigned int subPriority)
 *
 * Description:     This macro sets the sub-priority for an External interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          A Sub-priority value
 *
 * Output:          None
 *
 * Example:         SetSubPriorityInt0(EXT_INT_SUB_PRI_2)
 *
 *****************************************************************************/
#define SetSubPriorityINT0(subpriority) (mINT0SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT1(subpriority) (mINT1SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT2(subpriority) (mINT2SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT3(subpriority) (mINT3SetIntSubPriority((subpriority) >> 4))
#define SetSubPriorityINT4(subpriority) (mINT4SetIntSubPriority((subpriority) >> 4))


/******************************************************************************
 * <combinewith CloseINT1, CloseINT2, CloseINT3, CloseINT4>
 *
 * External INTx Control Function
 *
 * Function:        void CloseINTx(void)
 *
 * Description:     This macro disables the external interrupt and clears corresponding flag.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         CloseINT0()
 *
 *****************************************************************************/
#define CloseINT0()                 (mINT0IntEnable(0), mINT0ClearIntFlag())
#define CloseINT1()                 (mINT1IntEnable(0), mINT1ClearIntFlag())
#define CloseINT2()                 (mINT2IntEnable(0), mINT2ClearIntFlag())
#define CloseINT3()                 (mINT3IntEnable(0), mINT3ClearIntFlag())
#define CloseINT4()                 (mINT4IntEnable(0), mINT4ClearIntFlag())

/******************************************************************************
 * <combinewith EnableINT1, EnableINT2, EnableINT3, EnableINT4>
 *
 * External INTx Control Function
 *
 * Function:        void EnableINTx(void)
 *
 * Description:     This macro enables an external interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableINT4()
 *
 *****************************************************************************/
#define EnableINT0              (mINT0IntEnable(1))
#define EnableINT1              (mINT1IntEnable(1))
#define EnableINT2              (mINT2IntEnable(1))
#define EnableINT3              (mINT3IntEnable(1))
#define EnableINT4              (mINT4IntEnable(1))

/******************************************************************************
 * <combinewith DisableINT1, DisableINT2, DisableINT3, DisableINT4>
 *
 * External INTx Control Function
 *
 * Function:        void DisableINTx(void)
 *
 * Description:     This macro disables an external interrupt.
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableINT0()
 *
 *****************************************************************************/
#define DisableINT0             (mINT0IntEnable(0))
#define DisableINT1             (mINT1IntEnable(0))
#define DisableINT2             (mINT2IntEnable(0))
#define DisableINT3             (mINT3IntEnable(0))
#define DisableINT4             (mINT4IntEnable(0))


/******************************************************************************
 * Parameter values to be used with ConfigINTCN()
 *****************************************************************************/
// Change Interrupt ON/OFF values.
#define CHANGE_INT_ON               (1 << 23)
#define CHANGE_INT_OFF              (0)             /* Default */

// Change Interrupt Priority Values
#define CHANGE_INT_PRI_7            (7) //Priority 7
#define CHANGE_INT_PRI_6            (6) //Priority 6
#define CHANGE_INT_PRI_5            (5) //Priority 5
#define CHANGE_INT_PRI_4            (4) //Priority 4
#define CHANGE_INT_PRI_3            (3) //Priority 3
#define CHANGE_INT_PRI_2            (2) //Priority 2
#define CHANGE_INT_PRI_1            (1) //Priority 1
#define CHANGE_INT_PRI_0            (0) //Priority default

/******************************************************************************
 * Change Notice Interrupt Control Function
 *
 * Function:        void ConfigIntCN(unsigned int config)
 *
 * Description:     This macro configures Change Notice interrupts as follows
 *                  1. clears CN interrupt flag
 *                  2. sets CN interrupt priority
 *                  3. enables CN interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CHANGE_INT_PRIx and
 *                  CHANGE_INT_XXX sets
 *
 * Output:          None
 *
 * Example:         ConfigIntCN(CHANGE_INT_PRI_3 |
 *                                CHANGE_INT_ON)
 *
 *****************************************************************************/
 #if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
 #define ConfigIntCNA(config) (mCNAClearIntFlag(), mCNSetIntPriority(((config) & 7)),\
        mCNAIntEnable(((config) >> 23)))
#define ConfigIntCNB(config) (mCNBClearIntFlag(), mCNSetIntPriority(((config) & 7)),\
        mCNBIntEnable(((config) >> 23)))
#define ConfigIntCNC(config) (mCNCClearIntFlag(), mCNSetIntPriority(((config) & 7)),\
        mCNCIntEnable(((config) >> 23)))
#else
#define ConfigIntCN(config) (mCNClearIntFlag(), mCNSetIntPriority(((config) & 7)),\
        mCNIntEnable(((config) >> 23)))
#endif

/******************************************************************************
 * <combinewith CN0_PULLUP_ENABLE, CN1_PULLUP_ENABLE, CN2_PULLUP_ENABLE, CN3_PULLUP_ENABLE,
 *  CN4_PULLUP_ENABLE, CN5_PULLUP_ENABLE, CN6_PULLUP_ENABLE, CN7_PULLUP_ENABLE, CN8_PULLUP_ENABLE,
 *  CN9_PULLUP_ENABLE, CN10_PULLUP_ENABLE, CN11_PULLUP_ENABLE, CN12_PULLUP_ENABLE, CN13_PULLUP_ENABLE,
 *  CN14_PULLUP_ENABLE, CN15_PULLUP_ENABLE, CN16_PULLUP_ENABLE, CN17_PULLUP_ENABLE, CN18_PULLUP_ENABLE,
 *  CN19_PULLUP_ENABLE, CN20_PULLUP_ENABLE, CN_PULLUP_DISABLE_ALL>
 *
 * Parameter values to be used with ConfigCNPullups()
 *****************************************************************************/
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#define CNA10_PULLUP_ENABLE                 (1 << _CNPUA_CNPUA10_POSITION)
#define CNA9_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA9_POSITION)
#define CNA8_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA8_POSITION)
#define CNA7_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA7_POSITION)
#define CNA4_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA4_POSITION)
#define CNA3_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA3_POSITION)
#define CNA2_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA2_POSITION)
#define CNA1_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA1_POSITION)
#define CNA0_PULLUP_ENABLE                  (1 << _CNPUA_CNPUA0_POSITION)
#define CNA_PULLUP_DISABLE_ALL       		(0)             /* Default */

#define CNB15_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB15_POSITION)
#define CNB14_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB14_POSITION)
#define CNB13_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB13_POSITION)
#define CNB12_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB12_POSITION) 
#define CNB11_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB11_POSITION) 
#define CNB10_PULLUP_ENABLE                 (1 << _CNPUB_CNPUB10_POSITION)
#define CNB9_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB9_POSITION)
#define CNB8_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB8_POSITION)
#define CNB7_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB7_POSITION)
#define CNB6_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB6_POSITION)
#define CNB5_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB5_POSITION)
#define CNB4_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB4_POSITION)
#define CNB3_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB3_POSITION)
#define CNB2_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB2_POSITION)
#define CNB1_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB1_POSITION)
#define CNB0_PULLUP_ENABLE                  (1 << _CNPUB_CNPUB0_POSITION)
#define CNB_PULLUP_DISABLE_ALL       		(0)             /* Default */

#define CNC9_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC9_POSITION)
#define CNC8_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC8_POSITION)
#define CNC7_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC7_POSITION)
#define CNC6_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC6_POSITION)
#define CNC5_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC5_POSITION)
#define CNC4_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC4_POSITION)
#define CNC3_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC3_POSITION)
#define CNC2_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC2_POSITION)
#define CNC1_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC1_POSITION)
#define CNC0_PULLUP_ENABLE                  (1 << _CNPUC_CNPUC0_POSITION) 
#define CNC_PULLUP_DISABLE_ALL       		(0)             /* Default */

#else 
#define CN21_PULLUP_ENABLE          (1 << _CNPUE_CNPUE21_POSITION)
#define CN20_PULLUP_ENABLE          (1 << _CNPUE_CNPUE20_POSITION)
#define CN19_PULLUP_ENABLE          (1 << _CNPUE_CNPUE19_POSITION)
#define CN18_PULLUP_ENABLE          (1 << _CNPUE_CNPUE18_POSITION)
#define CN17_PULLUP_ENABLE          (1 << _CNPUE_CNPUE17_POSITION)
#define CN16_PULLUP_ENABLE          (1 << _CNPUE_CNPUE16_POSITION)
#define CN15_PULLUP_ENABLE          (1 << _CNPUE_CNPUE15_POSITION)
#define CN14_PULLUP_ENABLE          (1 << _CNPUE_CNPUE14_POSITION)
#define CN13_PULLUP_ENABLE          (1 << _CNPUE_CNPUE13_POSITION)
#define CN12_PULLUP_ENABLE          (1 << _CNPUE_CNPUE12_POSITION)
#define CN11_PULLUP_ENABLE          (1 << _CNPUE_CNPUE11_POSITION)
#define CN10_PULLUP_ENABLE          (1 << _CNPUE_CNPUE10_POSITION)
#define CN9_PULLUP_ENABLE           (1 << _CNPUE_CNPUE9_POSITION)
#define CN8_PULLUP_ENABLE           (1 << _CNPUE_CNPUE8_POSITION)
#define CN7_PULLUP_ENABLE           (1 << _CNPUE_CNPUE7_POSITION)
#define CN6_PULLUP_ENABLE           (1 << _CNPUE_CNPUE6_POSITION)
#define CN5_PULLUP_ENABLE           (1 << _CNPUE_CNPUE5_POSITION)
#define CN4_PULLUP_ENABLE           (1 << _CNPUE_CNPUE4_POSITION)
#define CN3_PULLUP_ENABLE           (1 << _CNPUE_CNPUE3_POSITION)
#define CN2_PULLUP_ENABLE           (1 << _CNPUE_CNPUE2_POSITION)
#define CN1_PULLUP_ENABLE           (1 << _CNPUE_CNPUE1_POSITION)
#define CN0_PULLUP_ENABLE           (1 << _CNPUE_CNPUE0_POSITION)
#define CN_PULLUP_DISABLE_ALL       (0)             /* Default */

#endif
/******************************************************************************
 * Change Notice Pullup Enable Control Function
 *
 * Function:        void ConfigCNPullups(unsigned int config)
 *
 * Description:     Configures Change Notice pull-ups
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CNx_PULLUP_ENABLE sets
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         To enable CN0 & CN1 pullups and disable all others
 *                  ConfigCNPullups(CN0_PULLUP_ENABLE | CN1_PULLUP_ENABLE)
 *
 *****************************************************************************/
 #if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#define ConfigCNAPullups(config)     CNPUA = config
#define ConfigCNBPullups(config)     CNPUB = config
#define ConfigCNCPullups(config)     CNPUC = config
#else
#define ConfigCNPullups(config)     CNPUE = config
#endif
/******************************************************************************
 * Parameter values to be used with mCNOpen()
 *****************************************************************************/
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#define CNA_ON                           (1 << _CNCONA_ON_POSITION)     /* CN ON */
#define CNA_OFF                          (0)  /* CN OFF */

#define CNA_FRZ_ON                       (1 << _CNCONA_FRZ_POSITION)    /* Freeze timer on debug halt */
#define CNA_FRZ_OFF                      (0) //Freeze off

#define CNA_IDLE_CON                     (1 << _CNCONA_SIDL_POSITION)     /* operate during idle */
#define CNA_IDLE_STOP                    (0) // stop during idle

#define CNB_ON                           (1 << _CNCONB_ON_POSITION)     /* CN ON */
#define CNB_OFF                          (0)  /* CN OFF */

#define CNB_FRZ_ON                       (1 << _CNCONB_FRZ_POSITION)    /* Freeze timer on debug halt */
#define CNB_FRZ_OFF                      (0) //Freeze off

#define CNB_IDLE_CON                     (1 << _CNCONB_SIDL_POSITION)     /* operate during idle */
#define CNB_IDLE_STOP                    (0) // stop during idle

#define CNC_ON                           (1 << _CNCONC_ON_POSITION)     /* CN ON */
#define CNC_OFF                          (0)  /* CN OFF */

#define CNC_FRZ_ON                       (1 << _CNCONC_FRZ_POSITION)    /* Freeze timer on debug halt */
#define CNC_FRZ_OFF                      (0) //Freeze off

#define CNC_IDLE_CON                     (1 << _CNCONC_SIDL_POSITION)     /* operate during idle */
#define CNC_IDLE_STOP                    (0) // stop during idle
#else

#define CN_ON                           (1 << _CNCON_ON_POSITION)     /* CN ON */
#define CN_OFF                          (0)  /* CN OFF */

#define CN_FRZ_ON                       (1 << _CNCON_FRZ_POSITION)    /* Freeze timer on debug halt */
#define CN_FRZ_OFF                      (0) //Freeze off

#define CN_IDLE_CON                     (1 << _CNCON_SIDL_POSITION)     /* operate during idle */
#define CN_IDLE_STOP                    (0) // stop during idle
#endif

/******************************************************************
 * <combinewith CN0_ENABLE, CN1_ENABLE, CN2_ENABLE, CN3_ENABLE,
 * CN4_ENABLE, CN5_ENABLE, CN6_ENABLE, CN7_ENABLE, CN8_ENABLE,
 * CN9_ENABLE, CN10_ENABLE, CN11_ENABLE, CN12_ENABLE, CN13_ENABLE,
 * CN14_ENABLE, CN15_ENABLE, CN16_ENABLE, CN17_ENABLE, CN18_ENABLE,
 * CN19_ENABLE, CN20_ENABLE, CN_DISABLE_ALL>
 *
 * Change notice enable flags
 *******************************************************************/
 #if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))

#define CNA10_ENABLE                 (1 << _CNENA_CNIEA10_POSITION)
#define CNA9_ENABLE                  (1 << _CNENA_CNIEA9_POSITION)
#define CNA8_ENABLE                  (1 << _CNENA_CNIEA8_POSITION)
#define CNA7_ENABLE                  (1 << _CNENA_CNIEA7_POSITION)
#define CNA4_ENABLE                  (1 << _CNENA_CNIEA4_POSITION)
#define CNA3_ENABLE                  (1 << _CNENA_CNIEA3_POSITION)
#define CNA2_ENABLE                  (1 << _CNENA_CNIEA2_POSITION)
#define CNA1_ENABLE                  (1 << _CNENA_CNIEA1_POSITION)
#define CNA0_ENABLE                  (1 << _CNENA_CNIEA0_POSITION)
#define CNA_DISABLE_ALL              (0)             /* Default */

#define CNB15_ENABLE                 (1 << _CNENB_CNIEB15_POSITION)
#define CNB14_ENABLE                 (1 << _CNENB_CNIEB14_POSITION)
#define CNB13_ENABLE                 (1 << _CNENB_CNIEB13_POSITION)
#define CNB12_ENABLE                 (1 << _CNENB_CNIEB12_POSITION) 
#define CNB11_ENABLE                 (1 << _CNENB_CNIEB11_POSITION) 
#define CNB10_ENABLE                 (1 << _CNENB_CNIEB10_POSITION)
#define CNB9_ENABLE                  (1 << _CNENB_CNIEB9_POSITION)
#define CNB8_ENABLE                  (1 << _CNENB_CNIEB8_POSITION)
#define CNB7_ENABLE                  (1 << _CNENB_CNIEB7_POSITION)
#define CNB6_ENABLE                  (1 << _CNENB_CNIEB6_POSITION)
#define CNB5_ENABLE                  (1 << _CNENB_CNIEB5_POSITION)
#define CNB4_ENABLE                  (1 << _CNENB_CNIEB4_POSITION)
#define CNB3_ENABLE                  (1 << _CNENB_CNIEB3_POSITION)
#define CNB2_ENABLE                  (1 << _CNENB_CNIEB2_POSITION)
#define CNB1_ENABLE                  (1 << _CNENB_CNIEB1_POSITION)
#define CNB0_ENABLE                  (1 << _CNENB_CNIEB0_POSITION)
#define CNB_DISABLE_ALL              (0)             /* Default */

#define CNC9_ENABLE                  (1 << _CNENC_CNIEC9_POSITION)
#define CNC8_ENABLE                  (1 << _CNENC_CNIEC8_POSITION)
#define CNC7_ENABLE                  (1 << _CNENC_CNIEC7_POSITION)
#define CNC6_ENABLE                  (1 << _CNENC_CNIEC6_POSITION)
#define CNC5_ENABLE                  (1 << _CNENC_CNIEC5_POSITION)
#define CNC4_ENABLE                  (1 << _CNENC_CNIEC4_POSITION)
#define CNC3_ENABLE                  (1 << _CNENC_CNIEC3_POSITION)
#define CNC2_ENABLE                  (1 << _CNENC_CNIEC2_POSITION)
#define CNC1_ENABLE                  (1 << _CNENC_CNIEC1_POSITION)
#define CNC0_ENABLE                  (1 << _CNENC_CNIEC0_POSITION)
#define CNC_DISABLE_ALL              (0)             /* Default */
 
#else
#define CN21_ENABLE                 (1 << _CNEN_CNEN21_POSITION)
#define CN20_ENABLE                 (1 << _CNEN_CNEN20_POSITION)
#define CN19_ENABLE                 (1 << _CNEN_CNEN19_POSITION)
#define CN18_ENABLE                 (1 << _CNEN_CNEN18_POSITION)
#define CN17_ENABLE                 (1 << _CNEN_CNEN17_POSITION)
#define CN16_ENABLE                 (1 << _CNEN_CNEN16_POSITION)
#define CN15_ENABLE                 (1 << _CNEN_CNEN15_POSITION)
#define CN14_ENABLE                 (1 << _CNEN_CNEN14_POSITION)
#define CN13_ENABLE                 (1 << _CNEN_CNEN13_POSITION)
#define CN12_ENABLE                 (1 << _CNEN_CNEN12_POSITION)
#define CN11_ENABLE                 (1 << _CNEN_CNEN11_POSITION)
#define CN10_ENABLE                 (1 << _CNEN_CNEN10_POSITION)
#define CN9_ENABLE                  (1 << _CNEN_CNEN9_POSITION)
#define CN8_ENABLE                  (1 << _CNEN_CNEN8_POSITION)
#define CN7_ENABLE                  (1 << _CNEN_CNEN7_POSITION)
#define CN6_ENABLE                  (1 << _CNEN_CNEN6_POSITION)
#define CN5_ENABLE                  (1 << _CNEN_CNEN5_POSITION)
#define CN4_ENABLE                  (1 << _CNEN_CNEN4_POSITION)
#define CN3_ENABLE                  (1 << _CNEN_CNEN3_POSITION)
#define CN2_ENABLE                  (1 << _CNEN_CNEN2_POSITION)
#define CN1_ENABLE                  (1 << _CNEN_CNEN1_POSITION)
#define CN0_ENABLE                  (1 << _CNEN_CNEN0_POSITION)
#define CN_DISABLE_ALL              (0)             /* Default */
#endif
/******************************************************************************
 * Change Notice Open Control Function
 *
 * Function:        void mCNOpen(unsigned int control, unsigned int pins, unsigned int pullup)
 *
 * Description:     Configures Change Notice interrupt, enables specified
 *                  change notice inputs and pullups and configures the CNCON register.
 *                  Attention: This function does not enable the CN interrupt nor its priorities.
 *                  The user should use macro ConfigIntCN to enable the CN interrupt and set the
 *                  desired priorities only after reading the corresponding ports.
 *                  See Notes below.
 *
 * PreCondition:    None
 *
 * Inputs:          Bit-wise OR value of CNx_ENABLE sets
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
* Example:          Enable the change notice module, select pins CN0 & CN1 and enable
 *                  corresponding weak pull-ups.
 *                  mCNOpen(CN_ON | CN_IDLE_CON, CN0_ENABLE | CN1_ENABLE,
 *                  CN0_PULLUP_ENABLE | CN1_PULLUP_ENABLE)
 *
 * Notes:           It is recommended to disable vector interrupts prior to configuring
 *                  the change notice module and to use the following sequence to
 *                  prevent spurious change notice interrupts during configuration:
 *
 *                  1. setup the change notice module, pins and optional pullups
 *                  mCNOpen(control, pins, pullups).
 *
 *                  2. read every port that has a corresponding enabled change notice pins
 *                  var = mPORTARead;
 *                  var = PORTBRead;
 *                  ...
 *
 *                  3. setup the change notice interrupts
 *                  ConfigIntCN(interrupt).
 *
 *****************************************************************************/

#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#define mCNAOpen(configA, pinsA, pullupsA)\
        (CNCONACLR = 0xFFFF, CNCONASET = ((configA) | CN_ON), CNENA = (pinsA), CNPUA = (pullupsA))
#define mCNBOpen(configB, pinsB, pullupsB)\
        (CNCONBCLR = 0xFFFF, CNCONBSET = ((configB) | CN_ON), CNENB = (pinsB), CNPUB = (pullupsB))
#define mCNCOpen(configC, pinsC, pullupsC)\
        (CNCONCCLR = 0xFFFF, CNCONCSET = ((configC) | CN_ON), CNENC = (pinsC), CNPUC = (pullupsC))
#else
#define mCNOpen(config, pins, pullups)\
        (CNCONCLR = 0xFFFF, CNCONSET = ((config) | CN_ON), CNEN = (pins), CNPUE = (pullups))
#endif

/******************************************************************************
 * Change Notice Close Control Function
 *
 * Function:        void mCNClose(void)
 *
 * Description:     Disables Change Notice interrupt, disables all
 *                  change notice inputs and pullups
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         mCNClose();
 *
 *****************************************************************************/
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#define mCNAClose() (mCNAClearIntFlag(), mCNAIntEnable(0), CNCONACLR = (1 << 15),\
                    CNENA = 0, CNPUA = 0)
#define mCNBClose() (mCNBClearIntFlag(), mCNBIntEnable(0), CNCONBCLR = (1 << 15),\
                    CNENB = 0, CNPUB = 0)
#define mCNCClose() (mCNCClearIntFlag(), mCNCIntEnable(0), CNCONCCLR = (1 << 15),\
                    CNENC = 0, CNPUC = 0)
#else
#define mCNClose() (mCNClearIntFlag(), mCNIntEnable(0), CNCONCLR = (1 << 15),\
                    CNEN = 0, CNPUE = 0)
#endif

/******************************************************************************
 * Change Notice Enable Interrupt Control Function
 *
 * Function:        void mCNEnable(void)
 *
 * Description:     Enables/Disables Change Notice Interrupt
 *
 * PreCondition:    Assumes Change Notice interrupt priorities have already been
 *                  set as well as the individual CN inputs
 *
 * Inputs:          CHANGE_INT_ON, CHANGE_INT_OFF
 *
 * Output:          None
 *
 * Example:         mCNEnable(CHANGE_INT_ON);
 *
 *****************************************************************************/
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
#define mCNAEnable(config) (mCNAIntEnable((config) >> 15))
#define mCNBEnable(config) (mCNBIntEnable((config) >> 15))
#define mCNCEnable(config) (mCNCIntEnable((config) >> 15))
#else
#define mCNEnable(config) (mCNIntEnable((config) >> 15))
#endif

/******************************************************************************
 * <combinewith EnableCN0, EnableCN1, EnableCN2, EnableCN3, EnableCN4, EnableCN5,
 * EnableCN6, EnableCN7, EnableCN8, EnableCN9, EnableCN10, EnableCN11, EnableCN12, EnableCN13,
 * EnableCN14, EnableCN15, EnableCN16, EnableCN17, EnableCN18, EnableCN19, EnableCN20>
 *
 * Change Notice Interrupt Control Function
 *
 * Function:        void EnableCNx(void)
 *
 * Description:     Enables individual Change Notice interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         EnableCN0()
 *
 *****************************************************************************/
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__)) 
#define EnableCNA10                (CNENASET = (1 << _CNENA_CNIEA10_POSITION))
#define EnableCNA9                 (CNENASET = (1 << _CNENA_CNIEA9_POSITION))
#define EnableCNA8                 (CNENASET = (1 << _CNENA_CNIEA8_POSITION))
#define EnableCNA7                 (CNENASET = (1 << _CNENA_CNIEA7_POSITION))
#define EnableCNA4                 (CNENASET = (1 << _CNENA_CNIEA4_POSITION))
#define EnableCNA3                 (CNENASET = (1 << _CNENA_CNIEA3_POSITION))
#define EnableCNA2                 (CNENASET = (1 << _CNENA_CNIEA2_POSITION))
#define EnableCNA1                 (CNENASET = (1 << _CNENA_CNIEA1_POSITION))
#define EnableCNA0                 (CNENASET = (1 << _CNENA_CNIEA0_POSITION))
                                                                           
#define EnableCNB15                (CNENBSET = (1 << _CNENB_CNIEB15_POSITION))
#define EnableCNB14                (CNENBSET = (1 << _CNENB_CNIEB14_POSITION))
#define EnableCNB13                (CNENBSET = (1 << _CNENB_CNIEB13_POSITION))
#define EnableCNB12                (CNENBSET = (1 << _CNENB_CNIEB12_POSITION)) 
#define EnableCNB11                (CNENBSET = (1 << _CNENB_CNIEB11_POSITION)) 
#define EnableCNB10                (CNENBSET = (1 << _CNENB_CNIEB10_POSITION))
#define EnableCNB9                 (CNENBSET = (1 << _CNENB_CNIEB9_POSITION))
#define EnableCNB8                 (CNENBSET = (1 << _CNENB_CNIEB8_POSITION))
#define EnableCNB7                 (CNENBSET = (1 << _CNENB_CNIEB7_POSITION))
#define EnableCNB6                 (CNENBSET = (1 << _CNENB_CNIEB6_POSITION))
#define EnableCNB5                 (CNENBSET = (1 << _CNENB_CNIEB5_POSITION))
#define EnableCNB4                 (CNENBSET = (1 << _CNENB_CNIEB4_POSITION))
#define EnableCNB3                 (CNENBSET = (1 << _CNENB_CNIEB3_POSITION))
#define EnableCNB2                 (CNENBSET = (1 << _CNENB_CNIEB2_POSITION))
#define EnableCNB1                 (CNENBSET = (1 << _CNENB_CNIEB1_POSITION))
#define EnableCNB0                 (CNENBSET = (1 << _CNENB_CNIEB0_POSITION))
                                   
#define EnableCNC9                 (CNENCSET = (1 << _CNENC_CNIEC9_POSITION))
#define EnableCNC8                 (CNENCSET = (1 << _CNENC_CNIEC8_POSITION))
#define EnableCNC7                 (CNENCSET = (1 << _CNENC_CNIEC7_POSITION))
#define EnableCNC6                 (CNENCSET = (1 << _CNENC_CNIEC6_POSITION))
#define EnableCNC5                 (CNENCSET = (1 << _CNENC_CNIEC5_POSITION))
#define EnableCNC4                 (CNENCSET = (1 << _CNENC_CNIEC4_POSITION))
#define EnableCNC3                 (CNENCSET = (1 << _CNENC_CNIEC3_POSITION))
#define EnableCNC2                 (CNENCSET = (1 << _CNENC_CNIEC2_POSITION))
#define EnableCNC1                 (CNENCSET = (1 << _CNENC_CNIEC1_POSITION))
#define EnableCNC0                 (CNENCSET = (1 << _CNENC_CNIEC0_POSITION))

#else
#define EnableCN21                  (CNENSET = (1 << _CNEN_CNEN21_POSITION))
#define EnableCN20                  (CNENSET = (1 << _CNEN_CNEN20_POSITION))
#define EnableCN19                  (CNENSET = (1 << _CNEN_CNEN19_POSITION))
#define EnableCN18                  (CNENSET = (1 << _CNEN_CNEN18_POSITION))
#define EnableCN17                  (CNENSET = (1 << _CNEN_CNEN17_POSITION))
#define EnableCN16                  (CNENSET = (1 << _CNEN_CNEN16_POSITION))
#define EnableCN15                  (CNENSET = (1 << _CNEN_CNEN15_POSITION))
#define EnableCN14                  (CNENSET = (1 << _CNEN_CNEN14_POSITION))
#define EnableCN13                  (CNENSET = (1 << _CNEN_CNEN13_POSITION))
#define EnableCN12                  (CNENSET = (1 << _CNEN_CNEN12_POSITION))
#define EnableCN11                  (CNENSET = (1 << _CNEN_CNEN11_POSITION))
#define EnableCN10                  (CNENSET = (1 << _CNEN_CNEN10_POSITION))
#define EnableCN9                   (CNENSET = (1 << _CNEN_CNEN9_POSITION))
#define EnableCN8                   (CNENSET = (1 << _CNEN_CNEN8_POSITION))
#define EnableCN7                   (CNENSET = (1 << _CNEN_CNEN7_POSITION))
#define EnableCN6                   (CNENSET = (1 << _CNEN_CNEN6_POSITION))
#define EnableCN5                   (CNENSET = (1 << _CNEN_CNEN5_POSITION))
#define EnableCN4                   (CNENSET = (1 << _CNEN_CNEN4_POSITION))
#define EnableCN3                   (CNENSET = (1 << _CNEN_CNEN3_POSITION))
#define EnableCN2                   (CNENSET = (1 << _CNEN_CNEN2_POSITION))
#define EnableCN1                   (CNENSET = (1 << _CNEN_CNEN1_POSITION))
#define EnableCN0                   (CNENSET = (1 << _CNEN_CNEN0_POSITION))
#endif

/******************************************************************************
 * <combinewith DisableCN0, DisableCN1, DisableCN2, DisableCN3, DisableCN4, DisableCN5,
 * DisableCN6, DisableCN7, DisableCN8, DisableCN9, DisableCN10, DisableCN11, DisableCN12,
 * DisableCN13, DisableCN14, DisableCN15, DisableCN16, DisableCN17, DisableCN18, DisableCN19,
 * DisableCN20, DisableCN_ALL>
 *
 * Change Notice Interrupt Control Function
 *
 * Function:        void DisableCNx(void)
 *
 * Description:     Disables individual Change Notice interrupt
 *
 * PreCondition:    None
 *
 * Inputs:          None
 *
 * Output:          None
 *
 * Example:         DisableCN0()
 *
 *****************************************************************************/
#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))  
#define DisableCNA10                (CNENACLR = (1 << _CNENA_CNIEA10_POSITION))
#define DisableCNA9                 (CNENACLR = (1 << _CNENA_CNIEA9_POSITION))
#define DisableCNA8                 (CNENACLR = (1 << _CNENA_CNIEA8_POSITION))
#define DisableCNA7                 (CNENACLR = (1 << _CNENA_CNIEA7_POSITION))
#define DisableCNA4                 (CNENACLR = (1 << _CNENA_CNIEA4_POSITION))
#define DisableCNA3                 (CNENACLR = (1 << _CNENA_CNIEA3_POSITION))
#define DisableCNA2                 (CNENACLR = (1 << _CNENA_CNIEA2_POSITION))
#define DisableCNA1                 (CNENACLR = (1 << _CNENA_CNIEA1_POSITION))
#define DisableCNA0                 (CNENACLR = (1 << _CNENA_CNIEA0_POSITION))
#define DisableCNA_ALL              (CNENACLR = (0xFFFF))
                                                      
#define DisableCNB15                (CNENBCLR = (1 << _CNENB_CNIEB15_POSITION))
#define DisableCNB14                (CNENBCLR = (1 << _CNENB_CNIEB14_POSITION))
#define DisableCNB13                (CNENBCLR = (1 << _CNENB_CNIEB13_POSITION))
#define DisableCNB12                (CNENBCLR = (1 << _CNENB_CNIEB12_POSITION)) 
#define DisableCNB11                (CNENBCLR = (1 << _CNENB_CNIEB11_POSITION)) 
#define DisableCNB10                (CNENBCLR = (1 << _CNENB_CNIEB10_POSITION))
#define DisableCNB9                 (CNENBCLR = (1 << _CNENB_CNIEB9_POSITION))
#define DisableCNB8                 (CNENBCLR = (1 << _CNENB_CNIEB8_POSITION))
#define DisableCNB7                 (CNENBCLR = (1 << _CNENB_CNIEB7_POSITION))
#define DisableCNB6                 (CNENBCLR = (1 << _CNENB_CNIEB6_POSITION))
#define DisableCNB5                 (CNENBCLR = (1 << _CNENB_CNIEB5_POSITION))
#define DisableCNB4                 (CNENBCLR = (1 << _CNENB_CNIEB4_POSITION))
#define DisableCNB3                 (CNENBCLR = (1 << _CNENB_CNIEB3_POSITION))
#define DisableCNB2                 (CNENBCLR = (1 << _CNENB_CNIEB2_POSITION))
#define DisableCNB1                 (CNENBCLR = (1 << _CNENB_CNIEB1_POSITION))
#define DisableCNB0                 (CNENBCLR = (1 << _CNENB_CNIEB0_POSITION))
#define DisableCNB_ALL              (CNENBCLR = (0xFFFF))
 
#define DisableCNC9                 (CNENCCLR = (1 << _CNENC_CNIEC9_POSITION))
#define DisableCNC8                 (CNENCCLR = (1 << _CNENC_CNIEC8_POSITION))
#define DisableCNC7                 (CNENCCLR = (1 << _CNENC_CNIEC7_POSITION))
#define DisableCNC6                 (CNENCCLR = (1 << _CNENC_CNIEC6_POSITION))
#define DisableCNC5                 (CNENCCLR = (1 << _CNENC_CNIEC5_POSITION))
#define DisableCNC4                 (CNENCCLR = (1 << _CNENC_CNIEC4_POSITION))
#define DisableCNC3                 (CNENCCLR = (1 << _CNENC_CNIEC3_POSITION))
#define DisableCNC2                 (CNENCCLR = (1 << _CNENC_CNIEC2_POSITION))
#define DisableCNC1                 (CNENCCLR = (1 << _CNENC_CNIEC1_POSITION))
#define DisableCNC0                 (CNENCCLR = (1 << _CNENC_CNIEC0_POSITION))
#define DisableCNC_ALL              (CNENCCLR = (0xFFFF))                                  
#else								  
								  
#define DisableCN21                 (CNENCLR = (1 << _CNEN_CNEN21_POSITION))
#define DisableCN20                 (CNENCLR = (1 << _CNEN_CNEN20_POSITION))
#define DisableCN19                 (CNENCLR = (1 << _CNEN_CNEN19_POSITION))
#define DisableCN18                 (CNENCLR = (1 << _CNEN_CNEN18_POSITION))
#define DisableCN17                 (CNENCLR = (1 << _CNEN_CNEN17_POSITION))
#define DisableCN16                 (CNENCLR = (1 << _CNEN_CNEN16_POSITION))
#define DisableCN15                 (CNENCLR = (1 << _CNEN_CNEN15_POSITION))
#define DisableCN14                 (CNENCLR = (1 << _CNEN_CNEN14_POSITION))
#define DisableCN13                 (CNENCLR = (1 << _CNEN_CNEN13_POSITION))
#define DisableCN12                 (CNENCLR = (1 << _CNEN_CNEN12_POSITION))
#define DisableCN11                 (CNENCLR = (1 << _CNEN_CNEN11_POSITION))
#define DisableCN10                 (CNENCLR = (1 << _CNEN_CNEN10_POSITION))
#define DisableCN9                  (CNENCLR = (1 << _CNEN_CNEN9_POSITION))
#define DisableCN8                  (CNENCLR = (1 << _CNEN_CNEN8_POSITION))
#define DisableCN7                  (CNENCLR = (1 << _CNEN_CNEN7_POSITION))
#define DisableCN6                  (CNENCLR = (1 << _CNEN_CNEN6_POSITION))
#define DisableCN5                  (CNENCLR = (1 << _CNEN_CNEN5_POSITION))
#define DisableCN4                  (CNENCLR = (1 << _CNEN_CNEN4_POSITION))
#define DisableCN3                  (CNENCLR = (1 << _CNEN_CNEN3_POSITION))
#define DisableCN2                  (CNENCLR = (1 << _CNEN_CNEN2_POSITION))
#define DisableCN1                  (CNENCLR = (1 << _CNEN_CNEN1_POSITION))
#define DisableCN0                  (CNENCLR = (1 << _CNEN_CNEN0_POSITION))
#define DisableCN_ALL               (CNENCLR = (0xFFFF))
#endif

/******************************************************************************
 * PORT Parameter values to be used with mPORTxxx macros
 *****************************************************************************/

 #define BIT_31                       (1 << 31)
 #define BIT_30                       (1 << 30)
 #define BIT_29                       (1 << 29)
 #define BIT_28                       (1 << 28)
 #define BIT_27                       (1 << 27)
 #define BIT_26                       (1 << 26)
 #define BIT_25                       (1 << 25)
 #define BIT_24                       (1 << 24)
 #define BIT_23                       (1 << 23)
 #define BIT_22                       (1 << 22)
 #define BIT_21                       (1 << 21)
 #define BIT_20                       (1 << 20)
 #define BIT_19                       (1 << 19)
 #define BIT_18                       (1 << 18)
 #define BIT_17                       (1 << 17)
 #define BIT_16                       (1 << 16)
 #define BIT_15                       (1 << 15)
 #define BIT_14                       (1 << 14)
 #define BIT_13                       (1 << 13)
 #define BIT_12                       (1 << 12)
 #define BIT_11                       (1 << 11)
 #define BIT_10                       (1 << 10)
 #define BIT_9                        (1 << 9)
 #define BIT_8                        (1 << 8)
 #define BIT_7                        (1 << 7)
 #define BIT_6                        (1 << 6)
 #define BIT_5                        (1 << 5)
 #define BIT_4                        (1 << 4)
 #define BIT_3                        (1 << 3)
 #define BIT_2                        (1 << 2)
 #define BIT_1                        (1 << 1)
 #define BIT_0                        (1 << 0)


typedef enum {
#ifdef _PORTA
        IOPORT_A,
#endif
#ifdef _PORTB
        IOPORT_B,
#endif
#ifdef _PORTC
        IOPORT_C,
#endif
#ifdef _PORTD
        IOPORT_D,
#endif
#ifdef _PORTE
        IOPORT_E,
#endif
#ifdef _PORTF
        IOPORT_F,
#endif
#ifdef _PORTG
        IOPORT_G,
#endif
    IOPORT_NUM
    }IoPortId;

/******************************************************************************
 * Set Pins as Digital Input
 *
 * Function:        PORTSetPinsDigitalIn(IoPortId portId, unsigned int inputs)
 *
 * Description:     Configures selected pins as digital inputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  inputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalIn(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTSetPinsDigitalIn(IoPortId portId, unsigned int inputs);

/******************************************************************************
 * Set Pins as Digital Output
 *
 * Function:        PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as digital outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsDigitalOut(IOPORT_C, IOPORT_PIN_6 | IOPORT_PIN_7);
 *
 *****************************************************************************/
void    PORTSetPinsDigitalOut(IoPortId portId, unsigned int outputs);

/******************************************************************************
 * Set Pins as Analog Input
 *
 * Function:        PORTSetPinsAnalogIn(IoPortId portId, unsigned int inputs)
 *
 * Description:     Configures selected pins as Analog inputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  inputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsAnalogIn(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTSetPinsAnalogIn(IoPortId portId, unsigned int inputs);

/******************************************************************************
 * Set Pins as Analog Output
 *
 * Function:        PORTSetPinsAnalogOut(IoPortId portId, unsigned int outputs)
 *
 * Description:     Configures selected pins as analog outputs
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  outputs: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTSetPinsAnalogOut(IOPORT_C, IOPORT_PIN_6 | IOPORT_PIN_7);
 *
 *****************************************************************************/
void    PORTSetPinsAnalogOut(IoPortId portId, unsigned int outputs);

/******************************************************************************
 * Reset PORT pins
 *
 * Function:        PORTResetPins(IoPortId portId, unsigned int pins)
 *
 * Description:     Resets IOPORT pins to their POR state
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  pins: Bit-wise ORed of Priority, Interrupt Edge
 *                          Mode and Interrupt enable/disable value.
 *
 *                  Note: An absent symbol assumes corresponding bit(s)
 *                  are disabled, or default value, and will be set = 0.
 *
 * Output:          None
 *
 * Example:         PORTResetPins(IOPORT_D, IOPORT_PIN_15);
 *
 *****************************************************************************/
void    PORTResetPins(IoPortId portId, unsigned int pins);

/******************************************************************************
 * Reads digital port
 *
 * Function:        unsigned int    PORTRead(IoPortId portId);
 *
 * Description:     Reads from a selected port
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 * Output:          Value of input port
 *
 * Example:         unsigned int value = PORTRead(IOPORT_B);
 *
 *****************************************************************************/
unsigned int    PORTRead(IoPortId portId);

/******************************************************************************
 * Reads digital port bits
 *
 * Function:        unsigned int    PORTReadBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Reads selected pins from port
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be read
 *
 * Output:          Value of input port
 *
 * Example:         unsigned int value = PORTReadBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
unsigned int    PORTReadBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Writes to a digital port
 *
 * Function:        void    PORTWrite(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes to PORT register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 * Output:          None
 *
 * Example:         PORTWrite(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTWrite(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Sets digital port bits
 *
 * Function:        void    PORTSetBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTSET register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTSetBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTSetBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Clears digital port bits
 *
 * Function:        void    PORTClearBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTCLR register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTClearBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTClearBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * Toggle digital port bits
 *
 * Function:        void    PORTToggleBits(IoPortId portId, unsigned int bits);
 *
 * Description:     Writes selected bits to PORTINV register
 *
 * PreCondition:    None
 *
 * Inputs:          portID: Enumerated PORT Identifier - see ports.h
 *
 *                  bits:   Mask of bits to be written
 *
 * Output:          None
 *
 * Example:         PORTToggleBits(IOPORT_B, BIT_2 | BIT_4);
 *
 *****************************************************************************/
void    PORTToggleBits(IoPortId portId, unsigned int bits);

/******************************************************************************
 * <combinewith mPORTAGetDirection, mPORTAReadDirectionBits, mPORTARead ,mPORTAReadBits, mPORTAReadLatch,
 * mPORTAReadLatchBits, mPORTAWrite, mPORTASetBits, mPORTAClearBits, mPORTAToggleBits, mPORTAOpenDrainOpen,
 * mPORTAOpenDrainClose, mPORTACloseAll, mPORTACloseBits, mPORTASetPinsDigitalIn, mPORTASetPinsDigitalOut,
 * mPORTBDirection, mPORTBGetDirection, mPORTBReadDirectionBits, mPORTBRead ,mPORTBReadBits, mPORTBReadLatch,
 * mPORTBReadLatchBits, mPORTBWrite, mPORTBSetBits, mPORTBClearBits, mPORTBToggleBits, mPORTBOpenDrainOpen,
 * mPORTBOpenDrainClose, mPORTBCloseAll, mPORTBCloseBits, mPORTBSetPinsDigitalIn, mPORTBSetPinsDigitalOut,
 * mPORTBSetPinsAnalogOut, mPORTBSetPinsAnalogIn,
 * mPORTCDirection, mPORTCGetDirection, mPORTCReadDirectionBits, mPORTCRead ,mPORTCReadBits, mPORTCReadLatch,
 * mPORTCReadLatchBits, mPORTCWrite, mPORTCSetBits, mPORTCClearBits, mPORTCToggleBits, mPORTCOpenDrainOpen,
 * mPORTCOpenDrainClose, mPORTCCloseAll, mPORTCCloseBits, mPORTCSetPinsDigitalIn, mPORTCSetPinsDigitalOut,
 * mPORTDDirection, mPORTDGetDirection, mPORTDReadDirectionBits, mPORTDRead ,mPORTDReadBits, mPORTDReadLatch,
 * mPORTDReadLatchBits, mPORTDWrite, mPORTDSetBits, mPORTDClearBits, mPORTDToggleBits, mPORTDOpenDrainOpen,
 * mPORTDOpenDrainClose, mPORTDCloseAll, mPORTDCloseBits, mPORTDSetPinsDigitalIn, mPORTDSetPinsDigitalOut,
 * mPORTBEirection, mPORTEGetDirection, mPORTEReadDirectionBits, mPORTERead ,mPORTEReadBits, mPORTEReadLatch,
 * mPORTEReadLatchBits, mPORTEWrite, mPORTESetBits, mPORTEClearBits, mPORTEToggleBits, mPORTEOpenDrainOpen,
 * mPORTEOpenDrainClose, mPORTECloseAll, mPORTECloseBits, mPORTESetPinsDigitalIn, mPORTESetPinsDigitalOut,
 * mPORTFDirection, mPORTFGetDirection, mPORTFReadDirectionBits, mPORTFRead ,mPORTFReadBits, mPORTFReadLatch,
 * mPORTFReadLatchBits, mPORTFWrite, mPORTFSetBits, mPORTFClearBits, mPORTFToggleBits, mPORTFOpenDrainOpen,
 * mPORTFOpenDrainClose, mPORTFCloseAll, mPORTFCloseBits, mPORTFSetPinsDigitalIn, mPORTFSetPinsDigitalOut,
 * mPORTGDirection, mPORTGGetDirection, mPORTGReadDirectionBits, mPORTGRead ,mPORTGReadBits, mPORTGReadLatch,
 * mPORTGReadLatchBits, mPORTGWrite, mPORTGSetBits, mPORTGClearBits, mPORTGToggleBits, mPORTGOpenDrainOpen,
 * mPORTGOpenDrainClose, mPORTGCloseAll, mPORTGCloseBits, mPORTGSetPinsDigitalIn, mPORTGSetPinsDigitalOut>
 *
 * GPIO Control Macros
 *
 * Description:
 *          To set I/O pin directions for a PORTx
 *                  void mPORTxConfig(unsigned int _direction)
 *                  unsigned int mPORTxGetConfig(void)
 *                  unsigned int mPORTxReadConfigBit(unsigned int _bits)
 *
 *          To read an input pin
 *                  unsigned int mPORTxRead(void)
 *                  unsigned int mPORTxReadBit(unsigned int _bits)
 *
 *          To write to an output pin
 *                  void mPORTxWrite(unsigned int _value)
 *                  unsigned int mPORTxReadLatch(void)
 *                  unsigned int mPORTxReadLatchBit(unsigned int _bits)
 *
 *          To configure select pins in a PORT without affecting other pins
 *                  void mPORTxSetPinsDigitalInput(unsigned int _inputs)
 *                  void mPORTxSetPinsDigitalOutput(unsigned int _outputs)
 *                  void mPORTxSetPinsAnalogInput(unsigned int _inputs)
 *                  void mPORTxSetPinsAnalogOutput(unsigned int _outputs)
 *                  void mPORTxOutputConfig(unsigned int _outputs)
 *                  void mPORTxInputConfig(unsigned int _inputs)
 *
 *          To manipulate select pins in a PORT without affecting other pins
 *                  void mPORTxSetbits(unsigned int _bits)
 *                  void mPORTxClearBits(unsigned int _bits)
 *                  void mPORTxToggleBits(unsigned int _bits)
 *
 *          To make a PORT all input and clear latch values.
 *                  void mPORTxCloseAll(void)
 *                  void mPORTxCloseBits(unsigned int _bits)
 *
 *          To configure open drain I/Os in a PORT.
 *                  void mPORTxOpenDrainOpen(unsigned int _bits)
 *                  void mPORTxOpenDrainClose(unsigned int _bits)
 *
 *
 * Example:         mPORTCSetPinsDigitalOutput(IO_PORT_BIT_4 | IO_PORT_BIT_3)
 *
 *****************************************************************************/

#if defined _PORTA
#define mPORTADirection(_tris)              (TRISA = (unsigned int)(_tris))
#define mPORTAGetDirection()                (TRISA)
#define mPORTAReadDirectionBits(_bits)      (TRISA & (unsigned int)(_bits))

#define mPORTARead()                        (PORTA)
#define mPORTAReadBits(_bits)               (PORTA & (unsigned int)(_bits))
#define mPORTAReadLatch()                   (LATA)
#define mPORTAReadLatchBits(_bits)          (LATA & (unsigned int)(_bits))

#define mPORTAWrite(_lat)                   (LATA = (unsigned int)(_lat))
#define mPORTASetBits(_bits)                (LATASET = (unsigned int)(_bits))
#define mPORTAClearBits(_bits)              (LATACLR = (unsigned int)(_bits))
#define mPORTAToggleBits(_bits)             (LATAINV = (unsigned int)(_bits))

#define mPORTAOpenDrainOpen(_bits)          (ODCASET = (unsigned int)(_bits),\
                                             TRISACLR = (unsigned int)(_bits))
#define mPORTAOpenDrainClose(_bits)         (ODCACLR = (unsigned int)(_bits),\
                                             TRISASET = (unsigned int)(_bits))

#define mPORTACloseAll()                    (TRISASET = 0xFFFFFFFF,\
                                             LATACLR = 0xFFFFFFFF)
#define mPORTACloseBits(_bits)              (TRISASET = (unsigned int)(_bits),\
                                             LATACLR = (unsigned int)(_bits))


#if (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
	#define mPORTASetPinsAnalogOut(_outputs)    (TRISASET = (unsigned int)(_outputs),\
												ANSELASET = (unsigned int)(_outputs))
	#define mPORTASetPinsAnalogIn(_inputs)      (TRISASET = (unsigned int)(_inputs),\
												ANSELASET = (unsigned int)(_inputs))
	#define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs),\
												ANSELACLR = (unsigned int)(_outputs))
	#define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs),\
												ANSELACLR = (unsigned int)(_inputs))

#else
	#define mPORTASetPinsDigitalIn(_inputs)     (TRISASET = (unsigned int)(_inputs))
	#define mPORTASetPinsDigitalOut(_outputs)   (TRISACLR = (unsigned int)(_outputs))
#endif

#endif  //end PORTA


#if defined _PORTB
/******************************************************************************
 * PORTB macros
 *****************************************************************************/
#define mPORTBDirection(_tris)              (TRISB = (unsigned int)(_tris))
#define mPORTBGetDirection()                (TRISB)
#define mPORTBReadDirectionBits(_bits)      (TRISB & (unsigned int)(_bits))

#define mPORTBRead()                        (PORTB)
#define mPORTBReadBits(_bits)               (PORTB & (unsigned int)(_bits))
#define mPORTBReadLatch()                   (LATB)
#define mPORTBReadLatchBits(_bits)          (LATB & (unsigned int)(_bits))

#define mPORTBWrite(_lat)                   (LATB = (unsigned int)(_lat))
#define mPORTBSetBits(_bits)                (LATBSET = (unsigned int)(_bits))
#define mPORTBClearBits(_bits)              (LATBCLR = (unsigned int)(_bits))
#define mPORTBToggleBits(_bits)             (LATBINV = (unsigned int)(_bits))

#define mPORTBOpenDrainOpen(_bits)          (ODCBSET = (unsigned int)(_bits),\
                                            TRISBCLR = (unsigned int)(_bits))
#define mPORTBOpenDrainClose(_bits)         (ODCBCLR = (unsigned int)(_bits),\
                                            TRISBSET = (unsigned int)(_bits))

#define mPORTBCloseAll()                    (TRISBSET = 0xFFFFFFFF,\
                                             LATBCLR = 0xFFFFFFFF)
#define mPORTBCloseBits(_bits)              (TRISBSET = (unsigned int)(_bits),\
                                            LATBCLR = (unsigned int)(_bits))

#if (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
	#define mPORTBSetPinsAnalogOut(_outputs)    (TRISBSET = (unsigned int)(_outputs),\
												ANSELBSET = (unsigned int)(_outputs))
	#define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),\
												ANSELBSET = (unsigned int)(_inputs))
	#define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs),\
												ANSELBCLR= (unsigned int)(_outputs))
	#define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),\
												ANSELBCLR = (unsigned int)(_inputs))
#else
	#define mPORTBSetPinsAnalogOut(_outputs)    (TRISBSET = (unsigned int)(_outputs),\
												AD1PCFGCLR = (unsigned int)(_outputs))
	#define mPORTBSetPinsAnalogIn(_inputs)      (TRISBSET = (unsigned int)(_inputs),\
												AD1PCFGCLR = (unsigned int)(_inputs))
	#define mPORTBSetPinsDigitalOut(_outputs)   (TRISBCLR = (unsigned int)(_outputs),\
												AD1PCFGSET = (unsigned int)(_outputs))
	#define mPORTBSetPinsDigitalIn(_inputs)     (TRISBSET = (unsigned int)(_inputs),\
												AD1PCFGSET = (unsigned int)(_inputs))
#endif

#endif  //end PORTB

#if defined _PORTC
/******************************************************************************
 * PORTC macros
 *****************************************************************************/
#define mPORTCDirection(_tris)              (TRISC = (unsigned int)(_tris))
#define mPORTCGetDirection()                (TRISC)
#define mPORTCReadDirectionBits(_bits)      (TRISC & (unsigned int)(_bits))

#define mPORTCRead()                        (PORTC)
#define mPORTCReadBits(_bits)               (PORTC & (unsigned int)(_bits))
#define mPORTCReadLatch()                   (LATC)
#define mPORTCReadLatchBits(_bits)          (LATC & (unsigned int)(_bits))

#define mPORTCWrite(_lat)                   (LATC = (unsigned int)(_lat))
#define mPORTCSetBits(_bits)                (LATCSET = (unsigned int)(_bits))
#define mPORTCClearBits(_bits)              (LATCCLR = (unsigned int)(_bits))
#define mPORTCToggleBits(_bits)             (LATCINV = (unsigned int)(_bits))

#define mPORTCOpenDrainOpen(_bits)          (ODCCSET = (unsigned int)(_bits),\
                                            TRISCCLR = (unsigned int)(_bits))
#define mPORTCOpenDrainClose(_bits)         (ODCCCLR = (unsigned int)(_bits),\
                                            TRISCSET = (unsigned int)(_bits))

#define mPORTCCloseAll()                    (TRISCSET = 0xFFFFFFFF,\
                                            LATCCLR = 0xFFFFFFFF)
#define mPORTCCloseBits(_bits)              (TRISCSET = (unsigned int)(_bits),\
                                            LATCCLR = (unsigned int)(_bits))

#if (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)) || defined(__32MXGENERIC__))
	#define mPORTCSetPinsAnalogOut(_outputs)    (TRISCSET = (unsigned int)(_outputs),\
												ANSELCSET = (unsigned int)(_outputs))
	#define mPORTCSetPinsAnalogIn(_inputs)      (TRISCSET = (unsigned int)(_inputs),\
												ANSELCSET = (unsigned int)(_inputs))
	#define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs),\
												ANSELCCLR = (unsigned int)(_outputs))
	#define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs),\
												ANSELCCLR = (unsigned int)(_inputs))
#else
	#define mPORTCSetPinsDigitalIn(_inputs)     (TRISCSET = (unsigned int)(_inputs))
	#define mPORTCSetPinsDigitalOut(_outputs)   (TRISCCLR = (unsigned int)(_outputs))
#endif


#endif  // end PORTC

#if defined _PORTD
/******************************************************************************
 * PORTD macros
 *****************************************************************************/
#define mPORTDDirection(_tris)              (TRISD = (unsigned int)(_tris))
#define mPORTDGetDirection()                (TRISD)
#define mPORTDReadDirectionBits(_bits)      (TRISD & (unsigned int)(_bits))

#define mPORTDRead()                        (PORTD)
#define mPORTDReadBits(_bits)               (PORTD & (unsigned int)(_bits))
#define mPORTDReadLatch()                   (LATD)
#define mPORTDReadLatchBits(_bits)          (LATD & (unsigned int)(_bits))

#define mPORTDWrite(_lat)                   (LATD = (unsigned int)(_lat))
#define mPORTDSetBits(_bits)                (LATDSET = (unsigned int)(_bits))
#define mPORTDClearBits(_bits)              (LATDCLR = (unsigned int)(_bits))
#define mPORTDToggleBits(_bits)             (LATDINV = (unsigned int)(_bits))

#define mPORTDOpenDrainOpen(_bits)          (TRISDCLR = (unsigned int)(_bits),\
                                            ODCDSET = (unsigned int)(_bits))
#define mPORTDOpenDrainClose(_bits)         (TRISDSET = (unsigned int)(_bits),\
                                            ODCDCLR = (unsigned int)(_bits))

#define mPORTDCloseAll()                    (TRISDSET = 0xFFFFFFFF,\
                                            LATDCLR = 0xFFFFFFFF)
#define mPORTDCloseBits(_bits)              (TRISDSET = (unsigned int)(_bits),\
                                            LATDCLR = (unsigned int)(_bits))

#define mPORTDSetPinsDigitalIn(_inputs)     (TRISDSET = (unsigned int)(_inputs))
#define mPORTDSetPinsDigitalOut(_outputs)   (TRISDCLR = (unsigned int)(_outputs))

#endif  // end PORTD

#if defined _PORTE
/******************************************************************************
 * PORTE macros
 *****************************************************************************/
#define mPORTEDirection(_tris)              (TRISE = (unsigned int)(_tris))
#define mPORTEGetDirection()                (TRISE)
#define mPORTEReadDirectionBits(_bits)      (TRISE & (unsigned int)(_bits))

#define mPORTERead()                        (PORTE)
#define mPORTEReadBits(_bits)               (PORTE & (unsigned int)(_bits))
#define mPORTEReadLatch()                   (LATE)
#define mPORTEReadLatchBits(_bits)          (LATE & (unsigned int)(_bits))

#define mPORTEWrite(_lat)                   (LATE = (unsigned int)(_lat))
#define mPORTESetBits(_bits)                (LATESET = (unsigned int)(_bits))
#define mPORTEClearBits(_bits)              (LATECLR = (unsigned int)(_bits))
#define mPORTEToggleBits(_bits)             (LATEINV = (unsigned int)(_bits))

#define mPORTEOpenDrainOpen(_bits)          (ODCESET = (unsigned int)(_bits),\
                                            TRISECLR = (unsigned int)(_bits))
#define mPORTEOpenDrainClose(_bits)         (ODCECLR = (unsigned int)(_bits),\
                                            TRISESET = (unsigned int)(_bits))

#define mPORTECloseAll()                    (TRISESET = 0xFFFFFFFF,\
                                             LATECLR = 0xFFFFFFFF)
#define mPORTECloseBits(_bits)              (TRISESET = (unsigned int)(_bits),\
                                            LATECLR = (unsigned int)(_bits))

#define mPORTESetPinsDigitalIn(_inputs)     (TRISESET = (unsigned int)(_inputs))
#define mPORTESetPinsDigitalOut(_outputs)   (TRISECLR = (unsigned int)(_outputs))

#endif  // end PORTE

#if defined _PORTF
/******************************************************************************
 * PORTF macros
 *****************************************************************************/
#define mPORTFDirection(_tris)              (TRISF = (unsigned int)(_tris))
#define mPORTFGetDirection()                (TRISF)
#define mPORTFReadDirectionBits(_bits)      (TRISF & (unsigned int)(_bits))

#define mPORTFRead()                        (PORTF)
#define mPORTFReadBits(_bits)               (PORTF & (unsigned int)(_bits))
#define mPORTFReadLatch()                   (LATF)
#define mPORTFReadLatchBits(_bits)          (LATF & (unsigned int)(_bits))

#define mPORTFWrite(_lat)                   (LATF = (unsigned int)(_lat))
#define mPORTFSetBits(_bits)                (LATFSET = (unsigned int)(_bits))
#define mPORTFClearBits(_bits)              (LATFCLR = (unsigned int)(_bits))
#define mPORTFToggleBits(_bits)             (LATFINV = (unsigned int)(_bits))

#define mPORTFOpenDrainOpen(_bits)          (ODCFSET = (unsigned int)(_bits),\
                                            TRISFCLR = (unsigned int)(_bits))
#define mPORTFOpenDrainClose(_bits)         (ODCFCLR = (unsigned int)(_bits),\
                                            TRISFSET = (unsigned int)(_bits))

#define mPORTFCloseAll()                    (TRISFSET = 0xFFFFFFFF,\
                                            LATFCLR = 0xFFFFFFFF)
#define mPORTFCloseBits(_bits)              (TRISFSET = (unsigned int)(_bits),\
                                            LATFCLR = (unsigned int)(_bits))

#define mPORTFSetPinsDigitalIn(_inputs)     (TRISFSET = (unsigned int)(_inputs))
#define mPORTFSetPinsDigitalOut(_outputs)   (TRISFCLR = (unsigned int)(_outputs))

#endif  // end PORTF

#if defined _PORTG
/******************************************************************************
 * PORTG macros
 *****************************************************************************/
#define mPORTGDirection(_tris)              (TRISG = (unsigned int)(_tris))
#define mPORTGGetDirection()                (TRISG)
#define mPORTGReadDirectionBits(_bits)      (TRISG & (unsigned int)(_bits))

#define mPORTGRead()                        (PORTG)
#define mPORTGReadBits(_bits)               (PORTG & (unsigned int)(_bits))
#define mPORTGReadLatch()                   (LATG)
#define mPORTGReadLatchBits(_bits)          (LATG & (unsigned int)(_bits))

#define mPORTGWrite(_lat)                   (LATG = (unsigned int)(_lat))
#define mPORTGSetBits(_bits)                (LATGSET = (unsigned int)(_bits))
#define mPORTGClearBits(_bits)              (LATGCLR = (unsigned int)(_bits))
#define mPORTGToggleBits(_bits)             (LATGINV = (unsigned int)(_bits))

#define mPORTGOpenDrainOpen(_bits)          (ODCGSET = (unsigned int)(_bits),\
                                            TRISGCLR = (unsigned int)(_bits))
#define mPORTGOpenDrainClose(_bits)         (ODCGCLR = (unsigned int)(_bits),\
                                            TRISGSET = (unsigned int)(_bits))

#define mPORTGCloseAll()                    (TRISGSET = 0xFFFFFFFF,\
                                            LATGCLR = 0xFFFFFFFF)
#define mPORTGCloseBits(_bits)              (TRISGSET = (unsigned int)(_bits),\
                                            LATGCLR = (unsigned int)(_bits))

#define mPORTGSetPinsDigitalIn(_inputs)     (TRISGSET = (unsigned int)(_inputs))
#define mPORTGSetPinsDigitalOut(_outputs)   (TRISGCLR = (unsigned int)(_outputs))

#endif  // end PORTG




/******************************************************************************
 * Parameter values to be used with mJTAGPortEnable()
 *****************************************************************************/
#define DEBUG_JTAGPORT_ON                       (1)
#define DEBUG_JTAGPORT_OFF                      (0) // Debug JTAG Off

/******************************************************************************
 * JTAG macro       void mJTAGPortEnable(unsigned int enable)
 *
 * Function:
 *                  To enable/disable JTAG module
 *                  mJTAGEnable(unsigned int _enable)
 *
 * Description:     Enables or disables JTAG port.
 *
 * PreCondition:    None
 *
 * Inputs:          0 = disable, 1 = enable
 *
 * Output:          None
 *
 * Example:         mJTAGPortEnable(1)
 *
 *****************************************************************************/
#define mJTAGPortEnable(_enable) (DDPCONbits.JTAGEN = (_enable))

#endif  // _PORTS_H_
