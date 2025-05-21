# Binary Output Record (bo)

The normal use for this record type is to store a simple bit (0 or 1) value
to be sent to a Digital Output module. It can also be used to write binary
values into other records via database or channel access links. This record
can implement both latched and momentary binary outputs depending on how
the HIGH field is configured.

### Scan Parameters

The binary output record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |

### Desired Output Parameters

The binary output record must specify where its desired output originates.
The desired output needs to be in engineering units.

The first field that determines where the desired output originates is the
output mode select (OMSL) field, which can have two possible values:
`closed_loop` or `supervisory`. If `supervisory` is specified, the value
in the VAL field can be set externally via dbPuts at run-time. If
`closed_loop` is specified, the VAL field's value is obtained from the
address specified in the Desired Output Link (DOL) field which can be a
database link or a channel access link, but not a constant. To achieve
continuous control, a database link to a control algorithm record should be
entered in the DOL field.

See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on hardware addresses and links.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |

### Convert and Write Parameters

These parameters are used to determine where the binary output writes to
and how to convert the engineering units to a raw signal. After VAL is set
and forced to be either 1 or 0, as the result of either a dbPut or a new
value being retrieved from the link in the DOL field, then what happens
next depends on which device support routine is used and how the HIGH field
is configured.

If the `Soft Channel` device support routine is specified, then the device
support routine writes the VAL field's value to the address specified in
the OUT field. Otherwise, RVAL is the value written by the device support
routines after being converted.

If VAL is equal to 0, then the record processing routine sets RVAL equal to
zero. When VAL is not equal to 0, then RVAL is set equal to the value
contained in the MASK field. (MASK is set by the device support routines
and is of no concern to the user.) Also, when VAL is not 0 and after RVAL is
set equal to MASK, the record processing routine checks to see if the HIGH
field is greater than 0. If it is, then the routine will process the record
again with VAL set to 0 after the number of seconds specified by HIGH.
Thus, HIGH implements a momentary output which changes the state of the
device back to 0 after _N_ number of seconds.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| VAL | Current Value | ENUM | Yes |   | Yes | Yes | Yes |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| HIGH | Seconds to Hold High | DOUBLE | Yes |   | Yes | Yes | No |
| ZNAM | Zero Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONAM | One Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |

### Conversion Parameters

The ZNAM field has the string that corresponds to the 0 state, and the ONAM
field holds the string that corresponds to the 1 state. These fields, other
than being used to tell the operator what each state represents, are used
to perform conversions if the value fetched by DOL is a string. If it is,
VAL is set to the state which corresponds to that string. For instance, if the
value fetched is the string "Off" and the ZNAM string is "Off," then VAL is
set to 0.

After VAL is set, if VAL is equal to 0, then the record processing routine
sets RVAL equal to zero. When VAL is not equal to 0, then RVAL is set equal
to the value contained in the MASK field. (Mask is set by the device
support routines and is of no concern to the user.) Also when VAL is equal
to 1 and after RVAL is set equal to MASK, the record processing routine checks
to see if the HIGH field is greater than 0. If it is, then the routine
processes the record again with VAL=0 after the number of seconds specified
by HIGH. Thus, HIGH implements a latched output which changes the state of
the device or link to 1, then changes it back to 0 after _N_ number of seconds.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ZNAM | Zero Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONAM | One Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| HIGH | Seconds to Hold High | DOUBLE | Yes |   | Yes | Yes | No |

### Output Specification

The OUT field specifies where the binary output record writes its output.
It must specify the address of an I/O card if the record sends its output
to hardware, and the DTYP field must contain the corresponding device
support module. Be aware that the address format differs according to the
I/O bus used. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of hardware addresses.

Otherwise, if the record is configured to use the soft device support modules,
then it can be either a database link, a channel access link, or a constant. Be
aware that nothing will be written when OUT is a constant. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of the database and channel access addresses.
Also, see ["Device Support For Soft Records"](#device-support-for-soft-records) in this chapter for more on output
to other records.

### Operator Display Parameters

These parameters are used to present meaningful data to the operator, The
`get_enum_str()` record support routine can retrieve the state string
corresponding to the VAL's state. So, if the value is 1, `get_enum_str()`
will return the string in the ONAM field: and if 0, `get_enum_str()` will
return the ZNAM string.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ZNAM | Zero Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| ONAM | One Name | STRING \[26\] | Yes |   | Yes | Yes | Yes |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

These parameters are used to determine the binary output's alarm condition
and to determine the severity of that condition. The possible alarm
conditions for binary outputs are the SCAN, READ, INVALID and state alarms.
The user can configure the state alarm conditions using these fields.

The possible values for these fields are `NO_ALARM`, `MINOR`, and
`MAJOR`. The ZSV holds the severity for the zero state; OSV for the one
state. COSV is used to cause an alarm whenever the state changes between
states (0-1, 1-0) and its severity is configured as MINOR or MAJOR.

See [Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields) for more information on the IVOA and
IVOV fields. [Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related to alarms that are
common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ZSV | Zero Error Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| OSV | One Error Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| COSV | Change of State Sevr | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| IVOA | INVALID outpt action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID output value | USHORT | Yes |   | Yes | Yes | No |

### Run-Time Parameters

These parameters are used by the run-time code for processiong the binary
output. They are not configurable using a configuration tool. They
represent the current state of the binary output.

ORAW is used to determine if monitors should be triggered for RVAL at the
same time they are triggered for VAL.

MASK is given a value by the device support routines and should not concern
the user.

The RBV field is also set by device support. It is the actual read back
value obtained from the hardware itself or from the associated device
driver.

The ORBV field is used to decide if monitors should be triggered
for RBV at the same time monitors are triggered for changes in VAL.

The LALM field holds the value of the last occurrence of the change of
state alarm. It is used to implement the change of state alarm, and thus
only has meaning if COSV is MINOR or MAJOR.

The MLST is used by the `process()` record support routine to determine if
archive and value change monitors are invoked. They are if MLST is not
equal to VAL.

The WPDT field is a private field for honoring seconds to hold HIGH.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ORAW | prev Raw Value | ULONG | No |   | Yes | No | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| RBV | Readback Value | ULONG | No |   | Yes | No | No |
| ORBV | Prev Readback Value | ULONG | No |   | Yes | No | No |
| LALM | Last Value Alarmed | USHORT | No |   | Yes | No | No |
| MLST | Last Value Monitored | USHORT | No |   | Yes | No | No |
| RPVT | Record Private | NOACCESS | No |   | No | No | No |
| WDPT | Watch Dog Timer ID | NOACCESS | No |   | No | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML, if populated) is YES, the record is put
in SIMS severity and the unconverted value is written through SIOL.
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

## `init_record`

This routine initializes SIMM if SIML is a constant or creates a channel
access link if SIML is PV\_LINK. If SIOL is a PV\_LINK a channel access link
is created.

This routine next checks to see that device support is available. The
routine next checks to see if the device support write routine is defined.

If either device support or the device support write routine does not
exist, and error message is issued and processing is terminated.

If DOL is a constant, then VAL is initialized to 1 if its value is nonzero
or initialzed to 0 if DOL is zero, and UDF is set to FALSE.

If device support includes `init_record()`, it is called. VAL is set using
RVAL, and UDF is set to FALSE.

## `process`

See next section.

## `get_enum_str`

Retrieves ASCII string corresponding to VAL.

## `get_enum_strs`

Retrieves ASCII strings for ZNAM and ONAM.

## `put_enum_str`

Checks if string matches ZNAM or ONAM, and if it does, sets VAL.

## Record Processing

Routine process implements the following algorithm:

- 1.
Check to see that the appropriate device support module exists. If it
doesn't, an error message is issued and processing is terminated with
the PACT field still set to TRUE. This ensures that processes will no
longer be called for this record. Thus error storms will not occur.
- 2.
If PACT is FALSE

- If DOL holds a link and OMSL is `closed_loop`
    - get values from DOL
    - check for link alarm
    - force VAL to be 0 or 1
    - if MASK is defined
        - if VAL is 0 set RVAL = 0
    - else set RVAL = MASK

- 3.
Check alarms: This routine checks to see if the new VAL causes the alarm
status and severity to change. If so, NSEV, NSTA, and LALM are set.
- 4.
Check severity and write the new value. See [Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for more information on how INVALID alarms affect output.
- 5.
If PACT has been changed to TRUE, the device support write output routine
has started but has not completed writing the new value. in this case, the
processing routine merely returns, leaving PACT TRUE.
- 6.
Check WAIT. If VAL is 1 and WAIT is greater than 0, process again with a
VAL=0 after WAIT seconds.
- 7.
Check to see if monitors should be invoked.

- Alarm monitors are invoked if the alarm status or severity has changed.
- Archive and value change monitors are invoked if MLST is not equal to VAL.
- Monitors for RVAL and for RBV are checked whenever other monitors are
invoked.
- NSEV and NSTA are reset to 0.

- 8
Scan forward link if necessary, set PACT FALSE, and return

## Device support

### Fields Of Interest To Device Support

Each binary output record must have an associated set of device support
routines. The primary responsibility of the device support routines is to
write a new value whenever `write_bo()` is called. The device support routines
are primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| VAL | Current Value | ENUM | Yes |   | Yes | Yes | Yes |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | Yes | Yes |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| RBV | Readback Value | ULONG | No |   | Yes | No | No |

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

## `init_record(precord)`

This routine is optional. If provided, it is called by record support
`init_record()` routine. It should determine MASK if it is needed.

- 0: Success. RVAL modified (VAL will be set accordingly)
- 2: Success. VAL modified
- other: Error

## `get_ioint_info(int cmd, struct dbCommon *precord, IOSCANPVT *ppvt)`

This routine is called by the ioEventScan system each time the record is
added or deleted from an I/O event scan list. `cmd` has the value (0,1) if
the record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

## `write_bo(precord)`

This routine must output a new value. It returns the following values:

- 0: Success
- other: Error.

## Device Support For Soft Records

Two soft device support modules `Soft Channel` and `Raw Soft Channel` are
provided for output records not related to actual hardware devices. The OUT
link type must be either CONSTANT, DB\_LINK, or CA\_LINK.

### Soft Channel

This module writes the current value of VAL.

If the OUT link type is PV\_LINK, then `dbCaAddInlink()` is called by
`init_record()`. `init_record()` always returns a value of 2, which means
that no conversion will ever be attempted. `write_bo()` calls
`recGblPutLinkValue()` to write the current value of VAL. See ["Soft Output"](#soft-output)
for details.

### Raw Soft Channel

This module is like the previous except that it writes the current value of
RVAL
