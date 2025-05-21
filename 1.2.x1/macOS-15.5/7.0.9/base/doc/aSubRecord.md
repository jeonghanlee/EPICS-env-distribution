# Array Subroutine Record (aSub)

The aSub record is an advanced variant of the 'sub' (subroutine) record which
has a number of additional features:

- It provides 21 different input and output fields which can hold array or
scalar values.
The types and array capacities of these are user configurable, and they all
have an associated input or output link.
- The name of the C or C++ subroutine to be called when the record processes
can be changed dynamically while the IOC is running.
The name can either be fetched from another record using an input link, or
written directly into the SNAM field.
- The user can choose whether monitor events should be posted for the output
fields.
- The VAL field is set to the return value from the user subroutine, which is
treated as a status value and controls whether the output links will be used
or not. The record can also raise an alarm with a chosen severity if the status
value is non-zero.

This record type was included in base.dbd beginning with epics-base 3.14.10 .

## Record-specific Menus

### Menu aSubLFLG

The LFLG menu field controls whether the SUBL link will be read to update
the name of the subroutine to be called when the record processes.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | aSubLFLG\_IGNORE | IGNORE |
| 1 | aSubLFLG\_READ | READ |

### Menu aSubEFLG

The EFLG menu field indicates whether monitor events should be posted for the
VALA..VALU output value fields.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | aSubEFLG\_NEVER | NEVER |
| 1 | aSubEFLG\_ON\_CHANGE | ON CHANGE |
| 2 | aSubEFLG\_ALWAYS | ALWAYS |

## Parameter Fields

The record-specific fields are described below.

### Subroutine Fields

The VAL field is set to the value returned by the user subroutine.
The value is treated as an error status value where zero mean success.
The output links OUTA ... OUTU will only be used to forward the associated
output value fields when the subroutine has returned a zero status.
If the return status was less than zero, the record will be put into `SOFT_ALARM`
state with severity given by the BRSV field.

The INAM field may be used to name a subroutine that will be called once at
IOC initialization time.

LFLG tells the record whether to read or ignore the SUBL link.
If the value is `READ`, then the name of the subroutine to be called at
process time is read from SUBL.
If the value is `IGNORE`, the name of the subroutine is that currently held
in SNAM.

A string is read from the SUBL link to fetch the name of the subroutine to
be run during record processing.

SNAM holds the name of the subroutine to be called when the record processes.
The value in this field can be overwritten by the SUBL link if LFLG is set
to `READ`.

The SADR field is only accessible from C code; it points to the subroutine
to be called.

The CADR field may be set by the user subroutine to point to another function
that will be called immediately before setting the SADR field to some other
routine. This allows the main user subroutine to allocate resources when it is
first called and be able to release them again when they are no longer needed.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Subr. return value | LONG | No |   | Yes | Yes | No |
| OVAL | Old return value | LONG | No |   | Yes | No | No |
| INAM | Initialize Subr. Name | STRING \[41\] | Yes |   | Yes | No | No |
| LFLG | Subr. Input Enable | MENU [aSubLFLG](#menu-asublflg) | Yes |   | Yes | Yes | No |
| SUBL | Subroutine Name Link | INLINK | Yes |   | Yes | No | No |
| SNAM | Process Subr. Name | STRING \[41\] | Yes |   | Yes | Yes | No |
| ONAM | Old Subr. Name | STRING \[41\] | Yes |   | Yes | No | No |
| SADR | Subroutine Address | NOACCESS | No |   | No | No | No |
| CADR | Subroutine Cleanup Address | NOACCESS | No |   | No | No | No |
| BRSV | Bad Return Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |

### Operator Display Parameters

The PREC field specifies the number of decimal places with which to display
the values of the value fields A ... U and VALA ... VALU.
Except when it doesn't.

### Output Event Flag

This field tells the record when to post change events on the output fields
VALA ... VALU. If the value is `NEVER`, events are never posted. If the value
is `ALWAYS`, events are posted every time the record processes. If the value
is `ON CHANGE`, events are posted when any element of an array changes value.
This flag controls value, log (archive) and alarm change events.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EFLG | Output Event Flag | MENU [aSubEFLG](#menu-asubeflg) | Yes | 1 | Yes | Yes | No |

### Input Link Fields

The input links from where the values of A,...,U are fetched
during record processing.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| INPA | Input Link A | INLINK | Yes |   | Yes | Yes | No |
| INPB | Input Link B | INLINK | Yes |   | Yes | Yes | No |
| INPC | Input Link C | INLINK | Yes |   | Yes | Yes | No |
| INPD | Input Link D | INLINK | Yes |   | Yes | Yes | No |
| INPE | Input Link E | INLINK | Yes |   | Yes | Yes | No |
| INPF | Input Link F | INLINK | Yes |   | Yes | Yes | No |
| INPG | Input Link G | INLINK | Yes |   | Yes | Yes | No |
| INPH | Input Link H | INLINK | Yes |   | Yes | Yes | No |
| INPI | Input Link I | INLINK | Yes |   | Yes | Yes | No |
| INPJ | Input Link J | INLINK | Yes |   | Yes | Yes | No |
| INPK | Input Link K | INLINK | Yes |   | Yes | Yes | No |
| INPL | Input Link L | INLINK | Yes |   | Yes | Yes | No |
| INPM | Input Link M | INLINK | Yes |   | Yes | Yes | No |
| INPN | Input Link N | INLINK | Yes |   | Yes | Yes | No |
| INPO | Input Link O | INLINK | Yes |   | Yes | Yes | No |
| INPP | Input Link P | INLINK | Yes |   | Yes | Yes | No |
| INPQ | Input Link Q | INLINK | Yes |   | Yes | Yes | No |
| INPR | Input Link R | INLINK | Yes |   | Yes | Yes | No |
| INPS | Input Link S | INLINK | Yes |   | Yes | Yes | No |
| INPT | Input Link T | INLINK | Yes |   | Yes | Yes | No |
| INPU | Input Link U | INLINK | Yes |   | Yes | Yes | No |

### Input Value Fields

Thse fields hold the scalar or array values fetched through the input links
INPA,...,INPU.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| A | Input value A | Set by FTA | No |   | Yes | Yes | No |
| B | Input value B | Set by FTB | No |   | Yes | Yes | No |
| C | Input value C | Set by FTC | No |   | Yes | Yes | No |
| D | Input value D | Set by FTD | No |   | Yes | Yes | No |
| E | Input value E | Set by FTE | No |   | Yes | Yes | No |
| F | Input value F | Set by FTF | No |   | Yes | Yes | No |
| G | Input value G | Set by FTG | No |   | Yes | Yes | No |
| H | Input value H | Set by FTH | No |   | Yes | Yes | No |
| I | Input value I | Set by FTI | No |   | Yes | Yes | No |
| J | Input value J | Set by FTJ | No |   | Yes | Yes | No |
| K | Input value K | Set by FTK | No |   | Yes | Yes | No |
| L | Input value L | Set by FTL | No |   | Yes | Yes | No |
| M | Input value M | Set by FTM | No |   | Yes | Yes | No |
| N | Input value N | Set by FTN | No |   | Yes | Yes | No |
| O | Input value O | Set by FTO | No |   | Yes | Yes | No |
| P | Input value P | Set by FTP | No |   | Yes | Yes | No |
| Q | Input value Q | Set by FTQ | No |   | Yes | Yes | No |
| R | Input value R | Set by FTR | No |   | Yes | Yes | No |
| S | Input value S | Set by FTS | No |   | Yes | Yes | No |
| T | Input value T | Set by FTT | No |   | Yes | Yes | No |
| U | Input value U | Set by FTU | No |   | Yes | Yes | No |

### Input Value Data Types

Field types of the input value fields.
The choices can be found by following the link to the menuFtype definition.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| FTA | Type of A | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTB | Type of B | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTC | Type of C | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTD | Type of D | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTE | Type of E | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTF | Type of F | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTG | Type of G | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTH | Type of H | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTI | Type of I | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTJ | Type of J | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTK | Type of K | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTL | Type of L | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTM | Type of M | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTN | Type of N | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTO | Type of O | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTP | Type of P | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTQ | Type of Q | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTR | Type of R | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTS | Type of S | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTT | Type of T | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTU | Type of U | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |

### Input Value Array Capacity

These fields specify how many array elements the input value fields may hold.

Note that access to the `NOT` field from C code must use the field name in
upper case, e.g. `prec->NOT` since the lower-case `not` is a reserved
word in C++ and cannot be used as an identifier.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NOA | Max. elements in A | ULONG | Yes | 1 | Yes | No | No |
| NOB | Max. elements in B | ULONG | Yes | 1 | Yes | No | No |
| NOC | Max. elements in C | ULONG | Yes | 1 | Yes | No | No |
| NOD | Max. elements in D | ULONG | Yes | 1 | Yes | No | No |
| NOE | Max. elements in E | ULONG | Yes | 1 | Yes | No | No |
| NOF | Max. elements in F | ULONG | Yes | 1 | Yes | No | No |
| NOG | Max. elements in G | ULONG | Yes | 1 | Yes | No | No |
| NOH | Max. elements in H | ULONG | Yes | 1 | Yes | No | No |
| NOI | Max. elements in I | ULONG | Yes | 1 | Yes | No | No |
| NOJ | Max. elements in J | ULONG | Yes | 1 | Yes | No | No |
| NOK | Max. elements in K | ULONG | Yes | 1 | Yes | No | No |
| NOL | Max. elements in L | ULONG | Yes | 1 | Yes | No | No |
| NOM | Max. elements in M | ULONG | Yes | 1 | Yes | No | No |
| NON | Max. elements in N | ULONG | Yes | 1 | Yes | No | No |
| NOO | Max. elements in O | ULONG | Yes | 1 | Yes | No | No |
| NOP | Max. elements in P | ULONG | Yes | 1 | Yes | No | No |
| NOQ | Max. elements in Q | ULONG | Yes | 1 | Yes | No | No |
| NOR | Max. elements in R | ULONG | Yes | 1 | Yes | No | No |
| NOS | Max. elements in S | ULONG | Yes | 1 | Yes | No | No |
| NOT | Max. elements in T | ULONG | Yes | 1 | Yes | No | No |
| NOU | Max. elements in U | ULONG | Yes | 1 | Yes | No | No |

### Input Value Array Size

These fields specify how many array elements the input value fields currently
contain.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NEA | Num. elements in A | ULONG | No | 1 | Yes | No | No |
| NEB | Num. elements in B | ULONG | No | 1 | Yes | No | No |
| NEC | Num. elements in C | ULONG | No | 1 | Yes | No | No |
| NED | Num. elements in D | ULONG | No | 1 | Yes | No | No |
| NEE | Num. elements in E | ULONG | No | 1 | Yes | No | No |
| NEF | Num. elements in F | ULONG | No | 1 | Yes | No | No |
| NEG | Num. elements in G | ULONG | No | 1 | Yes | No | No |
| NEH | Num. elements in H | ULONG | No | 1 | Yes | No | No |
| NEI | Num. elements in I | ULONG | No | 1 | Yes | No | No |
| NEJ | Num. elements in J | ULONG | No | 1 | Yes | No | No |
| NEK | Num. elements in K | ULONG | No | 1 | Yes | No | No |
| NEL | Num. elements in L | ULONG | No | 1 | Yes | No | No |
| NEM | Num. elements in M | ULONG | No | 1 | Yes | No | No |
| NEN | Num. elements in N | ULONG | No | 1 | Yes | No | No |
| NEO | Num. elements in O | ULONG | No | 1 | Yes | No | No |
| NEP | Num. elements in P | ULONG | No | 1 | Yes | No | No |
| NEQ | Num. elements in Q | ULONG | No | 1 | Yes | No | No |
| NER | Num. elements in R | ULONG | No | 1 | Yes | No | No |
| NES | Num. elements in S | ULONG | No | 1 | Yes | No | No |
| NET | Num. elements in T | ULONG | No | 1 | Yes | No | No |
| NEU | Num. elements in U | ULONG | No | 1 | Yes | No | No |

### Output Link Fields

The output links through which the VALA ... VALU field values are sent
during record processing, provided the subroutine returned 0.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OUTA | Output Link A | OUTLINK | Yes |   | Yes | Yes | No |
| OUTB | Output Link B | OUTLINK | Yes |   | Yes | Yes | No |
| OUTC | Output Link C | OUTLINK | Yes |   | Yes | Yes | No |
| OUTD | Output Link D | OUTLINK | Yes |   | Yes | Yes | No |
| OUTE | Output Link E | OUTLINK | Yes |   | Yes | Yes | No |
| OUTF | Output Link F | OUTLINK | Yes |   | Yes | Yes | No |
| OUTG | Output Link G | OUTLINK | Yes |   | Yes | Yes | No |
| OUTH | Output Link H | OUTLINK | Yes |   | Yes | Yes | No |
| OUTI | Output Link I | OUTLINK | Yes |   | Yes | Yes | No |
| OUTJ | Output Link J | OUTLINK | Yes |   | Yes | Yes | No |
| OUTK | Output Link K | OUTLINK | Yes |   | Yes | Yes | No |
| OUTL | Output Link L | OUTLINK | Yes |   | Yes | Yes | No |
| OUTM | Output Link M | OUTLINK | Yes |   | Yes | Yes | No |
| OUTN | Output Link N | OUTLINK | Yes |   | Yes | Yes | No |
| OUTO | Output Link O | OUTLINK | Yes |   | Yes | Yes | No |
| OUTP | Output Link P | OUTLINK | Yes |   | Yes | Yes | No |
| OUTQ | Output Link Q | OUTLINK | Yes |   | Yes | Yes | No |
| OUTR | Output Link R | OUTLINK | Yes |   | Yes | Yes | No |
| OUTS | Output Link S | OUTLINK | Yes |   | Yes | Yes | No |
| OUTT | Output Link T | OUTLINK | Yes |   | Yes | Yes | No |
| OUTU | Output Link U | OUTLINK | Yes |   | Yes | Yes | No |

### Output Value Fields

These fields hold scalar or array data generated by the subroutine which will
be sent through the OUTA ... OUTU links during record processing.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VALA | Output value A | Set by FTVA | No |   | Yes | Yes | No |
| VALB | Output value B | Set by FTVB | No |   | Yes | Yes | No |
| VALC | Output value C | Set by FTVC | No |   | Yes | Yes | No |
| VALD | Output value D | Set by FTVD | No |   | Yes | Yes | No |
| VALE | Output value E | Set by FTVE | No |   | Yes | Yes | No |
| VALF | Output value F | Set by FTVF | No |   | Yes | Yes | No |
| VALG | Output value G | Set by FTVG | No |   | Yes | Yes | No |
| VALH | Output value H | Set by FTVH | No |   | Yes | Yes | No |
| VALI | Output value I | Set by FTVI | No |   | Yes | Yes | No |
| VALJ | Output value J | Set by FTVJ | No |   | Yes | Yes | No |
| VALK | Output value K | Set by FTVK | No |   | Yes | Yes | No |
| VALL | Output value L | Set by FTVL | No |   | Yes | Yes | No |
| VALM | Output value M | Set by FTVM | No |   | Yes | Yes | No |
| VALN | Output value N | Set by FTVN | No |   | Yes | Yes | No |
| VALO | Output value O | Set by FTVO | No |   | Yes | Yes | No |
| VALP | Output value P | Set by FTVP | No |   | Yes | Yes | No |
| VALQ | Output value Q | Set by FTVQ | No |   | Yes | Yes | No |
| VALR | Output value R | Set by FTVR | No |   | Yes | Yes | No |
| VALS | Output value S | Set by FTVS | No |   | Yes | Yes | No |
| VALT | Output value T | Set by FTVT | No |   | Yes | Yes | No |
| VALU | Output value U | Set by FTVU | No |   | Yes | Yes | No |

### Old Value Fields

The previous values of the output fields.
These are used to determine when to post events if EFLG is set to `ON CHANGE`.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| OVLA | Old Output A | NOACCESS | No |   | No | No | No |
| OVLB | Old Output B | NOACCESS | No |   | No | No | No |
| OVLC | Old Output C | NOACCESS | No |   | No | No | No |
| OVLD | Old Output D | NOACCESS | No |   | No | No | No |
| OVLE | Old Output E | NOACCESS | No |   | No | No | No |
| OVLF | Old Output F | NOACCESS | No |   | No | No | No |
| OVLG | Old Output G | NOACCESS | No |   | No | No | No |
| OVLH | Old Output H | NOACCESS | No |   | No | No | No |
| OVLI | Old Output I | NOACCESS | No |   | No | No | No |
| OVLJ | Old Output J | NOACCESS | No |   | No | No | No |
| OVLK | Old Output K | NOACCESS | No |   | No | No | No |
| OVLL | Old Output L | NOACCESS | No |   | No | No | No |
| OVLM | Old Output M | NOACCESS | No |   | No | No | No |
| OVLN | Old Output N | NOACCESS | No |   | No | No | No |
| OVLO | Old Output O | NOACCESS | No |   | No | No | No |
| OVLP | Old Output P | NOACCESS | No |   | No | No | No |
| OVLQ | Old Output Q | NOACCESS | No |   | No | No | No |
| OVLR | Old Output R | NOACCESS | No |   | No | No | No |
| OVLS | Old Output S | NOACCESS | No |   | No | No | No |
| OVLT | Old Output T | NOACCESS | No |   | No | No | No |
| OVLU | Old Output U | NOACCESS | No |   | No | No | No |

### Output Value Data Types

Field types of the output value fields.
The choices can be found by following a link to the menuFtype definition.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| FTVA | Type of VALA | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVB | Type of VALB | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVC | Type of VALC | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVD | Type of VALD | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVE | Type of VALE | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVF | Type of VALF | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVG | Type of VALG | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVH | Type of VALH | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVI | Type of VALI | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVJ | Type of VALJ | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVK | Type of VALK | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVL | Type of VALL | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVM | Type of VALM | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVN | Type of VALN | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVO | Type of VALO | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVP | Type of VALP | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVQ | Type of VALQ | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVR | Type of VALR | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVS | Type of VALS | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVT | Type of VALT | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |
| FTVU | Type of VALU | MENU [menuFtype](menuFtype.md) | Yes | DOUBLE | Yes | No | No |

### Output Value Array Capacity

These fields specify how many array elements the output value fields may hold.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NOVA | Max. elements in VALA | ULONG | Yes | 1 | Yes | No | No |
| NOVB | Max. elements in VALB | ULONG | Yes | 1 | Yes | No | No |
| NOVC | Max. elements in VALC | ULONG | Yes | 1 | Yes | No | No |
| NOVD | Max. elements in VALD | ULONG | Yes | 1 | Yes | No | No |
| NOVE | Max. elements in VALE | ULONG | Yes | 1 | Yes | No | No |
| NOVF | Max. elements in VALF | ULONG | Yes | 1 | Yes | No | No |
| NOVG | Max. elements in VALG | ULONG | Yes | 1 | Yes | No | No |
| NOVH | Max. elements in VAlH | ULONG | Yes | 1 | Yes | No | No |
| NOVI | Max. elements in VALI | ULONG | Yes | 1 | Yes | No | No |
| NOVJ | Max. elements in VALJ | ULONG | Yes | 1 | Yes | No | No |
| NOVK | Max. elements in VALK | ULONG | Yes | 1 | Yes | No | No |
| NOVL | Max. elements in VALL | ULONG | Yes | 1 | Yes | No | No |
| NOVM | Max. elements in VALM | ULONG | Yes | 1 | Yes | No | No |
| NOVN | Max. elements in VALN | ULONG | Yes | 1 | Yes | No | No |
| NOVO | Max. elements in VALO | ULONG | Yes | 1 | Yes | No | No |
| NOVP | Max. elements in VALP | ULONG | Yes | 1 | Yes | No | No |
| NOVQ | Max. elements in VALQ | ULONG | Yes | 1 | Yes | No | No |
| NOVR | Max. elements in VALR | ULONG | Yes | 1 | Yes | No | No |
| NOVS | Max. elements in VALS | ULONG | Yes | 1 | Yes | No | No |
| NOVT | Max. elements in VALT | ULONG | Yes | 1 | Yes | No | No |
| NOVU | Max. elements in VALU | ULONG | Yes | 1 | Yes | No | No |

### Output Value Array Size

These fields specify how many array elements the output value fields currently
contain.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NEVA | Num. elements in VALA | ULONG | No | 1 | Yes | No | No |
| NEVB | Num. elements in VALB | ULONG | No | 1 | Yes | No | No |
| NEVC | Num. elements in VALC | ULONG | No | 1 | Yes | No | No |
| NEVD | Num. elements in VALD | ULONG | No | 1 | Yes | No | No |
| NEVE | Num. elements in VALE | ULONG | No | 1 | Yes | No | No |
| NEVF | Num. elements in VALF | ULONG | No | 1 | Yes | No | No |
| NEVG | Num. elements in VALG | ULONG | No | 1 | Yes | No | No |
| NEVH | Num. elements in VAlH | ULONG | No | 1 | Yes | No | No |
| NEVI | Num. elements in VALI | ULONG | No | 1 | Yes | No | No |
| NEVJ | Num. elements in VALJ | ULONG | No | 1 | Yes | No | No |
| NEVK | Num. elements in VALK | ULONG | No | 1 | Yes | No | No |
| NEVL | Num. elements in VALL | ULONG | No | 1 | Yes | No | No |
| NEVM | Num. elements in VALM | ULONG | No | 1 | Yes | No | No |
| NEVN | Num. elements in VALN | ULONG | No | 1 | Yes | No | No |
| NEVO | Num. elements in VALO | ULONG | No | 1 | Yes | No | No |
| NEVP | Num. elements in VALP | ULONG | No | 1 | Yes | No | No |
| NEVQ | Num. elements in VALQ | ULONG | No | 1 | Yes | No | No |
| NEVR | Num. elements in VALR | ULONG | No | 1 | Yes | No | No |
| NEVS | Num. elements in VALS | ULONG | No | 1 | Yes | No | No |
| NEVT | Num. elements in VALT | ULONG | No | 1 | Yes | No | No |
| NEVU | Num. elements in VALU | ULONG | No | 1 | Yes | No | No |

### Old Value Array Size

These fields specify how many array elements the old value fields currently
contain.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ONVA | Num. elements in OVLA | ULONG | No | 1 | Yes | No | No |
| ONVB | Num. elements in OVLB | ULONG | No | 1 | Yes | No | No |
| ONVC | Num. elements in OVLC | ULONG | No | 1 | Yes | No | No |
| ONVD | Num. elements in OVLD | ULONG | No | 1 | Yes | No | No |
| ONVE | Num. elements in OVLE | ULONG | No | 1 | Yes | No | No |
| ONVF | Num. elements in OVLF | ULONG | No | 1 | Yes | No | No |
| ONVG | Num. elements in OVLG | ULONG | No | 1 | Yes | No | No |
| ONVH | Num. elements in VAlH | ULONG | No | 1 | Yes | No | No |
| ONVI | Num. elements in OVLI | ULONG | No | 1 | Yes | No | No |
| ONVJ | Num. elements in OVLJ | ULONG | No | 1 | Yes | No | No |
| ONVK | Num. elements in OVLK | ULONG | No | 1 | Yes | No | No |
| ONVL | Num. elements in OVLL | ULONG | No | 1 | Yes | No | No |
| ONVM | Num. elements in OVLM | ULONG | No | 1 | Yes | No | No |
| ONVN | Num. elements in OVLN | ULONG | No | 1 | Yes | No | No |
| ONVO | Num. elements in OVLO | ULONG | No | 1 | Yes | No | No |
| ONVP | Num. elements in OVLP | ULONG | No | 1 | Yes | No | No |
| ONVQ | Num. elements in OVLQ | ULONG | No | 1 | Yes | No | No |
| ONVR | Num. elements in OVLR | ULONG | No | 1 | Yes | No | No |
| ONVS | Num. elements in OVLS | ULONG | No | 1 | Yes | No | No |
| ONVT | Num. elements in OVLT | ULONG | No | 1 | Yes | No | No |
| ONVU | Num. elements in OVLU | ULONG | No | 1 | Yes | No | No |

<div>
    <br>
    <hr>
    <br>
</div>

## Record Support Routines

### init\_record

    long (*init_record)(struct dbCommon *precord, int pass)

This routine is called twice at iocInit. On the first call it does the
following:

- Calloc sufficient space to hold the number of input scalars and/or arrays
defined by the settings of the fields FTA-FTU and NOA-NOU. Initialize fields
NE\* to the values of the associated NO\* field values.
- Calloc sufficient space to hold the number of output scalars and/or arrays
defined by  the settings of the fields FTVA-FTVU and NOVA-NOVU. For the output
fields, also calloc space to  hold the previous value of a field. This is
required when the decision is made on whether or not to post events.

On the second call, it does the following:

- Initializes SUBL if it is a constant link.
- Initializes each constant input link.
- If the field INAM is set, look-up the address of the routine and call it.
- If the field LFLG is set to IGNORE and SNAM is defined, look up the address of
the process routine.

### process

    long (*process)(struct dbCommon *precord)

This routine implements the following algorithm:

- If PACT is FALSE, perform normal processing
- If PACT is TRUE, perform asynchronous-completion processing

Normal processing:

- Set PACT to TRUE.
- If the field LFLG is set to READ, get the subroutine name from the SUBL link.
If the name is not NULL and it is not the same as the previous subroutine name,
look up the subroutine address. Set the old subroutine name, ONAM, equal to the
current name, SNAM.
- Fetch the values from the input links.
- Set PACT to FALSE
- If all input-link fetches succeeded, call the routine specified by SNAM.
- Set VAL equal to the return value from the routine specified by SNAM.
- If the SNAM routine set PACT to TRUE, then return.  In this case, we presume
the routine has arranged that process will be called at some later time for
asynchronous completion.
- Set PACT to TRUE.
- If VAL is zero, write the output values using the output links.
- Get the time of processing and put it into the timestamp field.
- If VAL has changed, post a change-of value and log event for  this field.
If EFLG is set to ALWAYS, post change-of-value and log events for every output
field. If EFLG is set to ON CHANGE, post change-of-value and log events for
every output field which has changed. In the case of an array, an event will be
posted if any single element of the array has changed. If EFLG is set to NEVER,
no change-of-value or log events are posted for the output fields.
- Process the record on the end of the forward link, if one exists.
- Set PACT to FALSE.

Asynchronous-completion processing:

- Call the routine specified by SNAM (again).
- Set VAL equal to the return value from the routine specified by SNAM.
- Set PACT to TRUE.
- If VAL is zero, write the output values using the output links.
- Get the time of processing and put it into the timestamp field.
- If VAL has changed, post a change-of value and log event for this field. If
EFLG is set to ALWAYS, post change-of-value and log events for every output
field. If EFLG is set to ON CHANGE, post change-of-value and log events for
every output field which has changed. In the case of an array, an event will
be posted if any single element of the array has changed. If EFLG is set to
NEVER, no  change-of-value or log events are posted for the output fields.
- Process the record on the end of the forward link, if one exists.
- Set PACT to FALSE.

<div>
    <br>
    <hr>
    <br>
</div>

## Use of the aSub Record

The aSub record has input-value fields (A-U) and output-value fields
(VALA-VALU), which are completely independent.  The input-value fields have
associated input links (INPA-INPU), and the output-value fields have associated
output links (OUTA-OUTU).  Both inputs and outputs have type fields (FTA-FTU,
FTVA-FTVU, which default to 'DOUBLE') and number-of-element fields (NOA-NOU,
NOVA-NOVU, which default to '1'). The output links OUTA-OUTU will only be
processed if the subroutine returns a zero (OK) status value.

### Example database fragment

To use the A field to read an array from some other record, then, you would
need a database fragment that might look something like this:

    record(aSub,"my_asub_record") {
        field(SNAM,"my_asub_routine")
        ...
        field(FTA, "LONG")
        field(NOA, "100")
        field(INPA, "myWaveform_1 NPP NMS")
        ...
    }

If you wanted some other record to be able to write to the A field, then you
would delete the input link above.  If you wanted the A field to hold a scalar
value, you would either delete the NOA specification, or specify it as "1".

### Example subroutine fragment

The associated subroutine code that uses the A field might look like this:

    static long my_asub_routine(aSubRecord *prec) {
        long i;
        epicsInt32 *a;

        double sum=0;
        ...
        a = (epicsInt32 *)prec->a;
        for (i=0; i<prec->noa; i++) {
            sum += a[i];
        }
        ...
        return 0; /* process output links */
    }

Note that the subroutine code must always handle the value fields (A-U,
VALA-VALU) as arrays, even if they contain only a single element.

### Required export code

Aside from your own code, you must export and register your subroutines so the
record can locate them.  The simplest way is as follows:

    #include <registryFunction.h>
    #include <epicsExport.h>
    
    static long my_asub_routine(aSubRecord *prec) {
        ...
    }
    epicsRegisterFunction(my_asub_routine);

### Required database-definition code

The .dbd file loaded by the ioc must then contain the following line, which
tells the linker to include your object file in the IOC binary:

    function(my_asub_routine)

### Device support, writing to hardware

The aSub record does not call any device support routines. If you want to write
to hardware, you might use your output fields and links to write to some other
record that can write to hardware.

### Dynamically Changing the User Routine called during Record Processing

The aSub record allows the user to dynamically change which routine is called
when the record processes. This can be done in two ways:

- The LFLG field can be set to READ so that the name of the routine is read from
the SUBL link. Thus, whatever is feeding this link can change the name of the
routine before the aSub record is processed. In this case, the record looks in
the symbol table for the symbol name whenever the name of routine fetched from
the link changes.
- The LFLG field can be set to IGNORE. In this case, the routine called during
record processing is that specified in the SNAM field. Under these conditions,
the SNAM field can be changed by a Channel Access write to that field. During
development when trying several versions of the routine, it is not necessary
to reboot the IOC and reload the database. A new routine can be loaded with
the vxWorks ld command, and Channel Access or the dbpf command used to put the
name of the routine into the record's SNAM field. The record will look up the
symbol name in the symbol table whenever the SNAM field gets modified. The
same routine name can even be used as the vxWorks symbol lookup returns the
latest version of the code to have been loaded.
