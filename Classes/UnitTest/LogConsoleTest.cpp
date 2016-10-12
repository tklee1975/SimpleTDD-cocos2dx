#ifdef ENABLE_TDD
//
//  LogConsoleTest.m
//	TDD Framework
//
//
#include "LogConsoleTest.h"
#include "TDDHelper.h"

void LogConsoleTest::setUp()
{
	log("TDD Setup is called");
}


void LogConsoleTest::tearDown()
{
	log("TDD tearDown is called");
}

void LogConsoleTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void LogConsoleTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void LogConsoleTest::defineTests()
{
	ADD_TEST(testSample);
}

#pragma mark -
#pragma mark Sub Test Definition
void LogConsoleTest::testSample()
{
	log("this is a sample subTest");
}


#endif
