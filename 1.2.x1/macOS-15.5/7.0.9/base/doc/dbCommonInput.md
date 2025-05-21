# Fields Common to Input Record Types

This section describes fields that are found in many input record types.
These fields usually have the same meaning whenever they are used.

See also [Fields Common to All Record Types](dbCommonRecord.md) and [Fields Common
to Output Record Types](dbCommonOutput.md).

### Input and Value Fields

The **INP** field specifies an input link. It is used by the device support
routines to obtain input. For soft analog records it can be a constant, a
database link, or a channel access link.

The **DTYP** field specifies the name of the device support module that will
input values. Each record type has its own set of device support routines. If
a record type does not have any associated device support, DTYP is
meaningless.

The **RVAL** field contains - whenever possible - the raw data value exactly as
it is obtained from the hardware or from the associated device driver and
before it undergoes any conversions. The Soft Channel device support module
reads values directly into VAL, bypassing this field.

The **VAL** field contains the record's final value, after any needed
conversions have been performed.

### Device Input

A device input routine normally returns one of the following values to its
associated record support routine:

- 0: Success and convert. The input value is in RVAL. The record support module
will compute VAL from RVAL.
- 2: Success, but don't convert. The device support module can specify this
value if it does not want any conversions. It might do this for two reasons:
    - A hardware error is detected (in this case, it should also raise an alarm
    condition).
    - The device support routine reads values directly into the VAL field and then
    sets UDF to FALSE. For some record types the device support routine may have to
    do other record-specific processing as well such as applying a smoothing filter
    to the engineering units value.

### Device Support for Soft Records

In most cases, two soft output device support modules are provided: Soft Channel
and Raw Soft Channel. Both allow INP to be a constant, a database link, or a
channel access link. The Soft Channel device support module reads input directly
into the VAL field and specifies that no value conversion should be performed.
This allows the record to store values in the data type of its VAL field. Note
that for Soft Channel input, the RVAL field is not used. The Raw Soft Channel
support module reads input into RVAL and indicates that any specified unit
conversions be performed.

The device support read routine normally calls `dbGetLink()` which
fetches a value from the link.

If a value was returned by the link the UDF field is set to FALSE. The device
support read routine normally returns the status from `dbGetLink()`.

### Input Simulation Fields

The **SIMM** field controls simulation mode.
By setting this field to YES or RAW, the record can be switched into
simulation mode of operation.
While in simulation mode, input will be obtained from SIOL instead of INP.

The **SIML** field specifies the simulation mode location. This field can be a
constant, a database link, or a channel access link. If SIML is a database or
channel access link, then SIMM is read from SIML. If SIML is a constant link
then SIMM is initialized with the constant value, but can be changed via
database or channel access puts.

The **SVAL** field contains the simulation value. This is the record's input
value, in engineering units, when the record is switched into simulation mode,
i.e., SIMM is set to YES or RAW. If the record type supports conversion,
setting SIMM to RAW causes SVAL to be written to RVAL and the conversion to
be done.

The **SIOL** field is a link that can be used to fetch the simulation value. The
link can be a constant, a database link, or a channel access link. If SIOL is a
database or channel access link, then SVAL is read from SIOL. If SIOL is a
constant link then SVAL is initialized with the constant value but can be
changed via database or channel access puts.

The **SIMS** field specifies the simulation mode alarm severity. When this
field is set to a value other than NO\_ALARM and the record is in simulation
mode, it will be put into alarm with this severity and a status of SIMM\_ALARM.

The **SDLY** field specifies a delay (in seconds) to implement asynchronous
processing in simulation mode. A positive SDLY value will be used as delay
between the first and second phase of processing in simulation mode.
A negative value (default) specifies synchronous processing.

The **SSCN** field specifies the SCAN mechanism to be used in simulation mode.
This is specifically useful for 'I/O Intr' scanned records, which would
otherwise never be scanned in simulation mode.

### Simulation Mode for Input Records

An input record can be switched into simulation mode of operation by setting
the value of SIMM to YES or RAW.
During simulation, the record will be put into alarm with a severity of SIMS
and a status of SIMM\_ALARM.

              --  (SIMM = NO?)
            /         (if supported and directed by device support,
           /              INP -> RVAL -- convert -> VAL),
                      (else INP -> VAL)
    SIML -> SIMM

            \
              --  (SIMM = YES?) SIOL -> SVAL -> VAL
              \
                -- (SIMM = RAW?) SIOL -> SVAL -> RVAL -- convert -> VAL

If SIMM is set to YES, the input value, in engineering units, will be obtained
from SIOL instead of INP and directly written to the VAL field.
If SIMM is set to RAW, the value read through SIOL will be truncated and
written to the RVAL field, followed by the regular raw value conversion.
While the record is in simulation mode, there will be no calls to device
support when the record is processed.

If SIOL contains a link, a TSE setting of "time from device" (-2) is honored
in simulation mode by taking the time stamp from the record that SIOL points
to.

Normally input records contain a private `readValue()` routine which performs
the following steps:

- If PACT is TRUE, the device support read routine is called, status is set to
its return code, and readValue returns.
- Call `dbGetLink()` to get a new value for SIMM from SIML.
- Check value of SIMM.
- If SIMM is NO, then call the device support read routine, set status to its
return code, and return.
- If SIMM is YES or RAW, then
    - Set alarm status to SIMM\_ALARM and severity to SIMS,
    if SIMS is greater than zero.
    - If the record simulation processing is synchronous (SDLY < 0) or the record is
    in the second phase of an asynchronous processing, call `dbGetLink()`
    to read the input value from SIOL into SVAL.
    Set status to the return code from `dbGetLink()`.
    If the call succeeded and SIMM is YES, write the value to VAL and set the
    status to 2 (don't convert),
    if SIMM is RAW and the record type supports conversion, cast the value to RVAL
    and leave the status as 0 (convert).

        Otherwise (record is in first phase of an asynchronous processing), set up a
        callback processing with the delay specified in SDLY.
- If SIMM is not YES, NO or RAW, a SOFT alarm with a severity of INVALID is
raised, and return status is set to -1.
