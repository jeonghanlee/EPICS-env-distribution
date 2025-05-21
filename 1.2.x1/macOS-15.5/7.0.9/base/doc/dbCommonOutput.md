# Fields Common to Output Record Types

This section describes fields that are found in many output record types.
These fields usually have the same meaning whenever they are used.

See also [Fields Common to All Record Types](dbCommonRecord.md) and [Fields Common to
Input Records](dbCommonInput.md).

### Output and Value Fields

The **OUT** field specifies an output link. It is used by the device support
routines to decide where to send output. For soft records, it can be a
constant, a database link, or a channel access link. If the link is a
constant, the result is no output.

The **DTYP** field specifies the name of the device support module that will
input values. Each record type has its own set of device support routines. If
a record type does not have any associated device support, DTYP is
meaningless.

The **VAL** field contains the desired value before any conversions to raw
output have been performed.

The **OVAL** field is used to decide when to invoke monitors. Archive and value
change monitors are invoked if OVAL is not equal to VAL. If a record type
needs to make adjustments, OVAL is used to enforce the maximum rate of change
limit before converting the desired value to a raw value.

The **RVAL** field contains - whenever possible -  the actual value sent to the
hardware itself or to the associated device driver.

The **RBV** field contains - whenever possible - the actual read back value
obtained from the hardware itself or from the associated device driver.

### Device Support for Soft Records

Normally two soft output device support modules are provided, Soft Channel and
and Raw Soft Channel. Both write a value through the output link OUT.
The Soft Channel module writes output from the value associated with OVAL or
VAL (if OVAL does not exist). The Raw Soft Channel support module writes the
value associated with the RVAL field after conversion has been performed.

The device support write routine normally calls `dbPutLink()` which writes a
value through the OUT link, and returns the status from that call.

### Input and Mode Select Fields

The **DOL** field is a link from which the desired output value can be fetched.
DOL can be a constant, a database link, or a channel access link. If DOL is a
database or channel access link and OMSL is closed\_loop, then VAL is obtained
from DOL.

The **OMSL** field selects the output mode. This field has either the value
`supervisory` or `closed_loop`. DOL is used to fetch VAL only if OMSL has the
value `closed_loop`. By setting this field a record can be switched between
supervisory and closed loop mode of operation. While in closed loop mode, the
VAL field cannot be set via dbPuts.

### Output Mode Selection

The fields DOL and OMSL are used to allow the output record to be part of a
closed loop control algorithm. OMSL is meaningful only if DOL refers to a
database or channel access link. It can have the values `supervisory` or
`closed_loop`. If the mode is `supervisory`, then nothing is done to VAL. If
the mode is `closed_loop` and the record type does not contain an OIF field,
then each time the record is processed, VAL is set equal to the value obtained
from the location referenced by DOL. If the mode is `closed_loop` in record
types with an OIF field and OIF is Full, VAL is set equal to the value obtained
from the location referenced by DOL; if OIF is Incremental VAL is incremented by
the value obtained from DOL.

### Invalid Output Action Fields

The **IVOA** field specifies the output action for the case that the record is
put into an INVALID alarm severity. IVOA can be one of the following actions:

- `Continue normally`
- `Don't drive outputs`
- `Set output to IVOV`

The **IVOV** field contains the value for the IVOA action `Set output to IVOV`
in engineering units. If a new severity has been set to INVALID  and IVOA is
`Set output to IVOV`, then VAL is set to IVOV and converted to RVAL before
device support is called.

### Invalid Alarm Output Action

Whenever an output record is put into INVALID alarm severity, IVOA specifies
an action to take. The record support process routine for each output record
contains code which performs the following steps.

- If new severity is less than INVALID, then call `writeValue()`:
- Else do the following:
    - If IVOA is `Continue normally` then call `writeValue()`.
    - If IVOA is `Don't drive outputs` then do not write output.
    - If IVOA is `Set output to IVOV` then set VAL to IVOV, call `convert()` if
    necessary, and then call `writeValue()`.
    - If IVOA not one of the above, an error message is generated.

### Output Simulation Fields

The **SIMM** field controls simulation mode. It has either the value YES or NO.
By setting this field to YES, the record can be switched into simulation mode
of operation. While in simulation mode, output will be forwarded through SIOL
instead of OUT.

The **SIML** field specifies the simulation mode location. This field can be a
constant, a database link, or a channel access link. If SIML is a database or
channel access link, then SIMM is read from SIML. If SIML is a constant link
then SIMM is initialized with the constant value, but can be changed via
database or channel access puts.

The **SIOL** field is a link that the output value is written to when the record
is in simulation mode.

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

### Simulation Mode for Output Records

An output record can be switched into simulation mode of operation by setting
the value of SIMM to YES. During simulation, the record will be put into alarm
with a severity of SIMS and a status of SIMM\_ALARM. While in simulation mode,
output values, in engineering units, will be written to SIOL instead of OUT.
However, the output values are never converted. Also, while the record is in
simulation mode, there will be no calls to device support during record
processing.

Normally output records contain a private `writeValue()` routine which performs
the following steps:

- If PACT is TRUE, the device support write routine is called, status is set to
its return code, and readValue returns.
- Call `dbGetLink()` to get a new value for SIMM if SIML is a DB\_LINK or a
CA\_LINK.
- Check value of SIMM.
- If SIMM is NO, then call the device support write routine, set status to its
return code, and return.
- If SIMM is YES, then
    - Set alarm status to SIMM\_ALARM and severity to SIMS,
    if SIMS is greater than zero.
    - If the record simulation processing is synchronous (SDLY < 0) or the record is
    in the second phase of an asynchronous processing, call `dbPutLink()`
    to write the output value from VAL or OVAL to SIOL.

        Otherwise (record is in first phase of an asynchronous processing), set up a
        callback processing with the delay specified in SDLY.

    - Set status to the return code from `dbPutLink()` and return.
- If SIMM is not YES or NO, a SOFT alarm with a severity of INVALID is
raised, and return status is set to -1.
