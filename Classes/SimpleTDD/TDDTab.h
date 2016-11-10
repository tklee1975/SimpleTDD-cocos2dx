//
//  TDDTab.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 6/8/2016.
//
//

#ifndef TDDTab_hpp
#define TDDTab_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"

#ifdef ENABLE_TDD

USING_NS_CC;

class TDDButton;

class TDDTab : public LayerColor
{
public:
	typedef std::function<void(Ref*, int selectedTab, bool isRepeat)> TDDTabCallback;
	
public:
	CREATE_FUNC(TDDTab);
	TDDTab();
	~TDDTab();
	
	int addTab(const std::string &tabName);		// return the tabIndex
	void selectTab(int index, bool doCallback=true);
	void setCallback(const TDDTabCallback &callback);
	
	CC_SYNTHESIZE(Color3B, mTitleColor, TitleColor);
	CC_SYNTHESIZE(Color3B, mActiveTitleColor, ActiveTitleColor);
	CC_SYNTHESIZE(std::string, mFontName, FontName);
	CC_SYNTHESIZE(int, mFontSize, FontSize);
	CC_SYNTHESIZE(Size, mTabSize, TabSize);
	
	int getTabCount();
	std::string getName(int index);

private:
	TDDButton *getButtonAtIndex(int index);
	TDDButton *createButton(const std::string &name, const Vec2 &pos, int tabIndex);
	void updateContentSize();
	
private:
	std::vector<TDDButton *> mButtonArray;
	TDDTabCallback mCallback;
	int mSelectedIndex;
	
//	bool mEnableCallback;
//	
//	LayerColor *mSwitchBg;
//	Size mSwitchSize;
//	std::vector<ControlButton *> mButtonArray;
//	std::vector<std::string> mNameArray;
//	int mSelected;
//	tddSwitchCallback mCallback;
//	
//	ControlButton *addSwitchButton(const std::string &switchName, int index,
//											const Point &pos, const Size &size);
//	void setupSwitchBg(int count);
//	void setSwitchSelected(int index);
//	ControlButton *getButtonAtIndex(int index);
//	void touchUpInsideAction(Ref *sender, Control::EventType controlEvent);
//	std::string getName(int index);
};


#endif /* TDDTab_hpp */

#endif
