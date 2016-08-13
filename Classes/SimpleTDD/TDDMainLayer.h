//
//  TDDMainLayer.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 13/8/2016.
//
//

#ifndef TDDMainLayer_hpp
#define TDDMainLayer_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

#include "TDDTable.h"

class TDDTopBar;

// The layer contains the TopBar and TDDTable
class TDDMainLayer : public LayerColor
{
public:
	CREATE_FUNC(TDDMainLayer);
	TDDMainLayer();
	~TDDMainLayer();
	bool init();		// simple init
	
	void setupGUI();	// call after theme setting
	
	// Property
	CC_SYNTHESIZE(Color4B, mBackgroundColor, BackgroundColor);
};

#endif /* TDDMainLayer_hpp */
