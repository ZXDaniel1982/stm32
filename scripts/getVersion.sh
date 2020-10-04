#!/bin/bash

ROOT=$(dirname "$0")
BASE_DIR="$ROOT/../"
MANAGER_DIR="$BASE_DIR/stm32_manager/"
MANAGER_FILE="$MANAGER_DIR/stm32mgr"

#
# fail if the image does not exist
#
if [ ! -f "$MANAGER_FILE" ] ; then
    echo "$ERROR \"$MANAGER_FILE\" does not exist"
    exit 1
fi

$MANAGER_FILE getversion
