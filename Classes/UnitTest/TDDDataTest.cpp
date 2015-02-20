#ifdef ENABLE_TDD
//
//  TDDDataTest.m
//	TDD Framework 
//
//
#include "TDDDataTest.h"
#include "TDDHelper.h"
#include "TDDData.h"

void TDDDataTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDDataTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDDataTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDDataTest::testClearHistory);
	SUBTEST(TDDDataTest::testSave);
	SUBTEST(TDDDataTest::testLoad);
	SUBTEST(TDDDataTest::testAddTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDDataTest::testAddTest(Ref *sender)
{
	//log("this is a sample subTest");

	TDDData::instance()->addTest("HelloTest");
	TDDData::instance()->addTest("KittyTest");
	
	
	log("history:\n%s\n", TDDData::instance()->toString().c_str());
}

void TDDDataTest::testLoad(Ref *sender)
{
	//log("this is a sample subTest");
	
	TDDData::instance();
	
	
	log("%s\n", TDDData::instance()->toString().c_str());
}


void TDDDataTest::testSave(Ref *sender)
{
	//log("this is a sample subTest");
	
	TDDData::instance();
	
	TDDData::instance()->setMenuMode(TDDMenuModeHistory);
	
	TDDData::instance()->load();
	log("%s\n", TDDData::instance()->toString().c_str());
}

void TDDDataTest::testClearHistory(Ref *sender)
{
	log("Before Clear\n%s\n", TDDData::instance()->toString().c_str());
	
	TDDData::instance()->clearHistory();
	
	log("After Clear\n%s\n", TDDData::instance()->toString().c_str());
}

#endif
