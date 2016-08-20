//
//  TDDTestMenu.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 20/8/2016.
//
//

#ifndef TDDTestMenu_hpp
#define TDDTestMenu_hpp

#include <stdio.h>

#include <stdio.h>
#include <string>
#include <vector>
#include <map>

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;
USING_NS_CC_EXT;

#include "TDDTable.h"

class TDDTestMenu : public LayerColor, public TDDTableDelegate
{
public:
	typedef std::function<void(const std::string &name)> TestSelectedCallback;
	typedef std::function<void()> TestCallback;
public:
	CREATE_FUNC(TDDTestMenu);
	
	TDDTestMenu();
	
	bool init();
	
//	void addTest(const std::string &name, const TestCallback &callback);
	void setTests(std::vector<std::string> &testList);
	
	void refreshMenu();
	
	void setTestSelectedCallback(const TestSelectedCallback &callback);
	// void runTest(const std::string &)
	
#pragma mark - TDDTableDelegate
private:
	virtual int getTableCellCount();
	virtual Size getTableCellSize();
	virtual Node *tableCellForIndex(int index);

private:
	std::string getTestName(int index);
//	void doTestCallback(const std::string &name);
	
private:
	std::vector<std::string> mTestNameList;
//	std::map<std::string, TestCallback> mTestCallbackMap;
	
	TDDTable *mTestTable;
	
	TestSelectedCallback mTestSelectedCallback;
};


#endif /* TDDTestMenu_hpp */
