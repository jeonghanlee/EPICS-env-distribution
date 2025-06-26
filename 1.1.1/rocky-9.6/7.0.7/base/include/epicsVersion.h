/* Generated file epicsVersion.h */

#ifndef INC_epicsVersion_H
#define INC_epicsVersion_H

#define EPICS_VERSION        7
#define EPICS_REVISION       0
#define EPICS_MODIFICATION   7
#define EPICS_PATCH_LEVEL    0
#define EPICS_DEV_SNAPSHOT   ""
#define EPICS_SITE_VERSION   "github.com/jeonghanlee/EPICS-env"

#define EPICS_VERSION_SHORT  "7.0.7"
#define EPICS_VERSION_FULL   "7.0.7-github.com/jeonghanlee/EPICS-env"
#define EPICS_VERSION_STRING "EPICS 7.0.7-github.com/jeonghanlee/EPICS-env"
#define epicsReleaseVersion  "EPICS R7.0.7-github.com/jeonghanlee/EPICS-env"

#ifndef VERSION_INT
#  define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif
#define EPICS_VERSION_INT VERSION_INT(7, 0, 7, 0)

#endif /* INC_epicsVersion_H */
