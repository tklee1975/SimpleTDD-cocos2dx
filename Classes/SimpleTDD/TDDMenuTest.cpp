#ifdef ENABLE_TDD
//
//  TDDMenuTest.m
//	TDD Framework 
//
//
#include "TDDMenuTest.h"
#include "TDDHelper.h"
#include "TDDMenu.h"

void TDDMenuTest::callback(Ref * sender)
{
	log("TDDMenuTest:callback is called");
	long count = mMenuArray.size();
	
	char tempStr[100];
	sprintf(tempStr, "newMenu-%ld", count);
	
	MenuItem *menuItem = TDDHelper::createMenuItem(tempStr,
							CC_CALLBACK_1(TDDMenuTest::callback, this));
	mMenuArray.pushBack(menuItem);

	// update the menu items
	// mMenu->setMenuItems(mMenuArray);
}

void TDDMenuTest::tearDown()
{
}

void TDDMenuTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	//Size size = TDDHelper::getScreenSize();

	// Construct the array
	Vector<MenuItem *> menuArray;
	
	for (int i = 0; i < 10; i++)
	{
		char tempStr[100];
		sprintf(tempStr, "menu-%d", i);

		//  MenuItem *item = MenuItemFont::create(temp, CC_CALLBACK_1(ButtonTest::onMenuSelected, this));
		// MenuItem *menuItem = TDDHelper::createMenuItem(tempStr,
		//						CC_CALLBACK_1(TDDMenuTest::callback, this));
		MenuItem *menuItem = MenuItemFont::create(tempStr, CC_CALLBACK_1(TDDMenuTest::callback, this));
		menuItem->setColor(Color3B::WHITE);
		menuArray.pushBack(menuItem);
	}
	
	TDDMenu *menu = new TDDMenu(Size(400, 300), Color4B(100, 100, 200, 100), 40);
	menu->setPosition(Point(50, 50));
	this->addChild(menu);
	menu->release();
	mMenu = menu;
	
	// update the menu
	// menu->setMenuItems(menuArray);
	menu->setItemsWithColumn(menuArray, 3);
}

#endif