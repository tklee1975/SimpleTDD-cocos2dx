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
}


void TDDSubMenuTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDSubMenuTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDSubMenuTest::subTest);
	SUBTEST(TDDSubMenuTest::testMenu);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDSubMenuTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	Size size = Size(200, 200);
	TDDSubMenu *menu = new TDDSubMenu(size);
	menu->setPosition(Point(100, 120));
	
	menu->setBackAction(this, cccontrol_selector(TDDSubMenuTest::onBackPressed));
	
	this->addChild(menu);
}

void TDDSubMenuTest::onBackPressed(Ref *sender, Control::EventType controlEvent)
{
	log("onBackPressed: is called");
}

void TDDSubMenuTest::testMenu(Ref *sender)
{
	log("this is a sample subTest");
	
	Size size = Size(200, 200);
	TDDSubMenu *menu = new TDDSubMenu(size);
	menu->setPosition(Point(100, 120));
	
	this->addChild(menu);
	
	Vector<MenuItem *> menuArray;
	setSubTest(menuArray);
	
	menu->setSubTest(menuArray);
}


#endif
