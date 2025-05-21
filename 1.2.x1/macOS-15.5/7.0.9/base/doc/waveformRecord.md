# Waveform Record (waveform)

The waveform record type is used to interface waveform digitizers. The record
stores its data in arrays. The array can contain any of the supported data
types.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The waveform record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read Parameters

These fields are configurable by the user to specify how and from where the
record reads its data. How the INP field is configured determines where the
waveform gets its input. It can be a hardware address, a channel access or
database link, or a constant. Only in records that use soft device support can
the INP field be a channel access link, a database link, or a constant.
Otherwise, the INP field must be a hardware address.

#### Fields related to waveform reading

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | No | No |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |
| RARM | Rearm the waveform | SHORT | Yes |   | Yes | Yes | Yes |

The DTYP field must contain the name of the appropriate device support module.
The values retrieved from the input link are placed in an array referenced by
VAL. (If the INP link is a constant, elements can be placed in the array via
dbPuts.) NELM specifies the number of elements that the array will hold, while
FTVL specifies the data type of the elements (follow the link in the table
above for a list of the available choices).

The RARM field used to cause some device types to re-arm when it was set to 1,
but we don't know of any such devices any more.

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the waveform either textually or
graphically.

#### Fields related to _Operator Display_

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

EGU is a string of up to 16 characters describing the units that the waveform
measures. It is retrieved by the `get_units` record support routine.

The HOPR and LOPR fields set the upper and lower display limits for array
elements referenced by the VAL field. Both the `get_graphic_double` and
`get_control_double` record support routines retrieve these fields.

The PREC field determines the floating point precision with which to display the
array values. It is used whenever the `get_precision` record support
routine is called.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

### Alarm Parameters

The waveform record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the VAL
field.
The APST and MPST fields are a menu with choices `Always` and `On Change`.
The default is `Always`, thus monitors will normally be sent every time
the record processes.
Selecting `On Change` causes a 32-bit hash of the VAL
field buffer to be calculated and compared with the previous hash value every
time the record processes; the monitor will only be sent if the hash is
different, indicating that the buffer has changed. Note that there is a small
chance that two different value buffers might result in the same hash value, so
for critical systems `Always` may be a better choice, even though it re-sends
duplicate data.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| APST | Post Archive Monitors | MENU [waveformPOST](#menu-waveformpost) | Yes |   | Yes | Yes | No |
| MPST | Post Value Monitors | MENU [waveformPOST](#menu-waveformpost) | Yes |   | Yes | Yes | No |
| HASH | Hash of OnChange data. | ULONG | No |   | Yes | Yes | No |

#### Menu waveformPOST

This menu defines the possible choices for `APST` and `MPST` fields:

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | waveformPOST\_Always | Always |
| 1 | waveformPOST\_OnChange | On Change |

### Run-time Parameters

These parameters are used by the run-time code for processing the waveform. They
are not configured using a configuration tool. Only the VAL field is modifiable
at run-time.

VAL references the array where the waveform stores its data. The BPTR field
holds the address of the array.

The NORD field indicates the number of elements that were read into the array.

The BUSY field permits asynchronous device support to collect array elements
sequentially in multiple read cycles which may call the record's `process()`
method many times before completing a read operation. Such a device would set
BUSY to TRUE along with setting PACT at the start of acquisition (it could also
set NORD to 0 and use it to keep track of how many elements have been received).
After receiving the last element the `read_wf()` routine would clear BUSY which
informs the record's `process()` method that the read has finished. Note that
CA clients that perform gets of the VAL field can see partially filled arrays
when this type of device support is used, so the BUSY field is almost never used
today.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Value | Set by FTVL | No |   | Yes | Yes | Yes |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| NORD | Number elements read | ULONG | No |   | Yes | No | No |
| BUSY | Busy Indicator | SHORT | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML) is YES, the record is put in SIMS
severity and the value is fetched through SIOL.
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
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

<div>
    <br>
    <hr>
    <br>
</div>

## Record Support

### Record Support Routines

#### init\_record

    static long init_record(waveformRecord *prec, int pass)

Using NELM and FTVL space for the array is allocated. The array address is
stored in the record.

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. VAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a device
support read routine is defined. If either does not exist, an error message is
issued and processing is terminated

If device support includes `init_record()`, it is called.

#### process

    static long process(waveformRecord *prec)

See ["Record Processing"](#record-processing) section below.

#### cvt\_dbaddr

    static long cvt_dbaddr(DBADDR *paddr)

This is called by dbNameToAddr. It makes the dbAddr structure refer to the
actual buffer holding the result.

#### get\_array\_info

    static long get_array_info(DBADDR *paddr, long *no_elements, long *offset)

Obtains values from the array referenced by VAL.

#### put\_array\_info

    static long put_array_info(DBADDR *paddr, long nNew)

Writes values into the array referenced by VAL.

#### get\_units

    static long get_units(DBADDR *paddr, char *units)

Retrieves EGU.

#### get\_prec

    static long get_precision(DBADDR *paddr, long *precision)

Retrieves PREC if field is VAL field. Otherwise, calls `recGblGetPrec()`.

#### get\_graphic\_double

    static long get_graphic_double(DBADDR *paddr, struct dbr_grDouble *pgd)

Sets the upper display and lower display limits for a field. If the field is VAL
the limits are set to HOPR and LOPR, else if the field has upper and lower
limits defined they will be used, else the upper and lower maximum values for
the field type will be used.

Sets the following values:

    upper_disp_limit = HOPR
    lower_disp_limit = LOPR

#### get\_control\_double

    static long get_control_double(DBADDR *paddr, struct dbr_ctrlDouble *pcd)

Sets the upper control and the lower control limits for a field. If the field is
VAL the limits are set to HOPR and LOPR, else if the field has upper and lower
limits defined they will be used, else the upper and lower maximum values for
the field type will be used.

Sets the following values

    upper_ctrl_limit = HOPR
    lower_ctrl_limit = LOPR

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. Call device support read routine.
3. If PACT has been changed to TRUE, the device support read routine has started
but has not completed writing the new value. In this case, the processing
routine merely returns, leaving PACT TRUE.
4. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if APST or MPST are Always or if
    the result of the hash calculation is different.
    - NSEV and NSTA are reset to 0.
5. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br>
    <hr>
    <br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each waveform record must have an associated set of device support routines. The
primary responsibility of the device support routines is to obtain a new array
value whenever read\_wf is called. The device support routines are primarily
interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | No | No |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |
| RARM | Rearm the waveform | SHORT | Yes |   | Yes | Yes | Yes |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| NORD | Number elements read | ULONG | No |   | Yes | No | No |
| BUSY | Busy Indicator | SHORT | No |   | Yes | No | No |

### Device Support Routines

Device support consists of the following routines:

#### report

    long report(int level)

This optional routine is called by the IOC command `dbior` and is passed the
report level that was requested by the user.
It should print a report on the state of the device support to stdout.
The `level` parameter may be used to output increasingly more detailed
information at higher levels, or to select different types of information with
different levels.
Level zero should print no more than a small summary.

#### init

    long init(int after)

This optional routine is called twice at IOC initialization time.
The first call happens before any of the `init_record()` calls are made, with
the integer parameter `after` set to 0.
The second call happens after all of the `init_record()` calls have been made,
with `after` set to 1.

#### init\_record

    long init_record(dbCommon *precord)

This routine is optional. If provided, it is called by the record support
`init_record()` routine.

#### get\_ioint\_info

    long get_ioint_info(int cmd, dbCommon *precord, IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list.  `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### read\_wf

    long read_wf(waveformRecord *prec)

This routine must provide a new input value. It returns the following values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

The `Soft Channel` device support module is provided to read values from
other records and store them in the VAL field. If INP is a constant link, then
`read_wf()` does nothing. In this case, the record can be used to hold a fixed
set of data or array values written from elsewhere. If INP is a valid link, the
new array value is read from that link. NORD is set to the number of items
received.

If the INP link type is constant, VAL is set from it in the `init_record()`
routine and NORD is also set at that time.
