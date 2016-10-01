#ifdef ENABLE_TDD
//
//  TDDConsoleViewTest.h
//
//
#ifndef __TDD_TDDConsoleViewTest__
#define __TDD_TDDConsoleViewTest__

// Include Header

#include "TDDBaseTest.h"

class TDDConsoleView;

// Class Declaration
class TDDConsoleViewTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSample();
	void testClear();
	void testAppend();
	void testAppend2();
	void testAppendFormat();
private:
	TDDConsoleView *mConsoleView;
};

#endif

#endif
