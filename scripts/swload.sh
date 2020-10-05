#!/bin/bash

ROOT=$(dirname "$0")
BASE_DIR="$ROOT/../"
MANAGER_DIR="$BASE_DIR/stm32_manager/"
MANAGER_FILE="$MANAGER_DIR/stm32mgr"

print_update () {
    echo "[32m $1[0m"
}

#
# script usage
#
if [ $# -lt 2 ] ; then
    echo " Usage: $0 <device> <image> [-d|--dev-mode]"
    echo "   <device>: The block device that will be written to, e.g. /dev/mmcblk0"
    echo "   <image>: The BIN file that will be written, e.g. stm32app.bin"
    echo "   [-d|--dev-mode]: Enable development mode on the SD card"
    echo " Note: <device> must be either /dev/mmcblk{0-9} or /dev/sd{a-z}"
    exit 0
fi

#
# need pv
#
if ! command -v pv > /dev/null ; then
    echo "$ERROR please run \"sudo apt-get install pv\""
    exit 1
fi

#
# need stm32mgr
#
if ! command -v stm32mgr > /dev/null ; then
    echo "$ERROR please install stm32mgr"
    exit 1
fi

#
# parse the device argument
#
DEVICE=$1 ; shift
if [ ! "$DEVICE" =~ /dev/ttyUSB0 ] ; then
    echo "$ERROR \"$DEVICE\" is not a valid device"
    exit 1
fi

#
# parse the image argument
#
IMAGE=$1 ; shift
if [[ ! "$IMAGE" =~ \.bin$ ]] ; then
    echo "$ERROR \"$IMAGE\" is not a valid image"
    exit 1
fi

#
# parse the optional arguments
#
for arg in "$@" ; do
    case $arg in
        "-d"|"--dev-mode")
            DEV_MODE=1
            ;;
        *)
            echo "$ERROR \"$arg\" is not a valid option"
            exit 1
    esac
done

#
# fail if the device does not exist
#
if [ ! -b "$DEVICE" ] ; then
    echo "$ERROR \"$DEVICE\" does not exist"
    exit 1
fi

#
# fail if the image does not exist
#
if [ ! -f "$IMAGE" ] ; then
    echo "$ERROR \"$IMAGE\" does not exist"
    exit 1
fi

#
# Generate arg file
#
MANAGER_FILE sdimage $IMAGE

#
# fail if the image does not exist
#
if [ ! -f "$ARG_FILE" ] ; then
    echo "$ERROR \"$ARG_FILE\" does not exist"
    exit 1
fi

#
# Install image file
#
MANAGER_FILE install $IMAGE

