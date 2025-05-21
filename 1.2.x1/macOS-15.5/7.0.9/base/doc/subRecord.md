# Subroutine Record (sub)

The subroutine record is used to call a C initialization routine and a recurring
scan routine. There is no device support for this record.

## Parameter Fields

The record-specific fields are described below, grouped by functionality.

### Scan Parameters

The subroutine record has the standard fields for specifying under what
circumstances it will be processed.
These fields are described in [Scan Fields](dbCommonRecord.md#Scan-Fields).

### Read Parameters

The subroutine record has twelve input links (INPA-INPL), each of which has a
corresponding value field (A-L). These fields are used to retrieve and store
values that can be passed to the subroutine that the record calls.

The input links can be either channel access or database links, or constants.
When constants, the corresponding value field for the link is initialized with
the constant value and the field's value can be changed at run-time via dbPuts.
Otherwise, the values for (A-F) are fetched from the input links when the record
is processed.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| INPA | Input A | INLINK | Yes |   | Yes | Yes | No |
| INPB | Input B | INLINK | Yes |   | Yes | Yes | No |
| INPC | Input C | INLINK | Yes |   | Yes | Yes | No |
| INPD | Input D | INLINK | Yes |   | Yes | Yes | No |
| INPE | Input E | INLINK | Yes |   | Yes | Yes | No |
| INPF | Input F | INLINK | Yes |   | Yes | Yes | No |
| INPG | Input G | INLINK | Yes |   | Yes | Yes | No |
| INPH | Input H | INLINK | Yes |   | Yes | Yes | No |
| INPI | Input I | INLINK | Yes |   | Yes | Yes | No |
| INPJ | Input J | INLINK | Yes |   | Yes | Yes | No |
| INPK | Input K | INLINK | Yes |   | Yes | Yes | No |
| INPL | Input L | INLINK | Yes |   | Yes | Yes | No |
| A | Value of Input A | DOUBLE | No |   | Yes | Yes | Yes |
| B | Value of Input B | DOUBLE | No |   | Yes | Yes | Yes |
| C | Value of Input C | DOUBLE | No |   | Yes | Yes | Yes |
| D | Value of Input D | DOUBLE | No |   | Yes | Yes | Yes |
| E | Value of Input E | DOUBLE | No |   | Yes | Yes | Yes |
| F | Value of Input F | DOUBLE | No |   | Yes | Yes | Yes |
| G | Value of Input G | DOUBLE | No |   | Yes | Yes | Yes |
| H | Value of Input H | DOUBLE | No |   | Yes | Yes | Yes |
| I | Value of Input I | DOUBLE | No |   | Yes | Yes | Yes |
| J | Value of Input J | DOUBLE | No |   | Yes | Yes | Yes |
| K | Value of Input K | DOUBLE | No |   | Yes | Yes | Yes |
| L | Value of Input L | DOUBLE | No |   | Yes | Yes | Yes |

### Subroutine Connection

These fields are used to connect to the C subroutine. The name of the subroutine
should be entered in the SNAM field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| INAM | Init Routine Name | STRING \[40\] | Yes |   | Yes | No | No |
| SNAM | Subroutine Name | STRING \[40\] | Yes |   | Yes | Yes | No |

### Operator Display Parameters

These parameters are used to present meaningful data to the operator. They
display the value and other parameters of the subroutine either textually or
graphically.

EGU is a string of up to 16 characters that could describe any units used by the
subroutine record. It is retrieved by the `get_units` record support
routine.

The HOPR and LOPR fields set the upper and lower display limits for the VAL,
A-L, LA-LL, HIHI, LOLO, LOW, and HIGH fields. Both the `get_graphic_double` and `get_control_double` record support routines retrieve these
fields.

The PREC field determines the floating point precision with which to display
VAL. It is used whenever the `get_precision` record support routine is
called.

See [Fields Common to All Record Types](dbCommonRecord.md#Operator-Display-Parameters) for more on the record name (NAME) and description (DESC) fields.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| EGU | Engineering Units | STRING \[16\] | Yes |   | Yes | Yes | No |
| HOPR | High Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| LOPR | Low Operating Range | DOUBLE | Yes |   | Yes | Yes | No |
| PREC | Display Precision | SHORT | Yes |   | Yes | Yes | No |
| NAME | Record Name | STRING \[61\] | No |   | Yes | No | No |
| DESC | Descriptor | STRING \[41\] | Yes |   | Yes | Yes | No |

### Alarm Parameters

The possible alarm conditions for subroutine records are the SCAN, READ, limit
alarms, and an alarm that can be triggered if the subroutine returns a negative
value. The SCAN and READ alarms are called by the record or device support
routines. The limit alarms are configured by the user in the HIHI, LOLO, HIGH,
and LOW fields using numerical values. They apply to the VAL field. For each of
these fields, there is a corresponding severity field which can be either
NO\_ALARM, MINOR, or MAJOR.

The BRSV field is where the user can set the alarm severity in case the
subroutine returns a negative value.

[Alarm Fields](dbCommonRecord.md#Alarm-Fields) lists the fields related to
alarms that are common to all record types.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| HIHI | Hihi Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| HIGH | High Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| LOW | Low Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| LOLO | Lolo Alarm Limit | DOUBLE | Yes |   | Yes | Yes | Yes |
| HHSV | Hihi Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HSV | High Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LSV | Low Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| LLSV | Lolo Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| BRSV | Bad Return Severity | MENU [menuAlarmSevr](menuAlarmSevr.md) | Yes |   | Yes | Yes | Yes |
| HYST | Alarm Deadband | DOUBLE | Yes |   | Yes | Yes | No |

### Monitor Parameters

These parameters are used to determine when to send monitors placed on the VAL
field. The appropriate monitors are invoked when VAL differs from the values in
the ALST and MLST run-time fields, i.e., when the value of VAL changes by more
than the deadband specified in these fields. The ADEL and MDEL fields specify a
minimum delta which the change must surpass before the value-change monitors are
invoked. If these fields have a value of zero, everytime the value changes, a
monitor will be triggered; if they have a value of -1, everytime the record is
processed, monitors are triggered. The ADEL field is used by archive monitors
and the MDEL field for all other types of monitors.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| ADEL | Archive Deadband | DOUBLE | Yes |   | Yes | Yes | No |
| MDEL | Monitor Deadband | DOUBLE | Yes |   | Yes | Yes | No |

### Run-time Parameters

These parameters are used by the run-time code for processing the subroutine
record. They are not configured using a database configuration tool. They
represent the current state of the record. Many of them are used by the record
processing routines or the monitors.

VAL should be set by the subroutine. SADR holds the subroutine address and is
set by the record processing routine.

The rest of these fields--LALM, ALST, MLST, and the LA-LL fields--are used to
implement the monitors. For example, when LA is not equal to A, the value-change
monitors are called for that field.

| Field | Summary | Type | DCT | Default | Read | Write | CA PP |
| ----- | ------- | ---- | --- | ------- | ---- | ----- | ----- |
| VAL | Result | DOUBLE | No |   | Yes | Yes | Yes |
| SADR | Subroutine Address | NOACCESS | No |   | No | No | No |
| LALM | Last Value Alarmed | DOUBLE | No |   | Yes | No | No |
| ALST | Last Value Archived | DOUBLE | No |   | Yes | No | No |
| MLST | Last Value Monitored | DOUBLE | No |   | Yes | No | No |
| LA | Prev Value of A | DOUBLE | No |   | Yes | No | No |
| LB | Prev Value of B | DOUBLE | No |   | Yes | No | No |
| LC | Prev Value of C | DOUBLE | No |   | Yes | No | No |
| LD | Prev Value of D | DOUBLE | No |   | Yes | No | No |
| LE | Prev Value of E | DOUBLE | No |   | Yes | No | No |
| LF | Prev Value of F | DOUBLE | No |   | Yes | No | No |
| LG | Prev Value of G | DOUBLE | No |   | Yes | No | No |
| LH | Prev Value of H | DOUBLE | No |   | Yes | No | No |
| LI | Prev Value of I | DOUBLE | No |   | Yes | No | No |
| LJ | Prev Value of J | DOUBLE | No |   | Yes | No | No |
| LK | Prev Value of K | DOUBLE | No |   | Yes | No | No |
| LL | Prev Value of L | DOUBLE | No |   | Yes | No | No |

## Record Support

### Record Support Routines

#### init\_record

    long (*init_record)(struct dbCommon *precord, int pass)

For each constant input link, the corresponding value field is initialized with
the constant value. For each input link that is of type PV\_LINK, a channel
access link is created.

If an initialization subroutine is defined, it is located and called.

The processing subroutine is located and its address stored in SADR.

#### process

    long (*process)(struct dbCommon *precord)

See ["Record Processing"](#record-processing).

#### get\_units

    long (*get_units)(struct dbAddr *paddr, char *units)

Retrieves EGU.

#### get\_precision

    long (*get_precision)(const struct dbAddr *paddr, long *precision)

Retrieves PREC when VAL is the field being referenced. Otherwise, calls `recGblGetPrec()`.

#### get\_graphic\_double

    long (*get_graphic_double)(struct dbAddr *paddr, struct dbr_grDouble *p)

Sets the upper display and lower display limits for a field. If the field is
VAL, A-L, LA-LL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR,
else if the field has upper and lower limits defined they will be used, else the
upper and lower maximum values for the field type will be used.

#### get\_control\_double

    long (*get_control_double)(struct dbAddr *paddr, struct dbr_ctrlDouble *p)

Sets the upper control and the lower control limits for a field. If the field is
VAL, A-L, LA-LL, HIHI, HIGH, LOW, or LOLO, the limits are set to HOPR and LOPR,
else if the field has upper and lower limits defined they will be used, else the
upper and lower maximum values for the field type will be used.

#### get\_alarm\_double

    long (*get_alarm_double)(struct dbAddr *paddr, struct dbr_alDouble *p)

Sets the following values:

    upper_alarm_limit = HIHI
    upper_warning_limit = HIGH
    lower_warning_limit = LOW
    lower_alarm_limit = LOLO

### Record Processing

Routine process implements the following algorithm:

1. If PACT is FALSE then fetch all arguments.
2. Call the subroutine and check return value.
    - Call subroutine
    - Set PACT TRUE
    - If return value is 1, return
3. Check alarms. This routine checks to see if the new VAL causes the alarm status
and severity to change.
If so, NSEV, NSTA and LALM are set.
It also honors the alarm hysteresis factor (HYST).
Thus the value must change by more than HYST before the alarm status and
severity is lowered.
4. Check to see if monitors should be invoked.
    - Alarm monitors are invoked if the alarm status or severity has changed.
    - Archive and value change monitors are invoked if ADEL and MDEL conditions are
    met.
    - Monitors for A-L are invoked if value has changed.
    - NSEV and NSTA are reset to 0.
5. Scan forward link if necessary, set PACT FALSE, and return.

### Example Synchronous Subroutine

This is an example subroutine that merely increments VAL each time process is
called.

    #include <stdio.h>
    #include <dbDefs.h>
    #include <subRecord.h>
    #include <registryFunction.h>
    #include <epicsExport.h>

    static long subInit(struct subRecord *psub)
    {
        printf("subInit was called\n");
        return 0;
    }

    static long subProcess(struct subRecord *psub)
    {
        psub->val++;
        return 0;
    }

    epicsRegisterFunction(subInit);
    epicsRegisterFunction(subProcess);

### Example Asynchronous Subroutine

This example for a VxWorks IOC shows an asynchronous subroutine. It uses
(actually misuses) fields A and B. Field A is taken as the number of seconds
until asynchronous completion. Field B is a flag to decide if messages should be
printed. Lets assume A > 0 and B = 1. The following sequence of actions will
occcur:

1. subProcess is called with pact FALSE. It performs the following steps.
    - Computes, from A, the number of ticks until asynchronous completion should
    occur.
    - Prints a message stating that it is requesting an asynchronous callback.
    - Calls the vxWorks watchdog start routine.
    - Sets pact TRUE and returns a value of 0. This tells record support to complete
    without checking alarms, monitors, or the forward link.
2. When the time expires, the system wide callback task calls myCallback.
myCallback locks the record, calls process, and unlocks the record.
3. Process again calls subProcess, but now pact is TRUE. Thus the following is
done:
    - VAL is incremented.
    - A completion message is printed.
    - subProcess returns 0. The record processing routine will complete record
    processing.

    #include <types.h>
    #include <stdio.h>
    #include <wdLib.h>
    #include <callback.h>
    #include <dbDefs.h>
    #include <dbAccess.h>
    #include <subRecord.h>

    /* control block for callback*/
    struct callback {
        epicsCallback callback;
        struct dbCommon *precord;
        WDOG_ID wd_id;
    };

    void myCallback(struct callback *pcallback)
    {
        struct dbCommon *precord=pcallback->precord;
        struct rset *prset=(struct rset *)(precord->rset);
        dbScanLock(precord);
        (*prset->process)(precord);
        dbScanUnlock(precord);
    }

    long subInit(struct subRecord *psub)
    {
        struct callback *pcallback;
        pcallback = (struct callback *)(calloc(1,sizeof(struct callback)));
        psub->dpvt = (void *)pcallback;
        callbackSetCallback(myCallback,pcallback);
        pcallback->precord = (struct dbCommon *)psub;
        pcallback->wd_id = wdCreate();
        printf("subInit was called\n");
        return 0;
    }

    long subProcess(struct subRecord *psub)
    {
        struct callback *pcallback=(struct callback *)(psub->dpvt);
        /* sub.inp must be a CONSTANT*/
        if (psub->pact) {
            psub->val++;
            if (psub->b)
            printf("%s subProcess Completed\n", psub->name);
            return 0;
        } else {
            int wait_time = (long)(psub->a * vxTicksPerSecond);
            if (wait_time <= 0){
                if (psub->b)
                    printf("%s subProcess sync processing\n", psub->name);
                psub->pact = TRUE;
                return 0;
            }
            if (psub->b){
                callbackSetPriority(psub->prio, pcallback);
                printf("%s Starting async processing\n", psub->name);
                wdStart(pcallback->wd_id, wait_time, callbackRequest, (int)pcallback);
                return 1;
            }
        }
        return 0;
    }
