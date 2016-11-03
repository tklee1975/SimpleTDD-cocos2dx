#ifdef ENABLE_TDD
//
//  PositionTest.h
//
//
#ifndef __TDD_PositionTest__
#define __TDD_PositionTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration
class PositionTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test

private:
	void showNodeInfo(Node *node, const std::string &name);
	
private:
	void testSample();
};

#endif

#endif
