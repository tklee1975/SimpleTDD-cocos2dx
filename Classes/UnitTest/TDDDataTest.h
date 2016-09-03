#ifdef ENABLE_TDD
//
//  TDDDataTest.h
//
//
#ifndef __TDD_TDDDataTest__
#define __TDD_TDDDataTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class TDDDataTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testAddTest();
	void testLoad();
	void testSave();
	void testClearHistory();
}; 

#endif

#endif
