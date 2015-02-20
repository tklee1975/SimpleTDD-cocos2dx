#ifdef ENABLE_TDD
//
//  SampleTest.cpp
//  TDDLib
//
//  Created by Ken Lee on 15/12/13.
//
//

#include "TDDSample.h"
#include "TDDHelper.h"

void TDDSample::setUp()
{
	log("Test is setUp");
	
	Size size = TDDHelper::getScreenSize();
	Point top = Director::getInstance()->convertToGL(Point(0, 50));

	//auto label = LabelTTF::create("Hello World", "Arial", 24);
    

	
	auto label = LabelTTF::create("Sample Code 1", "Arial", 20);
	label->setPosition(Point(size.width/2, top.y - 40));
	addChild(label);

	int centerX = size.width / 2;
	Point pos = Point(centerX, top.y - 50);
	
	int fontsizeArray[] = {20, 30, 40};
	
	for(int i=0; i<3; i++) {
		int fontSize = fontsizeArray[i];
		
		// String *str = String::createWithFormat("Font Size: %d", fontSize);
		char temp[100];
		sprintf(temp, "Font Size: %d", fontSize);
		
		auto label = LabelTTF::create(temp, "Arial", fontSize);
		label->setPosition(pos);
		addChild(label);
		
		pos.y -= fontSize * 1.5;
	}
	
}

void TDDSample::tearDown()
{
	log("Test is tearDown (before onExit)");
}


void TDDSample::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDSample::test1);
	SUBTEST(TDDSample::test2);
	SUBTEST(TDDSample::test3);

}

#pragma mark -
#pragma mark Sub Test Definition
void TDDSample::test1(Ref *sender)
{
	log("hello this is test1");
}

void TDDSample::test2(Ref *sender)
{
	log("hello this is test2");
}


void TDDSample::test3(Ref *sender)
{
	log("hello this is test3");
}

#endif