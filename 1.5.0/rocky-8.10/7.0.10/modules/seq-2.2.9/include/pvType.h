/*************************************************************************\
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/* Definitions for EPICS sequencer message system-independent types.
 *
 * William Lupton, W. M. Keck Observatory
 * Ben Franksen, HZB
 */

#ifndef INCLpvTypeh
#define INCLpvTypeh

#include "epicsTime.h"		/* for time stamps */
#include "epicsTypes.h"

#include "pvAlarm.h"		/* status and severity definitions */

/*
 * Enum for data types (very restricted set of types)
 */
typedef enum {
    pvTypeERROR       = -1,
    pvTypeCHAR        = 0,
    pvTypeSHORT       = 1,
    pvTypeLONG        = 2,
    pvTypeFLOAT       = 3,
    pvTypeDOUBLE      = 4,
    pvTypeSTRING      = 5,
    pvTypeTIME_CHAR   = 6,
    pvTypeTIME_SHORT  = 7,
    pvTypeTIME_LONG   = 8,
    pvTypeTIME_FLOAT  = 9,
    pvTypeTIME_DOUBLE = 10,
    pvTypeTIME_STRING = 11
} pvType;

/* these must correspond to corresponding types in db_access.h */
typedef epicsUInt8      pvChar;     /* dbr_char_t   */
typedef epicsInt16      pvShort;    /* dbr_short_t  */
typedef epicsInt32      pvLong;     /* dbr_long_t   */
typedef epicsFloat32    pvFloat;    /* dbr_float_t  */
typedef epicsFloat64    pvDouble;   /* dbr_double_t */
typedef epicsOldString  pvString;   /* dbr_string_t */

typedef void            pvValue;    /* abstract */

#define pv_is_simple_type(type)\
    ((type)>=pvTypeCHAR&&(type)<=pvTypeSTRING)
#define pv_is_time_type(type)\
    ((type)>=pvTypeTIME_CHAR&&(type)<=pvTypeTIME_STRING)
#define pv_is_valid_type(type)\
    ((type)>=pvTypeCHAR&&(type)<=pvTypeTIME_STRING)

#define pv_status(pv,type)\
    (assert(pv_is_time_type(type)),\
    (pvStat)*(epicsInt16 *)(((char *)pv)+pv_status_offsets[(type)-pvTypeTIME_CHAR]))
#define pv_severity(pv,type)\
    (assert(pv_is_time_type(type)),\
    (pvSevr)*(epicsInt16 *)(((char *)pv)+pv_severity_offsets[(type)-pvTypeTIME_CHAR]))
#define pv_stamp(pv,type)\
    (assert(pv_is_time_type(type)),\
    *(epicsTimeStamp *)(((char *)pv)+pv_stamp_offsets[(type)-pvTypeTIME_CHAR]))

#define pv_value_ptr(pv,type)\
    (assert(pv_is_valid_type(type)),(void *)(((char *)pv)+pv_value_offsets[type]))
#define pv_size(type)\
    (assert(pv_is_valid_type(type)),pv_sizes[type])
#define pv_size_n(type,count)\
    (assert(pv_is_valid_type(type)),\
    (count)<=0?pv_sizes[type]:pv_sizes[type]+((count)-1)*pv_value_sizes[type])

#ifdef __cplusplus
extern "C" {
#endif

epicsShareExtern const size_t pv_sizes[];
epicsShareExtern const size_t pv_value_sizes[];
epicsShareExtern const size_t pv_value_offsets[];
epicsShareExtern const size_t pv_status_offsets[];
epicsShareExtern const size_t pv_severity_offsets[];
epicsShareExtern const size_t pv_stamp_offsets[];

#ifdef __cplusplus
}
#endif

#endif /* INCLpvTypeh */
