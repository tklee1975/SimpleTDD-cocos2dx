#ifdef ENABLE_TDD
//
//  TDDTableTest.h
//
//
#ifndef __TDD_TDDTableTest__
#define __TDD_TDDTableTest__

// Include Header

#include "TDDBaseTest.h"

class TDDTable;
class TDDTableDelegate;

// Class Declaration 
class TDDTableTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
private:
	void setupTable();
	void increaseItem();
	void decreaseItem();
	void testTableStyle();
	
private:
	TDDTable *mTable;
	TDDTableDelegate *mTableDelegate;
}; 

#endif

#endif
