# State Record (state)

The state record is a means for a state program to communicate with the operator
interface. Its only function is to provide a place in the database through which
the state program can inform the operator interface of its state by storing an
arbitrary ASCII string in its VAL field.

**Note this record is deprecated and may be removed in a future EPICS release.**

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The state record has the standard fields for specifying under what circumstances
it will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Operator Display Parameters

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The state record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Run-time Parameters

These parameters are used by the application code to convey the state of the
program to the operator interface. The VAL field holds the string retrieved from
the state program. The OVAL is used to implement monitors for the VAL field.
When the string in OVAL differs from the one in VAL, monitors are triggered.
They represent the current state of the sequence program.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Value | STRING \[20\] | Yes |   | Yes | Yes | Yes |
| OVAL | Prev Value | STRING \[20\] | No |   | Yes | No | No |

## Record Support

### Record Support Routines

#### process

    long (*process)(struct dbCommon *precord)

`process()` triggers monitors on VAL when it changes and scans the forward
link if necessary.
