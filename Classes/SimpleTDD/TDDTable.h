//
//  TDDTable.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 8/8/2016.
//
//

#ifdef ENABLE_TDD

#ifndef TDDTable_hpp
#define TDDTable_hpp



#include <stdio.h>


#include <stdio.h>


#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <string>
#include <vector>
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TDDTableDelegate
{
public:
	virtual int getTableCellCount() = 0;
	virtual Size getTableCellSize() = 0;
	virtual Node *tableCellForIndex(int index) = 0;		
};

class TDDTable : public LayerColor
{
public:
	typedef std::function<void(Ref *, int itemIndex)> TDDTableCallback;
	
public:
	static TDDTable *create(const Size &contentSize);
	
	
	
	TDDTable();
	~TDDTable();
	
	bool initWithSize(const Size &contentSize);
	
	CC_SYNTHESIZE(TDDTableDelegate *, mDelegate, Delegate);
	CC_SYNTHESIZE(Color3B, mTitleColor, TitleColor);
	CC_SYNTHESIZE(Color4B, mBackgroundColor, BackgroundColor);
	CC_SYNTHESIZE(std::string, mFontName, FontName);
	CC_SYNTHESIZE(int, mFontSize, FontSize);
	CC_SYNTHESIZE(int, mColumn, Column);
	
	void updateData();
	void updateBackgroundColor();
	void resizeTo(const Size &newSize);

private:
	Node *createTableCell(int index, const Size &size, const Vec2 &cellCenterPos);
	void notifyCallback(int index);
	
private:
	std::vector<ui::Button *> mButtonArray;
	TDDTableCallback mCallback;
	ScrollView *mScrollView;
	LayerColor *mScrollContentLayer;
};

#endif /* TDDTable_hpp */

#endif