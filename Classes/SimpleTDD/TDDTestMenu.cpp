//
//  TDDTestMenu.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 20/8/2016.
//
//

#include "TDDTestMenu.h"
TDDTestMenu::TDDTestMenu()
: mTestNameList()
, mTestSelectedCallback(nullptr)
, mHeaderColor(Color4B(0, 0, 100, 100))
, mShow(true)
{
	
}

bool TDDTestMenu::init()
{
	bool flag = LayerColor::initWithColor(Color4B(0, 0, 0, 0), 200, 200);
	if(flag == false) {
		return false;
	}
	
	// Layout
	mHeaderHeight = 40;
	mTableHeight = getContentSize().height - mHeaderHeight;
	
	// Setup the sub component
	setupHeader();
	setupTable();
	
//	setContentSize(Size(200, 200));
//	setColor(Color3B::YELLOW);
	
	// setBackGroundColor(Color3B::YELLOW);
	addTouchListener();
	
	return true;
}

//void TDDTestMenu::addTest(const std::string &name, const TestCallback &callback)
//{
//	mTestNameList.push_back(name);
//	mTestCallbackMap[name] = callback;
//}

void TDDTestMenu::setTests(std::vector<std::string> &testList)
{
	mTestNameList.clear();
	for(int i=0; i<testList.size(); i++) {
		mTestNameList.push_back(testList[i]);
	}
	
	mTestTable->updateData();
}

#pragma mark - Touch handling
void TDDTestMenu::addTouchListener()
{
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(TDDTestMenu::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(TDDTestMenu::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(TDDTestMenu::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(TDDTestMenu::onTouchCancelled, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
}

bool TDDTestMenu::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Vec2 nodeLocation = convertTouchToNodeSpace(touch);
	
	bool touchInHeader = isTouchInsideHeader(nodeLocation);
	
	log("nodeLocation: %f,%f touchHeader=%d", nodeLocation.x, nodeLocation.y, touchInHeader);
	
	if(touchInHeader == false) {
		mIsTouching = false;
		return false;
	}
	
	mIsTouching = true;
	mLastLocation = touch->getLocation();
	
	return true;
}

void TDDTestMenu::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
	Vec2 newLocation = touch->getLocation();
	
	Vec2 delta = newLocation - mLastLocation;
	
	moveBy(delta);
	
	mLastLocation = newLocation;
}

void TDDTestMenu::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
	mIsTouching = false;
}

void TDDTestMenu::onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event)
{
}

#pragma mark - TDDTableDelegate
int TDDTestMenu::getTableCellCount()
{
	return (int) mTestNameList.size();
}

Size TDDTestMenu::getTableCellSize()
{
	float width = getContentSize().width;
	
	return Size(width, 40);
}

Node *TDDTestMenu::tableCellForIndex(int index)
{
	std::string name = getTestName(index);
	
	
	
	ui::Button *button = ui::Button::create();
	//button->setColor(Color3B::YELLOW);		// this is no use
	button->setTitleText(name);
	button->setContentSize(getTableCellSize());
	button->setTitleColor(Color3B::WHITE);
	button->setTitleFontSize(15);
	
	button->addClickEventListener([&, name](Ref *) {
		if(mTestSelectedCallback) {
			mTestSelectedCallback(name);
		}
	});
	
	return button;
	
}
//
//void TDDTestMenu::doTestCallback(const std::string &name)
//{
////	TestCallback callback = mTestCallbackMap[name];
////	if(callback == nullptr) {
////		log("doTestCallback: callback is null. name=%s", name.c_str());
////		return;
////	}
////	
////	callback();
//}

std::string TDDTestMenu::getTestName(int index)
{
	if(index < 0 || index >= mTestNameList.size()) {
		return "";
	}
	
	return mTestNameList[index];
}

void TDDTestMenu::refreshMenu()
{
	if(mTestTable) {
		mTestTable->updateData();
	}
	
}

void TDDTestMenu::setTestSelectedCallback(const TestSelectedCallback &callback)
{
	mTestSelectedCallback = callback;
}

void TDDTestMenu::setBackCallback(const TestMenuCallback &callback)
{
	mBackCallback = callback;
}


void TDDTestMenu::setupHeader()
{
	
	Vec2 pos = Vec2(0, mTableHeight);		// anchor=left,bottom
	
	float width = getContentSize().width;
	LayerColor *headerLayer = LayerColor::create(mHeaderColor, width, mHeaderHeight);
	headerLayer->setPosition(pos);
	
	
	addChild(headerLayer);
	
	mHeaderNode = headerLayer;
}

void TDDTestMenu::setupTable()
{
	Size tableSize = Size(getContentSize().width, mTableHeight);
	Vec2 pos = Vec2::ZERO;					// anchor=left,bottom
	
	// Add the Table
	TDDTable *table = TDDTable::create(tableSize);
	table->setColumn(1);
	table->setBackgroundColor(Color4B(0,0,0,140));
	table->setDelegate(this);
	//delegate->release();
	
	table->updateData();
	
	addChild(table);
	mTestTable = table;
	
}

void TDDTestMenu::moveBy(const Vec2 &delta)
{
	Vec2 newPos = getPosition() + delta;
	
	setPosition(newPos);
}

// Toggle the Menu
void TDDTestMenu::toggleMenu()
{
	if(mShow) {
		hideMenu();
	} else {
		showMenu();
	}
	
}

void TDDTestMenu::showMenu()
{
	mTestTable->setVisible(true);
}

void TDDTestMenu::hideMenu()
{
	mTestTable->setVisible(false);
}


bool TDDTestMenu::isTouchInsideHeader(const Vec2 &touchLocation)
{
	Rect headerArea = mHeaderNode->getBoundingBox();
	
	return headerArea.containsPoint(touchLocation);
}