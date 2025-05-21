# Long String Input Record (lsi)

The long string input record is used to retrieve an arbitrary ASCII string with
a maximum length of 32767 characters.

This record type was included in base.dbd beginning with epics-base 3.15.0.2 .

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The long string input record has the standard fields for specifying under what
circumstances it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Input Specification

The INP field determines where the long string input record obtains its string
from. It can be a database or channel access link, or a constant. If constant,
the VAL field is initialized with the constant and can be changed via dbPuts.
Otherwise, the string is read from the specified location each time the record
is processed and placed in the VAL field. The maximum number of characters in
VAL is given by SIZV, and cannot be larger than 32767. In addition, the
appropriate device support module must be entered into the DTYP field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Current Value | STRING or CHAR\[SIZV\] | No |   | Yes | Yes | Yes |
| OVAL | Old Value | STRING or \[SIZV\] | No |   | Yes | No | No |
| SIZV | Size of buffers | USHORT | Yes | 41 | Yes | No | No |
| INP | Input Specification | INLINK | Yes |   | Yes | Yes | No |
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

The long string input record has the alarm parameters common to all record
types. [Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Run-time Parameters

The old value field (OVAL) of the long string input record is used to implement
value change monitors for VAL. If VAL is not equal to OVAL, then monitors are
triggered. LEN contains the length of the string in VAL, OLEN contains the
length of the string in OVAL.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OVAL | Old Value | STRING or \[SIZV\] | No |   | Yes | No | No |
| LEN | Length of VAL | ULONG | No |   | Yes | No | No |
| OLEN | Length of OVAL | ULONG | No |   | Yes | No | No |

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

## Device Support Interface

The record requires device support to provide an entry table (dset) which
defines the following members:

    typedef struct {
        long number;
        long (*report)(int level);
        long (*init)(int after);
        long (*init_record)(lsiRecord *prec);
        long (*get_ioint_info)(int cmd, lsiRecord *prec, IOSCANPVT *piosl);
        long (*read_string)(lsiRecord *prec);
    } lsidset;

The module must set `number` to at least 5, and provide a pointer to its
`read_string()` routine; the other function pointers may be `NULL` if their
associated functionality is not required for this support layer.
Most device supports also provide an `init_record()` routine to configure the
record instance and connect it to the hardware or driver support layer.

## Device Support for Soft Records

A device support module for DTYP `Soft Channel` is provided for retrieving
values from other records or other software components.

Device support for DTYP `getenv` is provided for retrieving strings from
environment variables. `INST_IO` addressing `@<environment variable>` is
used on the `INP` link field to select the desired environment variable.
