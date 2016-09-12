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

// ZOrder
const int kZorderBackground = -10000;
const int kZorderTestMenu = 10000;
const TDDAlign kDefaultMenuAlign = TDDAlign::eTDDTopRight;

TDDBaseTest::TDDBaseTest()
: mBaseNode(nullptr)
, mMenuAlign(eTDDTopRight)
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

	willRunTest(name);

	callback();

	didRunTest(name);
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

void TDDBaseTest::setMenuSize(const Size &size)
{
	if(mTestMenu == nullptr) {
		return;
	}

	mTestMenu->setContentSize(size);
	// Size newSize = mTestMenu->getContentSize();
	// log("debug: setMenuSize. newSize=%f,%f", newSize.width, newSize.height);
	TDDHelper::alignNode(mTestMenu, mMenuAlign);		// reset the test menu
	mTestMenu->refreshTable();
	
}


#endif
