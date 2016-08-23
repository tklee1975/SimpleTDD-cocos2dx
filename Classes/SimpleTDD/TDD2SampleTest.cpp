//
//  TDD2SampleTest.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 24/8/2016.
//
//

#include "TDD2SampleTest.h"


void TDD2SampleTest::setUp()
{
	log("Sample Test for SimpleTDD 2.x");
}

void TDD2SampleTest::tearDown()
{
	log("Test is tearDown (before onExit)");
}


void TDD2SampleTest::defineTests()
{
	ADD_TEST(test1);
	ADD_TEST(test2);
	ADD_TEST(test3);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDD2SampleTest::test1()
{
	log("hello this is test1");
}

void TDD2SampleTest::test2()
{
	log("hello this is test2");
}


void TDD2SampleTest::test3()
{
	log("hello this is test3");
}