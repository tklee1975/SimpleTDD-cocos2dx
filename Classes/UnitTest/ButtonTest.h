#ifdef ENABLE_TDD
//
//  ButtonTest.h
//
//
#ifndef __TDD_ButtonTest__
#define __TDD_ButtonTest__

// Include Header

#include "TDDBaseTest.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

// Class Declaration 
class ButtonTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
	
	const Size alignMenuItem(Menu *menu);
private:
	Menu *createMenu(int numitem);
	
	void onMenuSelected(Ref *caller);
	
	void testButtonClick();
	
	void testMenuLayout();
	void testMenuStyle();
	void testAlighColumn();
	void testAlignItems();
	void testAlignItemsWithScroll();
	void testControlButton();
	void testButtonColor();
	void testButtonStyle();
	//void testControlButton();
	
	void setButtonSelected(Ref *sender, Control::EventType controlEvent);
	void touchUpInsideAction(Ref *sender, Control::EventType controlEvent);
}; 

#endif

#endif
