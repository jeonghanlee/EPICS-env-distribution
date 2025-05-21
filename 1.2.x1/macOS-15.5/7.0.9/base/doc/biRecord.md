# Binary Input Record (bi)

This record type is normally used to obtain a binary value of 0 or 1. Most
device support modules obtain values from hardware and place the value in
RVAL. For these devices, record processing sets VAL = (0,1) if RVAL is (0,
not 0). Device support modules may optionally read a value directly from
VAL.

Soft device modules are provided to obtain input via database or channel
access links via dbPutField or dbPutLink requests. Two soft device support
modules are provided: `Soft Channel` and `Raw Soft Channel`. The first
allows VAL to be an arbitrary unsigned short integer. The second reads the
value into RVAL just like normal hardware modules.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The binary input record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |

### Read and Convert Parameters

The read and convert fields determine where the binary input gets its
input from and how to convert the raw signal to engineering units. The INP
field contains the address from where device support retrieves the value.
If the binary input record gets its value from hardware, the address of the
card must be entered in the INP field, and the name of the device support
module must be entered in the DTYP field. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of the hardware address.

For records that specify `Soft Channel` or `Raw Soft Channel` device
support routines, the INP field can be a channel or a database link, or a
constant. If a constant, VAL can be changed directly by dbPuts. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of database and
channel access addresses. Also, see ["Device Support for Soft Records"](#device-support-for-soft-records) in
this chapter for information on soft device support.

If the record gets its values from hardware or uses the `Raw Soft Channel`
device support, the device support routines place the value in the RVAL
field.
(Since 7.0.8) If the MASK field is non-zero, then this MASK is applied to RVAL.
The value from RVAL is then converted using the process described in the
next section.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| ZNAM | Zero Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONAM | One Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| VAL | Current Value | ENUM | Yes |   | Yes | Yes | Yes |

### Conversion Fields

The VAL field is set equal to (0,1) if the RVAL field is (0, not 0), unless
the device support module reads a value directly into VAL or the
`Soft Channel` device support is used. The value can also be fetched as one of
the strings specified in the ZNAM or ONAM fields. The ZNAM field has a
string that corresponds to the 0 state, so when the value is fetched as
this string, `put_enum_str()` will return a 0. The ONAM field hold the
string that corresponds to the 1 state, so when the value is fetched as
this string, `put_enum_str()` returns a 1.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ZNAM | Zero Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONAM | One Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. The
`get_enum_str()` record support routine can retrieve the state string
corresponding to the VAL's state. If the value is 1, `get_enum_str()` will
return the string in the ONAM field; and if 0, `get_enum_str()` will return
the ZNAM string.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ZNAM | Zero Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONAM | One Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

These parameters are used to determine if the binary input is in alarm
condition and to determine the severity of that condition. The possible
alarm conditions for binary inputs are the SCAN, READ state alarms, and the
change of state alarm. The SCAN and READ alarms are called by the device
supprt routines.

The user can choose the severity of each state in the ZSV and OSV fields.
The possible values for these fields are `NO_ALARM`, `MINOR`, and
`MAJOR`. The ZSV field holds the severity for the zero state; OSV, for
the one state.  COSV causes an alarm whenever the state changes between
0 and 1 and the severity is configured as MINOR or MAJOR.

See [Alarm Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#alarm-specification)
for a complete explanation of record alarms and of the standard fields.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related
to alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ZSV | Zero Error Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| OSV | One Error Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| COSV | Change of State Svr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |

### Run-time Parameters

These parameters are used by the run-time code for processing the binary
input. They are not configured using a database configuration tool.

ORAW is used to determine if monitors should be triggered for RVAL at the same
time they are triggered for VAL.

MASK is given a value by ithe device support routines. This value is used to
manipulate the record's value, but is only the concern of the hardware device
support routines.

The LALM fields holds the value of the last occurence of the change of
state alarm. It is used to implement the change of state alarm, and thus
only has meaning if COSV is MAJOR or MINOR.

The MSLT field is used by the `process()` record support routine to
determine if archive and value change monitors are invoked. They are if MSLT
is not equal to VAL.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ORAW | prev Raw Value | ULONG | No |   | Yes | No | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| LALM | Last Value Alarmed | USHORT | No |   | Yes | No | No |
| MLST | Last Value Monitored | USHORT | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML) is YES or RAW, the record is put in SIMS
severity and the value is fetched through SIOL (buffered in SVAL).
If SIMM is YES, SVAL is written to VAL without conversion,
if SIMM is RAW, SVAL is trancated to RVAL and converted.
SSCN sets a different SCAN mechanism to use in simulation mode.
SDLY sets a delay (in sec) that is used for asynchronous simulation
processing.

See [Input Simulation Fields](dbCommonInput.md#Input-Simulation-Fields)
for more information on simulation mode and its fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuSimm](menuSimm.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Input Link | INLINK | Yes |   | Yes | Yes | No |
| SVAL | Simulation Value | ULONG | No |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

## Record Support

### Record Support Routines

    long init_record(struct dbCommon *precord, int pass);

This routine initializes SIMM with the value of SIML if SIML type is a
CONSTANT link or creates a channel access link if SIML type is PV\_LINK.
SVAL is likewise initialized if SIOL is a CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a
device support routine is defined. If neither exist, an error is issued and
processing is terminated.

If device support includes `init_record()`, it is called.

    long process(struct dbCommon *precord);

See ["Record Processing"](#record-processing) below.

    long get_enum_str(const struct dbAddr *paddr, char *pbuffer);

Retrieves ASCII string corresponding to VAL.

    long get_enum_strs(const struct dbAddr *paddr, struct dbr_enumStrs *p);

Retrieves ASCII strings for ZNAM and ONAM.

    long put_enum_str(const struct dbAddr *paddr, const char *pbuffer);

Check if string matches ZNAM or ONAM, and if it does, sets VAL.

## Record Processing

Routine process implements the following algorithm:

- 1.
Check to see that the appropriate device support module exists. If it
doesn't, an error message is issued and processing is terminated with
the PACT field still set to TRUE. This ensures that processes will no
longer be called for this record. Thus error storms will not occur.
- 2.
`readValue()` is called. See ["Input Records"](#input-records) for details.
- 3.
If PACT has been changed to TRUE, the device support read routine has
started but has not completed reading a new input value. In this case, the
processing routine merely returns, leaving PACT TRUE.
- 4.
Convert.

- status = read\_bi
- PACT = TRUE
- `recGblGetTimeStamp()` is called.
- if status is 0, then set VAL=(0,1) if RVAL is (0, not 0) and UDF = False.
- if status is 2, set status = 0

- 5.
Check alarms: This routine checks to see if the new VAL causes the alarm
status and severity to change. If so, NSEV, NSTA and LALM are set. Note
that if VAL is greater than 1, no checking is performed.
- 6.
Check if monitors should be invoked:

- Alarm monitors are invoked if the alarm status or severity has changed.
- Archive and value change monitors are invoked if MSLT is not equal to VAL.
- Monitors for RVAL are checked whenever other monitors are invoked.
- NSEV and NSTA are reset to 0.

- 7.
Scan forward link if necessary, set PACT FALSE, and return.

## Device Support

### Fields of Interest to Device Support

Each binary input record must have an associated set of device support
routines. The primary resposibility of the device support routines is to
obtain a new raw input value whenever `read_bi()` is called. The device
support routines are primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| VAL | Current Value | ENUM | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |

### Device Support routines

Device support consists of the following routines:

    long report(int level);

This optional routine is called by the IOC command `dbior` and is passed the
report level that was requested by the user.
It should print a report on the state of the device support to stdout.
The `level` parameter may be used to output increasingly more detailed
information at higher levels, or to select different types of information with
different levels.
Level zero should print no more than a small summary.

    long init(int after);

This optional routine is called twice at IOC initialization time.
The first call happens before any of the `init_record()` calls are made, with
the integer parameter `after` set to 0.
The second call happens after all of the `init_record()` calls have been made,
with `after` set to 1.

    long init_record(struct dbCommon *precord);

This routine is optional. If provided, it is called by the record support
`init_record()` routine.

    long get_ioint_info(int cmd, struct dbCommon *precord, IOSCANPVT *ppvt);

This routine is called by the ioEventScan system each time the record is
added or deleted from an I/O event scan list. `cmd` has the value (0,1) if
the record is being (added to, deleted from) and I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

    long read_bi(struct dbCommon *precord);

This routine must provide a new input value. It returns the following
values:

- 0:
Success. A new raw value is placed in RVAL. The record support module
forces VAL to be (0,1) if RVAL is (0, not 0).
- 2:
Success, but don't modify VAL.
- Other:
Error.

### Device Support for Soft Records

Two soft device support modules, Soft Channel and Raw Soft Channel, are
provided for input records not related to actual hardware devices. The INP
link type must be either CONSTANT, DB\_LINK, or CA\_LINK.

### Soft Channel

`read_bi()` always returns a value of 2, which means that no conversion is
performed.

If the INP link type is CONSTANT, then the constant value is stored in VAL
by `init_record()`, and the UDF is set to FALSE. VAL can be changed via
`dbPut()` requests. If the INP link type is PV\_LINK, the `dbCaAddInlink()` is
called by `init_record()`.

`read_bi()` calls `dbGetLinkValue` to read the current value of VAL.
See ["Soft Input"](#soft-input) for details.

If the return status of `dbGetLinkValue()` is zero, then `read_bi()` sets
UDF to FALSE. The status of `dbGetLinkValue()` is returned.

### Raw Soft Channel

This module is like the previous except that values are read into RVAL.

`read_bi()` returns a value of 0. Thus the record processing routine will
force VAL to be 0 or 1.
