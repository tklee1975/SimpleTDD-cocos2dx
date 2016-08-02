//
//  TDDManager.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 2/8/2016.
//
//

#include "TDDManager.h"



//  Building the gTestArray
#define TEST(__ClassName__)		 			{#__ClassName__, []() { return new __ClassName__(); } }
#define TDD_CASES							TDDTestCase sTestArray[] =

#include "MyTestCases.h"
//

static TDDManager *sInstance = nullptr;

TDDManager *TDDManager::instance()
{
	if(sInstance == nullptr) {
		sInstance = new TDDManager();
	}
	
	return sInstance;
}


TDDManager::TDDManager()
: mTestMap()
{
	
}

void TDDManager::loadTestList()
{
	mTestMap.clear();
	
	int testCount = sizeof(sTestArray) / sizeof(sTestArray[0]);
	
	for(int i=0; i<testCount; i++) {
		TDDTestCase testCase = sTestArray[i];
		
		std::string name(testCase.name);
		
		mTestMap[name] = testCase;
	}
}

void TDDManager::runTest(const std::string &name)
{
	
}

const TDDTestCase TDDManager::getTest(const std::string &name) &
{
	return mTestMap[name];
}


std::string TDDManager::infoAllTest()
{
	std::string result = StringUtils::format("Test Count: %d\n", (int) mTestMap.size());
	
	std::map<std::string, TDDTestCase>::iterator it = mTestMap.begin();
	
	for(; it != mTestMap.end(); it++) {
		std::string name = it->first;
		
		result += "- " + name + "\n";
	}
	
	return result;
}