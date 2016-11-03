#ifdef ENABLE_TDD
//
//  TDDButtonTest.m
//	TDD Framework
//
//
#include "TDDButtonTest.h"
#include "TDDHelper.h"
#include "TDDButton.h"

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
	button->setPosition(Vec2(0, 0));
	//button->setBackGroundColor(Color3B::YELLOW);
	addChild(button);
	
	Layout *panel = Layout::create();
	panel->setContentSize(Size(100, 100));
	panel->setPosition(Vec2(200, 200));
	panel->setBackGroundColorType(Layout::BackGroundColorType::SOLID);
	panel->setBackGroundColor(Color3B::BLUE);
	addChild(panel);
	
//	button->addClickEventListener([&](Ref *) {
//		log("Testing!!");
//	});
	
	
	

}

void TDDButtonTest::testVariousStyle()
{
	const int nStyle = 2;
	
	Color3B titleColor[nStyle] = {Color3B::RED, Color3B::GREEN};
	Color3B bgColor[nStyle] = {Color3B::GREEN, Color3B::RED};
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
		button->setBackGroundColor(bgColor[i]);
		
		button->setPosition(pos);
	
		addChild(button);
		pos.y += 60;
	}
	//sbutton->setTitleColor(Color3B::BLUE);
	
	//button->setBackGroundColor(Color3B::YELLOW);
	
}

#endif
