#!/usr/bin/env bash
#
#  Copyright (c) 2025 -         Jeong Han Lee
#
#  The program is free software: you can redistribute
#  it and/or modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation, either version 2 of the
#  License, or any newer version.
#
#  This program is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
#  more details.
#
#  You should have received a copy of the GNU General Public License along with
#  this program. If not, see https://www.gnu.org/licenses/gpl-2.0.txt
#
#  author  : Jeong Han Lee
#  email   : jeonghan.lee@gmail.com
#  version : 0.0.3
#

declare -g SC_RPATH;
#declare -g SC_NAME;
declare -g SC_TOP;
declare -g SC_TIME;

SC_RPATH="$(realpath "$0")";
#SC_NAME=${0##*/};
SC_TOP="${SC_RPATH%/*}"
SC_TIME="$(date +%y%m%d%H%M)"

# Enable core dumps in case the JVM fails
ulimit -c unlimited

# Function: pushdd
# Description: Wrapper for 'pushd' that changes the current directory and
#              suppresses the command's output.
function pushdd { builtin pushd "$@" > /dev/null || exit; }
# Function: popdd
# Description: Wrapper for 'popd' that returns to the previous directory and
#              suppresses the command's output.
function popdd  { builtin popd  > /dev/null || exit; }

declare -g OS_NAME;
declare -g OS_VERSION;
declare -g INSTALL_LOCAITON_EPICS;
declare -g INSTALL_LOCATION_VER;
declare -g EPICS_BASE_PATH;
declare -g EPICS_MODS_PATH;
declare -g VENDOR_LIB_PATH;

declare -g WORKING_FOLDER=${HOME}/.temp_folder
declare -g EPICS_ENV_PATH=${WORKING_FOLDER}/EPICS-env
declare -g EPICS_ENV_SUPPORT_PATH=${WORKING_FOLDER}/EPICS-env-support
declare -g VENDOR_ULDAQ_SRC=${WORKING_FOLDER}/uldaq-env
declare -g VENDOR_OPEN62451_SRC=${WORKING_FOLDER}/open62541-env

# Function: is_redhat_variant
# Description: Checks if the current operating system is a Red Hat variant
#              (Rocky, RHEL, CentOS, or Fedora) and sets global variables.
# Returns: 0 if a variant is detected, 1 otherwise.
function is_redhat_variant
{
  if [ -f /etc/os-release ]; then
    source /etc/os-release
    case "$ID" in
      "rocky"|"rhel"|"centos"|"fedora")
        return 0
        ;;
      *)
        return 1
        ;;
    esac
  else
    return 1
  fi
}

# Function: _setup_working_path
# Description: Creates and cleans the main working directory to ensure a fresh
#              environment for the build process.
function _setup_working_path
{
    echo "--- Setting up working path at ${WORKING_FOLDER} ---"
    mkdir -p "${WORKING_FOLDER}"
    pushdd "${WORKING_FOLDER}"
    # Use a safer way to clean the directory
    find . -maxdepth 1 -mindepth 1 -exec rm -rf {} +
    popdd
}

# Function: _git_clone_repos
# Description: Clones all necessary Git repositories from their respective
#              URLs into the working directory.
function _git_clone_repos
{
    echo "--- Cloning repositories ---"
    pushdd "${WORKING_FOLDER}";
    git clone git@github.com:jeonghanlee/EPICS-env.git
    git clone git@github.com:jeonghanlee/EPICS-env-support.git
    git clone git@github.com:jeonghanlee/uldaq-env.git
    git clone git@github.com:jeonghanlee/open62541-env.git
    popdd;
}

# Function: _prep_env
# Description: Checks out a specific version of the main EPICS environment and
#              writes the local installation path to its configuration file.
function _prep_env
{
    local version="$1"
    pushdd "${EPICS_ENV_PATH}"
    git checkout "${version}" || { echo "Failed to checkout version ${version}"; exit 1; }
    echo "INSTALL_LOCATION=${SC_TOP}" > configure/CONFIG_SITE.local
    popdd
}


# Function: initial_setup
# Description: Performs the initial setup by creating the working folder,
#              cloning all repositories, and preparing the main EPICS environment
#              for a specified version.
function initial_setup
{
    local version="$1"
    echo "--- Preparing environment for version: ${version} ---"
    _setup_working_path
    _git_clone_repos
    _prep_env "${version}"
}

# Function: _fill_env
# Description: Fills global environment variables by running `make` commands
#              within the main EPICS environment to retrieve paths and OS information.
function _fill_env
{
    pushdd "${EPICS_ENV_PATH}"
    OS_NAME=$(make print-OS_NAME)
    OS_VERSION=$(make print-OS_VERSION)
    INSTALL_LOCATION_EPICS=$(make print-INSTALL_LOCATION_EPICS)
    INSTALL_LOCATION_VER=$(make print-INSTALL_LOCATION_VER)
    EPICS_BASE_PATH=${INSTALL_LOCATION_EPICS}/base
    EPICS_MODS_PATH=${INSTALL_LOCATION_EPICS}/modules
    VENDOR_LIB_PATH=${INSTALL_LOCATION_EPICS}/vendor
    popdd
}

# Function: _echo_env
# Description: Prints the values of all relevant global variables after the environment is set up.
function _echo_env
{
    echo "--- Environment Variables ---"
    echo "OS_NAME: ${OS_NAME}"
    echo "OS_VERSION: ${OS_VERSION}"
    echo "INSTALL_LOCAITON_EPICS: ${INSTALL_LOCATION_EPICS}"
    echo "INSTALL_LOCATION_VER: ${INSTALL_LOCATION_VER}"
    echo "EPICS_BASE_PATH: ${EPICS_BASE_PATH}"
    echo "EPICS_MODS_PATH: ${EPOCS_MODS_PATH}"
    echo "VENDOR_LIB_PATH: ${VENDOR_LIB_PATH}"
    echo "WORKING_FOLDER: ${WORKING_FOLDER}"
    echo "EPICS_ENV_PATH: ${EPICS_ENV_PATH}"
    echo "EPICS_ENV_SUPPORT_PATH: ${EPICS_ENV_SUPPORT_PATH}"
    echo "VENDOR_ULDAQ_SRC: ${VENDOR_ULDAQ_SRC}"
    echo "VENDOR_OPEN62451_SRC: ${VENDOR_OPEN62451_SRC}"
}
# Function: _prep_vendor
# Description: A generic function that prepares a vendor library by checking out
#              its version, setting the installation path, and running the necessary
#              'make' commands to clean, configure, build, and install it.
function _prep_vendor()
{
    _fill_env;
    local folder="$1"; shift;
    local name="${folder##*/}"
    echo "--- Preparing vendor library: ${name} ---"
    pushdd "$folder"
    echo "INSTALL_LOCATION=${VENDOR_LIB_PATH}" > configure/CONFIG_SITE.local
    make distclean || exit
    make init    || exit
   	if is_redhat_variant; then
        echo "Error: This system is an ugly Red Hat variant."
        make conf.rocky8 || exit;
    else
        echo "Whoray! This system is not a Red Hat variant."
        make conf || exit;
    fi
    make build   || exit
    make install || exit
    popdd
}

# Function: _pre_support
# Description: A generic function to prepare a support module by checking out
#              a specific version, setting the installation path, and running the
#              necessary 'make' commands to build and link the module.
function _pre_support
{
    _fill_env;
    local version="$1"; shift
    local folder="$1"; shift
    local name="${folder##*/}"
    echo "--- Preparing support module: ${name} (version: ${version}) ---"
    pushdd "$folder"
    git checkout "$version" || { echo "Failed to checkout version ${version}"; exit 1; }
    echo "INSTALL_LOCATION=${EPICS_BASE_PATH}" > configure/CONFIG_SITE.local
    # This distclean will remove *.local file, so we need to run one more time.
    make distclean || exit
    echo "INSTALL_LOCATION=${EPICS_BASE_PATH}" > configure/CONFIG_SITE.local
    make init     || exit
    make conf     || exit
    make patch.ADCore.apply ||exit
    make build.gz    || exit
    make symlinks || exit
    popdd
}

# Function: prep_uldaq
# Description: Prepares the 'uldaq' vendor library by calling the generic
#              '_prep_vendor' function.
# Function: prep_open62541
# Description: Prepares the 'open62541' vendor library by calling the generic
#              '_prep_vendor' function.
function prep_uldaq     { _fill_env; _prep_vendor "${VENDOR_ULDAQ_SRC}"; }
function prep_open62541 { _fill_env; _prep_vendor "${VENDOR_OPEN62451_SRC}"; }

function prep_vendors
{
    prep_uldaq;
    prep_open62541;
}

# Function: epics_env_support
# Description: Prepares the 'EPICS-env-support' module for a specified version
#              by calling the generic '_pre_support' function.
function epics_env_support { _fill_env; local version="$1"; _pre_support "$version" "${EPICS_ENV_SUPPORT_PATH}"; }


# Function: epics_env
# Description: Builds and installs the main EPICS environment by configuring
#              release paths, cleaning, patching, and then running a full build
#              and installation process.
function epics_env
{
    _fill_env;
    echo "--- Building EPICS environment ---"
    pushdd "$EPICS_ENV_PATH"
    echo "EPICS_TS_NTP_INET=tic.lbl.gov"         > configure/RELEASE.local
    echo "VENDOR_ULDAQ_PATH=${VENDOR_LIB_PATH}" >> configure/RELEASE.local
    echo 'OPEN62541_PATH=\$$\$$\(\_OPEN62541_CONFIG_OPCUA\)/../../../vendor'    >> configure/RELEASE.local
    make distclean   || exit
    make init        || exit
    make patch       || exit
    make conf        || exit
    # WHY: The build system reuses existing configuration files instead of overwriting them.
    # This can cause conflicts with stale configurations from previous Git commits.
    #
    # WHAT: Force a 'distclean' on all modules to remove old configurations
    # (e.g., CFG/CONFIG_OPCUA) and ensure a clean build state.
    # make clean.modules actually perform "make distclean" in each module source
	if [ -d "${EPICS_MODS_PATH}" ]; then
		make clean.modules || exit
	fi
    make conf        || exit
    make build.gz       || exit
    make install     || exit
    make symlinks    || exit
    popdd
}

# Function: epics_build
# Description: A generic function to build the EPICS environment using a
#              provided 'make' command. It handles setting up release paths
#              and entering the correct directory.
#   $1         : distclean, init, patch, conf, clean.modules, conf, build
#              : install, symlinks, and so on
function epics_build
{
    local cmd="$1";shift;
    _fill_env;
    echo "--- Building EPICS environment ---"
    pushdd "$EPICS_ENV_PATH"
    echo "EPICS_TS_NTP_INET=tic.lbl.gov"         > configure/RELEASE.local
    echo "VENDOR_ULDAQ_PATH=${VENDOR_LIB_PATH}" >> configure/RELEASE.local
    echo 'OPEN62541_PATH=\$$\$$\(\_OPEN62541_CONFIG_OPCUA\)/../../../vendor' >> configure/RELEASE.local
    make $cmd        || exit
    popdd
}

# Function: all
# Description: Performs a full, end-to-end setup, cloning all repositories,
#              preparing vendor libraries and support modules, and building the
#              main EPICS environment.
function all
{
    local version="$1"
    initial_setup "${version}"
    prep_vendors
    epics_env
    epics_env_support "${version}"
}

# Function: show_env
# Description: A public-facing function that calls _echo_env to display the
#              current environment variables.
function show_env {  _fill_env; _echo_env; }

# Function: check_deps
# Description: Runs the dependency checking script inside the EPICS environment
#              directory.
#   $1       : A flag or option to pass to the check_deps.bash script.
#              only one option -v
function check_deps
{
    local opt="$1";shift;
    _fill_env;
    pushdd "$EPICS_ENV_PATH"
    bash tools/check_deps.bash $opt || exit
    popdd
}

# Function: usage
# Description: Displays the usage information and available commands for the script.
# Returns: 1 to indicate an error, and the script will exit
function usage
{
   cat << EOF

Usage: ${0##*/} <command> [<version>]

Commands:
  init                - Prepare the environment installation
  help                - Displays this help message.
  prep-uldaq          - Prepare uldaq
  prep-open62451      - Prepare open62451
  prep-vendors        - Prepare uldaq and open65451
  epics-env           - Setup EPICS-env
  epics-env-support   - Setup EPICS-env-support
  epics-build         - Build EPICS with a custom make command
  show-env            - Display current environment variables
  check-deps          - Check EPICS environment dependencies
  all                 - init, prep-vendors,
                        epics-env, epics-env-support

Example:
  # Perform a full build for version 1.1.2
  bash ${0##*/} all 1.1.2

  # Just clone the repositories
  bash ${0##*/} init

  # Build EPICS with custom make commands
  # ,which are defined in EPICS-env (for troubleshooting)
  bash ${0##*/} epics-build vars
  bash ${0##*/} epics-build exist

EOF
    exit 1;
}

if [ "$#" -eq 0 ]; then
    usage
fi

COMMAND="$1"
SRC_VER="$2"
func_name="${COMMAND//-/_}"

if [ -z "$SRC_VER" ]; then
    SRC_VER="master"
fi

case "$COMMAND" in
    init)
        initial_setup "${SRC_VER}"
        ;;
    help)
        usage
        ;;
    epics-env-support)
        # Check if the function actually exists before calling it
        if declare -F "$func_name" > /dev/null; then
            "$func_name" "$SRC_VER"
        else
            echo "Error: Internal script error - function '$func_name' not found." >&2
            exit 1
        fi
        ;;
    prep-uldaq|prep-open62541|prep-vendors|epics-env|show-env)
        if declare -F "$func_name" > /dev/null; then
            "$func_name"
        else
            echo "Error: Internal script error - function '$func_name' not found." >&2
            exit 1
        fi
        ;;
     epics-build)
        if [ -z "$2" ]; then
            echo "Error: $COMMAND command requires a make command as a second argument." >&2
            usage
            exit 1
        fi
        if declare -F "$func_name" > /dev/null; then
            "$func_name" "$2";
        else
            echo "Error: Internal script error - function '$func_name' not found." >&2
            exit 1
        fi
        ;;
     check-deps)
        if declare -F "$func_name" > /dev/null; then
            "$func_name" "$2";
        else
            echo "Error: Internal script error - function '$func_name' not found." >&2
            exit 1
        fi
        ;;
    all)
        all "${SRC_VER}"
        echo "--- All tasks completed successfully for version ${SRC_VER} ---"
        ;;
    OS)
        if is_redhat_variant; then
            echo "Error: This system is an ugly Red Hat variant."
        else
            echo "Whoray! This system is not a Red Hat variant."
        fi
        ;;
    *)
        echo "Error: Unknown command '$COMMAND'" >&2
        usage
        ;;
esac

