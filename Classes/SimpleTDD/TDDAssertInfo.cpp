//
//  TDDAssert.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 23/9/2016.
//
//

#include "TDDAssertInfo.h"

namespace {
	std::string getShortName(const std::string &file)
	{
		std::size_t found = file.rfind("/");
		if(std::string::npos == found) {
			return file;
		}
		
		return file.substr(found + 1);
	}
}

TDDAssertInfo *TDDAssertInfo::create(const std::string &methodName,
										const std::string &file, int line)
{
	TDDAssertInfo *info = new TDDAssertInfo();
	
	std::string shortName = getShortName(file);
	
	info->setMethodName(methodName);
	info->setFile(shortName);
	info->setLine(line);
	
	// make autorelease and return
	info->autorelease();
	return info;
}

TDDAssertInfo::TDDAssertInfo()
: mIsPassed(false)
, mRemark("")
, mResult("")
, mFile("")
, mLine(-1)
{
	
}

std::string TDDAssertInfo::toString()
{

	std::string result = "";
	
	
	// Call Location and method
	result += getCallLocation() + ":";
	result += mMethodName + ":";
	
	if(mIsPassed) {
		result += " [PASS]";
	} else {
		result += " [FAIL] ";
		result += mResult;
	}

	result += ": " + mRemark;
	
	return result;
	//if(
}

std::string TDDAssertInfo::getCallLocation()
{
	return StringUtils::format("%s:%d", mFile.c_str(), mLine);
}