//
//  TDDMainLayer.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 13/8/2016.
//
//

#include "TDDMainLayer.h"
#include "TDDTopBar.h"

TDDMainLayer::TDDMainLayer()
: mBackgroundColor(Color4B::WHITE)
, mKeyword("")
, mResultList()
, mColumn(4)
{
	
}

TDDMainLayer::~TDDMainLayer()
{
	
}

bool TDDMainLayer::init()
{
	Size viewSize = Director::getInstance()->getVisibleSize();
	bool flag = LayerColor::initWithColor(Color4B::WHITE, viewSize.width, viewSize.height);
	if(flag == false) {
		return false;
	}
	
	setupProperties();
	setupGUI();
	
	return true;	
}

void TDDMainLayer::setupProperties()
{
	mColumn = 4;
	
	float cellWidth = getContentSize().width / mColumn;
	float cellHeight = 40;
	mTableCellSize = Size(cellWidth, cellHeight);
	
}

void TDDMainLayer::setupGUI()	// call after theme settin
{
	// Define the layout data for the key component
	
	//    (Size)
	Size layerSize = getContentSize();
	
	Size topBarSize = Size(layerSize.width, 70);
	Size tableSize = Size(layerSize.width, layerSize.height - topBarSize.height);
	
	//    (Position)
	Vec2 topBarPos = Vec2(0, layerSize.height - topBarSize.height);		// pos at left-bottom corner;
	Vec2 tablePos = Vec2(0, 0);			// pos at left-bottom corner
	
	
	// Adding the top bar
	TDDTopBar *topBar = TDDTopBar::create(topBarSize);
	topBar->setPosition(topBarPos);
	topBar->setup(TDDTopBarTabAll, "");
	
	addChild(topBar);
	
	// Add the Table
	TDDTable *table = TDDTable::create(tableSize);
	table->setColumn(mColumn);
	table->setTitleColor(Color3B(49,166,148));
	table->setBackgroundColor(Color4B(250,219,191,255));
	table->setFontSize(12);
	table->setDelegate(this);
	//delegate->release();
	
	table->updateData();
	
	addChild(table);

	
}


#pragma mark - TDDTableDelegate
int TDDMainLayer::getTableCellCount()
{
//	return mResultList.size();
	return 100;
}

Size TDDMainLayer::getTableCellSize()
{
	return mTableCellSize;
}
void TDDMainLayer::onTableCellClicked(int selectedIndex)
{
	log("tableCell clicked: %d", selectedIndex);
}


Node *TDDMainLayer::tableCellForIndex(int index)
{
	return Label::createWithSystemFont(StringUtils::format("cell%d", index), "", 30);
}