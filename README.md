# ALS-U EPICS Environment Binary Distribution

This repository provides a pre-built binary distribution of the EPICS environment specifically designed for the Advanced Light Source Upgrade (ALS-U) project.

This distribution simplifies setting up the required EPICS environment for developing and running IOCs  and client applications for ALS-U.

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

## Get the ALS-U EPICS environment

Clone the ALS-U EPICS repository using Git.

### Clone the ALS-U EPICS environment by using `git clone`

Please use **`--depth 1`**, which you only need for this distribution.

```shell
$ git clone --depth 1 https://github.com/jeonghanlee/EPICS-env-distribution.git ~/epics
```

By cloning the repository, you have the environment at the `${HOME}/epics` folder. In most cases, you are ready to use it.


## Configure the ALS-U EPICS enviornment
The ALS-U EPICS environment supports multiple operating system versions and EPICS versions. **Please note that the pre-built binaries included in this environment currently target the Linux x86_64 architecture exclusively.**

To select and activate a specific environment version in your current terminal session, you need to source the appropriate `setEpicsEnv.bash` script corresponding to your operating system and desired EPICS version:

```shell
# Example for EPICS 7.0.7 on Debian 12 (x86_64)
source ~/epics/1.1.1/debian-12/7.0.7/setEpicsEnv.bash
# or
# Example for EPICS 7.0.7 on Rocky 8.10 (x86_64)
source ~/epics/1.1.1/rocky-8.10/7.0.7/setEpicsEnv.bash
# or (x86_64)
source ~/epics/select_compatiable_Linux_Distribution/7.0.7/setEpicsEnv.bash
```
Sourcing the script sets up necessary environment variables like `EPICS_BASE`, `PATH`, and `LD_LIBRARY_PATH`. The output should resemble this (user and specific paths will vary):
```shell
Set the EPICS Environment as follows:
THIS Source NAME    : setEpicsEnv.bash
THIS Source PATH    : /home/jeonglee/epics/1.1.1/debian-12/7.0.7
EPICS_BASE          : /home/jeonglee/epics/1.1.1/debian-12/7.0.7/base
EPICS_HOST_ARCH     : linux-x86_64  # <-- Note the architecture
EPICS_MODULES       : /home/jeonglee/epics/1.1.1/debian-12/7.0.7/modules
PATH                : /home/jeonglee/epics/1.1.1/debian-12/7.0.7/modules/pmac/bin/linux-x86_64:/home/jeonglee/epics/1.1.1/debian-12/7.0.7/modules/pvxs/bin/linux-x86_64:/home/jeonglee/epics/1.1.1/debian-12/7.0.7/base/bin/linux-x86_64:/home/jeonglee/programs/root_v6-28-04/bin:/home/jeonglee/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games
LD_LIBRARY_PATH     : /home/jeonglee/epics/1.1.1/debian-12/7.0.7/modules/pmac/lib/linux-x86_64:/home/jeonglee/epics/1.1.1/debian-12/7.0.7/modules/pvxs/bundle/usr/linux-x86_64/lib:/home/jeonglee/epics/1.1.1/debian-12/7.0.7/modules/pvxs/lib/linux-x86_64:/home/jeonglee/epics/1.1.1/debian-12/7.0.7/base/lib/linux-x86_64:/home/jeonglee/programs/root_v6-28-04/lib/root

Enjoy Everlasting EPICS!
```
Note how the `EPICS_HOST_ARCH` variable and the paths explicitly mention `linux-x86_64`.


## Testing the Environment

Once the environment is sourced, verify that the EPICS command-line tools are accessible in your PATH:

```shell
# Check help output for an EPICS command-line tool (e.g., caput)
$ caput -h

# Verify the location of an EPICS command-line tool (e.g., caget)
$ which caget
```

If these commands run successfully and show help/path information, you have successfully configured the ALS-U EPICS environment in your current terminal session.

## macOS (M1) Support

* Version 1.1.1 does not currently support macOS 15.5. This setup is intended for training purposes only.
* Compatibility with all modules is not guaranteed and has not been fully tested.
* There are no plans to support macOS (Intel). If you are using an Intel-based Mac, please use UTM to virtualize Debian or Ubuntu Linux.



