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

//	virtual bool showStat();
//	void setMenuVisible(bool flag);

//




//	virtual void setSubTest(Vector<MenuItem *> &menuArray);
//	void addSubTestMenu(Vector<MenuItem *> &menuArray, const char *name, const ccMenuCallback& callback);
//	void hideMenu();
//	void hideToolBar();
//
//	void setToolBarOpacity(GLubyte value);


#pragma mark - Helper Method
private:
	void setupGUI();
	TDDTestMenu *createTestMenu();
	void back();


	void findBaseNode();

//	void configTest();
//	void resetConfig();
//	void sampleTest(Ref *sender);

//	Menu *createBackMenu();
//	Menu *createToggleMenu();

//
//	void setupControlLayer();
//	void setupSubMenu(Layer *parent);		// New UI
//	void setupToolbar(Layer *parent);		// Old UI
//	LayerColor *createToolBarLayer(bool hasMenu);
//	TDDMenu *createTDDMenu();
//	void toggleMenu(Ref *sender);
//	void toggleStat(Ref *sender);
//	void backToSuite(Ref *sender);
//	void addToggleStatMenuItem(Vector<MenuItem *> &menuArray);
//	void onBackPressed(Ref *sender, Control::EventType controlEvent);

	// private data
private:
//	Layer *mControlLayer;	// Core control layer contains ToolBar & SubTest Menu
//	LayerColor *mBackLayer;		// Background Layer, default color is GRAY
//	LayerColor *mToolBarLayer;
//	TDDMenu *mTDDMenu;
//	bool mMenuVisible;
	TDDTestMenu *mTestMenu;
	LayerColor *mBackLayer;		// Background Layer, default color is GRAY
	Node *mBaseNode;

private:
	std::vector<std::string> mTestNameList;
	std::map<std::string, std::function<void()>> mTestCallbackMap;

};



#endif /* TDDBaseTest_hpp */

#endif
