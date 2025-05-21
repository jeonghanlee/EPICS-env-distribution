# Analog Input Record (ai)

This record type is normally used to obtain an analog value from a hardware
input and convert it to engineering units.
The record supports linear and break-point conversion to engineering units,
smoothing, alarm limits, alarm filtering, and graphics and control limits.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Input Specification

These fields control where the record will read data from when it is processed:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |

The DTYP field selects which device support layer should be responsible for
providing input data to the record.
The ai device support layers provided by EPICS Base are documented in the
["Device Support Interface"](#device-support-interface) section.
External support modules may provide additional device support for this record
type.
If not set explicitly, the DTYP value defaults to the first device support that
is loaded for the record type, which will usually be the `Soft Channel` support
that comes with Base.

The INP link field contains a database or channel access link or provides
hardware address information that the device support uses to determine where the
input data should come from.
The format for the INP field value depends on the device support layer that is
selected by the DTYP field.
See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for a description of the various hardware address formats supported.

### Units Conversion

These fields control if and how the raw input value gets converted into
engineering units:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| RVAL | Current Raw Value | LONG | No |   | Yes | Yes | Yes |
| ROFF | Raw Offset | ULONG | No |   | Yes | Yes | Yes |
| ASLO | Adjustment Slope | DOUBLE | Yes | 1 | Yes | Yes | Yes |
| AOFF | Adjustment Offset | DOUBLE | Yes |   | Yes | Yes | Yes |
| LINR | Linearization | MENU [menuConvert](menuConvert.md) | Yes |   | Yes | Yes | Yes |
| ESLO | Raw to EGU Slope | DOUBLE | Yes | 1 | Yes | Yes | Yes |
| EOFF | Raw to EGU Offset | DOUBLE | Yes |   | Yes | Yes | Yes |
| EGUL | Engineer Units Low | DOUBLE | Yes |   | Yes | Yes | Yes |
| EGUF | Engineer Units Full | DOUBLE | Yes |   | Yes | Yes | Yes |

These fields are not used if the device support layer reads its value in
engineering units and puts it directly into the VAL field.
This applies to Soft Channel and Async Soft Channel device support, and is also
fairly common for GPIB and similar high-level device interfaces.

If the device support sets the RVAL field, the LINR field controls how this gets
converted into engineering units and placed in the VAL field as follows:

- 1.
RVAL is converted to a double and ROFF is added to it.
- 2.
If ASLO is non-zero the value is multiplied by ASLO.
- 3.
AOFF is added.
- 4.
If LINR is `NO CONVERSION` the units conversion is finished after the above
steps.
- 5.
If LINR is `LINEAR` or `SLOPE`, the value from step 3 above is multiplied by
ESLO and EOFF is added to complete the units conversion process.
- 6.
Any other value for LINR selects a particular breakpoint table to be used on the
value from step 3 above.

The distinction between the `LINEAR` and `SLOPE` settings for the LINR field
are in how the conversion parameters are calculated:

- With `LINEAR` conversion the user must set EGUL and EGUF to the lowest and
highest possible engineering units values respectively that can be converted by
the hardware.
The device support knows the range of the raw data and calculates ESLO and EOFF
from them.
- `SLOPE` conversion requires the user to calculate the appropriate scaling and
offset factors and put them directly in ESLO and EOFF.

### Smoothing Filter

This filter is usually only used if the device support sets the RVAL field and
the Units Conversion process is used.
Device support that directly sets the VAL field may implement the filter if
desired.

The filter is controlled with a single parameter field:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SMOO | Smoothing | DOUBLE | Yes |   | Yes | Yes | No |

The SMOO field should be set to a number between 0 and 1.
If set to zero the filter is not used (no smoothing), while if set to one the
result is infinite smoothing (the VAL field will never change).
The calculation performed is:

> VAL = VAL \* SMOO + (1 - SMOO) \* New Data

where `New Data` was the result from the Units Conversion above.
This implements a first-order infinite impulse response (IIR) digital filter
with z-plane pole at SMOO.
The equivalent continuous-time filter time constant τ is given by

> τ = −T / ln(SMOO)

where T is the time between record processing.

### Undefined Check

If after applying the smoothing filter the VAL field contains a NaN
(Not-a-Number) value, the UDF field is set to a non-zero value, indicating that
the record value is undefined, which will trigger a `UDF_ALARM` with severity
`INVALID_ALARM`.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |

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

### Alarm Limits

The user configures limit alarms by putting numerical values into the HIHI,
HIGH, LOW and LOLO fields, and by setting the associated alarm severity in the
corresponding HHSV, HSV, LSV and LLSV menu fields.

The HYST field controls hysteresis to prevent alarm chattering from an input
signal that is close to one of the limits and suffers from significant readout
noise.

The AFTC field sets the time constant on a low-pass filter that delays the
reporting of limit alarms until the signal has been within the alarm range for
that number of seconds (the default AFTC value of zero retains the previous
behavior). The record must be scanned often enough for the filtering action to
work effectively and the alarm severity can only change when the record is
processed, but that processing does not have to be regular; the filter uses the
time since the record last processed in its calculation. Setting AFTC to a
positive number of seconds will delay the record going into or out of a minor
alarm severity or from minor to major severity until the input signal has been
in the alarm range for that number of seconds.

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
| AFTC | Alarm Filter Time Constant | DOUBLE | Yes |   | Yes | Yes | No |
| LALM | Last Value Alarmed | DOUBLE | No |   | Yes | No | No |

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the VAL
field.
The monitors are sent when the current value exceeds the last transmitted value
by the appropriate deadband.
If these fields are set to zero, a monitor will be triggered every time the
value changes; if set to -1, a monitor will be sent every time the record is
processed.

The ADEL field sets the deadband for archive monitors (`DBE_LOG` events), while
the MDEL field controls value monitors (`DBE_VALUE` events).

The remaining fields are used by the record at run-time to implement the record
monitoring functionality.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | DOUBLE | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | DOUBLE | Yes |   | Yes | Yes | No |
| ALST | Last Value Archived | DOUBLE | No |   | Yes | No | No |
| MLST | Last Val Monitored | DOUBLE | No |   | Yes | No | No |
| ORAW | Previous Raw Value | LONG | No |   | Yes | No | No |

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
| SVAL | Simulation Value | DOUBLE | No |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

## Device Support Interface

The record requires device support to provide an entry table (dset) which
defines the following members:

    typedef struct {
        long number;
        long (*report)(int level);
        long (*init)(int after);
        long (*init_record)(aiRecord *prec);
        long (*get_ioint_info)(int cmd, aiRecord *prec, IOSCANPVT *piosl);
        long (*read_ai)(aiRecord *prec);
        long (*special_linconv)(aiRecord *prec, int after);
    } aidset;

The module must set `number` to at least 6, and provide a pointer to its
`read_ai()` routine; the other function pointers may be `NULL` if their
associated functionality is not required for this support layer.
Most device supports also provide an `init_record()` routine to configure the
record instance and connect it to the hardware or driver support layer, and if
using the record's ["Units Conversion"](#units-conversion) features they set `special_linconv()`
as well.

The individual routines are described below.

### Device Support Routines

    long report(int level)

This optional routine is called by the IOC command `dbior` and is passed the
report level that was requested by the user.
It should print a report on the state of the device support to stdout.
The `level` parameter may be used to output increasingly more detailed
information at higher levels, or to select different types of information with
different levels.
Level zero should print no more than a small summary.

    long init(int after)

This optional routine is called twice at IOC initialization time.
The first call happens before any of the `init_record()` calls are made, with
the integer parameter `after` set to 0.
The second call happens after all of the `init_record()` calls have been made,
with `after` set to 1.

    long init_record(aiRecord *prec)

This optional routine is called by the record initialization code for each ai
record instance that has its DTYP field set to use this device support.
It is normally used to check that the INP address is the expected type and that
it points to a valid device; to allocate any record-specific buffer space and
other memory; and to connect any communication channels needed for the
`read_ai()` routine to work properly.

If the record type's unit conversion features are used, the `init_record()`
routine should calculate appropriate values for the ESLO and EOFF fields from
the EGUL and EGUF field values.
This calculation only has to be performed if the record's LINR field is set to
`LINEAR`, but it is not necessary to check that condition first.
This same calculation takes place in the `special_linconv()` routine, so the
implementation can usually just call that routine to perform the task.

    long get_ioint_info(int cmd, aiRecord *prec, IOSCANPVT *piosl)

This optional routine is called whenever the record's SCAN field is being
changed to or from the value `I/O Intr` to find out which I/O Interrupt Scan
list the record should be added to or deleted from.
If this routine is not provided, it will not be possible to set the SCAN field
to the value `I/O Intr` at all.

The `cmd` parameter is zero when the record is being added to the scan list,
and one when it is being removed from the list.
The routine must determine which interrupt source the record should be connected
to, which it indicates by the scan list that it points the location at `*piosl`
to before returning.
It can prevent the SCAN field from being changed at all by returning a non-zero
value to its caller.

In most cases the device support will create the I/O Interrupt Scan lists that
it returns for itself, by calling `void scanIoInit(IOSCANPVT *piosl)` once for
each separate interrupt source.
That routine allocates memory and inializes the list, then passes back a pointer
to the new list in the location at `*piosl`.

When the device support receives notification that the interrupt has occurred,
it announces that to the IOC by calling `void scanIoRequest(IOSCANPVT iosl)`
which will arrange for the appropriate records to be processed in a suitable
thread.
The `scanIoRequest()` routine is safe to call from an interrupt service routine
on embedded architectures (vxWorks and RTEMS).

    long read_ai(aiRecord *prec)

This essential routine is called when the record wants a new value from the
addressed device.
It is responsible for performing (or at least initiating) a read operation, and
(eventually) returning its value to the record.

... PACT and asynchronous processing ...

... return value ...

    long special_linconv(aiRecord *prec, int after)

This optional routine should be provided if the record type's unit conversion
features are used by the device support's `read_ai()` routine returning a
status value of zero.
It is called by the record code whenever any of the the fields LINR, EGUL or
EGUF are modified and LINR has the value `LINEAR`.
The routine must calculate and set the fields EOFF and ESLO appropriately based
on the new values of EGUL and EGUF.

These calculations can be expressed in terms of the minimum and maximum raw
values that the `read_ai()` routine can put in the RVAL field.
When RVAL is set to _RVAL\_max_ the VAL field will be set to EGUF, and when RVAL
is set to _RVAL\_min_ the VAL field will become EGUL.

The formulae to use are:

> EOFF = (_RVAL\_max_ \* EGUL − _RVAL\_min_ \* EGUF) /
> (_RVAL\_max_ − _RVAL\_min_)
>
> ESLO = (EGUF − EGUL) / (_RVAL\_max_ − _RVAL\_min_)

Note that the record support sets EOFF to EGUL before calling this routine,
which is a very common case (when _RVAL\_min_ is zero).

### Extended Device Support

...
