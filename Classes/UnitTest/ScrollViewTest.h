#ifdef ENABLE_TDD
//
//  ScrollViewTest.h
//
//
#ifndef __TDD_ScrollViewTest__
#define __TDD_ScrollViewTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class ScrollViewTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void subTest();
	void testFromTop();
}; 

#endif

#endif
