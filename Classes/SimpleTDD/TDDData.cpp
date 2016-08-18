//
//  TDDData.cpp
//  Cocos2dxTDDLib
//
//  Created by Ken Lee on 14/8/14.
//
//
#ifdef ENABLE_TDD

#include "TDDData.h"
#include "TDDHelper.h"

#define kKeyTestHistory		"simpleTDD.ccx.history"
#define kKeySearchType		"simpleTDD.ccx.searchType"
#define kKeyKeywordAll		"simpleTDD.ccx.keyword.all"
#define kKeyKeywordRecent	"simpleTDD.ccx.keyword.recent"

// singleton stuff
static TDDData *sShareInstance = nullptr;

TDDData::TDDData()
: mSearchType(TDDSearchAll)
, mKeywordAll("")
, mKeywordRecent("")
{
	
}

TDDData *TDDData::instance()
{
    if (!sShareInstance)
    {
        sShareInstance = new TDDData();
		sShareInstance->load();
    }
	
    return sShareInstance;
}

void TDDData::addTest(const std::string &testName)
{
	// Remove the existing first
	vector<std::string>::iterator it;
	for(it = mTestHistory.begin(); it != mTestHistory.end(); )
	{
		std::string value = *it;
		if(value.compare(testName) == 0) {
			mTestHistory.erase(it);
		} else {
			it++;
		}
	}
	
	//
	it = mTestHistory.begin();
	
	mTestHistory.insert(it, testName);
//	mTestHistory

	save();
}

void TDDData::clearHistory()
{
	if(mTestHistory.size() <= 1) {
		// No need to clear
		return;
	}
	
	vector<std::string>::iterator begin = mTestHistory.begin() + 1;
	vector<std::string>::iterator end = mTestHistory.end();
	
	mTestHistory.erase(begin, end);
	
	save();
}

void TDDData::save()
{
	// Combine the history first
	std::string content = TDDHelper::joinString(mTestHistory, "\n");
	TDDHelper::saveStringToDevice(kKeyTestHistory, content);
	
	// Save the search type
	std::string value = mSearchType == TDDSearchRecent ? "recent" : "all";
	TDDHelper::saveStringToDevice(kKeySearchType, value);
}

void TDDData::load()
{
	// Load keyword
	mKeywordRecent = TDDHelper::loadStringFromDevice(kKeyKeywordRecent);
	mKeywordAll = TDDHelper::loadStringFromDevice(kKeyKeywordAll);
	
	
	// Load the test history
	std::string content = TDDHelper::loadStringFromDevice(kKeyTestHistory);
	std::vector<std::string> history = TDDHelper::splitString(content, '\n', 0);
	
	mTestHistory.clear();
	
	//
	for(int i=0; i<history.size(); i++)
	{
		std::string str = history[i];
		if(str.length() == 0) {
			continue;
		}
		mTestHistory.push_back(str);
	}
	
	// Search Type
	content = TDDHelper::loadStringFromDevice(kKeySearchType);
	mSearchType = (content == "recent") ? TDDSearchRecent : TDDSearchAll;
}

std::string TDDData::toString()
{
	std::string result = "";
	
	result += StringUtils::format("SearchType=%d\n", mSearchType);
	result += StringUtils::format("History count=%ld\n", mTestHistory.size());
	
	// List of history test
	for(int i=0; i<mTestHistory.size(); i++) {
		result += mTestHistory[i];
		result += "\n";
	}
	
	return result;
}

std::vector<std::string> TDDData::getTestHistory()
{
	return mTestHistory;
}

void TDDData::setSearchType(const TDDSearchType &searchType)
{
	mSearchType = searchType;
	save();
}

TDDSearchType TDDData::getSearchType()
{
	return mSearchType;
}

void TDDData::saveKeyword(TDDSearchType type, const std::string &keyword)
{
	if(TDDSearchAll == type) {
		mKeywordAll = keyword;
		TDDHelper::saveStringToDevice(kKeyKeywordAll, keyword);
	} else if(TDDSearchRecent == type) {
		mKeywordRecent = keyword;
		TDDHelper::saveStringToDevice(kKeyKeywordRecent, keyword);
	}
}

std::string TDDData::getKeyword(TDDSearchType type)
{
	if(TDDSearchAll == type) {
		return mKeywordAll;
	} else if(TDDSearchRecent == type) {
		return mKeywordRecent;
	} else {
		return "";
	}
}

#endif /* ENABLE_TDD */