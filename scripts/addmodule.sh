#!/usr/bin/bash

WORKING_DIR=$(pwd)
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

mkdir "$WORKING_DIR/$1"
mkdir "$WORKING_DIR/$1/inc"
mkdir "$WORKING_DIR/$1/src"
mkdir "$WORKING_DIR/$1/bin"
touch "$WORKING_DIR/$1/inc/lib.h"
echo "#include \"../inc/lib.h\"" > "$WORKING_DIR/$1/src/lib.c"
echo "#include \"inc/lib.h\"" > "$WORKING_DIR/$1/$1.c"


sed "s/<<target>>/$1/" "$SCRIPT_DIR/Makefile_template" > "$WORKING_DIR/$1/Makefile"
