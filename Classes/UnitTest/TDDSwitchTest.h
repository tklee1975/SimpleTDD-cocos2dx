#ifdef ENABLE_TDD
//
//  TDDSwitchTest.h
//
//
#ifndef __TDD_TDDSwitchTest__
#define __TDD_TDDSwitchTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class TDDSwitchTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void subTest();
	void testMoveSwitch();
	void testSetSwitches();
	void switchSelected(Ref *sender, std::string name, int selected);
	void testThreeSwitch();
}; 

#endif

#endif
