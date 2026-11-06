# Work Register

Release line: master
Milestone index: d18e1cd0
Canonical path: `docs/milestone-d18e1cd0.md`
Canonical branch or ref: master
Git upstream: origin/master
Remote tracker: none

Next session entry point: `docs/milestone-d18e1cd0.md` M6 - execute the prepared six OS commits and documentation commit under their approved operation scopes, then continue publication.

## Milestone

### Work

| Group | ID | Work unit | Type | Status | Ready | Deps | Done when / Evidence |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Agent skill | M1 | Confirm agent skill discovery paths | Milestone | Complete | No | D1, D2, D5 | Discovery paths and an isolated test method confirmed for each installed agent CLI, and the file layout recorded as a decision; [detail](#m1---confirm-agent-skill-discovery-paths) |
| Agent skill | M2 | Environment usage skill | Milestone | In progress | No | D6 | An agent told only to read this repository finds `epics-env-usage/SKILL.md`, activates the tree matching the host, and answers environment questions from it; [detail](#m2---environment-usage-skill) |
| Repository | M4 | Human-followable README | Milestone | In progress | No | D3 | README commands run verbatim in an empty `$HOME` match the README under the M4 matching rule; [detail](#m4---human-followable-readme) |
| Repository | M5 | Remove install.bash | Milestone | Complete | No | D4 | `install.bash` absent from the tree with no remaining reference; [detail](#m5---remove-installbash) |
| Distribution | M6 | Prepare 1.5.0 public candidates | Milestone | In progress | No | D7, D8 | Six verified OS trees, accepted baselines, and matching usage documentation; [detail](#m6---prepare-150-public-candidates) |

### Decisions

| ID | Decision | Decision Date |
| --- | --- | --- |
| D1 | The usage skill is named `epics-env-usage`, covers using the distribution only (not building or publishing), and ships inside this repository. | 2026-09-23 |
| D2 | Scope proceeds in two stages: environment activation first, IOC template tools second. | 2026-09-23 |
| D3 | README targets human readers who follow its commands verbatim. | 2026-09-23 |
| D4 | `install.bash` is removed; distribution trees are produced by the VM build pipeline in `https://github.com/jeonghanlee/cloud-provision` and `https://github.com/jeonghanlee/ansible-provision`. | 2026-09-23 |
| D5 | M1 confirms discovery by documentation and by an isolated probe run of each CLI against a scratch project outside this repository. | 2026-09-23 |
| D6 | `epics-env-usage` is one self-contained user skill file at `epics-env-usage/SKILL.md`, not a development skill: an agent told to read this repository uses it to set up the environment and answer questions about it, with no dependence on other files or agent configuration. It supersedes D1, D2, and D5, retires M1, and defers M3. | 2026-09-23 |
| D7 | The public 1.5.0 distribution uses build.gz, site disabled, and Debian 12/13, Rocky 8.10/10.2, Ubuntu 24.04/26.04. Earlier release directories follow replace retention during publication, with their history preserved. | 2026-11-06 |
| D8 | Accept the observed Debian 12, Rocky 10.2, Ubuntu 24.04, and Ubuntu 26.04 counts and outputs as their OS baselines, tied to each executed suite revision. Debian 13 and Rocky 8.10 retain their recorded baselines. | 2026-11-06 |

### Assignment History

| Work Identity | From Canonical | To Canonical | Target Commit | Authority Moved At |
| --- | --- | --- | --- | --- |
| d18e1cd0 / M3 | `docs/milestone-d18e1cd0.md` Milestone, master | `docs/milestone-d18e1cd0.md` Backlog, master | this synchronization commit | this synchronization commit |

### Milestone Details

#### M1 - Confirm agent skill discovery paths

Origin: d18e1cd0 / M1
Identity History: none
GitHub Issue: none
Status: Complete

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
  skills and instructions excluded, including how that session obtains its
  authentication.
- An isolated probe session of each CLI reads a probe skill placed in the
  candidate layout and loads no user-level skill.
- The file layout is recorded as a Decisions row.

##### Dependencies And Decisions

- D1, D2, D5

##### Implementation Plan

Plan Status: accepted
Plan Acceptance: 2026-09-23, plan carried by the working tree after commit ac5c1709
Implementation Authorization: 2026-09-23
Superseded Plan Artifacts: none

1. Record `claude --version`, `codex --version`, and `opencode --version`.
2. Read the project instruction, skill discovery, configuration-directory,
   and authentication documentation of each CLI for the installed version.
3. Record the observed paths and the isolated session command per CLI, each
   with its documentation URL and installed version, in the Evidence cell of
   M1 / T1 Verification Results.
4. Create a scratch Git project outside this repository in the candidate
   layout, holding a probe skill whose body contains a unique marker string.
5. Run T2 with the isolated session command of each CLI in that project.
6. Record the chosen file layout as a Decisions row; revise the candidate
   layout first when T2 shows a CLI does not read it.

##### Test Plan

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | Documentation | Read each CLI's documentation for instruction and skill discovery, configuration-directory override, and authentication | Published documentation for the installed versions | Paths and isolated session command recorded with URL, version, and observation date for all three CLIs |
| T2 | End-to-end | In the scratch project, start an isolated session of each CLI and ask `Which project skills are available? Quote the marker from the probe skill.` | Debian 13 host | Each CLI quotes the marker and names no user-level skill such as `epics-env-pipeline` |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | Not run | Published documentation | Pending | none |
| T2 | Not run | Debian 13 host | Pending | none |

##### Closure Evidence

- Retired 2026-09-23 by D6: the skill is one file read on request, so per-CLI
  discovery paths and isolated discovery probes are not needed. T1 and T2 are
  waived.

#### M2 - Environment usage skill

Origin: d18e1cd0 / M2
Identity History: none
GitHub Issue: none
Status: In progress

##### Summary

Add `epics-env-usage/SKILL.md`, one self-contained user skill file. An agent
told to read this repository uses it to select and activate the tree matching
the host and to answer questions about the environment.

##### Scope

The skill file only: repository layout, host and tree selection, activation
inside an agent shell, verification, and answers about supported systems,
versions, modules, and tools.

Out of scope: IOC development (M3); building or publishing distribution
trees; `AGENTS.md`, `CLAUDE.md`, or any agent-specific discovery file.

##### Completion Criteria

- The file depends on no other file or agent configuration.
- An agent session given only the request below, with no user-level skill or
  instruction loaded, reads the file, activates the matching tree, runs the
  verification the file defines, and answers the questions from the tree.

##### Dependencies And Decisions

- D6
- The skill is commit `b04f3ea5`, observed on `origin/master` at 2026-09-23 by
  `git fetch origin` followed by
  `git merge-base --is-ancestor b04f3ea5 origin/master` exiting 0.
- Remaining: a second-person review of the change that guards every `REPO`
  use, and a fresh sub-agent run of T5 on that change.
- T2 through T4 are not run: on 2026-09-23 the owner declined running the
  agent CLIs with copied authentication files. They stay Pending until a
  method without copied credentials is chosen or the owner waives them.

##### Implementation Plan

Plan Status: accepted
Plan Acceptance: 2026-09-23
Implementation Authorization: 2026-09-23
Superseded Plan Artifacts: the M2 plan in commit ac5c1709

1. Write `epics-env-usage/SKILL.md` from facts observed in the shipped tree.
2. Run T1 on this host against the file.
3. Run T2 through T4 with agent sessions that receive no answers from the
   authoring conversation.

##### Test Plan

Request, sent verbatim to each agent session started in the repository root:

`Read this repository and set up the EPICS environment for this machine. Then tell me which EPICS base version and which asyn version it provides.`

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | Procedure | Run every command in the skill file in order in a clean shell | Debian 13 host | Every command succeeds; `caget` reads the probe PV value |
| T2 | End-to-end | Claude Code session without user-level skills or instructions sent the request | Debian 13 host | Transcript shows the skill file read; activation of `1.5.0/debian-13/7.0.10`; a PV read; answers `7.0.10` and `4.46.0` |
| T3 | End-to-end | Codex CLI session under the same condition sent the request | Debian 13 host | Same as T2 |
| T4 | End-to-end | opencode session under the same condition sent the request | Debian 13 host | Same as T2 |
| T5 | End-to-end, partial | Claude sub-agent spawned from the authoring session, sent the request and told to use no skill tool and only files in the repository; it still sees the user-level skill list, so it does not replace T2 | Debian 13 host | Same as T2 |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | 2026-09-23 | Debian 13 host, `env -i` bash with `PATH=/usr/local/bin:/usr/bin:/bin` | Pass | Host identity `debian-13`; six shipped trees listed; `caget -h` rc=0; `caget`, `softIoc`, `pvxget` resolved under `1.3.0/debian-13/7.0.10`; `caget probe:value` printed 42 with rc=0; base 7.0.10; `asyn -> ./asyn-4.46.0`. Re-run after adding the pvAccess check and the outside-repository rule: from `/tmp`, `caget probe:value` printed 42 with rc=0 against `softIoc`, and `pvxget probe:value` printed `value double = 42` with rc=0 against `softIocPVX`. Re-run after replacing the fixed wait with a five-try read loop: with each IOC started 3 s late, both reads succeeded on the third try with rc=0; with no IOC, both loops exited rc=1. Re-run after moving each probe into its own `mktemp -d` directory and printing `read rc=`: both skill blocks, extracted verbatim and run in clean shells, printed the value and `read rc=0` normally and with the IOC 3 s late, printed `read rc=1` with no IOC, showed only the documented retry lines, and removed their directories. Re-run after adding the `REPO` command and the empty-`TREE` guard: the `REPO` command printed the repository root; the one-line `TREE=...; source ... && caget -h` form exited 0; each probe block exited 127 with `set TREE to the chosen tree first` when `TREE` was unset, and printed the value and `read rc=0` when it was set. Re-run after guarding every `REPO` use: with `REPO` unset, each listing command and the `TREE` example stopped with `set REPO to the repository root first` instead of searching `/`; with `REPO` set, the listing returned the six trees and the selection returned `1.3.0/debian-13/7.0.10`; each probe block with a prepended `TREE=` line printed `read rc=0` |
| T2 | Not run | Debian 13 host | Pending | none |
| T3 | Not run | Debian 13 host | Pending | none |
| T4 | Not run | Debian 13 host | Pending | none |
| T5 | 2026-09-23 | Debian 13 host, Claude sub-agent without the skill tool | Pass, partial | Found and followed `epics-env-usage/SKILL.md` after `README.md`; sourced `1.3.0/debian-13/7.0.10/setEpicsEnv.bash`; `caget probe:value` printed 42; answered 7.0.10 and 4.46.0 from `CONFIG_BASE_VERSION` and the `asyn` link. It also read this document, which states the expected answers, so the answers are not independent. An extra interactive `softIoc` run left an empty `.iocsh_history` in the repository root. Re-run 2026-09-23 after the pvAccess, `TREE`, and version-order changes: a fresh sub-agent reached the skill through the README, read no other repository document, selected the tree with `sort -V`, read 42 over Channel Access from `softIoc` and over pvAccess from `softIocPVX`, answered 7.0.10 and 4.46.0 from the tree, ran every IOC from `/tmp`, and reported no failed step. Second re-run 2026-09-23 after the five-try read loop: a fresh sub-agent again reached the skill through the README, read 42 over both protocols (pvAccess on the second try), answered 7.0.10 and 4.46.0 from the tree, and left the repository unchanged. Third re-run 2026-09-23 after the `mktemp -d` probes and retry-line notes: a fresh sub-agent followed the README to the skill, ran both probe blocks as written, recognized the retry lines as expected, saw `read rc=0` for both protocols, answered 7.0.10 and 4.46.0, and left the repository unchanged |

##### Closure Evidence

- none

#### M4 - Human-followable README

Origin: d18e1cd0 / M4
Identity History: none
GitHub Issue: none
Status: In progress

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
- Steps 2 and 3 are done: the README change is commit `f94cc998`, observed on
  `origin/master` at 2026-09-23 by `git fetch origin` followed by
  `git merge-base --is-ancestor f94cc998 origin/master` exiting 0. The push
  landed before the step 3 gate row existed, so no gate row is open. T1 is
  next.

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
Status: Complete

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
| T1 | 2026-09-23 | Repository checkout after `git rm install.bash` | Pass | `git ls-files install.bash` and `git grep -n install.bash -- ':!docs/milestone-d18e1cd0.md'` printed nothing |

##### Closure Evidence

- Commit `7bcc1803` observed on `origin/master` at 2026-09-23 by `git fetch origin`
  followed by `git merge-base --is-ancestor 7bcc1803 origin/master` exiting 0.

#### M6 - Prepare 1.5.0 public candidates

Origin: d18e1cd0 / M6
Identity History: none
GitHub Issue: none
Status: In progress

##### Summary

Prepare six verified EPICS-env 1.5.0 binary trees and the documentation needed
to use the public distribution.

##### Scope

Release source `0752183b2723016441a1f8f0f2cff5e749e83ac2`, build.gz,
site disabled, and the six OS directories under `1.5.0/`. Each tree includes
Base 7.0.10, 36 declared modules, commonIocsh scripts, uldaq 1.2.2,
and open62541 1.3.15. Update README and the self-contained usage skill.

Out of scope: publishing commits or tags, removing earlier release directories,
and published-checkout readback. Those require the publication plan and their
operation-specific authorization. M2 and M4 retain their separate completion criteria.

##### Completion Criteria

- All six trees pass installation, runtime, preservation, relocation, and final-path checks.
- Expected results are accepted for each OS and remain tied to the executed suite.
- README and the usage skill describe the actual candidate paths and behavior.
- A fresh agent executes the changed usage skill against the real matching candidate.

##### Dependencies And Decisions

- D7 and D8 define release scope and accepted verification results.
- Independent OS builds may run two at a time when provider capacity permits.
- Public clone/readback verification follows publication; local candidate checks do not replace it.

##### Implementation Plan

Plan Status: accepted
Plan Acceptance: 2026-11-06, accepted direction to confirm OS baselines and prepare distribution documentation
Implementation Authorization: 2026-11-06, proceed with baseline records and publication preparation
Superseded Plan Artifacts: none

1. Retain the actual per-OS logs and complete manifests; record accepted baselines.
2. Align README and the usage skill with the six candidate trees and loader.
3. Run local candidate documentation checks and a fresh usage-skill execution.
4. Prepare the per-OS commit and publication sequence; keep execution separate.

##### Test Plan

| Label | Layer | Method | Environment | Expected Result |
| --- | --- | --- | --- | --- |
| T1 | Build and runtime | Released installer, full loader suite, installed/isolated commonIocsh, caPutLog, and preserved-path IOC | Each of the six target OS guests | Actual successful exits, complete expected counts, real CA/PVA values, restored source/configuration |
| T2 | Artifact integrity | Compare full manifests and checksum copies; run final dependency and debug scans | Preserved guest trees and final repository candidates | Copies identical, earlier candidates unchanged, 86 executables and 79 libraries without path findings |
| T3 | Candidate documentation | Execute usage skill with a fresh agent and exercise README activation/loader commands against the real matching candidate | Debian 13 controller, clean shells, external IOC workspace | Correct tree selected; CA/PVA values read; loader starts; candidate unchanged |
| T4 | Document structure | Validate skill metadata, milestone schema, local links and command formatting | Candidate checkout | All applicable checks pass |
| T5 | Publication contents | Compare complete publication manifests with the retrieved candidates; run Git add dry-run for every selected file | Six OS trees and three documentation files | Only the recorded Git metadata path is absent per OS; all remaining entries match; every selected path is reported by Git |

##### Verification Results

| Label | Observed At | Environment | Result | Evidence |
| --- | --- | --- | --- | --- |
| T1 | 2026-11-05 to 2026-11-06 | Six target OS guests | Pass | Per-OS results below; 322 minimal IOC records and CA/PVA reads passed for every OS |
| T2 | 2026-11-05 to 2026-11-06 | Preserved and retrieved candidates | Pass | Preserved/staging/retrieved manifests equal; zero dependency findings; existing candidate trees unchanged at retrieval. T5 records the later publication-only metadata exclusion. |
| T3 | 2026-11-06 | Debian 13 candidate | Pass | Fresh Codex agent followed only the usage skill, selected the matching tree, read CA/PVA value 42, confirmed Base 7.0.10 and asyn 4.46.0, and ran loader preview/start/exit. README commands were extracted and executed against the real candidate in a clean shell: iocInit, dbl, CA/PVA value 42, and exit 0. All six candidate manifests matched their recorded values after these runs. Public clone/readback remains pending. |
| T4 | 2026-11-06 | Candidate documents | Pass | Skill validator, milestone checker, local links, shell command line lengths, and git diff whitespace check pass |
| T5 | 2026-11-06 | Publication candidates | Pass | Removed only vendor/share/open62541/tools/ua-nodeset/.git from each OS publication tree and retained the files outside the distribution. Complete manifest comparisons confirm every other entry is unchanged. Git add dry-run selects all 3,186 paths per OS and all three documentation files. |

Per-OS observations for source release 1.5.0:

| OS directory | Loader scripts / checks | commonIocsh installed / isolated | caPutLog | Truncated-library statuses |
| --- | --- | --- | --- | --- |
| debian-12 | 17 / 274 | 8 / 8 scripts | 6 pass | 135, 0, 0 |
| debian-13 | 17 / 274 | 8 / 8 scripts | 6 pass | 135, 0, 0 |
| rocky-8.10 | 17 / 272 | 8 / 8 scripts | 6 pass | 0, 0, 0 |
| rocky-10.2 | 17 / 272 | 8 / 8 scripts, 37 assertions each | 6 pass | 135, 0, 0 |
| ubuntu-24.04 | 17 / 272 | 8 / 8 scripts, 37 assertions each | 6 pass | 135, 0, 0 |
| ubuntu-26.04 | 17 / 272 | 8 / 8 scripts, 37 assertions each | 6 pass | 135, 0, 0 |

Counts describe the executed suites, not a count inferred from the OS.
The last three rows use tools revision `49d466ad43a7ac9a42c02f41335e08de96a1c9d1`.
Earlier executions retain their own suite identities in private execution evidence.
No per-OS mdBook rerun is required. Debug sections remain only in the
vendor open62541 library, which uses its recorded vendor build target.

Publication manifests contain 3,127 regular files and 59 symlinks per OS.
They exclude the source submodule `.git` pointer; original execution manifests
remain preserved, and published-checkout readback uses the publication manifests.

##### Closure Evidence

- T1 through T5 pass; OS baseline acceptance is D8. Repository landing remains pending, so M6 stays In progress.
- Published-checkout verification and M2/M4 historical completion criteria remain separate. No distribution commit, tag, push, or published-product readback is claimed.

## Backlog

### Work

| Group | ID | Work unit | Type | Status | Ready | Deps | Done when / Evidence |
| --- | --- | --- | --- | --- | --- | --- | --- |
| Agent skill | M3 | IOC template extension | Milestone | Deferred | No | D6 | Assignment returns by a new dated decision; [detail](#m3---ioc-template-extension) |

### Backlog Details

#### M3 - IOC template extension

Origin: d18e1cd0 / M3
Identity History: none
GitHub Issue: none
Status: Deferred

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

- D6: deferred 2026-09-23; returns to Not started only by a new dated decision.

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
