#ifdef ENABLE_TDD
//
//  TDD2SampleTest.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 24/8/2016.
//
//

#ifndef TDD2SampleTest_hpp
#define TDD2SampleTest_hpp

#include <stdio.h>

#include "TDDBaseTest.h"

class TDD2SampleTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();

private:
	void test1();
	void testSetBackground();
	void testAddSomethings();
	void testClearChildren();
	void testToggleStat();
	void testHideMenu();
};


#endif /* TDD2SampleTest_hpp */

#endif
