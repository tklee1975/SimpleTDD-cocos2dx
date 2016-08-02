//
//  TDDManager.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 2/8/2016.
//
//

#ifndef TDDManager_hpp
#define TDDManager_hpp

#include <stdio.h>
#include "cocos2d.h"
#include <vector>

#include "TDDTypes.h"
#include "TDDTest.h"		// contain the data structure
#include <string>
#include <vector>

USING_NS_CC;

class TDDManager
{
public:
	static TDDManager *instance();
	
private:
	TDDManager();
	
public:
	CC_SYNTHESIZE(std::string, mFontName, FontName);
	
public:
	void loadTestList();
	std::string infoAllTest();
	
	std::vector<std::string> getRecentTestList(const std::string &filterName);
	std::vector<std::string> getTestList(const std::string &filterName);
	
	bool runTest(const std::string &name);
	const TDDTestCase *getTest(const std::string &name);
	
private:
	std::vector<std::string> getFilteredList(std::vector<std::string> &list, const std::string &filterName);
	
private:
	std::vector<std::string> mTestList;		// This array keep the original order
	std::map<std::string, TDDTestCase *> mTestMap;	// This help faster access to the TestCase Data
	//Vector<std::str
};


#endif /* TDDManager_hpp */
