//
//  TDDHeaderLayer.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 11/8/2016.
//
//

#include "TDDTopBar.h"
#include "TDDTab.h"
#include "TDDHelper.h"

Color4B kDefaultColor(255, 255, 255, 255);

TDDTopBar::TDDTopBar()
: mTopBarColor(Color4B::BLUE)
, mTextColor(Color3B::WHITE)
, mActiveTextColor(Color3B::ORANGE)
, mSearchBoxColor(Color3B(200, 200, 200))
, mSearchBoxTextColor(Color3B::BLACK)
{
	
}

TDDTopBar::~TDDTopBar()
{
	
}

bool TDDTopBar::initWithSize(const Size &size)
{
	bool flag = LayerColor::initWithColor(kDefaultColor, size.width, size.height);
	if(flag == false) {
		return false;
	}
	
	initTopBar();
	initSearchBar();
	
	
	return true;
}


void TDDTopBar::initTopBar()
{
	float halfHeight = getContentSize().height / 2;
	float fontSize = 15;
	Size tabSize = Size(50, halfHeight);
	Size buttonSize = Size(50, halfHeight);
	
	Vec2 topBarPos = Vec2(0, halfHeight);
	
	// Create the top bar layer
	LayerColor *layer = LayerColor::create(mTopBarColor, getContentSize().width, halfHeight);
	layer->setPosition(topBarPos);
	addChild(layer);
	mTopBarLayer = layer;
	
	
	
	// Add the Tab "All" / "Recent"
	TDDTab *tab = TDDTab::create();
	tab->setTitleColor(mTextColor);
	tab->setActiveTitleColor(mActiveTextColor);
	tab->setTabSize(tabSize);
	tab->setFontSize(fontSize);
	tab->setPosition(Vec2(10, 0));
	tab->addTab("All");
	tab->addTab("Recent");
	mTopBarLayer->addChild(tab);

	
	// Add the "Close" button
	cocos2d::ui::Button *closeButton = cocos2d::ui::Button::create();
	
	
	Vec2 pos = Vec2(getContentSize().width - buttonSize.width, buttonSize.height/2);
	closeButton->setTitleText("Close");
	closeButton->setTitleColor(mTextColor);
	closeButton->setTitleFontSize(fontSize);
	closeButton->setPosition(pos);
	mTopBarLayer->addChild(closeButton);
}


void TDDTopBar::initSearchBar()
{
	float fontSize = 15;
	float hSpacing = 4;
	float vSpacing = 4;
	
	float halfHeight = getContentSize().height / 2;
	float buttonLen = halfHeight - vSpacing * 2;
	Size buttonSize = Size(buttonLen, buttonLen);
	
	
	float searchBoxWidth = getContentSize().width - 4 * hSpacing - 2 * buttonSize.width;
	Size searchBoxSize = Size(searchBoxWidth, halfHeight - vSpacing * 2);
	
	
	// Adding the searchBox
	Vec2 pos = Vec2(hSpacing + searchBoxSize.width/2, vSpacing + searchBoxSize.height / 2);		// anchor = center
	ui::EditBox *editBox = TDDHelper::createEditBox(searchBoxSize,
								mSearchBoxColor, mSearchBoxTextColor,
								"", fontSize);
	editBox->setPlaceHolder("Test Keyword. e.g Sprite");
	editBox->setPlaceholderFontSize(fontSize * 0.8);
	editBox->setPosition(pos);
	
	addChild(editBox);
	
//	EditBox *editBox = TDDHelper::createEditBox(this, Point(inputX, midY), Size(inputW, inputH));
//	mEditFilter->setFont(TDD_FONT_NAME, fontSizeEdit);
//	mEditFilter->setPlaceholderFont(TDD_FONT_NAME, fontSizeEdit);
//	mEditFilter->setText(TDDHelper::getFilter());
//	mEditFilter->setPlaceHolder("Testcase Filter");
//	mEditFilter->setDelegate(this);

}