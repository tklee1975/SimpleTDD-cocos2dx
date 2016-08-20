#ifdef ENABLE_TDD
//
//  TDDTestMenuTest.m
//	TDD Framework 
//
//
#include "TDDTestMenuTest.h"
#include "TDDHelper.h"
#include "TDDTestMenu.h"

#define ADD_TEST(__name__)	addTest(#__name__, [&]() { __name__(); });


//{#__ClassName__, []() { return new __ClassName__(); } }

void TDDTestMenuTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TDDTestMenuTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}


void TDDTestMenuTest::addTest(const std::string &name, const std::function<void()> &callback)
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

void TDDTestMenuTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDTestMenuTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDTestMenuTest::subTest(Ref *sender)
{
	// Define the test
//	addTest("test1", [&](){
//		test1();
//	});
//	
//	addTest("test2", [&](){
//		test2();
//	});
	
	ADD_TEST(test1);
	ADD_TEST(test2);
	

	//
	TDDTestMenu *menu = TDDTestMenu::create();
	
	
	menu->setPosition(Vec2(50, 50));
	// menu->updateSizeAndPosition();
	
	addChild(menu);
	
	// Define the test to the menu
	menu->setTestSelectedCallback([&](const std::string &name) {
		doTestCallback(name);
	});
	
	menu->setTests(mTestNameList);
	
}

void TDDTestMenuTest::test1()
{
	log("test1");
}

void TDDTestMenuTest::test2()
{
	log("test2");
}


#endif
