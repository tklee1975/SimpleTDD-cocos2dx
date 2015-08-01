//
//  TTDSuite.cpp
//  TDDLib
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifdef ENABLE_TDD

#include "TDDSuite.h"
#include "TDDTypes.h"
#include "TDDCases.h"
#include "TDDHelper.h"
#include "TDDMenu.h"
#include "TDDConstant.h"
#include "TDDSwitch.h"
#include "TDDData.h"

static int gTestCount = sizeof(gTestArray) / sizeof(gTestArray[0]);

#define kTestZOrder			10000
#define kLineHeight			kDefaultMenuRowHeight
#define kToolBarHeight		kDefaultToolbarHeight
#define kStatusBarHeight	30
#define kStatusBarFontSize	15

//#define kColorTestMenu		Color4B(50, 50, 100, 255)
#define kColorTestMenu				Color4B(255, 255, 255, 0)
#define kColorToolBar				Color4B(TDD_COLOR_BLUE2)

#define kColorSwitchBg				Color4B(TDD_COLOR_WHITE)
#define kColorSwitch				Color4B(TDD_COLOR_BLUE2)
#define kColorSwitchOnText			TDD_COLOR_WHITE
#define kColorSwitchOffText			TDD_COLOR_GRAY

#pragma mark -
#pragma mark Local Function
namespace {
	bool passFilter(const char *name, const char *filterPattern)
	{
		if(strlen(filterPattern) == 0) {
			return true;
		}
		
		std::string modifyName = TDDHelper::replaceString(name, "Test", "");
		

		
		return strcasestr(modifyName.c_str(), filterPattern) != NULL;
	}
}

#pragma mark -
#pragma mark TDDSuiteScene
TDDSuiteScene::TDDSuiteScene()
{
	mHasSetup = false;
}

TDDSuiteScene::~TDDSuiteScene()
{
	
}

void TDDSuiteScene::onEnter()
{
	//log("TDDSuiteScene: onEnter");

	Scene::onEnter();
	
	//log("TDDSuiteScene: onEnter is called");
	
	TDDSuiteLayer *layer = new TDDSuiteLayer();
	addChild(layer);
	layer->release();
	
	// Save the stat setting and then turn off
	hasStat = Director::getInstance()->isDisplayStats();
	Director::getInstance()->setDisplayStats(false);
	
}

void TDDSuiteScene::onExit()
{
	//log("TDDSuiteScene: onExit");
	//this->removeAllChildren();
	
	Director::getInstance()->setDisplayStats(hasStat);
	Scene::onExit();
}


#pragma mark -
#pragma mark TDDSuiteLayer

TDDSuiteLayer::TDDSuiteLayer()
: mEditFilter(NULL)
, mStatusLeftLabel(NULL)
, mFilterCount(0)
, mMode(TDDMenuModeAll)
, mClearMenu(NULL)
{
	Size screenSize = TDDHelper::getScreenSize();
	LayerColor *bgLayer = LayerColor::create(Color4B(TDD_COLOR_WHITE2),
											 screenSize.width, screenSize.height );
	addChild(bgLayer);

	// Top bar with: back, filter and all/history
	setupToolBar();

	// Status
	setupStatusBar();

	// Menu
	setupTestMenu();

	
}

TDDSuiteLayer::~TDDSuiteLayer()
{
	
}


void TDDSuiteLayer::clearHistory(Ref * sender)
{
	//log("clearHistory");
	TDDData::instance()->clearHistory();
	
	setDisplayTestWithHistory();
}


void TDDSuiteLayer::goBack(Ref * sender)
{
	//log("goback to main");
	Director::getInstance()->popToRootScene();
}

void TDDSuiteLayer::filterTest(Ref * sender)
{
	//log("filterTest");
	
	const char *pattern = (mEditFilter == NULL) ? "" : mEditFilter->getText();
	
	std::string trimPattern = TDDHelper::trimString(pattern);
	
	TDDHelper::saveFilter(trimPattern.c_str());
	
	// Director::getInstance()->popToRootScene();
	setDisplayTestWithFilter();
	
}



// Tool bar constains the following elements
//	Back button
//	Filter Input
//	Switch
//	Layout:		| BACK | INPUT  .... SWITCH |		// 800 or 480
//  Landscape:  | 80
//  Portrait:	| 80 | 80 | ... 120 |		400 - 120 = 280 -
Layer *TDDSuiteLayer::createToolBarLayer()
{
	float scale = TDDHelper::getBestScale();
	int fontSizeSwitch = (int)(scale * TDD_FONT_SIZE2 );
	int fontSizeEdit = (int)(scale * TDD_FONT_SIZE1 );
	
	log("font: edit=%d switch=%d", fontSizeEdit, fontSizeSwitch);
	
	// bool isLandscape = TDDHelper::isLandscape();
	Size screenSize = TDDHelper::getScreenSize();
	int midY = kToolBarHeight/2;
	
	int buttonW = (int)(scale * 90);
	int inputW = (int)(scale * 200);
	int switchW = (int)(scale * 130);

	
	int backX = buttonW/2;
	int inputH = kToolBarHeight - 10;
	int inputX = inputW / 2 + buttonW;
	
	int clearX = buttonW + buttonW/2;
	
	int switchY = 5;
	int switchX = screenSize.width - switchW - 10;
	int switchH = kToolBarHeight - switchY * 2;
	
	
	
	// Layer containter
	LayerColor *menuLayer = LayerColor::create(kColorToolBar, screenSize.width, kToolBarHeight);
	
	
	// Back Button
	Menu *menuBack = TDDHelper::createMenu(Point(backX, midY), "Back",
										   CC_CALLBACK_1(TDDSuiteLayer::goBack, this));
	
	menuLayer->addChild(menuBack);
	
	
	// Clear History button
	Menu *menuClear = TDDHelper::createMenu(Point(clearX, midY), "Clear",
									CC_CALLBACK_1(TDDSuiteLayer::clearHistory, this));
	
	menuLayer->addChild(menuClear);
	mClearMenu = menuClear;
	mClearMenu->setVisible(false);
	
	// Filter Input
	mEditFilter = TDDHelper::createEditBox(menuLayer, Point(inputX, midY), Size(inputW, inputH));
	mEditFilter->setFont(TDD_FONT_NAME, fontSizeEdit);
	mEditFilter->setPlaceholderFont(TDD_FONT_NAME, fontSizeEdit);
	mEditFilter->setText(TDDHelper::getFilter());
	mEditFilter->setPlaceHolder("Testcase Filter");
	mEditFilter->setDelegate(this);
	

	// Switch
	TDDSwitch *switchControl = new TDDSwitch(Size(switchW, switchH),
											 kColorSwitchBg, kColorSwitch,
											 kColorSwitchOffText, kColorSwitchOnText,
											 TDD_FONT_NAME, fontSizeSwitch);
	
	switchControl->setPosition(Point(switchX, switchY));
	
	menuLayer->addChild(switchControl);
	
	std::vector<std::string> switches;
	switches.push_back("all");
	switches.push_back("history");
	
	TDDMenuMode savedMode = TDDData::instance()->getMenuMode();
	int index = 0;
	if(savedMode == TDDMenuModeHistory) {
		index = 1;
	}
	
	switchControl->setSwitches(switches,
				CC_CALLBACK_3(TDDSuiteLayer::switchSelected, this), index);
	
	
	return menuLayer;
}


void TDDSuiteLayer::switchSelected(Ref *sender, std::string name, int selected)
{
	log("selected switch: %s (%d)", name.c_str(), selected);
	
	if(selected == 1) {
		mMode = TDDMenuModeHistory;
		setDisplayTestWithHistory();
	} else {
		mMode = TDDMenuModeAll;
		setDisplayTestWithFilter();
	}
	
	TDDData::instance()->setMenuMode(mMode);
}


void TDDSuiteLayer::setupToolBar()
{
	Point pos = Point(0, kToolBarHeight);
	Layer *toolBar = createToolBarLayer();
	toolBar->setPosition(Director::getInstance()->convertToGL(pos));
	this->addChild(toolBar);
}



Layer *TDDSuiteLayer::createStatusBarLayer()
{
	Size screenSize = TDDHelper::getScreenSize();
	int midY = kStatusBarHeight/2;
	int margin = 10;
	Point leftAnchor = Point(0, 0.5);
	Point rightAnchor = Point(1, 0.5);
	

	// Layer containter
	LayerColor *layer = LayerColor::create(kColorToolBar, screenSize.width, kStatusBarHeight);
	
	//
	Label *leftLabel = TDDHelper::createLabel("Left", kStatusBarFontSize, Color3B::WHITE);
	leftLabel->setAnchorPoint(leftAnchor);
	leftLabel->setPosition(Point(margin, midY));
	layer->addChild(leftLabel);
	mStatusLeftLabel = leftLabel;
	
	Label *rightLabel = TDDHelper::createLabel("Right", kStatusBarFontSize, Color3B::WHITE);
	rightLabel->setAnchorPoint(rightAnchor);
	rightLabel->setPosition(Point(screenSize.width - margin, midY));
	layer->addChild(rightLabel);
	
	// Setting Right Label
	char text[200];
	sprintf(text, "%s %s (%d)", APP_NAME, VERSION, BUILD);
	rightLabel->setString(text);

	return layer;
}

void TDDSuiteLayer::updateStatusBar()
{
	if(mStatusLeftLabel == NULL) {
		return;
	}
	
	// Setting Left Label
	char text[200];
	
	if(mMode == TDDMenuModeHistory) {
		sprintf(text, "Test count: %d ", getTotalTestCount());
	} else {
		sprintf(text, "Test count: %d / %d", getFilteredTestCount(), getTotalTestCount());
	}
	mStatusLeftLabel->setString(text);
	
}

void TDDSuiteLayer::setupStatusBar()
{
	Point pos = Point(0, 0);
	Layer *bar = createStatusBarLayer();
	bar->setPosition(pos);
	this->addChild(bar);
}



void TDDSuiteLayer::setupTestMenu()
{
	Size screenSize = TDDHelper::getScreenSize();
	Size menuSize = Size(screenSize.width, screenSize.height - kToolBarHeight);
	
	//log("DEBUG: screenSize=%f,%f menuSize=%f,%f", screenSize.width, screenSize.height,
	//	menuSize.width, menuSize.height);
	
	TDDMenu *menu = new TDDMenu(menuSize, kColorTestMenu, kLineHeight);
	this->addChild(menu);
	menu->release();
	
	// Set to the class variable
	mTestMenu = menu;
	
	// Refresh Menu Data
	mMode = TDDData::instance()->getMenuMode();
	if(mMode == TDDMenuModeHistory) {
		setDisplayTestWithHistory();
	} else {
		setDisplayTestWithFilter();
	}
}

const char *TDDSuiteLayer::getFilterName()
{
	return TDDHelper::getFilter();
}

void TDDSuiteLayer::createMenuItemArray(const std::vector<int> &testIndices, Vector<MenuItem *> &menuArray)
{
	MenuItemFont::setFontName("GillSans");
	MenuItemFont::setFontSize(22);
	
	MenuItem *menuItem;
	for(int i=0; i<testIndices.size(); i++) {
		int index = testIndices.at(i);
		
		const char *name = gTestArray[index].name;
		
		//menuItem = TDDHelper::createMenuItem(name, CC_CALLBACK_1(TDDSuiteLayer::menuCallback, this));
		menuItem = TDDHelper::createMenuItemWithFont(name, TDD_FONT_NAME,
										CC_CALLBACK_1(TDDSuiteLayer::menuCallback, this));
		menuItem->setTag(index);	// this must be the index of the test in the gTestArray
		
		menuArray.pushBack(menuItem);
	}
}

void TDDSuiteLayer::createTestMenuItemArray(
							const std::vector<std::string> &testNames,
							Vector<MenuItem *> &menuArray)
{
	MenuItemFont::setFontName("GillSans");
	MenuItemFont::setFontSize(22);
	
	MenuItem *menuItem;
	for(int i=0; i<testNames.size(); i++) {
		std::string name = testNames[i];
		//menuItem = TDDHelper::createMenuItem(name, CC_CALLBACK_1(TDDSuiteLayer::menuCallback, this));
		menuItem = TDDHelper::createMenuItemWithFont(name.c_str(), TDD_FONT_NAME,
													 CC_CALLBACK_1(TDDSuiteLayer::menuCallback, this));
		menuItem->setTag(i);	// this must be the index of the test in the gTestArray
		
		menuArray.pushBack(menuItem);
	}
}


void TDDSuiteLayer::refreshTestMenu()
{
	//Array *menuArray = Array::createWithCapacity(gTestCount);
	Vector<MenuItem *> menuArray;
	
	createTestMenuItemArray(mDisplayTest, menuArray);
	
	mFilterCount = (int) mDisplayTest.size();
	
	// mTestMenu->setMenuItems(menuArray);
	int numCol = TDDHelper::isLandscape() ? 3 : 2;
	mTestMenu->setItemsWithColumn(menuArray, numCol);
	
	// update filter count
	updateStatusBar();
}

#pragma mark -
#pragma mark EditBoxDelegate
void TDDSuiteLayer::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
	//log("editBox change to [%s]", text.c_str());
	
	filterTest(NULL);
}

void TDDSuiteLayer::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
	
}

void TDDSuiteLayer::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
	
}

void TDDSuiteLayer::editBoxReturn(cocos2d::extension::EditBox* editBox)
{
	
}


#pragma mark - Display Test Data
void TDDSuiteLayer::setDisplayTestWithFilter()
{
	std::string name = TDDHelper::getFilter();
	setDisplayTestWithFilter(name);
	
}

void TDDSuiteLayer::setDisplayTestWithFilter(const std::string &filter)
{
	mDisplayTest.clear();
	log("testWithFilter");
	
	log("gTestCount: count=%d", gTestCount);
	
	// TODO: Filtering !!!!
	const char *filterPattern = getFilterName();
	
	for (int i = 0; i < gTestCount; i++)
	{
		const char *name = gTestArray[i].name;
		
		if(passFilter(name, filterPattern) == false) {
			continue;
		}
		
		mDisplayTest.push_back(std::string(name));
	}

	refreshTestMenu();

	// Tool bar
	mEditFilter->setEnabled(true);
	mEditFilter->setVisible(true);
	mClearMenu->setVisible(false);
	
	//
	updateStatusBar();

}

void TDDSuiteLayer::setDisplayTestWithHistory()
{
	
	// Update the mDisplay vector and refresh the menu
	mDisplayTest.clear();
	
	
	// TODO: Filtering !!!!
	std::vector<std::string> tests = TDDData::instance()->getTestHistory();
	
	for (int i = 0; i < tests.size(); i++)
	{
		mDisplayTest.push_back(tests[i]);
	}
	
	refreshTestMenu();
	
	//
	mEditFilter->setEnabled(false);
	mEditFilter->setVisible(false);
	mClearMenu->setVisible(true);
	
	//
	updateStatusBar();
}

#pragma mark -
#pragma mark Test Action Handling
void TDDSuiteLayer::runTest(int testIdx)
{
	
	if(testIdx < 0 || testIdx >= gTestCount) {
		log("ERROR: TDDSuteLayer.runTest: invalid index=%d", testIdx);
		return;
	}
	
	// create the test scene and run it
    auto scene = gTestArray[testIdx].callback();
	if (scene)
    {
		Director::getInstance()->pushScene(scene);
        scene->release();
    }
}

int TDDSuiteLayer::getTestIndexByName(const std::string &testName)
{
	for (int i = 0; i < gTestCount; i++)
	{
		const char *name = gTestArray[i].name;
		
		if(testName.compare(name) == 0) {
			return i;
		}
	}
	
	return -1;
}

std::string TDDSuiteLayer::getDisplayTestNameByIndex(int index)
{
	if(index < 0 || index >= mDisplayTest.size()) {
		return "";
	}
	
	return mDisplayTest[index];
}

void TDDSuiteLayer::menuCallback(Ref * sender)
{
	//log("menuCallback: is called");
	MenuItem *item = dynamic_cast<MenuItem *>(sender);
	
	std::string testName = getDisplayTestNameByIndex(item->getTag());
	//log("item tag=%d %s", item->getTag(), testName.c_str());
	
	int testIdx = getTestIndexByName(testName);
	if(testIdx < 0) {
		log("Cannot find the test! name=%s", testName.c_str());
		return;
	}
	
	TDDData::instance()->addTest(testName);
	
	runTest(testIdx);
	
}

int TDDSuiteLayer::getTotalTestCount()
{
	return gTestCount;
}

int TDDSuiteLayer::getFilteredTestCount()
{
	return mFilterCount;
}


#endif