//
//  TTDSuite.h
//  TDDLib
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef __TDDLib__TTDSuite__
#define __TDDLib__TTDSuite__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <vector>
#include <string>
#include "TDDTypes.h"

USING_NS_CC_EXT;

USING_NS_CC;

class TDDMenu;


class TDDSuiteScene : public Scene
{
public:
	TDDSuiteScene();
    ~TDDSuiteScene();
	
	virtual void onEnter();
	virtual void onExit();
	
private:
	bool hasStat;
	bool mHasSetup;
};

class TDDSuiteLayer : public Layer,
				public cocos2d::extension::EditBoxDelegate
{
public:

public:
    TDDSuiteLayer();
    ~TDDSuiteLayer();

	void goBack(Ref *sender);
	void filterTest(Ref *sender);
	void menuCallback(Ref *sender);
	void runTest(int testIdx);
	
#pragma mark -
#pragma mark Private Data
// Private Data
private:
    Point mBeginPos;
	TDDMenu *mTestMenu;
	EditBox *mEditFilter;
	Menu *mClearMenu;
	int mFilterCount;
	Label *mStatusLeftLabel;
	std::vector<std::string> mDisplayTest;
	TDDMenuMode mMode;
	
	
#pragma mark -
#pragma mark Private Method
	void setupTestMenu();
	void setupToolBar();
	void refreshTestMenu();
	const char *getFilterName();
	Layer *createToolBarLayer();	// Tool Bar
	void createMenuItemArray(const std::vector<int> &testIndices, Vector<MenuItem *> &menuArray);
	void createTestMenuItemArray(const std::vector<std::string> &testNames,
												Vector<MenuItem *> &menuArray);
	
	void clearHistory(Ref * sender);
	
	Layer *createStatusBarLayer();
	void setupStatusBar();
	void updateStatusBar();
	
	// public cocos2d::extension::EditBoxDelegate
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
	virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);

	void switchSelected(Ref *sender, std::string name, int selected);
	
	void setDisplayTestWithFilter();
	void setDisplayTestWithFilter(const std::string &filter);
	void setDisplayTestWithHistory();
	int getTestIndexByName(const std::string &name);
	std::string getDisplayTestNameByIndex(int index);
	
	int getTotalTestCount();
	int getFilteredTestCount();
};


#endif /* defined(__Dg__TTDSuite__) */
