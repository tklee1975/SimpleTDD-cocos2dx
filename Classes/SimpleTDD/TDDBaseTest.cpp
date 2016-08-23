//
//  TDDBaseTest.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 24/8/2016.
//
//

#include "TDDBaseTest.h"
#include "TDDTestMenu.h"

// ZOrder
const int kZorderBackground = -10000;
const int kZorderTestMenu = 10000;


TDDBaseTest::TDDBaseTest()
{
	
}

void TDDBaseTest::onEnter()
{
	Scene::onEnter();
	
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
	
	callback();
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