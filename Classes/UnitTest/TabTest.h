#ifdef ENABLE_TDD
//
//  TabTest.h
//
//
#ifndef __TDD_TabTest__
#define __TDD_TabTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class TabTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testSimple();
	void testCallback();
}; 

#endif

#endif
