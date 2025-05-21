# Menu menuPini

This menu defines the choices for the `PINI` field, which controls whether
and when each record should be processed during initialization or pausing
of the IOC. Choices other than `NO` cause record processing at the
following initHook transitions:

- YES

    `initHookAfterScanInit` — All records and links have been
    initialized but the scan threads and CA server are not running yet, nor
    have CA links been connected up. The initHook `initHookAfterInitialProcess`
    immediately follows this procssing.

- RUN

    `initHookAtIocRun` — The `iocRun()` routine has just been called,
    although not necessarily for the first time.

- RUNNING

    `initHookAfterIocRunning` — All remaining initializations have
    taken place, `interruptAccept` is enabled, the scan threads and CA server
    are running and the IOC is processing records. CA links might not have
    finished connecting though, and sequence programs won't usually have been
    started yet.

- PAUSE

    `initHookAtIocPause` — The `iocPause()` routine has just been
    called and the IOC is about to suspend operations.

- PAUSED

    `initHookAfterIocPaused` — The CA server, CA link operations and
    the scan threads have been paused and `interruptAccept` disabled.

Note that the order in which records that have the same `PINI` value get
processed can be controlled by setting their `PHAS` field, which is honored
for `PINI` processing as well as for regular scanning.

| Index | Identifier | Choice String |
| ----- | ---------- | ------------- |
| 0 | menuPiniNO | NO |
| 1 | menuPiniYES | YES |
| 2 | menuPiniRUN | RUN |
| 3 | menuPiniRUNNING | RUNNING |
| 4 | menuPiniPAUSE | PAUSE |
| 5 | menuPiniPAUSED | PAUSED |
