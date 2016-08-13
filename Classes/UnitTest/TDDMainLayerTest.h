#ifdef ENABLE_TDD
//
//  TDDMainLayerTest.h
//
//
#ifndef __TDD_TDDMainLayerTest__
#define __TDD_TDDMainLayerTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TDDMainLayerTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testCreate(Ref *sender);
}; 

#endif

#endif
