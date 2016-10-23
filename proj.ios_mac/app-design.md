Design of the Application 
============================

Mini Cocos2d version: v.3.10



Design Rule
----------------
- Cannot use "cocos studio" to build the gui; Reason: this causes the library not easy to install
- By default, we will use "System font" unless user define them 
- The usage of the framework should be as simple as possible, measured by the steps to build a new test
- The library is invisible in the release version (e.g not defined 'ENABLE_TDD')
- Use cocos2d data structure for cocos2d stuff, else use std data astructure 

Class Design
----------------
- SimpleTDD		: Facade class for user to access the library 
- TDDConstant	: Constant definition 
- TDDCases.h	: Will include MyTDDCases.h will build the gTestArray Array
- TDDHelper.h	: Helper  Class
- TDDData.h		: To Save / Load the history (it is singleton)
- TDDManager.h	: A singleton to manage the core logic of the Simple TDD
- UI Widget
	- TDDTopBar
	- TDDTable 
	- TDDTab 

Work Backlog (v 2.0.0)
------------------------------------------
- Save Recent / All search key - done

Completed Work Backlog (v 2.0.0)
------------------------------------------
- Improve the EditBox in TDDTopBar, replace using TextField 
- TDDMainLayer: Add Version 
- DDMainLayer: Add Result Count 
- TDDTable: No Result handling
- TDDTest: using Lamda to build the sub test 
- Testing: build in ios/release android
- Assertion Logic



