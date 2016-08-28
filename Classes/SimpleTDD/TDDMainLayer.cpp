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
, mTableTextColor(Color4B::BLUE)
, mTableFontSize(14)
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

void TDDMainLayer::updateResult(std::vector<std::string> &result)
{
	// Copy the resultList
	mResultList.clear();
	for(int i=0; i<result.size(); i++) {
		mResultList.push_back(result[i]);
	}
	
	//
	mResultTable->updateData();
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
	float cellHeight = 40;
	mTableCellSize = Size(cellWidth, cellHeight);

	// Non GUI
	mSearchType = TDDManager::instance()->getSearchType();
	mKeyword = TDDManager::instance()->getKeyword(mSearchType);
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
	topBar->setup(mSearchType, mKeyword);
	
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

	
	// Add the Table
	TDDTable *table = TDDTable::create(tableSize);
	table->setColumn(mColumn);
	table->setTitleColor(Color3B(0,0,148));
	table->setBackgroundColor(Color4B(0,0,0,0));
	table->setFontSize(12);
	table->setDelegate(this);
	//delegate->release();
	
	table->updateData();
	
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

#endif