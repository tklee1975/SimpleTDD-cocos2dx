//
//  TDDMainLayer.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 13/8/2016.
//
//

#ifdef ENABLE_TDD
#include "TDDMainLayer.h"
#include "TDDTopBar.h"
#include "TDDManager.h"
#include "TDDHelper.h"
#include "TDDConstant.h"

Scene *TDDMainLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();
	
	// 'layer' is an autorelease object
	auto layer = TDDMainLayer::create();
	
	// add layer as a child to scene
	scene->addChild(layer);
	
	// return the scene
	return scene;
}


TDDMainLayer::TDDMainLayer()
: mBackgroundColor(Color4B::WHITE)
, mKeyword("")
, mResultList()
, mColumn(4)
, mTopBar(nullptr)
, mResultTable(nullptr)
, mStatusLayer(nullptr)
, mTableTextColor(Color4B::BLUE)
, mTableFontSize(14)
, mCountLabel(nullptr)
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

	setupData();
	
	return true;	
}

void TDDMainLayer::setupData()
{
	if(TDDSearchRecent == mSearchType) {
		showRecentTest(mKeyword);
	} else {
		showAllTest(mKeyword);
	}
	
}

void TDDMainLayer::updateTestCount(int searchCount)
{
	int total = TDDManager::instance()->getTestCount();
	std::string info = StringUtils::format("Tests: %d / %d", searchCount, total);
	
	if(mCountLabel) {
		mCountLabel->setString(info);
	}
}

void TDDMainLayer::updateResult(std::vector<std::string> &result)
{
	// Copy the resultList
	mResultList.clear();
	for(int i=0; i<result.size(); i++) {
		mResultList.push_back(result[i]);
	}
	
	//
	mResultTable->refresh();
	
	updateTestCount((int) result.size());
}

void TDDMainLayer::showAllTest(const std::string &keyword)
{
	std::vector<std::string> result = TDDManager::instance()->getTestList(keyword);
	updateResult(result);
}

void TDDMainLayer::showRecentTest(const std::string &keyword)
{
	std::vector<std::string> result = TDDManager::instance()->getRecentTestList(keyword);
	updateResult(result);
}


void TDDMainLayer::setupProperties()
{
	mColumn = TDDHelper::isLandscape() ? 4 : 2;
	
	float cellWidth = getContentSize().width / mColumn;
	float cellHeight = 35;
	mTableCellSize = Size(cellWidth, cellHeight);

	// Non GUI
	mSearchType = TDDManager::instance()->getSearchType();
	mKeyword = TDDManager::instance()->getKeyword(mSearchType);
}

#pragma mark - setting up GUI
void TDDMainLayer::setupGUI()	// call after theme settin
{
	// Define the layout data for the key component
	
	//    (Size)
	Size layerSize = getContentSize();
	
	Size topBarSize = Size(layerSize.width, 70);
	Size tableSize = Size(layerSize.width, layerSize.height - topBarSize.height);
	Size statusSize = Size(layerSize.width, 20);
	
	//    (Position)
	Vec2 topBarPos = Vec2(0, layerSize.height - topBarSize.height);		// pos at left-bottom corner;
	Vec2 tablePos = Vec2(0, 0);			// pos at left-bottom corner
	Vec2 statusPos = Vec2(0, 0);
	
	// Adding the top bar
	setupTopBar(topBarSize, topBarPos);
	setupTestTable(tableSize, tablePos);
	setupStatusBar(statusSize, statusPos);
}

void TDDMainLayer::setupStatusBar(const Size &size, const Vec2 &pos)
{
	// The container Layer
	Color4B bgColor = TDD_COLOR4_TRANS_BLUE;
	LayerColor *layer = LayerColor::create(bgColor, size.width, size.height);
	layer->setPosition(pos);
	addChild(layer);
	mStatusLayer = layer;

	// Layout Position & Size
	float margin = 5;
	float halfHeight = size.height / 2;
	Vec2 countPos = Vec2(margin, halfHeight);
	Vec2 versionPos = Vec2(size.width - margin, halfHeight);
	float fontSize = 12;
	
	// Version Label
	std::string name = TDDManager::instance()->getVersion();
	Label *label = Label::createWithSystemFont(name, "", fontSize);
	// label->setColor
	label->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
	label->setPosition(versionPos);
	addChild(label);
	
	// Result Count
	std::string countValue = "tests: ?/?";
	label = Label::createWithSystemFont(countValue, "", fontSize);
	// label->setColor
	label->setAnchorPoint(Vec2::ANCHOR_MIDDLE_LEFT);
	label->setPosition(countPos);
	addChild(label);
	mCountLabel = label;
}

void TDDMainLayer::setupTopBar(const Size &size, const Vec2 &pos)
{
	TDDTopBar *topBar = TDDTopBar::create(size);
	topBar->setTopBarColor(Color4B(TDD_COLOR_BLUE2));
	topBar->setPosition(pos);
	topBar->setup(mSearchType, mKeyword);
	
	topBar->updateColor();
	
	addChild(topBar);
	mTopBar = topBar;
	
	// Adding the listener
	topBar->setCloseListener([&](TDDTopBar *topBar){
		handleClose();
	});
	
	topBar->setTabChangeListener([&](TDDTopBar *topBar, TDDSearchType tab){
		if(tab == TDDSearchAll) {
			handleAllTab();
		} else if(tab == TDDSearchRecent) {
			handleRecentTab();
		}
	});
	
	topBar->setKeywordChangeListener([&](TDDTopBar *topBar, const std::string &keyword){
		handleSearchKeyChanged(keyword);
		// log("keyword change to %s", keyword.c_str());
	});
}

void TDDMainLayer::setupTestTable(const Size &size, const Vec2 &pos)
{
	
	// Add the Table
	TDDTable *table = TDDTable::create(size);
	table->setPosition(pos);
	table->setColumn(mColumn);
	table->setTitleColor(Color3B(0,0,148));
	table->setBackgroundColor(Color4B(0,0,0,0));
	table->setFontSize(12);
	table->setDelegate(this);
	
	table->refresh();
	
	addChild(table);
	mResultTable = table;
}


std::string TDDMainLayer::getTestName(int index)
{
	if(index < 0 || index >= mResultList.size()) {
		return "";
	}

	return mResultList[index];
}

void TDDMainLayer::handleClose()
{
	Director::getInstance()->popScene();
}

void TDDMainLayer::updateKeyword(const std::string &keyword)
{
	mKeyword = keyword;
	mTopBar->setSearchKeyword(mKeyword);
}

void TDDMainLayer::handleAllTab()
{
	mSearchType = TDDSearchAll;
	
	TDDManager::instance()->saveSearchType(mSearchType);
	
	updateKeyword(TDDManager::instance()->getKeyword(mSearchType));
	
	// update the gui
	showAllTest(mKeyword);
	
	//TDDManager
}

void TDDMainLayer::handleRecentTab()
{
	mSearchType = TDDSearchRecent;
	
	TDDManager::instance()->saveSearchType(mSearchType);
	
	updateKeyword(TDDManager::instance()->getKeyword(mSearchType));
	
	// update the gui
	showRecentTest(mKeyword);
}

void TDDMainLayer::handleSearchKeyChanged(const std::string &keyword)
{
	// update the data
	mKeyword = keyword;
	TDDManager::instance()->saveKeyword(mSearchType, keyword);
	
	// Update the GUI
	if(mSearchType == TDDSearchRecent) {
		showRecentTest(mKeyword);
	} else {
		showAllTest(mKeyword);
	}
	
	
	//int currenTab = mTopBar->getT
}


#pragma mark - TDDTableDelegate
int TDDMainLayer::getTableCellCount()
{
	return (int) mResultList.size();
}

Size TDDMainLayer::getTableCellSize()
{
	return mTableCellSize;
}


void TDDMainLayer::runTest(const std::string &test)
{
	TDDManager::instance()->runTest(test);
	
}

Node *TDDMainLayer::tableCellForIndex(int index)
{
	std::string name = getTestName(index);
	

	
	ui::Button *button = ui::Button::create();
	//button->setColor(Color3B::YELLOW);		// this is no use
	button->setTitleText(name);
	button->setContentSize(mTableCellSize);
	button->setTitleColor(mTableTextColor);
	button->setTitleFontSize(mTableFontSize);
	
	button->addClickEventListener([&, name](Ref *) {
		runTest(name);
	});
	
	return button;
}

#pragma mark - onEnter & onExit
void TDDMainLayer::onEnter()
{
	Layer::onEnter();
	
	mWasShowStat = Director::getInstance()->isDisplayStats();
	Director::getInstance()->setDisplayStats(false);
}

void TDDMainLayer::onExit()
{
	Director::getInstance()->setDisplayStats(mWasShowStat);
	 
	Layer::onExit();
	
	
}

#endif