#ifdef ENABLE_TDD
//
//  TDDAssertTest.h
//
//
#ifndef __TDD_TDDAssertTest__
#define __TDD_TDDAssertTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class TDDAssertTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testAssertEqual();
	void testAssertTrue();
};

#endif

#endif
