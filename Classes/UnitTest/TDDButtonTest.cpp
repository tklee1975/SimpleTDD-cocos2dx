#ifdef ENABLE_TDD
//
//  TDDButtonTest.m
//	TDD Framework
//
//
#include "TDDButtonTest.h"
#include "TDDHelper.h"
#include "TDDButton.h"
#include "VisibleRect.h"

void TDDButtonTest::setUp()
{
	log("TDD Setup is called");
}


void TDDButtonTest::tearDown()
{
	log("TDD tearDown is called");
}

void TDDButtonTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void TDDButtonTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TDDButtonTest::defineTests()
{
	ADD_TEST(testSample);
	ADD_TEST(testVariousStyle);
	ADD_TEST(testButtonChange);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDButtonTest::testSample()
{
	TDDButton *button;
	Size size = Size(100, 50);
	
	
	button = TDDButton::create();
	button->setTitleText("clickMe");
	
	button->setAnchorPoint(Vec2(0.5f, 0.5f));
	button->setContentSize(size);
	//sbutton->setTitleColor(Color3B::BLUE);
	// button->setPosition(Vec2(0, 0));
	button->setPosition(Vec2(100, 100));
	//button->setBackGroundColor(Color3B::YELLOW);
	addChild(button);
	
	button->addClickEventListener([&](Ref *) {
		TDDHelper::showToastAlert("TDDButton is clicked", VisibleRect::center());
		log("Testing!!");
	});

	// Testing code
	
//	Layout *panel = Layout::create();
//	panel->setContentSize(Size(100, 100));
//	panel->setPosition(Vec2(200, 200));
//	panel->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
//	panel->setBackGroundColor(Color3B::BLUE);
//	addChild(panel);
//	
	
	
	

}

void TDDButtonTest::testVariousStyle()
{
	const int nStyle = 2;
	
	Color3B titleColor[nStyle] = {Color3B::RED, Color3B::GREEN};
	Color4B bgColor[nStyle] = {Color4B::GREEN, Color4B::RED};
	float fontSize[nStyle] = {10, 20};
	
	Vec2 pos = Vec2(100, 100);
	Size size = Size(100, 50);

	
	TDDButton *button;
	
	for(int i=0; i<nStyle; i++) {
		
		
		
		button = TDDButton::create();
		button->setTitleText(StringUtils::format("Button %d", i));
	
		button->setAnchorPoint(Vec2(0.5f, 0.5f));
		button->setContentSize(size);
		button->setTitleFontSize(fontSize[i]);
		button->setTitleColor(titleColor[i]);
		button->setBackgroundColor(bgColor[i]);
		
		button->setPosition(pos);
	
		addChild(button);
		pos.y += 60;
	}
	//sbutton->setTitleColor(Color3B::BLUE);
	
	//button->setBackGroundColor(Color3B::YELLOW);
	
}

void TDDButtonTest::testButtonChange()
{
	
	Size size = Size(200, 50);
	float fontSize = 16;
	
	TDDButton *button;
	button = TDDButton::create();
	button->setTitleText("TDDButton (NEW)");
	button->setContentSize(size);
	button->setTitleFontSize(fontSize);
	button->setTitleColor(Color3B::RED);
	button->setPosition(Vec2(150, 100));
	button->setBackgroundColor(Color4B::YELLOW);
	addChild(button);
	button->addClickEventListener([&](Ref *) {
		TDDHelper::showToastAlert("TDDButton is clicked", VisibleRect::center());
		
	});
	

	

	ui::Button *uiButton = TDDHelper::addButtonWithBackground(this,
					Vec2(150, 200), size, "ui:Button (OLD)",
					Color3B::GREEN, Color4B::YELLOW);
	uiButton->setTitleFontSize(fontSize);
	uiButton->addClickEventListener([&](Ref *) {
		TDDHelper::showToastAlert("ui::Button is clicked", VisibleRect::center());
		
	});
}


#endif
