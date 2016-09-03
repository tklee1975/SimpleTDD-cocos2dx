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

void TDDMainLayerTest::defineTests()
{
	ADD_TEST(testCreate);
	ADD_TEST(testScene);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDMainLayerTest::testCreate()
{
	TDDMainLayer *mainLayer = TDDMainLayer::create();
	
	addChild(mainLayer);
}

void TDDMainLayerTest::testScene()
{
	auto scene = TDDMainLayer::createScene();
	
	Director::getInstance()->pushScene(scene);
}


#endif
