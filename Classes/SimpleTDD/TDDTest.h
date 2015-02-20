#ifdef ENABLE_TDD
//
//  TDDTest.h
//  TDDLib
//
//	Base Class of the Test Driven Unit Test
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef __TDDLib__TDDTest__
#define __TDDLib__TDDTest__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

#include "TDDTypes.h"

USING_NS_CC;
USING_NS_CC_EXT;


// Macro
#define SUBTEST(__Method__) addSubTestMenu(menuArray, #__Method__, CC_CALLBACK_1(__Method__, this));

// Forward class declaration
class TDDMenu;

class TDDTest : public Scene
{
public:
	TDDTest(bool portrait = true, bool physics = false);
    virtual void onEnter();
	virtual void onExit();
	
    // virtual void runTest() = 0;		// must implemented

	
	
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual bool showStat();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	void addSubTestMenu(Vector<MenuItem *> &menuArray, const char *name, const ccMenuCallback& callback);
	void hideMenu();
	void hideToolBar();
	void setMenuVisible(bool flag);
	void setToolBarOpacity(GLubyte value);
	void setBackgroundColor(const Color3B &color);

private:
	void setupGUI();
	void configTest();
	void resetConfig();
	void sampleTest(Ref *sender);
	
	Menu *createBackMenu();
	Menu *createToggleMenu();
	
	
	void setupControlLayer();
	void setupSubMenu(Layer *parent);		// New UI 
	void setupToolbar(Layer *parent);		// Old UI
	LayerColor *createToolBarLayer(bool hasMenu);
	TDDMenu *createTDDMenu();
	void toggleMenu(Ref *sender);
	void toggleStat(Ref *sender);
	void backToSuite(Ref *sender);
	void addToggleStatMenuItem(Vector<MenuItem *> &menuArray);
	void onBackPressed(Ref *sender, Control::EventType controlEvent);
	
// private data
private:
	Layer *mControlLayer;	// Core control layer contains ToolBar & SubTest Menu
	LayerColor *mBackLayer;		// Background Layer, default color is GRAY
	LayerColor *mToolBarLayer;
	TDDMenu *mTDDMenu;
	bool mMenuVisible;
};

// C++ 11
#define CL(__className__) [](){ return new __className__();}


typedef struct {
	const char *name;
	std::function<TDDTest *()> callback;
} TDDTestCase;


#endif /* defined(__Dg__TDDTest__) */
#endif