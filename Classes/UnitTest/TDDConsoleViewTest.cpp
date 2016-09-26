#ifdef ENABLE_TDD
//
//  TDDConsoleViewTest.m
//	TDD Framework
//
//
#include "TDDConsoleViewTest.h"
#include "TDDHelper.h"
#include "TDDConsoleView.h"

void TDDConsoleViewTest::setUp()
{
	log("TDD Setup is called");
}


void TDDConsoleViewTest::tearDown()
{
	log("TDD tearDown is called");
}

void TDDConsoleViewTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void TDDConsoleViewTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TDDConsoleViewTest::defineTests()
{
	ADD_TEST(testSample);
	ADD_TEST(testClear);
	ADD_TEST(testAppend);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDConsoleViewTest::testSample()
{
	log("this is a sample subTest");
	TDDConsoleView *view = TDDConsoleView::create(Size(300, 250));
	
	addChild(view);
	
	for(int i=0; i<100; i++) {
		std::string str = StringUtils::format("testing %d", i);
		view->appendLog(str);
	}

	mConsoleView = view;
}

void TDDConsoleViewTest::testClear()
{
	if(mConsoleView) {
		mConsoleView->clear();
		mConsoleView->appendLog("first log");
	}
}

void TDDConsoleViewTest::testAppend()
{
	static int counter = 0;
	if(mConsoleView) {
		mConsoleView->appendLog(StringUtils::format("new line %d", (counter++)));
	}
}
#endif
