# Compression Record (compress)

The data compression record is used to collect and compress data from arrays.
When the INP field references a data array field, it immediately compresses the
entire array into an element of an array using one of several algorithms,
overwriting the previous element. If the INP field obtains its value from a
scalar-value field, the compression record will collect a new sample each time
the record is processed and add it to the compressed data array as a circular
buffer.

The INP link can also specify a constant; however, if this is the case, the
compression algorithms are ignored, and the record support routines merely
return after checking the FLNK field.

## Record-specific Menus

### Menu compressALG

The ALG field which uses this menu controls the compression algorithm used by
the record.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | compressALG\_N\_to\_1\_Low\_Value | N to 1 Low Value |
| 1 | compressALG\_N\_to\_1\_High\_Value | N to 1 High Value |
| 2 | compressALG\_N\_to\_1\_Average | N to 1 Average |
| 3 | compressALG\_Average | Average |
| 4 | compressALG\_Circular\_Buffer | Circular Buffer |
| 5 | compressALG\_N\_to\_1\_Median | N to 1 Median |

### Menu bufferingALG

The BALG field which uses this menu controls whether new values are inserted at
the beginning or the end of the VAL array.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | bufferingALG\_FIFO | FIFO Buffer |
| 1 | bufferingALG\_LIFO | LIFO Buffer |

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scanning Parameters

The compression record has the standard fields for specifying under what
circumstances the record will be processed. Since  the compression record
supports no direct interfaces to hardware, its SCAN field cannot be set to `I/O Intr`.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |

### Algorithms and Related Parameters

The user specifies the algorithm to be used in the ALG field. There are six possible
algorithms which can be specified as follows:

#### Menu compressALG

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | compressALG\_N\_to\_1\_Low\_Value | N to 1 Low Value |
| 1 | compressALG\_N\_to\_1\_High\_Value | N to 1 High Value |
| 2 | compressALG\_N\_to\_1\_Average | N to 1 Average |
| 3 | compressALG\_Average | Average |
| 4 | compressALG\_Circular\_Buffer | Circular Buffer |
| 5 | compressALG\_N\_to\_1\_Median | N to 1 Median |

The following fields determine what channel to read and how to compress the data:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ALG | Compression Algorithm | MENU [compressALG](#menu-compressalg) | Yes |   | Yes | Yes | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
| NSAM | Number of Values | ULONG | Yes | 1 | Yes | No | No |
| N | N to 1 Compression | ULONG | Yes | 1 | Yes | Yes | No |
| ILIL | Init Low Interest Lim | DOUBLE | Yes |   | Yes | Yes | No |
| IHIL | Init High Interest Lim | DOUBLE | Yes |   | Yes | Yes | No |
| OFF | Offset | ULONG | No |   | Yes | No | No |
| RES | Reset | SHORT | No |   | Yes | Yes | No |
| PBUF | Use Partial buffers | MENU [menuYesNo](menuYesNo.md) | Yes | NO | Yes | Yes | No |

As stated above, the ALG field specifies which algorithm to be performed on the data.

The INP should be a database or channel access link. Though INP can be a
constant, the data compression algorithms are supported only when INP is a
database link. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on specifying links.

IHIL and ILIL can be set to provide an initial value filter on the input array.
If ILIL < IHIL, the input elements will be skipped until a value is found
that is in the range of ILIL to IHIL. Note that ILIL and IHIL are used only in
`N to 1` algorithms.

OFF provides the offset to the current beginning of the array data.
Note that OFF is used only in `N to 1` algorithms.

The RES field can be accessed at run time to cause the algorithm to reset
itself before the maximum number of samples are reached.

#### Algorithms

**Circular Buffer** algorithm keeps a circular buffer of length NSAM.
Each time the record is processed, it gets the data referenced by INP and puts
it into the circular buffer referenced by VAL. The INP can refer to both scalar or
array data and VAL is just a time ordered circular buffer of  values obtained
from INP.
Note that N, ILIL, IHIL and OFF are not used in `Circular Buffer` algorithm.

**Average** takes an average of every element of the array obtained from
INP over time; that is, the entire array referenced by INP is retrieved, and for
each element, the new average is calculated and placed in the corresponding
element of the value buffer. The retrieved array is truncated to be of length
NSAM. N successive arrays are averaged and placed in the buffer. Thus, VAL\[0\]
holds the average of the first element of INP over N samples, VAL\[1\] holds the
average of the next element of INP over N samples, and so on. The following
shows the equation:

<div>
    <img src="image/compress-1.png">
</div>

**N to 1** If any of the `N to 1` algorithms are chosen, then VAL is a circular
buffer of NSAM samples.
The actual algorithm depends on whether INP references a scalar or an array.

If INP refers to a scalar, then N successive time ordered samples of INP are taken.
After the Nth sample is obtained, a new value determined by the algorithm
(Lowest, Highest, or Average), is written to the circular buffer referenced by
VAL. If `Low Value` the lowest value of all the samples is written; if
`High Value` the highest value is written; and if `Average`, the
average of all the samples are written.  The `Median` setting behaves
like `Average` with scalar input data.

If INP refers to an array, then the following applies:

- `N to 1 Low Value`

    Compress N to 1 samples, keeping the lowest value.

- `N to 1 High Value`

    Compress N to 1 samples, keeping the highest value.

- `N to 1 Average`

    Compress N to 1 samples, taking the average value.

- `N to 1 Median`

    Compress N to 1 samples, taking the median value.

The behaviour of the record for partially filled buffers depends on the field PBUF.
If PBUF is set to NO, then the record will wait until the buffer is completely full
before processing. If PBUF is set to YES, then it will start processing immediately.

For example, if ALG is set to `N to 1 Average` with NSAM equal to 4, N equal
to 1, and PBUF set to NO, then the first three times that the compress record is
processed it will remain in an undefined state. On the fourth process, the average
of all four records will be calculated and placed into the VAL field.

If PBUF is set to YES, then after each process the average of the first several
elements will be calculated.

Note that PBUF has no impact on the `Average` method. If one wishes to have a
rolling average computed, then the best way to achieve that is with two compress
records: a `Circular buffer` which is linked to an `N to 1 Average`
record with PBUF set to YES.

The compression record keeps NSAM data samples.

The field N determines the number of elements to compress into each result.

Thus, if NSAM was 3, and N was also equal to 3, then the algorithms would work
as in the following diagram:

<div>
    <img src="image/compress-2.png">
</div>

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the record either textually or
graphically.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

The EGU field should be given a string that describes the value of VAL, but is
used whenever the `get_units` record support routine is called.

The HOPR and LOPR fields only specify the upper and lower display limits for
VAL, HIHI, HIGH, LOLO and LOW fields.

PREC controls the floating-point precision whenever `get_precision` is
called, and the field being referenced is the VAL field (i.e., one of the values
contained in the circular buffer).

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

### Alarm Parameters

The compression record has the alarm parameters common to all record types
described in [Alarm Fields](dbCommonRecord.md#Alarm-Fields).

### Run-time Parameters

These parameters are used by the run-time code for processing the data
compression algorithm. They are not configurable by the user, though some are
accessible at run-time. They can represent the current state of the algorithm or
of the record whose field is referenced by the INP field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NUSE | Number Used | ULONG | No |   | Yes | No | No |
| OUSE | Old Number Used | ULONG | No |   | Yes | No | No |
| BPTR | Buffer Pointer | NOACCESS | No |   | No | No | No |
| SPTR | Summing Buffer Ptr | NOACCESS | No |   | No | No | No |
| WPTR | Working Buffer Ptr | NOACCESS | No |   | No | No | No |
| CVB | Compress Value Buffer | DOUBLE | No |   | Yes | No | No |
| INPN | Number of elements in Working Buffer | LONG | No |   | Yes | No | No |
| INX | Current number of readings | ULONG | No |   | Yes | No | No |

NUSE and OUSE hold the current and previous number of elements stored in VAL.

BPTR points to the buffer referenced by VAL.

SPTR points to an array that is used for array averages.

WPTR points to the buffer containing data referenced by INP.

CVB stores the current compressed value for `N to 1` algorithms when INP
references a scalar.

INPN is updated when the record processes; if INP references an array and the
size changes, the WPTR buffer is reallocated.

INX counts the number of readings collected.

## Record Support

### Record Support Routines

    long init_record(struct dbCommon *precord, int pass)

Space for all necessary arrays is allocated. The addresses are stored in the
appropriate fields in the record.

    long process(struct dbCommon *precord)

See ["Record Processing"](#record-processing) below.

    long special(struct dbAddr *paddr, int after)

This routine is called when RSET, ALG, or N are set. It performs a reset.

    long cvt_dbaddr(struct dbAddr *paddr)

This is called by dbNameToAddr. It makes the dbAddr structure refer to the
actual buffer holding the result.

    long get_array_info(struct dbAddr *paddr, long *no_elements, long *offset)

Obtains values from the circular buffer referenced by VAL.

    long put_array_info(struct dbAddr *paddr, long nNew);

Writes values into the circular buffer referenced by VAL.

    long get_units(struct dbAddr *paddr, char *units);

Retrieves EGU.

    long get_precision(const struct dbAddr *paddr, long *precision);

Retrieves PREC.

    long get_graphic_double(struct dbAddr *paddr, struct dbr_grDouble *p);

Sets the upper display and lower display limits for a field. If the field is
VAL, the limits are set to HOPR and LOPR, else if the field has upper and lower
limits defined they will be used, else the upper and lower maximum values for
the field type will be used.

    long get_control_double(struct dbAddr *paddr, struct dbr_ctrlDouble *p);

Sets the upper control and the lower control limits for a field. If the field is
VAL, the limits are set to HOPR and LOPR, else if the field has upper and lower
limits defined they will be used, else the upper and lower maximum values for
the field type will be used.

### Record Processing

Routine process implements the following algorithm:

1. If INP is not a database link, check monitors and the forward link and return.
2. Get the current data referenced by INP.
3. Perform the appropriate algorithm:
    - Average: Read N successive instances of INP and perform an element by element
    average. Until N instances have been obtained it just return without checking
    monitors or the forward link. When N instances have been obtained complete the
    algorithm, store the result in the VAL array, check monitors and the forward
    link, and return.
    - Circular Buffer: Write the values obtained from INP into the VAL array as a
    circular buffer, check monitors and the forward link, and return.
    - N to 1 xxx when INP refers to a scalar: Obtain N successive values from INP and
    apply the N to 1 xxx algorithm to these values. Until N values are obtained
    monitors and forward links are not triggered. When N successive values have been
    obtained, complete the algorithm, check monitors and trigger the forward link,
    and return.
    - N to 1 xxx when INP refers to an array: The ILIL and IHIL are honored if ILIL
    < IHIL. The input array is divided into subarrays of length N. The specified
    N to 1 xxx compression algorithm is applied to each sub-array and the result
    stored in the array referenced by VAL. The monitors and forward link are
    checked.
4. If success, set UDF to FALSE.
5. Check to see if monitors should be invoked:
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.
