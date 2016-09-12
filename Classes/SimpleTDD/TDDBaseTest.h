#ifdef ENABLE_TDD
//
//  TDDBaseTest.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 24/8/2016.
//
//

#ifndef TDDBaseTest_hpp
#define TDDBaseTest_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

#include "TDDTypes.h"

USING_NS_CC;
USING_NS_CC_EXT;


// Macro
#define ADD_TEST(__method__)	addTest(#__method__, [&]() { __method__(); });

class TDDTestMenu;

// Note:
//		call sequence of TDDBaseTest
//			 start up: constructor -> onEnter -> defineTest -> setupGUI -> setUpd
//			 user click the test: willRunTest -> test -> didRunTest
//			 shut down: onExit -> tearDown -> destructor
//

class TDDBaseTest : public Scene
{

public:
	TDDBaseTest();
	virtual void onEnter();
	virtual void onExit();

#pragma mark - Core Method for override
protected:

	// For
	virtual void setUp();
	virtual void tearDown();

	virtual void defineTests() = 0;		// Required to override

	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test

#pragma mark - Core Method for testing
	void addTest(const std::string &name, const std::function<void()> &callback);
	void doTestCallback(const std::string &name);


#pragma mark - Helper Method for build the test
protected:
	void setBackgroundColor(const Color3B &color);
	void clearChildren();

	// Method available in TDDTest (old version)
	void toggleStat();
	void hideMenu();
	void setMenuVisible(bool flag);
	void clearNodes();

	
#pragma mark - For customization
	void setMenuPostion(const Vec2 &pos);
	void setMenuSize(const Size &size);
	
#pragma mark - Helper Method
private:
	void setupGUI();
	TDDTestMenu *createTestMenu();
	void back();
	void findBaseNode();
private:
	TDDTestMenu *mTestMenu;
	LayerColor *mBackLayer;		// Background Layer, default color is GRAY
	Node *mBaseNode;

private:
	std::vector<std::string> mTestNameList;
	std::map<std::string, std::function<void()>> mTestCallbackMap;
	
	TDDAlign mMenuAlign;
};



#endif /* TDDBaseTest_hpp */

#endif
