# Long String Output Record (lso)

The long string output record is used to write an arbitrary ASCII string with a
maximum length of 32767 characters.

This record type was included in base.dbd beginning with epics-base 3.15.0.2 .

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The long string output record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Desired Output Parameters

The long string output record must specify from where it gets its desired output
string. The first field that determines where the desired output originates is
the output mode select (OMSL) field, which can have two possible values:
`closed_loop` or `supervisory`. If `closed_loop` is specified, the VAL
field's value is fetched from the address specified in the Desired Output Link
field (DOL) which can be either a database link or a channel access link. If
`supervisory` is specified, DOL is ignored, the current value of VAL is
written, and VAL can be changed externally via dbPuts at run-time.

The maximum number of characters in VAL is given by SIZV, and cannot be larger
than 32767.

DOL can also be a constant instead of a link, in which case VAL is initialized
to the constant value. Most simple string constants are likely to be interpreted
as a CA link name though. To initialize a string output record it is simplest
to set the VAL field directly; alternatively use a JSON constant link type in
the DOL field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current Value | STRING or CHAR\[SIZV\] | No |   | Yes | Yes | Yes |
| SIZV | Size of buffers | USHORT | Yes | 41 | Yes | No | No |
| DOL | Desired Output Link | INLINK | Yes |   | Yes | Yes | No |
| OMSL | Output Mode Select | MENU [menuOmsl](menuOmsl.md) | Yes |   | Yes | Yes | No |

### Output Specification

The output link specified in the OUT field specifies where the long string
output record is to write its string. The link can be a database or channel
access link. If the OUT field is a constant, no output will be written.

In addition, the appropriate device support module must be entered into the DTYP
field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to specify when the monitor post should be sent by the
`monitor()` routine. There are two possible choices:

APST is used for archiver monitors and MPST  for all other type of monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| MPST | Post Value Monitors | MENU [menuPost](menuPost.md) | Yes |   | Yes | Yes | No |
| APST | Post Archive Monitors | MENU [menuPost](menuPost.md) | Yes |   | Yes | Yes | No |

### Operator Display Parameters

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The long string input record has the same alarm parameters common to all record
types. [Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

The IVOA field specifies an action to take when the INVALID alarm is triggered.
When `Set output to IVOV`, the value contained in the IVOV field is
written to the output link during an alarm condition. See
[Invalid Output Action Fields](dbCommonOutput.md#Invalid-Output-Action-Fields)
for more information on the IVOA and IVOV fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| IVOA | INVALID Output Action | MENU [menuIvoa](menuIvoa.md) | Yes |   | Yes | Yes | No |
| IVOV | INVALID Output Value | STRING \[40\] | Yes |   | Yes | Yes | No |

### Run-time Parameters

The old value field (OVAL) of the long string input record is used to implement
value change monitors for VAL. If VAL is not equal to OVAL, then monitors are
triggered. LEN contains the length of the string in VAL, OLEN contains the
length of the string in OVAL.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OVAL | Previous Value | STRING or \[SIZV\] | No |   | Yes | No | No |
| LEN | Length of VAL | ULONG | No |   | Yes | No | No |
| OLEN | Length of OVAL | ULONG | No |   | Yes | No | No |

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
| SIML | Simulation Mode link | INLINK | Yes |   | Yes | Yes | No |
| SIMM | Simulation Mode | MENU [menuYesNo](menuYesNo.md) | No |   | Yes | Yes | No |
| SIOL | Simulation Output Link | OUTLINK | Yes |   | Yes | Yes | No |
| SIMS | Simulation Mode Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| SDLY | Sim. Mode Async Delay | DOUBLE | Yes | -1.0 | Yes | Yes | No |
| SSCN | Sim. Mode Scan | MENU [menuScan](menuScan.md) | Yes | 65535 | Yes | Yes | No |

## Device Support Interface

The record defines a device support entry table type `lsodset` in the generated
lsoRecord.h file as follows:

    typedef struct lsodset {
        dset common;
        long (*write_string)(struct lsoRecord *prec);
    } lsodset;
    #define HAS_lsodset

The support module must set `common.number` to at least 5, and provide a
pointer to its `write_string()` routine; the other function pointers may be
`NULL` if their associated functionality is not required for this support
layer.
Most device supports also provide a `common.init_record()` routine to configure
the record instance and connect it to the hardware or driver support layer.

## Device Support for Soft Records

Device support for DTYP `Soft Channel` is provided for writing values to other
records or other software components.

Device support for DTYP `stdio` is provided for writing values to the stdout,
stderr, or errlog streams. `INST_IO` addressing `@stdout`, `@stderr` or
`@errlog` is used on the OUT link field to select the desired stream.
