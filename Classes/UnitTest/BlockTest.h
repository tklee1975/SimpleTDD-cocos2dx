#ifdef ENABLE_TDD
//
//  BlockTest.h
//
//
#ifndef __TDD_BlockTest__
#define __TDD_BlockTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class BlockTest : public TDDTest
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
