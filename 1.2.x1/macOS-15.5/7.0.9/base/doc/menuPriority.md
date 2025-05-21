# Menu menuPriority

This menu is used for the `PRIO` field of all record types. It controls
the relative priority of records scheduled with `SCAN=Event` or
`SCAN=I/O Intr`, and also of records that use asynchronous completion.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | menuPriorityLOW | LOW |
| 1 | menuPriorityMEDIUM | MEDIUM |
| 2 | menuPriorityHIGH | HIGH |

The number of priorities is set in various other places in the code too,
so adding new entries to this menu will probably break the IOC build.
