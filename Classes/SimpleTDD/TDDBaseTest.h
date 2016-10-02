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

#define TDD_ASSERT_EQ(__expect__, __actual__, __remark__)\
		assertEquals(__FILE__, __LINE__, __expect__, __actual__, __remark__)

#define TDD_ASSERT_TRUE(__cond__, __remark__)	\
		assertTrue(__FILE__, __LINE__, __cond__, __remark__)

class TDDTestMenu;
class TDDConsoleView;

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

private:
	bool isCoreNode(Node *node);		// Core node mean the node that required by BaseTest
	
#pragma mark - Menu customization
protected:
	void setMenuPostion(const Vec2 &pos);
	void setMenuSize(const Size &size);
	void setMenuSizeByPercent(const Vec2 &percent);	// using 0.0 ~ 1.0
	void setMenuWidth(const float &width);
	void setMenuHeight(const float &height);
	void alignMenu(const TDDAlign &align);
	void setMenuColor(const Color4B &headerColor, const Color4B &bgColor);
	void setMenuTextColor(const Color3B &textColor);

	
#pragma mark - Console
protected:
	void setConsoleVisible(bool flag);
	void alignConsole(const TDDAlign &align);
	void logConsole(const char * format, ...);
	
	// void setMenuPostion(const Vec2 &pos);
	
	
private:
	TDDConsoleView *mConsoleView;
	Size mConsoleSize;
	TDDAlign mConsoleAlign;
	
	
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
	
#pragma mark - Test Info
public:
	std::string getTestName();
	
private:
	std::string mCurrentTestName;
	
#pragma mark - Assertion Logic
protected:
	void assertTrue(const std::string &file, int line, bool cond, const std::string &remark="");
	void assertEquals(const std::string &file, int line,
						int expect, int actual, const std::string &remark="");
	void assertEquals(const std::string &file, int line,
						float expect, float actual, const std::string &remark);
	void assertEquals(const std::string &file, int line,
						double expect, double actual, const std::string &remark="");
	void assertEquals(const std::string &file, int line,
						long expect, long actual, const std::string &remark="");
	void assertEquals(const std::string &file, int line,
						bool expect, bool actual, const std::string &remark="");
	
	
	// every will call this!
	void doAssertLogic(const std::string &file, int line, const std::string &remark,
					   bool isPassed, const std::string &result);
	
	CC_SYNTHESIZE(bool, mBreakWhenFail, BreakWhenFail);
};



#endif /* TDDBaseTest_hpp */

#endif
