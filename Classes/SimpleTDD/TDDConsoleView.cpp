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
const float kHeaderHeight = 30;

const float kButtonSize = 50;

const Color4B kClearColor = Color4B(0, 0, 0, 0);
const Color4B kHeaderColor = Color4B(0, 0, 0, 100);


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
, mHeaderColor(kHeaderColor)
, mHeaderHeight(kHeaderHeight)
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
	
	setupHeader();
	setupScrollView();
	
	return true;
}

#pragma mark - Setup
void TDDConsoleView::setupScrollView()
{
	Size contentSize = getContentSize();
	
	float width = contentSize.width;
	float height = contentSize.height - mHeaderHeight;
	
	Size scrollSize = Size(width, height);
	
	// configure the scrollView
	mScrollContentLayer = LayerColor::create(kClearColor, width, height);
	mScrollView = ScrollView::create(scrollSize, mScrollContentLayer);
	mScrollView->setDirection(ScrollView::Direction::VERTICAL);
	mScrollView->setClippingToBounds(true);
	
	//
	addChild(mScrollView);
	
	// Set the Label
	mContentText = ui::Text::create(mContent, mFontName, mFontSize);
	mContentText->setAnchorPoint(Vec2(0, 1));
	mContentText->setPosition(Vec2(kSideMargin, height));
	mScrollContentLayer->addChild(mContentText);
	
}

void TDDConsoleView::setupHeader()
{
	Size contentSize = getContentSize();
	
	Vec2 pos = Vec2(0, contentSize.height - mHeaderHeight);		// anchor=left,bottom
	
	float width = getContentSize().width;
	LayerColor *headerLayer = LayerColor::create(mHeaderColor, width, mHeaderHeight);
	headerLayer->setPosition(pos);
	
	
	
	// Title
	ui::Text *titleText = ui::Text::create("Console", "", 15);
	titleText->setColor(Color3B::GREEN);
	titleText->setAnchorPoint(Vec2(0, 0.5));
	titleText->setPosition(Vec2(kSideMargin, mHeaderHeight/2));
	headerLayer->addChild(titleText);
	
	Size size = Size(kButtonSize, mHeaderHeight);
	// Buttons in Header
	//		Top / Clear / Close
	Vec2 buttonPos = Vec2(contentSize.width - kSideMargin - size.width / 2, size.height / 2);	// anchor point = center
	
	//
	// Close Button
	ui::Button *closeButton = createButton("close", size);
	closeButton->addClickEventListener([&](Ref *) {
//		if(mBackCallback) {
//			mBackCallback(this);
//		}
	});
	closeButton->setPosition(buttonPos);
	headerLayer->addChild(closeButton);
	
	buttonPos.x -= size.width;
	// Close Button
	ui::Button *clearbutton = createButton("clear", size);
	clearbutton->addClickEventListener([&](Ref *) {
		clear();
	});
	clearbutton->setPosition(buttonPos);
	headerLayer->addChild(clearbutton);

	buttonPos.x -= size.width;
	// Close Button
	ui::Button *topButton = createButton("top", size);
	topButton->addClickEventListener([&](Ref *) {
		scrollToTop(0.2);
	});
	topButton->setPosition(buttonPos);
	headerLayer->addChild(topButton);
	
	
	//
	addChild(headerLayer);
	
	mHeaderLayer = headerLayer;
	
}


void TDDConsoleView::clear()
{
	setConsoleContent("");
}


void TDDConsoleView::appendLog(const std::string &msg)
{
	std::string newContent = msg + "\n" + mContent;
	setConsoleContent(newContent);
}

void TDDConsoleView::setConsoleContent(const std::string &msg)
{
	mContent = msg;
	mContentText->setString(mContent);
	
	//	Size textSize = mContentText->getTextAreaSize();
	//	log("debug: text size=%f %f", textSize.width, textSize.height);
	//
	
	Size contentSize = mContentText->getContentSize();
	float newHeight = MAX(contentSize.height, mScrollView->getViewSize().height);
	
	
	// log("debug: contentSize text height=%f,%f", contentSize.width, contentSize.height);
	float newY = newHeight;
	
	mContentText->setPosition(Vec2(kSideMargin, newY));
	
	
	Size newSize = Size(mScrollView->getContentSize().width, newHeight);
	mScrollContentLayer->setContentSize(newSize);
	
	
	// mScrollView->setViewSize(contentSize);
	
	// Modify the scroll size
	scrollToTop();
}

void TDDConsoleView::scrollToTop(float dt)
{
	float scrollHeight = mScrollView->getViewSize().height;
	float contentHeight = mScrollContentLayer->getContentSize().height;
	
	mScrollView->setContentOffset(Vec2(0, -contentHeight+scrollHeight), dt);
}

ui::Button *TDDConsoleView::createButton(const std::string &title, const Size &size)
{
	ui::Button *button = ui::Button::create();
	button->setTitleText(title);
	button->setContentSize(size);
	button->setTitleColor(Color3B::WHITE);
	button->setTitleFontSize(15);
	
	return button;
}
