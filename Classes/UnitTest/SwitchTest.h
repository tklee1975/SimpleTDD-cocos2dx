#ifdef ENABLE_TDD
//
//  SwitchTest.h
//
//
#ifndef __TDD_SwitchTest__
#define __TDD_SwitchTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class SwitchTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testSimple();
}; 

#endif

#endif
