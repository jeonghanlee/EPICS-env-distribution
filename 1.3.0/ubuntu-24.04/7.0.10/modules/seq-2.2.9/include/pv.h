/*************************************************************************\
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/* Definitions for EPICS sequencer message system-independent library (pv)
 * (NB, "pv" = "process variable").
 *
 * This is a simple layer which is specifically designed to provide the
 * facilities needed by the EPICS sequencer. Specific message systems are
 * expected to inherit from the pv classes.
 *
 * William Lupton, W. M. Keck Observatory
 */
#ifndef INCLpvh
#define INCLpvh

#include "shareLib.h"       /* reset share lib defines */

#include "pvAlarm.h"        /* status and severity definitions */
#include "pvType.h"         /* pv type definitions */

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

typedef enum {
    pvEventGet,
    pvEventPut,
    pvEventMonitor
} pvEventType;

typedef struct pvSystem pvSystem;
typedef struct pvVar pvVar;
typedef void pvConnFunc(int connected, void *arg);
typedef void pvEventFunc(pvEventType evt, void *arg, pvType type, unsigned count, pvValue *value, pvStat status);

/* structures must be allocated by client code */

struct pvSystem {
    struct ca_client_context *id;
    const char *msg;
};

struct pvVar {
    struct oldChannelNotify *chid;
    struct oldSubscription *monid;
    pvConnFunc *conn_handler;
    pvEventFunc *event_handler;
    void *arg;
    const char *msg;
};

#define pvSysIsDefined(x) ((x).id != NULL)
#define pvVarIsDefined(x) ((x).chid != NULL)
#define pvMonIsDefined(x) ((x).monid != NULL)

epicsShareExtern const struct pvSystem nullPvSys;
epicsShareExtern const struct pvVar nullPvVar;

epicsShareFunc pvStat pvSysCreate(pvSystem *pSys);
epicsShareFunc pvStat pvSysFlush(pvSystem sys);
epicsShareFunc pvStat pvSysAttach(pvSystem sys);

epicsShareFunc pvStat pvVarCreate(pvSystem sys, const char *name,
    pvConnFunc *conn_func, pvEventFunc *event_func, void *arg, pvVar *var);
epicsShareFunc pvStat pvVarDestroy(pvVar *var);
epicsShareFunc pvStat pvVarGetCallback(pvVar *var, pvType type, unsigned count, void *arg);
epicsShareFunc pvStat pvVarPutNoBlock(pvVar *var, pvType type, unsigned count, pvValue *value);
epicsShareFunc pvStat pvVarPutCallback(pvVar *var, pvType type, unsigned count, pvValue *value, void *arg);

epicsShareFunc pvStat pvVarMonitorOn(pvVar *var, pvType type, unsigned count, void *arg);
epicsShareFunc pvStat pvVarMonitorOff(pvVar *var);

epicsShareFunc unsigned pvVarGetCount(pvVar *var);

#define pvVarGetPrivate(var) (var).arg
#define pvVarGetMess(var) (var).msg
#define pvSysGetMess(sys) (sys).msg

epicsShareFunc pvStat pvTimeGetCurrentDouble(double *pTime);

#endif /* INCLpvh */
