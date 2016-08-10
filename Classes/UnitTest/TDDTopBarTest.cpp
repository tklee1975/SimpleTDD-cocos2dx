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
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDTopBarTest::subTest(Ref *sender)
{
	TDDTopBar *topBar = TDDTopBar::create(Size(300, 60));
	
	addChild(topBar);
}


#endif
