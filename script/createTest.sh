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
SRC_DIR=$ROOT_DIR/Classes/UnitTest

# Testing Dir
#TEST_SRC_DIR=$SCRIPT_DIR/test		

HEADER_TEMPLATE=$SCRIPT_DIR/template/test.h.template
SRC_TEMPLATE=$SCRIPT_DIR/template/test.cpp.template

echo "ROOT_DIR=$ROOT_DIR"
echo "SRC_DIR=$SRC_DIR"
echo "TEMPLATE=$TEMPLATE"

# Checking argument
if ([ $# -ne 1 ])
then
echo "Usage: $0 [Test Name]"
exit 0
fi

TEST_NAME=$1

# Prepare to create the test
SRC_FOLDER=${SRC_DIR}
SRC_FILE=$SRC_FOLDER/${TEST_NAME}Test.cpp
HEADER_FILE=$SRC_FOLDER/${TEST_NAME}Test.h

echo "Create test folder '$SRC_FOLDER'"
mkdir -p $SRC_FOLDER

# check if the out file exist
if [ -f $SRC_FILE ];
then
echo "Test '$SRC_FILE' already exists'"
exit
fi

if [ -f $HEADER_FILE ];
then
echo "Test '$HEADER_FILE' already exists'"
exit
fi


# Create the cpp
echo "Create Test cpp '$SRC_FILE'"
sed -e "s/\#TestName\#/$TEST_NAME/g" $SRC_TEMPLATE > $SRC_FILE

echo "Create Test header '$HEADER_FILE'"
sed -e "s/\#TestName\#/$TEST_NAME/g" $HEADER_TEMPLATE > $HEADER_FILE
