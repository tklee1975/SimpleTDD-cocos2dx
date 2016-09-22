#ifdef ENABLE_TDD
//
//  TDDBaseTest.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 24/8/2016.
//
//

#include "TDDBaseTest.h"
#include "TDDTestMenu.h"
#include "TDDTypes.h"
#include "TDDHelper.h"
#include "TDDAssertInfo.h"

// ZOrder
const int kZorderBackground = -10000;
const int kZorderTestMenu = 10000;
const TDDAlign kDefaultMenuAlign = TDDAlign::eTDDTopRight;
const Vec2 kMenuSizePercent = Vec2(0.3, 1.0);

TDDBaseTest::TDDBaseTest()
: mBaseNode(nullptr)
, mMenuAlign(kDefaultMenuAlign)
, mCurrentTestName("")
, mBreakWhenFail(false)
{
	Size screenSize = Director::getInstance()->getVisibleSize();
	setContentSize(screenSize);		// note: it is zero by default
}

void TDDBaseTest::onEnter()
{
	Scene::onEnter();

	findBaseNode();		// Find the base node, prevent it is removed from clearChildren!!

	defineTests();		// Define the list of sub test

	setupGUI();

	setUp();
}

void TDDBaseTest::onExit()
{
	tearDown();

	Scene::onExit();
}

#pragma mark - Core Method for testing
void TDDBaseTest::setUp()
{

}

void TDDBaseTest::tearDown()
{

}

void TDDBaseTest::addTest(const std::string &name, const std::function<void()> &callback)
{
	mTestNameList.push_back(name);
	mTestCallbackMap[name] = callback;
}

void TDDBaseTest::doTestCallback(const std::string &name)
{
	std::function<void()> callback = mTestCallbackMap[name];
	if(callback == nullptr) {
		log("doTestCallback: callback is null. name=%s", name.c_str());
		return;
	}

	mCurrentTestName = name;
	
	willRunTest(name);

	callback();

	didRunTest(name);
	
	mCurrentTestName = "";
}

void TDDBaseTest::willRunTest(const std::string &name)	// before run a test
{

}

void TDDBaseTest::didRunTest(const std::string &name)	// after run a test
{

}


#pragma mark - Helper Method
void TDDBaseTest::setupGUI()
{
	Size screenSize = Director::getInstance()->getVisibleSize();

	// Background Layer
	mBackLayer = LayerColor::create(Color4B::GRAY, screenSize.width, screenSize.height);
	mBackLayer->setLocalZOrder(kZorderBackground);
	addChild(mBackLayer);

	// TestMenu
	TDDTestMenu *testMenu = createTestMenu();
	testMenu->setLocalZOrder(kZorderTestMenu);
	addChild(testMenu);
	mTestMenu = testMenu;
	
	setMenuSizeByPercent(kMenuSizePercent);

	// Default SizePercent
	// setMenuSizeByPercent(
	
	TDDHelper::alignNode(mTestMenu, mMenuAlign);
}

TDDTestMenu *TDDBaseTest::createTestMenu()
{
	TDDTestMenu *menu = TDDTestMenu::create();

	menu->setPosition(Vec2(50, 50));

	// Define the test to the menu
	menu->setTestSelectedCallback([&](const std::string &name) {
		doTestCallback(name);
	});

	menu->setBackCallback([&](TDDTestMenu *menu){
		back();
	});

	menu->setTests(mTestNameList);

	return menu;
}

void TDDBaseTest::back()
{
	Director::getInstance()->popScene();
}

void TDDBaseTest::setBackgroundColor(const Color3B &color)
{
	if(mBackLayer) {
		mBackLayer->setColor(color);
	}
}

void TDDBaseTest::clearChildren()
{
	Vector<Node *> allNodes = this->getChildren();

	for(int i=1; i<allNodes.size(); i++) {	// The first node is the scene base layer, cannot remove
		Node *node = allNodes.at(i);
		if(node == mBackLayer || node == mTestMenu || node == mBaseNode) {
			continue;
		}

		node->removeFromParent();
	}
}


void TDDBaseTest::findBaseNode()
{
	Vector<Node *> allNodes = this->getChildren();
	if(allNodes.size() == 0) {
		return;		// this is something wrong here!!, suppose it is size = 1
	}

	mBaseNode = allNodes.at(0);
}


void TDDBaseTest::hideMenu()
{
	setMenuVisible(false);
}

void TDDBaseTest::toggleStat()
{
	Director *director = Director::getInstance();
	bool hasStat = director->isDisplayStats();
	director->setDisplayStats(! hasStat);
}

void TDDBaseTest::setMenuVisible(bool flag)
{
	if(mTestMenu) {
		mTestMenu->setVisible(flag);
	}
}

void TDDBaseTest::setMenuColor(const Color4B &headerColor, const Color4B &bgColor)
{
	if(mTestMenu) {
		mTestMenu->setMenuColor(headerColor, bgColor);
	}
}

void TDDBaseTest::setMenuTextColor(const Color3B &textColor)
{
	if(mTestMenu) {
		mTestMenu->setTextColor(textColor);
	}
	
}

void TDDBaseTest::clearNodes()
{
	clearChildren();
}

void TDDBaseTest::setMenuPostion(const Vec2 &pos)
{
	if(mTestMenu) {
		mTestMenu->setPosition(pos);
	}
}

void TDDBaseTest::setMenuSizeByPercent(const Vec2 &percent)
{
	if(mTestMenu) {
		mTestMenu->setContentSizeByPercent(percent);
		TDDHelper::alignNode(mTestMenu, mMenuAlign);		// reset the test menu
	}
	

}


void TDDBaseTest::setMenuWidth(const float &width)
{
	if(mTestMenu) {
		mTestMenu->setWidth(width);
		TDDHelper::alignNode(mTestMenu, mMenuAlign);		// reset the test menu
	}

}

void TDDBaseTest::setMenuHeight(const float &height)
{
	if(mTestMenu) {
		mTestMenu->setHeight(height);
		TDDHelper::alignNode(mTestMenu, mMenuAlign);		// reset the test menu
	}
}

void TDDBaseTest::setMenuSize(const Size &size)
{
	if(mTestMenu) {
		mTestMenu->setContentSize(size);
		TDDHelper::alignNode(mTestMenu, mMenuAlign);		// reset the test menu
	}
}

void TDDBaseTest::alignMenu(const TDDAlign &align)
{
	if(mTestMenu == nullptr) {
		return;
	}
	
	mMenuAlign = align;
	TDDHelper::alignNode(mTestMenu, mMenuAlign);
}


#pragma mark - Test Info
std::string TDDBaseTest::getTestName()
{
	return mCurrentTestName;
}


#pragma mark - Assertion Logic
void TDDBaseTest::assertEquals(int expect, int actual, const std::string &remark)
{
	TDDAssertInfo *info = TDDAssertInfo::create(getTestName());
	info->setIsPassed(expect == actual);
	info->setRemark(remark);
	if(! info->getIsPassed()) {
		info->setResult(StringUtils::format("expect <%d> but <%d>", expect, actual));
	}
	
	if(mBreakWhenFail) {
		CC_ASSERT(info->getIsPassed());
	}
}

void TDDBaseTest::assertTrue(bool cond, const std::string &remark)
{
	//CC_ASSERT(<#cond#>)
	TDDAssertInfo *info = TDDAssertInfo::create(getTestName());
	info->setIsPassed(true == cond);
	info->setRemark(remark);
	if(! info->getIsPassed()) {
		info->setResult("expect true");
	}
	
	if(mBreakWhenFail) {
		CC_ASSERT(info->getIsPassed());
	}
}

#endif
