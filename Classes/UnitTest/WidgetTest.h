#ifdef ENABLE_TDD
//
//  WidgetTest.h
//
//
#ifndef __TDD_WidgetTest__
#define __TDD_WidgetTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class WidgetTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testButton();
}; 

#endif

#endif
