#ifdef ENABLE_TDD
//
//  TDDMainLayerTest.h
//
//
#ifndef __TDD_TDDMainLayerTest__
#define __TDD_TDDMainLayerTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class TDDMainLayerTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testCreate();
	void testScene();
}; 

#endif

#endif
