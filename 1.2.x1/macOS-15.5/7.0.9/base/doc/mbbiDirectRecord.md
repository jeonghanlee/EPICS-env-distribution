# Multi-Bit Binary Input Direct Record (mbbiDirect)

The mbbiDirect record retrieves a 32-bit hardware value and converts it to
an array of 32 unsigned characters, each representing a bit of the word.
These fields (B0-B9, BA-BF, B10-B19, B1A-B1F) are set to 1 if the corresponding
bit is set, and 0 if not.

This record's operation is similar to that of the
[multi-bit binary input record](mbbiRecord.md),
and it has many fields in common with it. This record also has two available
soft device support modules: `Soft Channel` and `Raw Soft Channel`.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The mbbiDirect record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read and Convert Parameters

The device support routines obtain the record's input from the device or link
specified in the INP field. For records that obtain their input from devices,
the INP field must contain the address of the I/O card, and the DTYP field
must specify the proper device support module. Be aware that the address format
differs according to the I/O bus used.

Two soft device support modules can be specified in DTYP `Soft Channel` and
`Raw Soft Channel`.

`Raw Soft Channel` reads the value into RVAL,
upon which the normal conversion process is undergone. `Soft Channel`
reads any unsigned integer directly into VAL. For a soft mbbiDirect record, the
INP field can be a constant, a database, or a channel access link. If INP is a
constant, then the VAL is initialized to the INP value but can be changed at
run-time via dbPutField or dbPutLink.

For records that don't use `Soft Channel` device support, RVAL is used to
determine VAL as follows:

- 1. RVAL is assigned to a temporary variable _rval_ = RVAL
- 2. _rval_ is shifted right SHFT number of bits.
- 3. VAL is set equal to _rval_.

Each of the fields, B0-BF and B10-B1F, represents one bit of the word.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current Value | LONG | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| SHFT | Shift | USHORT | Yes |   | Yes | Yes | No |
| B0 | Bit 0 | UCHAR | No |   | Yes | Yes | Yes |
| B1 | Bit 1 | UCHAR | No |   | Yes | Yes | Yes |
| B2 | Bit 2 | UCHAR | No |   | Yes | Yes | Yes |
| B3 | Bit 3 | UCHAR | No |   | Yes | Yes | Yes |
| B4 | Bit 4 | UCHAR | No |   | Yes | Yes | Yes |
| B5 | Bit 5 | UCHAR | No |   | Yes | Yes | Yes |
| B6 | Bit 6 | UCHAR | No |   | Yes | Yes | Yes |
| B7 | Bit 7 | UCHAR | No |   | Yes | Yes | Yes |
| B8 | Bit 8 | UCHAR | No |   | Yes | Yes | Yes |
| B9 | Bit 9 | UCHAR | No |   | Yes | Yes | Yes |
| BA | Bit 10 | UCHAR | No |   | Yes | Yes | Yes |
| BB | Bit 11 | UCHAR | No |   | Yes | Yes | Yes |
| BC | Bit 12 | UCHAR | No |   | Yes | Yes | Yes |
| BD | Bit 13 | UCHAR | No |   | Yes | Yes | Yes |
| BE | Bit 14 | UCHAR | No |   | Yes | Yes | Yes |
| BF | Bit 15 | UCHAR | No |   | Yes | Yes | Yes |
| B10 | Bit 16 | UCHAR | No |   | Yes | Yes | Yes |
| B11 | Bit 17 | UCHAR | No |   | Yes | Yes | Yes |
| B12 | Bit 18 | UCHAR | No |   | Yes | Yes | Yes |
| B13 | Bit 19 | UCHAR | No |   | Yes | Yes | Yes |
| B14 | Bit 20 | UCHAR | No |   | Yes | Yes | Yes |
| B15 | Bit 21 | UCHAR | No |   | Yes | Yes | Yes |
| B16 | Bit 22 | UCHAR | No |   | Yes | Yes | Yes |
| B17 | Bit 23 | UCHAR | No |   | Yes | Yes | Yes |
| B18 | Bit 24 | UCHAR | No |   | Yes | Yes | Yes |
| B19 | Bit 25 | UCHAR | No |   | Yes | Yes | Yes |
| B1A | Bit 26 | UCHAR | No |   | Yes | Yes | Yes |
| B1B | Bit 27 | UCHAR | No |   | Yes | Yes | Yes |
| B1C | Bit 28 | UCHAR | No |   | Yes | Yes | Yes |
| B1D | Bit 29 | UCHAR | No |   | Yes | Yes | Yes |
| B1E | Bit 30 | UCHAR | No |   | Yes | Yes | Yes |
| B1F | Bit 31 | UCHAR | No |   | Yes | Yes | Yes |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Run-time Parameters

These parameters are used by the run-time code for processing the mbbi direct
record. They are not configurable prior to run-time.

MASK is used by device support routine to read hardware register. Record support
sets low order NOBT bits in MASK. Device support can shift this value.

MLST holds the value when the last monitor for value change was triggered.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NOBT | Number of Bits | SHORT | Yes |   | Yes | No | No |
| ORAW | Prev Raw Value | ULONG | No |   | Yes | No | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| MLST | Last Value Monitored | LONG | No |   | Yes | No | No |

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
| SVAL | Simulation Value | LONG | No |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

### Alarm Parameters

The possible alarm conditions for multi-bit binary input direct records are the
SCAN and READ alarms. These alarms are not configurable by the user since they
are always of MAJOR severity. No fields exist for the mbbi direct record
to have state alarms.

[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

## Record Support

### Record Support Routines

#### init\_record

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. SVAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a device
support read routine is defined. If either does not exist, an error message is
issued and processing is terminated.

Clears MASK and then sets the NOBT low order bits.

If device support includes `init_record()`, it is called.

refresh\_bits is then called to refresh all the bit fields based on a hardware
value.

#### process

See next section.

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. readValue is called. See ["Output Records"](#output-records) for information.
3. If PACT has been changed to TRUE, the device support read routine has started
but has not completed reading a new input value. In this case, the processing
routine merely returns, leaving PACT TRUE.
4. Convert.
    - status = read\_mbbiDirect
    - PACT = TRUE
    - `recGblGetTimeStamp()` is called.
    - If status is 0, then determine VAL
        - Set rval = RVAL
        - Shift rval right SHFT bits
        - Set VAL = RVAL
    - If status is 1, return 0
    - If status is 2, set status = 0
5. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if MLST is not equal to VAL.
    - Monitors for RVAL are checked whenever other monitors are invoked.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br><hr><br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each input record must have an associated set of device support routines.

The primary responsibility of the device support routines is to obtain a new raw
input value whenever read\_mbbiDirect is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| NOBT | Number of Bits | SHORT | Yes |   | Yes | No | No |
| VAL | Current Value | LONG | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| SHFT | Shift | USHORT | Yes |   | Yes | Yes | No |

### Device Support Routines

Device support consists of the following routines:

#### long report(int level)

This optional routine is called by the IOC command `dbior` and is passed the
report level that was requested by the user.
It should print a report on the state of the device support to stdout.
The `level` parameter may be used to output increasingly more detailed
information at higher levels, or to select different types of information with
different levels.
Level zero should print no more than a small summary.

#### long init(int after)

This optional routine is called twice at IOC initialization time.
The first call happens before any of the `init_record()` calls are made, with
the integer parameter `after` set to 0.
The second call happens after all of the `init_record()` calls have been made,
with `after` set to 1.

#### init\_record

    init_record(precord)

This routine is optional. If provided, it is called by the record support
`init_record()` routine. If it uses MASK, it should shift it as necessary and
also give SHFT a value.

#### get\_ioint\_info

    get_ioint_info(int cmd,struct dbCommon *precord,IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### read\_mbbiDirect

    read_mbbiDirect(precord)

This routine must provide a new input value. It returns the following values:

- 0: Success. A new raw value is placed in RVAL. The record support module
determines VAL from RVAL and SHFT.
- 2: Success, but don't modify VAL.
- Other: Error.

### Device Support For Soft Records

Two soft device support modules, `Soft Channel` and `Raw Soft Channel`, are provided for multi-bit binary input direct records not related to
actual hardware devices. The INP link type must be either CONSTANT, DB\_LINK, or
CA\_LINK.

#### Soft Channel

For this module, read\_mbbiDirect always returns a value of 2, which means that
no conversion is performed.

If the INP link type is constant, then the constant value is stored into VAL by
`init_record()`, and UDF is set to FALSE. VAL can be changed via dbPut
requests. If the INP link type is PV\_LINK, then dbCaAddInlink is called by
`init_record()`.

read\_mbbiDirect calls recGblGetLinkValue to read the current value of VAL.

See ["Input Records"](#input-records) for a further explanation.

If the return status of recGblGetLinkValue is zero, then read\_mbbi sets UDF to
FALSE. The status of recGblGetLinkValue is returned.

#### Raw Soft Channel

This module is like the previous except that values are read into RVAL, VAL is
computed from RVAL, and read\_mbbiDirect returns a value of 0. Thus the record
processing routine will determine VAL in the normal way.
