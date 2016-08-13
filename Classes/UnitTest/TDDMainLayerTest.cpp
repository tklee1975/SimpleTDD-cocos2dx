#ifdef ENABLE_TDD
//
//  TDDMainLayerTest.m
//	TDD Framework 
//
//
#include "TDDMainLayerTest.h"
#include "TDDHelper.h"
#include "TDDMainLayer.h"

void TDDMainLayerTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDMainLayerTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDMainLayerTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDMainLayerTest::testCreate);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDMainLayerTest::testCreate(Ref *sender)
{
	TDDMainLayer *mainLayer = TDDMainLayer::create();
	
	addChild(mainLayer);
	
}


#endif
