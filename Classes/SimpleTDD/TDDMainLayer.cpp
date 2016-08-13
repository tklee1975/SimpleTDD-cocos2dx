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
	
	setupGUI();
	
	return true;	
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
	
	
}