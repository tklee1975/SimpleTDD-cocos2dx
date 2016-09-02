#ifdef ENABLE_TDD
//
//  TDDHelperTest.h
//
//
#ifndef __TDD_TDDHelperTest__
#define __TDD_TDDHelperTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
//class TDDHelperTest : public TDDTest
class TDDHelperTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
	Menu *createMenuWithFont(int numitem, const char *font, int fontSize, const Color3B &color);
	Menu *createMenu(int numitem);
private:
	void testCreateEditBox();
	void testAlignMenuItem();
	void testMenuItemFont();
	void testColor();
	void testTrimString();
	void testReplaceString();
	void testCreateLabel();
	void testSplitString();
	void testJoinString();
	void testAddButtonWithBg();
	void testResolveAlign();
	void testAlignNode();
}; 

#endif

#endif
