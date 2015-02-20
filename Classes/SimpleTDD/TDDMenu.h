//
//  TDDMenu.h
//  Dg
//
//  Created by Ken Lee on 16/12/13.
//
//

#ifndef __TDDLib__TDDMenu__
#define __TDDLib__TDDMenu__

#include <iostream>


#include "cocos2d.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;


class TDDMenu : public ScrollView
{
public:
	TDDMenu(Size size, Color4B color, float rowHeight);
	~TDDMenu();
	
	void setMenuItems(Vector<MenuItem *> &itemArray);
	void setItemsWithColumn(Vector<MenuItem *> &itemArray, int column=3);
	
	// private data
private:
	LayerColor *mMainLayer;
	Menu *mMenu;
	float mRowHeight;
//	Array *mMenuItemArray;
	
	// private method
private:
	void addMenuItems(Vector<MenuItem *> &itemArray);
};



#endif /* defined(__Dg__TDDMenu__) */
