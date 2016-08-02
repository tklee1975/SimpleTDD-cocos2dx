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


USING_NS_CC;

class TDDManager
{
public:
	static TDDManager *instance();

private:
	TDDManager();
	
	
	
public:
	void loadTestList();
	std::string infoAllTest();
	void runTest(const std::string &name);
	const TDDTestCase getTest(const std::string &name) &;
	
private:
	std::map<std::string, TDDTestCase> mTestMap;
	//Vector<std::str
};


#endif /* TDDManager_hpp */
