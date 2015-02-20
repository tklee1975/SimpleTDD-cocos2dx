#ifdef ENABLE_TDD
//
//  SwitchTest.m
//	TDD Framework 
//
//
#include "SwitchTest.h"
#include "TDDHelper.h"
#include "extensions/cocos-ext.h"

USING_NS_CC_EXT;

void SwitchTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void SwitchTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void SwitchTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(SwitchTest::testSimple);
}

#pragma mark -
#pragma mark Sub Test Definition
void SwitchTest::testSimple(Ref *sender)
{
	log("this is a sample subTest");
	
	
}


#endif
