#ifdef ENABLE_TDD
//
//  TDDAssertTest.m
//	TDD Framework
//
//
#include "TDDAssertTest.h"
#include "TDDHelper.h"

void TDDAssertTest::setUp()
{
	log("TDD Setup is called");
}


void TDDAssertTest::tearDown()
{
	log("TDD tearDown is called");
}

void TDDAssertTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void TDDAssertTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TDDAssertTest::defineTests()
{
	ADD_TEST(testAssertEqual);
	ADD_TEST(testAssertTrue);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDAssertTest::testAssertEqual()
{
	log("test assertEquals");
	
	int result = 20;
	assertEquals(10, result, "error case for equal check for int");
	assertEquals(20, result, "success case for equal check for int");
	
	float resultFloat = 12.34;
	assertEquals(12.3f, resultFloat, "error case for equal check for float");
	assertEquals(12.34f, resultFloat, "success case for equal check for float");
	
	double resultDouble = 12.34;
	assertEquals(12.3, resultDouble, "error case for equal check for double");
	assertEquals(12.34, resultDouble, "success case for equal check for double");
}

void TDDAssertTest::testAssertTrue()
{
	log("test assertEquals");
	
	assertTrue(false, "error case for true checking");
	assertTrue(true, "success case for true checking");
}


#endif
