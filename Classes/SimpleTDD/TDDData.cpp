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

#define kKeyTestHistory		"tddccx3.testHistory"
#define kKeyMenuMode		"tddccx3.menuMode"

// singleton stuff
static TDDData *sShareInstance = nullptr;

TDDData::TDDData()
: mMenuMode(TDDMenuModeAll)
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
	
	// Save the menuMode
	char temp[100];
	sprintf(temp, "%d", mMenuMode);
	TDDHelper::saveStringToDevice(kKeyMenuMode, temp);
}

void TDDData::load()
{
	
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
	
	// menuMode
	content = TDDHelper::loadStringFromDevice(kKeyMenuMode);
	if(content.length() == 0) {
		mMenuMode = TDDMenuModeAll;
	} else {
		sscanf(content.c_str(), "%d", &mMenuMode);
	}
}

std::string TDDData::toString()
{
	char tempStr[300];
	
	std::string result = "";
	sprintf(tempStr, "Menu Mode: %d\n", mMenuMode);
	result.append(tempStr);
	
	// Count
	sprintf(tempStr, "History count: %ld\n", mTestHistory.size());
	result.append(tempStr);
	
	// List of history test
	for(int i=0; i<mTestHistory.size(); i++) {
		result.append(mTestHistory[i]);
		result.append("\n");
	}
	
	return result;
}

std::vector<std::string> TDDData::getTestHistory()
{
	return mTestHistory;
}

void TDDData::setMenuMode(const TDDMenuMode &mode)
{
	mMenuMode = mode;
	save();
}

TDDMenuMode TDDData::getMenuMode()
{
	return mMenuMode;
}

#endif /* ENABLE_TDD */