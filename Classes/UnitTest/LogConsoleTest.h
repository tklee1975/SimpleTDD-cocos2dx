#ifdef ENABLE_TDD
//
//  LogConsoleTest.h
//
//
#ifndef __TDD_LogConsoleTest__
#define __TDD_LogConsoleTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class LogConsoleTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSample();
};

#endif

#endif
