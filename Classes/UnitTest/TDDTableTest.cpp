#ifdef ENABLE_TDD
//
//  TDDTableTest.m
//	TDD Framework 
//
//
#include "TDDTableTest.h"
#include "TDDHelper.h"
#include "TDDTable.h"

class MyTableDelegate : public TDDTableDelegate
{
public:
	CC_SYNTHESIZE(int, mItemCount, ItemCount);
	
	MyTableDelegate()
	: mItemCount(40)
	{
		
	}
	
	virtual int getTableCellCount()
	{
		return mItemCount;
	}
	
	virtual Size getTableCellSize()
	{
		return Size(100, 30);
	}
		
	virtual void onTableCellClicked(int selectedIndex)
	{
		log("tableCellClicked: %d", selectedIndex);
	}
};

void TDDTableTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	mTable = nullptr;
}


void TDDTableTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TDDTableTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TDDTableTest::setupTable);
	SUBTEST(TDDTableTest::increaseItem);
	SUBTEST(TDDTableTest::decreaseItem);
	SUBTEST(TDDTableTest::testTableStyle);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDTableTest::setupTable(Ref *sender)
{
	log("this is a sample subTest");
	
	MyTableDelegate *delegate = new MyTableDelegate();
	
	TDDTable *table = TDDTable::create(Size(400, 300));
	table->setDelegate(delegate);
	//delegate->release();
	
	table->updateData();
	
	addChild(table);
	
	// Store the value
	mTable = table;
	mTableDelegate = delegate;
}

void TDDTableTest::increaseItem(Ref *sender)
{
	MyTableDelegate *delegate = (MyTableDelegate *) mTableDelegate;
	delegate->setItemCount(100);
	
	mTable->updateData();
}

void TDDTableTest::decreaseItem(Ref *sender)
{
	MyTableDelegate *delegate = (MyTableDelegate *) mTableDelegate;
	delegate->setItemCount(10);
	
	mTable->updateData();
}


void TDDTableTest::testTableStyle(Ref *sender)
{
	log("this is a sample subTest");
	
	MyTableDelegate *delegate = new MyTableDelegate();
	
	TDDTable *table = TDDTable::create(Size(400, 300));
	table->setColumn(5);
	table->setTitleColor(Color3B(49,166,148));
	table->setBackgroundColor(Color4B(250,219,191,255));
	table->setFontSize(12);
	
	
	table->setDelegate(delegate);
	//delegate->release();
	
	table->updateData();
	
	addChild(table);
	
	// Store the value
	mTable = table;
	mTableDelegate = delegate;
}

#endif
