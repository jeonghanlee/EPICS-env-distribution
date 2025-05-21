# Field Modifiers and Channel Filters

## Contents

- [Introduction
    ](#introduction)
- [Using Field Modifiers and Channel Filters
    ](#using-field-modifiers-and-channel-filters)
- [Example Filters
    ](#example-filters)
- [Field Modifier Reference
    ](#field-modifier-reference)
    - [Long String Modifier `$`
        ](#long-string-field-modifier)
    - [Subarray Modifier `[…]`
        ](#subarray-field-modifier-start-increment-end)
- [JSON5 Channel Filters
    ](#json5-channel-filters)
    - [TimeStamp Filter `{ts:{}}`
        ](#timestamp-filter-ts)
    - [Deadband Filter `{dbnd:{…}}`
        ](#deadband-filter-dbnd)
    - [Array Filter `{arr:{…}}`
        ](#array-filter-arr)
    - [Synchronize Filter `{sync:{…}}`
        ](#synchronize-filter-sync)
    - [Decimation Filter `{dec:{…}}`
        ](#decimation-filter-dec)
    - [User Tag Filter `{utag:{…}}`
        ](#user-tag-filter-utag)

## Introduction

A Field Modifier is a string that is appended to the field name part of a
Channel Access or PV Access channel name of an IOC-based server.
The IOC currently recognizes 3 different kinds of field modifier, which are
described below.

A Channel Filter is an IOC plugin that can be attached to an IOC process
variable channel using a field modifier, and can alter the data updates that are
served to the client that requested the filtering.
Clients that use a channel filter have no effect on other clients connected to
the same PV.
Filters can only modify or drop monitor events that the IOC posts; introducing
extra monitor events (in between the events posted by the IOC itself) is not
currently possible.

Most Channel Filters are configured by a field modifier that uses JSON5
syntax to select the type of filter and provide any parameters it accepts.

## Using Field Modifiers and Channel Filters

Modifiers can be added to any Channel Access or PV Access channel name.
There can be more than one modifier or filter applied to a channel.
Modifiers must appear immediately after the field name if one is included in the
channel name.
If no field is named because the default (VAL) field is the target, the
modifiers must come immediately after a dot `.` appended to the record name.

The order that modifiers and filters are specified controls the order in which
they are applied to the resulting data-stream.
If used, the Long String and Subarray field modifiers must appear first and in
that order, followed by any channel filters inside a pair of braces ` {} ` that
form a JSON5 ([JavaScript Object Notation](https://spec.json5.org/)) map, which
allows filters and their parameters to be specified as needed.

Each JSON5 filter is specified as a name:value pair.
The filter name is a map key that may be an unquoted identifier name (which all
of the filter names given below are), or a string enclosed inside either single-
or double-quote characters `'` or `"` as per the JSON5 specification.
Parameters to the filter are provided in the value part of the key:value pair
after the colon `:` character, and will normally be an embedded JSON5 map
containing zero or more key/value pairs inside a nested pair of braces ` {} `.

Unless included inside a quoted string, white space characters are ignored and
skipped over by the JSON5 parser between other token characters.
This includes horizontal and vertical tabs, line feed/form feed/carriage return,
space and the non-breaking space character ` \xA0 `.
Within a quoted string, line breaks may escaped with a backslash `\` to be
omitted from the parsed string.

An IOC Channel Access link can include filters in its channel name, but it is
important to not include any spaces at all in the filter specification.
If a filter name or parameter must contain a space it will be necessary to
express that space character as an escaped character `\x20` or `\u0020` inside
a quoted string, otherwise the space will mark the end of the channel name to
the link parsing code inside the IOC.

#### Example Filters

Given a record called `test:channel` the following would all apply a channel
filter `f` to the VAL field of that record, giving the filter two numeric
parameters named `lo` and `hi`:

    test:channel.{f:{lo:0,hi:10}}
    test:channel.{"f":{"lo":0, "hi":10}}
    test:channel.{'f': {'lo':0, 'hi':10} }

When typing a filtered channel name as an argument to a Unix shell command, if
quote characters are used for keys or values in JSON strings within the channel
name string it may be necessary to enclose the name within quotes `'` or `"`
or to use back-slash escapes before them.
Quotes may not be required when the Long String modifier `$` is used at the end
of a field name with nothing following it, but will be necessary for a square
bracketted Subarray filter or if a dollar sign is followed by something else.

    Hal$ caget test:channel.{f:{lo:0,hi:10}}
    ...
    Hal$ caget 'test:channel.{"f":{"lo":0, "hi":10}}'
    ...
    Hal$ caget -S calc:record.CALC$
    ...
    Hal$ caget -S 'test:channel.NAME$[0:4]'
    test:channel.NAME$[0:4] test

## Field Modifier Reference

The two built-in field modifiers use a simplified syntax following the record
field name.

### Long String Field Modifier `$`

Appending a dollar sign `$` to the name of a `DBF_STRING` field causes the IOC
to change the representation of that field into an array of characters, which
allows strings longer than 40 character to be transported through Channel
Access.
Long strings are particularly useful for the CALC fields of a calculation or
calcout record, which can hold up to 80 characters, or the VAL fields of an lsi
(Long String Input) or lso (Long String Output) record which can be any length
as chosen by the database designer.

    Hal$ cainfo test:channel.NAME
    test:channel.NAME
        State:            connected
        Host:             10.234.56.78:5064
        Access:           read, no write
        Native data type: DBF_STRING
        Request type:     DBR_STRING
        Element count:    1
    Hal$ cainfo test:channel.NAME$
    test:channel.NAME$
        State:            connected
        Host:             10.234.56.78:5064
        Access:           read, no write
        Native data type: DBF_CHAR
        Request type:     DBR_CHAR
        Element count:    61

A CA client accessing a channel that uses the Long String field modifier will
have to be specifically configured to treat the data as a string instead of the
array of `DBF_CHAR` that it looks like.
CA clients should not attempt to parse the channel name themselves to recognize
this field modifier in the name.
All long string values returned by the IOC should include a trailing zero byte
in their data as is standard for strings in the C language.
For the catools programs provided with Base, the flag `-S` indicates that a
channel containing a character array should be treated as a long string.

    Hal$ caget test:channel.NAME
    test:channel.NAME              test:channel
    Hal$ caget test:channel.NAME$
    test:channel.NAME$ 61 116 101 115 116 58 99 104 97 110 110 101 108 0 0 ...
    Hal$ caget -S test:channel.NAME$
    test:channel.NAME$ test:channel

### Subarray Field Modifier `[start:increment:end]`

This square-bracket field modifier syntax gets translated within the IOC into
calls to the [Array Filter](#array-filter-arr), see that section below for
details of this shorthand.

The subarray field modifier syntax can immediately follow a Long String field
modifier, which permits fetching various kinds of substrings from the field.
This syntax cannot appear after a JSON filter specification though, the JSON
"arr" filter syntax must be used to apply an array filter after any other JSON
filter type.

    Hal$ caget -S 'test:channel.NAME$[0:4]'
    test:channel.NAME$[0:4] test
    Hal$ caget -S 'test:channel.NAME$[5:-1]'
    test:channel.NAME$[5:-1] channel

## JSON5 Channel Filters

### TimeStamp Filter `"ts"`

This filter is used for two purposes:

- to retrieve the timestamp of the record as a value in several different
        formats;
- to retrieve the record value as normal, but replace the timestamp with
        the time the value was fetched.

#### Parameters

#### No parameters (an empty pair of braces)

Retrieve the record value as normal, but replace the timestamp with the time the
value was fetched (or an update was sent). This is useful for clients that can't
handle timestamps that are far in the past. Normally, the record's timestamp
indicates when the record last processed, which could have been days or even
weeks ago for some records, or set to the EPICS epoch if the record has never
processed.

#### Numeric type `"num"`

The following values are accepted for this parameter:

- `"dbl"` requests the timestamp as `epicsFloat64` representing the
        non-integral number of seconds since epoch. This format is convenient,
        but loses precision, depending on which epoch is used.
- `"sec"` requests the number of seconds since epoch as `epicsUInt32`.
- `"nsec"` requests the number of nanoseconds since epoch as
        `epicsUInt32`.
- `"ts"` requests the entire timestamp. It is provided as a two-element
        array of `epicsUInt32` representing seconds and nanoseconds.

Note that `epicsUInt32` cannot be transferred over Channel Access; in that
case, the value will be converted to `epicsFloat64`.

#### String type `"str"`

The following values are accepted for this parameter:

- `"epics"` requests the timestamp as a string in the format used by
        tools such as `caget`.
- `"iso"` requests the timestamp as a string in the ISO8601 format.

#### Epoch adjustment `"epoch"`

The following values are accepted for this parameter:

- `"epics"` keeps the EPICS epoch (1990-01-01) and is the default if the
        `"epoch"` parameter is not specified.
- `"unix"` converts the timestamp to the UNIX/POSIX epoch (1970-01-01).

#### Examples

    Hal$ caget -a 'test:invalid_ts.{"ts":{}}'
    test:invalid_ts.{"ts":{}}      2012-08-28 22:10:31.192547 0 UDF INVALID
    Hal$ caget -a 'test:invalid_ts'
    test:invalid_ts                <undefined> 0 UDF INVALID
    Hal$ caget -a test:channel
    test:channel                   2021-03-11 18:23:48.265386 42
    Hal$ caget 'test:channel.{"ts": {"str": "epics"}}'
    test:channel.{"ts": {"str": "epics"}} 2021-03-11 18:23:48.265386
    Hal$ caget 'test:channel.{"ts": {"str": "iso"}}'
    test:channel.{"ts": {"str": "iso"}} 2021-03-11T18:23:48.265386+0100
    Hal$ caget -f9 'test:channel.{"ts": {"num": "dbl"}}'
    test:channel.{"ts": {"num": "dbl"}} 984331428.265386105
    Hal$ caget -f1 'test:channel.{"ts": {"num": "ts"}}'
    test:channel.{"ts": {"num": "ts"}} 2 984331428.0 265386163.0
    Hal$ caget -f1 'test:channel.{"ts": {"num": "ts", "epoch": "unix"}}'
    test:channel.{"ts": {"num": "ts", "epoch": "unix"}} 2 1615483428.0 265386163.0

### Deadband Filter `"dbnd"`

This filter implements a channel-specific monitor deadband, which is applied
after any deadbands implemented by the record itself (it can only drop updates
that the unfiltered channel generates, never add additional updates).

The deadband can be specified as an absolute value change, or as a relative
percentage.

#### Parameters

- Mode+Deadband `"abs"`/`"rel"` (shorthand)

    Mode and deadband can be specified in one definition (shorthand).
    The desired mode is given as parameter name (`"abs"` or `"rel"`), with the
    numeric size of the deadband (absolute value or numeric percentage) as value.

- Deadband `"d"`

    The size of the deadband to use.
    Relative deadband values are given as a numeric percentage, but without any
    trailing percent character.

- Mode `"m"` (optional)

    A string (enclosed in double-quotes `"`), which should contain either
    `abs` or `rel`.
    The default mode is `abs` if no mode parameter is included.

#### Example

    Hal$ camonitor 'test:channel'
    test:channel                    2012-09-01 22:10:19.600595 1 LOLO MAJOR
    test:channel                    2012-09-01 22:10:20.600661 2 LOLO MAJOR
    test:channel                    2012-09-01 22:10:21.600819 3 LOW MINOR
    test:channel                    2012-09-01 22:10:22.600905 4 LOW MINOR
    test:channel                    2012-09-01 22:10:23.601023 5  
    test:channel                    2012-09-01 22:10:24.601136 6 HIGH MINOR
    ^C
    Hal$ camonitor 'test:channel.{"dbnd":{"d":1.5}}'
    test:channel.{"dbnd":{"d":1.5}} 2012-09-01 22:11:49.613341 1 LOLO MAJOR
    test:channel.{"dbnd":{"d":1.5}} 2012-09-01 22:11:51.613615 3 LOW MINOR
    test:channel.{"dbnd":{"d":1.5}} 2012-09-01 22:11:53.613804 5  
    test:channel.{"dbnd":{"d":1.5}} 2012-09-01 22:11:55.614074 7 HIGH MINOR
    test:channel.{"dbnd":{"d":1.5}} 2012-09-01 22:11:57.614305 9 HIHI MAJOR
    ^C

### Array Filter `"arr"`

This filter is used to retrieve parts of an array (subarrays and strided
subarrays).

#### Parameters

- Square bracket notation `[start:increment:end]` (shorthand)

    This much shorter square bracket notation can be used in place of JSON.
    Any parameter may be omitted (keeping the colons) to use the default value.
    If only one colon is included, it means `[start:end]` with an increment of 1.
    If only a single parameter is given `[index]` the filter returns one element.

    Index numbers for the start and end parameters must be integers, with the first
    array element being found at index `0`.
    The value of an index may be negative, in which case the indexing is counted
    backwards from the end of the array, with `-1` being the last element.
    If the start index selects an element that comes after the end index element,
    the subarray returned will always be empty.

- Start index `"s"`

    Index of the first original array element to retrieve.

- Increment `"i"`

    The stride or increment to apply between elements of the original array to be
    retrieved. This value must be a positive integer.

- End index `"e"`

    Index of the last original array element to retrieve.

Defaults (when parameters are omitted) are:
`s=0` (first element), `i=1` (fetch all elements), `e=-1`
(last element)

#### Example

    Hal$ caget test:channel 'test:channel.{"arr":{s:2,i:2,e:8}}' test:channel.[3:5] test:channel.[3:2:-3]
    test:channel 10 0 1 2 3 4 5 6 7 8 9
    test:channel.{"arr":{s:2,i:2,e:8}} 4 2 4 6 8
    test:channel.[3:5] 3 3 4 5
    test:channel.[3:2:-3] 3 3 5 7

### Synchronize Filter `"sync"`

This filter is used to dynamically enable or disable monitors according
to a condition and a state variable declared by the IOC.

State variables have a boolean value and can be set by a binary output
record, an iocsh command or by other software running in the IOC calling
`dbStateSet()`.

#### Parameters

- Mode+State

    Mode and state can be specified in one definition (shorthand).
    The desired mode is given as the parameter name (`"before"` / `"first"` /
    `"while"` / `"last"` / `"after"` / `"unless"` which may be unquoted), with
    the state name (enclosed in single or double quotes `"` or `'`) as the value.

- Mode `"m"`

    A single word from the list below, enclosed in single or double quotes `'` or
    `"`.
    This controls how the state value should affect the monitor stream. 

    - `"before"` — only the last value received before the state
    changes from false to true is forwarded to the client.
    - `"first"` — only the first value received after the state
    changes from true to false is forwarded to the client.
    - `"while"` — values are forwarded to the client as long as
    the state is true.
    - `"last"` — only the last value received before the state
    changes from true to false is forwarded to the client.
    - `"after"` — only the first value received after the state
    changes from true to false is forwarded to the client.
    - `"unless"` — values are forwarded to the client as long
    as the state is false.

- State `"s"`

    The name of a state variable, enclosed in single or double quotes `"` or `'`.

#### Example

Assuming there is a system state called "blue", that is being controlled by
some other facility such as a timing system, updates could be restricted to
periods only when "blue" is true by using

    Hal$ camonitor 'test:channel' 'test:channel.{sync:{while:"blue"}}'
    ...

### Decimation Filter `"dec"`

This filter is used to reduce the number or rate of monitor updates from a
channel by an integer factor `n` that is provided as a filter argument,
discarding the other updates. A true decimation following the original meaning
of the word would be achieved by giving `n` as 10, to only allow every tenth
update through.

#### Parameters

- Number `"n"`

    The decimation factor, a positive integer. Giving n=1 is equivalent to a no-op
    that allows all updates to be passed to the client.

This filter is intentionally very simplistic. It passes on the first monitor
event that it sees after the channel connects, then discards the next N-1 events
before sending the next event. If several clients connect to a channel using the
same filter settings they may see completely different data streams since each
client gets its own instance of the filter whose event counter starts when that
client connects.

#### Example

To sample a 60Hz channel at 1Hz, a 10Hz channel every 6 seconds or a 1Hz channel
once every minute:

    Hal$ camonitor 'test:channel' 'test:channel.{dec:{n:60}}'
    ...

### User Tag Filter `"utag"`

This filter applies a test ` (UTAG & M) == V ` to the value of the record's
UTAG field at the time each monitor event is posted, and drops all updates for
which this expression is false.

#### Parameters

- Mask `"M"`

    An integer to be used as a bit mask.

- Value `"V"`

    The integer value to be matched after applying the mask to the UTAG value.

#### Example

To read a channel only when the UTAG value is even (bit 0 is 0):

    Hal$ camonitor 'test:channel' 'test:channel.{utag:{m:1, v:0}}'
    ...
