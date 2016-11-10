//
//  TDDHeaderLayer.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 11/8/2016.
//
//

#ifdef ENABLE_TDD

#ifndef TDDHeaderLayer_hpp
#define TDDHeaderLayer_hpp

#include <stdio.h>

#include "cocos2d.h"
#include <string>
#include <vector>
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

#include "TDDMacro.h"
#include "TDDTypes.h"

class TDDTab;
class TDDTopBar;


class TDDTopBar
: public LayerColor
, public cocos2d::ui::EditBoxDelegate
{
public:
	CREATE_FUNC_WITH_SIZE(TDDTopBar);	// it make TDDHeaderLayer::create(const Size &size)
	
	TDDTopBar();
	~TDDTopBar();

	bool initWithSize(const Size &contentSize);
	
	// Property
	
	CC_SYNTHESIZE(Color4B, mSearchBarColor, SearchBarColor);
	CC_SYNTHESIZE(Color4B, mTopBarColor, TopBarColor);
	CC_SYNTHESIZE(Color3B, mTextColor, TextColor);
	CC_SYNTHESIZE(Color3B, mActiveTextColor, ActiveTextColor);
	CC_SYNTHESIZE(Color4B, mSearchBoxColor, SearchBoxColor);
	CC_SYNTHESIZE(Color3B, mSearchBoxTextColor, SearchBoxTextColor);
	
	// setup
	void setup(const TDDSearchType &tab, const std::string &keyword);	// note: no callback will be triggered
	
	// Callback
	void setCloseListener(const std::function<void(TDDTopBar *)> &callback);
	void setTabChangeListener(const std::function<void(TDDTopBar *, TDDSearchType)> &callback);
	void setKeywordChangeListener(const std::function<void(TDDTopBar *, const std::string &keyword)> &callback);
	
	void setSearchKeyword(const std::string &key);
	std::string getSearchKeyword();
	
	void updateColor();
	
#pragma mark - Internal Method
private:
	void initTopBar();
	void initSearchBar();
	
	void clearSearchText();

	void onCloseClicked();
	void onTabClicked(int selectedIndex, bool isRepeat);
	void onSearchKeyChanged();
	
	

#pragma mark - Internal Data
private:
	std::function<void(TDDTopBar *)> mCloseCallback;
	std::function<void(TDDTopBar *, TDDSearchType)> mTabChangeCallback;
	std::function<void(TDDTopBar *, const std::string &keyword)> mKeywordChangeCallback;
	
	LayerColor *mTopBarLayer;
	std::string mSearchKey;
	TDDTab *mTab;
	ui::EditBox *mEditBox;
	ui::TextField *mTextField;

#pragma mark - TextField handling
	void onTextFieldChange();

#pragma mark - EditBox Delegage
	virtual void editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text);
	virtual void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
	virtual void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
	virtual void editBoxReturn(cocos2d::ui::EditBox* editBox);
	

};


#endif /* TDDHeaderLayer_hpp */

#endif
