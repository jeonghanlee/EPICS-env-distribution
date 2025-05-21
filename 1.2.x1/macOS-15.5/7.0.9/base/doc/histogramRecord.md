# Histogram Record (histogram)

The histogram record is used to store frequency counts of a signal into an array
of arbitrary length. The user can configure the range of the signal value that
the array will store. Anything outside this range will be ignored.

This record type was included in base.dbd beginning with epics-base 3.15.0.1 .

## Parameter Fields

The record-specific fields are described below.

### Read Parameters

The SVL is the input link where the record reads its value. It can be a
constant, a database link, or a channel access link. If SVL is a database or
channel access link, then SGNL is read from SVL. If SVL is a constant, then SGNL
is initialized with the constant value but can be changed via dbPuts. The `Soft
Channel` device support module can be specified in the DTYP field.

The ULIM and LLIM fields determine the usable range of signal values. Any value
of SGNL below LLIM or above ULIM is outside the range and will not be stored in
the array. In the NELM field the user must specify the array size, e.g., the
number of array elements. Each element in the NELM field holds the counts for an
interval of the range of signal counts, the range specified by ULIM and LLIM.
These intervals are determined by dividing the range by NELM:

    (ULIM - LLIM) / NELM.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SVL | Signal Value Location | INLINK | Yes |   | Yes | Yes | No |
| SGNL | Signal Value | DOUBLE | No |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| NELM | Num of Array Elements | USHORT | Yes | 1 | Yes | No | No |
| ULIM | Upper Signal Limit | DOUBLE | Yes |   | Yes | Yes | No |
| LLIM | Lower Signal Limit  | DOUBLE | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. These
fields are used to display the value and other parameters of the histogram
either textually or graphically. See
[Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters)
for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The Histogram record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Monitor Parameters

The MDEL field implements the monitor count deadband. Only when MCNT is greater
than the value given to MDEL are monitors triggered, MCNT being the number of
counts since the last time the record was processed. If MDEL is -1, everytime
the record is processed, a monitor is triggered regardless.

If SDEL is greater than 0, it causes a callback routine to be called. The number
specified in SDEL is the callback routines interval. The callback routine is
called every SDEL seconds. The callback routine posts an event if MCNT is
greater than 0.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| MDEL | Monitor Count Deadband | SHORT | Yes |   | Yes | Yes | No |
| SDEL | Monitor Seconds Dband | DOUBLE | Yes |   | Yes | Yes | No |

### Run-time and Simulation Mode Parameters

These parameters are used by the run-time code for processing the histogram.
They are not configurable by the user prior to run-time. They represent the
current state of the record. Many of them are used to process the histogram more
efficiently.

The BPTR field contains a pointer to the unsigned long array of frequency
values. The VAL field references this array as well. However, the BPTR field is
not accessible at run-time.

The MCNT field keeps the number of signal counts since the last monitor
was invoked.

The collections controls field (CMD) is a menu field with four choices:

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | histogramCMD\_Read | Read |
| 1 | histogramCMD\_Clear | Clear |
| 2 | histogramCMD\_Start | Start |
| 3 | histogramCMD\_Stop | Stop |

When CMD is `Read`, the record retrieves its values and adds them to the signal
array. This command will first clear the signal counts which have already been
read when it is first invoked.

The `Clear` command erases the signal counts, setting the elements in the array
back to zero. Afterwards, the CMD field is set back to `Read`.

The `Start` command simply causes the record to read signal values into the
array. Unlike `Read`, it doesn't clear the array first.

The `Stop` command disables the reading of signal values into the array.

The CSTA or collections status field implements the CMD field choices by
enabling or disabling the reading of values into the histogram array. While
FALSE, no signals are added to the array. While TRUE, signals are read and added
to the array. The field is initialized to TRUE. The `Stop` command is the only
command that sets CSTA to FALSE. On the other hand, the `Start` command is the
only command that sets it to TRUE. Thus, `Start` must be invoked after each
`Stop` command in order to enable counting; invoking `Read` will not enable
signal counting after `Stop` has been invoked.

A typical use of these fields would be to initialize the CMD field to `Read`
(it is initialized to this command by default), to use the `Stop` command to
disable counting when necessary, after which the `Start` command can be invoked
to re-start the signal count.

The WDTH field is a private field that holds the signal width of the array
elements. For instance, if the LLIM was configured to be 4.0 and ULIM was
configured to be 12.0 and the NELM was set to 4, then the WDTH for each array
would be 2. Thus, it is (ULIM - LLIM) / NELM.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| VAL | Value | ULONG\[\] | No |   | Yes | Yes | No |
| MCNT | Counts Since Monitor | SHORT | No |   | Yes | No | No |
| CMD | Collection Control | MENU [histogramCMD](#menu-histogramcmd) | No |   | Yes | Yes | No |
| CSTA | Collection Status | SHORT | No | 1 | Yes | No | No |
| WDTH | Element Width | DOUBLE | No |   | Yes | No | No |

The following fields are used to operate the histogram record in simulation
mode. See ["Fields Common to Many Record Types"](#fields-common-to-many-record-types) for more information on the
simulation mode fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SIOL | Simulation Input Link | INLINK | Yes |   | Yes | Yes | No |
| SVAL | Simulation Value | DOUBLE | No |   | Yes | Yes | No |
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |

## Record Support

### Record Support Routines

#### init\_record

Using NELM, space for the unsigned long array is allocated and the width WDTH of
the array is calculated.

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. SVAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support and a device support read
routine are available. If device support includes `init_record()`, it is
called.

#### process

See next section.

#### special

Special is invoked whenever the fields CMD, SGNL, ULIM, or LLIM are changed.

If SGNL is changed, add\_count is called.

If ULIM or LLIM are changed, WDTH is recalculated and clear\_histogram is called.

If CMD is less or equal to 1, clear\_histogram is called and CMD is reset to 0.
If CMD is 2, CSTA is set to TRUE and CMD is reset to 0. If CMD is 3, CSTA is set
to FALSE and CMD is reset to 0.

clear\_histogram zeros out the histogram array. add\_count increments the
frequency in the histogram array.

#### cvt\_dbaddr

This is called by dbNameToAddr. It makes the dbAddr structure refer to the
actual buffer holding the array.

#### get\_array\_info

Obtains values from the array referenced by VAL.

#### put\_array\_info

Writes values into the array referenced by VAL.

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field set
to TRUE. This ensures that processes will no longer be called for this record.
Thus error storms will not occur.
2. readValue is called. See  ["Input Records"](#input-records) for more information
3. If PACT has been changed to TRUE, the device support read routine has started
but has not completed writing the new value. In this case, the processing
routine merely returns, leaving PACT TRUE.
4. Add count to histogram array.
5. Check to see if monitors should be invoked. Alarm monitors are invoked if the
alarm status or severity has changed. Archive and value change monitors are
invoked if MDEL conditions are met. NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT and INIT to FALSE, and return.

## Device Support

### Fields Of Interest To Device Support

The device support routines are primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| SVL | Signal Value Location | INLINK | Yes |   | Yes | Yes | No |
| SGNL | Signal Value | DOUBLE | No |   | Yes | Yes | No |

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

This routine is called by the record support `init_record()` routine. It makes
sure that SGNL is a CONSTANT, PV\_LINK, DB\_LINK, or CA\_LINK. It also retrieves a
value for SVL from SGNL. If SGNL is none of the above, an error is generated.

#### read\_histogram

    read_histogram(*precord)

This routine is called by the record support routines. It retrieves a value for
SVL from SGNL.

### Device Support For Soft Records

Only the device support module `Soft Channel` is currently provided, though
other device support modules may be provided at the user's site.

#### Soft Channel

The `Soft Channel` device support routine retrieves a value from SGNL. SGNL
must be CONSTANT, PV\_LINK, DB\_LINK, or CA\_LINK.
