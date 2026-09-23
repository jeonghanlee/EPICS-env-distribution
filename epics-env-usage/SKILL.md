---
name: epics-env-usage
description: Set up and explain the prebuilt EPICS environment in this repository. Use when asked to read this repository, set up or activate EPICS on this machine, or answer questions about the supported systems, EPICS base version, modules, module versions, or command-line tools it provides. Applies to requests in any language.
---

# EPICS Environment Usage

This repository is a prebuilt, relocatable EPICS environment. Nothing is
built or installed: select the tree that matches the host, source its
environment script, and use the tools. This file is self-contained; it needs
no other file, agent configuration, or network access.

In the commands below, `REPO` is the repository root: the directory that
contains the `epics-env-usage/` directory holding this file. Set it from the
path of this file:

```bash
REPO="$(cd "$(dirname "<path of this file>")/.." && pwd)"
```

For example, when this file is `/home/user/epics/epics-env-usage/SKILL.md`,
`REPO` is `/home/user/epics`.

## Layout

```text
<REPO>/<release>/<os>-<os-version>/<base-version>/
    setEpicsEnv.bash   sets EPICS_BASE, EPICS_HOST_ARCH, EPICS_MODULES, PATH, LD_LIBRARY_PATH
    .versions          build timestamp and the EPICS-env source commit
    base/              EPICS base: bin/, lib/, include/, dbd/, db/, configure/
    modules/           <name> -> <name>-<version> symlinks and the module trees
    vendor/            third-party libraries used by modules
```

Example: `1.3.0/debian-13/7.0.10/setEpicsEnv.bash`. Binaries target Linux
`x86_64` only.

## Select The Tree

1. Require `uname -m` to print `x86_64`.
2. Read the host identity: `. /etc/os-release && echo "${ID}-${VERSION_ID}"`.
   The tree directory uses exactly this form, for example `debian-12`,
   `debian-13`, `rocky-8.10`, `rocky-10.2`, `ubuntu-24.04`, `ubuntu-26.04`.
3. List what the repository ships:
   `ls -d "${REPO:?set REPO to the repository root first}"/*/*/*/setEpicsEnv.bash`.
4. Pick the entry whose `<os>-<os-version>` equals the host identity. When
   more than one release or base version matches, use the highest in version
   order unless the user names one:

   ```bash
   HOST_ID="$(. /etc/os-release && echo "${ID}-${VERSION_ID}")"
   ls -d "${REPO:?set REPO to the repository root first}"/*/"$HOST_ID"/*/setEpicsEnv.bash | sort -V | tail -n 1
   ```

5. When no entry matches, stop. Report the host identity and the shipped
   entries. Do not substitute a tree built for another system.
6. Set `TREE` to the directory that holds the chosen `setEpicsEnv.bash`, for
   example `TREE="${REPO:?set REPO to the repository root first}/1.3.0/debian-13/7.0.10"`.
   The steps below use it.

## Activate

`setEpicsEnv.bash` must be sourced by `bash`; `perl` must be installed, since
the script derives `EPICS_HOST_ARCH` with it. The script prints the resulting
variables.

```bash
source "$TREE/setEpicsEnv.bash"
```

The variables the script sets, and `REPO` and `TREE` themselves, live only
in the shell that set them. When each command runs in a new shell, as in most
agent tools, set `REPO` or `TREE` to its absolute path in the same command
line as the command that uses it, and source the script in the same command
line as the EPICS command:

```bash
REPO="/home/user/epics"; ls -d "${REPO:?set REPO to the repository root first}"/*/*/*/setEpicsEnv.bash
TREE="/home/user/epics/1.3.0/debian-13/7.0.10"; source "$TREE/setEpicsEnv.bash" >/dev/null && caget -h
```

A command that uses `REPO` stops with an error message when `REPO` is empty.

For a person's interactive terminal, sourcing once per terminal is enough.

## Verify

Run items 1 and 2 in the shell that sourced the script. The blocks in items
3 and 4 source it themselves; run each block as one command, in a shell where
`TREE` is set. In a new shell, add the line `TREE="<absolute path of the tree>"`
before the block's first line and run the result as one command. A block
stops with an error message when `TREE` is empty.

1. `command -v caget softIoc pvxget` prints three paths under `$TREE`.
2. `caget -h` exits 0.
3. A local IOC answers a Channel Access read:

   ```bash
   : "${TREE:?set TREE to the chosen tree first}"
   source "$TREE/setEpicsEnv.bash" >/dev/null
   WORK="$(mktemp -d)" && cd "$WORK"
   printf 'record(ai, "probe:value") { field(VAL, "42") }\n' > probe.db
   softIoc -S -d probe.db > probe.log 2>&1 &
   export EPICS_CA_ADDR_LIST=127.0.0.1 EPICS_CA_AUTO_ADDR_LIST=NO
   for i in 1 2 3 4 5; do caget -w 1 probe:value && break; [ "$i" -lt 5 ] && sleep 1; done
   rc=$?; kill %1; wait; cd / && rm -rf "$WORK"; echo "read rc=$rc"
   ```

   The loop retries while the IOC starts and exits non-zero when all five
   reads fail. The read prints one line with `probe:value` and `42`. Lines
   such as `Channel connect timed out: 'probe:value' not found.` before it
   come from tries made while the IOC was still starting; they are not a
   failure when a later try prints the value and the last line is `read rc=0`.

4. For pvAccess, serve the same record with `softIocPVX`, the pvxs IOC.
   `softIoc` serves Channel Access only.

   ```bash
   : "${TREE:?set TREE to the chosen tree first}"
   source "$TREE/setEpicsEnv.bash" >/dev/null
   WORK="$(mktemp -d)" && cd "$WORK"
   printf 'record(ai, "probe:value") { field(VAL, "42") }\n' > probe.db
   softIocPVX -S -d probe.db > probe.log 2>&1 &
   export EPICS_PVA_ADDR_LIST=127.0.0.1 EPICS_PVA_AUTO_ADDR_LIST=NO
   for i in 1 2 3 4 5; do pvxget -w 1 probe:value && break; [ "$i" -lt 5 ] && sleep 1; done
   rc=$?; kill %1; wait; cd / && rm -rf "$WORK"; echo "read rc=$rc"
   ```

   The read prints `probe:value` followed by `value double = 42`. Lines such
   as `Timeout with 1 outstanding` before it come from earlier tries, as in
   step 3; they are not a failure when the last line is `read rc=0`.

When a tool fails with a missing shared library, report the `ldd` output of
that tool. Do not install packages or edit the tree without the user's
approval.

## Answer Questions

Answer from the tree on disk, not from memory. Source the script first where
a command needs the EPICS variables.

- Supported systems and releases:
  `ls -d "${REPO:?set REPO to the repository root first}"/*/*/*/setEpicsEnv.bash`.
- EPICS base version:
  `grep -E '^EPICS_(VERSION|REVISION|MODIFICATION|PATCH_LEVEL) *=' "$TREE/base/configure/CONFIG_BASE_VERSION"`.
- Modules and their versions: `ls -l "$TREE/modules" | grep -- '->'`. Each
  link reads `<name> -> ./<name>-<version>`; the suffix is a release number or
  a short source commit.
- Where a module lives: `$EPICS_MODULES/<name>`, which equals
  `$EPICS_BASE/../modules/<name>`.
- Command-line tools: the `bin/linux-x86_64` directories of `base`,
  `modules/pvxs`, and `modules/pmac`, which the script puts on `PATH`.
- Build provenance: `cat "$TREE/.versions"`.
- Records, devices, and link fields: `$TREE/base/dbd/` for the base record
  types, and the `dbd/` and `db/` directories of each module under
  `$TREE/modules/`.

## Rules

- Treat the repository as read-only. Run IOCs from a directory outside it,
  such as one made by `mktemp -d`; an interactive IOC shell writes
  `.iocsh_history` into its working directory.
- Use only the tree that matches the host.
- Do not guess a version, module, or path; read it from the tree and quote the
  command that produced it.
