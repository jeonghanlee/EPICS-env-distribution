# Menu menuScan

This menu is used for the `SCAN` field of all record types.

The set of periodic scan rates may be modified for an individual IOC by
copying the `menuScan.dbd` file from Base into the IOC's source
directory and changing it to contain the desired scan rates.

The scan periods are extracted from the choice strings at runtime, which
must be expressed as a number with any of the following units appended:

>     second
>     seconds
>     minute
>     minutes
>     hour
>     hours
>     Hertz
>     Hz

At IOC start-up a separate scan thread will be created for each period,
with thread priority increasing further down the list, so faster periods
should appear after slower ones.

Scan rates that cannot be achieved will generate a warning message from
the `iocInit` command.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | menuScanPassive | Passive |
| 1 | menuScanEvent | Event |
| 2 | menuScanI\_O\_Intr | I/O Intr |
| 3 | menuScan10\_second | 10 second |
| 4 | menuScan5\_second | 5 second |
| 5 | menuScan2\_second | 2 second |
| 6 | menuScan1\_second | 1 second |
| 7 | menuScan\_5\_second | .5 second |
| 8 | menuScan\_2\_second | .2 second |
| 9 | menuScan\_1\_second | .1 second |
