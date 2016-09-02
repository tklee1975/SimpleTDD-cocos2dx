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
	SUBTEST(TDDManagerTest::testGetTestList);
	SUBTEST(TDDManagerTest::testRunTest);
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

void TDDManagerTest::testRunTest(Ref *sender)
{
	TDDManager::instance()->loadTestList();
	
	TDDManager::instance()->runTest("LabelTest");
}

void TDDManagerTest::testGetTestList(Ref *sender)
{
	std::vector<std::string> fullList = TDDManager::instance()->getTestList("");
	
	log("fullList result:");
	for(int i=0; i<fullList.size(); i++) {
		log("%s", fullList[i].c_str());
	}
	
	std::vector<std::string> filterList = TDDManager::instance()->getTestList("TDD");
	for(int i=0; i<filterList.size(); i++) {
		log("%s", filterList[i].c_str());
	}
}

#endif
