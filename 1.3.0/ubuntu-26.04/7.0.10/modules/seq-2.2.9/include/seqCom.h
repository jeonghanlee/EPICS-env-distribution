/*************************************************************************\
Copyright (c) 1993      The Regents of the University of California
                        and the University of Chicago.
                        Los Alamos National Laboratory
Copyright (c) 2010-2015 Helmholtz-Zentrum Berlin f. Materialien
                        und Energie GmbH, Germany (HZB)
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/*	Public interface to the sequencer run-time library
 *
 *	Author:		Andy Kozubal
 *	Date:		01mar94
 *
 *	Experimental Physics and Industrial Control System (EPICS)
 *
 *	This software was produced under  U.S. Government contracts:
 *	(W-7405-ENG-36) at the Los Alamos National Laboratory,
 *	and (W-31-109-ENG-38) at Argonne National Laboratory.
 *
 *	Initial development by:
 *		The Controls and Automation Group (AT-8)
 *		Ground Test Accelerator
 *		Accelerator Technology Division
 *		Los Alamos National Laboratory
 */
#ifndef INCLseqComh
#define INCLseqComh

#include "epicsTypes.h"
#include "epicsThread.h"
#include "epicsTime.h"
#include "shareLib.h"

#include "pvAlarm.h"
#include "seq_release.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NOEVFLAG		0	/* argument to pvSync to remove sync */

#define DEFAULT_TIMEOUT		10.0	/* default timeout for SYNC operations */

/* I/O completion type (extra argument passed to seq_pvGet() and seq_pvPut()) */
enum compType {
	DEFAULT,
        ASYNC,
        SYNC
};

typedef	struct state_set *const SS_ID;	/* state set id, opaque */
typedef char string[MAX_STRING_SIZE];	/* representation of SNL string type */

/*
 * It is strongly advised to treat EF_ID and CH_ID as opaque;
 * in future versions they may be replaced by pointer types.
 */
typedef unsigned EF_ID;			/* identifier for an event */
typedef unsigned CH_ID;			/* identifier for a pv */

typedef int seqBool;

typedef struct seqProgram seqProgram;	/* struct defined in generated code */

/*
 * Function declarations for interface between state program & sequencer.
 * Prefix "seq_" is added by SNC to reduce probability of name clashes.
 * Implementations are in module seq_if.c.
 */

/* event flag operations */
epicsShareFunc void seq_efSet(SS_ID, EF_ID);
epicsShareFunc seqBool seq_efTest(SS_ID, EF_ID);
epicsShareFunc seqBool seq_efClear(SS_ID, EF_ID);
epicsShareFunc seqBool seq_efTestAndClear(SS_ID, EF_ID);
/* pv operations */
epicsShareFunc pvStat seq_pvGet(SS_ID, CH_ID, enum compType);
epicsShareFunc pvStat seq_pvGetTmo(SS_ID, CH_ID, enum compType, double tmo);
epicsShareFunc seqBool seq_pvGetQ(SS_ID, CH_ID);
epicsShareFunc void seq_pvFlushQ(SS_ID, CH_ID);
epicsShareFunc pvStat seq_pvPut(SS_ID, CH_ID, enum compType);
epicsShareFunc pvStat seq_pvPutTmo(SS_ID, CH_ID, enum compType, double tmo);
epicsShareFunc seqBool seq_pvGetComplete(SS_ID, CH_ID);
/* note: extra parameters retained for compatibility: */
epicsShareFunc seqBool seq_pvPutComplete(SS_ID, CH_ID,
	unsigned, seqBool, seqBool*);
epicsShareFunc void seq_pvGetCancel(SS_ID, CH_ID);
epicsShareFunc void seq_pvPutCancel(SS_ID, CH_ID);
epicsShareFunc pvStat seq_pvAssignSubst(SS_ID, CH_ID, const char *);
epicsShareFunc pvStat seq_pvAssign(SS_ID, CH_ID, const char *);
epicsShareFunc pvStat seq_pvMonitor(SS_ID, CH_ID);
epicsShareFunc void seq_pvSync(SS_ID, CH_ID, EF_ID);
epicsShareFunc pvStat seq_pvStopMonitor(SS_ID, CH_ID);
/* pv info */
epicsShareFunc char *seq_pvName(SS_ID, CH_ID);
epicsShareFunc unsigned seq_pvCount(SS_ID, CH_ID);
epicsShareFunc pvStat seq_pvStatus(SS_ID, CH_ID);
epicsShareFunc pvSevr seq_pvSeverity(SS_ID, CH_ID);
epicsShareFunc epicsTimeStamp seq_pvTimeStamp(SS_ID, CH_ID);
epicsShareFunc const char *seq_pvMessage(SS_ID, CH_ID);
epicsShareFunc seqBool seq_pvAssigned(SS_ID, CH_ID);
epicsShareFunc seqBool seq_pvConnected(SS_ID, CH_ID);

#define seq_pvIndex(ssId, chId)	chId

/* global operations */
epicsShareFunc void seq_pvFlush(SS_ID);
epicsShareFunc seqBool seq_delay(SS_ID, double);
epicsShareFunc char *seq_macValueGet(SS_ID, const char *);
epicsShareFunc void seq_exit(SS_ID);

/* global info */
epicsShareFunc unsigned seq_pvChannelCount(SS_ID);
epicsShareFunc unsigned seq_pvConnectCount(SS_ID);
epicsShareFunc unsigned seq_pvAssignCount(SS_ID);
epicsShareFunc seqBool seq_optGet(SS_ID, const char *);

/* shell commands */
epicsShareFunc void epicsShareAPI seqShow(epicsThreadId);
epicsShareFunc void epicsShareAPI seqChanShow(epicsThreadId, const char *);
epicsShareFunc void epicsShareAPI seqcar(int level);
epicsShareFunc void epicsShareAPI seqQueueShow(epicsThreadId);
epicsShareFunc void epicsShareAPI seqStop(epicsThreadId);
epicsShareFunc epicsThreadId epicsShareAPI seq(seqProgram *, const char *, unsigned);

/* backwards compatibility macros */
/* DEPRECATED don't use in new code */
typedef struct seqg_vars        USER_VAR;
#define UserVar			seqg_vars
#define ssId			seqg_env
#define pVar			seqg_var
#define VAR_ID			CH_ID
#define EV_ID			EF_ID
#define seq_pvFreeQ		seq_pvFlushQ
#define DEFAULT_QUEUE_SIZE	100	/* number of elements */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif	/*INCLseqComh*/
