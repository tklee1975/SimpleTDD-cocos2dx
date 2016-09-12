#ifdef ENABLE_TDD
//
//  TestMenuTest.m
//	TDD Framework
//
//
#include "TestMenuTest.h"
#include "TDDHelper.h"

void TestMenuTest::setUp()
{
	log("TDD Setup is called");
}


void TestMenuTest::tearDown()
{
	log("TDD tearDown is called");
}

void TestMenuTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void TestMenuTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TestMenuTest::defineTests()
{
	ADD_TEST(testChangeSize);
}

#pragma mark -
#pragma mark Sub Test Definition
void TestMenuTest::testSample()
{
	log("this is a sample subTest");
}

void TestMenuTest::testHeaderColor()
{
	log("this is a sample subTest");
}

void TestMenuTest::testChangeSize()
{
	const int nSize = 3;
	Size sizeList[nSize] = {
		Size(300, 300),
		Size(100, 400),
		Size(400, 150),
	};
	
	static int index = 0;
	
	
	Size selectedSize = sizeList[index];
	
	// Change Size
	setMenuSize(selectedSize);
	
	
	// next index
	index = (index + 1) % nSize;
}

#endif
