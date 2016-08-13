//
//  TDDTable.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 8/8/2016.
//
//

#include "TDDTable.h"


TDDTable *TDDTable::create(const Size &contentSize)
{
	TDDTable *table = new TDDTable();
	
	table->initWithSize(contentSize);
	
	table->autorelease();
	
	return table;
}

TDDTable::TDDTable()
: mButtonArray()
, mTitleColor(Color3B::BLUE)
, mBackgroundColor(Color4B::WHITE)
, mFontSize(15)
, mColumn(4)
, mDelegate(nullptr)
{
	
}

TDDTable::~TDDTable()
{
	
}

bool TDDTable::initWithSize(const Size &contentSize)
{
	bool flag = LayerColor::initWithColor(Color4B(0, 0, 0, 0), contentSize.width, contentSize.height);
	
	if(! flag) {
		return false;
	}
	
	// configure the scrollView
	mScrollContentLayer = LayerColor::create(Color4B::WHITE, contentSize.width, contentSize.height);
	mScrollView = ScrollView::create(contentSize, mScrollContentLayer);
	mScrollView->setDirection(ScrollView::Direction::VERTICAL);
	
	//
	addChild(mScrollView);
	
	return true;
}

void TDDTable::updateBackgroundColor()
{
	mScrollContentLayer->setColor(Color3B(mBackgroundColor));
	mScrollContentLayer->setOpacity(mBackgroundColor.a);
}

void TDDTable::updateData()
{
	if(! mDelegate) {
		log("TDDTable: mDelegate undefined.");
		return;
	}
	
	// update background color
	updateBackgroundColor();
	
	// Clean up first
	mScrollContentLayer->removeAllChildren();
	
	// Calculate the position first
	Size cellSize = mDelegate->getTableCellSize();
	int itemCount = mDelegate->getTableCellCount();
	int rowcount = (int) ceil((float) itemCount / getColumn());
	// log("rowCount=%d", rowcount);	// 50 / 4 = 13
	
	float totalWidth = cellSize.width * getColumn();
	float totalHeight = cellSize.height * rowcount;
	
	bool hasVerticalScroll;
	if(totalHeight <= mScrollView->getContentSize().height) {
		totalHeight = mScrollView->getContentSize().height;
		hasVerticalScroll = false;
	} else {
		hasVerticalScroll = true;
	}
	
	
	
	Vec2 pos = Vec2(0, totalHeight);		// define the first positon
	pos += Vec2(cellSize.width/2, -cellSize.height/2);
	
	
	
	// Setting the scrollView
	mScrollContentLayer->setContentSize(Size(totalWidth, totalHeight));
	
	// Create the TableCell using Button
	for(int i=0; i<itemCount; i++) {
		// Add
		
		// Size buttonSize = Size(50, 50);
		Node *node = createTableCell(i, cellSize, pos);
		//button->setAnchorPoint(Vec2(0, 1));		// Anchor at left-top corner
		if(node) {
			mScrollContentLayer->addChild(node);
		}
		
		// Define the next position
		bool isLastColumn = ((i+1) % getColumn()) == 0;
		
		if(isLastColumn) {
			pos.x = cellSize.width/2;
			pos.y -= cellSize.height;
		} else {
			pos.x += cellSize.width;
		}
	}
	
//	if(hasVerticalScroll == false) {
//		mScrollView->setDirection(ScrollView::Direction::HORIZONTAL);
//	}
	
	// Scroll Top
	float scroll = -totalHeight + mScrollView->getViewSize().height;
	mScrollView->setContentOffset(Vec2(0, scroll));
}

Node *TDDTable::createTableCell(int index, const Size &size, const Vec2 &cellCenterPos)
{
	if(mDelegate == nullptr) {
		return nullptr;
	}
	
	Node *cellNode = mDelegate->tableCellForIndex(index);	// this is an autorelease node
	if(cellNode == nullptr) {
		return nullptr;
	}
	
	Size nodeSize = cellNode->getContentSize();
	
	Vec2 pos = cellCenterPos - Vec2(nodeSize.width, nodeSize.height) / 2;
	cellNode->setAnchorPoint(Vec2(0, 0));		// ken: some of cocos2d Node don't know how to anchor at center
	cellNode->setPosition(pos);
	
	return cellNode;
	
	
//	cocos2d::ui::Button *button = cocos2d::ui::Button::create();
//	
//	// configure the button
//	button->setTitleText(StringUtils::format("Cell %d", index));	// for debugging
//	button->setTitleFontSize(getFontSize());
//	button->setTitleAlignment(TextHAlignment::CENTER);
//	button->setTitleColor(getTitleColor());
//	button->setTag(index);		// note: tag value is the index
//
//	button->addClickEventListener([&, index](Ref *button) {
//		//notifyCallback(clickedButton->getTag());
//		notifyCallback(index);
//	});
//	
//	return button;
}

void TDDTable::notifyCallback(int index)
{
	log("Clicked. index=%d", index);
	if(mDelegate) {
		mDelegate->onTableCellClicked(index);
	}
}
//void TDDTable::addItem(const std::string &itemName)
//{
//	
//}