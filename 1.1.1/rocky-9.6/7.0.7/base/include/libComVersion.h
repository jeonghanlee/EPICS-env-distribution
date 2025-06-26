/*************************************************************************\
* Copyright (c) 2017 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* SPDX-License-Identifier: EPICS
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

#ifndef INC_libComVersion_H
#define INC_libComVersion_H

#define EPICS_LIBCOM_MAJOR_VERSION 3
#define EPICS_LIBCOM_MINOR_VERSION 22
#define EPICS_LIBCOM_MAINTENANCE_VERSION 0
#define EPICS_LIBCOM_DEVELOPMENT_FLAG 0

#include <epicsVersion.h>

#define LIBCOM_VERSION_INT VERSION_INT(EPICS_LIBCOM_MAJOR_VERSION, \
    EPICS_LIBCOM_MINOR_VERSION, EPICS_LIBCOM_MAINTENANCE_VERSION, 0)

#endif /* INC_libComVersion_H */
