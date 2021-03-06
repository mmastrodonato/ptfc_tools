/**
 * @file CAND_config.c
 * @brief Source for user configuration of CAN driver module. In this file,
 * by configuration look-up tables, must configured the driver properties of
 * messages configured in the relative public interface.
 * WARNING: the Tx messages configuration to have a dedicated mailbox
 * for diag messages and can have a sigle mailbox for remaining messages
 * since in CAND module is managed the message dynamic send.
 * @n The message properties to configure are:
 * @li Mailbox handle
 * @li Message DLC
 * @li Message ID
 * @li Message direction: Tx or Rx
 * @li Message buffer to have tha mailbox mirror
 * </ul>
 *
 * @version 2.3
 * @author Carmine Celozzi (Akhela S.r.l.)
 * @date 14 october 2014
 * @note (C) Copyright 2014 Bitron S.p.A. @link www.Bitron.net
 */
/*
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| GIL          Gianpiero Lenta           Bitron S.p.A.
| CC           Carmine Celozzi           Akhela S.r.l
| MM           Matteo Mastrodonato       Bitron S.p.A.
| DF           Davide Fogliano           Polimatica S.r.l.
| DC           Daniele Cloralio          Ema S.r.l.
|-----------------------------------------------------------------------------
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------  ----------------------------------------------------
| 15/06/15   0.1  DC     952 message map:  P_952_E2A_R3_BHCAN_15_05_2015_CR8681
|-----------------------------------------------------------------------------
| 28/07/15   0.1  DC     952 message map:  P952_E3A_R1_BHCAN
|-----------------------------------------------------------------------------
*/

#define CAND_CONFIG_IF_OWNER

/*______ I N C L U D E - F I L E S ___________________________________________*/

#include "CAND.h"

/* Module inhibition filter */
#ifdef __CAND_IS_PRESENT__

/*______ G L O B A L - D E F I N E S _________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

/*______ L O C A L - D A T A _________________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

const CAND_MsgObject_t CAND_TxMsgObject[CAND_TX_MSG_NMB] =
{
/*+--------------------------------+----------------------------------------+---------------------------------------+------------------+-----------------------------------+
  |         message                |                  dlc                   |                  id                   |     direction    |                buffer             |
  |         handler                |                                        |                                       |                  |                Address            |
  +--------------------------------+----------------------------------------+---------------------------------------+------------------+-----------------------------------+ */
  { CAND_MAILBOX_0_HND,             CAND_STATUS_HMSM_DLC,                    CAND_STATUS_HMSM_ID,                    CAND_TX_CFG,       (uint8_t*)& (STATUS_HMSM)                    },
  { CAND_MAILBOX_0_HND,             CAND_NWM_HMSM_DLC,                       CAND_NWM_HMSM_ID,                       CAND_TX_CFG,       (uint8_t*)& (NWM_HMSM)                       },
  { CAND_MAILBOX_0_HND,             CAND_CFG_DATA_CODE_RSP_HMSM_DLC,         CAND_CFG_DATA_CODE_RSP_HMSM_ID,         CAND_TX_CFG,       (uint8_t*)& (CFG_DATA_CODE_RSP_HMSM)         },
  { CAND_MAILBOX_1_HND,             CAND_DIAGNOSTIC_RESPONSE_HMSM_DLC,       CAND_DIAGNOSTIC_RESPONSE_HMSM_ID,       CAND_TX_CFG,       (uint8_t*)& (DiagResponseBuf)                },
};

/* IMPORTANTE COSTRAINS: IL PRIMO HANDLER DEVE ESSERE SUBITO QUELLO SUCCESSIVO a L'ULTIMO DI TX
   E DEVONO CRESCERE IN MODO LINEARE */
const CAND_MsgObject_t CAND_RxMsgObject[CAND_RX_MSG_NMB] =
{
/*+--------------------------------+----------------------------------------+---------------------------------------+------------------+-----------------------------------+
  |         message                |                  dlc                   |                  id                   |     direction    |                buffer             |
  |         handler                |                                        |                                       |                  |                Address            |
    +--------------------------------+----------------------------------------+---------------------------------------+------------------+-----------------------------------+ */
  { CAND_MAILBOX_2_HND,             CAND_VIN_DLC,                            CAND_VIN_ID,                            CAND_RX_CFG,       (uint8_t*)& (VIN)                            },
  { CAND_MAILBOX_3_HND,             CAND_STATUS_CCAN3_DLC,                   CAND_STATUS_CCAN3_ID,                   CAND_RX_CFG,       (uint8_t*)& (STATUS_CCAN3)                   },
  { CAND_MAILBOX_4_HND,             CAND_STATUS_CLIMATE2_DLC,                CAND_STATUS_CLIMATE2_ID,                CAND_RX_CFG,       (uint8_t*)& (STATUS_CLIMATE2)                },
  { CAND_MAILBOX_5_HND,             CAND_STATUS_LIN_DLC,                     CAND_STATUS_LIN_ID,                     CAND_RX_CFG,       (uint8_t*)& (STATUS_LIN)                     },
  { CAND_MAILBOX_6_HND,             CAND_STATUS_MIRROR_DLC,                  CAND_STATUS_MIRROR_ID,                  CAND_RX_CFG,       (uint8_t*)& (STATUS_MIRROR)                  },
  { CAND_MAILBOX_7_HND,             CAND_TRIP_A_B_DLC,                       CAND_TRIP_A_B_ID,                       CAND_RX_CFG,       (uint8_t*)& (TRIP_A_B)                       },
  { CAND_MAILBOX_8_HND,             CAND_STATUS_BH_BCM1_DLC,                 CAND_STATUS_BH_BCM1_ID,                 CAND_RX_CFG,       (uint8_t*)& (STATUS_BH_BCM1)                 },
  { CAND_MAILBOX_9_HND,             CAND_CFG_DATA_CODE_REQUEST_DLC,          CAND_CFG_DATA_CODE_REQUEST_ID,          CAND_RX_CFG,       (uint8_t*)& (CFG_DATA_CODE_REQUEST)          },
  { CAND_MAILBOX_10_HND,            CAND_DIAG_REQ_FUNC_BH_C2_DLC,            CAND_DIAG_REQ_FUNC_BH_C2_ID,            CAND_RX_CFG,       (uint8_t*)& (DiagRequestBuf)                 },
  { CAND_MAILBOX_11_HND,            CAND_DIAG_REQ_PHYS_HMSM_DLC,             CAND_DIAG_REQ_PHYS_HMSM_ID,             CAND_RX_CFG,       (uint8_t*)& (DiagRequestBuf)                 },
  { CAND_MAILBOX_12_HND,            CAND_NWM_BCM_DLC,                        CAND_NWM_BCM_ID,                        CAND_RX_CFG,       (uint8_t*)& (NWM_BCM)                        },
  { CAND_MAILBOX_13_HND,            CAND_BCM_IGNITION_ON_COUNTER_DLC,        CAND_BCM_IGNITION_ON_COUNTER_ID,        CAND_RX_CFG,       (uint8_t*)& (BCM_IGNITION_ON_COUNTER)        },
  { CAND_MAILBOX_14_HND,            CAND_STATUS_BH_BCM2_DLC,                 CAND_STATUS_BH_BCM2_ID,                 CAND_RX_CFG,       (uint8_t*)& (STATUS_BH_BCM2)                 },
};


 /*______ P R I V A T E - M A C R O S _________________________________________*/
 
 /*______ G L O B A L - M A C R O S ___________________________________________*/
 
 /*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/
 
 
/**
 * @brief Initialization of can message signal (common signal) in TX ad RX direction
 */
#ifndef __CMMD_MULTI_DBC__
void CAND_DbcMsgInit(void)
{
/**
 * @brief Initialization of can message signal (common signal) in TX ad RX direction
 */
  /*NWM_HMSM initialization */
  /*Initialized by NWMA*/
  //NWM_HMSM.bit.Zero_byte_HMSM                          = CMMD_FIXED;
  //NWM_HMSM.bit.SystemStatus_HMSM                       = CMMD_STS_WAKE_UP;
  //NWM_HMSM.bit.ActiveLoadSlave_HMSM                    = CMMD_NO_ACTIVE_LOADS_IN_SLAVE;
  //NWM_HMSM.bit.EOL_HMSM                                = CMMD_NO_EOL_PROGRAMMING;
  //NWM_HMSM.bit.GenericFailSts_HMSM                     = CMMD_NO_FUNCTIONALFAILPRESENT;
  //NWM_HMSM.bit.CurrentFailSts_HMSM                     = CMMD_NO_FAIL_PRESENT;
  //NWM_HMSM.bit.D_ES_HMSM                               = CMMD_ERROR_ACTIVE_STATE;
  
  /*CFG_DATA_CODE_RSP_HMSM initialization */

  /*STATUS_HMSM initialization */
  STATUS_HMSM.bit.DataCmdReady                         = CMMD_NOT_READY;                  /*   0 = NOT_READY,1 = READY, */
  STATUS_HMSM.bit.MirrorDrvHorizzontalPosCmd           = 0U;                              /* 255 = SNA, */
  STATUS_HMSM.bit.MirrorDrvVerticalPosCmd              = 0U;                              /* 255 = SNA, */
  STATUS_HMSM.bit.MirrorPsngrHorizzontalPosCmd         = 0U;                              /* 255 = SNA, */
  STATUS_HMSM.bit.MirrorPsngrVerticalPosCmd            = 0U;                              /* 255 = SNA, */
  STATUS_HMSM.bit.Ack_beep                             = 0U;
  
  /*DIAGNOSTIC_RESPONSE_HMSM initialization */
  
  /*CFG_DATA_CODE_REQUEST initialization */
  
  /*DIAGNOSTIC_REQ_FUNC_BH_C2 initialization */
  
  /*DIAGNOSTIC_REQUEST_HMSM initialization */
  
  
  /************** Common RX messages initialization ****************/

  /*NWM_BCM initialization */
  NWM_BCM.bit.ActiveLoadMaster                         = CMMD_NO_ACTIVE_LOADS_IN_MASTER;       /* 0 = NO_ACTIVE_LOADS_IN_MASTER,1 = ACTIVE_LOADS_IN_MASTER, */
  NWM_BCM.bit.D_ES_BCM                                 = CMMD_ERROR_ACTIVE_STATE;              /* 0 = ERROR_ACTIVE_STATE,1 = ERROR_PASSIVE_WARNING_STATE,2 = BUS_OFF_STATE,3 = NOT_USED, */
  NWM_BCM.bit.EOL_BCM                                  = CMMD_NO_EOL_PROGRAMMING;              /* 0 = NO_EOL_PROGRAMMING,1 = EOL_PROGRAMMING, */
  NWM_BCM.bit.GenericFailSts_BCM                       = CMMD_NO_FUNCTIONALFAILPRESENT;        /* 0 = NO_FUNCTIONALFAILPRESENT,1 = FUNCTIONALFAILPRESENT, */
  NWM_BCM.bit.Node0                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node1                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node10                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node11                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node12                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node13                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node14                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node15                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node16                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node17                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node18                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node19                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node2                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node20                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node21                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node22                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node23                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node24                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node25                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node26                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node27                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node28                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node29                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node3                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node30                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node31                                   = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node4                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node5                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node6                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node7                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node8                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.Node9                                    = CMMD_NOT_ACTIVE;                      /* 0 = NOT_ACTIVE,1 = ACTIVE, */
  NWM_BCM.bit.P_ES                                     = CMMD_SPEED_FAIL_NOT_PRESENT;          /* 0 = FAIL_NOT_PRESENT,1 = FAIL_PRESENT, */
  NWM_BCM.bit.SystemCommand                            = CMMD_CMD_WAKE_UP;                     /* 0 = WAKE_UP,1 = NOT_USED,2 = STAYACTIVE,3 = SLEEP, */
  NWM_BCM.bit.Zero_byte_BCM                            = CMMD_FIXED;                           /* 0 = FIXED, */
  
  /*BCM_IGNITION_ON_COUNTER initialization */
  
  /*STATUS_BH_BCM2 initialization */
  STATUS_BH_BCM2.bit.CmdIgn_FailSts                    = CMMD_IGN_FAIL_NOT_PRESENT;                /* 0 = FAIL_NOT_PRESENT,1 = FAIL_PRESENT,3 = SNA, */
  STATUS_BH_BCM2.bit.CmdIgnSts                         = CMMD_INITIALIZATION;                  /* 0 = INITIALIZATION,1 = IGN_LK,3 = ACC,4 = RUN,5 = START,7 = SNA, */
  
  /*VIN initialization */
  VIN.bit.VIN_MSG                                      = CMMD_VIN_SNA;                             /* 0 = VIN_LO,1 = VIN_MID,2 = VIN_HI,3 = SNA, */
  
  /*STATUS_CCAN3 initialization */
  STATUS_CCAN3.bit.EngineSts                           = CMMD_ENGINE_SNA;                             /* 0 = ENGINE_OFF,1 = ENGINE_CRANKING,2 = ENGINE_ON,3 = SNA, */
  STATUS_CCAN3.bit.VehicleSpeedVSOSig_40to47           = 0U;
  STATUS_CCAN3.bit.VehicleSpeedVSOSig_55to51           = 0U;                                   /* 8191 = SNA, */
  STATUS_CCAN3.bit.VehicleSpeedVSOSigFailSts           = CMMD_SPEED_FAIL_NOT_PRESENT;               /* 0 = FAIL_NOT_PRESENT,1 = FAIL_PRESENT, */
  
  /*STATUS_CLIMATE2 initialization */
  STATUS_CLIMATE2.bit.HeatedLeft                       = CMMD_OFF_;                            /* 0 = OFF_,1 = LOW,2 = MEDIUM,3 = HIGH, */
  STATUS_CLIMATE2.bit.HeatedRight                      = CMMD_OFF_;                            /* 0 = OFF_,1 = LOW,2 = MEDIUM,3 = HIGH, */
  STATUS_CLIMATE2.bit.SteeringHeatedCmd                = CMMD_OFF;                             /* 0 = OFF,1 = ON, */
  STATUS_CLIMATE2.bit.VentilatedLeft                   = CMMD_OFF_;                            /* 0 = OFF_,1 = LOW,2 = MEDIUM,3 = HIGH, */
  STATUS_CLIMATE2.bit.VentilatedRight                  = CMMD_OFF_;                            /* 0 = OFF_,1 = LOW,2 = MEDIUM,3 = HIGH, */
  
  /*STATUS_LIN initialization */
  STATUS_LIN.bit.StW_TempSensSts                       = CMMD_NORMALOPERATION_OK;              /* 0 = NORMALOPERATION_OK,1 = SWTEMP__SENSORSHORTCIRCUIT_SHRT,2 = SWTEMP_SENSOROPENCIRCUIT_OPN,3 = SNA, */
  STATUS_LIN.bit.StW_TempSts                           = 0U;                              /* 255 = SNA, */
  
  /*STATUS_MIRROR initialization */
  STATUS_MIRROR.bit.MirrorDrvHorizzontalPosSts         = 0U;                              /* 255 = SNA, */
  STATUS_MIRROR.bit.MirrorDrvStandStillSts             = CMMD_STANDSTILL;                      /* 0 = STANDSTILL,1 = MOVING, */
  STATUS_MIRROR.bit.MirrorDrvVerticalPosSts            = 0U;                              /* 255 = SNA, */
  STATUS_MIRROR.bit.MirrorPsngrHorizzontalPosSts       = 0U;                              /* 255 = SNA, */
  STATUS_MIRROR.bit.MirrorPsngrStandStillSts           = CMMD_STANDSTILL;                      /* 0 = STANDSTILL,1 = MOVING, */
  STATUS_MIRROR.bit.MirrorPsngrVerticalPosSts_24to27   = 0U;                              /* 255 = SNA, */
  STATUS_MIRROR.bit.MirrorPsngrVerticalPosSts_39to36   = 0U;                              /* 255 = SNA, */
  
  /*TRIP_A_B initialization */
  
  /*STATUS_BH_BCM1 initialization */
  STATUS_BH_BCM1.bit.OperationalModeSts                = CMMD_OP_MODE_INITIALIZATION;     /* 0 = INITIALIZATION,1 = IGNITION_OFF_WITHOUTKEY,2 = IGNITION_OFF,3 = IGNITION_ACC,4 = IGNITION_ON,5 = IGNITION_PRE_START,6 = IGNITION_START,7 = IGNITION_CRANKING,8 = IGNITION_ON_ENGON,9 = IGNITION_PRE_ACC,10 = IGNITION_PRE_OFF,11 = AUTOMATIC_CRANKING,12 = AUTOMATIC_STOP,13 = KEY_AUTH */
  
}

#else

void CAND_FirstDbcMsgInit(void)
{
}

void CAND_SecondDbcMsgInit(void)
{
}

#endif /* __CMMD_MULTI_DBC__ */

#endif /* end __CAND_IS_PRESENT__ */


/*______ E N D _____ (CAND_config.c) _________________________________________*/
