#ifdef ENABLE_TDD
//
//  TDDSuiteLayerTest.h
//
//
#ifndef __TDD_TDDSuiteLayerTest__
#define __TDD_TDDSuiteLayerTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDSuiteLayerTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
}; 

#endif

#endif
