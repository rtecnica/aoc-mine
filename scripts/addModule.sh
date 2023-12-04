#!/usr/bin/bash

WORKING_DIR=$(pwd)
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

$SCRIPT_DIR/addmodule.sh c
stack new h
mkdir r
cd r
cargo init
cd ..

