#ifdef ENABLE_TDD
//
//  ScrollTest.h
//
//
#ifndef __TDD_ScrollTest__
#define __TDD_ScrollTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class ScrollTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void subTest();
}; 

#endif

#endif
