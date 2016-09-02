#ifdef ENABLE_TDD
//
//  TDDManagerTest.h
//
//
#ifndef __TDD_TDDManagerTest__
#define __TDD_TDDManagerTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDManagerTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testLoadTest(Ref *sender);
	void testRunTest(Ref *sender);
	void testGetTestList(Ref *sender);
}; 

#endif

#endif
