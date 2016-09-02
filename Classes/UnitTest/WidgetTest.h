#ifdef ENABLE_TDD
//
//  WidgetTest.h
//
//
#ifndef __TDD_WidgetTest__
#define __TDD_WidgetTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class WidgetTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testButton(Ref *sender);
}; 

#endif

#endif
