#ifdef ENABLE_TDD
//
//  BlockTest.m
//	TDD Framework 
//
//
#include "BlockTest.h"
#include "TDDHelper.h"

void BlockTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void BlockTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void BlockTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(BlockTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void BlockTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
}


#endif
