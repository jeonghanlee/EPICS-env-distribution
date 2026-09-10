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

| Index | Identifier                             | Choice String          |
| ----- | -------------------------------------- | ---------------------- |
|     0 | aSubLFLG\_IGNORE                       | IGNORE                 |
|     1 | aSubLFLG\_READ                         | READ                   |

### Menu aSubEFLG

The EFLG menu field indicates whether monitor events should be posted for the
VALA..VALU output value fields.

| Index | Identifier                             | Choice String          |
| ----- | -------------------------------------- | ---------------------- |
|     0 | aSubEFLG\_NEVER                        | NEVER                  |
|     1 | aSubEFLG\_ON\_CHANGE                   | ON CHANGE              |
|     2 | aSubEFLG\_ALWAYS                       | ALWAYS                 |

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

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| VAL   | Subr. return value         | LONG          | No  |         | Yes  | Yes   | No    |
| OVAL  | Old return value           | LONG          | No  |         | Yes  | No    | No    |
| INAM  | Initialize Subr. Name      | STRING \[41\] | Yes |         | Yes  | No    | No    |
| LFLG  | Subr. Input Enable         | MENU [aSubLFLG](#menu-asublflg) | Yes |         | Yes  | Yes   | No    |
| SUBL  | Subroutine Name Link       | INLINK        | Yes |         | Yes  | No    | No    |
| SNAM  | Process Subr. Name         | STRING \[41\] | Yes |         | Yes  | Yes   | No    |
| ONAM  | Old Subr. Name             | STRING \[41\] | Yes |         | Yes  | No    | No    |
| SADR  | Subroutine Address         | NOACCESS      | No  |         | No   | No    | No    |
| CADR  | Subroutine Cleanup Address | NOACCESS      | No  |         | No   | No    | No    |
| BRSV  | Bad Return Severity        | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |         | Yes  | Yes   | Yes   |

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

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| EFLG  | Output Event Flag          | MENU [aSubEFLG](#menu-asubeflg) | Yes |       1 | Yes  | Yes   | No    |

### Input Link Fields

The input links from where the values of A,...,U are fetched
during record processing.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| INPA  | Input Link A               | INLINK        | Yes |         | Yes  | Yes   | No    |
| ⋮                                                                                  ||||||||
| INPU  | Input Link U               | INLINK        | Yes |         | Yes  | Yes   | No    |

### Input Value Fields

These fields hold the scalar or array values fetched through the input links
INPA,...,INPU.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| A     | Input value A              | Set by FTA\[NOA\] | No  |         | Yes  | Yes   | No    |
| ⋮                                                                                  ||||||||
| U     | Input value U              | Set by FTU\[NOU\] | No  |         | Yes  | Yes   | No    |

### Input Value Data Types

Field types of the input value fields.
The choices can be found by following the link to the menuFtype definition.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| FTA   | Type of A                  | MENU [menuFtype](menuFtype.md) | Yes |  DOUBLE | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| FTU   | Type of U                  | MENU [menuFtype](menuFtype.md) | Yes |  DOUBLE | Yes  | No    | No    |

### Input Value Array Capacity

These fields specify how many array elements the input value fields may hold.

Note that access to the `NOT` field from C code must use the field name in
upper case, e.g. `prec->NOT` since the lower-case `not` is a reserved
word in C++ and cannot be used as an identifier.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| NOA   | Max. elements in A         | ULONG         | Yes |       1 | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| NOU   | Max. elements in U         | ULONG         | Yes |       1 | Yes  | No    | No    |

### Input Value Array Size

These fields specify how many array elements the input value fields currently
contain.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| NEA   | Num. elements in A         | ULONG         | No  |       1 | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| NEU   | Num. elements in U         | ULONG         | No  |       1 | Yes  | No    | No    |

### Output Link Fields

The output links through which the VALA ... VALU field values are sent
during record processing, provided the subroutine returned 0.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| OUTA  | Output Link A              | OUTLINK       | Yes |         | Yes  | Yes   | No    |
| ⋮                                                                                  ||||||||
| OUTU  | Output Link U              | OUTLINK       | Yes |         | Yes  | Yes   | No    |

### Output Value Fields

These fields hold scalar or array data generated by the subroutine which will
be sent through the OUTA ... OUTU links during record processing.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| VALA  | Output value A             | Set by FTVA\[NOVA\] | No  |         | Yes  | Yes   | No    |
| ⋮                                                                                  ||||||||
| VALU  | Output value U             | Set by FTVU\[NOVU\] | No  |         | Yes  | Yes   | No    |

### Old Value Fields

The previous values of the output fields.
These are used to determine when to post events if EFLG is set to `ON CHANGE`.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| OVLA  | Old Output A               | NOACCESS      | No  |         | No   | No    | No    |
| ⋮                                                                                  ||||||||
| OVLU  | Old Output U               | NOACCESS      | No  |         | No   | No    | No    |

### Output Value Data Types

Field types of the output value fields.
The choices can be found by following a link to the menuFtype definition.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| FTVA  | Type of VALA               | MENU [menuFtype](menuFtype.md) | Yes |  DOUBLE | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| FTVU  | Type of VALU               | MENU [menuFtype](menuFtype.md) | Yes |  DOUBLE | Yes  | No    | No    |

### Output Value Array Capacity

These fields specify how many array elements the output value fields may hold.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| NOVA  | Max. elements in VALA      | ULONG         | Yes |       1 | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| NOVU  | Max. elements in VALU      | ULONG         | Yes |       1 | Yes  | No    | No    |

### Output Value Array Size

These fields specify how many array elements the output value fields currently
contain.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| NEVA  | Num. elements in VALA      | ULONG         | No  |       1 | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| NEVU  | Num. elements in VALU      | ULONG         | No  |       1 | Yes  | No    | No    |

### Old Value Array Size

These fields specify how many array elements the old value fields currently
contain.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| ONVA  | Num. elements in OVLA      | ULONG         | No  |       1 | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| ONVU  | Num. elements in OVLU      | ULONG         | No  |       1 | Yes  | No    | No    |

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
