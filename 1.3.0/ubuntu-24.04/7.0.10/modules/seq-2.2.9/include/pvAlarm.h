/*************************************************************************\
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/* Definitions for EPICS sequencer message system-independent status and
 * severity (alarms).
 *
 * William Lupton, W. M. Keck Observatory
 */

#ifndef INCLpvAlarmh
#define INCLpvAlarmh

/*
 * Status.
 */
typedef enum {
    /* generic OK and error statuses */
    pvStatOK           = 0,
    pvStatERROR        = -1,
    pvStatDISCONN      = -2,

    /* correspond to EPICS statuses */
    pvStatREAD	       = 1,
    pvStatWRITE        = 2,
    pvStatHIHI         = 3,
    pvStatHIGH         = 4,
    pvStatLOLO         = 5,
    pvStatLOW          = 6,
    pvStatSTATE	       = 7,
    pvStatCOS          = 8,
    pvStatCOMM         = 9,
    pvStatTIMEOUT      = 10,
    pvStatHW_LIMIT     = 11,
    pvStatCALC         = 12,
    pvStatSCAN         = 13,
    pvStatLINK         = 14,
    pvStatSOFT         = 15,
    pvStatBAD_SUB      = 16,
    pvStatUDF          = 17,
    pvStatDISABLE      = 18,
    pvStatSIMM         = 19,
    pvStatREAD_ACCESS  = 20,
    pvStatWRITE_ACCESS = 21
} pvStat;

/*
 * Severity.
 */
typedef enum {
    /* generic OK and error severities */
    pvSevrOK      = 0,
    pvSevrERROR   = -1,

    /* correspond to EPICS severities */
    pvSevrNONE    = 0,
    pvSevrMINOR   = 1,
    pvSevrMAJOR   = 2,
    pvSevrINVALID = 3
} pvSevr;

#endif /* INCLpvAlarmh */
