#ifdef ENABLE_TDD
//
//  ScrollViewTest.h
//
//
#ifndef __TDD_ScrollViewTest__
#define __TDD_ScrollViewTest__

// Include Header

#include "TDDBaseTest.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

// Class Declaration 
class ScrollViewTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void subTest();
	void testFromTop();
	void testScrollTop();
	void testScrollBottom();
private:
	cocos2d::extension::ScrollView *mScrollView;
	Layer *mScrollContent;
}; 

#endif

#endif
