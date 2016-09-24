#ifdef ENABLE_TDD
//
//  StdStringTest.h
//
//
#ifndef __TDD_StdStringTest__
#define __TDD_StdStringTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class StdStringTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void test_rfind();
};

#endif

#endif
