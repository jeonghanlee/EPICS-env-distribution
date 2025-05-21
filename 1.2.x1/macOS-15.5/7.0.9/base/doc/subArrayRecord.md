# Sub-Array Record (subArray)

The normal use for the subArray record type is to obtain sub-arrays from
waveform records. Setting either the number of elements (NELM) or index (INDX)
fields causes the record to be processed anew so that applications in which the
length and position of a sub-array in a waveform record vary dynamically can be
implemented using standard EPICS operator interface tools.

The first element of the sub-array, that at location INDX in the referenced
waveform record, can be displayed as a scalar, or the entire subarray (of length
NELM) can be displayed in the same way as a waveform record. If there are fewer
than NELM elements in the referenced waveform after the INDX, only the number of
elements actually available are returned, and the number of elements read field
(NORD) is set to reflect this. This record type does not support writing new
values into waveform records.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The subArray record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read Parameters

The subArray's input link (INP) should be configured to reference the Waveform
record. It should specify the VAL field of a Waveform record. The INP field can
be a channel access link, in addition to a database link.

In addition, the DTYP field must specify a device support module. Currently, the
only device support module is `Soft Channel`.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |

### Array Parameters

These parameters determine the number of array elements (the array length) and
the data type of those elements. The Field Type of Value (FTVL) field determines
the data type of the array.

The user specifies the maximum number of elements that can be read into the
subarray in the MALM field. This number should normally be equal to the number
of elements of the Waveform array (found in the Waveform's NELM field). The MALM
field is used to allocate memory. The subArray's Number of Elements (NELM) field
is where the user specifies the actual number of elements that the subArray will
extract. It should of course be no greater than MALM; if it is, the record
processing routine sets it equal to MALM.

The INDX field determines the offset of the subArray record's array in relation
to the Waveform's. For instance, if INDX is 2, then the subArray will read NELM
elements starting with the third element of the Waveform's array. Thus, it
equals the index number of the Waveform's array.

The actual sub-array is referenced by the VAL field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |
| VAL | Value | Set by FTVL | No |   | Yes | Yes | Yes |
| MALM | Maximum Elements | ULONG | Yes | 1 | Yes | No | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | Yes | Yes |
| INDX | Substring Index | ULONG | Yes |   | Yes | Yes | Yes |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the subarray record either textually
or graphically.

EGU is a string of up to 16 characters describing the engineering units (if any)
of the values which the subArray holds. It is retrieved by the `get_units()`
record support routine.

The HOPR and LOPR fields set the upper and lower display limits for the
sub-array elements. Both the `get_graphic_double()` and `get_control_double()`
record support routines retrieve these fields.

The PREC field determines the floating point precision with which to display
VAL. It is used whenever the `get_precision()` record support routine is
called.

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

The subarray record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Run-time Parameters

These fields are not configurable by the user. They are used for the record's
internal processing or to represent the current state of the record.

The NORD field holds the number of elements that were actually read into the
array. It will be less than NELM whenever the sum of the NELM and INDX fields
exceeds the number of existing elements found in the source array.

BPTR contains a pointer to the record's array.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NORD | Number elements read | LONG | No |   | Yes | No | No |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |

<div>
    <br>
    <hr>
    <br>
</div>

## Record Support

### Record Support Routines

#### init\_record

    long (*init_record)(struct dbCommon *precord, int pass)

Using MALM and FTVL, space for the array is allocated. The array address is
stored in BPTR. This routine checks to see that device support is available and
a device support read routine is defined. If either does not exist, an error
message is issued and processing is terminated. If device support includes
`init_record()`, it is called.

#### process

    long (*process)(struct dbCommon *precord)

See ["Record Processing"](#record-processing).

#### cvt\_dbaddr

    long (*cvt_dbaddr)(struct dbAddr *paddr)

This is called by `dbNameToAddr()`. It makes the dbAddr structure refer to the
actual buffer holding the result.

#### get\_array\_info

    long (*get_array_info)(struct dbAddr *paddr, long *no_elements, long *offset)

Retrieves NORD.

#### put\_array\_info

    long (*put_array_info)(struct dbAddr *paddr, long nNew)

Sets NORD.

#### get\_graphic\_double

    long (*get_graphic_double)(struct dbAddr *paddr, struct dbr_grDouble *p)

For the elements in the array, this routine routines HOPR and LOPR. For the INDX
field, this routine returns MALM - 1 and 0. For NELM, it returns MALM and 1. For
other fields, it calls `recGblGetGraphicDouble()`.

#### get\_control\_double

    long (*get_control_double)(struct dbAddr *paddr, struct dbr_ctrlDouble *p)

For array elements, this routine retrieves HOPR and LOPR. Otherwise,
`recGblGetControlDouble()` is called.

#### get\_units

    long (*get_units)(struct dbAddr *paddr, char *units)

Retrieves EGU.

#### get\_precision

    long (*get_precision)(const struct dbAddr *paddr, long *precision)

Retrieves PREC.

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. Sanity check NELM and INDX. If NELM is greater than MALM it is set to MALM. If
INDX is greater than or equal to MALM it is set to MALM-1.
3. Call the device support's `read_sa()` routine. This routine is expected to
place the desired sub-array at the beginning of the buffer and set NORD to the
number of elements of the sub-array that were read.
4. If PACT has been changed to TRUE, the device support read operation has started
but has not completed writing the new value. In this case, the processing
routine merely returns, leaving PACT TRUE. Otherwise, process sets PACT TRUE at
this time. This asynchronous processing logic is not currently used but has been
left in place.
5. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are always invoked.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br>
    <hr>
    <br>
</div>

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
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| FTVL | Field Type of Value | MENU [menuFtype](menuFtype.md) | Yes |   | Yes | No | No |
| MALM | Maximum Elements | ULONG | Yes | 1 | Yes | No | No |
| NELM | Number of Elements | ULONG | Yes | 1 | Yes | Yes | Yes |
| INDX | Substring Index | ULONG | Yes |   | Yes | Yes | Yes |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| NORD | Number elements read | LONG | No |   | Yes | No | No |

### Device Support Routines (devSASoft.c)

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

    long init_record(subArrayRecord *prec)

This routine is called by the record support `init_record()` routine.

#### read\_sa

    long read_sa(subArrayRecord *prec)

Enough of the source waveform is read into BPTR, from the beginning of the
source, to include the requested sub-array. The sub-array is then copied to the
beginning of the buffer. NORD is set to indicate how many elements of the
sub-array were acquired.

### Device Support For Soft Records

Only the device support module `Soft Channel` is currently provided.

#### Soft Channel

INP is expected to point to an array field of a waveform record or similar.
