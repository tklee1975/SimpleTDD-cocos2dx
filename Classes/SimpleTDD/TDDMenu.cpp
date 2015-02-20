//
//  TDDMenu.cpp
//  TDDLib
//
//	The list of the test
//
//	constructor
//		Size / Color / RowHeight
//		delegate
//
//	Setting
//		NSArray<MenuItem *>
//
//
//
//  Created by Ken Lee on 16/12/13.
//
//
#include "TDDMenu.h"
#include "TDDHelper.h"

TDDMenu::TDDMenu(Size size, Color4B color, float rowHeight)
: mMenu(NULL)
{
	// Data Array to keep the menuItem
	//
	mRowHeight = rowHeight;

	// Setting the size of the scroll
	this->initWithViewSize(size);

	// Create the layer to contain the result
	LayerColor *layer = LayerColor::create(color, size.width, size.height);
	this->setContainer(layer);
	mMainLayer = layer;

	
	
	// create the menu
	Menu *menu = Menu::create();
	menu->setPosition(Point(0, 0));
	menu->alignItemsVertically();
	layer->addChild(menu);
	mMenu = menu;
	
	// configure the scrollView
	this->setDirection(ScrollView::Direction::VERTICAL);
}


TDDMenu::~TDDMenu()
{
}

void TDDMenu::addMenuItems(Vector<MenuItem *> &itemArray)
{
	float layerH = mMainLayer->getContentSize().height;
	float layerW = mMainLayer->getContentSize().width;
	
	Point pos = Point(layerW / 2, layerH - mRowHeight / 2);
	log("addMenuItems: pos=%f,%f", pos.x, pos.y);
	int order = 10000;
	
	for(int i=0; i<itemArray.size(); i++) {
		MenuItem *menuItem = itemArray.at(i);
		if(! menuItem) {
			log("addMenuItems: i=%d is null", i);
			continue;
		}
		
		
		log("addMenuItems: i=%d pos=%f,%f", i, pos.x, pos.y);
		menuItem->setPosition(pos);
		mMenu->addChild(menuItem, order);
		order++;
		
		pos.y -= mRowHeight;
	}

}

void TDDMenu::setMenuItems(Vector<MenuItem *> &itemArray)
{
	if(mMenu == NULL) {
		log("setMenuItem: error. mMenu is NULL");
		return;
	}
	// clean up first
	// mMainLayer->removeAllChildren();
	mMenu->removeAllChildren();
	
	int numMenus = (int) itemArray.size();
	float viewH = this->getViewSize().height;
	float viewW = this->getViewSize().width;
	
	// layer
	float layerH = MAX(mRowHeight * numMenus, viewH);
	float layerW = viewW;
	
	log("new layerH=%f viewH=%f", layerH, viewH);
	
	// Resize the layer
	Size newSize = Size(layerW, layerH);
	mMainLayer->setContentSize(newSize);
	this->setContentSize(newSize);
	
	//
	this->addMenuItems(itemArray);
	
	
	// mMenu->alignItemsVertically();
	// Scroll to Top
	TDDHelper::scrollToTop(this);
}


void TDDMenu::setItemsWithColumn(Vector<MenuItem *> &itemArray, int column)
{
	// clean up first
	// mMainLayer->removeAllChildren();
	mMenu->removeAllChildren();
	
	
	// Add the new menuItem
	for(int i=0; i<itemArray.size(); i++)
	{
		MenuItem *menuItem = itemArray.at(i);
		if(! menuItem) { continue; }
		mMenu->addChild(menuItem, i);
	}
	
	float viewH = this->getViewSize().height;
	float viewW = this->getViewSize().width;
	
	Size menuSize = TDDHelper::alignMenuItem(mMenu, viewW, column, 10);
	
	
	// layer
	float layerH = menuSize.height;	//MAX(menuSize.height, viewH);
	float layerW = menuSize.width;
	
	log("new layerH=%f viewH=%f", layerH, viewH);
	
	// Resize the layer
	Size newSize = Size(layerW, layerH);
	mMainLayer->setContentSize(newSize);
	this->setContentSize(newSize);
	log("newContentSize: %f,%f", newSize.width, newSize.height);
	
	// mMenu->alignItemsVertically();
	// Scroll to Top
	TDDHelper::scrollToTop(this);
}
