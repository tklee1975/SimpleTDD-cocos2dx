//
//  TDDTestMenu.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 20/8/2016.
//
//

#include "TDDTestMenu.h"
TDDTestMenu::TDDTestMenu()
: mTestNameList()
, mTestSelectedCallback(nullptr)
{
	
}

bool TDDTestMenu::init()
{
	bool flag = LayerColor::initWithColor(Color4B::BLUE, 200, 200);
	if(flag == false) {
		return false;
	}
//	setContentSize(Size(200, 200));
//	setColor(Color3B::YELLOW);
	
	// setBackGroundColor(Color3B::YELLOW);
	
	Size tableSize = Size(200, 160);
	
	// Add the Table
	TDDTable *table = TDDTable::create(tableSize);
	table->setColumn(1);
	table->setTitleColor(Color3B(0,0,148));
	table->setBackgroundColor(Color4B(0,0,0,0));
	table->setFontSize(12);
	table->setDelegate(this);
	//delegate->release();
	
	table->updateData();
	
	addChild(table);
	mTestTable = table;
	
	return true;
}

//void TDDTestMenu::addTest(const std::string &name, const TestCallback &callback)
//{
//	mTestNameList.push_back(name);
//	mTestCallbackMap[name] = callback;
//}

void TDDTestMenu::setTests(std::vector<std::string> &testList)
{
	mTestNameList.clear();
	for(int i=0; i<testList.size(); i++) {
		mTestNameList.push_back(testList[i]);
	}
	
	mTestTable->updateData();
}


#pragma mark - TDDTableDelegate
int TDDTestMenu::getTableCellCount()
{
	return (int) mTestNameList.size();
}

Size TDDTestMenu::getTableCellSize()
{
	float width = getContentSize().width;
	
	return Size(width, 40);
}

Node *TDDTestMenu::tableCellForIndex(int index)
{
	std::string name = getTestName(index);
	
	
	
	ui::Button *button = ui::Button::create();
	//button->setColor(Color3B::YELLOW);		// this is no use
	button->setTitleText(name);
	button->setContentSize(getTableCellSize());
	button->setTitleColor(Color3B::WHITE);
	button->setTitleFontSize(15);
	
	button->addClickEventListener([&, name](Ref *) {
		if(mTestSelectedCallback) {
			mTestSelectedCallback(name);
		}
	});
	
	return button;
	
}
//
//void TDDTestMenu::doTestCallback(const std::string &name)
//{
////	TestCallback callback = mTestCallbackMap[name];
////	if(callback == nullptr) {
////		log("doTestCallback: callback is null. name=%s", name.c_str());
////		return;
////	}
////	
////	callback();
//}

std::string TDDTestMenu::getTestName(int index)
{
	if(index < 0 || index >= mTestNameList.size()) {
		return "";
	}
	
	return mTestNameList[index];
}

void TDDTestMenu::refreshMenu()
{
	if(mTestTable) {
		mTestTable->updateData();
	}
	
}

void TDDTestMenu::setTestSelectedCallback(const TestSelectedCallback &callback)
{
	mTestSelectedCallback = callback;
}