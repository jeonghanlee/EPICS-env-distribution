# Array Analog Output (aao)

The array analog output record type is used to write array data. The array data
can contain any of the supported data types. The record is in many ways similar
to the waveform record but outputs arrays instead of reading them. It also
allows the device support to allocate the array storage.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The array analog output record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |

### Write Parameters

These fields are configurable by the user to specify how and where to the record
writes its data. The OUT field determines where the array analog output writes
its output. It can be a hardware address, a channel access or database link, or
a constant. Only in records that use soft device support can the OUT field be a
channel access link, a database link, or a constant. Otherwise, the OUT field
must be a hardware address. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of hardware addresses and database links.

#### Fields related to array writing

The DTYP field must contain the name of the appropriate device support module.
The values in the array referenced by are written to the location specified in
the OUT field. (If the OUT link is a constant, no data are written.) NELM
specifies the maximum number of elements that the array can hold, while FTVL
specifies the data type of the elements (follow the link in the table below for
a list of the available choices).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | No | No |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the waveform either textually or
graphically.

#### Fields related to _Operator Display_

EGU is a string of up to 16 characters describing the units that the array data
measures. It is retrieved by the `get_units` record support routine.

The HOPR and LOPR fields set the upper and lower display limits for array
elements referenced by the VAL field. Both the `get_graphic_double` and
`get_control_double` record support routines retrieve these fields.

The PREC field determines the floating point precision with which to display the
array values. It is used whenever the `get_precision` record support
routine is called.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The array analog output record has the alarm parameters common to all record
types.

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the VAL
field. The APST and MPST fields are a menu with choices "Always" and "On
Change". The default is "Always", thus monitors will normally be sent every time
the record processes. Selecting "On Change" causes a 32-bit hash of the VAL
field buffer to be calculated and compared with the previous hash value every
time the record processes; the monitor will only be sent if the hash is
different, indicating that the buffer has changed. Note that there is a small
chance that two different value buffers might result in the same hash value, so
for critical systems "Always" may be a better choice, even though it re-sends
duplicate data.

#### Record fields related to _Monitor Parameters_

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| APST | Post Archive Monitors | MENU [aaoPOST](#menu-aaopost) | Yes |   | Yes | Yes | No |
| MPST | Post Value Monitors | MENU [aaoPOST](#menu-aaopost) | Yes |   | Yes | Yes | No |
| HASH | Hash of OnChange data. | ULONG | No |   | Yes | Yes | No |

#### Menu aaoPOST

These are the choices available for the `APST` and `MPST` fields

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | aaoPOST\_Always | Always |
| 1 | aaoPOST\_OnChange | On Change |

### Run-time Parameters

These parameters are used by the run-time code for processing the array analog
output record. They are not configured using a configuration tool. Only the VAL
field is modifiable at run-time.

VAL references the array where the array analog output record stores its data.
The BPTR field holds the address of the array.

The NORD field holds a counter of the number of elements that have been written
to the output,

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Value | DOUBLE\[\] | No |   | Yes | Yes | Yes |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| NORD | Number elements read | ULONG | No |   | Yes | No | No |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |

The following steps are performed in order during record processing.

#### Fetch Value

The OMSL menu field is used to determine whether the DOL link
field should be used during processing or not:

- If OMSL is `supervisory` the DOL field are not used.
The new output value is taken from the VAL field, which may have been set from
elsewhere.
- If OMSL is `closed_loop` the DOL link field is read to obtain a value.

Note: The OMSL and DOL fields were added to the aaoRecord in Base 7.0.7.

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
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Output Link | OUTLINK | Yes |   | Yes | Yes | No |
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

    static long init_record(aaoRecord *prec, int pass)

If device support includes `init_record()`, it is called.

Checks if device support allocated array space. If not, space for the array is
allocated using NELM and FTVL. The array address is stored in the record.

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. VAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a device
support write routine is defined. If either does not exist, an error message is
issued and processing is terminated

#### process

    static long process(aaoRecord *prec)

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
2. Call device support write routine `write_aao`.
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

Each array analog output record record must have an associated set of device
support routines. The primary responsibility of the device support routines is
to write the array data value whenever `write_aao()` is called. The device
support routines are primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | No | No |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| NORD | Number elements read | ULONG | No |   | Yes | No | No |

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

#### write\_aao

    long write_aao(dbCommon *precord)

This routine must write the array data to output. It returns the following
values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

The `Soft Channel` device support module is provided to write values to
other records and store them in arrays. If OUT is a constant link, then
`write_aao()` does nothing. In this case, the record can be used to hold arrays
written via dbPuts. If OUT is a database or channel access link, the array value
is written to the link. NORD is set to the number of items in the array.

If the OUT link type is constant, then NORD is set to zero.
