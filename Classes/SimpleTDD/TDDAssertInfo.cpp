//
//  TDDAssert.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 23/9/2016.
//
//

#include "TDDAssertInfo.h"

TDDAssertInfo *TDDAssertInfo::create(const std::string &methodName)
{
	TDDAssertInfo *info = new TDDAssertInfo();
	
	info->setMethodName(methodName);
	
	// make autorelease and return
	info->autorelease();
	return info;
}

TDDAssertInfo::TDDAssertInfo()
: mIsPassed(false)
, mRemark("")
, mResult("")
{
	
}

std::string TDDAssertInfo::toString()
{

	std::string result = mMethodName + ": ";
	if(mIsPassed) {
		result += " [PASS]";
	} else {
		result += " [FAIL] ";
		result += mResult;
		result += ": " + mRemark;
	}
	
	return result;
	//if(
}

