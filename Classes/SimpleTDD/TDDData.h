//
//  TDDData.h
//  Cocos2dxTDDLib
//
//  Created by Ken Lee on 14/8/14.
//
//
#ifdef ENABLE_TDD

#ifndef __Cocos2dxTDDLib__TDDData__
#define __Cocos2dxTDDLib__TDDData__

#include <iostream>
#include <vector>
#include <string>
#include "TDDTypes.h"

class TDDData
{
public:
	static TDDData *instance();
	
	std::string toString();

	void addTest(const std::string &testName);
	void setMenuMode(const TDDMenuMode &mode);
	TDDMenuMode getMenuMode();
	void clearHistory();
	
	void save();
	void load();
	std::vector<std::string> getTestHistory();
	
	
private:
	TDDData();
	
private:
	std::vector<std::string> mTestHistory;
	TDDMenuMode mMenuMode;
};

#endif /* defined(__Cocos2dxTDDLib__TDDData__) */

#endif /* ENABLE_TDD */