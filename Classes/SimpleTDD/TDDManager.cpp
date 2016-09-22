//
//  TDDManager.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 2/8/2016.
//
//

#include "TDDManager.h"

#ifdef ENABLE_TDD
#include "TDDData.h"

// Version
const std::string kVersion = "2.2.0";
const std::string kName = "SimpleTDD";


//  Building the sTestArray
#define TEST(__ClassName__)		 			{#__ClassName__, []() { return new __ClassName__(); } }
#define TDD_CASES							static TDDTestCase sTestArray[] =

#include "MyTDDCases.h"
// Building the sTestArray (End)

//  Local helper method
namespace {
	std::string toUpper(std::string input) {
		for (std::string::iterator it = input.begin(); it != input.end(); ++ it)
		{
			*it = toupper(*it);
		}
		return input;
	}
	
	bool isTestMatch(const std::string &testName, const std::string &filterPattern)
	{
		if(filterPattern == "") {
			return true;
		}
		
		// Turn XXXTest -> XXX
		std::string name = testName;
		if(name.length() > 4) {
			name = name.substr(0, name.length()-4);
		}
		name = toUpper(name);
		
		
		// log("trimmed testName=[%s]", name.c_str());
		std::string filter = toUpper(filterPattern);
		
		std::size_t found = name.find(filter);
		
		return (found!=std::string::npos);
	}
	
	
}


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
, mTestList()
, mFontName("")
{
	loadTestList();
	loadData();
}

void TDDManager::loadTestList()
{
	mTestMap.clear();
	mTestList.clear();
	
	int testCount = sizeof(sTestArray) / sizeof(sTestArray[0]);
	
	for(int i=0; i<testCount; i++) {
		TDDTestCase *testCase = &sTestArray[i];
		
		std::string name(testCase->name);
		
		mTestList.push_back(name);
		mTestMap[name] = testCase;
	}
}

void TDDManager::loadData()
{
	TDDData::instance()->load();
}

bool TDDManager::runTest(const std::string &name)
{
	const TDDTestCase *test = getTest(name);
	if(test == nullptr) {
		log("TDDManager: test %s not found", name.c_str());
		return false;
	}
	
	auto scene = test->callback();
	if (scene)
	{
		// mark the data
		TDDData::instance()->addTest(name);
		
		// Show the scene
		Director::getInstance()->pushScene(scene);
		scene->release();
		return true;
	} else {
		
		log("TDDManager: test %s scene not found", name.c_str());
		
		return false;
	}

	
}

const TDDTestCase *TDDManager::getTest(const std::string &name) 
{
	return mTestMap[name];
}


std::string TDDManager::infoAllTest()
{
	std::string result = StringUtils::format("Test Count: %d\n", (int) mTestMap.size());
	
	std::map<std::string, TDDTestCase *>::iterator it = mTestMap.begin();
	
	for(; it != mTestMap.end(); it++) {
		std::string name = it->first;
		
		result += "- " + name + "\n";
	}
	
	return result;
}

std::vector<std::string> TDDManager::getRecentTestList(const std::string &filterName)
{
	std::vector<std::string> testList = TDDData::instance()->getTestHistory();
	return getFilteredList(testList, filterName);
}

std::vector<std::string> TDDManager::getTestList(const std::string &filterName)
{
	return getFilteredList(mTestList, filterName);
}

std::vector<std::string> TDDManager::getFilteredList(std::vector<std::string> &list,
													 const std::string &filterName)
{
	std::vector<std::string> result;
	
	std::vector<std::string>::iterator it;
	
	for(it = list.begin(); it != list.end(); it++) {
		std::string testName = *it;
		
		if(isTestMatch(testName, filterName)) {
			result.push_back(testName);
		}
	}
	
	return result;
}

TDDSearchType TDDManager::getSearchType()
{
	return TDDData::instance()->getSearchType();
}

void TDDManager::saveSearchType(TDDSearchType type)
{
	TDDData::instance()->setSearchType(type);
}

std::string TDDManager::getKeyword(TDDSearchType type)
{
	return TDDData::instance()->getKeyword(type);
}

void TDDManager::saveKeyword(TDDSearchType type, const std::string &keyword)
{
	TDDData::instance()->saveKeyword(type, keyword);
}

std::string TDDManager::getVersion(bool withName)
{
	if(withName) {
		return kName + " " + kVersion;
	} else {
		return kVersion;
	}
}

int TDDManager::getTestCount()
{
	return (int) mTestMap.size();
}

#endif