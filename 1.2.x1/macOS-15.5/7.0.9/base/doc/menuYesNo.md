# Menu menuYesNo

This menu is used by many record types to specify simple `NO` or `YES`
options for record-specific purposes.

Note that no other values for a field that uses menuYesNo are possible, e.g.
`MAYBE` or `NO WAY` would not be accepted as choices for the field.
Also, the choices `yes`, `No`, and `Yes` are not valid choices since they
don't match the case of `NO` or `YES`.
The integer values `0` and `1` may often be used instead however, they are
used as an index into the choices so `0` becomes `NO` and `1` becomes
`YES`.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | menuYesNoNO | NO |
| 1 | menuYesNoYES | YES |
