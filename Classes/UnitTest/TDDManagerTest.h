#ifdef ENABLE_TDD
//
//  TDDManagerTest.h
//
//
#ifndef __TDD_TDDManagerTest__
#define __TDD_TDDManagerTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class TDDManagerTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testLoadTest();
	void testRunTest();
	void testGetTestList();
}; 

#endif

#endif
