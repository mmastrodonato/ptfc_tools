/********************************************************************************/
/* @F_PROJECT:          TESLA X                                                 */
/* F_NAME:              DOIFC_cfgIf  Digital Output with current(I) Feedback    */
/* @F_PURPOSE:                                                                  */
/* @F_CREATED_BY:       Matteo MASTRODONATO                                     */
/* @F_MPROC_TYPE:       Renesas 78kF0R1826-FC3                                  */
/* F_CREATION_DATE:     21/nov/2014                                             */
/* @F_CREATION_SITE:    Bitron S.p.A.      - Grugliasco (TO)                    */
/******************************************* (C) Copyright 2012 Bitron S.p.A. ***/
/*
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
|              Matteo MASTRODONATO                   Bitron S.p.A.
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date        Ver  Author  Description
| ----------  ---  ------  ----------------------------------------------------
| 21/giu/2013     0.1  Matteo MASTRODONATO
*/

#ifndef DOIFC_CFGIF_H_
#define DOIFC_CFGIF_H_

/*______ I N C L U D E - F I L E S ___________________________________________*/

/*______ G L O B A L - T Y P E S _____________________________________________*/

typedef enum DOIFC_Handle_e
{
  DOIFC_CmdHeatDrv,
  DOIFC_CmdHeatPass,
  DOIFC_CmdHeatSteer,
  DOIFC_HDL_MAX
} DOIFC_Handle_t;


/*______ G L O B A L - D E F I N E S _________________________________________*/

/*______ G L O B A L - D A T A _______________________________________________*/

/*______ P R I V A T E - M A C R O S _________________________________________*/

/*______ G L O B A L - M A C R O S ___________________________________________*/

/*______ G L O B A L - F U N C T I O N S - P R O T O T Y P E S _______________*/

/*______ E X T E R N A L - D A T A ___________________________________________*/


#endif /* DOIFC_CFGIF_H_ */
