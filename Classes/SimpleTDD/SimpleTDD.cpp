//
//  SimpleTDD.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 19/8/2016.
//
//

#include "SimpleTDD.h"
#include "TDDHelper.h"
#include "TDDManager.h"
#include "TDDMainLayer.h"

void SimpleTDD::setup(Node *parent, const Vec2 &pos,
						const Color4B &bgColor,
						const Color3B &textColor,
						int fontSize)
{
#if (ENABLE_TDD == 1)
	if(parent == nullptr) {
		log("SimpleTDD.setup: parent is null!!");
		return;
	}
	
	//
	cocos2d::ui::Button *button;
	Size size = Size(fontSize * 7, fontSize * 2);
	
	button = TDDHelper::addButtonWithBackground(parent, pos,
												size,
												"SimpleTDD",
												textColor, bgColor);
	
	button->setTitleFontSize(fontSize);
	
	button->addClickEventListener([&](Ref *) {
		auto scene = TDDMainLayer::createScene();
		
		Director::getInstance()->pushScene(scene);
	});
	
#else 
	log("SimpleTDD: Unit Test Disabled!! define ENABLE_TDD = 1 to enable!");
#endif
	
}