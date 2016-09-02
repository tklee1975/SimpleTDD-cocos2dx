#ifdef ENABLE_TDD
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
	ADD_TEST(testSetBackground);
	ADD_TEST(testAddSomethings);
	ADD_TEST(testClearChildren);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDD2SampleTest::test1()
{
	log("hello this is test1");
	setBackgroundColor(Color3B::GRAY);
}

void TDD2SampleTest::testSetBackground()
{
	setBackgroundColor(Color3B::BLUE);
}

void TDD2SampleTest::testAddSomethings()
{
	float x = RandomHelper::random_int(0, 300);
	float y = RandomHelper::random_int(0, 300);

	Label *label = Label::createWithSystemFont("Testing", "", 15);
	label->setPosition(Vec2(x, y));
	addChild(label);
}

void TDD2SampleTest::testClearChildren()
{
	clearChildren();
}

#endif
