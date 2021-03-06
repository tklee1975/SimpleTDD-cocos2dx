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
	: mItemCount(10)
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

	virtual Node *tableCellForIndex(int index)
	{
		return Label::createWithSystemFont(StringUtils::format("cell%d", index), "", 30);
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

void TDDTableTest::defineTests()
{
	ADD_TEST(setupTable);
	ADD_TEST(testMoreHeight);
	ADD_TEST(testResize);
	ADD_TEST(increaseItem);
	ADD_TEST(decreaseItem);
	ADD_TEST(testTableStyle);
}

#pragma mark -
#pragma mark Sub Test Definition
void TDDTableTest::setupTable()
{
	log("this is a sample subTest");
	
	MyTableDelegate *delegate = new MyTableDelegate();
	
	TDDTable *table = TDDTable::create(Size(400, 300));
	table->setDelegate(delegate);
	//delegate->release();
	
	table->refresh();
	
	addChild(table);
	
	// Store the value
	mTable = table;
	mTableDelegate = delegate;
}

void TDDTableTest::increaseItem()
{
	if(mTableDelegate == nullptr) {
		log("Table not yet setup");
		return;
	}
	
	MyTableDelegate *delegate = (MyTableDelegate *) mTableDelegate;
	delegate->setItemCount(100);
	
	mTable->refresh();
}

void TDDTableTest::decreaseItem()
{
	MyTableDelegate *delegate = (MyTableDelegate *) mTableDelegate;
	delegate->setItemCount(10);
	
	mTable->refresh();
}


void TDDTableTest::testTableStyle()
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
	
	table->refresh();
	
	addChild(table);
	
	// Store the value
	mTable = table;
	mTableDelegate = delegate;
}

void TDDTableTest::testMoreHeight()
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
	
	table->refresh();
	
	addChild(table);
	
	// Store the value
	mTable = table;
	mTableDelegate = delegate;
}

void TDDTableTest::testResize()
{
	if(! mTable) {
		log("Please add a table first");
		return;
	}
	
	
	
	const int nSize = 3;
	Size sizeList[nSize] = {
		Size(300, 300),
		Size(200, 200),
		Size(400, 150),
	};
	
	static int index = 0;
	
	
	Size selectedSize = sizeList[index];
	
	// Change Size
	if(mTable) {
		mTable->resizeTo(selectedSize);
		
	}
	
	
	// next index
	index = (index + 1) % nSize;
	
}

#endif
