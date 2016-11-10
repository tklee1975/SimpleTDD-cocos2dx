//
//  TDDUIHelper.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 3/10/2016.
//
//

#ifndef TDDUIHelper_hpp
#define TDDUIHelper_hpp

#include <stdio.h>


#include "cocos2d.h"
#include "TDDTypes.h"
#include <string>
#include <vector>

USING_NS_CC;

using namespace std;

class TDDUIHelper
{
public:
	static TDDDirection getAlignDir(const TDDAlign &align);
	static void placeNodes(Node *parent, const Vector<Node *> &nodeList,
						   const TDDDirection &dir,
				const TDDAlign &align,
				const float &margin, const float &spacing);


#pragma mark Alignment Stuff
public:
	static void alignNode(Node *targetNode, TDDAlign align);
	static void alignNode(Node *targetNode, const Size &parentSize, TDDAlign align);
	
	static void resolveAlign(TDDAlign align, TDDAlign &verticalAlign, TDDAlign &horizontalAlign);
	
	static std::string getAlignName(TDDAlign align);
	
	static std::vector<TDDAlign> getAlignList();

};

#endif /* TDDUIHelper_hpp */
