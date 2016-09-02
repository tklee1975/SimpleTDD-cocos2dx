//
//  TDDMainLayer.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 13/8/2016.
//
//
#ifdef ENABLE_TDD

#ifndef TDDMainLayer_hpp
#define TDDMainLayer_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

#include "TDDTable.h"
#include "TDDTypes.h"

class TDDTopBar;

// The layer contains the TopBar and TDDTable
class TDDMainLayer : public LayerColor, public TDDTableDelegate
{
public:
	static Scene *createScene();
	
	CREATE_FUNC(TDDMainLayer);
	TDDMainLayer();
	~TDDMainLayer();
	bool init();		// simple init
	
	virtual void onEnter();
	virtual void onExit();
	
	// Property (Theme)
	CC_SYNTHESIZE(Color4B, mBackgroundColor, BackgroundColor);
	CC_SYNTHESIZE(Color3B, mTableTextColor, TableTextColor);
	CC_SYNTHESIZE(int, mTableFontSize, TableFontSize);
	CC_SYNTHESIZE(int, mColumn, Column);
	
#pragma mark - setting up GUI
protected:
	void setupGUI();	// call after theme setting
	void setupTopBar(const Size &size, const Vec2 &pos);
	void setupTestTable(const Size &size, const Vec2 &pos);
	void setupStatusBar(const Size &size, const Vec2 &pos);
	
#pragma mark - Core Logic
private:
	void setupProperties();
	void setupData();
	std::string getTestName(int index);

	
	void updateKeyword(const std::string &keyword);
	void updateResult(std::vector<std::string> &result);
	
	void showAllTest(const std::string &keyword);
	void showRecentTest(const std::string &keyword);
	
	void handleClose();
	void handleAllTab();
	void handleRecentTab();
	void handleSearchKeyChanged(const std::string &keyword);
	
	void updateTestCount(int searchCount);
	
	void runTest(const std::string &test);
	
#pragma mark - TDDTableDelegate
private:
	virtual int getTableCellCount();
	virtual Size getTableCellSize();
	virtual Node *tableCellForIndex(int index);

private:
	//
	TDDSearchType mSearchType;
	std::string mKeyword;
	std::vector<std::string> mResultList;
	
	//
	Size mTableCellSize;
	TDDTable *mResultTable;
	TDDTopBar *mTopBar;
	
	LayerColor *mStatusLayer;
	Label *mCountLabel;
	
	bool mWasShowStat;
};

#endif /* TDDMainLayer_hpp */

#endif