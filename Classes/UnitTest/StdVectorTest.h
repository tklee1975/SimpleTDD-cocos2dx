#ifdef ENABLE_TDD
//
//  StdVectorTest.h
//
//
#ifndef __TDD_StdVectorTest__
#define __TDD_StdVectorTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class StdVectorTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testErase(Ref *sender);
}; 

#endif

#endif
