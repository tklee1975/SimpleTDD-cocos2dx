#!/usr/bin/python

# -------------------------------
# Convert the Test based on TDDTest to TDDBaseTest
#
# Usage: convertTest.py <your_test.h>
#
# Example: ./script/convertTest.py ../NewGame/UnitTest/SpriteTest.h
#
# ---------------------------------------

import os
import sys
import shutil           # for file copy

def check_and_make_parent(parent_dir):
  #print("parent: %s", parent_dir)
  if(os.path.exists(parent_dir) == False):
    os.makedirs(parent_dir)
#end


## Copy File
def copy_file(src_file, dst_file):

  # check for the parent folder
  check_and_make_parent(os.path.dirname(dst_file))

  # copy the file
  shutil.copy(src_file, dst_file)

  return
#end

## Read file
def read_file(file):
    fo = open(file, "r")
    str = fo.read()
    return str
#end

## writefile
def write_file(file, content):
    fo = open(file, "w")
    fo.write(content)
    fo.close()
#end

## Setup the TDD Library
def setup_tdd_library():
  print("Setup SimpleTDD Library")
  src_dir = os.path.join(main_dir, "Classes/SimpleTDD");
  dst_dir = os.path.join(project_dir, "Classes/SimpleTDD");
  print("src: %s" % src_dir)
  print("dst: %s" % dst_dir)

  for path, dirs, files in os.walk(src_dir):
    for name in files:
      # print("name: %s" % name)
      src_file = os.path.join(path, name)

      #dst_file = os.path.join(dst_dir, name)
      #print("src: %s" % src_file)
      #print("dst: %s" % dst_file)
      copy_file(src_file, dst_dir)


  return
# End

def setupFiles(inputFile):
    global headerFile, sourceFile
    global headerBackup, sourceBackup

    headerFile = inputFile
    sourceFile = headerFile.replace(".h", ".cpp")
    headerBackup = headerFile + ".bak"
    sourceBackup = sourceFile + ".bak"


    print "header=[%s] source=[%s]" % (headerFile, sourceFile)
    print "backup: header=[%s] source=[%s]" % (headerBackup, sourceBackup)

def isConverted(inputFile):
    content = read_file(inputFile)

    return "TDDBaseTest" in content

def hasOrigin(currentFile, backupFile):
    if isConverted(currentFile) == False:
        return True

    if os.path.exists(backupFile) == False:
        return False

    return isConverted(backupFile) == False

def checkInput():
    global headerFile, sourceFile

    # Check for Header
    if os.path.exists(headerFile) == False:
        print "the unit test header is missing. file=%s" % headerFile
        return False

    # Check for Source
    if os.path.exists(sourceFile) == False:
        print "the unit test source is missing. file=%s" % sourceFile
        return False

    if hasOrigin(headerFile, headerBackup) == False:
        print "No origin copy of header file"
        return False;

    if hasOrigin(sourceFile, sourceBackup) == False:
        print "No origin copy of source file"
        return False;

    return True

def backup():
    global headerFile, sourceFile
    global headerBackup, sourceBackup

    # backup if the headerFile is still the original
    if isConverted(headerFile) == False:
        copy_file(headerFile, headerBackup)

    if isConverted(sourceFile) == False:
        copy_file(sourceFile, sourceBackup)

def convertHeader():
    global headerFile, headerBackup

    content = read_file(headerBackup)

    convertList = [
        ["\"TDDTest.h\"", "\"TDDBaseTest.h\""],
        ["public TDDTest", "public TDDBaseTest"],
        ["setSubTest(Vector<MenuItem *> &menuArray);", "defineTests();"],
        ["(Ref *sender);", "();"]
    ]

    convertedContent = content

    for (fromStr, toStr) in convertList:
        convertedContent = convertedContent.replace(fromStr, toStr);

    #print "----\n%s\n------\n" % content
    #print "----\n%s\n------\n" % convertedContent

    # Output the file
    write_file(headerFile, convertedContent)

def convertSource():
    global sourceFile, sourceBackup

    filename = os.path.basename(sourceFile)
    classname = filename.replace(".cpp", "")

    print "name=%s class=%s" % (filename, classname)

    content = read_file(sourceBackup)
    #
    convertList = [
        ["SUBTEST(" + classname + "::", "ADD_TEST("],
        ["setSubTest(Vector<MenuItem *> &menuArray)", "defineTests()"],
        ["(Ref *sender)", "()"]
    ]

    #
    convertedContent = content

    for (fromStr, toStr) in convertList:
        convertedContent = convertedContent.replace(fromStr, toStr);

    #print "----\n%s\n------\n" % content
    #print "----\n%s\n------\n" % convertedContent

    # Output the file
    write_file(sourceFile, convertedContent)

def showConvertNote():
    global headerFile, sourceFile
    global headerBackup, headerBackup

    #print "Converted Files:\n%s\n%s\n" % (headerFile, sourceFile)
    #print "Backup:\n%s\n%s\n" % (headerBackup, headerBackup)
    print "\nAfter the conversion, the test may cause build errors.\n"\
            "Suggest to 'KEEP the backup files' until 'build success'.\n"


def testArray():
    myArray = [
        ["a", "apple"],
        ["b", "boy"],
    ];

    print "Testing 2D Array"
    for (v1, v2) in myArray:
        print "v1=%s v2=%s" % (v1, v2)

    myMap = {
        "a" : "apple",
        "b" : "boy",
    };

    for key in myMap:
        value = myMap[key]
        print "k=%s v=%s" % (key, value)

def testIsConverted():


    fileList = [
        "./script/sample/ButtonTest.h",
        "./script/sample/ButtonTest.cpp",
        "./script/sample/ButtonTest.h.bak",
        "./script/sample/ButtonTest.cpp.bak",
    ]

    for file in fileList:
        print "%s converted=%s" % (file, isConverted(file))

def test():
    # testArray()
    #testIsConverted();
    showConvertNote();

doTest = False

if doTest:
    test();
    quit()

# Main
#   Core Logic
#    - Find the targetHeader and targetSource
#    - Prompt if the file is missing
#    - Backup
#    - modify the header file
#    - modify the source file
#
# -------------- main --------------
if len(sys.argv) <= 1:
  print("Usage:")
  print("%s (your_unit_test.h)" % sys.argv[0])
  quit()

setupFiles(sys.argv[1])
if checkInput() == False:
    quit()

backup()

convertHeader()
convertSource()
showConvertNote()

#
# target_file = sys.argv[1]
# script_dir = os.path.dirname(os.path.realpath(__file__))
# main_dir = os.path.dirname(script_dir)
#
# print("prj: %s script: %s main: %s" % (project_dir, script_dir, main_dir))
#
# if(os.path.exists(project_dir) == False):
#   print("Note: project dir not exists. [%s]" % source_path)
#
# setup_tdd_library()
