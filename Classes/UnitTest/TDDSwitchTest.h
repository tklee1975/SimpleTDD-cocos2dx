#ifdef ENABLE_TDD
//
//  TDDSwitchTest.h
//
//
#ifndef __TDD_TDDSwitchTest__
#define __TDD_TDDSwitchTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDSwitchTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testMoveSwitch(Ref *sender);
	void testSetSwitches(Ref *sender);
	void switchSelected(Ref *sender, std::string name, int selected);
	void testThreeSwitch(Ref *sender);
}; 

#endif

#endif
