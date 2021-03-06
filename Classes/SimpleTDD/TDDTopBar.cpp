//
//  TDDHeaderLayer.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 11/8/2016.
//
//

#ifdef ENABLE_TDD

#include "TDDTopBar.h"
#include "TDDTab.h"
#include "TDDHelper.h"

Color4B kDefaultColor(255, 255, 255, 255);

TDDTopBar::TDDTopBar()
: mTopBarColor(Color4B(80, 80, 200, 255))
, mSearchBarColor(Color4B(150, 150, 200, 255))
, mTextColor(Color3B::WHITE)
, mActiveTextColor(Color3B::BLUE)
, mSearchBoxColor(Color3B(230, 230, 230))
, mSearchBoxTextColor(Color3B::BLACK)
, mTopBarLayer(nullptr)
, mEditBox(nullptr)
, mTab(nullptr)
, mCloseCallback(nullptr)
, mTabChangeCallback(nullptr)
, mKeywordChangeCallback(nullptr)
, mSearchKey("")
, mTextField(nullptr)
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

	
	tab->setCallback([&](Ref *tab, int selectedTab, bool isRepeat)
					 {
						 onTabClicked(selectedTab, isRepeat);
					 });
	
	mTab = tab;
	
	
	// Add the "Close" button
	cocos2d::ui::Button *closeButton = cocos2d::ui::Button::create();
	
	
	Vec2 pos = Vec2(getContentSize().width - buttonSize.width, buttonSize.height/2);
	closeButton->setTitleText("Close");
	closeButton->setTitleColor(mTextColor);
	closeButton->setTitleFontSize(fontSize);
	closeButton->setPosition(pos);
	mTopBarLayer->addChild(closeButton);
	
	closeButton->addClickEventListener([&](Ref *ref) {
		onCloseClicked();
	});
	
}

void TDDTopBar::updateColor()
{
	if(mTopBarLayer) {
		mTopBarLayer->setColor(Color3B(getTopBarColor()));
		mTopBarLayer->setOpacity(getTopBarColor().a);
	}
}

void TDDTopBar::initSearchBar()
{
	// Layout Data
	float fontSize = 15;
	float hSpacing = 4;
	float vSpacing = 4;
	
	float halfHeight = getContentSize().height / 2;
	float searchBarCenterY = halfHeight/2;

	
	// Size
	float buttonH = halfHeight - vSpacing * 2;
	
	Size clearButtonSize = Size(buttonH, buttonH);
	
	float searchBoxWidth = getContentSize().width - 2 * hSpacing - clearButtonSize.width;
	Size searchBoxSize = Size(searchBoxWidth, halfHeight - vSpacing * 2);
	
	// Position
	Vec2 searchBoxPos = Vec2(hSpacing + searchBoxSize.width/2, searchBarCenterY);
	Vec2 searchBoxBgPos = Vec2(hSpacing, vSpacing);		// without center anchor point
	Vec2 clearButtonPos = Vec2(hSpacing + searchBoxSize.width + clearButtonSize.width/2, searchBarCenterY); // right after the searchBox
	
	
	// Setting the background color
	setColor(Color3B(mSearchBarColor));
	setOpacity(mSearchBarColor.a);
	
	// Adding the searchBox
					//vSpacing + searchBoxSize.height / 2);		// anchor = center
//	ui::EditBox *editBox = TDDHelper::createEditBox(searchBoxSize,
//								mSearchBoxColor, mSearchBoxTextColor,
//								"", fontSize);
//	editBox->setPlaceHolder("Test Keyword. e.g Sprite");
//	//editBox->setPlaceholderFontSize(fontSize * 0.8);
//	editBox->setPosition(searchBoxPos);
//	editBox->setDelegate(this);
//	
//	addChild(editBox);
//	mEditBox = editBox;
//
	// Add Layer Color behind the textfield
	LayerColor *backLayer = LayerColor::create(mSearchBoxColor, searchBoxSize.width, searchBoxSize.height);
	backLayer->setPosition(searchBoxBgPos);
	addChild(backLayer);
	
	//
	ui::TextField *tf = ui::TextField::create("Test Keyword. e.g Sprite", "", fontSize);
	tf->setTouchSize(searchBoxSize);
	tf->setTouchAreaEnabled(true);
	tf->setContentSize(searchBoxSize);
	tf->setPosition(searchBoxPos);
	tf->setTextColor(Color4B(mSearchBoxTextColor));
	tf->setColor(Color3B::YELLOW);
	tf->setTextHorizontalAlignment(TextHAlignment::LEFT);
	tf->addEventListener([&](Ref *ref, ui::TextField::EventType type) {
		// log("event: type=%d [%s]", type, mTextField->getString().c_str());
		if(ui::TextField::EventType::INSERT_TEXT == type
		   || ui::TextField::EventType::DELETE_BACKWARD == type)
		{
			onTextFieldChange();
		}
	});
	addChild(tf);
	mTextField = tf;

	
	// Adding the close Button
	TDDButton *clearButton = TDDHelper::addTDDButton(this,
										clearButtonPos, clearButtonSize,
										"X", mTextColor, mTopBarColor, fontSize);
	
	// clearButton->setTitleFontSize(fontSize);
	clearButton->addClickEventListener([&](Ref *ref) {
		clearSearchText();
	});
	
	
//	EditBox *editBox = TDDHelper::createEditBox(this, Point(inputX, midY), Size(inputW, inputH));
//	mEditFilter->setFont(TDD_FONT_NAME, fontSizeEdit);
//	mEditFilter->setPlaceholderFont(TDD_FONT_NAME, fontSizeEdit);
//	mEditFilter->setText(TDDHelper::getFilter());
//	mEditFilter->setPlaceHolder("Testcase Filter");
//	mEditFilter->setDelegate(this);

}

void TDDTopBar::clearSearchText()
{
	if(mTextField) {
		setSearchKeyword("");
		onSearchKeyChanged();	// notify callback
	}
}

void TDDTopBar::onCloseClicked()
{
	if(mCloseCallback) {
		mCloseCallback(this);
	}
}

void TDDTopBar::onTabClicked(int selectedIndex, bool isRepeat)
{
	if(! mTabChangeCallback) {
		return;
	}
	
	if(isRepeat) {	// TODO: Different behaviour for repeat tab click
		return;
	}

	TDDSearchType value;
	
	// find the value
	if(1 == selectedIndex) {
		value = TDDSearchRecent;
	} else {
		value = TDDSearchAll;
	}
	
	// do callback
	mTabChangeCallback(this, value);
}

void TDDTopBar::onSearchKeyChanged()
{
	if(mKeywordChangeCallback) {
		mKeywordChangeCallback(this, getSearchKeyword());
	}

}

void TDDTopBar::setCloseListener(const std::function<void(TDDTopBar *)> &callback)
{
	mCloseCallback = callback;
}

void TDDTopBar::setTabChangeListener(const std::function<void(TDDTopBar *, TDDSearchType)> &callback)
{
	mTabChangeCallback = callback;
}

void TDDTopBar::setKeywordChangeListener(const std::function<void(TDDTopBar *, const std::string &keyword)> &callback)
{
	mKeywordChangeCallback = callback;
}


std::string TDDTopBar::getSearchKeyword()
{
	return mSearchKey;
}

void TDDTopBar::setSearchKeyword(const std::string &key)
{
	mSearchKey = key;
	
	if(mTextField) {
		mTextField->setString(mSearchKey);
	}
	
}

#pragma mark - EditBox Delegage
void TDDTopBar::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string& text)
{
	//setSearchKeyword(text);
	mSearchKey = text;
	onSearchKeyChanged();
}

void TDDTopBar::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
	
}

void TDDTopBar::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
	
}

void TDDTopBar::editBoxReturn(cocos2d::ui::EditBox* editBox)
{
	
}

void TDDTopBar::setup(const TDDSearchType &tab, const std::string &keyword)	// note: no callback will be triggere
{
	if(mTab) {
		int index = tab == TDDSearchRecent ? 1 : 0;
		mTab->selectTab(index, false);
	}
	
	setSearchKeyword(keyword);
}

#pragma mark - TextField handling
void TDDTopBar::onTextFieldChange()
{
	if(!mTextField) {
		return;
	}
	mSearchKey = mTextField->getString();
	onSearchKeyChanged();
}



#endif
