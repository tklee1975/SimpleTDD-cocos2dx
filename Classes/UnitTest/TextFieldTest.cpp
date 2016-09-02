#ifdef ENABLE_TDD
//
//  TextFieldTest.m
//	TDD Framework
//
//
#include "TextFieldTest.h"
#include "TDDHelper.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;

void TextFieldTest::setUp()
{
	log("TDD Setup is called");
	mTextField = nullptr;
}


void TextFieldTest::tearDown()
{
	log("TDD tearDown is called");
}

void TextFieldTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
//	clearChildren();
}

void TextFieldTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TextFieldTest::defineTests()
{
	ADD_TEST(testSample);
	ADD_TEST(testCustomTextField);
	ADD_TEST(testClearText);
}

#pragma mark -
#pragma mark Sub Test Definition
void TextFieldTest::testSample()
{
	log("this is a sample subTest");
	
	ui::TextField *tf = ui::TextField::create();
	tf->setContentSize(Size(200, 50));
	tf->setPosition(Vec2(100, 100));
	
	addChild(tf);
}

void TextFieldTest::testCustomTextField()
{
	ui::TextField *tf = ui::TextField::create("Input your name", "xxx", 12);
	tf->setContentSize(Size(200, 50));
	tf->setPosition(Vec2(100, 100));
	
	tf->addEventListener([&](Ref *ref, ui::TextField::EventType type) {
		log("event: type=%d [%s]", type, mTextField->getString().c_str());
	});
	
	addChild(tf);
	
	mTextField = tf;
}

void TextFieldTest::testClearText()
{
	if(mTextField) {
		mTextField->setString("");
	}
}
#endif
