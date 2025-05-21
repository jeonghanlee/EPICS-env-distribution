# Printf Record (printf)

The printf record is used to generate and write a string using a format
specification and parameters, analogous to the C `printf()` function.

This record type was included in base.dbd beginning with epics-base 3.15.0.2 .

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The printf record has the standard fields for specifying under what
circumstances it will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |

### String Generation Parameters

The printf record must specify the desired output string with embedded format
specifiers in the FMT field. Plain characters are copied directly to the output
string. A pair of percent characters '`%%`' are converted into a single percent
character in the output string. A single precent character '`%`' introduces a
format specifier and is followed by zero or more of the standard `printf()`
format flags and modifiers:

- Plus ('`+`')
- Minus ('`-`')
- Space ('` `')
- Hash ('`#`')
- Minimum Field Width (decimal digits or '`*`')
- Precision ('`.`' followed by decimal digits or '`*`')
- Length Modifier '`hh`' – Reads link as DBR\_CHAR or DBR\_UCHAR
- Length Modifier '`h`' – Reads link as DBR\_SHORT or DBR\_USHORT for
integer conversions, DBR\_FLOAT for floating-point conversions.
- Length Modifier '`l`' – Reads link as DBR\_LONG or DBR\_ULONG for integer
conversions, array of DBR\_CHAR for string conversion.
- Length Modifier '`ll`' – Reads link as DBR\_INT64 or DBR\_UINT64 for
integer conversions.

The following character specifies the conversion to perform, see your operating
system's `printf()` documentation for more details. These conversions
ultimately call the `snprintf()` routine for the actual string conversion
process, so are subject to the behaviour of that routine.

- '`c`' – Convert to a character. Only single byte characters are
permitted.
- '`d`' or '`i`' – Convert to a decimal integer.
- '`o`' – Convert to an unsigned octal integer.
- '`u`' – Convert to an unsigned decimal integer.
- '`x`' – Convert to an unsigned hexadecimal integer, using `abcdef`.
- '`X`' – Convert to an unsigned hexadecimal integer, using `ABCDEF`.
- '`e`' or '`E`' – Convert to floating-point in exponent style, reading
the link as DBR\_DOUBLE or DBR\_FLOAT.
- '`f`' or '`F`' – Convert to floating-point in fixed-point style,
reading the link as DBR\_DOUBLE or DBR\_FLOAT.
- '`g`' or '`G`' – Convert to floating-point in general style, reading
the link as DBR\_DOUBLE or DBR\_FLOAT.
- '`s`' – Insert string, reading the link as DBR\_STRING or array of
DBR\_CHAR.

The fields INP0 ... INP9 are input links that provide the parameter values to be
formatted into the output. The format specifiers in the FMT string determine
which type of the data is requested through the appropriate input link. As with
`printf()` a `*` character may be used in the format to specify width and/or
precision instead of numeric literals, in which case additional input links are
used to provide the necessary integer parameter or parameters. See [Address
Specification](https://docs.epics-controls.org/en/latest/guides/EPICS_Process_Database_Concepts.html#address-specification)
for information on specifying links.

The formatted string is written to the VAL field.  The maximum number of
characters in VAL is given by SIZV, and cannot be larger than 32767. The LEN
field contains the length of the formatted string in the VAL field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| FMT | Format String | STRING \[81\] | Yes |   | Yes | Yes | Yes |
| INP0 | Input 0 | INLINK | Yes |   | Yes | Yes | No |
| INP1 | Input 1 | INLINK | Yes |   | Yes | Yes | No |
| INP2 | Input 2 | INLINK | Yes |   | Yes | Yes | No |
| INP3 | Input 3 | INLINK | Yes |   | Yes | Yes | No |
| INP4 | Input 4 | INLINK | Yes |   | Yes | Yes | No |
| INP5 | Input 5 | INLINK | Yes |   | Yes | Yes | No |
| INP6 | Input 6 | INLINK | Yes |   | Yes | Yes | No |
| INP7 | Input 7 | INLINK | Yes |   | Yes | Yes | No |
| INP8 | Input 8 | INLINK | Yes |   | Yes | Yes | No |
| INP9 | Input 9 | INLINK | Yes |   | Yes | Yes | No |
| VAL | Result | STRING\[SIZV\] | No |   | Yes | Yes | Yes |
| SIZV | Size of VAL buffer | USHORT | Yes | 41 | Yes | No | No |
| LEN | Length of VAL | ULONG | No |   | Yes | No | No |

### Output Specification

The output link specified in the OUT field specifies where the printf record is
to write the contents of  its VAL field. The link can be a database or channel
access link. If the OUT field is a constant, no output will be written.

In addition, the appropriate device support module must be entered into the DTYP
field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUT | Output Specification | OUTLINK | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |

### Operator Display Parameters

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The printf record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

The IVLS field specifies a string which is sent to the OUT link if if input
link data are invalid.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| IVLS | Invalid Link String | STRING \[16\] | Yes | LNK | Yes | Yes | No |

## Device Support Interface

The record requires device support to provide an entry table (dset) which
defines the following members:

    typedef struct {
        long number;
        long (*report)(int level);
        long (*init)(int after);
        long (*init_record)(printfRecord *prec);
        long (*get_ioint_info)(int cmd, printfRecord *prec, IOSCANPVT *piosl);
        long (*write_string)(printfRecord *prec);
    } printfdset;

The module must set `number` to at least 5, and provide a pointer to its
`write_string()` routine; the other function pointers may be `NULL` if their
associated functionality is not required for this support layer.
Most device supports also provide an `init_record()` routine to configure the
record instance and connect it to the hardware or driver support layer.

## Device Support for Soft Records

A soft device support module Soft Channel is provided for writing values to
other records  or other software components.

Device support for DTYP `stdio` is provided for writing values to the stdout,
stderr, or errlog streams. `INST_IO` addressing `@stdout`, `@stderr` or
`@errlog` is used on the OUT link field to select the desired stream.
