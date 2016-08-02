#ifdef ENABLE_TDD
//
//  TDDManagerTest.m
//	TDD Framework 
//
//
#include "TDDManagerTest.h"
#include "TDDHelper.h"
#include "TDDManager.h"

void TDDManagerTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDManagerTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDManagerTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDManagerTest::testLoadTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDManagerTest::testLoadTest(Ref *sender)
{
	log("this is a sample subTest");
	
	TDDManager::instance()->loadTestList();
	
	log("%s", TDDManager::instance()->infoAllTest().c_str());
	
//	TDDManager::instance()->loadTest();
//	
//	log(
}


#endif
