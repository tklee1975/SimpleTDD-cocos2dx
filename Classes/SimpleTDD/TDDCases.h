//
//  TDDDefine.h
//  TDDLib
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifdef ENABLE_TDD
#ifndef TDDLib_TDDDefine_h
#define TDDLib_TDDDefine_h

#include "TDDTypes.h"
#include "TDDTest.h"		// contain the data structure


// MACRO

// ADD_CASE will be used in MyTDDCases.h
#define TEST(__ClassName__)		 			{#__ClassName__, []() { return new __ClassName__(); } }

#define TDD_CASES								TDDTestCase gTestArray[] =

// Definition of the Unit Test Cases by users
#include "MyTDDCases.h"



#endif
#endif