#ifdef ENABLE_TDD
//
//  TDDUIHelperTest.h
//
//
#ifndef __TDD_TDDUIHelperTest__
#define __TDD_TDDUIHelperTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class TDDUIHelperTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testPlaceNodes();
};

#endif

#endif
