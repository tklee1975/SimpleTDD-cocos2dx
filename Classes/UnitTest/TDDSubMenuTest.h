#ifdef ENABLE_TDD
//
//  TDDSubMenuTest.h
//
//
#ifndef __TDD_TDDSubMenuTest__
#define __TDD_TDDSubMenuTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDSubMenuTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testMenu(Ref *sender);
	
	void onBackPressed(Ref *sender, Control::EventType controlEvent);
}; 

#endif

#endif
