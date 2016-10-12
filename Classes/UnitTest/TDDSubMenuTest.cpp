#ifdef ENABLE_TDD
//
//  TDDSubMenuTest.m
//	TDD Framework 
//
//
#include "TDDSubMenuTest.h"
#include "TDDHelper.h"
#include "TDDSubMenu.h"

void TDDSubMenuTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	Size size = Size(200, 200);
	TDDSubMenu *menu = new TDDSubMenu(size);
	menu->setPosition(Point(0, 100));
	this->addChild(menu);
	mMenu = menu;
}


void TDDSubMenuTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDSubMenuTest::defineTests()
{
	ADD_TEST(subTest);
	ADD_TEST(testMenu);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDSubMenuTest::subTest()
{
	log("this is a sample subTest");
	
	Size size = Size(200, 200);
	TDDSubMenu *menu = new TDDSubMenu(size);
	menu->setPosition(Point(100, 120));
	
	menu->setBackAction(this, cccontrol_selector(TDDSubMenuTest::onBackPressed));
	
	this->addChild(menu);
}

void TDDSubMenuTest::onBackPressed(Ref *sender, cocos2d::extension::Control::EventType controlEvent)
{
	log("onBackPressed: is called");
}

void TDDSubMenuTest::testMenu()
{
	log("this is a sample subTest");
	
	Size size = Size(200, 200);
	TDDSubMenu *menu = new TDDSubMenu(size);
	menu->setPosition(Point(100, 120));
	
	this->addChild(menu);
	
	Vector<MenuItem *> menuArray;
	// setSubTest(menuArray);
	
	menu->setSubTest(menuArray);
}


#endif
