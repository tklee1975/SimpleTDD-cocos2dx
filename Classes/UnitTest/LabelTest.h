#ifdef ENABLE_TDD
//
//  LabelTest.h
//
//
#ifndef __TDD_LabelTest__
#define __TDD_LabelTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class LabelTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void testTTF();
	void testDefaultFont();
	void testOutlineBug();
}; 

#endif

#endif
