#ifdef ENABLE_TDD
//
//  TDDSubMenuTest.h
//
//
#ifndef __TDD_TDDSubMenuTest__
#define __TDD_TDDSubMenuTest__

// Include Header

#include "TDDBaseTest.h"

class TDDSubMenu;

// Class Declaration 
class TDDSubMenuTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void subTest();
	void testMenu();
	
	void onBackPressed(Ref *sender, Control::EventType controlEvent);


private:
	TDDSubMenu *mMenu;
};

#endif

#endif
