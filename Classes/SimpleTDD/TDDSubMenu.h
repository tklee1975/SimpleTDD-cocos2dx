//
//  TDDSubMenu.h
//  Cocos2dxTDDLib
//
//  Created by Ken Lee on 5/9/14.
//
//

#ifndef __Cocos2dxTDDLib__TDDSubMenu__
#define __Cocos2dxTDDLib__TDDSubMenu__

#include <iostream>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <string>
#include <vector>

USING_NS_CC;
USING_NS_CC_EXT;

#define kDefaultHeaderColor			Color4B(0, 0, 0, 100)
#define kDefaultBodyColor			Color4B(50, 50, 50, 160)

class TDDMenu;

class TDDSubMenu : public LayerColor
{
public:
	TDDSubMenu(const Size &size,
			   const Color4B &headerColor = kDefaultHeaderColor,
			   const Color4B &bodyColor = kDefaultBodyColor,
			   const Color3B &textColor = Color3B::WHITE,
			   const std::string font = "arial",
			   const int fontSize = 15);
	
	~TDDSubMenu();
	void setSubTest(Vector<MenuItem *> &menuArray);
	void setBackAction(Ref* target, Control::Handler action);
	
private:
	ControlButton *createButton(const std::string &name, int tag,
								const Point &pos, const Size &size);
	void setupHeader(const Color4B &headerColor);
	void setupMenu();
	void touchUpInsideAction(Ref *sender, Control::EventType controlEvent);
	void toggleMenu();
	void showMenu();
	void hideMenu();
	void closeTest();
	bool moveLayer(Point diff);

#pragma mark - Touch Handling
	bool onTouchBegan(Touch *touch, Event *event);
	void onTouchMoved(Touch *touch, Event *event);
	void onTouchEnded(Touch *touch, Event *event);
	void onTouchCancelled(Touch *touch, Event *event);

private:
	TDDMenu *mMenu;
	ControlButton *mToggleButton;
	ControlButton *mBackButton;
	LayerColor *mHeaderLayer;
	Size mMaxSize;
	bool mShow;
	bool mIsPressed;
	Point mLastPos;
};


#endif /* defined(__Cocos2dxTDDLib__TDDSubMenu__) */
