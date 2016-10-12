#ifdef ENABLE_TDD
//
//  ScrollViewTest.m
//	TDD Framework 
//
//
#include "ScrollViewTest.h"
#include "TDDHelper.h"

void ScrollViewTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	mScrollView = nullptr;
	mScrollContent = nullptr;
}


void ScrollViewTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void ScrollViewTest::defineTests()
{
	ADD_TEST(subTest);
	ADD_TEST(testFromTop);
	ADD_TEST(testScrollTop);
	ADD_TEST(testScrollBottom);
}

#pragma mark -
#pragma mark Sub Test Definition
void ScrollViewTest::subTest()
{
	log("this is a sample subTest");
	
	LayerColor *scrollContent = LayerColor::create(Color4B::YELLOW, 300, 600);
	
	
	cocos2d::extension::ScrollView *scrollView = cocos2d::extension::ScrollView::create(Size(200, 200), scrollContent);
	mScrollContent = scrollContent;
	
	addChild(scrollView);
	
	// Add item to the scrollContent
	Vec2 pos = Vec2(10, 0);
	for(int i=0; i<50; i++) {
		std::string text = StringUtils::format("line %d", i);
		Label *label = Label::createWithSystemFont(text, "", 30);
		label->setAnchorPoint(Vec2(0, 0));
		label->setPosition(pos);
		label->setTextColor(Color4B::BLACK);
		
		scrollContent->addChild(label);
		
		pos.y += 50;
	}
	mScrollView = scrollView;
}

void ScrollViewTest::testFromTop()
{
	log("this is a sample subTest");
	
	LayerColor *scrollContent = LayerColor::create(Color4B::YELLOW, 300, 600);
	
	
	ScrollView *scrollView = ScrollView::create(Size(200, 200), scrollContent);
	
	
	addChild(scrollView);
	
	// Add item to the scrollContent
	Vec2 pos = Vec2(10, 600);
	for(int i=0; i<10; i++) {
		std::string text = StringUtils::format("line %d", i);
		Label *label = Label::createWithSystemFont(text, "", 30);
		label->setAnchorPoint(Vec2(0, 1));
		label->setPosition(pos);
		label->setTextColor(Color4B::BLACK);
		
		scrollContent->addChild(label);
		
		pos.y -= 50;
	}
	
	
	scrollView->setContentOffset(Vec2(0, -600+200));
	
	
}

void ScrollViewTest::testScrollTop()
{
	if(! mScrollView) {
		return;
	}
	
	Size scrollSize = mScrollView->getContentSize();
	Size viewSize = mScrollView->getViewSize();
	Size contentSize = mScrollContent->getContentSize();
	Vec2 offset = mScrollView->getContentOffset();
	
	// debug info
	log("scrollSize=%s viewSize=%s contentSize=%s offset=%s",
		TDD_SIZE_TO_STR(scrollSize).c_str(),
		TDD_SIZE_TO_STR(viewSize).c_str(),
		TDD_SIZE_TO_STR(contentSize).c_str(),
		TDD_VEC2_TO_STR(offset).c_str()
		);

	
	
	//float scrollHeight = mScrollView->getContentSize();
	float scrollOffset = -contentSize.height + viewSize.height;
	mScrollView->setContentOffsetInDuration(Vec2(0, scrollOffset), 0.2);
}

void ScrollViewTest::testScrollBottom()
{
	if(! mScrollView) {
		return;
	}
	
	
	Size scrollSize = mScrollView->getContentSize();
	Size viewSize = mScrollView->getViewSize();
	Size contentSize = mScrollContent->getContentSize();
	Vec2 offset = mScrollView->getContentOffset();
	
	// debug info
	log("scrollSize=%s viewSize=%s contentSize=%s offset=%s",
				TDD_SIZE_TO_STR(scrollSize).c_str(),
				TDD_SIZE_TO_STR(viewSize).c_str(),
				TDD_SIZE_TO_STR(contentSize).c_str(),
				TDD_VEC2_TO_STR(offset).c_str()
		);
	
	
	//
	mScrollView->setContentOffsetInDuration(Vec2(0, 0), 0.2);
}

#endif
