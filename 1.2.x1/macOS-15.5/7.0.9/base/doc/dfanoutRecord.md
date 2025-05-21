# Data Fanout Record (dfanout)

The Data Fanout or "dfanout" record is used to forward data to up to
eight other records. It's similar to the fanout record except that the
capability to forward data has been added to it. If has no associated
device support.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The data fanout record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Desired Output Parameters

The data fanout record must specify where the desired output value
originates, i.e., the data which is to be fowarded to the records in its
output links. The output mode select (OMSL) field determines whether the
output originates from another record or from run-time database access.
When set to `closed_loop`, the desired output is retrieved from the link
specified in the Desired Output Link (DOL) field, which can specify either a
database or a channel access link, and placed into the VAL field. When set
to `supervisory`, the desired output can be written to the VAL field via
dbPuts at run-time.

The DOL field can also be a constant in which case the VAL field is
initialized to the constant value.

Note that there are no conversion parameters, so the desired output value
undergoes no conversions before it is sent out to the output links.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |
| VAL | Desired Output | DOUBLE | Yes |   | Yes | Yes | Yes |

### Write Parameters

The OUTA-OUTH fields specify where VAL is to be sent. Each field that is to
forward data must specify an address to another record. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on specifying links.

The SELL, SELM, and SELN fields specify which output links are to be
used.

#### Menu dfanoutSELM

SELM is a menu, with three choices:

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | dfanoutSELM\_All | All |
| 1 | dfanoutSELM\_Specified | Specified |
| 2 | dfanoutSELM\_Mask | Mask |

If SELM is `All`, then all output links are used, and the values of
SELL and SELN are ignored.

If SELM is `Specified`, then the value of SELN is used to specify a single
link which will be used. If SELN==0, then no link will be used; if SELN==1,
then OUTA will be used, and so on.

SELN can either have its value set directly, or have it retrieved from
another EPICS PV. If SELL is a valid PV link, then SELN will be read from
the linked PV.

If SELM is `Mask`, then SELN will be treated as a bit mask. If bit zero
(the LSB) of SELN is set, then OUTA will be written to; if bit one is set,
OUTB will be written to, and so on. Thus when SELN==5, both OUTC and OUTA
will be written to.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SELL | Link Selection Loc | INLINK | Yes |   | Yes | Yes | No |
| SELM | Select Mechanism | MENU [dfanoutSELM](#menu-dfanoutselm) | Yes |   | Yes | Yes | No |
| SELN | Link Selection | USHORT | No | 1 | Yes | Yes | No |
| OUTA | Output Spec A | OUTLINK | Yes |   | Yes | Yes | No |
| OUTB | Output Spec B | OUTLINK | Yes |   | Yes | Yes | No |
| OUTC | Output Spec C | OUTLINK | Yes |   | Yes | Yes | No |
| OUTD | Output Spec D | OUTLINK | Yes |   | Yes | Yes | No |
| OUTE | Output Spec E | OUTLINK | Yes |   | Yes | Yes | No |
| OUTF | Output Spec F | OUTLINK | Yes |   | Yes | Yes | No |
| OUTG | Output Spec G | OUTLINK | Yes |   | Yes | Yes | No |
| OUTH | Output Spec H | OUTLINK | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator.
They do not affect the functioning of the record at all.

- NAME is the record's name, and can be useful when the PV name that a client
knows is an alias for the record.
- DESC is a string that is usually used to briefly describe the record.
- EGU is a string of up to 16 characters naming the engineering units that the VAL
field represents.
- The HOPR and LOPR fields set the upper and lower display limits for the VAL,
HIHI, HIGH, LOW, and LOLO fields.
- The PREC field determines the floating point precision (i.e. the number of
digits to show after the decimal point) with which to display VAL and the other
DOUBLE fields.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more about the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |

### Alarm Parameters

The possible alarm conditions for data fanouts are the SCAN, READ, INVALID,
and limit alarms. The SCAN and READ alarms are called by the record
routines. The limit alarms are configured by the user in the HIHI, LOLO,
HIGH, and LOW fields using floating point values. The limit alarms apply 
only to the VAL field. The severity for each of these limits is specified
in the corresponding field (HHSV, LLSV, HSV, LSV) and can be either
NO\_ALARM, MINOR, or MAJOR. In the hysteresis field (HYST) can be entered a
number which serves as the deadband on the limit alarms.

See [Alarm Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#alarm-specification)
for a complete explanation of record alarms and of the standard fields.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related
to alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| HIHI | Hihi Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| HIGH | High Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| LOW | Low Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| LOLO | Lolo Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| HHSV | Hihi Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HSV | High Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LSV | Low Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LLSV | Lolo Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HYST | Alarm Deadband | DOUBLE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the
VAL field. These monitors are sent when the value field exceeds the last
monitored fields by the specified deadband, ADEL for archivers monitors and
MDEL for all other types of monitors. If these fields have a value of zero,
everytime the value changes, a monitor will be triggered; if they have a
value of -1, everytime the record is scanned, monitors are triggered. See
["Monitor Specification"](#monitor-specification) for a complete explanation of monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | DOUBLE | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | DOUBLE | Yes |   | Yes | Yes | No |

### Run-Time Parameters and Simulation Mode Parameters

These parameters are used by the run-time code for processing the data
fanout record. Ther are not configurable. They are used to implement the
hysteresis factors for monitor callbacks.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| LALM | Last Value Alarmed | DOUBLE | No |   | Yes | No | No |
| ALST | Last Value Archived | DOUBLE | No |   | Yes | No | No |
| MLST | Last Val Monitored | DOUBLE | No |   | Yes | No | No |

## Record Support

### Record Support Routines

## `init_record()`

This routine initializes all output links that are defined. Then it initializes
DOL if DOL is a constant or a PV\_LINK. When initializing the output links
and the DOL link, a non-zero value is returned if an error occurs.

## `process()`

See next section.

## `get_units()`

The routine copies the string specified in the EGU field to the location
specified by a pointer which is passed to the routine.

## `get_graphic_double()`

If the referenced field is VAL, HIHI, HIGH, LOW, or LOLO, this routine sets
the `upper_disp_limit` member of the `dbr_grDouble` structure to the
HOPR and the `lower_disp_limit` member to the LOPR. If the referenced
field is not one of the above fields, then `recGblGetControlDouble()`
routine is called.

## `get_control_double()`

Same as the `get_graphic_double()` routine except that it uses the
`dbr_ctrlDouble` structure.

## `get_alarm_double()`

This sets the members of the `dbr_alDouble` structure to the specified
alarm limits when the referenced field is VAL:

> upper\_alarm\_limit = HIHI
>
> upper\_warning\_limit = HIGH
>
> lower\_warning\_limit = LOW
>
> lower\_alarm\_limit = LOLO

If the referenced field is not VAL, the `recGblGetAlarmDouble()` routine
is called.

### Record Processing

- 1.
The `process()` routine first checks that DOL is not a constant link and
that OMSL is set to "closed\_loop". If so, it retrieves a value through DOL
and places it into VAL. If no errors occur, UDF is set to FALSE.
- 2.
PACT is set TRUE, and the record's timestamp is set.
- 3.
A value is fetched from SELL and placed into SELN.
- 4.
Alarms ranges are checked against the contents of the VAL field.
- 5.
VAL is then sent through the OUTA-OUTH links by calling `dbPutLink()` for
each link, conditional on the setting of SELM and the value in SELN.
- 6.
Value and archive monitors are posted on the VAL field if appropriate based on
the settings of MDEL and ADEL respectively.
- 7.
The data fanout's forward link FLNK is processed.
- 6.
PACT is set FALSE, and the `process()` routine returns.
