#ifdef ENABLE_TDD
//
//  TDDTableTest.h
//
//
#ifndef __TDD_TDDTableTest__
#define __TDD_TDDTableTest__

// Include Header

#include "TDDTest.h"

class TDDTable;
class TDDTableDelegate;

// Class Declaration 
class TDDTableTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void setupTable(Ref *sender);
	void increaseItem(Ref *sender);
	void decreaseItem(Ref *sender);
	void testTableStyle(Ref *sender);
	
private:
	TDDTable *mTable;
	TDDTableDelegate *mTableDelegate;
}; 

#endif

#endif
