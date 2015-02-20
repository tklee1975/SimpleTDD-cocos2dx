#ifdef ENABLE_TDD
//
//  ScrollTest.h
//
//
#ifndef __TDD_ScrollTest__
#define __TDD_ScrollTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class ScrollTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
}; 

#endif

#endif
