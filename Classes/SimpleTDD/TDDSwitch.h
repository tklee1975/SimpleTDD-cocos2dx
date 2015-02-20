//
//  TDDSwitch.h
//  Cocos2dxTDDLib
//
//  Created by Ken Lee on 6/8/14.
//
//

#ifndef __Cocos2dxTDDLib__TDDToggle__
#define __Cocos2dxTDDLib__TDDToggle__

#include <iostream>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <string>
#include <vector>

USING_NS_CC;
USING_NS_CC_EXT;

typedef std::function<void(Ref*, std::string switchName, int switchIndex)> tddSwitchCallback;

class TDDSwitch : public LayerColor
{
public:
	TDDSwitch(const Size &size,
				const Color4B &bgColor, const Color4B &switchColor,
				const Color3B &offTextColor = Color3B::GRAY,
				const Color3B &onTextColor = Color3B::WHITE,
				const std::string font = "arial",
				const int fontSize = 15);
	~TDDSwitch();
	
	void moveSwitchBg(int index);
	void setSwitches(std::vector<std::string> switches,
						const tddSwitchCallback& callback, int defaultSelection=0);
	
private:
	Color4B mBgColor;
	Color4B mSwitchColor;
	Color3B mOffTextColor;
	Color3B mOnTextColor;
	
	std::string mFont;
	int mFontSize;
	bool mEnableCallback;
	
	LayerColor *mSwitchBg;
	Size mSwitchSize;
	std::vector<ControlButton *> mButtonArray;
	std::vector<std::string> mNameArray;
	int mSelected;
	tddSwitchCallback mCallback;
	
	ControlButton *addSwitchButton(const std::string &switchName, int index,
											const Point &pos, const Size &size);
	void setupSwitchBg(int count);
	void setSwitchSelected(int index);
	ControlButton *getButtonAtIndex(int index);
	void touchUpInsideAction(Ref *sender, Control::EventType controlEvent);
	std::string getName(int index);
};


#endif /* defined(__Cocos2dxTDDLib__TDDToggle__) */
