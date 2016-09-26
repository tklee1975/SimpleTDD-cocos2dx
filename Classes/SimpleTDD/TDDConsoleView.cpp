//
//  TDDConsoleView.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 25/9/2016.
//
//

#include "TDDConsoleView.h"

const Color4B kDefaultBgColor = Color4B(0, 0, 0, 100);
const Color3B kDefaultTextColor = Color3B::WHITE;
const float kSideMargin = 5;


TDDConsoleView *TDDConsoleView::create(const Size &contentSize)
{
	TDDConsoleView *view = new TDDConsoleView();
	
	view->initWithSize(contentSize);
	
	view->autorelease();
	
	return view;
}

TDDConsoleView::TDDConsoleView()
: mBackgroundColor(kDefaultBgColor)
, mContent("")
, mFontName("")
, mFontSize(10)
, mTextColor(kDefaultTextColor)
// , mContentText(nullptr)
{
	
}

TDDConsoleView::~TDDConsoleView()
{
	
}

bool TDDConsoleView::initWithSize(const Size &contentSize)
{
	bool flag = LayerColor::initWithColor(mBackgroundColor, contentSize.width, contentSize.height);
	
	if(! flag) {
		return false;
	}
	
	float width = contentSize.width;
	Size scrollSize = Size(width, contentSize.height);
	
	// configure the scrollView
	mScrollContentLayer = LayerColor::create(Color4B(0,0,0,0), contentSize.width, contentSize.height);
	mScrollView = ScrollView::create(scrollSize, mScrollContentLayer);
	mScrollView->setDirection(ScrollView::Direction::VERTICAL);
	mScrollView->setClippingToBounds(true);
	
	//
	addChild(mScrollView);
	
	// Set the Label
	mContentText = ui::Text::create(mContent, mFontName, mFontSize);
	mContentText->setAnchorPoint(Vec2(0, 1));
	mContentText->setPosition(Vec2(kSideMargin, contentSize.height));
	mScrollContentLayer->addChild(mContentText);
	
	return true;
}


void TDDConsoleView::appendLog(const std::string &msg)
{
	mContent = msg + "\n" + mContent;
	
	mContentText->setString(mContent);
	
//	Size textSize = mContentText->getTextAreaSize();
//	log("debug: text size=%f %f", textSize.width, textSize.height);
//	
	Size contentSize = mContentText->getContentSize();
	float newHeight = contentSize.height;
	
	// log("debug: contentSize text height=%f,%f", contentSize.width, contentSize.height);
	mContentText->setPosition(Vec2(kSideMargin, newHeight));
	
	
	Size newSize = Size(mScrollView->getContentSize().width, newHeight);
	mScrollContentLayer->setContentSize(newSize);
	
	
	// mScrollView->setViewSize(contentSize);
	
	// Modify the scroll size
	scrollToTop();
}

void TDDConsoleView::scrollToTop()
{
	float scrollHeight = mScrollView->getViewSize().height;
	float contentHeight = mScrollContentLayer->getContentSize().height;
	
	mScrollView->setContentOffset(Vec2(0, -contentHeight+scrollHeight));
}