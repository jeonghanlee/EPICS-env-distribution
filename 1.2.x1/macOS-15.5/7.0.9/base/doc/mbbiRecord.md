# Multi-Bit Binary Input Record (mbbi)

The normal use for the multi-bit binary input record is to read contiguous,
multiple bit inputs from hardware. The binary value represents a state from a
range of up to 16 states. The multi-bit input record interfaces with devices
that use more than one bit.

Most device support modules obtain values from hardware and place the value in
RVAL. For these device support modules record processing uses RVAL to determine
the current state (VAL is given a value between 0 and 15). Device support
modules may optionally read a value directly into VAL.

Soft device modules are provided to obtain input via database or channel access
links or via dbPutField or dbPutLink requests. Two soft device support modules
are provided: `Soft Channel` allows VAL to be an arbitrary unsigned short
integer. `Raw Soft Channel` reads the value into RVAL just like normal
device support modules.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The multi-bit binary input record has the standard fields for specifying under
what circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read and Convert Parameters

The device support routines obtain the record's input from the device or link
specified in the INP field. For records that obtain their input from devices,
the INP field must contain the address of the I/O card, and the DTYP field must
specify the proper device support module. Be aware that the address format
differs according to the I/O bus used.

Two soft device support modules can be specified in DTYP `Soft Channel` and
`Raw Soft Channel`.

`Raw Soft Channel` reads the value into RVAL,
upon which the normal conversion process is undergone. `Soft Channel`
reads any unsigned integer directly into VAL. For a soft mbbi record, the INP
field can be a constant, a database, or a channel access link. If INP is a
constant, then the VAL is initialized to the constant value but can be changed
at run-time via dbPutField or dbPutLink.

MASK is used by the raw soft channel read routine, and by typical device support
read routines, to select only the desired bits when reading the hardware
register.  It is initialized to ((1 << NOBT) - 1) by record
initialization.  The user can configure the NOBT field, but the device support
routines may set it, in which case the value given to it by the user is simply
overridden.   The device support routines may also override MASK or shift it
left by SHFT bits.   If MASK is non-zero, only the bits specified by MASK will
appear in RVAL.

Unless the device support routine specifies no conversion, RVAL is used to
determine VAL as follows:

1. RVAL is assigned to a temporary variable -- rval = RVAL
2. rval is shifted right SHFT number of bits.
3. A match is sought between rval and one of the state value fields, ZRVL-FFVL.

Each of the fields, ZRVL-FFVL, represents one of the possible sixteen states
(not all sixteen have to be used).

Alternatively, the input value can be read as a string, in which case, a match
is sought with one of the strings specified in the ZRST-FFST fields. Then RVAL
is set equal to the corresponding value for that string, and the conversion
process occurs.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current Value | ENUM | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| NOBT | Number of Bits | USHORT | Yes |   | Yes | No | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| SHFT | Shift | USHORT | Yes |   | Yes | Yes | No |
| ZRVL | Zero Value | ULONG | Yes |   | Yes | Yes | Yes |
| ONVL | One Value | ULONG | Yes |   | Yes | Yes | Yes |
| TWVL | Two Value | ULONG | Yes |   | Yes | Yes | Yes |
| THVL | Three Value | ULONG | Yes |   | Yes | Yes | Yes |
| FRVL | Four Value | ULONG | Yes |   | Yes | Yes | Yes |
| FVVL | Five Value | ULONG | Yes |   | Yes | Yes | Yes |
| SXVL | Six Value | ULONG | Yes |   | Yes | Yes | Yes |
| SVVL | Seven Value | ULONG | Yes |   | Yes | Yes | Yes |
| EIVL | Eight Value | ULONG | Yes |   | Yes | Yes | Yes |
| NIVL | Nine Value | ULONG | Yes |   | Yes | Yes | Yes |
| TEVL | Ten Value | ULONG | Yes |   | Yes | Yes | Yes |
| ELVL | Eleven Value | ULONG | Yes |   | Yes | Yes | Yes |
| TVVL | Twelve Value | ULONG | Yes |   | Yes | Yes | Yes |
| TTVL | Thirteen Value | ULONG | Yes |   | Yes | Yes | Yes |
| FTVL | Fourteen Value | ULONG | Yes |   | Yes | Yes | Yes |
| FFVL | Fifteen Value | ULONG | Yes |   | Yes | Yes | Yes |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the mbbi record either textually or
graphically. The ZRST-FFST fields contain strings describing one of the possible
states of the record. The `get_enum_str` and `get_enum_strs`
record routines retrieve these strings for the operator. `Get_enum_str`
gets the string corresponding to the value set in VAL, and `get_enum_strs` retrieves all the strings.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |
| ZRST | Zero String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONST | One String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| TWST | Two String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| THST | Three String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| FRST | Four String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| FVST | Five String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| SXST | Six String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| SVST | Seven String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| EIST | Eight String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| NIST | Nine String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| TEST | Ten String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ELST | Eleven String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| TVST | Twelve String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| TTST | Thirteen String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| FTST | Fourteen String | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| FFST | Fifteen String | STRING \[26\] | Yes |   | Yes | Yes | Yes |

### Alarm Parameters

The possible alarm conditions for multi-bit binary inputs are the SCAN, READ,
and state alarms. The state alarms are configured in the below severity fields.
These fields have the usual possible values for severity fields: NO\_ALARM,
MINOR, and MAJOR.

The AFTC field sets the time constant on a low-pass filter that delays the
reporting of limit alarms until the signal has been within the alarm range for
that number of seconds (the default AFTC value of zero retains the previous
behavior).

The unknown state severity (UNSV) field, if set to MINOR or MAJOR, triggers an
alarm when the record support routine cannot find a matching value in the state
value fields for `rval`.

The change of state severity (COSV) field triggers an alarm when any change of
state occurs, if set to MAJOR or MINOR.

The other fields, when set to MAJOR or MINOR, trigger an alarm when VAL equals
the corresponding state.

See [Alarm Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#alarm-specification)
for a complete explanation of record alarms and of the standard fields.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related
to alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| UNSV | Unknown State Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| COSV | Change of State Svr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| ZRSV | State Zero Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| ONSV | State One Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| TWSV | State Two Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| THSV | State Three Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| FRSV | State Four Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| FVSV | State Five Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| SXSV | State Six Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| SVSV | State Seven Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| EISV | State Eight Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| NISV | State Nine Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| TESV | State Ten Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| ELSV | State Eleven Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| TVSV | State Twelve Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| TTSV | State Thirteen Sevr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| FTSV | State Fourteen Sevr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| FFSV | State Fifteen Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| AFTC | Alarm Filter Time Constant | DOUBLE | Yes |   | Yes | Yes | No |

### Run-time Parameters

These parameters are used by the run-time code for processing the multi-bit
binary input.

ORAW is used by record processing to hold the prior RVAL for use in determining
when to post a monitor event for the RVAL field.

The LALM field implements the change of state alarm severity by holding the
value of VAL when the previous change of state alarm was issued.

MLST holds the value when the last monitor for value change was triggered.

SDEF is used by record support to save time if no states are defined.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ORAW | Prev Raw Value | ULONG | No |   | Yes | No | No |
| LALM | Last Value Alarmed | USHORT | No |   | Yes | No | No |
| MLST | Last Value Monitored | USHORT | No |   | Yes | No | No |
| SDEF | States Defined | SHORT | No |   | Yes | No | No |

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

#### init\_record

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. SVAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a device
support read routine is defined. If either does not exist, an error message is
issued and processing is terminated.

Clears MASK and then sets the NOBT low order bits.

If device support includes `init_record()`, it is called.

init\_common is then called to determine if any states are defined. If states are
defined, SDEF is set to TRUE.

#### process

See next section.

#### special

Calls init\_common to compute SDEF when any of the fields ZRVL, ... FFVL change
value.

#### get\_enum\_str

Retrieves ASCII string corresponding to VAL.

#### get\_enum\_strs

Retrieves ASCII strings for ZRST,...FFST.

#### put\_enum\_str

Checks if string matches ZRST,...FFST and if it does, sets VAL.

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. readValue is called. See ["Input Records"](#input-records) for more information.
3. If PACT has been changed to TRUE, the device support read routine has started
but has not completed reading a new input value. In this case, the processing
routine merely returns, leaving PACT TRUE.
4. Convert:
    - status=read\_mbbi
    - PACT = TRUE
    - `recGblGetTimeStamp()` is called.
    - If status is 0, then determine VAL
        - Set rval = RVAL
        - Shift rval right SHFT bits
    - If at least one state value is defined
        - Set UDF to TRUE
    - If RVAL is ZRVL,...,FFVL then set
        - VAL equals index of state
        - UDF set to FALSE
    - Else set VAL = undefined
        - Else set VAL = RVAL
    - Set UDF to FALSE
        - If status is 1, return 0
        - If status is 2, set status = 0
5. Check alarms. This routine checks to see if the new VAL causes the alarm status
and severity to change. If so, NSEV, NSTA and LALM are set.
6. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if MLST is not equal to VAL.
    - Monitors for RVAL are checked whenever other monitors are invoked.
    - NSEV and NSTA are reset to 0.
7. Scan forward link if necessary, set PACT FALSE, and return.

## Device Support

### Fields Of Interest To Device Support

Each input record must have an associated set of device support routines.

The primary responsibility of the device support routines is to obtain a new raw
input value whenever read\_mbbi is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| NOBT | Number of Bits | USHORT | Yes |   | Yes | No | No |
| VAL | Current Value | ENUM | Yes |   | Yes | Yes | Yes |
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
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the record is
being (added to, deleted from) an I/O event list. It must be provided for any
device type that can use the I/O Event scanner.

#### read\_mbbi

    read_mbbi(precord)

This routine must provide a new input value. It returns the following values:

- 0: Success. A new raw value is placed in RVAL. The record support module
determines VAL from RVAL, SHFT, and ZEVL ... FFVL.
- 2: Success, but don't modify VAL.
- Other: Error.

### Device Support For Soft Records

Two soft device support modules `Soft Channel` and `Raw Soft Channel` are provided for multi-bit binary input records not related to actual
hardware devices. The INP link type must be either CONSTANT, DB\_LINK, or
CA\_LINK.

#### Soft Channel

read\_mbbi always returns a value of 2, which means that no conversion is
performed.

If the INP link type is constant, then the constant value is stored into VAL by
`init_record()`, and UDF is set to FALSE. VAL can be changed via dbPut
requests. If the INP link type is PV\_LINK, then dbCaAddInlink is called by
`init_record()`.

read\_mbbi calls recGblGetLinkValue to read the current value of VAL. See [Soft
Input](Soft%0AInput.md).

If the return status of recGblGetLinkValue is zero, then read\_mbbi sets UDF to
FALSE. The status of recGblGetLinkValue is returned.

#### Raw Soft Channel

This module is like the previous except that values are read into RVAL, VAL is
computed from RVAL, and read\_mbbi returns a value of 0. Thus the record
processing routine will determine VAL in the normal way.
