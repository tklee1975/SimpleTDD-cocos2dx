#!/bin/sh
# ----------------------------------------
# Generate a UnitTest cpp source
#
# Usage: <folder> <TestName>
#
# Example: 
# input: CCAction
# Output file will be: src/../UnitTest/CCActionTest.cpp
#
# Author: kenlee
# ----------------------------------------

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT_DIR=$SCRIPT_DIR/..


LIB_DIR=Classes/TDDLib/
MASTER_TDDLIB_DIR=$ROOT_DIR/../Cocos2dxTDDLib/$LIB_DIR
MY_TDDLIB_DIR=$ROOT_DIR/$LIB_DIR

echo "MASTER_TDDLIB_DIR=$MASTER_TDDLIB_DIR"
echo "MY_TDDLIB_DIR=$MY_TDDLIB_DIR"

cp $MASTER_TDDLIB_DIR/*.* $MY_TDDLIB_DIR
