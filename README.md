SimpleTDD.ccx3: A TDD Framework for cocos2d-x 3.x 
==========================================================

(This README is composed in http://dillinger.io/)

SimpleTDD is a TDD framework that help making unit test easily for mobile application.

## Goal
* This project wanna help cocos2d-x developers make unit test easily so that we can develop in a Test Driven style. 

## Features

* Tests can be created easily 
* Tests can be filtered out
* Test History is kept so it is ease to redo the recent tests;

## Project Structure
* /script : The script to create a new test 
* /Classes : The example project source 
* /Classes/TDDLib : The TDDLib library source
* /Classes/UnitTest : Example Unit test


## How to setup in your project

### 0. Setup cocos2d-x 3.3 or above

Before using this library, make sure your cocos2d-x is ready.
Also make sure you have installed python, our script will use it.

### 1. Download the Library project 

Download our project at 
 * https://github.com/tklee1975/SimpleTDD-cocos2dx

### 2. Run the setup script
* Run the following command to setup SimpleTDD in your project
  ./script/setupTDD.py (your project path)
* This script will do the following things:
 * Copy the SimpleTDD library to your project
 * Copy the script of SimpleTDD to your project
 * Setup the Unit Test Folder 

### 3. Add the Library and Unit Test to your project

When setup is done, the following Sources folder will be added, 
They are:
* Classes/SimpleTDD
* Classes/UnitTest

### 4. Set the MACRO 'ENABLE_TDD'

As we don't want to let the unit test stuff affect the size of the release build, all the UnitTest code and most of the library are enclosed by the 'ENABLE_TDD' macro. The test will not be included if 'ENABLE_TDD' isn't defined. 

To turn the test code on, we need add the Marcro "ENABLE_TDD" definition to the compile setting. 

### 5. Add the Test Button

Unlike the way of most unit test framework, TDDLib will build with the main code; Thus, the unit tests are linked with the main code in Test build version. 

The way to do so is that add "test" button is placed on the Main View (e.g title scene or main scene) of the game. 

The code sample is: 

<pre>
TDDHelper::addTestButton(this, Point(visibleSize.width/2, 50)); 
</pre>

## How to add a new test

(note: we will use ExampleTest as the example of the new UnitTest)

### 1. Run the 'createTest' script 

* Go to the main folder e.g MyProject/
* Run the createTest.sh script  
 <pre>
 ./script/createTest.sh Example
 </pre>
  noted that the following files will be generated.

  - MyProject/Classes/UnitTest/ExampleTest.h
  - MyProject/Classes/UnitTest/ExampleTest.cpp


### 2. Add the new test class

* Add the new UnitTest header and source files to XCode
* For my preference, I will place them in a group called 'UnitTest'.

### 3. Create the MyTDDCases.h 

MyTDDCases.h is the your header defining the test cases you created.

This is the sample code 
<pre>
// include files
#include "ExampleTest.h"	// Test class header

// Test Class Definition 
TDD_CASES
{
	TEST(ExampleTest),	// Test class name
};
</pre>

To add a new test, just include your test class header and define it inside TDD_CASES block
 
 

### 4. Build and Run 
* Build (Cmd+B) and Run (Cmd + R) in Xcode. 


### 5. Adding test code

If the unit test is successfully added. you can place your test code inside.

#### 5.1 Using the sub test


Every Unit Test is designed to contain many sub tests to be invoked. Just add the sub test method and add the entry in the setSubTest method. 

The code sample are as follows:

* Add the sub test method 

<pre>
void ExampleTest::testSomethingNew(Ref *sender)
{
	log("testSomethingNew");
}
</pre>

* Add the entry in setSubTest method

<pre>
void ExampleTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(ExampleTest::testSomethingNew);
	SUBTEST(ExampleTest::testSprite);
}
</pre>


#### 5.2 Override the Unit Test content

Every Unit Test Class (TDDTest) is the sub class of Scene. So it can do everything you expect to be done in Scene. But the different is that TDDTest will run 'setUp' after the Scene is loaded and 'tearDown' below the Scene is removed. 

So, we can setup a custom testing UI at the setUp logic to fit the test environment we needed.

(note: build an example in the future)

## Future Development
* Document:
    * Tutorial #1: Setup TDDLib
    * Tutorial #2: Very simple unit test
* Feature: 
    * Beautify the UI
    * More compact subtest menu
    * Clear the current filtering keyword
* Sample Code
    * Custom Test UI. e.g particle test with setting sliders










