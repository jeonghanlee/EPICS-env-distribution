# Extensible IOC Database Links

The extensible link mechanism allows new kinds of record links to be created,
using JSON for the link address syntax.
The IOC continues to support the older link types that do not use JSON to
specify their link addresses.

The following additional link types are available in this release:

- [Constant](#constant-link-const)
- [Calc](#calculation-link-calc)
- [dbState](#dbstate-link-state)
- [Debug](#debug-link-debug)
- [Trace](#trace-link-trace)

## Using JSON Links

When setting a record link field to a JSON link address, the link specification
must appear inside a pair of braces ` {} ` expressed as a JSON5 ([JavaScript
Object Notation](https://spec.json5.org/)) object, which allows link parameters
to be defined as needed by the particular link type. When link fields are set in
an IOC database file, the field value may take advantage of the JSON5 syntax to
reduce the number of double-quote characters required.

## Link Type Reference

### Constant Link `"const"`

Constant links are input links that provide literal values at link initalization
time, but do not return any data when their `getValue()` routine is called.
Most record types support the use of constant links on their input links by
calling `recGblInitConstantLink()` at record initialization, which results in
the constant value being loaded into the target field at that time.

Note that for most record types (the `printf` and `calcout` records are the
main exceptions) it is pointless to set an input link to a constant link at
runtime since the link initialization that loads the field value usually only
happens when a record is initialized. A constant link that is embedded inside
another input link type such as a calculation link should be OK though since the
link initialization will take place when the record's field gets set.

#### Parameters

A const link takes a parameter which may be an integer, double or string, or an
array of those types. If an array contains both integers and double values the
integers will be promoted to doubles. Mixing strings and numbers in an array
results in an error.

#### Examples

    {const: 3.14159265358979}
    {const: "Pi"}
    {const: [1, 2.718281828459, 3.14159265358979]}
    {const: ["One", "e", "Pi"]}
    {const:[Inf, -Inf]})

The newer JSON5 syntax supports Infinity values when parsing numbers, so it is
no longer necessary to quote these in a string, although that still works:

    field(INP, {const:"Inf"})

### Calculation Link `"calc"`

A calculation link is an input link that can evaluate mathematical expressions
on scalar (double-precision floating-point) values obtained from up to 12 child
input links, and returns a double-precision floating-point result. The
expression is evaluated by the EPICS Calc engine, and the result is returned as
the value of the link.

Two additional expressions may also be provided and are evaluated to determine
whether the record owning the link should be placed in alarm state. In both
cases the result of the main calculation is available to these expressions as
`VAL` (attempts to assign to `VAL` inside either expression will have no
lasting effect). If the `major` expression evaluates to a non-zero value the
record will be placed in `LINK/MAJOR` alarm. If not and the `minor` expression
evaluates to non-zero the record will be placed in `LINK/MINOR` alarm state.

A calculation link can also be an output link, with the scalar output value
being converted to a double and provided to the expression as `VAL`. Up to 12
additional input links can also be read and provided to the expression as above.
The result of the calculation is forwarded to a child output link specified in
the link's `out` parameter.

For an output link the main expression is actually optional; if not provided the
converted value will be forwarded to the output link unchanged. The two alarm
expressions may still be used to put the output link into alarm state as
described above.

#### Parameters

The link address is a JSON map with the following keys:

- expr

    The primary expression to be evaluated, given as a string.
    This is optional for output links, required for input links.

- major

    An optional expression that returns non-zero to raise a major alarm.

- minor

    An optional expression that returns non-zero to raise a minor alarm.

- args

    A JSON list of up to 12 input arguments for the expression, which are assigned
    to the inputs `A`, `B`, `C`, ... `L`. Each input argument may be either a
    numeric literal or an embedded JSON link inside `{}` braces. The same input
    values are provided to the two alarm expressions as to the primary expression.

- out

    A JSON link inside `{}` braces which specifies the destination of `putValue`
    operations after any expressions have been evaluated.
    This key is required for output links, not used by input links.

- units

    An optional string specifying the engineering units for the result of the
    expression. Equivalent to the `EGU` field of a record.

- prec

    An optional integer specifying the numeric precision with which the calculation
    result should be displayed. Equivalent to the `PREC` field of a record.

- time

    An optional string containing a single upper or lower-case letter `A` ... `L`
    which must correspond to an input provided in the `args` parameter. When the
    record containing such a link has `TSEL` set to -2 (epicsTimeEventDeviceTime)
    the record's timestamp field `TIME` will be read from the indicated input link
    atomically with the value of the input argument.

#### Example

    {calc: {expr:"A*B", args:[{pva:"record"}, 1.5], prec:3}}

### dbState Link `"state"`

A dbState link is one that gets or puts a boolean value from/to a named global
flag as implemented by the dbState facility in `dbstate.h`. The link type can
invert the sense of the dbState flag during the get or put if desired.

The value of the named flag is read or written at the time of the link I/O
operation. When reading a flag, the value returned by the link will be zero or
one converted to the requested data type. When writing to a flag the boolean
value of the data written is determined in the originating data type. All
strings are regarded as true other than `""` and `"0"` which are both false.

A link can be configured to invert the sense of the flag data by putting an
exclamation mark `!` before the first character of the flag's name in the link
address.

These dbState flags can be accessed from the IOC Shell with various dbState
commands, and are also used by the `"sync"` Channel-Access server-side filter
mechanism.

#### Parameters

The link takes a single parameter which must be a string, providing the name of
the dbState object, with an optional leading `!` character to indicate that the
flag's value should be inverted. The dbState object will be created when the
link is initialized if it doesn't already exist.

#### Examples

    {state:"redBeam"}
    {state:"!simEnable"}

### Debug Link `"debug"`

The debug link type exists to enable debugging of other link types; it provides
no functionality itself other than to turn on the debug flag for the child link
that is its only parameter and pass all link operations down to that link.

#### Example

    {debug:{state:"redBeam"}}

### Trace Link `"trace"`

The trace link type is a relative of the debug link type that also traces the
operation of its child link. At creation it turns on the debug flag of its child
link, then it prints the method arguments and return values of all link
operations before / after passing control down to the child link.

#### Example

    {trace:{state:"redBeam"}}
