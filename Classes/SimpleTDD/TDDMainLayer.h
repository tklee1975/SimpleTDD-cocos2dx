//
//  TDDMainLayer.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 13/8/2016.
//
//

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

class TDDTopBar;

// The layer contains the TopBar and TDDTable
class TDDMainLayer : public LayerColor, public TDDTableDelegate
{
public:
	CREATE_FUNC(TDDMainLayer);
	TDDMainLayer();
	~TDDMainLayer();
	bool init();		// simple init
	
	void setupGUI();	// call after theme setting
	
	// Property (Theme)
	CC_SYNTHESIZE(Color4B, mBackgroundColor, BackgroundColor);
	CC_SYNTHESIZE(int, mColumn, Column);
	
	
private:
	void setupProperties();
	
#pragma mark - TDDTableDelegate
private:
	virtual int getTableCellCount();
	virtual Size getTableCellSize();
	virtual void onTableCellClicked(int selectedIndex);
	virtual Node *tableCellForIndex(int index);

private:
	//
	std::string mKeyword;
	std::vector<std::string> mResultList;
	
	//
	Size mTableCellSize;
	TDDTable *mResultTable;
};

#endif /* TDDMainLayer_hpp */
