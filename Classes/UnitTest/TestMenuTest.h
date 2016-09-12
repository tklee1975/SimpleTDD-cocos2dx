#ifdef ENABLE_TDD
//
//  TestMenuTest.h
//
//
#ifndef __TDD_TestMenuTest__
#define __TDD_TestMenuTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class TestMenuTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSample();
	void testHeaderColor();
	void testChangeSize();
};

#endif

#endif
