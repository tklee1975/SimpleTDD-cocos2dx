#ifdef ENABLE_TDD
//
//  TDDTestMenuTest.m
//	TDD Framework 
//
//
#include "TDDTestMenuTest.h"
#include "TDDHelper.h"
#include "TDDTestMenu.h"

#define ADD_SUB_TEST(__name__)	addSubTest(#__name__, [&]() { __name__(); });


//{#__ClassName__, []() { return new __ClassName__(); } }

void TDDTestMenuTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	
	//
	TDDTestMenu *menu = TDDTestMenu::create();
	
	menu->setPosition(Vec2(0, 0));
	// menu->updateSizeAndPosition();
	menu->setTests(mTestNameList);
	addChild(menu);
	
	mTestMenu = menu;
}


void TDDTestMenuTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}


void TDDTestMenuTest::addSubTest(const std::string &name, const std::function<void()> &callback)
{
	mTestNameList.push_back(name);
	mTestCallbackMap[name] = callback;
}

void TDDTestMenuTest::doTestCallback(const std::string &name)
{
	std::function<void()> callback = mTestCallbackMap[name];
	if(callback == nullptr) {
		log("doTestCallback: callback is null. name=%s", name.c_str());
		return;
	}
	
	callback();
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDTestMenuTest::defineTests()
{
	ADD_TEST(subTest);
	ADD_TEST(testTheme);
	ADD_TEST(testSetColumn);
	ADD_TEST(testSetSize);	
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDTestMenuTest::subTest()
{
	// Define the test
//	addTest("test1", [&](){
//		test1();
//	});
//	
//	addTest("test2", [&](){
//		test2();
//	});
	
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	ADD_SUB_TEST(toggle);
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);
	ADD_SUB_TEST(test1);
	ADD_SUB_TEST(test2);

	//
	TDDTestMenu *menu = TDDTestMenu::create();
	
	
	menu->setPosition(Vec2(50, 50));
	// menu->updateSizeAndPosition();
	
	addChild(menu);
	
	// Define the test to the menu
	menu->setTestSelectedCallback([&](const std::string &name) {
		doTestCallback(name);
	});
	
	menu->setBackCallback([&](TDDTestMenu *menu){
		log("back is called");
	});
	
	menu->setTests(mTestNameList);

	mTestMenu = menu;
}

void TDDTestMenuTest::test1()
{
	log("test1");
}

void TDDTestMenuTest::test2()
{
	log("test2");
}

void TDDTestMenuTest::toggle()
{
	if(mTestMenu) {
		mTestMenu->toggleMenu();
	}
}

void TDDTestMenuTest::testTheme()
{
	TDDTestMenu *menu = TDDTestMenu::create();
	menu->setPosition(Vec2(250, 50));

	menu->setMenuColor(Color4B::BLUE, Color4B::YELLOW);
	
	addChild(menu);
}

void TDDTestMenuTest::testSetColumn()
{
	if(mTestMenu) {
		mTestMenu->setColumn(3);
		mTestMenu->refreshTable();
	}
}

void TDDTestMenuTest::testSetSize()
{
	if(mTestMenu) {
		mTestMenu->setContentSize(Size(300, 300));
		mTestMenu->refreshTable();
	}
}


#endif
