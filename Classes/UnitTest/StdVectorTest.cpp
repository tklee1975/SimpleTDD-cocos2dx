#ifdef ENABLE_TDD
//
//  StdVectorTest.m
//	TDD Framework 
//
//
#include "StdVectorTest.h"
#include "TDDHelper.h"
#include <vector>

void StdVectorTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void StdVectorTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void StdVectorTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(StdVectorTest::testErase);
}

#pragma mark -
#pragma mark Sub Test Definition
void StdVectorTest::testErase(Ref *sender)
{
	log("this is a sample subTest");
	
	std::vector<int> array;
	
	array.push_back(1);
	array.push_back(2);
	array.push_back(1);
	array.push_back(3);
	array.push_back(1);
	array.push_back(5);
	array.push_back(1);
	
	// Do the erase
	// http://forums.codeguru.com/showthread.php?475058-RESOLVED-what-is-wrong-with-this-vector-lt-int-gt-code
	vector<int>::iterator it;
	for(it = array.begin(); it != array.end(); )
	{
		if(*it == 1) {
			array.erase(it);
		} else {
			it++;
		}
	}
	
	//
	for(int i=0; i<array.size(); i++) {
		printf("%d: %d\n", i, array[i]);
	}
	printf("\n");
}


#endif
