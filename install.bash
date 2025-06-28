#!/usr/bin/env bash
#
#  author  : Jeong Han Lee
#  email   : jeonghan.lee@gmail.com
#  version : 0.0.2

# We know 1.1.1 is ready,
# ${HOME}/epics is the clone folder of this environment

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

function pushdd { builtin pushd "$@" > /dev/null || exit; }
function popdd  { builtin popd  > /dev/null || exit; }

#
# EPICS-env / EPICS-env-support must have the same branch name
#
SRC_VER="$1";shift;
if [ -z "$SRC_VER" ]; then
    SRC_VER="master"
fi

# ${HOME}
pushdd ${HOME}
mkdir temp_folder
## temp_folder
pushdd temp_folder
rm -rf *

## EPICS-env, EPICS-env-support, and alsu-site-modules
## must be the same "branch" or "tag"
git clone git@github.com:jeonghanlee/EPICS-env.git
git clone git@github.com:jeonghanlee/EPICS-env-support.git
git clone git@github.com:jeonghanlee/uldaq-env.git

###
pushdd EPICS-env
git checkout "${SRC_VER}" || exit
echo "INSTALL_LOCATION=${SC_TOP}" > configure/CONFIG_SITE.local
OS_NAME=`make print-OS_NAME`
OS_VERSION=`make print-OS_VERSION`
INSTALL_LOCATION_EPICS=`make print-INSTALL_LOCATION_EPICS`
INSTALL_LOCATION_VER=`make print-INSTALL_LOCATION_VER`
popdd #### EPICS-env

EPICS_BASE_PATH=${INSTALL_LOCATION_EPICS}/base
VENDOR_LIB_PATH=${INSTALL_LOCATION_EPICS}/vendor

echo ${EPICS_BASE_PATH}
echo ${VENDOR_LIB_PATH}

echo "INSTALL_LOCATION=${VENDOR_LIB_PATH}" > uldaq-env/configure/CONFIG_SITE.local
make -C uldaq-env/ init || exit
make -C uldaq-env/ conf || exit
make -C uldaq-env/ build || exit
make -C uldaq-env/ install || exit


# git checkout 1.1.1
echo "EPICS_TS_NTP_INET=time1.google.com" > EPICS-env/configure/RELEASE.local
echo "VENDOR_ULDAQ_PATH=${VENDOR_LIB_PATH}" >> EPICS-env/configure/RELEASE.local
make -C EPICS-env/ init || exit
make -C EPICS-env/ patch || exit
make -C EPICS-env/ build.gz || exit
make -C EPICS-env/ install || exit
make -C EPICS-env/ symlinks || exit

###
pushdd EPICS-env-support
git checkout "${SRC_VER}" || exit
echo "INSTALL_LOCATION=${EPICS_BASE_PATH}" > configure/CONFIG_SITE.local
make init || exit
make conf || exit
make build.gz || exit
make symlinks || exit
popdd ### EPICS-env-support

popdd ## temp_folder

popdd # $HOME

scp -r ${SC_TOP}/epics/* .
rm -rf ${SC_TOP}/epics

