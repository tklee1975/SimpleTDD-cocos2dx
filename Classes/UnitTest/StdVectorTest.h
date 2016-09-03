#ifdef ENABLE_TDD
//
//  StdVectorTest.h
//
//
#ifndef __TDD_StdVectorTest__
#define __TDD_StdVectorTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class StdVectorTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testErase();
}; 

#endif

#endif
