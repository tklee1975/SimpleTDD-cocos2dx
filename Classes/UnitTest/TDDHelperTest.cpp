#ifdef ENABLE_TDD
//
//  TDDHelperTest.m
//	TDD Framework 
//
//
#include "TDDHelperTest.h"
#include "TDDHelper.h"
#include "TDDConstant.h"

void TDDHelperTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	mAlignList.push_back(TDDAlign::eTDDTopLeft);
	mAlignList.push_back(TDDAlign::eTDDTopCenter);
	mAlignList.push_back(TDDAlign::eTDDTopRight);
	mAlignList.push_back(TDDAlign::eTDDMidLeft);
	mAlignList.push_back(TDDAlign::eTDDMidCenter);
	mAlignList.push_back(TDDAlign::eTDDMidRight);
	mAlignList.push_back(TDDAlign::eTDDBottomLeft);
	mAlignList.push_back(TDDAlign::eTDDBottomCenter);
	mAlignList.push_back(TDDAlign::eTDDBottomRight);
	
}


void TDDHelperTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDHelperTest::defineTests()
{
	ADD_TEST(testResolveAlign);
	ADD_TEST(testFormat);
	ADD_TEST(testAlignNode);
	ADD_TEST(testAddButtonWithBg);
	ADD_TEST(testJoinString);
	ADD_TEST(testSplitString);
	ADD_TEST(testCreateLabel);
	ADD_TEST(testReplaceString);
	ADD_TEST(testColor);
	ADD_TEST(testTrimString);
	ADD_TEST(testMenuItemFont);
	ADD_TEST(testAlignMenuItem);
	ADD_TEST(testCreateEditBox);
}

#pragma mark -
#pragma mark Helper Method
Menu *TDDHelperTest::createMenu(int numitem)
{
	Vector<MenuItem*> menuItems;
	
	for(int i=0; i<numitem; i++) {
		char temp[100];
		sprintf(temp, "Item %d", i);
		
		
	    MenuItem *item = MenuItemFont::create(temp, NULL);
		menuItems.pushBack(item);
		
		Size itemSize = item->getContentSize();
		//log("menuItem.size=%f,%f", itemSize.width, itemSize.height);
	}
	
	
	return Menu::createWithArray(menuItems);
}

Menu *TDDHelperTest::createMenuWithFont(int numitem, const char *font, int fontSize, const Color3B &color)
{
	Vector<MenuItem*> menuItems;
	
	MenuItemFont::setFontName(font);
	MenuItemFont::setFontSize(fontSize);
	
	
	for(int i=0; i<numitem; i++) {
		char temp[100];
		sprintf(temp, "Item %d", i);
		
		
	    MenuItem *item = MenuItemFont::create(temp, NULL);
		menuItems.pushBack(item);
		
		Size itemSize = item->getContentSize();
		//log("menuItem.size=%f,%f", itemSize.width, itemSize.height);
	}
	
	for(int i=0; i<menuItems.size(); i++) {
		MenuItem *item = menuItems.at(i);
		item->setColor(color);
	}
	
	
	return Menu::createWithArray(menuItems);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDHelperTest::testCreateEditBox()
{
	log("testCreateEditBox");
	
	Point pos = Point(50, 100);
	Size size = Size(200, 60);
	
	EditBox *edit = TDDHelper::createEditBox(this, pos, size);
	edit->setAnchorPoint(Point(0, 0));
	edit->setText("Testing!!!");
}



void TDDHelperTest::testAlignMenuItem()
{
	int numCol = 3;
	int count = 100;
	Menu *menu = createMenu(count);
	menu->setPosition(Point(0, 0));

	
	int width = 500;
	Size menuSize = TDDHelper::alignMenuItem(menu, width, numCol);

	//LayerColor *colorLayer = LayerColor::create(Color4B::GRAY, menuSize.width, menuSize.height);
	// colorLayer->addChild(menu);

	Node *containerLayer = menu;
	
	
	ScrollView *scrollView = ScrollView::create(Size(width, 200));
	scrollView->setPosition(Point(50, 50));
	
	scrollView->setContainer(containerLayer);
	scrollView->setContentSize(menuSize);
	scrollView->setDirection(ScrollView::Direction::VERTICAL);
	//
	
	addChild(scrollView, 0, 100);
	

}


void TDDHelperTest::testMenuItemFont()
{
	int numCol = 3;
	int count = 100;
	Menu *menu = createMenuWithFont(count, "GillSans", 20, Color3B::YELLOW);

	menu->setPosition(Point(50, 50));
	
	int width = 500;

	TDDHelper::alignMenuItem(menu, width, numCol);
	
	addChild(menu, 0, 100);
	
	
}



void TDDHelperTest::testColor()
{
	LayerColor *layer;
	float width = 100;
	float height = 100;
	float x = 5;
	float y = 50;
	
	const int numColor = 5;
	Color3B colors[numColor] = {
		TDD_COLOR_BLACK,
		TDD_COLOR_WHITE,
		TDD_COLOR_BLUE1,
		TDD_COLOR_BLUE2,
		TDD_COLOR_GREEN1,
	};
	
	// layer = LayerColor::create
	
	for(int i=0; i<numColor; i++) {
		Color3B color3B = colors[i];
		Color4B color = Color4B(color3B);
		
		layer = LayerColor::create(color, width, height);
		layer->setPosition(x, y);
		addChild(layer);
		
		x += width;
	}
}


void TDDHelperTest::testTrimString()
{
	const char *input = " text with space ";
	
	std::string result = TDDHelper::trimString(input);

	log("input=[%s]", input);
	log("result=[%s]", result.c_str());
}

void TDDHelperTest::testReplaceString()
{
	std::string input = "HelloTest";
	
	std::string result = TDDHelper::replaceString(input, "Test", "");
	
	log("input=[%s]", input.c_str());
	log("result=[%s]", result.c_str());
}

void TDDHelperTest::testCreateLabel()
{
	int startSize = 20;
	int endSize = 50;
	int step = 5;
	int spacing = 50;
	
	Point pos = Point(200, 30);
	
	for(int fontSize=startSize; fontSize <= endSize; fontSize +=step) {
		Label *label = TDDHelper::createLabel("Testing", fontSize, Color3B::WHITE);
		
		label->setPosition(pos);
		
		addChild(label);
		
		pos.y += spacing;
	}
}

void TDDHelperTest::testSplitString()
{
	std::vector<std::string> result = TDDHelper::splitString("aaa\nbbb\nccc\n", '\n', 0);
	
	for(int i=0; i<result.size(); i++) {
		log("i=%d str=%s", i, result[i].c_str());
	}
}

void TDDHelperTest::testJoinString()
{
	std::vector<std::string> strArray;
	
	strArray.push_back("Hello");
	strArray.push_back("ABC");
	strArray.push_back("Cat");
	
	std::string result = TDDHelper::joinString(strArray, " ");
	
	log("result=[%s]\n", result.c_str());
//	stt
	
}

void TDDHelperTest::testAddButtonWithBg()
{
	TDDHelper::addButtonWithBackground(this, Vec2(200, 200),
									   Size(80, 60),
									   "Click Me", Color3B::WHITE, Color4B::BLUE);
}

void TDDHelperTest::testResolveAlign()
{
	TDDAlign align = eTDDTopLeft;
	
	std::string name = TDDHelper::getAlignName(align);
	
	log("align=%d name=%s", align, name.c_str());
}

void TDDHelperTest::testAlignNode()
{
	static int index = 0;
	
	TDDAlign selectedAlign = mAlignList[index];
	
	LayerColor *testBox = LayerColor::create(Color4B::RED, 100, 70);
	
	addChild(testBox);

	TDDHelper::alignNode(testBox, Director::getInstance()->getVisibleSize(), selectedAlign);

	// next index
	index = (index + 1) % mAlignList.size();
}

void TDDHelperTest::testFormat()
{
//	std::string
	std::string result = TDDHelper::format("value=%d string=%s", 12345, "hello!!!");
	
	logConsole(result.c_str());
}


#endif
