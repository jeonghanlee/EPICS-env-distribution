# EPICS environment binary distribution

Release 1.5.0 provides relocatable Linux x86_64 binaries built from
[EPICS-env 1.5.0](https://github.com/jeonghanlee/EPICS-env/tree/1.5.0).
Each tree contains EPICS Base 7.0.10, 36 declared modules, the commonIocsh
scripts, and vendor libraries uldaq 1.2.2 and open62541 1.3.15.
This public distribution has site modules disabled.

## Supported operating systems

Use the tree matching your operating system. Every tree uses Base 7.0.10.

| Operating system | Directory |
| --- | --- |
| Debian 12 | `1.5.0/debian-12/7.0.10` |
| Debian 13 | `1.5.0/debian-13/7.0.10` |
| Rocky Linux 8.10 | `1.5.0/rocky-8.10/7.0.10` |
| Rocky Linux 10.2 | `1.5.0/rocky-10.2/7.0.10` |
| Ubuntu 24.04 LTS | `1.5.0/ubuntu-24.04/7.0.10` |
| Ubuntu 26.04 LTS | `1.5.0/ubuntu-26.04/7.0.10` |

## Get and activate the environment

Use Bash with Git and Perl installed. The binaries require their target
system's runtime libraries; report a missing library before changing the tree.

1. Clone the distribution:

   ```bash
   git clone --depth 1 https://github.com/jeonghanlee/EPICS-env-distribution.git ~/epics
   ```

2. Identify your architecture and operating system:

   ```bash
   uname -m
   HOST_ID="$(. /etc/os-release && printf '%s-%s' "$ID" "$VERSION_ID")"
   printf '%s\n' "$HOST_ID"
   ```

   Require `x86_64` and an exact directory match in the table.

3. Activate the matching tree in this terminal:

   ```bash
   TREE="$HOME/epics/1.5.0/$HOST_ID/7.0.10"
   test -f "$TREE/setEpicsEnv.bash"
   source "$TREE/setEpicsEnv.bash"
   ```

   The script sets `EPICS_PATH`, `EPICS_BASE`, `EPICS_MODULES`,
   `EPICS_HOST_ARCH`, `PATH`, and `LD_LIBRARY_PATH` for this shell.

## Start an IOC with the loader

The `iocsh.bash` loader starts `softIocPVX` and loads the modules named by
`module` directives, including their recorded dependencies.

1. Create a workspace outside the distribution and write a startup file:

   ```bash
   IOC_WORK="$(mktemp -d)"
   cd "$IOC_WORK"
   printf 'record(ai, "dist:probe") { field(VAL, "42") }\n' > probe.db
   printf 'module asyn\ndbLoadRecords("probe.db")\niocInit()\n' > st.cmd
   ```

2. Preview the generated startup and selected module paths:

   ```bash
   iocsh.bash -n st.cmd
   ```

3. Start the IOC:

   ```bash
   iocsh.bash st.cmd
   ```

   At the IOC prompt, enter `dbl` to list records and `exit` to stop.
   Keep the workspace for its startup file and IOC history.

## Verification

In the activated shell, confirm the tools resolve inside the selected tree:

```bash
command -v caget pvxget iocsh.bash
caget -h
cat "$TREE/.versions"
```

While the example IOC runs, activate the same tree in a second terminal
and read the example record over Channel Access (CA) and pvAccess (PVA):

```bash
caget dist:probe
pvxget dist:probe
```

Both reads must report 42. The usage skill below includes noninteractive
CA/PVA probes and instructions for preserving their logs.

## Use with a coding agent

Ask your agent to read [epics-env-usage/SKILL.md](epics-env-usage/SKILL.md).
It selects the matching tree, activates it, checks real CA/PVA reads, and
answers version and module questions from the installed files.

For application examples, see the
[loader guide](https://jeonghanlee.github.io/EPICS-env/procedures/set-up-shell.html),
[EPICS training](https://jeonghanlee.github.io/epics-trainings/), and
[IOC template tools](https://github.com/jeonghanlee/EPICS-IOC-template-tools).
