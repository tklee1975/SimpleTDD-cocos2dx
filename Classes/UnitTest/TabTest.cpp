#ifdef ENABLE_TDD
//
//  TabTest.m
//	TDD Framework 
//
//
#include "TabTest.h"
#include "TDDHelper.h"
#include "cocostudio/CocoStudio.h"
#include "TDDTab.h"


void TabTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TabTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TabTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TabTest::testSimple);
	SUBTEST(TabTest::testCallback);
}

#pragma mark -
#pragma mark Sub Test Definition
void TabTest::testSimple(Ref *sender)
{
	//log("this is a sample subTest");
	// TabControl
	TDDTab *tab = TDDTab::create();
	
	tab->addTab("Page1");
	tab->addTab("Page2");
	tab->addTab("Page3");
	
	tab->selectTab(0);
	
	addChild(tab);
}


void TabTest::testCallback(Ref *sender)
{
	//log("this is a sample subTest");
	// TabControl
	TDDTab *tab = TDDTab::create();
	
	tab->addTab("Page1");
	tab->addTab("Page2");
	tab->addTab("Page3");

	tab->setCallback([](Ref *tabControl, int selected, bool isRepeat) {
		log("selected: %d isRepeat=%d", selected, isRepeat);
	});
	
	tab->selectTab(0);
	
	addChild(tab);
}


#endif
