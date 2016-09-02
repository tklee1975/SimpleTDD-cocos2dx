#ifdef ENABLE_TDD
//
//  TDDTestMenuTest.h
//
//
#ifndef __TDD_TDDTestMenuTest__
#define __TDD_TDDTestMenuTest__

// Include Header

#include "TDDBaseTest.h"

class TDDTestMenu;

// Class Declaration 
class TDDTestMenuTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();

	
private:
	void addSubTest(const std::string &name, const std::function<void()> &callback);
	void doTestCallback(const std::string &name);
	
	
private:
	void test1();
	void test2();
	void toggle();
	
private:
	void subTest();
	void testTheme();
	void testSetColumn();
	void testSetSize();
	
private:
	std::vector<std::string> mTestNameList;
	std::map<std::string, std::function<void()>> mTestCallbackMap;
	
	TDDTestMenu *mTestMenu;
}; 

#endif

#endif
