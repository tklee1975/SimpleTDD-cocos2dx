#ifdef ENABLE_TDD
//
//  LabelTest.m
//	TDD Framework 
//
//
#include "LabelTest.h"
#include "TDDHelper.h"

void LabelTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	this->setColor(Color3B::GRAY);
}


void LabelTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void LabelTest::defineTests()
{
	ADD_TEST(testOutlineBug);
	ADD_TEST(testDefaultFont);
	ADD_TEST(testTTF);
}

#pragma mark -
#pragma mark Sub Test Definition
void LabelTest::testTTF()
{
	log("this is a sample subTest");
	
	// note: the ttf file must be exist!!!
	TTFConfig config("fonts/Marker Felt.ttf", 20, GlyphCollection::NEHE);
	std::string text = "Hello!!";
	auto label = Label::createWithTTF(config, text);
	
	label->setPosition(Point(200, 100));
	addChild(label);
}

void LabelTest::testDefaultFont()
{
	log("testDefaultFont");
	
	setBackgroundColor(Color3B::WHITE);
	
	// note: the ttf file must be exist!!!
	std::string text = "Hello!!";
	auto label = Label::create();
	label->setString(text);
	
	label->setPosition(Point(200, 100));
	addChild(label);
	
	// http://blog.csdn.net/star530/article/details/22313087
	// System Font
	std::string sysFont = "arial";
	// std::string sysFont = "applegothic";
	// std::string sysFont = "GillSans";
	label = Label::createWithSystemFont("System Font", sysFont, 40);
	label->setColor(Color3B::WHITE);
	label->setPosition(Point(200, 300));
	// label->disableEffect();		// it doesn't work
	label->enableOutline(Color4B::GREEN, 3);
	label->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);   // Why???
	// label->setBlendFunc(BlendFunc::DISABLE);
		
	
	addChild(label);
	
	
}


void LabelTest::testOutlineBug()
{
	log("testDefaultFont");
	
	setBackgroundColor(Color3B::WHITE);
	//std::string sysFont = "arial black";
	std::string sysFont = "GillSans";
	//std::string sysFont = "applegothic";
	std::string test1 = "No BlendFunc";
	std::string test2 = "ALPHA_PREMULTIPLIED";
	Label *label;
	
	Color3B textColor = Color3B(200, 245, 245);
	
	// http://blog.csdn.net/star530/article/details/22313087
	// System Font
	
	// std::string sysFont = "applegothic";
	// std::string sysFont = "GillSans";
	label = Label::createWithSystemFont(test1, sysFont, 40);
	label->setColor(textColor);
	label->setPosition(Point(250, 300));
	addChild(label);
	
	label = Label::createWithSystemFont(test2, sysFont, 40);
	label->setColor(textColor);
	label->setPosition(Point(250, 200));
	label->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
	addChild(label);
	

}


#endif
