#ifdef ENABLE_TDD
//
//  UITextTest.m
//	TDD Framework
//
//
#include "UITextTest.h"
#include "TDDHelper.h"
#include "CocosGUI.h"

void UITextTest::setUp()
{
	log("TDD Setup is called");
}


void UITextTest::tearDown()
{
	log("TDD tearDown is called");
}

void UITextTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void UITextTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void UITextTest::defineTests()
{
	ADD_TEST(testSample);
}

#pragma mark -
#pragma mark Sub Test Definition
void UITextTest::testSample()
{
	log("this is a sample subTest");
	
	Vec2 pos = Vec2(100, 30);
	
	ui::Text *text = ui::Text::create("testing", "", 12);
	
	text->setPosition(pos);
	
	addChild(text);
}


#endif
