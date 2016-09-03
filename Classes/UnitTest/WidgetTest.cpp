#ifdef ENABLE_TDD
//
//  WidgetTest.m
//	TDD Framework 
//
//
#include "WidgetTest.h"
#include "TDDHelper.h"

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <string>
#include <vector>
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

void WidgetTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void WidgetTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void WidgetTest::defineTests()
{
	ADD_TEST(testButton);
}

#pragma mark -
#pragma mark Sub Test Definition
void WidgetTest::testButton()
{
	log("this is a sample subTest");
	
	cocos2d::ui::Button *button = cocos2d::ui::Button::create();
	
	Size buttonSize = Size(100, 50);
	Vec2 pos = Vec2(50, 50);
	
	// Add background
	LayerColor *bg = LayerColor::create(Color4B::YELLOW, buttonSize.width, buttonSize.height);
	bg->setPosition(pos - Vec2(buttonSize.width/2, buttonSize.height/2));
	addChild(bg);
	
	
	// configure the button
	button->setTitleText("Click Me");	// for debugging
	//button->setContentSize(buttonSize);		// no use!!
	button->setTitleAlignment(TextHAlignment::LEFT);	// not working
	button->setTitleColor(Color3B::BLUE);
	
	// button->setAnchorPoint(Vec2(0, 0));
	button->setPosition(pos);

	addChild(button);
	
	
	// Button with background
	pos = Vec2(200, 50);
	button = cocos2d::ui::Button::create("buttonSmall.png");
	button->setTitleText("Click Me");
	button->setScale9Enabled(true);
	// button->setTitleAlignment(TextHAlignment::LEFT);
	button->setContentSize(Size(100, 100));
	button->setAnchorPoint(Vec2(0, 0));
	button->setPosition(pos);
	
	addChild(button);
	
}


#endif
