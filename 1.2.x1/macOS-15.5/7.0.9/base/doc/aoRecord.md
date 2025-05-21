# Analog Output Record (ao)

This record type is normally used to send an analog value to an output device,
converting it from engineering units into an integer value if necessary.
The record supports alarm and drive limits, rate-of-change limiting, output
value integration, linear and break-point conversion from engineering units, and
graphics and control limits.

## Record-specific Menus

### Menu aoOIF

The OIF field which uses this menu controls whether the record acts as an
integrator (`Incremental`) or not (`Full`).

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | aoOIF\_Full | Full |
| 1 | aoOIF\_Incremental | Incremental |

## Parameter Fields

The record-specific fields are described below.

### Output Value Determination

These fields control how the record determines the value to be output when it
gets processed:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| OIF | Out Full/Incremental | MENU [aoOIF](#menu-aooif) | Yes |   | Yes | Yes | No |
| PVAL | Previous value | DOUBLE | No |   | Yes | No | No |
| DRVH | Drive High Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| DRVL | Drive Low Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| VAL | Desired Output | DOUBLE | Yes |   | Yes | Yes | Yes |
| OROC | Output Rate of Change | DOUBLE | Yes |   | Yes | Yes | No |
| OVAL | Output Value | DOUBLE | No |   | Yes | Yes | No |

The following steps are performed in order during record processing.

#### Fetch Value, Integrate

The OMSL menu field is used to determine whether the DOL link and OIF menu
fields should be used during processing or not:

- If OMSL is `supervisory` the DOL and OIF fields are not used.
The new output value is taken from the VAL field, which may have been set from
elsewhere.
- If OMSL is `closed_loop` the DOL link field is read to obtain a value; if OIF
is `Incremental` and the DOL link was read successfully, the record's previous
output value PVAL is added to it.

#### Drive Limits

The output value is now clipped to the range DRVL to DRVH inclusive, provided
that DRVH > DRVL.
The result is copied into both the VAL and PVAL fields.

#### Limit Rate of Change

If the OROC field is not zero, the VAL field is now adjusted so it is no more
than OROC different to the previous output value given in OVAL.
OROC thus determines the maximum change in the output value that can occur each
time the record gets processed.
The result is copied into the OVAL field, which is used as the input to the
following Units Conversion processing stage.

### Units Conversion

...

For analog output records that do not use the Soft Channel device support
routine, the specified conversions (if any) are performed on the OVAL field and
the resulting value in the RVAL field is sent to the address contained in the
output link after it is adjusted by the values in the AOFF and ASLO fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| LINR | Linearization | MENU [menuConvert](menuConvert.md) | Yes |   | Yes | Yes | Yes |
| RVAL | Current Raw Value | LONG | No |   | Yes | Yes | Yes |
| ROFF | Raw Offset | ULONG | No |   | Yes | Yes | Yes |
| EGUF | Eng Units Full | DOUBLE | Yes |   | Yes | Yes | Yes |
| EGUL | Eng Units Low | DOUBLE | Yes |   | Yes | Yes | Yes |
| AOFF | Adjustment Offset | DOUBLE | Yes |   | Yes | Yes | Yes |
| ASLO | Adjustment Slope | DOUBLE | Yes |   | Yes | Yes | Yes |
| ESLO | EGU to Raw Slope | DOUBLE | Yes | 1 | Yes | Yes | Yes |
| EOFF | EGU to Raw Offset | DOUBLE | Yes |   | Yes | Yes | Yes |

#### Conversion Related Fields and the Conversion Process

Except for analog outputs that use Soft Channel device support, the LINR field
determines if a conversion is performed and which conversion algorithm is used
to convert OVAL to RVAL.

The LINR field can specify `LINEAR` or `SLOPE` for linear conversions,
`NO CONVERSION` for no conversions at all, or the name of a breakpoint table
such as `typeKdegC` for breakpoint conversions.

The EGUF and EGUL fields should be set for `LINEAR` conversions, and the ESLO
and EOFF fields for `SLOPE` conversion. Note that none of these fields have any
significance for records that use the Soft Channel device support module.

- EGUF, EGUF

    The user must set these fields when configuring the database for records
    that use `LINEAR` conversions.
    They are used to calculate the values for ESLO and EOFF.
    See Conversion Specification for more information on how to calculate these
    fields.

- ESLO, EOFF

    Computed by device support from EGUF and EGUL when LINR specifies `LINEAR`.
    These values must be supplied by the user when LINR specifies `SLOPE`.
    Used only when LINR is `LINEAR` or `SLOPE`.

- AOFF, ASLO

    These fields are adjustment parameters for the raw output values.
    They are applied to the raw output value after conversion from engineering
    units.

- ROFF

    This field can be used to offset the raw value generated by the conversion
    process, which is needed for some kinds of hardware.

Conversion proceeds as follows:

- 1. If LINR==LINEAR or LINR==SLOPE, then X = (VAL - EOFF) / ESLO,
else if LINR==NO\_CONVERSION, then X = VAL,
else X is obtained via breakpoint table.
- 2. X = (X - AOFF) / ASLO
- 3. RVAL = round(X) - ROFF

To see how the Raw Soft Channel device support routine uses these
fields, see ["Device Support For Soft Records"](#device-support-for-soft-records) below for more
information.

### Output Specification

The analog output record sends its desired output to the address in the
OUT field. For analog outputs that write their values to devices, the
OUT field must specify the address of the I/O card. In addition, the
DTYP field must contain the name of the device support module. Be aware
that the address format differs according to the I/O bus used. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on the format of hardware addresses.

For soft records the output link can be a database link, a channel
access link, or a constant value. If the link is a constant, no output
is sent.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator.
They display the value and other parameters of the analog output either
textually or graphically.

EGU is a string of up to 16 characters describing the units that the
analog output measures. It is retrieved by the get\_units record support
routine.

The HOPR and LOPR fields set the upper and lower display limits for the
VAL, OVAL, PVAL, HIHI, HIGH, LOW, and LOLO fields. Both the
get\_graphic\_double and get\_control\_double record support routines
retrieve these fields. If these values are defined, they must be in the
range: DRVL <= LOPR <= HOPR <= DRVH.

The PREC field determines the floating point precision with which to
display VAL, OVAL and PVAL. It is used whenever the get\_precision
record support routine is called.

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

The possible alarm conditions for analog outputs are the SCAN, READ,
INVALID and limit alarms. The SCAN, READ, and INVALID alarms are called
by the record or device support routines.

The limit alarms are configured by the user in the HIHI, LOLO, HIGH,
and LOW fields, which must be floating-point values. For each of these
fields, there is a corresponding severity field which can be either
NO\_ALARM, MINOR, or MAJOR.

See [Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for more information on the IVOA and IVOV fields.

[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists other fields related to a
alarms that are common to all record types.

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
| IVOA | INVALID output action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID output value | DOUBLE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to specify deadbands for monitors on the VAL
field. The monitors are sent when the value field exceeds the last
monitored field by the specified deadband. If these fields have a value
of zero, everytime the value changes, a monitor will be triggered; if
they have a value of -1, everytime the record is processed, monitors
are triggered. ADEL is the deadband for archive monitors, and MDEL the
deadband for all other types of monitors. See Monitor Specification for
a complete explanation of monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | DOUBLE | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | DOUBLE | Yes |   | Yes | Yes | No |

### Run-time Parameters

These parameters are used by the run-time code for processing the
analog output. They are not configurable. They represent the current
state of the record. The record support routines use some of them for
more efficient processing.

The ORAW field is used to decide if monitors should be triggered for
RVAL when monitors are triggered for VAL. The RBV field is the actual
read back value obtained from the hardware itself or from the
associated device driver. It is the responsibility of the device
support routine to give this field a value.

ORBV is used to decide if monitors should be triggered for RBV at the
same time monitors are triggered for changes in VAL.

The LALM, MLST, and ALST fields are used to implement the hysteresis
factors for monitor callbacks.

The INIT field is used to initialize the LBRK field and for smoothing.

The PBRK field contains a pointer to the current breakpoint table (if
any), and LBRK contains a pointer to the last breakpoint table used.

The OMOD field indicates whether OVAL differs from VAL. It will be
different if VAL or OVAL have changed since the last time the record
was processed, or if VAL has been adjusted by OROC during the current
processing.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ORAW | Previous Raw Value | LONG | No |   | Yes | No | No |
| RBV | Readback Value | LONG | No |   | Yes | No | No |
| ORBV | Prev Readback Value | LONG | No |   | Yes | No | No |
| LALM | Last Value Alarmed | DOUBLE | No |   | Yes | No | No |
| ALST | Last Value Archived | DOUBLE | No |   | Yes | No | No |
| MLST | Last Val Monitored | DOUBLE | No |   | Yes | No | No |
| INIT | Initialized? | SHORT | No |   | Yes | No | No |
| PBRK | Ptrto brkTable | NOACCESS | No |   | No | No | No |
| LBRK | LastBreak Point | SHORT | No |   | Yes | No | No |
| PVAL | Previous value | DOUBLE | No |   | Yes | No | No |
| OMOD | Was OVAL modified? | UCHAR | No |   | Yes | No | No |

### Simulation Mode Parameters

The following fields are used to operate the record in simulation mode.

If SIMM (fetched through SIML, if populated) is YES, the record is put in SIMS
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

## Record Support

### Record Support Routines

The following are the record support routines that would be of interest
to an application developer. Other routines are the get\_units,
get\_precision, get\_graphic\_double, and get\_control\_double routines.

- init\_record

    `long init_record(aoRecord *prec, int pass);`

    This routine initializes SIMM if SIML is a constant or creates a
    channel access link if SIML is PV\_LINK. If SIOL is PV\_LINK a channel
    access link is created.

    This routine next checks to see that device support is available. If
    DOL is a constant, then VAL is initialized with its value and UDF is
    set to FALSE.

    The routine next checks to see if the device support write routine is
    defined. If either device support or the device support write routine
    does not exist, an error message is issued and processing is
    terminated.

    For compatibility with old device supports that don't know EOFF, if
    both EOFF and ESLO have their default value, EOFF is set to EGUL.

    If device support includes `init_record()`, it is called.

    INIT is set TRUE. This causes PBRK, LBRK, and smoothing to be
    re-initialized. If "backwards" linear conversion is requested, then VAL
    is computed from RVAL using the algorithm:

        VAL = ((RVAL+ROFF) * ASLO + AOFF) * ESLO + EOFF

    and UDF is set to FALSE.

    For breakpoint conversion, a call is made to cvtEngToRawBpt and UDF is
    then set to FALSE. PVAL is set to VAL.

- process

    `long process(aoRecord *prec);`

    See next section.

- special

    `long special(DBADDR *paddr, int after);`

    The only special processing for analog output records is SPC\_LINCONV
    which is invoked whenever either of the fields LINR, EGUF, EGUL or ROFF
    is changed If the device support routine special\_linconv exists it is
    called.

    INIT is set TRUE. This causes PBRK, LBRK, and smoothing to be
    re-initialized.

- get\_alarm\_double

    `long get_alarm_double(DBADDR *, struct dbr_alDouble *);`

    Sets the following values:

        upper_alarm_limit = HIHI
        upper_warning_limit = HIGH
        lower_warning_limit = LOW
        lower_alarm_limit = LOLO

### Record Processing

Routine process implements the following algorithm:

- 1. Check to see that the appropriate device support module
exists. If it doesn't, an error message is issued and processing is
terminated with the PACT field set to TRUE. This ensures that processes
will no longer be called for this record. Thus error storms will not
occur.
- 2. Check PACT: If PACT is FALSE call fetch\_values and convert
which perform the following steps:
    - fetch\_values:
        - if DOL is DB\_LINK and OMSL is CLOSED\_LOOP then get value from
        DOL
        - if OIF is INCREMENTAL then set value = value + VAL else value =
        VAL
    - convert:
        - If Drive limits are defined force value to be within limits
        - Set VAL equal to value
        - Set UDF to FALSE.
        - If OVAL is undefined set it equal to value
        - If OROC is defined and not 0 make |value-OVAL| <=OROC
        - Set OVAL equal to value
        - Compute RVAL from OVAL. using linear or break point table
        conversion. For linear conversions the algorithm is RVAL =
        (OVAL-EOFF)/ESLO.
        - For break point table conversion a call is made to
        cvtEngToRawBpt.
        - After that, for all conversion types AOFF, ASLO, and ROFF are
        calculated in, using the formula RVAL = (RVAL -AOFF) / ASLO - ROFF.
- 3. Check alarms: This routine checks to see if the new VAL causes
the alarm status and severity to change. If so, NSEV, NSTA and y are
set. It also honors the alarm hysteresis factor (HYST). Thus the value
must change by at least HYST before the alarm status and severity is
reduced.
- 4. Check severity and write the new value. See Invalid Alarm
Output Action for details on how invalid alarms affect output records.
- 5. If PACT has been changed to TRUE, the device support write
output routine has started but has not completed writing the new value.
In this case, the processing routine merely returns, leaving PACT TRUE.
- 6. Check to see if monitors should be invoked:
    - Alarm monitors are invoked if the alarm status or severity has
    changed.
    - Archive and value change monitors are invoked if ADEL and MDEL
    conditions are met.
    - Monitors for RVAL and for RBV are checked whenever other
    monitors are invoked.
    - NSEV and NSTA are reset to 0.
- 7. Scan forward link if necessary, set PACT and INIT FALSE, and
return.

## Device Support

### Fields Of Interest To Device Support

Each analog output record must have an associated set of device support
routines. The primary responsibility of the device support routines is
to output a new value whenever write\_ao is called. The device support
routines are primarily interested in the following fields:

- PACT — Process Active, used to indicate asynchronous completion
- DPVT — Device Private, reserved for device support to use
- OUT — Output Link, provides addressing information
- EGUF — Engineering Units Full
- EGUL — Engineering Units Low
- ESLO — Engineering Unit Slope
- EOFF — Engineering Unit Offset
- OVAL — Output Value, in Engineering units
- RVAL — Raw Output Value, after conversion

### Device Support routines

Device support consists of the following routines:

- report

    `long report(int level);`

    This optional routine is called by the IOC command `dbior` and is passed the
    report level that was requested by the user.
    It should print a report on the state of the device support to stdout.
    The `level` parameter may be used to output increasingly more detailed
    information at higher levels, or to select different types of information with
    different levels.
    Level zero should print no more than a small summary.

- init

    `long init(int after);`

    This optional routine is called twice at IOC initialization time.
    The first call happens before any of the `init_record()` calls are made, with
    the integer parameter `after` set to 0.
    The second call happens after all of the `init_record()` calls have been made,
    with `after` set to 1.

- init\_record

    `long init_record(aoRecord *prec);`

    This optional routine is called by the record initialization code for each ao
    record instance that has its DTYP field set to use this device support.
    It is normally used to check that the OUT address has the expected type and
    points to a valid device; to allocate any record-specific buffer space and
    other memory; and to connect any communication channels needed for the
    `write_ao()` routine to work properly.

    If the record type's unit conversion features are used, the `init_record()`
    routine should calculate appropriate values for the ESLO and EOFF fields from
    the EGUL and EGUF field values.
    This calculation only has to be performed if the record's LINR field is set to
    `LINEAR`, but it is not necessary to check that condition first.
    This same calculation takes place in the `special_linconv()` routine, so the
    implementation can usually just call that routine to perform the task.

    If the the last output value can be read back from the hardware, this routine
    should also fetch that value and put it into the record's RVAL or VAL field. The
    return value should be zero if the RVAL field has been set, or 2 if either the
    VAL field has been set or if the last output value cannot be retrieved.

- get\_ioint\_info

    `long get_ioint_info(int cmd, aoRecord *prec, IOSCANPVT *piosl);`

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
    That API allocates memory and inializes the list, then passes back a pointer to
    the new list in the location at `*piosl`.
    When the device support receives notification that the interrupt has occurred,
    it announces that to the IOC by calling `void scanIoRequest(IOSCANPVT iosl)`
    which will arrange for the appropriate records to be processed in a suitable
    thread.
    The `scanIoRequest()` routine is safe to call from an interrupt service routine
    on embedded architectures (vxWorks and RTEMS).

- write\_ao

    `long write_ao(aoRecord *prec);`

    This essential routine is called whenever the record has a new output value to
    send to the device. It is responsible for performing the write operation, using
    either the engineering units value found in the record's OVAL field, or the raw
    value from the record's RVAL field if the record type's unit conversion
    facilities are used. A return value of zero indicates success, any other value
    indicates that an error occurred.

    This routine must not block (busy-wait) if the device takes more than a few
    microseconds to accept the new value. In that case the routine must use
    asynchronous completion to tell the record when the write operation eventually
    completes. It signals that this is an asynchronous operation by setting the
    record's PACT field to TRUE before it returns, having arranged for the record's
    `process()` routine to be called later once the write operation is over. When
    that happens the `write_ao()` routine will be called again with PACT still set
    to TRUE; it should then set it to FALSE to indicate the write has completed, and
    return.

- special\_linconv

    `long special_linconv(aoRecord *prec, int after);`

    This optional routine should be provided if the record type's unit conversion
    features are used by the device support's `write_ao()` routine utilizing the
    RVAL field rather than OVAL or VAL.
    It is called by the record code whenever any of the the fields LINR, EGUL or
    EGUF are modified and LINR has the value `LINEAR`.
    The routine must calculate and set the fields EOFF and ESLO appropriately based
    on the new values of EGUL and EGUF.

    These calculations can be expressed in terms of the minimum and maximum raw
    values that the `write_ao()` routine can accept in the RVAL field.
    When VAL is EGUF the RVAL field will be set to _RVAL\_max_, and when VAL is
    EGUL the RVAL field will become _RVAL\_min_.
    The fomulae to use are:

    >     EOFF = (_RVAL\_max_ \* EGUL − _RVAL\_min_ \* EGUF) /
    >     (_RVAL\_max_ − _RVAL\_min_)
    >
    >     ESLO = (EGUF − EGUL) / (_RVAL\_max_ − _RVAL\_min_)

    Note that the record support sets EOFF to EGUL before calling this routine,
    which is a very common case (_RVAL\_min_ is zero).

## Device Support For Soft Records

Two soft device support modules Soft Channel and Raw Soft Channel are
provided for output records not related to actual hardware devices. The
OUT link type must be either a CONSTANT, DB\_LINK, or CA\_LINK.

### Soft Channel

This module writes the current value of OVAL.

If the OUT link type is PV\_LINK, then dbCaAddInlink is called by
`init_record()`. `init_record()` always returns a value of 2, which means that
no conversion will ever be attempted.

write\_ao calls recGblPutLinkValue to write the current value of VAL.
See Soft Output for details.

### Raw Soft Channel

This module is like the previous except that it writes the current
value of RVAL.
