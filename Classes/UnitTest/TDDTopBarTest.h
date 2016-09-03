#ifdef ENABLE_TDD
//
//  TDDHeaderLayerTest.h
//
//
#ifndef __TDD_TDDHeaderLayerTest__
#define __TDD_TDDHeaderLayerTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class TDDTopBarTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void subTest();
	void testCallback();
}; 

#endif

#endif
