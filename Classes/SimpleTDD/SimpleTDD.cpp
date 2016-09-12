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
						const std::string &title,
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
	size_t strLen = title.length();
	Size size = Size(fontSize * strLen, fontSize * 2);

	button = TDDHelper::addButtonWithBackground(parent, pos,
												size,
												title,
												textColor, bgColor);

	button->setTitleFontSize(fontSize);

	button->addClickEventListener([&](Ref *) {
		gotoTestScene();
	});

#else
	log("SimpleTDD: Unit Test Disabled!! define ENABLE_TDD = 1 to enable!");
#endif

}


void SimpleTDD::gotoTestScene()
{
#if (ENABLE_TDD == 1)
	auto scene = TDDMainLayer::createScene();
	
	Director::getInstance()->pushScene(scene);
#else
	log("SimpleTDD: Unit Test Disabled!! define ENABLE_TDD = 1 to enable!");
#endif
}

void SimpleTDD::gotoTest(const std::string &testName)
{
#if (ENABLE_TDD == 1)
	if(TDDManager::instance()->runTest(testName) == false) {
		log("Fail to run test '%s'", testName.c_str());
	}
	
#endif
}