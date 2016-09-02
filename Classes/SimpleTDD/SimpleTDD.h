//
//  SimpleTDD.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 19/8/2016.
//
//

#ifndef SimpleTDD_hpp
#define SimpleTDD_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class SimpleTDD
{
public:
	static void setup(Node *parent, const Vec2 &pos,
						const Color4B &bgColor = Color4B(50, 50, 200, 255),
						const Color3B &textColor = Color3B::WHITE ,
						int fontSize = 15);
};


#endif /* SimpleTDD_hpp */
