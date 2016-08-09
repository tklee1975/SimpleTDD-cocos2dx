#ifdef ENABLE_TDD
//
//  ScrollViewTest.h
//
//
#ifndef __TDD_ScrollViewTest__
#define __TDD_ScrollViewTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class ScrollViewTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testFromTop(Ref *sender);
}; 

#endif

#endif
