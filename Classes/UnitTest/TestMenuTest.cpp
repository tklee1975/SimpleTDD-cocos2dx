#ifdef ENABLE_TDD
//
//  TestMenuTest.m
//	TDD Framework
//
//
#include "TestMenuTest.h"
#include "TDDHelper.h"
//#include "VisibleRect.h"

void TestMenuTest::setUp()
{
	log("TDD Setup is called");
	
	Label *label = Label::createWithSystemFont("Testing for BaseTest Menu",
											   "arial", 14);
	
	label->setPosition(Vec2(120, 150));
	addChild(label);
}


void TestMenuTest::tearDown()
{
	log("TDD tearDown is called");
}

void TestMenuTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void TestMenuTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TestMenuTest::defineTests()
{
	ADD_TEST(testChangeSize);
	ADD_TEST(testAlignMenu);
	ADD_TEST(testSetMenuVisible);
	ADD_TEST(testSetMenuColor);
}

#pragma mark -
#pragma mark Sub Test Definition
void TestMenuTest::testSample()
{
	log("this is a sample subTest");
}

void TestMenuTest::testHeaderColor()
{
	log("this is a sample subTest");
}

void TestMenuTest::testChangeSize()
{
	const int nSize = 3;
	Size sizeList[nSize] = {
		Size(300, 300),
		Size(200, 200),
		Size(400, 100),
	};
	
	static int index = 0;
	
	
	Size selectedSize = sizeList[index];
	
	// Change Size
	setMenuSize(selectedSize);
	
	
	// next index
	index = (index + 1) % nSize;
}

void TestMenuTest::testAlignMenu()
{
	std::vector<TDDAlign> alignList = TDDHelper::getAlignList();
	
	static int index = 0;
	
	TDDAlign selectedAlign = alignList[index];
	
	alignMenu(selectedAlign);
	
	// next index
	index = (index + 1) % alignList.size();
}

void TestMenuTest::testSetMenuVisible()
{
	setMenuVisible(false);
}

void TestMenuTest::testSetMenuColor()
{
	const int nColor = 3;
	Color4B headerColor[nColor] = {
			Color4B(200, 100, 100, 125),
			Color4B(50, 100, 50, 125),
			Color4B(200, 200, 100, 125)
	};
	Color4B bgColor[nColor] = {
			Color4B(100, 200, 100, 125),
			Color4B(100, 100, 200, 125),
			Color4B(100, 200, 200, 125),
	};
	
	static int index = 0;
	setMenuColor(headerColor[index], bgColor[index]);
	
	// next index
	index = (index + 1) % nColor;
}

#endif
