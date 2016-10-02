#ifdef ENABLE_TDD
//
//  TDDTestMenu.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 20/8/2016.
//
//

#ifndef TDDTestMenu_hpp
#define TDDTestMenu_hpp

#include <stdio.h>

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

#include "TDDTable.h"

class TDDTestMenu : public LayerColor, public TDDTableDelegate
{
public:
	typedef std::function<void(const std::string &name)> TestSelectedCallback;
	typedef std::function<void(TDDTestMenu *)> TestMenuCallback;

public:
	CREATE_FUNC(TDDTestMenu);

	TDDTestMenu();

	bool init();

	// Setting the Test List
	void setTests(std::vector<std::string> &testList);
	void refreshMenu();

	// Callback
	void setTestSelectedCallback(const TestSelectedCallback &callback);
	void setBackCallback(const TestMenuCallback &callback);
	void setToggleConsoleCallback(const TestMenuCallback &callback);

	// Toggle the Menu
	void toggleMenu();
	void showMenu();
	void hideMenu();

	// Theme
	void setMenuColor(const Color4B &headerColor, const Color4B &bgColor);
	void setTextColor(const Color3B &textColor);
	void setColumn(int column);

	virtual void setContentSize(const Size &size);
	void setContentSizeByPercent(const Vec2 &percent);
	void setWidth(const float &width);
	void setHeight(const float &height);

	// Position and Size stuff
	Vec2 getTopPosition();
	
	//
	void refreshTable();

#pragma mark - TDDTableDelegate
private:
	virtual int getTableCellCount();
	virtual Size getTableCellSize();
	virtual Node *tableCellForIndex(int index);

#pragma mark - Touch handling
	void addTouchListener();
	virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);


#pragma mark - Support Method
private:
	std::string getTestName(int index);
	ui::Button *createButton(const std::string &title, const Size &size);

	void setupHeader();
	void setupTable();

	bool isTouchInsideHeader(const Vec2 &touchLocation);		// touchLocation is related to this component
	void moveBy(const Vec2 &delta);

#pragma mark - Internal Data
private:
	// For Sub Test List
	std::vector<std::string> mTestNameList;
	TDDTable *mTestTable;
	LayerColor *mHeaderNode;


	// Callback
	TestSelectedCallback mTestSelectedCallback;
	TestMenuCallback mBackCallback;
	TestMenuCallback mToggleConCallback;
	//std::function<

	// Menu Control
	bool mShow;			// true if the menu is showing

	// For Move Menu Logic
	bool mIsTouching;
	Vec2 mLastLocation;	// Node Location

	// Theme & Layout
	Color4B mHeaderColor;
	float mHeaderHeight;
	float mTableHeight;
	Size mHeaderButtonSize;
	int mColumn;

	ui::Button *mToggleButton;
};


#endif /* TDDTestMenu_hpp */

#endif
