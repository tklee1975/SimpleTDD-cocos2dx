#ifdef ENABLE_TDD
//
//  SwitchTest.h
//
//
#ifndef __TDD_SwitchTest__
#define __TDD_SwitchTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class SwitchTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testSimple(Ref *sender);
}; 

#endif

#endif
