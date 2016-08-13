#ifdef ENABLE_TDD
//
//  TDDHeaderLayerTest.m
//	TDD Framework 
//
//
#include "TDDTopBarTest.h"
#include "TDDHelper.h"
#include "TDDTopBar.h"

void TDDTopBarTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDTopBarTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDTopBarTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDTopBarTest::subTest);
	SUBTEST(TDDTopBarTest::testCallback);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDTopBarTest::subTest(Ref *sender)
{
	TDDTopBar *topBar = TDDTopBar::create(Size(300, 60));
	
	addChild(topBar);
}

void TDDTopBarTest::testCallback(Ref *sender)
{
	TDDTopBar *topBar = TDDTopBar::create(Size(300, 60));
	
	topBar->setup(TDDTopBarTabRecent, "game");
	
	addChild(topBar);
	
	topBar->setCloseListener([&](TDDTopBar *topBar){
		log("close is clicked");
	});
	
	topBar->setTabChangeListener([&](TDDTopBar *topBar, TDDTopBarTab tab){
		log("tab change to %d", tab);
	});
	
	topBar->setKeywordChangeListener([&](TDDTopBar *topBar, const std::string &keyword){
		log("keyword change to %s", keyword.c_str());
	});
}


#endif
