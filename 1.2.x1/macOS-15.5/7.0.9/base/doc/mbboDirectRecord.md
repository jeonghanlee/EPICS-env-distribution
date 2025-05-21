# Multi-Bit Binary Output Direct Record (mbboDirect)

The mbboDirect record performs roughly the opposite function to that of the
[mbbiDirect record](mbbiDirectRecord.md).

It can accept boolean values in its 32 bit fields (B0-B9, BA-BF, B10-B19 and
B1A-B1F), and converts them to a 32-bit signed integer in VAL which is provided
to the device support. A zero value in a bit field becomes a zero bit in VAL, a
non-zero value in a bit field becomes a one bit in VAL, with B0 being the least
signficant bit and B1F the MSB/sign bit.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The mbboDirect record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |

### Desired Output Parameters

Like all output records, the mbboDirect record must specify where its output
should originate when it gets processed. The Output Mode SeLect field (OMSL)
determines whether the output value should be read from another record or not.
When set to `closed_loop`, a 32-bit integer value (the "desired output")
will be read from a link specified in the Desired Output Link (DOL) field and
placed into the VAL field.

When OMSL is set to `supervisory`, the DOL field is ignored during
processing and the contents of VAL are used. A value to be output may thus be
written direcly into the VAL field from elsewhere as long as the record is in
`supervisory` mode.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | Yes |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| VAL | Word | LONG | Yes |   | Yes | Yes | Yes |

#### Bit Fields

The fields B0 through BF and B10 through B1F provide an alternative way to set
the individual bits of the VAL field when the record is in `supervisory`
mode. Writing to one of these fields will then modify the corresponding bit in
VAL, and writing to VAL will update these bit fields from that value.

The VAL field is signed so it can be accessed through Channel Access as an
integer; if it were made unsigned (a `DBF_ULONG`) its representation through
Channel Access would become a `double`, which could cause problems with some
client programs.

Prior to the EPICS 7.0.6.1 release the individual bit fields were not updated
while the record was in `closed_loop` mode with VAL being set from the
DOL link, and writing to the bit fields in that mode could cause the record to
process but the actual field values would not affect VAL at all. Changing the
OMSL field from `closed_loop` to `supervisory` would set the bit
fields from VAL at that time and trigger a monitor event for the bits that
changed at that time. At record initialization if VAL is defined and the OMSL
field is `supervisory` the bit fields would be set from VAL.

From EPICS 7.0.6.1 the bit fields get updated from VAL during record processing
and monitors are triggered on them in either mode. Attempts to write to the bit
fields while in `closed_loop` mode will be rejected by the `special()`
routine which may trigger an error from the client that wrote to them. During
initialization if the record is still undefined (UDF) after DOL has been read
and the device support initialized but at least one of the B0-B1F fields is
non-zero, the VAL field will be set from those fields and UDF will be cleared.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| B0 | Bit 0 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1 | Bit 1 | UCHAR | Yes |   | Yes | Yes | Yes |
| B2 | Bit 2 | UCHAR | Yes |   | Yes | Yes | Yes |
| B3 | Bit 3 | UCHAR | Yes |   | Yes | Yes | Yes |
| B4 | Bit 4 | UCHAR | Yes |   | Yes | Yes | Yes |
| B5 | Bit 5 | UCHAR | Yes |   | Yes | Yes | Yes |
| B6 | Bit 6 | UCHAR | Yes |   | Yes | Yes | Yes |
| B7 | Bit 7 | UCHAR | Yes |   | Yes | Yes | Yes |
| B8 | Bit 8 | UCHAR | Yes |   | Yes | Yes | Yes |
| B9 | Bit 9 | UCHAR | Yes |   | Yes | Yes | Yes |
| BA | Bit 10 | UCHAR | Yes |   | Yes | Yes | Yes |
| BB | Bit 11 | UCHAR | Yes |   | Yes | Yes | Yes |
| BC | Bit 12 | UCHAR | Yes |   | Yes | Yes | Yes |
| BD | Bit 13 | UCHAR | Yes |   | Yes | Yes | Yes |
| BE | Bit 14 | UCHAR | Yes |   | Yes | Yes | Yes |
| BF | Bit 15 | UCHAR | Yes |   | Yes | Yes | Yes |
| B10 | Bit 16 | UCHAR | Yes |   | Yes | Yes | Yes |
| B11 | Bit 17 | UCHAR | Yes |   | Yes | Yes | Yes |
| B12 | Bit 18 | UCHAR | Yes |   | Yes | Yes | Yes |
| B13 | Bit 19 | UCHAR | Yes |   | Yes | Yes | Yes |
| B14 | Bit 20 | UCHAR | Yes |   | Yes | Yes | Yes |
| B15 | Bit 21 | UCHAR | Yes |   | Yes | Yes | Yes |
| B16 | Bit 22 | UCHAR | Yes |   | Yes | Yes | Yes |
| B17 | Bit 23 | UCHAR | Yes |   | Yes | Yes | Yes |
| B18 | Bit 24 | UCHAR | Yes |   | Yes | Yes | Yes |
| B19 | Bit 25 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1A | Bit 26 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1B | Bit 27 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1C | Bit 28 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1D | Bit 29 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1E | Bit 30 | UCHAR | Yes |   | Yes | Yes | Yes |
| B1F | Bit 31 | UCHAR | Yes |   | Yes | Yes | Yes |

### Convert and Write Parameters

For records that are to write values to hardware devices, the OUT output link
must contain the address of the I/O card, and the DTYP field must specify
the proper device support module. Be aware that the address format differs
according to the I/O bus used. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of hardware addresses.

During record processing VAL is converted into RVAL, which is the actual 32-bit
word to be sent out. RVAL is set to VAL shifted left by the number of bits
specified in the SHFT field (SHFT is normally set by device support). RVAL is
then sent out to the location specified in the OUT field.

The fields NOBT and MASK can be used by device support to force some of the
output bits written by that support to be zero. By default all 32 bits can be
sent, but the NOBT field can be set to specify a smaller number of contiguous
bits, or MASK can specify a non-contiguous set of bits. When setting MASK it is
often necessary to set NOBT to a non-zero value as well, although in this case
the actual value of NOBT may be ignored by the device support. If a device
support sets the SHFT field it will also left-shift the value of MASK at the
same time.

For mbboDirect records writing to a link instead of to hardware, the DTYP field
must select one of the soft device support routines `Soft Channel` or
`Raw Soft Channel`. The `Soft Channel` support writes the contents
of the VAL field to the output link. The `Raw Soft Channel` support
allows SHFT to be set in the DB file, and sends the result of ANDing the shifted
MASK with the RVAL field's value.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | No | Yes |
| SHFT | Shift | USHORT | Yes |   | Yes | Yes | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| NOBT | Number of Bits | SHORT | Yes |   | Yes | No | No |

### Operator Display Parameters

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Run-time Parameters

These parameters are used by the run-time code for processing the mbbo Direct
record.

MASK is used by device support routine to read the hardware register. Record
support sets the low order NOBT bits of MASK at initialization, and device
support is allowed to shift this value.

MLST holds the value when the last monitor for value change was triggered.
OBIT has a similar role for bits held in the B0-B1F fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NOBT | Number of Bits | SHORT | Yes |   | Yes | No | No |
| ORAW | Prev Raw Value | ULONG | No |   | Yes | No | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| MLST | Last Value Monitored | LONG | No |   | Yes | No | No |
| OBIT | Last Bit mask Monitored | LONG | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML) is YES, the record is put in SIMS
severity and the value is written through SIOL, without conversion.
If SIMM is RAW, the value is converted and RVAL is written.
SSCN sets a different SCAN mechanism to use in simulation mode.
SDLY sets a delay (in sec) that is used for asynchronous simulation
processing.

See [Output Simulation Fields](dbCommonOutput.md#Output-Simulation-Fields)
for more information on simulation mode and its fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SIML | Simulation Mode Link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuSimm](menuSimm.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Output Link | OUTLINK | Yes |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

### Alarm Parameters

The possible alarm conditions for mbboDirect records are the SCAN, READ, and
INVALID alarms.

The IVOA field specifies an action to take when an INVALID alarm is triggered.
There are three possible actions: `Continue normally`, `Don't drive
outputs`, or `Set output to IVOV`. When `Set output to IVOV` is
specified and a INVALID alarm is triggered, the record will write the value in
the IVOV field to the output.

See [Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for more information about IVOA and IVOV.

See [Alarm Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#alarm-specification)
for a complete explanation of record alarms and of the standard fields.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related
to alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| IVOA | INVALID outpt action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID output value | LONG | Yes |   | Yes | Yes | No |

## Record Support

### Record Support Routines

#### init\_record

This routine initializes SIMM if SIML is a constant or creates a channel access
link if SIML is PV\_LINK. If SIOL is PV\_LINK a channel access link is created.

This routine next checks to see that device support is available.The routine
next checks to see if the device support write routine is defined. If either
device support or the device support write routine does not exist, an error
message is issued and processing is terminated.

If DOL is a constant, then VAL is initialized to its value and UDF is set to
FALSE.

MASK is cleared and then the NOBT low order bits are set.

If device support includes `init_record()`, it is called.

If device support returns success, VAL is then set from RVAL and UDF is set to
FALSE.

#### Process

See next section.

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. If PACT is FALSE
    - If DOL is DB\_LINK and OMSL is CLOSED\_LOOP
        - Get value from DOL
        - Set PACT to FALSE
3. Convert
    - If PACT is FALSE, compute RVAL
        - Set RVAL = VAL
        - Shift RVAL left SHFT bits
    - Status=write\_mbboDirect
4. If PACT has been changed to TRUE, the device support write output routine has
started but has not completed writing the new value. In this case, the
processing routine merely returns, leaving PACT TRUE.
5. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if MLST is not equal to VAL.
    - Monitors for RVAL and RBV are checked whenever other monitors are invoked.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br><hr><br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each mbboDirect record must have an associated set of device support routines.
The primary responsibility of the device support routines is to obtain a new raw
mbbo value whenever write\_mbboDirect is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| NOBT | Number of Bits | SHORT | Yes |   | Yes | No | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| RVAL | Raw Value | ULONG | No |   | Yes | No | Yes |
| RBV | Readback Value | ULONG | No |   | Yes | No | No |
| MASK | Hardware Mask | ULONG | No |   | Yes | No | No |
| SHFT | Shift | USHORT | Yes |   | Yes | Yes | No |

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

This routine is optional. If provided, it is called by the record support
`init_record()` routine. If MASK is used, it should be shifted if necessary and
SHFT given a value.

#### get\_ioint\_info

    get_ioint_info(int cmd,struct dbCommon *precord,IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### write\_mbboDirect

    write_mbboDirect(precord)

This routine must output a new value. It returns the following values:

- 0: Success.
- Other: Error.

### Device Support For Soft Records

This `SOft Channel` module writes the current value of VAL.

If the OUT link type is PV\_LINK, then dbCaAddInlink is called by
`init_record()`.

write\_mbboDirect calls recGblPutLinkValue to write the current value of VAL.

See [Soft Output](Soft_Output.md).
