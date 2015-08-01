#ifdef ENABLE_TDD
//
//  SampleTest.h
//  TDDLib
//
//  Created by Ken Lee on 15/12/13.
//
//

#ifndef __TDDLib__SampleTest__
#define __TDDLib__SampleTest__

#include <iostream>
#include "TDDTest.h"

class TDDSample1 : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void test1(Ref *sender);
	void test2(Ref *sender);
	void test3(Ref *sender);
};

#endif /* defined(__Dg__SampleTest__) */
#endif