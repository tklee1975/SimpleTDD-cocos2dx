//
//  TDDAssert.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 23/9/2016.
//
//

#ifndef TDDAssert_hpp
#define TDDAssert_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class TDDAssertInfo : public Ref
{
public:
	
	static TDDAssertInfo *create(const std::string &methodName);
	
	TDDAssertInfo();
public:
	
	CC_SYNTHESIZE(std::string, mMethodName, MethodName);	// Name of the test method
	CC_SYNTHESIZE(std::string, mResult, Result);		// assert result: e.g: expect<123> but<234>
	CC_SYNTHESIZE(std::string, mRemark, Remark);		// remark defined by user
	CC_SYNTHESIZE(bool, mIsPassed, IsPassed);
	
	std::string toString();
};

#endif /* TDDAssert_hpp */
