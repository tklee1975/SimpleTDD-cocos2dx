#ifdef ENABLE_TDD
//
//  ScrollTest.m
//	TDD Framework 
//
//
#include "ScrollTest.h"
#include "TDDHelper.h"

void ScrollTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void ScrollTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void ScrollTest::defineTests()
{
	ADD_TEST(subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void ScrollTest::subTest()
{
	log("this is a sample subTest");
	
	// LayerColor *colorLayer = LayerColor::create(Color4B::RED, 300, 400);
	LayerGradient *colorLayer = LayerGradient::create(Color4B::RED, Color4B::GREEN);
	colorLayer->changeWidthAndHeight(200, 500);
	
	
	ScrollView *scrollView = ScrollView::create(Size(300, 200));
	scrollView->setPosition(Point(50, 50));
	
	scrollView->setContainer(colorLayer);
	scrollView->setDirection(ScrollView::Direction::VERTICAL);
	
	addChild(scrollView);
}


#endif
