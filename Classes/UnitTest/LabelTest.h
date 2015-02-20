#ifdef ENABLE_TDD
//
//  LabelTest.h
//
//
#ifndef __TDD_LabelTest__
#define __TDD_LabelTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class LabelTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testTTF(Ref *sender);
	void testDefaultFont(Ref *sender);
	void testOutlineBug(Ref *sender);
}; 

#endif

#endif
