# Multi-Bit Binary Output Record (mbbo)

The normal use for the mbbo record type is to send a binary value (representing
one of up to 16 states) to a Digital Output module. It is used for any device
that uses more than one contiguous bit to control it. The mbbo record can also
be used to write discrete values to other records via database or channel access
links.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The mbbo record has the standard fields for specifying under what circumstances
it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Desired Output Parameters

The multi-bit binary output record, like all output records, must specify where
its output originates. The output mode select (OMSL) field determines whether
the output originates from another record or from database access (i.e., the
operator). When set to `closed_loop`, the desired output is retrieved
from the link specified in the desired output (DOL) field--which can specify
either a database or channel access link--and placed into the VAL field. When
set to `supervisory`, the DOL field is ignored and the current value of
VAL is simply written. VAL can be changed via dpPuts at run-time when OMSL is
`supervisory`. The DOL field can also be a constant, in which case the
VAL field is initialized to the constant value. If DOL is a constant, OMSL
cannot be set to `closed_loop`.

The VAL field itself usually consists of an index that specifies one of the
states. The actual output written is the value of RVAL, which is converted from
VAL following the routine explained in the next section. However, records that
use the `Soft Channel` device support module write the VAL field's value
without any conversion.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| VAL | Desired Value | ENUM | Yes |   | Yes | Yes | Yes |

### Convert and Write Parameters

The device support routines write the desired output to the location specified
in the OUT field. If the record uses soft device support, OUT can contain a
constant, a database link, or a channel access link; however, if OUT is a
constant, no value will be written.

For records that write their values to hardware devices, the OUT output link
must specify the address of the I/O card, and the DTYP field must specify
the corresponding device support module. Be aware that the address format
differs according to the I/O bus used.

For mbbo records that write to hardware, the value written to the output
location is the value contained in RVAL, which is converted from VAL, VAL
containing an index of one of the 16 states (0-15). RVAL is then set to the
corresponding state value, the value in one of the fields ZRVL through FFVL.
Then this value is shifted left according to the number in the SHFT field so
that the value is in the correct position for the bits being used (the SHFT
value is set by device support and is not configurable by the user).

The state value fields ZRVL through FFVL must be configured by the user before
run-time. When the state values are not defined, the states defined (SDEF) field
is set to FALSE at initialization time by the record routines. When SDEF is
FALSE, then the record processing routine does not try to find a match, RVAL is
set equal to VAL, the bits are shifted using the number in SHFT, and the value
is written thus.

If the OUT output link specifies a database link, channel access link, or
constant, then the DTYP field must specify either one of the two soft device
support modules-- `Soft Channel` or `Raw Soft Channel`. `Soft` `Channel` writes the value of VAL to the output link, without any
conversion, while `Raw Soft Channel` writes the value from RVAL after it
has undergone the above conversion.

Note also that when a string is retrieved as the desired output, a record
support routine is provided (`put_enum_str()`) that will check to see
if the string matches one of the strings in the ZRST through FFST fields. If a
match is found, RVAL is set equal to the corresponding state value of that
string.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| SHFT | Shift | USHORT | Yes |   | Yes | Yes | No |
| SDEF | States Defined | SHORT | No |   | Yes | No | No |
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

These parameters are used to present meaningful data to the operator. These
fields are used to display the value and other parameters of the mbbo record
either textually or graphically. The ZRST-FFST fields contain strings describing
each of the corresponding states. The `get_enum_str()` and
`get_enum_strs()` record routines retrieve these strings for the
operator. `get_enum_str()` gets the string corresponding to the value in
VAL, and `get_enum_strs()` retrieves all the strings.

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

The possible alarm conditions for multi-bit binary outputs are the SCAN, READ,
INVALID, and state alarms. The SCAN and READ alarms are called by the support
modules and are not configurable by the user, as their severity is always MAJOR.

The IVOA field specifies an action to take from a number of possible choices
when the INVALID alarm is triggered. The IVOV field contains a value to be
written once the INVALID alarm has been triggered if `Set output to IVOV`
has been chosen in the IVOA field. The severity of the INVALID alarm is not
configurable by the user.

The state alarms are configured in the below severity fields. These fields have
the usual possible values for severity fields: NO\_ALARM, MINOR, and MAJOR.

The unknown state severity field (UNSV), if set to MINOR or MAJOR, triggers an
alarm when the record support routine cannot find a matching value in the state
value fields for VAL or when VAL is out of range.

The change of state severity field (COSV) triggers an alarm when the record's
state changes, if set to MAJOR or MINOR.

The state severity (ZRSV-FFSV) fields, when set to MAJOR or MINOR, trigger an
alarm when VAL equals the corresponding field.

See [Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for an explanation of the IVOA and IVOV fields.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| UNSV | Unknown State Sevr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| COSV | Change of State Sevr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| IVOA | INVALID outpt action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID output value | USHORT | Yes |   | Yes | Yes | No |
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
| FFSV | State Fifteen Sevr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |

### Run-Time Parameters

These parameters are used by the run-time code for processing the multi-bit
binary output.

MASK is used by device support routine to read the hardware register. Record
support sets low order of MASK the number of bits specified in NOBT. Device
support can shift this value.

The LALM field implements the change of state alarm severity by holding the
value of VAL when the previous change of state alarm was issued.

MLST holds the value when the last monitor for value change was triggered.

SDEF is used by record support to save time if no states are defined; it is used
for converting VAL to RVAL.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NOBT | Number of Bits | USHORT | Yes |   | Yes | No | No |
| ORAW | Prev Raw Value | ULONG | No |   | Yes | No | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| LALM | Last Value Alarmed | USHORT | No |   | Yes | No | No |
| MLST | Last Value Monitored | USHORT | No |   | Yes | No | No |
| SDEF | States Defined | SHORT | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML, if populated) is YES, the record is put in SIMS
severity and the value is written through SIOL, without conversion.
If SIMM is RAW, the value is converted and RVAL is written.
SSCN sets a different SCAN mechanism to use in simulation mode.
SDLY sets a delay (in sec) that is used for asynchronous simulation
processing.

See [Output Simulation Fields](dbCommonOutput.md#Output-Simulation-Fields)
for more information on simulation mode and its fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuSimm](menuSimm.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Output Link | OUTLINK | Yes |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

## Record Support

### Record Support Routines

#### init\_record

This routine initializes SIMM if SIML is a constant or creates a channel access
link if SIML is PV\_LINK. If SIOL is PV\_LINK a channel access link is created.

This routine next checks to see that device support is available. The routine
next checks to see if the device support write routine is defined. If either
device support or the device support write routine does not exist, an error
message is issued and processing is terminated.

If DOL is a constant, then VAL is initialized to its value and UDF is set to
FALSE.

MASK is cleared and then the NOBT low order bits are set.

If device support includes `init_record()`, it is called.

init\_common is then called to determine if any states are defined. If states are
defined, SDEF is set to TRUE.

If device support returns success, VAL is then set from RVAL and UDF is set to
FALSE.

#### process

See next section.

#### special

Computes SDEF when any of the fields ZRVL,...FFVL change value.

#### get\_value

Fills in the values of struct valueDes so that they refer to VAL.

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
still set to TRUE. This ensures that processes will not longer be called for
this record. Thus error storms will not occur.
2. If PACT is FALSE
    - If DOL is DB\_LINK and OMSL is CLOSED\_LOOP
        - Get value from DOL
        - Set UDF to FALSE
        - Check for link alarm
    - If any state values are defined
        - If VAL > 15, then raise alarm and go to 4
        - Else using VAL as index set RVAL = one of ZRVL,...FFVL
    - Else set RVAL = VAL
    - Shift RVAL left SHFT bits
3. Convert
    - If PACT is FALSE, compute RVAL
        - If VAL is 0,...,15, set RVAL from ZRVL,...,FFVL
        - If VAL out of range, set RVAL = undefined
    - Status = write\_mbbo
4. Check alarms. This routine checks to see if the new VAL causes the alarm status
and severity to change. If so, NSEV, NSTA and LALM are set.
5. Check severity and write the new value. See
[Output Simulation Fields](dbCommonOutput.md#Output-Simulation-Fields) and 
[Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields) for
more information.
6. If PACT has been changed to TRUE, the device support write output routine has
started but has not completed writing the new value. In this case, the
processing routine merely returns, leaving PACT TRUE.
7. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if MLST is not equal to VAL.
    - Monitors for RVAL and RBV are checked whenever other monitors are invoked.
    - NSEV and NSTA are reset to 0.
8. Scan forward link if necessary, set PACT FALSE, and return.

## Device Support

### Fields Of Interest To Device Support

Each mbbo record must have an associated set of device support routines. The
primary responsibility of the device support routines is to obtain a new raw
mbbo value whenever write\_mbbo is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| NOBT | Number of Bits | USHORT | Yes |   | Yes | No | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| RBV | Readback Value | ULONG | No |   | Yes | No | No |
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

This routine is optional. If provided, it is called by the record support's
`init_record()` routine. If MASK is used, it should be shifted if necessary and SHFT
given a value.

#### get\_ioint\_info

    get_ioint_info(int cmd,struct dbCommon *precord,IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### write\_mbbo

    write_mbbo(precord)

This routine must output a new value. It returns the following values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

#### Soft Channel

The `Soft Channel` module writes the current value of VAL.

If the OUT link type is PV\_LINK, then dbCaAddInlink is called by
`init_record()`.

`write_mbbo()` calls `dbPutLink()` to write the current value of VAL. See
["Soft Output"](#soft-output) for more information.

#### Raw Soft Channel

This module writes RVAL to the location specified in the output link. It returns
a 0.
