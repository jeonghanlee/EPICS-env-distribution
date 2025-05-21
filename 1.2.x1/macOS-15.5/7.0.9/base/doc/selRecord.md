# Select Record (sel)

The select record computes a value based on input obtained from up to 12
locations. The selection algorithm can be one of the following: `Specified`, `High Signal`, `Low Signal`, `Median Signal`. Each
input can be a constant, a database link, or a channel access link.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The select record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read Parameters

The INPA-L links determine where the selection record retrieves the values from
which it is to select or compute its final value. The INPA-L links are input
links configured by the user to be either constants, channel access links, or
database links. If channel access or database links, a value is retrieved for
each link and placed in the corresponding value field, A-L. If any input link is
a constant, the value field for that link will be initialized with the constant
value given to it and can be modified via dbPuts.

Any links not defined are ignored by the selection record and its algorithm. An
undefined link is any constant link whose value is 0. At initialization time,
the corresponding value links for such fields are set to NaN, which means
MISSING. The value field of an undefined link can be changed at run-time from
NaN to another value in order to define the link and its field. Note that all
undefined links must be recognized as such if the selection algorithm is to work
as expected.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| INPA | Input A | INLINK | Yes |   | Yes | Yes | No |
| INPB | Input B | INLINK | Yes |   | Yes | Yes | No |
| INPC | Input C | INLINK | Yes |   | Yes | Yes | No |
| INPD | Input D | INLINK | Yes |   | Yes | Yes | No |
| INPE | Input E | INLINK | Yes |   | Yes | Yes | No |
| INPF | Input F | INLINK | Yes |   | Yes | Yes | No |
| INPG | Input G | INLINK | Yes |   | Yes | Yes | No |
| INPH | Input H | INLINK | Yes |   | Yes | Yes | No |
| INPI | Input I | INLINK | Yes |   | Yes | Yes | No |
| INPJ | Input J | INLINK | Yes |   | Yes | Yes | No |
| INPK | Input K | INLINK | Yes |   | Yes | Yes | No |
| INPL | Input L | INLINK | Yes |   | Yes | Yes | No |
| A | Value of Input A | DOUBLE | No |   | Yes | Yes | Yes |
| B | Value of Input B | DOUBLE | No |   | Yes | Yes | Yes |
| C | Value of Input C | DOUBLE | No |   | Yes | Yes | Yes |
| D | Value of Input D | DOUBLE | No |   | Yes | Yes | Yes |
| E | Value of Input E | DOUBLE | No |   | Yes | Yes | Yes |
| F | Value of Input F | DOUBLE | No |   | Yes | Yes | Yes |
| G | Value of Input G | DOUBLE | No |   | Yes | Yes | Yes |
| H | Value of Input H | DOUBLE | No |   | Yes | Yes | Yes |
| I | Value of Input I | DOUBLE | No |   | Yes | Yes | Yes |
| J | Value of Input J | DOUBLE | No |   | Yes | Yes | Yes |
| K | Value of Input K | DOUBLE | No |   | Yes | Yes | Yes |
| L | Value of Input L | DOUBLE | No |   | Yes | Yes | Yes |

### Select Parameters

The selection algorithm is determined by three fields configurable by the user:
the select mechanism (SELM) field, the select number (SELN) field, and the index
value location (NVL) field.

The SELM field has four choices, i.e., four algorithms as follows:

#### Menu selSELM

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | selSELM\_Specified | Specified |
| 1 | selSELM\_High\_Signal | High Signal |
| 2 | selSELM\_Low\_Signal | Low Signal |
| 3 | selSELM\_Median\_Signal | Median Signal |

The selection record's VAL field is determined differently for each algorithm.
For `Specified`, the VAL field is set equal to the value field (A, B, C,
D, E, F, G, H, I, J, K, or L) specified by the SELN field. The SELN field
contains a
number from 0-11 which corresponds to the value field to be used (0 means use A;
1 means use B, etc.). How the NVL field is configured determines, in turn,
SELN's value. NVL is an input link from which a value for SELN can be retrieved,
Like most other input links NVL can be a constant, or a channel access or
database link. If NVL is a link, SELN is retrieved from the location in NVL. If
a constant, SELN is initialized to the value given to the constant and can be
changed via dbPuts.

The `High Signal`, `Low Signal`, and `Median Signal`
algorithms do not use SELN or NVL. If `High Signal` is chosen, VAL is set
equal to the highest value out of all the defined value fields (A-L). If `Low Signal` is chosen, VAL is set equal to lowest value of all the defined
fields (A-L). And if `Median Signal` is chosen, VAL is set equal to the
median value of the defined value fields (A-L). (Note that these algorithms
select from the value fields; they do not select from the value field index. For
instance, `Low Signal` will not select the A field's value unless the
value itself is the lowest of all the defined values.)

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SELM | Select Mechanism | MENU [selSELM](#menu-selselm) | Yes |   | Yes | Yes | No |
| SELN | Index value | USHORT | No |   | Yes | Yes | No |
| NVL | Index Value Location | INLINK | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the select record either textually or
graphically.

EGU is a string of up to 16 characters describing the units that the selection
record manipulates. It is retrieved by the `get_units` record support
routine.

The HOPR and LOPR fields set the upper and lower display limits for the VAL,
HIHI, HIGH, LOW, and LOLO fields. Both the `get_graphic_double` and `get_control_double` record support routines retrieve these fields.

The PREC field determines the floating point precision with which to display
VAL. It is used whenever the `get_precision` record support routine is
called.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Rng | DOUBLE | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The possible alarm conditions for select records are the SCAN, READ, and limit
alarms. The SCAN and READ alarms are called by the record or device support
routines. The limit alarms are configured by the user in the HIHI, LOLO, HIGH,
and LOW fields using numerical values. They specify conditions for the VAL
field. For each of these fields, there is a corresponding severity field which
can be either NO\_ALARM, MINOR, or MAJOR.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

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

These fields are configurable by the user. They are used as deadbands for the
archiver and monitor calls for the VAL field. Unless, VAL changes by more than
the value specified by each, then the respective monitors will not be called. If
these fields have a value of zero, everytime the VAL changes, monitors are
triggered; if they have a value of -1, everytime the record is processed,
monitors are triggered.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | DOUBLE | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | DOUBLE | Yes |   | Yes | Yes | No |

### Run-time Parameters

These parameters are used by the run-time code for processing the selection
record. They are not configurable prior to run-time, nor are they modifiable at
run-time. They represent the current state of the record. The record support
routines use some of them for more efficient processing.

The VAL field is the result of the selection record's processing. It can be
accessed in the normal way by another record or through database access, but is
not modifiable except by the record itself. The LALM, ALST, and the MLST are
used to implement the HYST, ADEL, and MDEL hysteresis factors for the alarms,
archiver, and monitors, respectively.

The LA-LL fields are used to implement the monitors for each of the value
fields, A-L. They represent previous input values. For example, unless LA is not
equal to A, no monitor is invoked for A.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Result | DOUBLE | Yes |   | Yes | No | No |
| LALM | Last Value Alarmed | DOUBLE | No |   | Yes | No | No |
| ALST | Last Value Archived | DOUBLE | No |   | Yes | No | No |
| MLST | Last Val Monitored | DOUBLE | No |   | Yes | No | No |
| LA | Prev Value of A | DOUBLE | No |   | Yes | No | No |
| LB | Prev Value of B | DOUBLE | No |   | Yes | No | No |
| LC | Prev Value of C | DOUBLE | No |   | Yes | No | No |
| LD | Prev Value of D | DOUBLE | No |   | Yes | No | No |
| LE | Prev Value of E | DOUBLE | No |   | Yes | No | No |
| LF | Prev Value of F | DOUBLE | No |   | Yes | No | No |
| LG | Prev Value of G | DOUBLE | No |   | Yes | No | No |
| LH | Prev Value of H | DOUBLE | No |   | Yes | No | No |
| LI | Prev Value of I | DOUBLE | No |   | Yes | No | No |
| LJ | Prev Value of J | DOUBLE | No |   | Yes | No | No |
| LK | Prev Value of K | DOUBLE | No |   | Yes | No | No |
| LL | Prev Value of L | DOUBLE | No |   | Yes | No | No |

## Record Support

### Record Support Routines

#### init\_record

    long (*init_record)(struct dbCommon *precord, int pass)

IF NVL is a constant, SELN is set to its value. If NVL is a PV\_LINK a channel
access link is created.

For each constant input link, the corresponding value field is initialized with
the constant value (or NaN if the constant has the value 0).

For each input link that is of type PV\_LINK, a database or channel access link
is created.

#### process

    long (*process)(struct dbCommon *precord)

See ["Record Processing"](#record-processing).

#### get\_units

    long (*get_units)(struct dbAddr *paddr, char *units)

Retrieves EGU.

#### get\_precision

    long (*get_precision)(const struct dbAddr *paddr, long *precision)

Retrieves PREC.

#### get\_graphic\_double

    long (*get_graphic_double)(struct dbAddr *paddr, struct dbr_grDouble *p)

Sets the upper display and lower display limits for a field. If the field is
VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else if the
field has upper and lower limits defined they will be used, else the upper and
lower maximum values for the field type will be used.

#### get\_control\_double

    long (*get_control_double)(struct dbAddr *paddr, struct dbr_ctrlDouble *p)

Sets the upper control and the lower control limits for a field. If the field is
VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else if the
field has upper and lower limits defined they will be used, else the upper and
lower maximum values for the field type will be used.

#### get\_alarm\_double

    long (*get_alarm_double)(struct dbAddr *paddr, struct dbr_alDouble *p)

Sets the following values:

    upper_alarm_limit = HIHI
    upper_warning_limit = HIGH
    lower_warning_limit = LOW
    lower_alarm_limit = LOLO

### Record Processing

Routine process implements the following algorithm:

1. If NVL is a database or channel access link, SELN is obtained from NVL. Fetch
all values if database or channel access links. If SELM is SELECTED, then only
the selected link is fetched.
2. Implement the appropriate selection algorithm. For SELECT\_HIGH, SELECT\_LOW, and
SELECT\_MEDIAN, input fields are ignored if they are undefined. If success, UDF
is set to FALSE.
3. Check alarms. This routine checks to see if the new VAL causes the alarm status
and severity to change. If so, NSEV, NSTA, and LALM are set. It also honors the
alarm hysteresis factor (HYST). Thus the value must change by more than HYST
before the alarm status and severity is lowered.
4. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if ADEL and MDEL conditions are
    met
    - Monitors for A-L are checked whenever other monitors are invoked
    - NSEV and NSTA are reset to 0.
5. Scan forward link if necessary, set PACT FALSE, and return.
