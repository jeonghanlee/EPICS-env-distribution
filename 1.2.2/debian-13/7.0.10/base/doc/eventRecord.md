# Event Record (event)

The normal use for this record type is to post a soft-event and/or process a
forward link.
`Soft Channel` device support is provided to allow the soft-event name to be
read from an input link.
Hardware device support for this record can provide an interrupt handler routine
to trigger processing of the record when an I/O Intr event occurs.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The event record has the standard fields for specifying under what circumstances
it should be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#scan-fields).

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| SCAN  | Scan Mechanism             | MENU [menuScan](menuScan.md) | Yes |         | Yes  | Yes   | No    |
| PHAS  | Scan Phase                 | SHORT         | Yes |         | Yes  | Yes   | No    |
| EVNT  | Event Name                 | STRING \[40\] | Yes |         | Yes  | Yes   | No    |
| PRIO  | Scheduling Priority        | MENU [menuPriority](menuPriority.md) | Yes |         | Yes  | Yes   | No    |
| PINI  | Process at iocInit         | MENU [menuPini](menuPini.md) | Yes |         | Yes  | Yes   | No    |

### Event Name Parameters

The VAL field is a string (prior to the Base-3.15.1 release it was a short
integer) providing the name of an IOC soft-event.
This named soft-event gets posted whenever the record is processed.

When the soft-event name is known at design time, the VAL field should be set to
the name in a loaded database file.
Soft-event names do not have to be registered before use, a handle for the name
is automatically created and stored when a name is first seen and the same
handle returned later if the same name is re-used.

The EPVT field holds the handle for the soft-event named in the VAL field.
Looking up the handle for a soft-event name is fast and uses a hash table.

For records that use the default `Soft Channel` device support, the soft-event
name can be fetched through the INP field link, written to the VAL field and the
handle looked up during record processing.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| VAL   | Event Name To Post         | STRING \[40\] | Yes |         | Yes  | Yes   | No    |
| EPVT  | Event private              | NOACCESS      | No  |         | No   | No    | No    |

### Input Specification

The device support routines use the address in this record to obtain input.
For records that provide an interrupt handler, the INP field should specify the
address of the I/O card, and the DTYP field should specify a valid device
support module.

The address format differs according to the card type  used. See
[Address
Specification](https://docs.epics-controls.org/en/latest/process-database/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of hardware addresses and specifying links.

For soft records, the INP field can be a constant, a database link, or a channel
access link, and the DTYP field should be empty or set to `Soft Channel`.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| INP   | Input Specification        | INLINK        | Yes |         | Yes  | Yes   | No    |
| DTYP  | Device Type                | DEVICE        | Yes |         | Yes  | Yes   | No    |

### Operator Display Parameters

See [Fields Common to All Record Types](dbCommonRecord.md#operator-display-parameters)
for more on the record name (NAME) and description (DESC) fields.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| NAME  | Record Name                | STRING \[61\] | No  |         | Yes  | No    | No    |
| DESC  | Descriptor                 | STRING \[41\] | Yes |         | Yes  | Yes   | No    |

### Alarm Parameters

The Event record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#alarm-fields) lists other fields related to alarms
that are common to all record types.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| STAT  | Alarm Status               | MENU [menuAlarmStat](menuAlarmStat.md) | No  |     UDF | Yes  | No    | No    |
| SEVR  | Alarm Severity             | MENU [menuAlarmSevr](menuAlarmSevr.md) | No  |         | Yes  | No    | No    |
| AMSG  | Alarm Message              | STRING \[40\] | No  |         | Yes  | No    | No    |
| NSTA  | New Alarm Status           | MENU [menuAlarmStat](menuAlarmStat.md) | No  |         | Yes  | No    | No    |
| NSEV  | New Alarm Severity         | MENU [menuAlarmSevr](menuAlarmSevr.md) | No  |         | Yes  | No    | No    |
| NAMSG | New Alarm Message          | STRING \[40\] | No  |         | Yes  | No    | No    |
| ACKS  | Alarm Ack Severity         | MENU [menuAlarmSevr](menuAlarmSevr.md) | No  |         | Yes  | No    | No    |
| ACKT  | Alarm Ack Transient        | MENU [menuYesNo](menuYesNo.md) | Yes |     YES | Yes  | No    | No    |
| UDF   | Undefined                  | UCHAR         | Yes |       1 | Yes  | Yes   | Yes   |

### Simulation Mode Parameters

The following fields are used to operate the event record in the simulation
mode.
See [Fields Common to Input Record Types](dbCommonInput.md#input-simulation-fields)
for more information on these fields.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| SIOL  | Sim Input Specifctn        | INLINK        | Yes |         | Yes  | Yes   | No    |
| SVAL  | Simulation Value           | STRING \[40\] | No  |         | Yes  | Yes   | No    |
| SIML  | Sim Mode Location          | INLINK        | Yes |         | Yes  | Yes   | No    |
| SIMM  | Simulation Mode            | MENU [menuYesNo](menuYesNo.md) | No  |         | Yes  | Yes   | No    |
| SIMS  | Sim mode Alarm Svrty       | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |         | Yes  | Yes   | No    |
| SSCN  | Sim. Mode Scan             | MENU [menuScan](menuScan.md) | Yes |   65535 | Yes  | Yes   | No    |
| SDLY  | Sim. Mode Async Delay      | DOUBLE        | Yes |    -1.0 | Yes  | Yes   | No    |

## Record Support

### Record Support Routines

#### init\_record

This routine initializes SIMM with the value of SIML if SIML type is a CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. SVAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

If device support includes `init_record()`, it is called.

The string in VAL is converted to a soft-event handle in EPVT.

#### process

See next section.

#### special

When the VAL field is set, the new string is converted to a soft-event handle in
EPVT.

### Record Processing

Routine `process()` implements the following algorithm:

1. `readValue()` is called.
See [Input Records](dbCommonInput.md#input-records) for more information.
2. If PACT has changed to TRUE, the device support read routine has started
but has not completed reading a new soft-event name.
In this case, the processing routine returns immediately, leaving PACT TRUE.
3. Set PACT to TRUE.
4. Post the soft-event whose handle is in EPVT.
5. Check to see if monitors should be invoked.
Alarm monitors are invoked if the new alarm status or severity are non-zero.
6. Scan forward link if set, set PACT to FALSE, and return.

## Device Support

### Fields of Interest To Device Support

Each record must have an associated set of device support routines. The device
support routines are primarily interested in the following fields:

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| PACT  | Record active              | UCHAR         | No  |         | Yes  | No    | No    |
| DPVT  | Device Private             | NOACCESS      | No  |         | No   | No    | No    |
| UDF   | Undefined                  | UCHAR         | Yes |       1 | Yes  | Yes   | Yes   |
| NSEV  | New Alarm Severity         | MENU [menuAlarmSevr](menuAlarmSevr.md) | No  |         | Yes  | No    | No    |
| NSTA  | New Alarm Status           | MENU [menuAlarmStat](menuAlarmStat.md) | No  |         | Yes  | No    | No    |
| INP   | Input Specification        | INLINK        | Yes |         | Yes  | Yes   | No    |
| PRIO  | Scheduling Priority        | MENU [menuPriority](menuPriority.md) | Yes |         | Yes  | Yes   | No    |
| VAL   | Event Name To Post         | STRING \[40\] | Yes |         | Yes  | Yes   | No    |
| EPVT  | Event private              | NOACCESS      | No  |         | No   | No    | No    |

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
Level zero should print only a 1-line summary.

#### init

    long init(int after)

This optional routine is called twice at IOC initialization time.
The first call happens before any of the `init_record()` calls are made, with
the integer parameter `after` set to 0.
The second call happens after all of the `init_record()` calls have been made,
with `after` set to 1.

#### init\_record

    long init_record(precord)

This routine is optional. If provided, it is called by the record support
`init_record()` routine.

#### get\_ioint\_info

    long get_ioint_info(int cmd, struct dbCommon *precord, IOSCANPVT *ppvt)

This routine is called by the dbScan system each time the record is added
or deleted from an I/O event scan list.
`cmd` has the value (0, 1) if the record is being (added to, deleted from) an
I/O event list.
The `get_ioint_info` routine is optional, but must be provided by any device
support that implements `I/O Intr` scanning for the event record type.

#### read\_event

    long read_event(precord)

This routine returns the following values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

A `Soft Channel` device support module is available.
The INP link field is used to fetch the soft-event name.

The `read_event()` routine reads a string through INP and stores it in VAL,
then looks up the named soft-event handle and sets EPVT.

See [Input Records](dbCommonInput.md#input-records) for details on soft input.
