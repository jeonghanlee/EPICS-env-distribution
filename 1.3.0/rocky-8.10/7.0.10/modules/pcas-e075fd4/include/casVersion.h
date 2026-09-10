#ifndef CASVERSION_H
#define CASVERSION_H

#include <epicsVersion.h>

#ifndef VERSION_INT
#  define VERSION_INT(V,R,M,P) ( ((V)<<24) | ((R)<<16) | ((M)<<8) | (P))
#endif

/* include generated headers with:
 *   EPICS_CAS_MAJOR_VERSION
 *   EPICS_CAS_MINOR_VERSION
 *   EPICS_CAS_MAINTENANCE_VERSION
 *   EPICS_CAS_DEVELOPMENT_FLAG
 */
#include <casVersionNum.h>

#define CAS_VERSION_INT VERSION_INT(EPICS_CAS_MAJOR_VERSION, EPICS_CAS_MINOR_VERSION, EPICS_CAS_MAINTENANCE_VERSION, 0)

#endif // CASVERSION_H
