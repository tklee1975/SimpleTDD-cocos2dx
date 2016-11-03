#ifdef ENABLE_TDD
//
//  PositionTest.m
//	TDD Framework
//
//
#include "PositionTest.h"
#include "TDDHelper.h"

#define POS_STR(p)		(StringUtils::format("%f,%f", p.x, p.y))

void PositionTest::setUp()
{
	log("TDD Setup is called");
}


void PositionTest::tearDown()
{
	log("TDD tearDown is called");
}

void PositionTest::willRunTest(const std::string &name)
{
	log("Before run %s", name.c_str());
}

void PositionTest::didRunTest(const std::string &name)
{
	log("After run %s", name.c_str());
}


#pragma mark -
#pragma mark List of Sub Tests

void PositionTest::defineTests()
{
	ADD_TEST(testSample);
}

#pragma mark -
#pragma mark Helper 
void PositionTest::showNodeInfo(Node *node, const std::string &name)
{
	Vec2 pos;
	
	Node *parent = node->getParent();
	
	pos = node->getPosition();
	log("%s: position=%s", name.c_str(), POS_STR(pos).c_str());
	
	pos = parent->convertToWorldSpace(node->getPosition());
	log("%s: worldSpace=%s", name.c_str(), POS_STR(pos).c_str());
	
	pos = parent->convertToWorldSpaceAR(node->getPosition());
	log("%s: worldSpaceARs=%s", name.c_str(), POS_STR(pos).c_str());
	
	
}


#pragma mark -
#pragma mark Sub Test Definition
void PositionTest::testSample()
{
	log("this is a sample subTest");
	
	setAnchorPoint(Vec2(0, 0));		// this will affect the worldSpaceAR result
	
	
	LayerColor *layer1 = LayerColor::create(Color4B::RED, 200, 200);
	layer1->setPosition(Vec2(50, 50));
	addChild(layer1);
	showNodeInfo(layer1, "layer1");

	LayerColor *layer2 = LayerColor::create(Color4B::BLUE, 100, 100);
	layer2->setPosition(Vec2(40, 40));
	layer1->addChild(layer2);
	showNodeInfo(layer2, "layer2");

	LayerColor *layer3 = LayerColor::create(Color4B::YELLOW, 50, 50);
	layer3->setPosition(Vec2(30, 30));
	layer2->addChild(layer3);
	showNodeInfo(layer3, "laye3");

}


#endif
