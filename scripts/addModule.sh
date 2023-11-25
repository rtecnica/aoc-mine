#!/usr/bin/bash

WORKING_DIR=$(pwd)
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &>/dev/null && pwd)

mkdir $1
cd $1
$SCRIPT_DIR/addmodule.sh c
mv $SCRIPT_DIR/.clang-format c/
stack new h
mkdir r
cd r
cargo init
cd ..
cd $WORKING_DIR
