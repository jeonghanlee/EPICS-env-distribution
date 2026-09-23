# EPICS Environment Binary Distribution

This repository provides a pre-built binary distribution of the EPICS environment specifically designed for the Advanced Light Source Upgrade (ALS-U) project.

This distribution simplifies setting up the required EPICS environment for developing and running IOCs and client applications.

## Source Repositories

This binary distribution is built from the following core repositories:

* [`jeonghanlee/EPICS-env`](https://github.com/jeonghanlee/EPICS-env)
* [`jeonghanlee/EPICS-env-support`](https://github.com/jeonghanlee/EPICS-env-support)

## Getting Started & Training

For comprehensive instructions on how to use this distribution, set up your development environment, and build EPICS IOCs, please refer to the full ALS-U EPICS Environment training materials and resources:

* **Full Training Website:** [`https://jeonghanlee.github.io/epics-trainings/`](https://jeonghanlee.github.io/epics-trainings/)
* **IOC Template Tools:** [`https://github.com/jeonghanlee/EPICS-IOC-template-tools`](https://github.com/jeonghanlee/EPICS-IOC-template-tools)
* **IOC Demo Project:** [`https://github.com/jeonghanlee/EPICS-IOC-Demo`](https://github.com/jeonghanlee/EPICS-IOC-Demo)

These resources cover installation, configuration, and development workflows.

## Get the EPICS Environment Binary Distribution

Clone the EPICS environment repository using Git.

### Clone the EPICS environment by using `git clone`

Please use **`--depth 1`**. Using the environment needs only the latest snapshot, not the history.

```shell
git clone --depth 1 https://github.com/jeonghanlee/EPICS-env-distribution.git ~/epics
```

The command places the environment in the `${HOME}/epics` folder. In most cases, you are ready to use it.


## Configure the EPICS environment
The EPICS environment supports multiple operating system versions. **Please note that the pre-built binaries included in this environment currently target the Linux x86_64 architecture exclusively.**

The `setEpicsEnv.bash` script requires `bash` and `perl`.

The distribution provides one tree per operating system, named `<os>-<version>`: `debian-12`, `debian-13`, `rocky-8.10`, `rocky-10.2`, `ubuntu-24.04`, and `ubuntu-26.04`. Print the name for your system and list the trees in the clone:

```shell
(. /etc/os-release && echo "${ID}-${VERSION_ID}")
ls ~/epics/1.3.0/
```

To activate the environment in your current terminal session, source the `setEpicsEnv.bash` script for your operating system:

```shell
# Example for EPICS 7.0.10 on Debian 13 (x86_64)
source ~/epics/1.3.0/debian-13/7.0.10/setEpicsEnv.bash
```

On another system, replace `debian-13` with the name printed above. The directory below it is the EPICS base version; list it with `ls ~/epics/1.3.0/<name>/`, for example `ls ~/epics/1.3.0/rocky-8.10/`.

Sourcing the script sets up necessary environment variables like `EPICS_BASE`, `PATH`, and `LD_LIBRARY_PATH`. The output should resemble this, with your home directory in place of `/home/user`. `PATH` and `LD_LIBRARY_PATH` show only the part the script adds; `...` stands for the values your shell already had, and does not appear when the variable was empty:
```shell
Set the EPICS Environment as follows:
THIS Source NAME    : setEpicsEnv.bash
THIS Source PATH    : /home/user/epics/1.3.0/debian-13/7.0.10
EPICS_BASE          : /home/user/epics/1.3.0/debian-13/7.0.10/base
EPICS_HOST_ARCH     : linux-x86_64
EPICS_MODULES       : /home/user/epics/1.3.0/debian-13/7.0.10/modules
PATH                : /home/user/epics/1.3.0/debian-13/7.0.10/modules/pmac/bin/linux-x86_64:/home/user/epics/1.3.0/debian-13/7.0.10/modules/pvxs/bin/linux-x86_64:/home/user/epics/1.3.0/debian-13/7.0.10/base/bin/linux-x86_64:...
LD_LIBRARY_PATH     : /home/user/epics/1.3.0/debian-13/7.0.10/base/lib/linux-x86_64:...

Enjoy Everlasting EPICS!

```
Note how the `EPICS_HOST_ARCH` variable and the paths explicitly mention `linux-x86_64`.


## Testing the Environment

Once the environment is sourced, verify that the EPICS command-line tools are accessible in your PATH:

```shell
# Check help output for an EPICS command-line tool (e.g., caput)
caput -h

# Verify the location of an EPICS command-line tool (e.g., caget)
which caget
```

If these commands run successfully and show help/path information, you have successfully configured the ALS-U EPICS environment in your current terminal session.

## Using a Coding Agent

`epics-env-usage/SKILL.md` is a self-contained instruction file for coding agents. Start your agent in `~/epics` and ask it to read this repository, or to read that file; it selects the tree for your system, activates it, verifies it, and answers questions about the environment.

