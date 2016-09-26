//
//  TDDConsoleView.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 25/9/2016.
//
//

#ifndef TDDConsoleView_hpp
#define TDDConsoleView_hpp

#include <stdio.h>


#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include <string>
#include <vector>
#include "cocostudio/CocoStudio.h"
#include "CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TDDConsoleView : public LayerColor
{
public:
	static TDDConsoleView *create(const Size &contentSize);
	
	TDDConsoleView();
	~TDDConsoleView();
	
	bool initWithSize(const Size &contentSize);

	CC_SYNTHESIZE(Color4B, mBackgroundColor, BackgroundColor);
	CC_SYNTHESIZE(Color3B, mTextColor, TextColor);
	CC_SYNTHESIZE(std::string, mFontName, FontName);
	CC_SYNTHESIZE(int, mFontSize, FontSize);

	void appendLog(const std::string &msg);
	void scrollToTop();
	
protected:
	ScrollView *mScrollView;
	Layer *mScrollContentLayer;
	ui::Text *mContentText;
	
	std::string mContent;
};


#endif /* TDDConsoleView_hpp */
