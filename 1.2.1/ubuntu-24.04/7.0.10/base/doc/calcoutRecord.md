# Calculation Output Record (calcout)

The Calculation Output or "Calcout" record is similar to the Calc record
with the added feature of having outputs (an "output link" and an "output
event") which are conditionally executed based on the result of the
calculation. This feature allows conditional branching to be implemented
within an EPICS database (e.g. process Record\_A only if Record\_B has a
value of 0). The Calcout record is also similar to the Wait record (with
additional features) but uses EPICS standard INLINK and OUTLINK fields
rather than the DBF\_STRING fields used in the Wait record. For new
databases, it is recommended that the Calcout record be used instead of the
Wait record.

Since 7.0.10 the number of inputs has been increased from 12 to 21.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The Calcout record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are listed in [Scan Fields](dbCommonRecord.md#scan-fields).

### Read Parameters

The read parameters for the Calcout record consists of 21 input links INPA -
INPU. The fields can be database links, channel access links, or constants.
If they are links, they must specify another record's field. If
they are constants, they will be initialized with the value they are
configured with and can be changed via `dbPuts`. These fields cannot be
hardware addresses. In addition, the Calcout record contains the INAV -
INUV fields which indicate the status of the link fields, for
example, whether or not the specified PV was found and a link to it
established. See ["Operator Display Parameters"](#operator-display-parameters) for an explanation of these
fields.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| INPA  | Input A                    | INLINK        | Yes |         | Yes  | Yes   | No    |
| ⋮                                                                                  ||||||||
| INPU  | Input U                    | INLINK        | Yes |         | Yes  | Yes   | No    |

### Expressions

Like the Calc record, the Calcout record's CALC field holds an infix expression
to be evaluated whenever the record is processed.
The resulting value is placed in the VAL field.

The OOPT field condition is applied to VAL (see ["Output Parameters"](#output-parameters)) and
controls whether to write to the output link (or post a named event), and the
DOPT field selects whether VAL should be written, or another expression from
the OCAL field should be evaluated and used instead.

The CALC and OCAL expressions get compiled into streams of Reverse Polish
Notation (RPN) opcodes for a stack-based machine, and stored in the RPCL and
ORPC fields respectively.

The RPN opcodes are used to calculate VAL at run-time, and are more efficient
than evaluating the infix expression.
The CALC and OCAL expressions can be replaced at run-time, triggering a special
record routine to compile the new expression into Reverse Polish Notation.

The infix expressions that can be used are very similar to the C expression
syntax, but with some additions and subtle differences in operator meaning and
precedence.
The string may contain a series of expressions separated by a semi-colon
character `;`, any one of which may provide the calculation result.
All other expressions included in the string must assign their result to a
variable.
All alphabetic elements described below are case independent, so upper and lower
case letters may be used and mixed in the variable and function names as
desired.
Spaces may be used anywhere within an expression except between characters that
make up a single expression element.

The range of expressions supported by the calculation record are separated into
literals, constants, operands, algebraic operators, trigonometric operators,
relational operators, logical operators, the assignment operator, parentheses
and commas, and the question mark colon or `?:` operator.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| CALC  | Calculation                | STRING \[160\] | Yes |         | Yes  | Yes   | Yes   |
| VAL   | Result                     | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| OVAL  | Output Value               | DOUBLE        | No  |         | Yes  | Yes   | No    |
| RPCL  | Reverse Polish Calc        | NOACCESS      | No  |         | No   | No    | No    |
| ORPC  | Reverse Polish OCalc       | NOACCESS      | No  |         | No   | No    | No    |

### Literals

- Standard double precision floating point numbers
- `Inf`: Infinity
- `NaN`: Not a Number

### Constants

- `PI`: returns the mathematical constant π
- `D2R`: evaluates to π/180 which, when used as a multiplier, converts an
angle from degrees to radians
- `R2D`: evaluates to 180/π which, when used as a multiplier, converts an
angle from radians to degrees

### Operands

The expression can use the values retrieved from the INPx links as
operands, though constants can be used as operands too. These values
retrieved from the input links are stored in the A-U fields. The values to
be used in the expression are simple references by the field letter. For
instance, the value obtained from the INPA link is stored in field A, and
the values obtained from the INPB link is stored in the field B. The names
can be included in the expression will operate on their respective values,
as in A+B.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| A     | Value of Input A           | DOUBLE        | No  |         | Yes  | Yes   | Yes   |
| ⋮                                                                                  ||||||||
| U     | Value of Input U           | DOUBLE        | No  |         | Yes  | Yes   | Yes   |

The keyword VAL returns the current contents of the expression's result
field, i.e. the VAL field for the CALC expression and the OVAL field for
the OCAL expression. (These fields can be written to by CA put, so it might
_not_ be the result from the last time the expression was evaluated).

### Arithmetic Operators

Except for unary minus these are infix binary operators.

- `+` : Addition
- `-` : Subtraction
- `-` : Minus (unary)
- `*` : Multiplication
- `/` : Division
- `%` : Modulo
- `^` : Exponential
- `**` : Exponential

### Algebraic Functions

When functions take more than one argument, a comma separator must appear
between them.

- `ABS (arg)` : Absolute value
- `EXP (arg)` : Exponential function
- `FMOD (num, den)` : Floating point modulo. Added in 7.0.8
- `LN (arg)` : Natural log
- `LOG (arg)` : Log base 10
- `LOGE (arg)` : Natural log
- `MIN (any number of args)` : Minimum
- `MAX (any number of args)` : Maximum
- `SQR (arg)` : Square root
- `SQRT (arg)` : Square root

### Trigonometric Functions

- `SIN (arg)` : Sine
- `ASIN (arg)` : Arc sine
- `COS (arg)` : Cosine
- `ACOS (arg)` : Arc cosine
- `TAN (arg)` : Tangent
- `ATAN (arg)` : Arc tangent
- `ATAN2 (den, num)` : 2-parameter Arc tangent. Arg's are reversed to ANSI C

### Hyperbolic Trigonometry Functions

- `SINH (arg)` : Hyperbolic sine
- `COSH (arg)` : Hyperbolic cosine
- `TANH (arg)` : Hyperbolic tangent

### Numeric Functions

- `CEIL (arg)` : Ceiling
- `FLOOR (arg)` : Floor
- `NINT (arg)` : Round to nearest integer
- `ISINF (arg)` : returns non-zero if any argument is Inf
- `ISNAN (any number of args)` : returns non-zero (true) if any argument is NaN
or Inf
- `FINITE (any number of args)` : returns non-zero (true) if none of the
arguments are NaN or Inf

### Boolean/Logical Operators

These operators use their arguments as a true (non-zero) or false (zero) value.

- `&&` : And, infix binary
- `||` : Or, infix binary
- `!` : Not, unary prefix

### Bitwise Operators

Mostly infix binary, the arguments are converted to a 32-bit integer, the
operator is applied, and the result converted back into a double.

- `&` : Bitwise and
- `|` : Bitwise or
- `~` : Bitwise not or one's complement, unary prefix
- `<<` : Arithmetic shift left
- `>>` : Arithmetic shift right
- `>>>` : Logical shift right
- `AND` : Bitwise and
- `OR` : Bitwise or
- `XOR` : Bitwise exclusive or
- `NOT` : Bitwise not or one's complement, unary prefix

### Relational Operators

These are all infix binary operators.

- `>=` : Greater than or equal to
- `>` : Greater than
- `<=` : Less than or equal to
- `<` : Less than
- `!=` : Not equal to
- `#` : Not equal to
- `==` : Equal to
- `=` : Equal to (not assignment)

### Assignment Operator

- `:=` : assigns a value (right hand side) to a variable (i.e. field)

### Parentheses, Comma, and Semicolon

The open `(` and close parentheses `)` are supported to override precedence
rules in a sub-expression.
Nested parentheses are supported to significant depth.

The comma `,` is required to separate the arguments of a function.

The semicolon `;` is used to value separate expressions.
Exactly one value expression must be present, but multiple assignment
expressions may be included before and/or after the value expression.

### Conditional Operator

The C language's question mark colon `?:` ternary operator is supported.
The format is:

_condition_ `?` _true-expression_ `:` _false-expression_

## Expression Examples

### Algebraic

`A + B + 10`

- Result is `A + B + 10`

### Relational

`(A + B) < (C + D)`

- Result is 1 if `(A + B) < (C + D)`
- Result is 0 if `(A + B) >= (C + D)`

### Question Mark

`(A + B) < (C + D) ? E : F + L + 10`

- Result is `E` if `(A + B) < (C + D)`
- Result is `F + L + 10` if `(A + B) >= (C + D)`

Prior to Base 3.14.9 it was legal to omit the colon `:` and the second (else)
part of the conditional, like this:

`(A + B)<(C + D) ? E`

- Result is E if `(A + B)<(C + D)`
- Result is unchanged if `(A + B)>=(C + D)`

    From 3.14.9 onwards, this expression must be written as
    `(A + B) < (C + D) ? E : VAL`

### Logical

`A & B`

- Causes the following to occur:
    - Convert A to integer
    - Convert B to integer
    - Bitwise A `and` B
    - Convert result to floating point

### Assignment

`sin(a); a:=a+D2R`

- Causes the Calc record to output the successive values of a sine curve in
1 degree intervals.

### Output Parameters

These parameters specify and control the output capabilities of the Calcout
record. They determine when to write the output, where to write it, and what
the output will be. The OUT link specifies the Process Variable to which
the result will be written.

#### Menu calcoutOOPT

The OOPT field determines the condition that causes the output link to be
written to. It's a menu field that has six choices:

| Index | Identifier                             | Choice String          |
| ----- | -------------------------------------- | ---------------------- |
|     0 | calcoutOOPT\_Every\_Time               | Every Time             |
|     1 | calcoutOOPT\_On\_Change                | On Change              |
|     2 | calcoutOOPT\_When\_Zero                | When Zero              |
|     3 | calcoutOOPT\_When\_Non\_zero           | When Non-zero          |
|     4 | calcoutOOPT\_Transition\_To\_Zero      | Transition To Zero     |
|     5 | calcoutOOPT\_Transition\_To\_Non\_zero | Transition To Non-zero |

- `Every Time` -- write output every time record is processed.
- `On Change` -- write output every time VAL changes, i.e., every time the
result of the expression changes.
- `When Zero` -- when record is processed, write output if VAL is zero.
- `When Non-zero` -- when record is processed, write output if VAL is
non-zero.
- `Transition To Zero` -- when record is processed, write output only if VAL
is zero and the last value was non-zero.
- `Transition To Non-zero` -- when record is processed, write output only if
VAL is non-zero and last value was zero.

#### Menu calcoutDOPT

The DOPT field determines what data is written to the output link when the
output is executed. The field is a menu field with two options: 

| Index | Identifier                             | Choice String          |
| ----- | -------------------------------------- | ---------------------- |
|     0 | calcoutDOPT\_Use\_VAL                  | Use CALC               |
|     1 | calcoutDOPT\_Use\_OVAL                 | Use OCAL               |

If `Use CALC` is specified, when the record writes its
output it will write the result of the expression in the CALC field, that
is, it will write the value of the VAL field. If `Use OCAL` is specified,
the record will instead write the result of the expression in the OCAL
field, which is contained in the OVAL field. The OCAL field is exactly like
the CALC field and has the same functionality it can contain the string
representation of an expression which is evaluated at run-time. Thus, if
necessary, the record can use the result of the CALC expression to
determine if data should be written and can use the result of the OCAL
expression as the data to write.

If the OEVT field isn't empty and the condition in the OOPT field is met, the
record will post the corresponding named event.
If the ODLY field is non-zero, the record pauses for the specified number of
seconds before executing the OUT link or posting the output event.
During this waiting period the record is "active" and will not be processed
again until the wait is over.
The field DLYA is equal to 1 during the delay period. The resolution of the
delay entry system dependent.

The IVOA field specifies what action to take with the OUT link if the
Calcout record enters an INVALID alarm status. The options are
`Continue normally`, `Don't drive outputs`, and `Set output to IVOV`.
If the IVOA field is `Set output to IVOV`, the data entered into the
IVOV field is written to the OUT link if the record alarm severity is
INVALID.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| OUT   | Output Specification       | OUTLINK       | Yes |         | Yes  | Yes   | No    |
| OOPT  | Output Execute Opt         | MENU [calcoutOOPT](#menu-calcoutoopt) | Yes |         | Yes  | Yes   | No    |
| DOPT  | Output Data Opt            | MENU [calcoutDOPT](#menu-calcoutdopt) | Yes |         | Yes  | Yes   | No    |
| OCAL  | Output Calculation         | STRING \[160\] | Yes |         | Yes  | Yes   | Yes   |
| OVAL  | Output Value               | DOUBLE        | No  |         | Yes  | Yes   | No    |
| OEVT  | Event To Issue             | STRING \[40\] | Yes |         | Yes  | Yes   | No    |
| ODLY  | Output Execute Delay       | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| IVOA  | INVALID output action      | MENU [menuIvoa](menuIvoa.md) | Yes |         | Yes  | Yes   | No    |
| IVOV  | INVALID output value       | DOUBLE        | Yes |         | Yes  | Yes   | No    |

### Operator Display Parameter

These parameters are used to present meaningful data to the operator. Some
are also meant to represent the status of the record at run-time.

The EGU field contains a string of up to 16 characters which is supplied by
the user and which describes the values being operated upon. The string is
retrieved whenever the routine `get_units()` is called. The EGU string is
solely for an operator's sake and does not have to be used.

The HOPR and LOPR fields only refer to the limits of the VAL, HIHI, HIGH,
LOW, and LOLO fields. PREC controls the precision of the VAL field.

#### Menu calcoutINAV

The INAV-INUV fields indicate the status of the link to the PVs specified
in the INPA-INPU fields respectively. These fields can have four possible
values:

| Index | Identifier                             | Choice String          |
| ----- | -------------------------------------- | ---------------------- |
|     0 | calcoutINAV\_EXT\_NC                   | Ext PV NC              |
|     1 | calcoutINAV\_EXT                       | Ext PV OK              |
|     2 | calcoutINAV\_LOC                       | Local PV               |
|     3 | calcoutINAV\_CON                       | Constant               |

- `Ext PV NC` -- the PV wasn't found on this IOC and a Channel Access link
hasn't been established.
- `Ext PV OK` -- the PV wasn't found on this IOC and a Channel Access link
has been established.
- `Local PV` -- the PV was found on this IOC.
- `Constant` -- the corresponding link field is a constant.

The OUTV field indicates the status of the OUT link. If has the same
possible values as the INAV-INUV fields.

The CLCV and OLCV fields indicate the validity of the expression in the
CALC and OCAL fields respectively. If the expression in invalid, the field
is set to one.

The DLYA field is set to one during the delay specified in ODLY.

See [Fields Common to All Record Types](dbCommonRecord.md#operator-display-parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| EGU   | Engineering Units          | STRING \[16\] | Yes |         | Yes  | Yes   | No    |
| PREC  | Display Precision          | SHORT         | Yes |         | Yes  | Yes   | No    |
| HOPR  | High Operating Rng         | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| LOPR  | Low Operating Range        | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| INAV  | INPA PV Status             | MENU [calcoutINAV](#menu-calcoutinav) | No  |       1 | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| INUV  | INPU PV Status             | MENU [calcoutINAV](#menu-calcoutinav) | No  |       1 | Yes  | No    | No    |
| OUTV  | OUT PV Status              | MENU [calcoutINAV](#menu-calcoutinav) | No  |         | Yes  | No    | No    |
| CLCV  | CALC Valid                 | LONG          | No  |         | Yes  | Yes   | No    |
| OCLV  | OCAL Valid                 | LONG          | No  |         | Yes  | Yes   | No    |
| DLYA  | Output Delay Active        | USHORT        | No  |         | Yes  | No    | No    |
| NAME  | Record Name                | STRING \[61\] | No  |         | Yes  | No    | No    |
| DESC  | Descriptor                 | STRING \[41\] | Yes |         | Yes  | Yes   | No    |

### Alarm Parameters

The possible alarm conditions for the Calcout record are the SCAN, READ,
Calculation, and limit alarms. The SCAN and READ alarms are called by the
record support routines. The Calculation alarm is called by the record
processing routine when the CALC expression is an invalid one, upon which
an error message is generated.

The following alarm parameters, which are configured by the user, define the
limit alarms for the VAL field and the severity corresponding to those
conditions.

The HYST field defines an alarm deadband for each limit.

See [Alarm Specification](https://docs.epics-controls.org/en/latest/process-database/EPICS_Process_Database_Concepts.html#alarm-specification)
for a complete explanation of record alarms and of the standard fields.
[Alarm Fields](dbCommonRecord.md#alarm-fields) lists other fields related
to alarms that are common to all record types.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| HIHI  | Hihi Alarm Limit           | DOUBLE        | Yes |         | Yes  | Yes   | Yes   |
| HIGH  | High Alarm Limit           | DOUBLE        | Yes |         | Yes  | Yes   | Yes   |
| LOW   | Low Alarm Limit            | DOUBLE        | Yes |         | Yes  | Yes   | Yes   |
| LOLO  | Lolo Alarm Limit           | DOUBLE        | Yes |         | Yes  | Yes   | Yes   |
| HHSV  | Hihi Severity              | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |         | Yes  | Yes   | Yes   |
| HSV   | High Severity              | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |         | Yes  | Yes   | Yes   |
| LSV   | Low Severity               | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |         | Yes  | Yes   | Yes   |
| LLSV  | Lolo Severity              | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |         | Yes  | Yes   | Yes   |
| HYST  | Alarm Deadband             | DOUBLE        | Yes |         | Yes  | Yes   | No    |

### Monitor Parameters

These parameters are used to determine when to send monitors for the value
fields. These monitors are sent when the value field exceeds the last
monitored field by the appropriate deadband, the ADEL for archiver monitors
and the MDEL field for all other types of monitors. If these fields have a
value of zero, every time the value changes, monitors are triggered; if
they have a value of -1, every time the record is scanned, monitors are
triggered. See ["Monitor Specification"](#monitor-specification) for a complete explanation of
monitors.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| ADEL  | Archive Deadband           | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| MDEL  | Monitor Deadband           | DOUBLE        | Yes |         | Yes  | Yes   | No    |

### Run-time Parameters

These fields are not configurable using a configuration tool and none are
modifiable at run-time. They are used to process the record.

The LALM field is used to implement the hysteresis factor for the alarm
limits.

The LA-LU fields are used to decide when to trigger monitors for the
corresponding fields. For instance, if LA does not equal the value for A,
monitors for A are triggered. The MLST and ALST fields are used in the same
manner for the VAL field.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| LALM  | Last Value Alarmed         | DOUBLE        | No  |         | Yes  | No    | No    |
| ALST  | Last Value Archived        | DOUBLE        | No  |         | Yes  | No    | No    |
| MLST  | Last Val Monitored         | DOUBLE        | No  |         | Yes  | No    | No    |
| LA    | Prev Value of A            | DOUBLE        | No  |         | Yes  | No    | No    |
| ⋮                                                                                  ||||||||
| LU    | Prev Value of U            | DOUBLE        | No  |         | Yes  | No    | No    |

## Record Support

### Record Support Routines

## `init_record`

For each constant input link, the corresponding value field is initialized
with the constant value if the input link is CONSTANT or a channel access
link is created if the input link is PV\_LINK.

A routine postfix is called to convert the infix expression in CALC and
OCAL to Reverse Polish Notation. The result is stored in RPCL and ORPC,
respectively.

## `process`

See next section.

## `special`

This is called if CALC or OCAL is changed. `special` calls postfix.

## `get_units`

Retrieves EGU.

## `get_precision`

Retrieves PREC.

## `get_graphic_double`

Sets the upper display and lower display limits for a field. If the field
is VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else
if the field has upper and lower limits defined they will be used, else the
upper and lower maximum values for the field type will be used.

## `get_control_double`

Sets the upper control and lower control limits for a field. If the VAL,
HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else if the
field has upper and lower limits defined they will be used, else the upper
and lower maximum values for the field will be used.

## `get_alarm_double`

Sets the following values:

> upper\_alarm\_limit = HIHI
>
> upper\_warning\_limit = HIGH
>
> lower warning\_limit = LOW
>
> lower\_alarm\_limit = LOLO

### Record Processing

## `process()`

The `process()` routine implements the following algorithm:

1. Fetch all arguments.
2. Call routine `calcPerform()`, which calculates VAL from the prefix version
of the expression given in CALC. If `calcPerform()` returns success, UDF
is set to FALSE.
3. Check alarms. This routine checks to see if the new VAL causes the alarm
status and severity to change. If so, NSEV, NSTA and LALM are set. If also
honors the alarm hysteresis factor (HYST). Thus the value must change by at
least HYST before the alarm status and severity changes.
4. Determine if the Output Execution Option (OOPT) is met. If met, either
execute the output link (and output event) immediately (if ODLY = 0), or
schedule a callback after the specified interval. See the explanation for
the `execOutput()` routine below.
5. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if ADEL and MDEL conditions
    are met.
    - Monitors for A-U are checked whenever other monitors are invoked.
    - NSEV and NSTA are reset to 0
6. If no output delay was specified, scan forward link if necessary, set PACT
FALSE, and return.

## `execOutput()`

1. If DOPT field specifies the use of OCAL, call the routine `calcPerform()`
for the postfix version of the expression in OCAL. Otherwise, use VAL.
2. If the Alarm Severity is INVALID, follow the option as designated by the
field IVOA.
3. The Alarm Severity is not INVALID or IVOA specifies "Continue Normally",
put the value of OVAL to the OUT link and post the event named in OEVT (if
not empty).
4. If an output delay was implemented, process the forward link.
