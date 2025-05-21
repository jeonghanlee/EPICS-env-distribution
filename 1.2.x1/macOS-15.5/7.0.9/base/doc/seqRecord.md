# Sequence Record (seq)

The Sequence record is used to trigger the processing of up to ten other records
and send values to those records. It is similar to the fanout record, except
that it will fetch an input value and write an output value instead of simply
processing a collection of forward links. It can also specify one of several
selection algorithms that determine which values to write. It has no associated
device support.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The sequence record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Desired Output Parameters

These fields determine where the record retrieves the values it is to write to
other records. All of these values are not necessarily used, depending on the
selection algorithm.

The sequence record can retrieve up to 16 values from 16 locations. The user
specifies the locations in the Desired Output Link fields (DOL0-DOLF), which can
be either constants, database links, or channel access links. If a Desired
Output Link is a constant, the corresponding value field for that link is
initialized to the constant value.
Otherwise, if the Desired Output Link is a database or channel access link, a
value is fetched from the link each time the record is processed.

The value fetched from the Desired Output Links are stored in the corresponding
Desired Output Value fields (DO0-DOF). These fields can be initialized to a
constant value, and may subsequently be changed via dbPuts.

#### Desired Output Link Fields

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DOL0 | Input link 0 | INLINK | Yes |   | Yes | Yes | No |
| DOL1 | Input link1 | INLINK | Yes |   | Yes | Yes | No |
| DOL2 | Input link 2 | INLINK | Yes |   | Yes | Yes | No |
| DOL3 | Input link 3 | INLINK | Yes |   | Yes | Yes | No |
| DOL4 | Input link 4 | INLINK | Yes |   | Yes | Yes | No |
| DOL5 | Input link 5 | INLINK | Yes |   | Yes | Yes | No |
| DOL6 | Input link 6 | INLINK | Yes |   | Yes | Yes | No |
| DOL7 | Input link 7 | INLINK | Yes |   | Yes | Yes | No |
| DOL8 | Input link 8 | INLINK | Yes |   | Yes | Yes | No |
| DOL9 | Input link 9 | INLINK | Yes |   | Yes | Yes | No |
| DOLA | Input link 10 | INLINK | Yes |   | Yes | Yes | No |
| DOLB | Input link 11 | INLINK | Yes |   | Yes | Yes | No |
| DOLC | Input link 12 | INLINK | Yes |   | Yes | Yes | No |
| DOLD | Input link 13 | INLINK | Yes |   | Yes | Yes | No |
| DOLE | Input link 14 | INLINK | Yes |   | Yes | Yes | No |
| DOLF | Input link 15 | INLINK | Yes |   | Yes | Yes | No |

#### Desired Output Value Fields

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DO0 | Value 0 | DOUBLE | No |   | Yes | Yes | No |
| DO1 | Value 1 | DOUBLE | No |   | Yes | Yes | No |
| DO2 | Value 2 | DOUBLE | No |   | Yes | Yes | No |
| DO3 | Value 3 | DOUBLE | No |   | Yes | Yes | No |
| DO4 | Value 4 | DOUBLE | No |   | Yes | Yes | No |
| DO5 | Value 5 | DOUBLE | No |   | Yes | Yes | No |
| DO6 | Value 6 | DOUBLE | No |   | Yes | Yes | No |
| DO7 | Value 7 | DOUBLE | No |   | Yes | Yes | No |
| DO8 | Value 8 | DOUBLE | No |   | Yes | Yes | No |
| DO9 | Value 9 | DOUBLE | No |   | Yes | Yes | No |
| DOA | Value 10 | DOUBLE | No |   | Yes | Yes | No |
| DOB | Value 11 | DOUBLE | No |   | Yes | Yes | No |
| DOC | Value 12 | DOUBLE | No |   | Yes | Yes | No |
| DOD | Value 13 | DOUBLE | No |   | Yes | Yes | No |
| DOE | Value 14 | DOUBLE | No |   | Yes | Yes | No |
| DOF | Value 15 | DOUBLE | No |   | Yes | Yes | No |

### Output Parameters

When the record is processed, the desired output values are retrieved for the
links in the record's selection algorithm and are written to the corresponding
output link (LNK0-LNKF). These output links can be database links or channel
access links; they cannot be device addresses. There are sixteen output links, one
for each desired output link. Only those that are defined are used.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| LNK0 | Output Link 0 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK1 | Output Link 1 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK2 | Output Link 2 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK3 | Output Link 3 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK4 | Output Link 4 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK5 | Output Link 5 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK6 | Output Link 6 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK7 | Output Link 7 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK8 | Output Link 8 | OUTLINK | Yes |   | Yes | Yes | No |
| LNK9 | Output Link 9 | OUTLINK | Yes |   | Yes | Yes | No |
| LNKA | Output Link 10 | OUTLINK | Yes |   | Yes | Yes | No |
| LNKB | Output Link 11 | OUTLINK | Yes |   | Yes | Yes | No |
| LNKC | Output Link 12 | OUTLINK | Yes |   | Yes | Yes | No |
| LNKD | Output Link 13 | OUTLINK | Yes |   | Yes | Yes | No |
| LNKE | Output Link 14 | OUTLINK | Yes |   | Yes | Yes | No |
| LNKF | Output Link 15 | OUTLINK | Yes |   | Yes | Yes | No |

### Selection Algorithm Parameters

When the sequence record is processed, it uses a selection algorithm similar to
that of the selection record to decide which links to process.The select
mechanism field (SELM) has three algorithms to choose from: `All`,
`Specified` or `Mask`.

#### Record fields related to the Selection Algorithm

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SELM | Select Mechanism | MENU [seqSELM](#menu-seqselm) | Yes |   | Yes | Yes | No |
| SELN | Link Selection | USHORT | No | 1 | Yes | Yes | No |
| SELL | Link Selection Loc | INLINK | Yes |   | Yes | Yes | No |
| SHFT | Shift for Mask mode | SHORT | Yes | -1 | Yes | Yes | No |
| OFFS | Offset for Specified | SHORT | Yes |   | Yes | Yes | No |

#### Fields Description

**SELM - Selection Mode**

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | seqSELM\_All | All |
| 1 | seqSELM\_Specified | Specified |
| 2 | seqSELM\_Mask | Mask |

See ["Selection Algorithms Description"](#selection-algorithms-description) below;

**SELL - Link Selection Location**

This field can be initialized as a CONSTANT or as a LINK to any other record.
SELN will fetch its value from this field when the seq record is processed.
Thus, when using `Mask` or `Specified` modes, the links that seq will
process can be dynamically changed by the record pointed by SELL.

**SELN - Link Selection**

When **SELM** has the value `Specified` the **SELN** field sets the index number
of the link that will be processed, after adding the **OFFS** field:

> LNK_n_ where _n_ = `SELN + OFFS`

_(If not set, the OFFS field is ZERO)_

When **SELM** has the value `Mask` the **SELN** field provides the bitmask that
determines which links will be processed, after shifting by **SHFT** bits:

    if (SHFT >= 0)
      bits = SELN >> SHFT
    else
      bits = SELN << -SHFT

_(If not set, the SHFT field is -1 so bits from SELN are shifted left by 1)_

#### **Note about SHFT and OFFS fields**

The first versions of seq record had DO, DOL, LNK and DLY fields starting with
index ONE (DO1, DOL1, LNK1 and DLY1).
Since EPICS 7 the seq record now supports 16 links, starting from index ZERO
(DO0, DOL0, LNK0 and DLY0).
The SHFT and OFFS fields were introduced to keep compatibility of old databases
that used seq records with links indexed from one.

**To use the DO0, DOL0, LNK0, DLY0 fields when SELM = Mask, the SHFT field must
be explicitly set to ZERO**

#### Selection Algorithms Description

**All**

The `All` algorithm causes the record to process each input and output
link each time the record is processed, in order from 0 to 15. So when SELM is
`All`, the desired output value from DOL0 will fetched and sent to LNK0,
then the desired output value from DOL1 will be fetched and sent to the location
in LNK1, and so on until the last input and output link DOF and LNKF. (Note that
undefined links are not used.) If DOL_x_ is a constant, the current value
field is simply used and the desired output link is ignored. The SELN field is
not used when `All` is the algorithm.

**Specified**

When the `Specified` algorithm is chosen, each time the record is
processed it gets the integer value in the Link Selection (SELN) field and uses
that as the index of the link to process. For instance, if SELN is 4, the
desired output value from DO4 will be retrieved and sent to LNK4. If DOL_x_ is
a constant, DO_x_ is simply used without the value being fetched from the
input link.

**Mask**

When `Mask` is chosen, the record uses the individual bits of the SELN
field to determine the links to process. When bit 0 of SELN is set, the value
from DO0 will be written to the location in LNK0; when bit 1 is set, the valud
from DO1 will be written to the location in LNK1 etc. Thus for example if SELN
is 3, the record will retrieve the values from DO0 and DO1 and write them to the
locations in LNK0 and LNK1, respectively. If SELN is 63, DO0...DO5 will be
written to LNK0...LNK5.

### Delay Parameters

The delay parameters consist of 16 fields, one for each I/O link discussed
above. These fields can be configured to cause the record to delay processing
the link. For instance, if the user gives the DLY1 field a value of 3.0, each
time the record is processed at run-time, the record will delay processing the
DOL1, DOV1, and LNK1 fields for three seconds. That is, the desired output value
will not be fetched and written to the output link until three seconds have
lapsed.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DLY0 | Delay 0 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY1 | Delay 1 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY2 | Delay 2 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY3 | Delay 3 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY4 | Delay 4 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY5 | Delay 5 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY6 | Delay 6 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY7 | Delay 7 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY8 | Delay 8 | DOUBLE | Yes |   | Yes | Yes | No |
| DLY9 | Delay 9 | DOUBLE | Yes |   | Yes | Yes | No |
| DLYA | Delay 10 | DOUBLE | Yes |   | Yes | Yes | No |
| DLYB | Delay 11 | DOUBLE | Yes |   | Yes | Yes | No |
| DLYC | Delay 12 | DOUBLE | Yes |   | Yes | Yes | No |
| DLYD | Delay 13 | DOUBLE | Yes |   | Yes | Yes | No |
| DLYE | Delay 14 | DOUBLE | Yes |   | Yes | Yes | No |
| DLYF | Delay 15 | DOUBLE | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. The
Precision field (PREC) determines the decimal precision for the VAL field when
it is displayed. It is used when the `get_precision` record routine is
called.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The sequence record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

## Record Support

### Record Processing

Routine process implements the following algorithm:

1. First, PACT is set to TRUE, and the link selection is fetched. Depending on the
selection mechanism chosen, the appropriate set of link groups will be
processed. If multiple link groups need to be processed they are done in
increasing numerical order, from LNK0 to LNKF.
2. When LNK_x_ is to be processed, the corresponding DLY_x_ value is first used
to generate the requested time delay, using the IOC's Callback subsystem to
perform subsequent operations. This means that although PACT remains TRUE, the
lockset that the sequence record belongs to will be unlocked for the duration of
the delay time (an unlock occurs even when the delay is zero).
3. After DLY_x_ seconds have expired, the value in DO_x_ is saved locally and a
new value is read into DO_x_ through the link DOL_x_ (if the link is valid).
Next the record's timestamp is set, and the value in DO_x_ is written through
the LNK_x_ output link. If the value of DO_x_ was changed when it was read in
a monitor event is triggered on that field.
4. If any link groups remain to be processed, the next group is selected and the
operations for that group are executed again from step 2 above.

    If the last link group has been processed, UDF is set to FALSE and the record's
    timestamp is set.

5. Monitors are posted on VAL and SELN.
6. The forward link is scanned, PACT is set FALSE, and the process routine returns.

For the delay mechanism to operate properly, the record is normally processed
asynchronously. The only time the record will not be processed asynchronously is
if it has nothing to do, because no link groups or only empty link groups are
selected for processing (groups where both DOL_x_ and LNK_x_ are unset or
contain only a constant value).
