//
//  TDDTab.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 6/8/2016.
//
//

#include "TDDTab.h"

TDDTab::TDDTab()
: mFontName("")
, mFontSize(10)
, mTitleColor(Color3B::BLUE)
, mActiveTitleColor(Color3B::RED)
, mButtonArray()
, mTabSize(Size(60, 40))	// Based on 320 x 640 spec
, mCallback(nullptr)
, mSelectedIndex(-1)
{
	
}

TDDTab::~TDDTab()
{
	
}

int TDDTab::addTab(const std::string &tabName)
{
	// Calc the position
	Size tabSize = getTabSize();
	float x = getTabCount() * tabSize.width + tabSize.width/2;
	float y = tabSize.height/2;
	
	int tabIndex = (int) getTabCount();
	
	ui::Button *button = createButton(tabName, Vec2(x, y), tabIndex);
	mButtonArray.push_back(button);	// note: retain only by the UI, not the array
	
	// modify the content size of the layer
	updateContentSize();
	
	return tabIndex;
}

int TDDTab::getTabCount()
{
	return (int) mButtonArray.size();
}

void TDDTab::selectTab(int index)
{
	if(index < 0 || index >= getTabCount()) {
		return;	// invalid input
	}
	
	ui::Button *newButton = getButtonAtIndex(index);
	ui::Button *oldButton = getButtonAtIndex(mSelectedIndex);
	
	// Change the button color if a new tab is chosen
	if(newButton != oldButton) {
		if(oldButton) {	// turn back to normal color
			oldButton->setTitleColor(getTitleColor());
		}

		if(newButton) {	// turn to active color
			newButton->setTitleColor(getActiveTitleColor());
		}
	}
	
	// update the mSelectedd
	bool isRepeat = (mSelectedIndex == index);	// old index is same new
	mSelectedIndex = index;
	
	// handle callback
	if(mCallback) {
		mCallback(this, mSelectedIndex, isRepeat);
	}
}

ui::Button *TDDTab::getButtonAtIndex(int index)
{
	if(index < 0 || index >= getTabCount()) {
		return nullptr;	// invalid input
	}

	return mButtonArray[index];
}

ui::Button *TDDTab::createButton(const std::string &name, const Vec2 &pos, int tabIndex)
{
	cocos2d::ui::Button *button = cocos2d::ui::Button::create();
	
	// configure the button
	button->setTitleText(name);
	button->setContentSize(getTabSize());
	button->setTitleColor(getTitleColor());
	button->setPosition(pos);
	
	// define the callback
	button->addClickEventListener([&, tabIndex](Ref *) {
		selectTab(tabIndex);
	});
	
	//
	addChild(button);
	
	return button;
}


void TDDTab::setCallback(const TDDTabCallback &callback)
{
	mCallback = callback;
}


void TDDTab::updateContentSize()
{
	Size totalSize = mTabSize * getTabCount();
	
	setContentSize(totalSize);
}