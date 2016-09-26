#ifdef ENABLE_TDD
//
//  UITextTest.h
//
//
#ifndef __TDD_UITextTest__
#define __TDD_UITextTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class UITextTest : public TDDBaseTest
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
