#ifdef ENABLE_TDD
//
//  TDDHeaderLayerTest.h
//
//
#ifndef __TDD_TDDHeaderLayerTest__
#define __TDD_TDDHeaderLayerTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDTopBarTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testCallback(Ref *sender);
}; 

#endif

#endif
