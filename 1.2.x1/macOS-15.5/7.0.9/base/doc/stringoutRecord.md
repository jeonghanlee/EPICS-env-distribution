# String Output Record (stringout)

The stringout record is used to write an arbitrary ASCII string of up to 40
characters to other records or software variables.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The string output record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Desired Output Parameters

The string output record must specify from where it gets its desired output
string. The first field that determines where the desired output originates is
the output mode select (OMSL) field, which can have two possible value: `closed_loop` or `supervisory`. If `supervisory` is specified,
DOL is ignored, the current value of VAL is written, and the VAL can be changed
externally via dbPuts at run-time. If `closed_loop` is specified, the VAL
field's value is obtained from the address specified in the Desired Output
Link field (DOL) which can be either a database link or a channel access
link.

DOL can also be a constant, in which case VAL will be initialized to the
constant value. However to be interpreted as a constant instead of a CA link
the constant can only be numeric, so string output records are best initialized
by dirctly setting the VAL field. Note that if DOL is a constant, OMSL
cannot be `closed_loop`.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current Value | STRING \[40\] | Yes |   | Yes | Yes | Yes |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |

### Output Specification

The output link specified in the OUT field specifies where the string output
record is to write its string. The link can be a database or channel access
link. If the OUT field is a constant, no output will be written.

In addition, the appropriate device support module must be entered into the DTYP
field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to specify when the monitor post should be sent by
`monitor()` routine. There are two possible choices:

#### Menu stringoutPOST

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | stringoutPOST\_OnChange | On Change |
| 1 | stringoutPOST\_Always | Always |

APST is used for archiver monitors and MPST is for all other type of monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| MPST | Post Value Monitors | MENU [stringoutPOST](#menu-stringoutpost) | Yes |   | Yes | Yes | No |
| APST | Post Archive Monitors | MENU [stringoutPOST](#menu-stringoutpost) | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. These
fields are used to display the value and other parameters of the string output
either textually or graphically.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Run-time Parameters

The old value field (OVAL) of the string input is used to implement value change
monitors for VAL. If VAL is not equal to OVAL, then monitors are triggered.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OVAL | Previous Value | STRING \[40\] | No |   | Yes | No | No |

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

### Alarm Parameters

The possible alarm conditions for the string output record are the SCAN, READ,
and INVALID alarms. The severity of the first two is always MAJOR and not
configurable.

The IVOA field specifies an action to take when the INVALID alarm is triggered.
When `Set output to IVOV`, the value contained in the IVOV field is
written to the output link during an alarm condition. See
[Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for more information on the IVOA and IVOV fields.

[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| IVOA | INVALID output action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID output value | STRING \[40\] | Yes |   | Yes | Yes | No |

## Record Support

### Record Support Routines

#### init\_record

    long (*init_record)(struct dbCommon *precord, int pass)

This routine initializes SIMM if SIML is a constant or creates a channel access
link if SIML is PV\_LINK. If SIOL is PV\_LINK a channel access link is created.

This routine next checks to see that device support is available. The routine
next checks to see if the device support write routine is defined. If either
device support or the device support write routine does not exist, an error
message is issued and processing is terminated.

If DOL is a constant, then the type double constant, if non-zero, is converted
to a string and stored into VAL and UDF is set to FALSE. If DOL type is a
PV\_LINK then dbCaAddInlink is called to create a channel access link.

If device support includes `init_record()`, it is called.

#### process

    long (*process)(struct dbCommon *precord)

See ["Record Processing"](#record-processing).

### Record Processing

Routine process implements the following algorithm:

1. Check to see that the appropriate device support module exists. If it doesn't,
an error message is issued and processing is terminated with the PACT field
still set to TRUE. This ensures that processes will no longer be called for this
record. Thus error storms will not occur.
2. If PACT is FALSE and OMSL is CLOSED\_LOOP, recGblGetLinkValue is called to read
the current value of VAL. See ["Soft Output"](#soft-output).
If the return status of recGblGetLinkValue is zero then UDF is set to FALSE.
3. Check severity and write the new value. See
["Simulation Mode"](#simulation-mode) and
[Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for details on how the simulation mode and the INVALID alarm conditions affect output.
4. If PACT has been changed to TRUE, the device support write output routine has
started but has not completed writing the new value. In this case, the
processing routine merely returns, leaving PACT TRUE.
5. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if OVAL is not equal to VAL.
    - NSEV and NSTA are reset to 0.
6. Scan forward link if necessary, set PACT FALSE, and return.

<div>
    <br>
    <hr>
    <br>
</div>

## Device Support

### Fields Of Interest To Device Support

Each stringout output record must have an associated set of device support
routines. The primary responsibility of the device support routines is to write
a new value whenever write\_stringout is called. The device support routines are
primarily interested in the following fields:

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| VAL | Current Value | STRING \[40\] | Yes |   | Yes | Yes | Yes |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |

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

    long init_record(dbCommon *prec)

This routine is optional. If provided, it is called by the record support
`init_record()` routine.

#### get\_ioint\_info

    long get_ioint_info(int cmd, dbCommon *precord, IOSCANPVT *ppvt)

This routine is called by the ioEventScan system each time the record is added
or deleted from an I/O event scan list. `cmd` has the value (0,1) if the
record is being (added to, deleted from) an I/O event list. It must be
provided for any device type that can use the ioEvent scanner.

#### write\_stringout

    long write_stringout(stringoutRecord *prec)

This routine must output a new value. It returns the following values:

- 0: Success.
- Other: Error.

### Device Support for Soft Records

The `Soft Channel` device support module writes the current value of VAL.

Device support for DTYP `stdio` is provided for writing values to the stdout,
stderr, or errlog streams. `INST_IO` addressing `@stdout`, `@stderr` or
`@errlog` is used on the OUT link field to select the desired stream.
