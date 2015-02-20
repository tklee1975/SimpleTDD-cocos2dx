#ifdef ENABLE_TDD
//
//  TDDSubMenu.cpp
//  Cocos2dxTDDLib
//
//  Created by Ken Lee on 5/9/14.
//
//

#include "TDDSubMenu.h"
#include "TDDHelper.h"
#include "TDDConstant.h"
#include "TDDMenu.H"

#define kHeaderHeight		30
#define kLineHeight			kDefaultMenuRowHeight

#define kAlpha				200
#define kColorTestMenu		Color4B(20, 20, 20, kAlpha)

#define kActionTagBack			1
#define kActionTagToggle		2

TDDSubMenu::TDDSubMenu(const Size &size,
					   const Color4B &headerColor,
					   const Color4B &bodyColor,
					   const Color3B &textColor,
					   const std::string font,
					   const int fontSize)
: mShow(true)
, mHeaderLayer(NULL)
, mToggleButton(NULL)
, mIsPressed(false)
, mMenu(NULL)
, mBackButton(NULL)
{
	TDDSubMenu::initWithColor(bodyColor, size.width, size.height);
	
	mMaxSize.width = size.width;
	mMaxSize.height = size.height;
	
	// Add the header
	setupHeader(headerColor);
	setupMenu();
	
	// Set touch
	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);	// ???
}


void TDDSubMenu::setupMenu()
{
	GLfloat parentH = this->getContentSize().height;
	GLfloat width = this->getContentSize().width;
	GLfloat height = parentH - kHeaderHeight;
	
	
	Size menuSize = Size(width, height);
	mMenu = new TDDMenu(menuSize, kColorTestMenu, kLineHeight);
	this->addChild(mMenu);
}

void TDDSubMenu::setSubTest(Vector<MenuItem *> &menuArray)
{
	if(mMenu) {
		mMenu->setMenuItems(menuArray);
	}
}

void TDDSubMenu::setupHeader(const Color4B &headerColor)
{
	GLfloat parentH = this->getContentSize().height;
	GLfloat width = this->getContentSize().width;
	GLfloat height = kHeaderHeight;
	
	LayerColor *headerLayer = LayerColor::create(headerColor, width, height);
	Point pos = Point(0, parentH - height);
	headerLayer->setPosition(pos);
	this->addChild(headerLayer);
	
	
	// Setting Buttons
	float scale = TDDHelper::getBestScale();
	// Size screenSize = TDDHelper::getScreenSize();
	int midY = height/2;
	int buttonW = (int)(scale * 50);
	int buttonH = height;
	int leftButtonX = buttonW / 2;
	int rightButtonX = width - leftButtonX;
	int midX = width/2;
	

	Size size = Size(buttonW, buttonH);

	ControlButton *button;
	pos.x = leftButtonX;
	pos.y = midY;
	button = createButton("back", kActionTagBack, pos, size);
	headerLayer->addChild(button);
	mBackButton = button;
	
	pos.x = rightButtonX;
	pos.y = midY;
	button = createButton("hide", kActionTagToggle, pos, size);
	headerLayer->addChild(button);
	button->addTargetWithActionForControlEvents(this,
												cccontrol_selector(TDDSubMenu::touchUpInsideAction),
												Control::EventType::TOUCH_UP_INSIDE);
	mToggleButton = button;
	
	// Label
	Label *title = Label::createWithSystemFont("MENU", "Arial", 15);
	title->setColor(Color3B::WHITE);
	title->setPosition(Point(midX, midY));
	headerLayer->addChild(title);
	
	
	//
	mHeaderLayer = headerLayer;
}



ControlButton *TDDSubMenu::createButton(const std::string &name, int tag,
										  const Point &pos, const Size &size)
{
	Color3B colorNormal = Color3B::WHITE;
	//Color3B colorSelected = colorNormal;
	
	Scale9Sprite *bgButton = Scale9Sprite::create();
	Scale9Sprite *bgHiliButton = Scale9Sprite::create();
	
	// bgButton->setContentSize(Size(200, 50));
	Label *titleButton = Label::createWithSystemFont(name.c_str(), "Arial", 15);
	titleButton->setColor(colorNormal);
	
	
	ControlButton *button = ControlButton::create(titleButton, bgButton);
	button->setBackgroundSpriteForState(bgHiliButton, Control::State::HIGH_LIGHTED);

	TDDHelper::setAlphaPremultiplied(button);
	button->setTag(tag);
	button->setContentSize(size);
	button->setPosition(pos);
	button->setSelected(false);
	
	return button;
}

TDDSubMenu::~TDDSubMenu()
{
}

void TDDSubMenu::closeTest()
{
	log("TDDSubMenu.closeTest");

}

void TDDSubMenu::setBackAction(Ref* target, Control::Handler action)
{
	if(mBackButton) {
		mBackButton->addTargetWithActionForControlEvents(target, action,
											Control::EventType::TOUCH_UP_INSIDE);
	}
}

void TDDSubMenu::toggleMenu()
{
	log("TDDSubMenu.toggleMenu:");
	if(mShow) {
		hideMenu();
	} else {
		showMenu();
	}
}

void TDDSubMenu::showMenu()
{
	mShow = true;
	
	Size currentSize = this->getContentSize();
	Point currentPos = this->getPosition();
	Size newSize = Size(mMaxSize.width, mMaxSize.height);
	float heightDiff = newSize.height - currentSize.height;
	Point newPos = Point(currentPos.x, currentPos.y - heightDiff);
	
	// Change the size
	this->setContentSize(newSize);
	
	// Change the position
	this->setPosition(newPos);
	
	// Move the header
	mHeaderLayer->setPosition(Point(0, heightDiff));
	
	// Change the button name
	mToggleButton->setTitleForState("hide", Control::State::NORMAL);
	
	mMenu->setVisible(true);
}

void TDDSubMenu::hideMenu()
{
	mShow = false;
	Size currentSize = this->getContentSize();
	Point currentPos = this->getPosition();
	Size newSize = Size(mMaxSize.width, kHeaderHeight);
	float heightDiff = currentSize.height - newSize.height;
	Point newPos = Point(currentPos.x, currentPos.y + heightDiff);
	
	// Change the size
	this->setContentSize(newSize);
	
	// Change the position
	this->setPosition(newPos);
	
	// Move the header
	mHeaderLayer->setPosition(Point(0, 0));
	
	// Change the button name
	mToggleButton->setTitleForState("show", Control::State::NORMAL);
	
	// Hide the menu
	mMenu->setVisible(false);
}

void TDDSubMenu::touchUpInsideAction(Ref *sender, Control::EventType controlEvent)
{
	ControlButton *button = (ControlButton *)sender;
	
	log("Button is clicked");
	int tag = button->getTag();
	
	switch(tag) {
		case kActionTagToggle:
		{
			toggleMenu();
			break;
		}
		
		case kActionTagBack:
		{
			closeTest();
			break;
		}

	}
}

bool TDDSubMenu::moveLayer(Point diff)
{
//	if(diff.x < 1 && diff.y < 1) {
//		return false;
//	}
	
	Point pos = getPosition();
	Point newPos = Point(diff.x + pos.x, diff.y + pos.y);
	
	if(newPos.x < 0) {
		newPos.x = 0;
	}
	
	float botBound = -(getContentSize().height - kHeaderHeight);
	if(newPos.y < botBound) {
		newPos.y = botBound;
	}
	
	Size winSize = Director::getInstance()->getWinSize();
	float topBound = winSize.height - getContentSize().height;
	if(newPos.y > topBound) {
		newPos.y = topBound;
	}


	setPosition(newPos);
	
	return true;
}

#pragma mark - Touch Handling
bool TDDSubMenu::onTouchBegan(Touch *touch, Event *event)
{
	Point posGL = touch->getLocation();			// from bottom
	Point nodeLoc = convertToNodeSpace(posGL);

	Size size = this->getContentSize();
	Point pos = this->getPosition();
	
	//log("began: posGL=%f,%f nodeLoc=%f,%f",
	//			posGL.x, posGL.y, nodeLoc.x, nodeLoc.y);
	
	// Check bound !
	// Check for X
	if(nodeLoc.x < 0 || nodeLoc.x > size.width) {
		return false;
	}
	
	float headerYStart = size.height - kHeaderHeight;
	if(nodeLoc.y < headerYStart || nodeLoc.y > size.height) {
		return false;
	}
	
	// is touching the header
	
	
//	if(nodeLoc.c)
	//if()
	//nodeLoc.
	
	mLastPos = touch->getLocation();
	mIsPressed = true;
	
	return true;
}

void TDDSubMenu::onTouchMoved(Touch *touch, Event *event)
{
	if(mIsPressed == false){
		return;
	}
	
	Point posGL = touch->getLocation();			// from bottom
	Point nodeLoc = convertToNodeSpace(posGL);

	Point diff = Point(posGL.x - mLastPos.x, posGL.y - mLastPos.y);

//	log("moved: posGL=%f,%f nodeLoc=%f,%f diff=%f,%f",
//				posGL.x, posGL.y, nodeLoc.x, nodeLoc.y, diff.x, diff.y);
	
	
	if(moveLayer(diff)) {
		mLastPos = posGL;
	}
	
	return;
}


void TDDSubMenu::onTouchEnded(Touch *touch, Event *event)
{
	mIsPressed = false;
	return;
}

void TDDSubMenu::onTouchCancelled(Touch *touch, Event *event)
{
	mIsPressed = false;
	return;
}


// Only for TDDLib
#endif