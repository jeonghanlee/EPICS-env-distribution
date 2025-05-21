# 64bit Integer Input Record (int64in)

This record type is normally used to obtain an integer value of up to 64 bits
from a hardware input.
The record supports alarm limits, alarm filtering, graphics and control
limits.

This record type was included in base.dbd beginning with epics-base 3.16.1 .

## Parameter Fields

The record-specific fields are described below.

### Input Specification

These fields control where the record will read data from when it is processed:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |

The DTYP field selects which device support layer should be responsible for
providing input data to the record.
The int64in device support layers provided by EPICS Base are documented in the
["Device Support"](#device-support) section.
External support modules may provide additional device support for this record
type.
If not set explicitly, the DTYP value defaults to the first device support that
is loaded for the record type, which will usually be the `Soft Channel` support
that comes with Base.

The INP link field contains a database or channel access link or provides
hardware address information that the device support uses to determine where the
input data should come from.

### Operator Display Parameters

These parameters are used to present meaningful data to the operator.
They do not affect the functioning of the record.

- DESC is a string that is usually used to briefly describe the record.
- EGU is a string of up to 16 characters naming the engineering units
that the VAL field represents.
- The HOPR and LOPR fields set the upper and lower display limits for the VAL,
HIHI, HIGH, LOW, and LOLO fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |
| EGU | Units name | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | INT64 | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | INT64 | Yes |   | Yes | Yes | No |

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
behavior).

The LALM field is used by the record at run-time to implement the alarm limit
functionality.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| HIHI | Hihi Alarm Limit | INT64 | Yes |   | Yes | Yes | Yes |
| HIGH | High Alarm Limit | INT64 | Yes |   | Yes | Yes | Yes |
| LOW | Low Alarm Limit | INT64 | Yes |   | Yes | Yes | Yes |
| LOLO | Lolo Alarm Limit | INT64 | Yes |   | Yes | Yes | Yes |
| HHSV | Hihi Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HSV | High Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LSV | Low Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LLSV | Lolo Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HYST | Alarm Deadband | INT64 | Yes |   | Yes | Yes | No |
| AFTC | Alarm Filter Time Constant | DOUBLE | Yes |   | Yes | Yes | No |
| LALM | Last Value Alarmed | INT64 | No |   | Yes | No | No |

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
monitoring deadband functionality.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | INT64 | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | INT64 | Yes |   | Yes | Yes | No |
| ALST | Last Value Archived | INT64 | No |   | Yes | No | No |
| MLST | Last Val Monitored | INT64 | No |   | Yes | No | No |

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
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Input Link | INLINK | Yes |   | Yes | Yes | No |
| SVAL | Simulation Value | INT64 | No |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

## Record Support

### Record Support Routines

The following are the record support routines that would be of interest
to an application developer.
Other routines are the `get_units`, `get_graphic_double`,
`get_alarm_double` and `get_control_double` routines, which are used to
collect properties from the record for the complex DBR data structures.

#### init\_record

This routine first initializes the simulation mode mechanism by setting SIMM
if SIML is a constant, and setting SVAL if SIOL is a constant.

It then checks if the device support and the device support's
`read_int64in` routine are defined.
If either one does not exist, an error message is issued
and processing is terminated.

If device support includes `init_record`, it is called.

Finally, the deadband mechanisms for monitors and level alarms are
initialized.

#### process

See next section.

### Record Processing

Routine `process` implements the following algorithm:

1. Check to see that the appropriate device support module and its
`read_int64in` routine are defined.
If either one does not exist, an error message is issued and processing is
terminated with the PACT field set to TRUE, effectively blocking the record
to avoid error storms.
2. Determine the value:

    If PACT is TRUE, call the device support `read_int64in` routine and return.

    If PACT is FALSE, read the value, honoring simulation mode:

    - Get SIMM by reading the SIML link.
    - If SIMM is `NO`,
    call the device support `read_int64in` routine and return.
    - If SIMM is `YES`, then
        - Set alarm status to SIMM\_ALARM and severity to SIMS,
        if SIMS is greater than zero.
        - If the record simulation processing is synchronous (SDLY < 0) or the record is
        in the second phase of an asynchronous processing, call `dbGetLink()`
        to read the input value from SIOL into SVAL.
        Set status to the return code from `dbGetLink()`.
        If the call succeeded, write the value to VAL and set UDF to 0.

            Otherwise (record is in first phase of an asynchronous processing), set up a
            callback processing with the delay specified in SDLY.
    - Raise an alarm for other values of SIMM.

3. If PACT has been changed to TRUE, the device support signals asynchronous
processing: its `read_int64in` output routine has started, but not
completed reading the new value.
In this case, the processing routine merely returns, leaving PACT TRUE.
4. Set PACT to TRUE. Get the processing time stamp. Set UDF to 0 if reading
the value was successful.
5. Check UDF and level alarms: This routine checks to see if the record is
undefined (UDF is TRUE) or if the new VAL causes the alarm status
and severity to change. In the latter case, NSEV, NSTA and LALM are set.
It also honors the alarm hysteresis factor (HYST): the value must change
by at least HYST between level alarm status and severity changes.
If AFTC is set, alarm level filtering is applied.
6. Check to see if monitors should be invoked:
    - Alarm monitors are posted if the alarm status or severity have
    changed.
    - Archive and value change monitors are posted if ADEL and MDEL
    conditions (see ["Monitor Parameters"](#monitor-parameters)) are met.
7. Scan (process) forward link if necessary, set PACT to FALSE, and return.

## Device Support

### Device Support Interface

The record requires device support to provide an entry table (dset) which
defines the following members:

    typedef struct {
        long number;
        long (*report)(int level);
        long (*init)(int after);
        long (*init_record)(int64inRecord *prec);
        long (*get_ioint_info)(int cmd, int64inRecord *prec, IOSCANPVT *piosl);
        long (*read_int64in)(int64inRecord *prec);
    } int64indset;

The module must set `number` to at least 5, and provide a pointer to its
`read_int64in()` routine; the other function pointers may be `NULL` if their
associated functionality is not required for this support layer.
Most device supports also provide an `init_record()` routine to configure the
record instance and connect it to the hardware or driver support layer.

The individual routines are described below.

### Device Support Routines

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

#### long init\_record(int64inRecord \*prec)

This optional routine is called by the record initialization code for each
int64in record instance that has its DTYP field set to use this device support.
It is normally used to check that the INP address is the expected type and that
it points to a valid device; to allocate any record-specific buffer space and
other memory; and to connect any communication channels needed for the
`read_int64in()` routine to work properly.

#### long get\_ioint\_info(int cmd, int64inRecord \*prec, IOSCANPVT \*piosl)

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

#### long read\_int64in(int64inRecord \*prec)

This essential routine is called when the record wants a new value from the
addressed device.
It is responsible for performing (or at least initiating) a read operation, and
(eventually) returning its value to the record.

If the device may take more than a few microseconds to return the new value,
this routine must never block (busy-wait), but use the asynchronous
processing mechanism.
In that case it signals the asynchronous operation by setting the record's
PACT field to TRUE before it returns, having arranged for the record's
`process()` routine to be called later once the read operation is finished.
When that happens, the `read_int64in()` routine will be called again with
PACT still set to TRUE; it should then set it to FALSE to indicate the read
has completed, and return.

A return value of zero indicates success, any other value indicates that an
error occurred.

### Extended Device Support

...

## Device Support For Soft Records

Two soft device support modules, Soft Channel and Soft Callback Channel, are
provided for input records not related to actual hardware devices. The
INP link type must be either a CONSTANT, DB\_LINK, or CA\_LINK.

### Soft Channel

This module reads the value using the record's INP link.

`read_int64in` calls `dbGetLink` to read the value.

### Soft Callback Channel

This module is like the previous except that it reads the value
using asynchronous processing that will not complete until an asynchronous
processing of the INP target record has completed.
