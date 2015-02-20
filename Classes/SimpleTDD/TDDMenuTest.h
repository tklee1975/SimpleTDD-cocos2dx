#ifdef ENABLE_TDD
//
//  TDDMenuTest.h
//
//
#ifndef __TDD_TDDMenuTest__
#define __TDD_TDDMenuTest__

// Include Header

#include "TDDTest.h"

// Forward Declaration
class TDDMenu;

// Class Declaration 
class TDDMenuTest : public TDDTest
{
	virtual void setUp();
	virtual void tearDown();
	
private:
	void callback(Ref * sender);
	
private:
	TDDMenu *mMenu;
	Vector<MenuItem *> mMenuArray;
}; 

#endif

#endif