# Menu menuOmsl

This menu is used for the `OMSL` field of many output record types. It controls
whether the record will fetch an input value from its `DOL` input link when
processed, which is useful when it is part of a closed loop control algorithm.
The `supervisory` state means the input link will not be used, `closed_loop`
enables the input link.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | menuOmslsupervisory | supervisory |
| 1 | menuOmslclosed\_loop | closed\_loop |
