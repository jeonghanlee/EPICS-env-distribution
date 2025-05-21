# Long Input Record (longin)

The normal use for the long input record or "longin" record is to retrieve a
long integer value of up to 32 bits. Device support routines are provided to
support direct interfaces to hardware. In addition, the `Soft Channel`
device module is provided to obtain input via database or channel access links
or via dbPutField or dbPutLink requests.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The long input record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read Parameters

The device support routines use the INP field to obtain the record's input. For
records that obtain their input from devices, the INP field must contain the
address of the I/O card, and the DTYP field must specify the proper device
support module. Be aware that the address format differs according to the
I/O bus used.

For soft records, the INP can be a constant, a database link, or a channel
access link. The value is read directly into VAL. The `Soft Channel`
device support module is available for longin records.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current value | LONG | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. These
fields are used to display the value and other parameters of the long input
either textually or graphically.

EGU is a string of up to 16 characters describing the units that the long input
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

The possible alarm conditions for long inputs are the SCAN, READ, and limit
alarms. The SCAN and READ alarms are called by the record or device support
routines.

The HYST field controls hysteresis to prevent alarm chattering from an input
signal that is close to one of the limits and suffers from significant readout
noise.

The AFTC field sets the time constant on a low-pass filter that delays the
reporting of limit alarms until the signal has been within the alarm range for
that number of seconds (the default AFTC value of zero retains the previous
behavior).

The limit alarms are configured by the user in the HIHI, LOLO, HIGH, and LOW
fields using numerical values. For each of these fields, there is a
corresponding severity field which can be either NO\_ALARM, MINOR, or MAJOR. The
HYST field can be used to specify a deadband around each limit.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

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
| AFTC | Alarm Filter Time Constant | DOUBLE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the value
field. The monitors are sent when the value field exceeds the last monitored
field (see the next section) by the appropriate deadband. If these fields have a
value of zero, everytime the value changes, a monitor will be triggered; if they
have a value of -1, everytime the record is scanned, monitors are triggered. The
ADEL field is used by archive monitors and the MDEL field for all other types of
monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | LONG | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | LONG | Yes |   | Yes | Yes | No |

### Run-time Parameters

The LALM, MLST, and ALST fields are used to implement the hysteresis factors for
monitor callbacks. Only if the difference between these fields and the
corresponding value field is greater than the appropriate delta (MDEL, ADEL,
HYST) will monitors be triggered. For instance, only if the difference
between VAL and MLST is greater than MDEL are the monitors triggered for VAL.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| LALM | Last Value Alarmed | LONG | No |   | Yes | No | No |
| ALST | Last Value Archived | LONG | No |   | Yes | No | No |
| MLST | Last Val Monitored | LONG | No |   | Yes | No | No |

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
| SIML | Sim Mode Location | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIOL | Sim Input Specifctn | INLINK | Yes |   | Yes | Yes | No |
| SVAL | Simulation Value | LONG | No |   | Yes | Yes | No |
| SIMS | Sim mode Alarm Svrty | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
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
2. readValue is called. See ["Input Records"](#input-records) for more information.
3. If PACT has been changed to TRUE, the device support read routine has started
but has not completed reading a new input value. In this case, the processing
routine merely returns, leaving PACT TRUE.
4. Check alarms. This routine checks to see if the new VAL causes the alarm status
and severity to change. If so, NSEV, NSTA and LALM are set. It also honors the
alarm hysteresis factor (HYST). Thus the value must change by more than HYST
before the alarm status and severity is lowered.
5. Check to see if monitors should be invoked:
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if ADEL and MDEL conditions are
    met.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br><hr><br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each long input record must have an associated set of device support routines.
The primary responsibility of the device support routines is to obtain a new
input value whenever read\_longin is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| VAL | Current value | LONG | Yes |   | Yes | Yes | Yes |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |

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

#### read\_longin

    read_longin(precord)

This routine must provide a new input value. It returns the following values:

- 0: Success. A new value is placed in VAL.
- Other: Error.

### Device Support For Soft Records

The `Soft Channel` device support module places a value directly in VAL.

If the INP link type is constant, then the constant value is stored into VAL by
`init_record()`, and UDF is set to FALSE. If the INP link type is PV\_LINK, then
dbCaAddInlink is called by `init_record()`.

`read_longin` calls recGblGetLinkValue to read the current value of VAL.
See ["Soft Input"](#soft-input) for more information

If the return status of `recGblGetLinkValue` is zero then read\_longin
sets UDF to FALSE. read\_longin returns the status of `recGblGetLinkValue`.
