#ifndef EPICS_RETOOLS_H
#define EPICS_RETOOLS_H

#include <shareLib.h>

#ifdef __cplusplus
extern "C" {
#endif

epicsShareFunc long reAddAlias(const char *pattern, const char *alias);
epicsShareFunc long reAddInfo(const char *pattern, const char *name,
        const char *value);
epicsShareFunc long rePutField(const char *pattern, const char *field,
        const char *value);
epicsShareFunc long reGetField(const char *pattern, const char *field);

#ifdef __cplusplus
}
#endif


#endif
