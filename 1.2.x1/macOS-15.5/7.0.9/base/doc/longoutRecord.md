# Long Output Record (longout)

The normal use for the long output or "longout" record type is to store long
integer values of up to 32 bits and write them to hardware devices. The `Soft Channel` device support layer can also be used to write values to
other records via database or channel access links. The OUT field determines how
the record is used. The record supports alarm limits and graphics and control
limits.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The longout record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Desired Output Parameters

The record must specify where the desired output originates, i.e., the 32 bit
integer value it is to write. The output mode select (OMSL) field determines
whether the output originates from another record or from database access. When
set to `closed_loop`, the desired output is retrieved from the link
specified in the Desired Output Link (DOL) field (which can specify either a
database or channel access link) and placed into the VAL field. When set to
`supervisory`, the desired output can be written into the VAL field via
dpPuts at run-time.

A third type of value for the DOL field is a constant in which case, when the
record is initialized, the VAL field will be initialized with this constant
value.

The VAL field's value will be clipped within limits specified in the fields DRVH
and DRVL if these have been configured by the database designer:

    DRVL <= VAL <= DRVH

Note: These limits are only enforced as long as DRVH > DRVL. If they are not
set or DRVH <= DRVL they will not be used.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |
| DRVH | Drive High Limit | LONG | Yes |   | Yes | Yes | Yes |
| DRVL | Drive Low Limit | LONG | Yes |   | Yes | Yes | Yes |
| VAL | Desired Output | LONG | Yes |   | Yes | Yes | Yes |

### Write Parameters

The OUT link field determines where the record is to send its output. For
records that write values to hardware devices, the OUT output link field must
specify the address of the I/O card, and the DTYP field must specify the
name of the corresponding device support module.

For soft records, the OUT output link can be a constant, a database link, or a
channel access link. If the link is a constant, the result is no output. The
DTYP field must then specify the `Soft Channel` device support routine.

See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of hardware addresses and database links.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| OOPT | Output Execute Opt | MENU [longoutOOPT](#menu-longoutoopt) | Yes |   | Yes | Yes | No |
| OOCH | Output Exec. On Change (Opt) | MENU [menuYesNo](menuYesNo.md) | Yes | 1 | Yes | Yes | No |

#### Menu longoutOOPT

The OOPT field was added in EPICS 7.0.8.

It determines the condition that causes the output link to be
written to. It's a menu field that has six choices:

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | longoutOOPT\_Every\_Time | Every Time |
| 1 | longoutOOPT\_On\_Change | On Change |
| 2 | longoutOOPT\_When\_Zero | When Zero |
| 3 | longoutOOPT\_When\_Non\_zero | When Non-zero |
| 4 | longoutOOPT\_Transition\_To\_Zero | Transition To Zero |
| 5 | longoutOOPT\_Transition\_To\_Non\_zero | Transition To Non-zero |

- `Every Time` -- write output every time record is processed. (DEFAULT)
- `On Change` -- write output every time VAL changes.
- `When Zero` -- when record is processed, write output if VAL is zero.
- `When Non-zero` -- when record is processed, write output if VAL is
non-zero.
- `Transition To Zero` -- when record is processed, write output only if VAL
is zero and the last value was non-zero.
- `Transition To Non-zero` -- when record is processed, write output only if
VAL is non-zero and last value was zero.

#### Changes in OUT field when OOPT = On Change

The OOCH field was added in EPICS 7.0.8.

If OOCH is `YES` (its default value) and the OOPT field is `On Change`,
the record will write to the device support the first time the record gets
processed after its OUT link is modified, even when the output value has
not actually changed.

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the long output either textually or
graphically.

EGU is a string of up to 16 characters describing the units that the long output
measures. It is retrieved by the `get_units` record support routine.

The HOPR and LOPR fields set the upper and lower display limits for the VAL,
HIHI, HIGH, LOW, and LOLO fields. Both the `get_graphic_double` and `get_control_double` record support routines retrieve these fields.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | LONG | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | LONG | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The possible alarm conditions for long inputs are the SCAN, READ, INVALID, and
limit alarms. The SCAN and READ alarms are not configurable by the user because
their severity is always MAJOR. The INVALID alarm is called by the record
support routine when the record or device support routines cannot write the
record's output. The IVOA field specifies the action to take in this case.

The limit alarms are configured by the user in the HIHI, LOLO, HIGH, and LOW
fields using floating-point values. For each of these fields, there is a
corresponding severity field which can be either NO\_ALARM, MINOR, or MAJOR.

The HYST field sets an alarm deadband around each limit alarm.

For an explanation of the IVOA and IVOV fields, see
[Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields).

See [Alarm Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#alarm-specification)
for a complete explanation of record alarms and of the standard fields.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related
to alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| HIHI | Hihi Alarm Limit | LONG | Yes |   | Yes | Yes | Yes |
| HIGH | High Alarm Limit | LONG | Yes |   | Yes | Yes | Yes |
| LOW | Low Alarm Limit | LONG | Yes |   | Yes | Yes | Yes |
| LOLO | Lolo Alarm Limit | LONG | Yes |   | Yes | Yes | Yes |
| HHSV | Hihi Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HSV | High Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LSV | Low Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LLSV | Lolo Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HYST | Alarm Deadband | LONG | Yes |   | Yes | Yes | No |
| IVOA | INVALID output action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID output value | LONG | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the value
field. The monitors are sent when the value field exceeds the last monitored
field by the appropriate delta. If these fields have a value of zero, everytime
the value changes, a monitor will be triggered; if they have a value of -1,
everytime the record is scanned, monitors are triggered. The ADEL field is the
delta for archive monitors, and the MDEL field is the delta for all other types
of monitors. See ["Monitor Specification"](#monitor-specification) for a complete explanation of
monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | LONG | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | LONG | Yes |   | Yes | Yes | No |

### Run-time Parameters

The LALM, MLST, and ALST fields are used to implement the hysteresis factors for
monitor callbacks. Only if the difference between these fields and the
corresponding value field is greater than the appropriate delta (MDEL, ADEL,
HYST)--only then are monitors triggered. For instance, only if the difference
between VAL and MLST is greater than MDEL are the monitors triggered for VAL.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| LALM | Last Value Alarmed | LONG | No |   | Yes | No | No |
| ALST | Last Value Archived | LONG | No |   | Yes | No | No |
| MLST | Last Val Monitored | LONG | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML) is YES, the record is put in SIMS
severity and the value is written through SIOL.
SSCN sets a different SCAN mechanism to use in simulation mode.
SDLY sets a delay (in sec) that is used for asynchronous simulation
processing.

See [Output Simulation Fields](dbCommonOutput.md#Output-Simulation-Fields)
for more information on simulation mode and its fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SIML | Sim Mode Location | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIOL | Sim Output Specifctn | OUTLINK | Yes |   | Yes | Yes | No |
| SIMS | Sim mode Alarm Svrty | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

<div>
    <br><hr><br>
</div>

## Record Support

### Record Support Routines

#### init\_record

This routine initializes SIMM if SIML is a constant or creates a channel access
link if SIML is PV\_LINK. If SIOL is PV\_LINK a channel access link is created.

This routine next checks to see that device support is available. The routine
next checks to see if the device support write routine is defined.

If either device support or the device support write routine does not exist, an
error message is issued and processing is terminated.

If DOL is a constant, then VAL is initialized to its value and UDF is set to
FALSE. If DOL type is a PV\_LINK then dbCaAddInlink is called to create a channel
access link.

If device support includes `init_record()`, it is called.

#### process

See next section.

#### get\_units

Retrieves EGU.

#### get\_graphic\_double

Sets the upper display and lower display limits for a field. If the field is
VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else if the
field has upper and lower limits defined they will be used, else the upper and
lower maximum values for the field type will be used.

#### get\_control\_double

Sets the upper control and the lower control limits for a field. If the field is
VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else if the
field has upper and lower limits defined they will be used, else the upper and
lower maximum values for the field type will be used.

#### get\_alarm\_double

Sets the following values:

    upper_alarm_limit = HIHI
    upper_warning_limit = HIGH
    lower_warning_limit = LOW
    lower_alarm_limit = LOLO

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. If PACT is FALSE and OMSL is CLOSED\_LOOP recGblGetLinkValue is called to read
the current value of VAL. See ["Output Records"](#output-records) for more information. If the
return status of recGblGetLinkValue is zero then UDF is set to FALSE.
3. Check alarms. This routine checks to see if the new VAL causes the alarm status
and severity to change. If so, NSEV, NSTA and LALM are set. It also honors the
alarm hysteresis factor (HYST). Thus the value must change by more than HYST
before the alarm status and severity is lowered.
4. Check severity and write the new value. See
[Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields) for
information on how INVALID alarms affect output records.
5. If PACT has been changed to TRUE, the device support write output routine has
started but has not completed writing the new value. In this case, the
processing routine merely returns, leaving PACT TRUE.
6. Check to see if monitors should be invoked:
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if ADEL and MDEL conditions are
    met.
    - NSEV and NSTA are reset to 0.
7. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br><hr><br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each long output record must have an associated set of device support routines.
The primary responsibility of the device support routines is to output a new
value whenever write\_longout is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |

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
`init_record()` routine.

#### get\_ioint\_info

    get_ioint_info(int cmd,struct dbCommon *precord,IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### write\_longout

    write_longout(precord)

This routine must output a new value. It returns the following values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

The `Soft Channel` module writes the current value of VAL.

If the OUT link type is PV\_LINK, then dbCaAddInlink is called by
`init_record()`.

write\_longout calls recGblPutLinkValue to write the current value of VAL.

See ["Soft Output"](#soft-output) for a further explanation.
