#ifdef ENABLE_TDD
//
//  TDDDataTest.h
//
//
#ifndef __TDD_TDDDataTest__
#define __TDD_TDDDataTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDDataTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testAddTest(Ref *sender);
	void testLoad(Ref *sender);
	void testSave(Ref *sender);
	void testClearHistory(Ref *sender);
}; 

#endif

#endif
