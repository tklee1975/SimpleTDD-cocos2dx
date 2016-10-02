#ifdef ENABLE_TDD
//
//  TDDUIHelperTest.m
//	TDD Framework
//
//
#include "TDDUIHelperTest.h"
#include "TDDHelper.h"
#include "TDDUIHelper.h"

//
namespace {
	Vector<Node *> createButtonList(Node *parent, int count, const Size &size)
	{
		Vector<Node *> nodeList;
		
		for(int i=0; i<count; i++) {
			std::string title = StringUtils::format("Button %d", i);
			
			ui::Button *button = ui::Button::create();
			button->setTitleText(title);
			button->setContentSize(size);
			button->setTitleColor(Color3B::RED);
			button->setTitleFontSize(15);
			
			parent->addChild(button);
			
			nodeList.pushBack(button);
		}
		
		return nodeList;
	}
}


///
void TDDUIHelperTest::setUp()
{
	log("TDD Setup is called");
	setConsoleVisible(false);
}


void TDDUIHelperTest::tearDown()
{
	log("TDD tearDown is called");
}

void TDDUIHelperTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
	clearNodes();
}

void TDDUIHelperTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void TDDUIHelperTest::defineTests()
{
	ADD_TEST(testPlaceNodes);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDUIHelperTest::testPlaceNodes()
{
	LayerColor *panel = LayerColor::create(Color4B::GREEN, 300, 300);
	addChild(panel);
	
	// Create List of Nodes
	Vector<Node *> nodeList = createButtonList(panel, 3, Size(60, 40));

	//
	TDDUIHelper::placeNodes(panel, nodeList, eDirHorizontal, eTDDTopLeft, 10, 20);
}


#endif
