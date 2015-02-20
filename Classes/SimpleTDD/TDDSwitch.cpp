//
//  TDDToggle.cpp
//  Cocos2dxTDDLib
//
//  Created by Ken Lee on 6/8/14.
//
//

#include "TDDSwitch.h"

#define kMargin		5

// Internal Method
namespace
{
	void setNodeAlphaPremultiplied(Node *node)
	{
		if(node == NULL) {
			return;
		}
		
		BlendProtocol *ptr = dynamic_cast<BlendProtocol *>(node);
		if(ptr == NULL) {
			return;
		}
		
		ptr->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
	}
	
	void setButtonSelected(ControlButton *button, bool flag,
						   const Color3B &onColor, const Color3B &offColor)
	{
		if(button == NULL) {
			return;
		}
		
		button->setHighlighted(false);
		
		button->setSelected(flag);
		
		if(button->isSelected()) {
			button->setTitleColorForState(onColor, Control::State::NORMAL);
		} else {
			button->setTitleColorForState(offColor, Control::State::NORMAL);
		}
	}

}


// 
TDDSwitch::TDDSwitch(const Size &size,
					 const Color4B &bgColor, const Color4B &switchColor,
					 const Color3B &offTextColor, const Color3B &onTextColor,
					 const std::string font,
					 const int fontSize)
: mSwitchBg(NULL)
, mSelected(-1)
, mCallback(NULL)
, mBgColor(bgColor)
, mSwitchColor(switchColor)
, mOffTextColor(offTextColor)
, mOnTextColor(onTextColor)
, mFont(font)
, mFontSize(fontSize)
, mEnableCallback(false)
{
	TDDSwitch::initWithColor(bgColor, size.width, size.height);
	
	//
	// Switch Button Background
	
}


TDDSwitch::~TDDSwitch()
{
}


void TDDSwitch::moveSwitchBg(int index)
{
	Point switchPos = Point(kMargin, kMargin);
	for(int i=0; i<index; i++) {
		switchPos.x += mSwitchSize.width;
	}
	if(mSwitchBg) {
		mSwitchBg->setPosition(switchPos);
	}
}



void TDDSwitch::touchUpInsideAction(Ref *sender, Control::EventType controlEvent)
{
	ControlButton *button = (ControlButton *)sender;
	
	log("Button is clicked");
	int index = button->getTag();
	
	setSwitchSelected(index);
	
	
//	if(button->isSelected()) {
//		button->setHighlighted(false);
//		button->setSelected(false);
//	} else {
//		button->setSelected(true);
//		button->setHighlighted(true);
//	}
	// button->setColor(Color3B::RED);
	//  _displayValueLabel->setString(String::createWithFormat("Touch Up Inside.")->getCString());
}


ControlButton *TDDSwitch::addSwitchButton(const std::string &switchName, int index,
											const Point &pos, const Size &size)
{
	Color3B colorNormal = mOffTextColor;
	Color3B colorSelected = mOnTextColor;
	
	Scale9Sprite *bgButton = Scale9Sprite::create();
	Scale9Sprite *bgHiliButton = Scale9Sprite::create();
	
	// bgButton->setContentSize(Size(200, 50));
	Label *titleButton = Label::createWithSystemFont(switchName.c_str(), mFont, mFontSize);
	titleButton->setColor(colorNormal);
	
	ControlButton *button = ControlButton::create(titleButton, bgButton);
	button->setBackgroundSpriteForState(bgHiliButton, Control::State::HIGH_LIGHTED);
	//button->setTitleColorForState(colorN, Control::State::HIGH_LIGHTED);
	
	
	
	// ((Label *)button->getTitleLabel())->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
	setNodeAlphaPremultiplied(button->getTitleLabel());
	
	button->setTag(index);
	button->setContentSize(size);
	button->setPosition(pos);
	button->addTargetWithActionForControlEvents(this,
												cccontrol_selector(TDDSwitch::touchUpInsideAction),
												Control::EventType::TOUCH_UP_INSIDE);
	
	addChild(button);
	
	button->setSelected(false);
	
	return button;
}


ControlButton *TDDSwitch::getButtonAtIndex(int index)
{
	if(index < 0) {
		return NULL;
	}
	
	if(index >= mButtonArray.size()) {
		return NULL;
	}
	
	return mButtonArray[index];
}

void TDDSwitch::setSwitchSelected(int index)
{
	bool doCallback;
	
	if(index != mSelected) {
		// Turn off the last selected button
		ControlButton *lastButton = getButtonAtIndex(mSelected);
		setButtonSelected(lastButton, false, mOnTextColor, mOffTextColor);
		
		doCallback = true;
	} else {
		doCallback = false;
	}

	// Assign
	mSelected = index;
	
	// Turn on the new selected button
	ControlButton *newButton = getButtonAtIndex(mSelected);
	setButtonSelected(newButton, true, mOnTextColor, mOffTextColor);
	
	// Set the background
	moveSwitchBg(mSelected);
	
	
	if(mEnableCallback && doCallback && mCallback)
	{
		std::string name = getName(mSelected);
		mCallback(this, name, mSelected);
	}
	

}

std::string TDDSwitch::getName(int index)
{
	return mNameArray[index];
}

void TDDSwitch::setupSwitchBg(int count)
{
	if(count == 0) {
		return;
	}
	
	Size size = this->getContentSize();
	
	GLfloat switchW = (size.width - kMargin * 2) / count;
	GLfloat switchH = size.height - kMargin * 2;
	mSwitchSize = Size(switchW, switchH);
	Point switchPos = Point(kMargin, kMargin);
	
	
	LayerColor *switchButtonBg = LayerColor::create(mSwitchColor, mSwitchSize.width, mSwitchSize.height);
	switchButtonBg->setPosition(switchPos);
	addChild(switchButtonBg);
	
	mSwitchBg = switchButtonBg;
}

void TDDSwitch::setSwitches(std::vector<std::string> switches,
							const tddSwitchCallback& callback, int defaultSelection)
{
	Point pos = Point(kMargin, kMargin);
	
	mCallback = callback;
	
	mNameArray.clear();
	
	// Setup Switch Background
	setupSwitchBg((int) switches.size());
	
	
	// Add the Switch Buttons
	// Move to the button center
	pos.x += mSwitchSize.width / 2;
	pos.y += mSwitchSize.height / 2;
	
	for(int i=0; i<switches.size(); i++) {
		std::string name = switches[i];
		
		log("name=%s", name.c_str());
		ControlButton *btn = addSwitchButton(name, i, pos, mSwitchSize);
		
		mNameArray.push_back(name);
		mButtonArray.push_back(btn);
		
		pos.x += mSwitchSize.width;
	}
	
	// Set Active
	setSwitchSelected(defaultSelection);
	
	mEnableCallback = true;
}


