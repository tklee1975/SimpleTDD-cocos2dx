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

void TDDDataTest::defineTests()
{
	ADD_TEST(testClearHistory);
	ADD_TEST(testSave);
	ADD_TEST(testLoad);
	ADD_TEST(testAddTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDDataTest::testAddTest()
{
	//log("this is a sample subTest");

	TDDData::instance()->addTest("HelloTest");
	TDDData::instance()->addTest("KittyTest");
	
	
	log("history:\n%s\n", TDDData::instance()->toString().c_str());
}

void TDDDataTest::testLoad()
{
	//log("this is a sample subTest");
	
	TDDData::instance();
	
	
	log("%s\n", TDDData::instance()->toString().c_str());
}


void TDDDataTest::testSave()
{
	//log("this is a sample subTest");
	
	TDDData::instance();
	
	TDDData::instance()->setSearchType(TDDSearchRecent);
	
	TDDData::instance()->load();
	log("%s\n", TDDData::instance()->toString().c_str());
}

void TDDDataTest::testClearHistory()
{
	log("Before Clear\n%s\n", TDDData::instance()->toString().c_str());
	
	TDDData::instance()->clearHistory();
	
	log("After Clear\n%s\n", TDDData::instance()->toString().c_str());
}

#endif
