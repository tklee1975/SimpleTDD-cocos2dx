#ifdef ENABLE_TDD
//
//  TDDSuiteLayerTest.m
//	TDD Framework 
//
//
#include "TDDSuiteLayerTest.h"
#include "TDDHelper.h"
#include "TDDSuite.h"

void TDDSuiteLayerTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDSuiteLayerTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDSuiteLayerTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDSuiteLayerTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDSuiteLayerTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	Point pos = Point(0, -100);
	
	TDDSuiteLayer *layer = new TDDSuiteLayer();
	layer->setPosition(pos);
	addChild(layer);
	layer->release();
	
	

}


#endif
