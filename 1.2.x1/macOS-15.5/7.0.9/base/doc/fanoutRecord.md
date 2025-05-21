# Fanout Record (fanout)

The fanout record uses several forward processing links to force multiple
passive records to scan. When more than one record needs to be scanned as the
result of a record being processed, the forward link of that record can specify
a fanout record. The fanout record can specify up to sixteen other records to
process. If more than sixteen are needed, one of the forward links in the fanout
record (or its FLNK field) can point to another fanout record.

**NOTE: Fanout records only propagate processing, not data.** The dfanout or
Data Fanout record can, on the other hand, send data to other records.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The forward link fields of the fanout record (LNK0-LNK9, LNKA-LNKF) specify
records to be scanned. The records to be processed must specify `Passive` in
their SCAN fields; otherwise the forward link will not cause them to process.
Also when specifying database links for the fanout record, the user needs only
to specify the record name. As no value is being sent or retrieved, a field name
is only required when the link will be over Channel Access, in which case the
field PROC must be named.

The SELM, SELN, and SELL fields specify the order of processing for the forward
links. The select mechanism menu field (SELM) has three choices:

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | fanoutSELM\_All | All |
| 1 | fanoutSELM\_Specified | Specified |
| 2 | fanoutSELM\_Mask | Mask |

How the SELM value affects which links to process and in which order is as
follows:

- **All**
Links are processed in numerical order - LNK0, LNK1, etc.
- **Specified** The sum of the values in the SELN and OFFS fields is used as the
specifier of which link to process. For instance, with OFFS=0 and SELN=1, the
record targeted by LNK1 will be processed.
- **Mask** The individual bits in SELN are shifted by SHFT bits (negative means
shift left) and the result used to select which links to process as follows:
    - If bit 0 (LSB) is set, LNK0 is processed.
    - If bit 1 is set, LNK2 is processed.
    - If bit 2 is set, LNK3 is processed, etc.

SELN reads its value from SELL. SELL can be a constant, a database link, or a
channel access link.  If a constant, SELN is initialized with the constant value
and can be changed via dbPuts. For database/channel access links, SELN is
retrieved from SELL each time the record is processed and can also be changed
via dbPuts.

The Fanout record also has the standard scanning fields common to all records.
These fields are listed in [Scan Fields](dbCommonRecord.md#Scan-Fields).

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SELM | Select Mechanism | MENU [fanoutSELM](#menu-fanoutselm) | Yes |   | Yes | Yes | No |
| SELN | Link Selection | USHORT | No | 1 | Yes | Yes | No |
| SELL | Link Selection Loc | INLINK | Yes |   | Yes | Yes | No |
| OFFS | Offset for Specified | SHORT | Yes |   | Yes | Yes | No |
| SHFT | Shift for Mask mode | SHORT | Yes | -1 | Yes | Yes | No |
| LNK0 | Forward Link 0 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK1 | Forward Link 1 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK2 | Forward Link 2 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK3 | Forward Link 3 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK4 | Forward Link 4 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK5 | Forward Link 5 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK6 | Forward Link 6 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK7 | Forward Link 7 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK8 | Forward Link 8 | FWDLINK | Yes |   | Yes | Yes | No |
| LNK9 | Forward Link 9 | FWDLINK | Yes |   | Yes | Yes | No |
| LNKA | Forward Link 10 | FWDLINK | Yes |   | Yes | Yes | No |
| LNKB | Forward Link 11 | FWDLINK | Yes |   | Yes | Yes | No |
| LNKC | Forward Link 12 | FWDLINK | Yes |   | Yes | Yes | No |
| LNKD | Forward Link 13 | FWDLINK | Yes |   | Yes | Yes | No |
| LNKE | Forward Link 14 | FWDLINK | Yes |   | Yes | Yes | No |
| LNKF | Forward Link 15 | FWDLINK | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. See
[Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters)
for more on these fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The Fanout record has the alarm parameters common to all record types.
[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

### Run-time Parameters

The VAL field performs no specific function, but a Channel Access put to it will
cause the record to process.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Used to trigger | LONG | No |   | Yes | Yes | Yes |

## Record Support

### Record Support Routines

#### init\_record

This routine initializes SELN with the value of SELL, if SELL type is CONSTANT
link, or creates a channel access link if SELL type is PV\_LINK.

#### process

See next section.

### Record Processing

Routine process implements the following algorithm:

1. PACT is set to TRUE.
2. The link selection SELN is fetched.
3. Depending on the selection mechanism, the link selection forward links are
processed, and UDF is set to FALSE.
4. Check to see if monitors should be invoked:
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - NSEV and NSTA are reset to 0.
5. Scan forward link field FLNK if used, set PACT FALSE, and return.
