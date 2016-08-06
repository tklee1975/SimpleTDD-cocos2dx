#ifdef ENABLE_TDD
//
//  TabTest.h
//
//
#ifndef __TDD_TabTest__
#define __TDD_TabTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TabTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testSimple(Ref *sender);
	void testCallback(Ref *sender);
}; 

#endif

#endif
