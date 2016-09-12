#ifdef ENABLE_TDD
//
//  TDDTestMenu.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 20/8/2016.
//
//
#include "TDDTestMenu.h"

const Color4B kClearColor = Color4B(0, 0, 0, 0);
const Color4B kHeaderColor = Color4B(0, 0, 0, 150);
const Color4B kBackgroundColor = Color4B(0, 0, 0, 100);


TDDTestMenu::TDDTestMenu()
: mTestNameList()
, mTestSelectedCallback(nullptr)
, mHeaderColor(kHeaderColor)
, mShow(true)
, mHeaderNode(nullptr)
, mTestTable(nullptr)
, mToggleButton(nullptr)
, mHeaderButtonSize(Size(50, 50))
, mColumn(1)
{

}

bool TDDTestMenu::init()
{
	bool flag = LayerColor::initWithColor(kClearColor, 200, 200);
	if(flag == false) {
		return false;
	}

	// Layout
	mHeaderHeight = 40;
	mHeaderButtonSize = Size(50, mHeaderHeight);
	mTableHeight = getContentSize().height - mHeaderHeight;

	// Setup the sub component
	setupHeader();
	setupTable();

	// Touch handling
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
	float width = getContentSize().width / mColumn;

	return Size(width, 35);
}

ui::Button *TDDTestMenu::createButton(const std::string &title, const Size &size)
{
	ui::Button *button = ui::Button::create();
	button->setTitleText(title);
	button->setContentSize(size);
	button->setTitleColor(Color3B::WHITE);
	button->setTitleFontSize(15);

	return button;
}

Node *TDDTestMenu::tableCellForIndex(int index)
{
	std::string name = getTestName(index);



	ui::Button *button = createButton(name, getTableCellSize());
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

	Size size = Size(50, mHeaderHeight);
	Vec2 backPos = Vec2(size.width/2, size.height/2);
	Vec2 togglePos = Vec2(width - size.width/2, size.height/2);

	//
	// Back Button
	ui::Button *backButton = createButton("back", size);
	backButton->setContentSize(size);
	backButton->setPosition(backPos);
	backButton->addClickEventListener([&](Ref *) {
		if(mBackCallback) {
			mBackCallback(this);
		}
	});
	headerLayer->addChild(backButton);


	// Toggle Menu
	ui::Button *toggleButton = createButton("hide", size);
	toggleButton->setContentSize(size);
	toggleButton->setPosition(togglePos);
	toggleButton->addClickEventListener([&](Ref *) {
		toggleMenu();
	});
	headerLayer->addChild(toggleButton);
	mToggleButton = toggleButton;

	//
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
	table->setBackgroundColor(kBackgroundColor);
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
	mShow = true;
	mTestTable->setVisible(true);
	if(mToggleButton) {
		mToggleButton->setTitleText("hide");
	}
}

void TDDTestMenu::hideMenu()
{
	mShow = false;
	mTestTable->setVisible(false);
	if(mToggleButton) {
		mToggleButton->setTitleText("show");
	}
}


bool TDDTestMenu::isTouchInsideHeader(const Vec2 &touchLocation)
{
	Rect headerArea = mHeaderNode->getBoundingBox();

	return headerArea.containsPoint(touchLocation);
}

void TDDTestMenu::setMenuColor(const Color4B &headerColor, const Color4B &bgColor)
{
	if(mHeaderNode) {
		mHeaderNode->setColor(Color3B(headerColor));
		mHeaderNode->setOpacity(headerColor.a);
	}

	if(mTestTable) {
		mTestTable->setBackgroundColor(bgColor);
		mTestTable->updateBackgroundColor();
	}
}

void TDDTestMenu::setColumn(int column)
{
	mColumn = column;
	if(mTestTable) {
		mTestTable->setColumn(column);
	}

}
void TDDTestMenu::refreshTable()
{
	if(mTestTable) {
		mTestTable->updateData();
	}

}

void TDDTestMenu::setContentSize(const Size &size)
{
	LayerColor::setContentSize(size);

	// Modify the Subnode
	if(mHeaderNode) {
		Size headerSize = mHeaderNode->getContentSize();
		headerSize.width = getContentSize().width;

		mHeaderNode->setContentSize(headerSize);

		Vec2 pos = Vec2(0, size.height - mHeaderHeight);
		mHeaderNode->setPosition(pos);
	}

	if(mTestTable) {
		Size size = getContentSize();
		size.height -= mHeaderHeight;

		mTestTable->resizeTo(size);
	}


	if(mToggleButton) {
		Size buttonSize = mToggleButton->getContentSize();

		Vec2 newPos = mToggleButton->getPosition();
		newPos.x = getContentSize().width - buttonSize.width/2 ;

		mToggleButton->setPosition(newPos);
	}

}

Vec2 TDDTestMenu::getTopPosition()
{
	Vec2 pos = getPosition();
	
	pos.y += getContentSize().height;
	
	return pos;
}

#endif
