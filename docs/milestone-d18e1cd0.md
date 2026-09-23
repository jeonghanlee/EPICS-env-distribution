# Work Register

Release line: master
Milestone index: d18e1cd0
Canonical path: `docs/milestone-d18e1cd0.md`
Canonical branch or ref: master
Git upstream: origin/master
Remote tracker: none

Next session entry point: `docs/milestone-d18e1cd0.md` M1 - review and accept the Implementation Plan.

## Milestone

### Work

| Group | ID | Work unit | Type | Status | Ready | Deps | Done when / Evidence |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Agent skill | M1 | Confirm agent skill discovery paths | Milestone | Not started | Yes | D1, D2 | Discovery paths and an isolated test method confirmed for each installed agent CLI, and the file layout recorded as a decision; [detail](#m1---confirm-agent-skill-discovery-paths) |
| Agent skill | M2 | Environment usage skill | Milestone | Not started | No | M1, D1, D2 | An isolated session of each agent CLI, reading the repository skill, activates the matching environment and runs its tools; [detail](#m2---environment-usage-skill) |
| Agent skill | M3 | IOC template extension | Milestone | Not started | No | M2 | An isolated session of each agent CLI, reading the repository skill, creates, builds, and runs an IOC from the template tools; [detail](#m3---ioc-template-extension) |
| Repository | M4 | Human-followable README | Milestone | Not started | Yes | D3 | README commands run verbatim in an empty `$HOME` match the README under the M4 matching rule; [detail](#m4---human-followable-readme) |
| Repository | M5 | Remove install.bash | Milestone | Not started | Yes | D4 | `install.bash` absent from the tree with no remaining reference; [detail](#m5---remove-installbash) |

### Decisions

| ID | Decision | Decision Date |
| --- | --- | --- |
| D1 | The usage skill is named `epics-env-usage`, covers using the distribution only (not building or publishing), and ships inside this repository. | 2026-09-23 |
| D2 | Scope proceeds in two stages: environment activation first, IOC template tools second. | 2026-09-23 |
| D3 | README targets human readers who follow its commands verbatim. | 2026-09-23 |
| D4 | `install.bash` is removed; distribution trees are produced by the VM build pipeline in `https://github.com/jeonghanlee/cloud-provision` and `https://github.com/jeonghanlee/ansible-provision`. | 2026-09-23 |

### Milestone Details

#### M1 - Confirm agent skill discovery paths

Origin: d18e1cd0 / M1
Identity History: none
GitHub Issue: none
Status: Not started

##### Summary

Determine where each supported agent CLI discovers project instructions and
skills, so one skill source serves every agent without duplicated content.

##### Scope

Claude Code, Codex CLI, and opencode at the versions installed on the test
host (observed 2026-09-23: Claude Code 2.1.280, codex-cli 0.156.1, opencode
1.18.32): project instruction files, project skill directories, and how to run
each CLI with user-level skills and instructions excluded.

Candidate layout to confirm or replace: one skill directory holding
`epics-env-usage`, a root `AGENTS.md` pointing to it for the agents that read
`AGENTS.md`, and a root `CLAUDE.md` importing `AGENTS.md` with `@AGENTS.md`
for Claude Code. It is a candidate, not a decision.

Out of scope: writing the skill (M2); agents other than the three listed.

##### Completion Criteria

- Each CLI's instruction-file and skill-directory discovery is recorded with
  its documentation URL, observation date, and the installed version it
  applies to.
- Each CLI has a recorded command that starts a session with user-level
  skills and instructions excluded.
- The file layout is recorded as a Decisions row.

##### Dependencies And Decisions

- D1, D2

##### Implementation Plan

Plan Status: draft
Plan Acceptance: none
Implementation Authorization: none
Superseded Plan Artifacts: none

1. Record `claude --version`, `codex --version`, and `opencode --version`.
2. Read the project instruction, skill discovery, and configuration-directory
   documentation of each CLI for the installed version.
3. Record the observed paths and the isolated session command per CLI, each
   with its documentation URL and installed version, in the Evidence cell of
   M1 / T1 Verification Results.
4. Record the chosen file layout as a Decisions row.

##### Test Plan

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | Documentation | Read each CLI's documentation for instruction and skill discovery and configuration-directory override | Published documentation for the installed versions | Paths and isolated session command recorded with URL, version, and observation date for all three CLIs |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | Not run | Published documentation | Pending | none |

##### Closure Evidence

- none

#### M2 - Environment usage skill

Origin: d18e1cd0 / M2
Identity History: none
GitHub Issue: none
Status: Not started

##### Summary

Add the `epics-env-usage` skill so an agent working in a clone of this
repository can select the tree matching the host OS, source its
`setEpicsEnv.bash`, and confirm the EPICS tools work.

##### Scope

Skill body, root `AGENTS.md`, and `CLAUDE.md` in the layout decided by M1:
repository layout, OS and version selection, sourcing, and tool verification.

Out of scope: IOC creation (M3); building or publishing distribution trees.

##### Completion Criteria

- An isolated session of each CLI (Claude Code, Codex CLI, opencode), started
  with the command recorded in M1 / T1 Verification Results and whose
  transcript shows the repository's `epics-env-usage` skill was read,
  sources the `setEpicsEnv.bash` matching the host OS and runs the
  verification commands the skill defines.

##### Dependencies And Decisions

- M1, D1, D2

##### Implementation Plan

Plan Status: draft
Plan Acceptance: none
Implementation Authorization: none
Superseded Plan Artifacts: none

1. Write the skill in the layout decided by M1.
2. Run T1 through T3 with isolated sessions that receive no answers from the
   authoring conversation.

##### Test Plan

Isolation, for every test in this detail: start the session with the isolated
command recorded in M1 / T1 Verification Results, so user-level skills and
instructions are not loaded, in this repository checkout. Pass requires the
session transcript to show that the repository's `epics-env-usage` skill was
read.

Request, sent verbatim:

`Set up the EPICS environment from this repository for this machine and show that it works.`

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | End-to-end | Isolated Claude Code session sent the request | Debian 13 host | Sources `1.3.0/debian-13/7.0.10/setEpicsEnv.bash`; `caget -h` exits 0; a `softIoc` PV is read with `caget` |
| T2 | End-to-end | Isolated Codex CLI session sent the request | Debian 13 host | Same as T1 |
| T3 | End-to-end | Isolated opencode session sent the request | Debian 13 host | Same as T1 |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | Not run | Debian 13 host | Pending | none |
| T2 | Not run | Debian 13 host | Pending | none |
| T3 | Not run | Debian 13 host | Pending | none |

##### Closure Evidence

- none

#### M3 - IOC template extension

Origin: d18e1cd0 / M3
Identity History: none
GitHub Issue: none
Status: Not started

##### Summary

Extend `epics-env-usage` so an agent can create an IOC with EPICS IOC
Template Tools (`https://github.com/jeonghanlee/EPICS-IOC-template-tools`) on
top of the activated environment.

##### Scope

Template tools retrieval, IOC generation, build, and run against the
distribution environment.

Out of scope: device-specific IOC development beyond the template output.

##### Completion Criteria

- An isolated session of each CLI (Claude Code, Codex CLI, opencode), started
  with the command recorded in M1 / T1 Verification Results and whose
  transcript shows the repository's `epics-env-usage` skill was read,
  generates an IOC from the template tools, builds it, runs it, and reads one
  of its PVs.

##### Dependencies And Decisions

- M2

##### Implementation Plan

Plan Status: draft
Plan Acceptance: none
Implementation Authorization: none
Superseded Plan Artifacts: none

1. Add the template procedure to the skill.
2. Run T1 through T3 with isolated sessions that receive no answers from the
   authoring conversation.

##### Test Plan

Isolation, for every test in this detail: start the session with the isolated
command recorded in M1 / T1 Verification Results, in this repository checkout.
Pass requires the session transcript to show that the repository's
`epics-env-usage` skill was read.

Request, sent verbatim:

`Create a new IOC with the EPICS IOC template tools using this EPICS environment, build it, and run it.`

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | End-to-end | Isolated Claude Code session sent the request | Debian 13 host | IOC builds to `bin/linux-x86_64`, starts, and a PV reads with `caget` |
| T2 | End-to-end | Isolated Codex CLI session sent the request | Debian 13 host | Same as T1 |
| T3 | End-to-end | Isolated opencode session sent the request | Debian 13 host | Same as T1 |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | Not run | Debian 13 host | Pending | none |
| T2 | Not run | Debian 13 host | Pending | none |
| T3 | Not run | Debian 13 host | Pending | none |

##### Closure Evidence

- none

#### M4 - Human-followable README

Origin: d18e1cd0 / M4
Identity History: none
GitHub Issue: none
Status: Not started

##### Summary

Correct README so a person following its commands verbatim reaches the paths
and output it shows.

##### Scope

Clone command and target directory, `source` example, printed paths, and
tool checks.

Out of scope: training material in the separate training repository.

##### Completion Criteria

- Every README command, run verbatim in an empty `$HOME`, produces the paths
  and output the README shows under the matching rule of T1.

##### Dependencies And Decisions

- D3

##### Implementation Plan

Plan Status: draft
Plan Acceptance: none
Implementation Authorization: none
Superseded Plan Artifacts: none

1. Align the clone command, target directory, and every example path. Show
   only the part of each printed `PATH` and `LD_LIBRARY_PATH` that
   `setEpicsEnv.bash` prepends, and abbreviate the inherited remainder as
   `...`.
2. The owner commits the README change under `git-workflow`.
3. Add an Open G row for the owner push of that commit to `origin/master`,
   with completion checked by `git fetch origin` followed by
   `git merge-base --is-ancestor <commit> origin/master` exiting 0. Add it to
   M4 `Deps`, set M4 to Blocked, and record resume as In progress.
4. After that G row is Complete, run T1.

##### Test Plan

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | End-to-end | With `HOME` set to an empty directory and the working directory at `$HOME`, run each README command verbatim after the push gate of step 3 is Complete | Debian 13 host | Clone location and sourced paths match the README with the README's home path replaced by the test `$HOME`; every other path component and tool result matches the README; for `PATH` and `LD_LIBRARY_PATH`, only the part `setEpicsEnv.bash` prepends is compared |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | Not run | Debian 13 host | Pending | none |

##### Closure Evidence

- none

#### M5 - Remove install.bash

Origin: d18e1cd0 / M5
Identity History: none
GitHub Issue: none
Status: Not started

##### Summary

Remove the in-repository build orchestrator, superseded by the external VM
build pipeline.

##### Scope

Delete `install.bash`.

Out of scope: the site NTP setting (`EPICS_TS_NTP_INET`) that `install.bash`
wrote to `RELEASE.local`. The file remains reachable through Git history.

##### Completion Criteria

- `install.bash` is absent from the tree and no tracked file outside this
  document references it.

##### Dependencies And Decisions

- D4

##### Implementation Plan

Plan Status: draft
Plan Acceptance: none
Implementation Authorization: none
Superseded Plan Artifacts: none

1. Remove `install.bash` with `git rm`.
2. Run T1.
3. The owner commits the removal under `git-workflow`.

##### Test Plan

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | Repository | `git ls-files install.bash` and `git grep -n install.bash -- ':!docs/milestone-d18e1cd0.md'` | Repository checkout | Both print nothing |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | Not run | Repository checkout | Pending | none |

##### Closure Evidence

- none

## Backlog

### Work

| Group | ID | Work unit | Type | Status | Ready | Deps | Done when / Evidence |
| --- | --- | --- | --- | --- | --- | --- | --- |

### Backlog Details

No unassigned work.
