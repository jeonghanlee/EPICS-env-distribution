/*************************************************************************\
* Copyright (c) 2017 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* SPDX-License-Identifier: EPICS
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

#ifndef INC_databaseVersion_H
#define INC_databaseVersion_H

#define EPICS_DATABASE_MAJOR_VERSION 3
#define EPICS_DATABASE_MINOR_VERSION 24
#define EPICS_DATABASE_MAINTENANCE_VERSION 0
#define EPICS_DATABASE_DEVELOPMENT_FLAG 0

#include <epicsVersion.h>

#define DATABASE_VERSION_INT VERSION_INT(EPICS_DATABASE_MAJOR_VERSION, \
    EPICS_DATABASE_MINOR_VERSION, EPICS_DATABASE_MAINTENANCE_VERSION, 0)

#endif /* INC_databaseVersion_H */
