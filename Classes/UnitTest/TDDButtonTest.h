#ifdef ENABLE_TDD
//
//  TDDButtonTest.h
//
//
#ifndef __TDD_TDDButtonTest__
#define __TDD_TDDButtonTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class TDDButtonTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSample();
	void testVariousStyle();
	void testButtonChange();
};

#endif

#endif
