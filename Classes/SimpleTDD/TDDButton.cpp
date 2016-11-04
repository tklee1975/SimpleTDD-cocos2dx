//
//  TDDButton.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 31/10/2016.
//
//

#include "TDDButton.h"

using namespace cocos2d::ui;

TDDButton::TDDButton()
: Layout()
, mButton(nullptr)
{
	
}

TDDButton::~TDDButton()
{
	
}

bool TDDButton::init()
{
	if (Layout::init() == false)
	{
		return false;
	}
	
	// Background
	setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	setBackGroundColor(Color3B::BLUE);
	setAnchorPoint(Vec2(0.5f, 0.5f));
	setOpacity(0);	// by default transparent background
	
	// Add the button
	mButton = ui::Button::create();
	addChild(mButton);
	updateButtonPosition();
	
	setTouchEnabled(true);
	
	addTouchEventListener([&](Ref *ref, TouchEventType eventType) {
//		log("Debug: panel touch: eventType=%d", eventType);
		sendClickToButton(eventType);
	});
	
	return true;
}

void TDDButton::sendClickToButton(TouchEventType eventType)
{
	//log("Debug: panel is touched");
	Touch touch;
	//World
	
	// log("ButtonPos=%d ")
	Vec2 buttonPos = mButton->getPosition();
	
	Vec2 touchPos = Director::getInstance()->convertToUI(convertToWorldSpace(buttonPos));
										// TODO: transform button position to world position
	//log("buttonPos=%f,%f", buttonPos.x, buttonPos.y);
	//log("touchPos=%f,%f", touchPos.x, touchPos.y);
	
	// touchPos = Vec2(49, 22);
	
	touch.setTouchInfo(0, touchPos.x, touchPos.y);
	Event *event = new Event(Event::Type::TOUCH);
	if(eventType == TouchEventType::BEGAN) {
		mButton->onTouchBegan(&touch, event);
	}else if(eventType == TouchEventType::ENDED) {
		mButton->onTouchEnded(&touch, event);
	}
	delete event;
	
}

void TDDButton::setTitleText(const std::string& text)
{
	mButton->setTitleText(text);
}

/**
 * Query the button title content.
 *@return Get the button's title content.
 */
const std::string TDDButton::getTitleText() const
{
	return mButton->getTitleText();
}

void TDDButton::updateButtonPosition()
{
	if(mButton == nullptr) {
		return;
	}
	Size size = getContentSize();
	Vec2 midPos = Vec2(size.width/2, size.height/2);

	mButton->setPosition(midPos);
}

void TDDButton::setContentSize(const Size &size)
{
	Layout::setContentSize(size);
	
	updateButtonPosition();
}


/**
 * Change the color of button's title.
 *@param color The title color in Color3B.
 */
void TDDButton::setTitleColor(const Color3B& color)
{
	mButton->setTitleColor(color);
}

/**
 * Query the button title color.
 *@return Color3B of button title.
 */
Color3B TDDButton::getTitleColor() const
{
	return mButton->getTitleColor();
}


/**
 * Change the font size of button's title
 *@param size Title font size in float.
 */
void TDDButton::setTitleFontSize(float size)
{
	mButton->setTitleFontSize(size);
}

/**
 * Query the font size of button title
 *@return font size in float.
 */
float TDDButton::getTitleFontSize() const
{
	return mButton->getTitleFontSize();
}

void TDDButton::addClickEventListener(const Widget::ccWidgetClickCallback &callback)
{
	mButton->addClickEventListener(callback);
}

void TDDButton::setBackgroundColor(const Color4B &color)
{
	setBackGroundColor(Color3B(color));
	setOpacity(color.a);
}
