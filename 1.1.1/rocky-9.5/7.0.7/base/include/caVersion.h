/*************************************************************************\
* Copyright (c) 2017 UChicago Argonne LLC, as Operator of Argonne
*     National Laboratory.
* SPDX-License-Identifier: EPICS
* EPICS BASE is distributed subject to a Software License Agreement found
* in file LICENSE that is included with this distribution.
\*************************************************************************/

#ifndef INC_caVersion_H
#define INC_caVersion_H

#define EPICS_CA_MAJOR_VERSION 4
#define EPICS_CA_MINOR_VERSION 14
#define EPICS_CA_MAINTENANCE_VERSION 2
#define EPICS_CA_DEVELOPMENT_FLAG 0

#include <epicsVersion.h>

#define CA_VERSION_INT VERSION_INT(EPICS_CA_MAJOR_VERSION, \
    EPICS_CA_MINOR_VERSION, EPICS_CA_MAINTENANCE_VERSION, 0)

#endif /* INC_caVersion_H */
