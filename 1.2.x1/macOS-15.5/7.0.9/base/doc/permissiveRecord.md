# Permissive Record (permissive)

The permissive record is for communication between a server and a client. An
example would be a sequence program server and an operator interface client.  By
using multiple permissive records a sequence program can communicate its current
state to the client.

**Note this record is deprecated and may be removed in a future EPICS release.**

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The permissive record has the standard fields for specifying under what
circumstances the record will be processed. These fields are listed in
[Scan Fields](dbCommonRecord.md#Scan-Fields).

### Client-server Parameters

The client and server communicate through the VAL and watchdog flag (WFLG)
fields. At initialization, both fields are set equal to 0, which means OFF. The
server sets WFLG equal to ON when it is ready to accept a request. The client
monitors WFLG and when WFLG equals 1, the client-server action is performed (a
private matter between server and client).

When WFLG is off--when the server is busy--the client program may turn the VAL
field from OFF to ON. After the server finishes its task, it will notice that
VAL is ON and will turn both WFLG and VAL OFF and performs the requested
service.

Note that when WFLG is ON, the client program ''must not'' turn VAL to on.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Status | USHORT | Yes |   | Yes | Yes | Yes |
| WFLG | Wait Flag | USHORT | No |   | Yes | Yes | Yes |

### Operator Display Parameters

The label field (LABL) contains a string given to it that should describe the
record in further detail. In  addition to the DESC field. See
["Fields Common to All Record Types"](#fields-common-to-all-record-types) for more on the record name (NAME) and
description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| LABL | Button Label | STRING \[20\] | Yes |   | Yes | Yes | Yes |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The Permissive record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Run-time Parameters

These fields are used to trigger monitors for each field. Monitors for the VAL
field are triggered when OVAL, the old value field, does not equal VAL.
Likewise, OFLG causes monitors to be invoked for WFLG when WFLG does not equal
OLFG.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OVAL | Old Status | USHORT | No |   | Yes | No | No |
| OFLG | Old Flag | USHORT | No |   | Yes | No | No |

## Record Support

### Record Support Routines

#### process

    long (*process)(struct dbCommon *precord)

`process()` sets UDF to FALSE, triggers monitors on VAL and WFLG when
they change, and scans the forward link if necessary.
