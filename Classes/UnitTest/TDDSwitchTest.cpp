#ifdef ENABLE_TDD
//
//  TDDSwitchTest.m
//	TDD Framework 
//
//
#include "TDDSwitchTest.h"
#include "TDDHelper.h"
#include "TDDSwitch.h"

void TDDSwitchTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDSwitchTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDSwitchTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDSwitchTest::subTest);
	SUBTEST(TDDSwitchTest::testMoveSwitch);
	SUBTEST(TDDSwitchTest::testThreeSwitch);
	SUBTEST(TDDSwitchTest::testSetSwitches);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDSwitchTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	TDDSwitch *switchControl = new TDDSwitch(Size(150, 40), Color4B::BLUE, Color4B::WHITE);
	
	switchControl->setPosition(Point(100, 50));
	
	addChild(switchControl);
}

//moveSwitchBg
void TDDSwitchTest::testMoveSwitch(Ref *sender)
{
	log("this is a sample subTest");
	
	TDDSwitch *switchControl = new TDDSwitch(Size(150, 40), Color4B::BLUE, Color4B::WHITE);
	
	switchControl->setPosition(Point(100, 50));
	
	addChild(switchControl);
	
	switchControl->moveSwitchBg(1);
}



void TDDSwitchTest::testSetSwitches(Ref *sender)
{
	log("testSetSwitches");
	
	TDDSwitch *switchControl = new TDDSwitch(Size(150, 40), Color4B::WHITE, Color4B::BLUE);
	
	switchControl->setPosition(Point(100, 50));
	
	addChild(switchControl);
	
	std::vector<std::string> switches;
	switches.push_back("all");
	switches.push_back("history");
	
	switchControl->setSwitches(switches, CC_CALLBACK_3(TDDSwitchTest::switchSelected, this));
}

void TDDSwitchTest::switchSelected(Ref *sender, std::string name, int selected)
{
	log("selected switch: %s (%d)", name.c_str(), selected);
}


void TDDSwitchTest::testThreeSwitch(Ref *sender)
{
	log("testSetSwitches");
	
	TDDSwitch *switchControl = new TDDSwitch(Size(200, 50),
								Color4B::WHITE, Color4B::BLUE,
								Color3B::GRAY, Color3B::YELLOW,
								"GillSans", 16);
	
	switchControl->setPosition(Point(10, 150));
	
	addChild(switchControl);
	
	std::vector<std::string> switches;
	switches.push_back("all");
	switches.push_back("history");
	switches.push_back("top");
	
	switchControl->setSwitches(switches, CC_CALLBACK_3(TDDSwitchTest::switchSelected, this));
}

#endif
