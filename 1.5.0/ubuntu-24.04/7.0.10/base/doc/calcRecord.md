# Calculation Record (calc)

The calculation or "Calc" record is used to perform algebraic, relational,
and logical operations on values retrieved from other records. The result
of its operations can then be accessed by another record so that it can
then be used.

Since 7.0.10 the number of inputs has been increased from 12 to 21.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The Calc record has the standard fields for specifying under what
circumstances the record will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#scan-fields).

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| SCAN  | Scan Mechanism             | MENU [menuScan](menuScan.md) | Yes |         | Yes  | Yes   | No    |
| PHAS  | Scan Phase                 | SHORT         | Yes |         | Yes  | Yes   | No    |
| EVNT  | Event Name                 | STRING \[40\] | Yes |         | Yes  | Yes   | No    |
| PRIO  | Scheduling Priority        | MENU [menuPriority](menuPriority.md) | Yes |         | Yes  | Yes   | No    |
| PINI  | Process at iocInit         | MENU [menuPini](menuPini.md) | Yes |         | Yes  | Yes   | No    |

### Read Parameters

The read parameters for the Calc record consist of 21 input links INPA -
INPU. The fields can be database links, channel access links, or constants.
If they are links, they must specify another record's field or a
channel access link. If they are constants, they will be initialized with
the value they are configured with and can be changed via `dbPuts`. They
cannot be hardware addresses.

See [Address
Specification](https://docs.epics-controls.org/en/latest/process-database/EPICS_Process_Database_Concepts.html#address-specification)
for information on how to specify database links.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| INPA  | Input A                    | INLINK        | Yes |         | Yes  | Yes   | No    |
| ⋮                                                                                  ||||||||
| INPU  | Input U                    | INLINK        | Yes |         | Yes  | Yes   | No    |

### Expression

At the core of the Calc record lies the CALC and RPCL fields.
The CALC field holds an infix expression to be evaluated whenever the record is
processed.
The calculated value is placed in the VAL field and can be accessed from there.

The CALC expression gets compiled into a stream of Reverse Polish Notation (RPN)
opcodes for a stack-based machine, and stored in the RPCL field.
The RPN opcodes are used to calculate VAL at run-time, and are more efficient
than evaluating the infix expression.
The CALC expression can be replaced at run-time, triggering a special record
routine to compile the new expression into Reverse Polish Notation.

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
| RPCL  | Reverse Polish Calc        | NOACCESS      | No  |         | No   | No    | No    |

### Literals

- Standard double precision floating point numbers
- `Inf`: Infinity
- `NaN`: Not a Number

### Constants

- `PI`: returns the mathematical constant π
- `D2R`: evaluates to π/180 which, when used as a multiplier, converts an
angle from degrees to radians
- `R2D`: evaluates to 180/π which as a multiplier converts an angle from
radians to degrees

### Operands

The expression uses the values retrieved from the INPx links as operands,
though constants can be used as operands too. These values retrieved from
the input links are stored in the A-U fields. The values to be used in the
expression are simply referenced by the field letter. For instance, the
value obtained from INPA link is stored in the field A, and the value
obtained from INPB is stored in field B. The field names can be included in
the expression which will operate on their respective values, as in A+B.
Also, the RNDM nullary function can be included as an operand in the
expression in order to generate a random number between 0 and 1.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| A     | Value of Input A           | DOUBLE        | No  |         | Yes  | Yes   | Yes   |
| ⋮                                                                                  ||||||||
| U     | Value of Input U           | DOUBLE        | No  |         | Yes  | Yes   | Yes   |

The keyword VAL returns the current contents of the VAL field (which can be
written to by a CA put, so it might _not_ be the result from the last time
the expression was evaluated).

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

- Result is `E` if `(A + B)<(C + D)`
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

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. These
fields are used to display VAL and other parameters of the calculation
record either textually or graphically.

The EGU field contains a string of up to 16 characters which is supplied by
the user and which describes the values being operated upon. The string is
retrieved whenever the routine `get_units` is called. The EGU string is
solely for an operator's sake and does not have to be used.

The HOPR and LOPR fields only refer to the limits of the VAL, HIHI, HIGH,
LOW and LOLO fields. PREC controls the precision of the VAL field.

See [Fields Common to All Record Types](dbCommonRecord.md#operator-display-parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary                    | Type          | DCT | Default | Read | Write | CA PP |
| ----- | -------------------------- | ------------- | --- | ------- | ---- | ----- | ----- |
| EGU   | Engineering Units          | STRING \[16\] | Yes |         | Yes  | Yes   | No    |
| PREC  | Display Precision          | SHORT         | Yes |         | Yes  | Yes   | No    |
| HOPR  | High Operating Rng         | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| LOPR  | Low Operating Range        | DOUBLE        | Yes |         | Yes  | Yes   | No    |
| NAME  | Record Name                | STRING \[61\] | No  |         | Yes  | No    | No    |
| DESC  | Descriptor                 | STRING \[41\] | Yes |         | Yes  | Yes   | No    |

### Alarm Parameters

The possible alarm conditions for the Calc record are the SCAN, READ,
Calculation, and limit alarms. The SCAN and READ alarms are called by the
record support routines. The Calculation alarm is called by the record
processing routine when the CALC expression is an invalid one, upon which
an error message is generated.

The following alarm parameters which are configured by the user, define the
limit alarms for the VAL field and the severity corresponding to those
conditions.

The HYST field defines an alarm deadband for each limit.

The AFTC field sets the time constant on a low-pass filter that delays the
reporting of limit alarms until the signal has been within the alarm range for
that number of seconds (the default AFTC value of zero retains the previous
behavior).

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
| AFTC  | Alarm Filter Time Constant | DOUBLE        | Yes |         | Yes  | Yes   | No    |

### Monitor Parameters

These paramaeters are used to determine when to send monitors for the value
fields. These monitors are sent when the value field exceeds the last
monitored field by the appropriate deadband, the ADEL for archiver monitors
and the MDEL field for all other types of monitors. If these fields have a
value of zero, every time the value changes, monitors are triggered; if they have a
value of -1, every time the record is scanned, monitors are triggered. See
["Monitor Specification"](#monitor-specification) for a complete explanation of monitors.

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
corresponding fields. For instance, if LA does not equal the value A,
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
link is created if the input link is a PV\_LINK.

A routine postfix is called to convert the infix expression in CALC to
Reverse Polish Notation. The result is stored in RPCL.

## `process`

See next section.

## `special`

This is called if CALC is changed. `special` calls postfix.

## `get_units`

Retrieves EGU.

## `get_precision`

Retrieves PREC.

## `get_graphic_double`

Sets the upper display and lower display limits for a field. If the field
is VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR, else
if the field has upper and lower limits defined they will be used, else the
upper and lower maximum values for the field will be used.

## `get_control_double`

Sets the upper control and the lower control limits for a field. If the
field is VAL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and
LOPR, else if the field has upper and lower limits defined they will be
used, else the upper and lower maximum values for the field type will be
used.

## `get_alarm_double`

Sets the following values:

> upper\_alarm\_limit = HIHI
>
> upper\_warning\_limit = HIGH
>
> lower\_warning\_limit = LOW
>
> lower\_alarm\_limit = LOLO

### Record Processing

Routine process implements the following algorithm:

1. Fetch all arguments.
2. Call routine `calcPerform`, which calculates VAL from the postfix version of
the expression given in CALC. If `calcPerform` returns success UDF is set to
FALSE.
3. Check alarms. This routine checks to see if the new VAL causes the alarm
status and severity to change. If so, NSEV, NSTA, and LALM are set. It also
honors the alarm hysteresis factor (HYST). Thus the value must change by
at least HYST before the alarm status and severity changes.
4. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and values change monitors are invoked if ADEL and MDEL conditions
    are met.
    - Monitors for A-U are checked whenever other monitors are invoked.
    - NSEV and NSTA are reset to 0.
5. Scan forward link if necessary, set PACT FALSE, and return.
