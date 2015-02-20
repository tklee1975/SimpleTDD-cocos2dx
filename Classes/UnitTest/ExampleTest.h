#ifdef ENABLE_TDD
//
//  ExampleTest.h
//
//
#ifndef __TDD_ExampleTest__
#define __TDD_ExampleTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class ExampleTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testLabel(Ref *sender);
	void testSprite(Ref *sender);
}; 

#endif

#endif
