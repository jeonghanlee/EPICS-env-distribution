# String Input Record (stringin)

The string input record retrieves an arbitrary ASCII string of up to 40
characters. Several device support routines are available, all of which are soft
device support for retrieving values from other records or other software
components.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The string input record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Input Specification

The INP field determines where the string input record gets its string. It can
be a database or channel access link, or a constant. If constant, the VAL field
is initialized with the constant and can be changed via dbPuts. Otherwise, the
string is read from the specified location each time the record is processed and
placed in the VAL field. The maximum number of characters that the string in VAL
can be is 40. In addition, the appropriate device support module must be entered
into the DTYP field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current Value | STRING \[40\] | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to specify when the monitor post should be sent by
`monitor()` routine. There are two possible choices:

#### Menu stringinPOST

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | stringinPOST\_OnChange | On Change |
| 1 | stringinPOST\_Always | Always |

APST is used for archiver monitors and MPST is for all other type of monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| MPST | Post Value Monitors | MENU [stringinPOST](#menu-stringinpost) | Yes |   | Yes | Yes | No |
| APST | Post Archive Monitors | MENU [stringinPOST](#menu-stringinpost) | Yes |   | Yes | Yes | No |

### Operator Display Parameters

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The string input record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Run-time Parameters

The old value field (OVAL) of the string input is used to implement value change
monitors for VAL. If VAL is not equal to OVAL, then monitors are triggered.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OVAL | Previous Value | STRING \[40\] | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML) is YES, the record is put in SIMS
severity and the value is fetched through SIOL (buffered in SVAL).
SSCN sets a different SCAN mechanism to use in simulation mode.
SDLY sets a delay (in sec) that is used for asynchronous simulation
processing.

See [Input Simulation Fields](dbCommonInput.md#Input-Simulation-Fields)
for more information on simulation mode and its fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Input Link | INLINK | Yes |   | Yes | Yes | No |
| SVAL | Simulation Value | STRING \[40\] | No |   | Yes | Yes | Yes |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

## Record Support

### Record Support Routines

#### init\_record

    long (*init_record)(struct dbCommon *precord, int pass)

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. SVAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a record
support read routine is defined. If either does not exist, an error message is
issued and processing is terminated.

If device support includes an `init_record()` routine it is called.

#### process

    long (*process)(struct dbCommon *precord)

See ["Record Processing"](#record-processing).

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. readValue is called. See ["Simulation Mode"](#simulation-mode) for more information on simulation
mode fields and how they affect input.
3. If PACT has been changed to TRUE, the device support read routine has started
but has not completed reading a new input value. In this case, the processing
routine merely returns, leaving PACT TRUE.
4. `recGblGetTimeStamp()` is called.
5. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if OVAL is not equal to VAL.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br>
    <hr>
    <br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each stringin input record must have an associated set of device support
routines. The primary responsibility of the device support routines is to obtain
a new ASCII string value whenever read\_stringin is called. The device support
routines are primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| VAL | Current Value | STRING \[40\] | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |

### Device Support Routines

Device support consists of the following routines:

#### report

    long report(int level)

This optional routine is called by the IOC command `dbior` and is passed the
report level that was requested by the user.
It should print a report on the state of the device support to stdout.
The `level` parameter may be used to output increasingly more detailed
information at higher levels, or to select different types of information with
different levels.
Level zero should print no more than a small summary.

#### init

    long init(int after)

This optional routine is called twice at IOC initialization time.
The first call happens before any of the `init_record()` calls are made, with
the integer parameter `after` set to 0.
The second call happens after all of the `init_record()` calls have been made,
with `after` set to 1.

#### init\_record

    long init_record(dbCommon *prec)

This routine is optional. If provided, it is called by the record support
`init_record()` routine.

#### get\_ioint\_info

    long get_ioint_info(int cmd, dbCommon *precord, IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### read\_stringin

    long read_stringin(stringinRecord *prec)

This routine must provide a new input value. It returns the following values:

- 0: Success. A new ASCII string is stored into VAL.
- Other: Error.

### Device Support for Soft Records

The `Soft Channel` module reads a value directly into VAL.

Device support for DTYP `getenv` is provided for retrieving strings from
environment variables.
`INST_IO` addressing `@<environment variable>` is used in the INP
link field to select the desired environment variable.
