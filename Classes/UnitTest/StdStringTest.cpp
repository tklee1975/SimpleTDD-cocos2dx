#ifdef ENABLE_TDD
//
//  StdStringTest.m
//	TDD Framework
//	Reference:
//			http://www.cplusplus.com/reference/string/string/
//
//
#include "StdStringTest.h"
#include "TDDHelper.h"
#include <string>

void StdStringTest::setUp()
{
	log("TDD Setup is called");
}


void StdStringTest::tearDown()
{
	log("TDD tearDown is called");
}

void StdStringTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void StdStringTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void StdStringTest::defineTests()
{
	ADD_TEST(test_rfind);
}

#pragma mark -
#pragma mark Sub Test Definition
void StdStringTest::test_rfind()
{
	// http://www.cplusplus.com/reference/string/string/rfind/
	log("this is a sample subTest");
	
	std::string file = "workspace/ccx3/project/SimpleTDD/Classes/UnitTest/TDDAssertTest.cpp";
	
	std::size_t found = file.rfind("/");
	
	std::string lastName = found == std::string::npos ? file : file.substr(found + 1);
	
	log("file=%s", file.c_str());
	log("lastName=%s", lastName.c_str());
}


#endif
