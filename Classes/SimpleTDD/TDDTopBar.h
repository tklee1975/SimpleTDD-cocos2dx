//
//  TDDHeaderLayer.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 11/8/2016.
//
//

#ifndef TDDHeaderLayer_hpp
#define TDDHeaderLayer_hpp

#include <stdio.h>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <string>
#include <vector>
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

#include "TDDMacro.h"

class TDDTopBar;

typedef enum {
	TDDTopBarTabAll,
	TDDTopBarTabRecent,
}TDDTopBarTab;


class TDDTopBar : public LayerColor
{
public:
	CREATE_FUNC_WITH_SIZE(TDDTopBar);	// it make TDDHeaderLayer::create(const Size &size)
	
	TDDTopBar();
	~TDDTopBar();

	bool initWithSize(const Size &contentSize);
	
	// Property
	
	CC_SYNTHESIZE(Color4B, mTopBarColor, TopBarColor);
	CC_SYNTHESIZE(Color3B, mTextColor, TextColor);
	CC_SYNTHESIZE(Color3B, mActiveTextColor, ActiveTextColor);
	CC_SYNTHESIZE(Color4B, mSearchBoxColor, SearchBoxColor);
	CC_SYNTHESIZE(Color3B, mSearchBoxTextColor, SearchBoxTextColor);
	
	// Callback
	void setCloseListener(const std::function<void(TDDTopBar *)> &callback);
	void setTabChangeListener(const std::function<void(TDDTopBar *, TDDTopBarTab)> &callback);
	void setKeywordChangeListener(const std::function<void(TDDTopBar *, const std::string &keyword)> &callback);
	
	void setSearchKeyword(const std::string &key);
	std::string getSearchKeyword();
	
private:
	void initTopBar();
	void initSearchBar();
	
	void clearSearchText();

	void onCloseClicked();
	void onTabClicked(int selectedIndex);
	void onSearchKeyChanged();
private:
	std::function<void(TDDTopBar *)> mCloseCallback;
	std::function<void(TDDTopBar *, TDDTopBarTab)> mTabChangeCallback;
	std::function<void(TDDTopBar *, const std::string &keyword)> mKeywordChangeCallback;
	
	LayerColor *mTopBarLayer;
	ui::EditBox *mEditBox;
	std::string mSearchKey;
};


#endif /* TDDHeaderLayer_hpp */
