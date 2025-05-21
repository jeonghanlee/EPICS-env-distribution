# Array Analog Input (aai)

The array analog input record type is used to read array data. The array data can
contain any of the supported data types. The record is in many ways similar to the
waveform record. It allows, however, the device support to allocate the array
storage.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The array analog input record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read Parameters

These fields are configurable by the user to specify how and from where the record
reads its data. The INP field determines from where the array analog input gets
its input. It can be a hardware address, a channel access or database link, or a
constant. Only in records that use soft device support can the INP field be a
channel access link, a database link, or a constant. Otherwise, the INP field must
be a hardware address.

#### Fields related to waveform reading

The DTYP field must contain the name of the appropriate device support module.
The values retrieved from the input link are placed in an array referenced by
VAL. (If the INP link is a constant, elements can be placed in the array via
dbPuts.) NELM specifies the number of elements that the array will hold, while
FTVL specifies the data type of the elements (follow the link in the table below
for a list of the available choices).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | No | No |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the waveform either textually or
graphically.

#### Fields related to _Operator Display_

EGU is a string of up to 16 characters describing the units that the array data
measures. It is retrieved by the `get_units()` record support routine.

The HOPR and LOPR fields set the upper and lower display limits for array
elements referenced by the VAL field. Both the `get_graphic_double()` and
`get_control_double()` record support routines retrieve these fields.

The PREC field determines the floating point precision with which to display the
array values. It is used whenever the `get_precision()` record support
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

The array analog input record has the alarm parameters common to all record types.

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the VAL
field. The APST and MPST fields are a menu with choices `Always` and `On
Change`. The default is `Always`, thus monitors will normally be sent every time
the record processes. Selecting `On Change` causes a 32-bit hash of the VAL
field buffer to be calculated and compared with the previous hash value every
time the record processes; the monitor will only be sent if the hash is
different, indicating that the buffer has changed. Note that there is a small
chance that two different value buffers might result in the same hash value, so
for critical systems `Always` may be a better choice, even though it re-sends
duplicate data.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| APST | Post Archive Monitors | MENU [aaiPOST](#menu-aaipost) | Yes |   | Yes | Yes | No |
| MPST | Post Value Monitors | MENU [aaiPOST](#menu-aaipost) | Yes |   | Yes | Yes | No |
| HASH | Hash of OnChange data. | ULONG | No |   | Yes | Yes | No |

#### Menu aaiPOST

These are the possible choices for the `APST` and `MPST` fields:

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | aaiPOST\_Always | Always |
| 1 | aaiPOST\_OnChange | On Change |

### Run-time Parameters

These parameters are used by the run-time code for processing the array analog
input record. They are not configured using a configuration tool. Only the VAL
field is modifiable at run-time.

VAL references the array where the array analog input record stores its data. The
BPTR field holds the address of the array.

The NORD field holds a counter of the number of elements that have been read
into the array.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Value | DOUBLE\[NELM\] | No |   | Yes | Yes | Yes |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| NORD | Number elements read | ULONG | No |   | Yes | No | No |

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

    static long init_record(aaiRecord *prec, int pass)

If device support includes an `init_record()` routine it is called, but unlike
most record types this occurs in pass 0, which allows the device support to
allocate the array buffer itself.

Since EPICS 7.0.5 the device support may return `AAI_DEVINIT_PASS1` to request
a second call to its `init_record()` routine in pass 1.

Checks if device support allocated array space. If not, space for the array is
allocated using NELM and FTVL. The array address is stored in BPTR.

This routine initializes SIMM with the value of SIML if SIML type is CONSTANT
link or creates a channel access link if SIML type is PV\_LINK. VAL is likewise
initialized if SIOL is CONSTANT or PV\_LINK.

This routine next checks to see that device support is available and a device
support read routine is defined. If either does not exist, an error message is
issued and processing is terminated

#### process

    static long process(aaiRecord *prec)

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
2. Call device support read routine `read_aai()`.
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

Each array analog input record record must have an associated set of device
support routines. The primary responsibility of the device support routines is to
obtain a new array value whenever `read_aai()` is called. The device support
routines are primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
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

This routine is optional.
If provided, it is called by the record support's `init_record()` routine in
pass 0.
The device support may allocate memory for the VAL field's array (enough space
for NELM elements of type FTVA) from its own memory pool if desired, and store
the pointer to this buffer in the BPTR field.
The record will use `calloc()` for this memory allocation if BPTR has not been
set by this routine.
The routine must return 0 for success, -1 or a error status on failure.

Since EPICS 7.0.5 if this routine returns `AAI_DEVINIT_PASS1` in pass 0, it
will be called again in pass 1 with the PACT field set to `AAI_DEVINIT_PASS1`.
In pass 0 the PACT field is set to zero (FALSE).

#### get\_ioint\_info

    long get_ioint_info(int cmd, dbCommon *precord, IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list.  `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### read\_aai

    long read_aai(dbCommon *precord)

This routine should provide a new input value.
It returns the following values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

The `Soft Channel` device support is provided to read values from other
records via the INP link, or to hold array values that are written into it.

If INP is a constant link the array value gets loaded from the link constant by
the `record_init()` routine, which also sets NORD.
The `read_aai()` routine does nothing in this case.

If INP is a database or channel access link, the `read_aai()` routine gets a
new array value from the link and sets NORD.
