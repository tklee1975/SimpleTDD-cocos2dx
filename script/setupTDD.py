#!/usr/bin/python

# -------------------------------
# Setup the TDD for other project
# 
# Usage: setupTDD.py cocos_project_dir 
#
# Example: ./script/setupTDD.py ../NewGame/ 
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
  check_and_make_parent(dst_file)

  # copy the file
  shutil.copy(src_file, dst_file)

  return
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

## Setup the UnitTest Folder
def setup_test_folder():
  print("Setup Unit Test Folder")
  
  name = "MyTDDCases.h"
  
  src_file = os.path.join(main_dir, "script/template", name)
  dst_path = os.path.join(project_dir, "Classes/UnitTest")
  
  print("src: %s" % src_file)
  print("dst: %s" % dst_path)
  
  copy_file(src_file, dst_path)
  
  return
# End

## Setup the Script Folder
#
# 
def setup_script_folder():
  print("Setup Script Folder")
  
  src_dir = os.path.join(main_dir, "script");
  dst_dir = os.path.join(project_dir, "script");
  print("src: %s" % src_dir)
  print("dst: %s" % dst_dir)
  
  for path, dirs, files in os.walk(src_dir):
    print("path: %s" % path)
    for name in files:
       #print("name: %s" % name)
       
       src_file = os.path.join(path, name)
       dst_path = os.path.dirname(src_file.replace(src_dir, dst_dir))
       
       #print("src_file: %s" % src_file)
       #print("dst_path: %s" % dst_path)
       copy_file(src_file, dst_path)
  
  return
# End

# Main
# -------------- main --------------
if len(sys.argv) <= 1:
  print("Usage:")
  print("%s (project_dir)" % sys.argv[0])
  quit()

project_dir = sys.argv[1]
script_dir = os.path.dirname(os.path.realpath(__file__))
main_dir = os.path.dirname(script_dir)

print("prj: %s script: %s main: %s" % (project_dir, script_dir, main_dir))

if(os.path.exists(project_dir) == False):
  print("Note: project dir not exists. [%s]" % source_path)

setup_tdd_library()
setup_test_folder()
setup_script_folder()



