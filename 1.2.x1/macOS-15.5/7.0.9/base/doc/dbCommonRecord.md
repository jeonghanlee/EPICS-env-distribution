# Fields Common to All Record Types

This section contains a description of the fields that are common to all record
types. These fields are defined in dbCommon.dbd.

See also [Fields Common to Input Record Types](dbCommonInput.md) and [Fields
Common to Output Record Types](dbCommonOutput.md).

### Operator Display Parameters

The **NAME** field contains the record name which must be unique within an
EPICS Channel Access name space. The name is supplied by the application
developer and is the means of identifying a specific record. The name has a
maximum length of 60 characters and should use only this limited set of
characters:

    a-z A-Z 0-9 _ - : [ ] < > ;

The **DESC** field may be set to provide a meaningful description of the
record's purpose. Maximum length is 40 characters.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Scan Fields

These fields contain information related to how and when a record processes. A
few records have unique fields that also affect how they process. These
fields, if any, will be listed and explained in the section for each record.

The **SCAN** field specifies the scanning period for periodic record scans or the
scan type for non-periodic record scans.  The default set of values for SCAN can
be found in [menuScan.dbd](menuScan.md).

The choices provided by this menu are:

- `Passive` for the record scan to be triggered by other records or Channel
Access
- `Event` for event-driven scan
- `I/O Intr` for interrupt-driven scan
- A set of periodic scan intervals

Additional periodic scan rates may be defined for individual IOCs by making a
local copy of menuScan.dbd and adding more choices as required. Periodic scan
rates should normally be defined in order following the other scan types, with
the longest periods appearing first. Scan periods can be specified with a unit
string of `second`/`seconds`, `minute`/`minutes`, `hour`/`hours` or
`Hertz`/`Hz`. Seconds are used if no unit is included in the choice string.
For example these rates are all valid:

    1 hour
    0.5 hours
    15 minutes
    3 seconds
    1 second
    2 Hertz

The **PINI** field specifies record processing at initialization. It can have the
values NO, YES, RUN, RUNNING, PAUSE, and PAUSED. If it is set to YES during
database configuration, the record is processed once at IOC initialization
(before the normal scan tasks are started). For the other values see
[menuPini.dbd](menuPini.md) for more details.

The **PHAS** field orders the records processed within a specific SCAN group or
PINI processing phase. All records of a specified phase are processed before
those with higher phase number. It is generally better practice to use linked
passive records to enforce the order of processing rather than a phase number.
If the PINI field is set to NO, the PHAS field is not meaningful for passive
records.

The **EVNT** field specifies an event name or number. This event identifier is
used if the SCAN field is set to `Event`. All records with scan type `Event`
and the same EVNT value will be processed when that event is signalled by other
software running in the IOC, either by calling `post_event(int event)` for
numeric events, or by calling `postEvent()` with an event handle previously
looked up using `eventNameToHandle()` for named events.

The **PRIO** field specifies the scheduling priority for processing records
with SCAN=`I/O Event` and asynchronous record completion tasks.

The **DISV** field specifies a "disable value". Record processing cannot
begin when the value of this field is equal to the value of the DISA
field, meaning the record is disabled. Note that field values of a record
can be changed by database or Channel Access puts, even if the record is
disabled.

The **DISA** field contains the value that is compared with DISV to determine if
the record is disabled. A value is obtained for the DISA field from the **SDIS**
link field before the IOC tries to process the record. If SDIS is not set, DISA
may be set by some other method to enable and disable the record.

The **DISS** field defines the record's "disable severity". If this field is
not NO\_ALARM and the record is disabled, the record will be put into alarm
with this severity and a status of DISABLE\_ALARM.

If the **PROC** field of a record is written to, the record is processed.

The **LSET** field contains the lock set to which this record belongs. All
records linked in any way via input, output, or forward database links belong
to the same lock set. Lock sets are determined at IOC initialization time, and
are updated whenever a database link is added, removed or altered.

The **LCNT** field counts the number of times dbProcess finds the record active
during successive scans, i.e. PACT is TRUE. If dbProcess finds the record
active MAX\_LOCK times (currently set to 10) it raises a SCAN\_ALARM.

The **PACT** field is TRUE while the record is active (being processed). For
asynchronous records PACT can be TRUE from the time record processing is
started until the asynchronous completion occurs. As long as PACT is TRUE,
dbProcess will not call the record processing routine. See Application
Developers Guide for details on usage of PACT.

The **FLNK** field is a link pointing to another record (the "target" record).
Processing a record with the FLNK field set will trigger processing of the
target record towards the end of processing the first record (but before PACT is
cleared), provided the target record's SCAN field is set to `Passive`. If the
FLNK field is a Channel Access link it must point to the PROC field of the
target record.

The **SPVT** field is for internal use by the scanning system.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| SCAN | Scan Mechanism | MENU [menuScan](menuScan.md) | Yes |   | Yes | Yes | No |
| PINI | Process at iocInit | MENU [menuPini](menuPini.md) | Yes |   | Yes | Yes | No |
| PHAS | Scan Phase | SHORT | Yes |   | Yes | Yes | No |
| EVNT | Event Name | STRING \[40\] | Yes |   | Yes | Yes | No |
| PRIO | Scheduling Priority | MENU [menuPriority](menuPriority.md) | Yes |   | Yes | Yes | No |
| DISV | Disable Value | SHORT | Yes | 1 | Yes | Yes | No |
| DISA | Disable | SHORT | No |   | Yes | Yes | No |
| SDIS | Scanning Disable | INLINK | Yes |   | Yes | Yes | No |
| PROC | Force Processing | UCHAR | No |   | Yes | Yes | Yes |
| DISS | Disable Alarm Sevrty | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | No |
| LCNT | Lock Count | UCHAR | No |   | Yes | No | No |
| PACT | Record active | UCHAR | No |   | Yes | No | No |
| FLNK | Forward Process Link | FWDLINK | Yes |   | Yes | Yes | No |
| SPVT | Scan Private | NOACCESS | No |   | No | No | No |

### Alarm Fields

Alarm fields indicate the status and severity of record alarms, or determine
how and when alarms are triggered. Of course, many records have alarm-related
fields not common to all records. Those fields are listed and explained in the
appropriate section on each record.

The **STAT** field contains the current alarm status.

The **SEVR** field contains the current alarm severity.

The **AMSG** string field may contain more detailed information about the alarm.

The STAT, SEVR and AMSG fields hold alarm information as seen outside of the
database. The **NSTA**, **NSEV** and **NAMSG** fields are used during record
processing by the database access, record support, and device support routines
to set new alarm status and severity values and message text. Whenever any
software component discovers an alarm condition, it calls one of these routines
to register the alarm:

    recGblSetSevr(precord, new_status, new_severity);
    recGblSetSevrMsg(precord, new_status, new_severity, "Message", ...);

These check the current alarm severity and update the NSTA, NSEV and NAMSG
fields if appropriate so they always relate to the highest severity alarm seen
so far during record processing. The file alarm.h defines the allowed alarm
status and severity values. Towards the end of record processing these fields
are copied into the STAT, SEVR and AMSG fields and alarm monitors triggered.

The **ACKS** field contains the highest unacknowledged alarm severity.

The **ACKT** field specifies whether it is necessary to acknowledge transient
alarms.

The **UDF** indicates if the record's value is **U**n**D**e**F**ined. Typically this
is caused by a failure in device support, the fact that the record has never
been processed, or that the VAL field currently contains a NaN (not a number) or
Inf (Infinite) value. UDF defaults to TRUE but can be set in a database file.
Record and device support routines which write to the VAL field are generally
responsible for setting and clearing UDF.

The **UDFS** field specifies the alarm severity that the record will be set to
whenever its value is undefined (i.e., the UDF field is 1). This includes the
initial severity of the record being undefined after the IOC boots.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| STAT | Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No | UDF | Yes | No | No |
| SEVR | Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| AMSG | Alarm Message | STRING \[40\] | No |   | Yes | No | No |
| NSTA | New Alarm Status | MENU [menuAlarmStat](menuAlarmStat.md) | No |   | Yes | No | No |
| NSEV | New Alarm Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| NAMSG | New Alarm Message | STRING \[40\] | No |   | Yes | No | No |
| ACKS | Alarm Ack Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | No |   | Yes | No | No |
| ACKT | Alarm Ack Transient | MENU [menuYesNo](menuYesNo.md) | Yes | YES | Yes | No | No |
| UDF | Undefined | UCHAR | Yes | 1 | Yes | Yes | Yes |
| UDFS | Undefined Alarm Sevrty | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes | INVALID | Yes | Yes | No |

### Device Fields

The **RSET** field contains the address of the Record Support Entry Table. See
the Application Developers Guide for details on usage.

The **DSET** field contains the address of Device Support Entry Table. The
value of this field is determined at IOC initialization time. Record support
routines use this field to locate their device support routines.

The **DPVT** field is is for private use of the device support modules.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| RSET | Address of RSET | NOACCESS | No |   | No | No | No |
| DSET | DSET address | NOACCESS | No |   | No | No | No |
| DPVT | Device Private | NOACCESS | No |   | No | No | No |

### Debugging Fields

The **TPRO** field can be used to trace record processing. When this field is
non-zero and the record is processed, a trace message will be be printed for
this record and any other record in the same lock-set that is triggered by a
database link from this record. The trace message includes the name of the
thread doing the processing, and the name of the record being processed.

The **BKPT** field indicates if there is a breakpoint set at this record. This
supports setting a debug breakpoint in the record processing. STEP through
database processing can be supported using this.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| TPRO | Trace Processing | UCHAR | No |   | Yes | Yes | No |
| BKPT | Break Point | NOACCESS | No |   | No | No | No |

### Miscellaneous Fields

The **ASG** string field sets the name of the access security group used for this
record. If left empty, the record is placed in group `DEFAULT`.

The **ASP** field is private for use by the access security system.

The **DISP** field can be set to a non-zero value to reject puts from outside of
the IOC (i.e. via Channel Access or PV Access) to any field of the record other
than to the DISP field itself. Field changes and record processing can still be
instigated from inside the IOC using DB links and the IOC scan mechanisms.

The **DTYP** field specifies the device type for the record. Most record types
have their own set of device types which are specified in the IOC's database
definition file. If a record type does not call any device support routines,
the DTYP and DSET fields are not used.

The **MLOK** field contains a mutex which is locked by the monitor routines in
dbEvent.c whenever the monitor list for this record is accessed.

The **MLIS** field holds a linked list of client monitors connected to this
record. Each record support module is responsible for triggering monitors for
any fields that change as a result of record processing.

The **PPN** field contains the address of a putNotify callback.

The **PPNR** field contains the next record for PutNotify.

The **PUTF** field is set to TRUE if dbPutField caused the current record
processing.

The **RDES** field contains the address of dbRecordType

The **RPRO** field specifies a reprocessing of the record when current
processing completes.

The **TIME** field holds the time stamp when this record was last processed.

The **UTAG** field can be used to hold a site-specific 64-bit User Tag value
that is associated with the record's time stamp.

The **TSE** field value indicates the mechanism to use to get the time stamp:

- ` 0` — Get the current time as normal
- `-1` — Ask the time stamp driver for its best source of the current time, if
available.
- `-2` — Device support sets the time stamp and the optional User Tag from the
hardware.
- Positive values (normally between 1-255) get the time of the last occurance of
the numbered generalTime event.

The **TSEL** field contains an input link for obtaining the time stamp. If this
link points to the TIME field of a record then the time stamp and User Tag of
that record are copied directly into this record (Channel Access links can only
copy the time stamp, not the User Tag). If the link points to any other field,
that field's value is read and stored in the TSE field which is then used to
provide the time stamp as described above.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ASG | Access Security Group | STRING \[29\] | Yes |   | Yes | Yes | No |
| ASP | Access Security Pvt | NOACCESS | No |   | No | No | No |
| DISP | Disable putField | UCHAR | Yes |   | Yes | Yes | No |
| DTYP | Device Type | DEVICE | Yes |   | Yes | Yes | No |
| MLOK | Monitor lock | NOACCESS | No |   | No | No | No |
| MLIS | Monitor List | NOACCESS | No |   | No | No | No |
| PPN | pprocessNotify | NOACCESS | No |   | No | No | No |
| PPNR | pprocessNotifyRecord | NOACCESS | No |   | No | No | No |
| PUTF | dbPutField process | UCHAR | No |   | Yes | No | No |
| RDES | Address of dbRecordType | NOACCESS | No |   | No | No | No |
| RPRO | Reprocess  | UCHAR | No |   | Yes | No | No |
| TIME | Time | NOACCESS | No |   | No | No | No |
| UTAG | Time Tag | UINT64 | No |   | Yes | No | No |
| TSE | Time Stamp Event | SHORT | Yes |   | Yes | Yes | No |
| TSEL | Time Stamp Link | INLINK | Yes |   | Yes | Yes | No |
