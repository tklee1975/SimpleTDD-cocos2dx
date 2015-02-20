#ifdef ENABLE_TDD
//
//  TDDHelperTest.h
//
//
#ifndef __TDD_TDDHelperTest__
#define __TDD_TDDHelperTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDHelperTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
	Menu *createMenuWithFont(int numitem, const char *font, int fontSize, const Color3B &color);
	Menu *createMenu(int numitem);
private:
	void testCreateEditBox(Ref *sender);
	void testAlignMenuItem(Ref *sender);
	void testMenuItemFont(Ref *sender);
	void testColor(Ref *sender);
	void testTrimString(Ref *sender);
	void testReplaceString(Ref *sender);
	void testCreateLabel(Ref *sender);
	void testSplitString(Ref *sender);
	void testJoinString(Ref *sender);
}; 

#endif

#endif
