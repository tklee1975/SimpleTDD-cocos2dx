//
//  TDDUIHelper.cpp
//  SimpleTDD
//
//  Created by Ken Lee on 3/10/2016.
//
//

#include "TDDUIHelper.h"

namespace  {
	std::string nameOfAlign(TDDAlign align)		// just top/mid/bot lef/cent/right
	{
		switch(align) {
			case eTDDTop	: return "top";
			case eTDDMiddle	: return "middle";
			case eTDDBottom	: return "bottom";
			case eTDDLeft	: return "left";
			case eTDDCenter	: return "center";
			case eTDDRight	: return "right";
				
			default			: return "";
		}
	}
	
	void fineTunePositon(Vec2 &pos, const TDDAlign &vert, const TDDAlign &hori, const float &margin)
	{
		// Modify the vertically position
		switch (vert) {
			case eTDDTop		: { pos += Vec2(0, -margin); break; }
			case eTDDBottom		: { pos += Vec2(0, margin); break; }
			default: break;
		}
		
		// Modify the horizontal position
		switch (hori) {
			case eTDDLeft		: { pos += Vec2(margin, 0); break; }
			case eTDDRight		: { pos += Vec2(-margin, 0); break;  }
			default: break;
		}
		
		
	}
}





TDDDirection TDDUIHelper::getAlignDir(const TDDAlign &align)
{
	switch(align) {
		case eTDDTop:
		case eTDDMiddle:
		case eTDDBottom:
			return eDirVertical;
			
		case eTDDLeft:
		case eTDDCenter:
		case eTDDRight:
			return eDirHorizontal;
			
		default:
			return eDirUnknown;
	}
	
}

void TDDUIHelper::placeNodes(Node *parent, const Vector<Node *> &nodeList,
					   const TDDDirection &dir,
					   const TDDAlign &align,
					   const float &margin, const float &spacing)
{
	if(parent == nullptr) {
		log("TDDUIHelper.placeNodes: parent is null");
		return;
	}
	
	if(nodeList.size() == 0) {
		return;
	}
	
	// Place the first node
	alignNode(nodeList.at(0), align);
	
	Vec2 firstPos = nodeList.at(0)->getPosition();
	
	// First the sign for position adjustment
	TDDAlign vert;
	TDDAlign hori;
	resolveAlign(align, vert, hori);
	
	float sign = (eTDDBottom == vert || eTDDRight == hori) ? -1 : 1;		//
	
	// Fine the first position
	log("debug: firstPos(1)=%f,%f", firstPos.x, firstPos.y);
	fineTunePositon(firstPos, vert, hori, margin);
	log("debug: firstPos(2)=%f,%f", firstPos.x, firstPos.y);
	nodeList.at(0)->setPosition(firstPos);
	
	
	// define the last position
	Vec2 lastPos = firstPos;
	Size lastNodeSize = nodeList.at(0)->getContentSize();
	
	// define the diff
	Vec2 diffPos;

	for(int i=1; i<nodeList.size(); i++) {
		// modify the position
		if(dir == eDirHorizontal) {
			diffPos.x = sign * (lastNodeSize.width + spacing);
			diffPos.y = 0;
		} else {	// Vertical
			diffPos.x = 0;
			diffPos.y = sign * (lastNodeSize.height + spacing);
		}
		
		//
		Node *node = nodeList.at(i);
		
		node->setPosition(lastPos + diffPos);
		
		
		log("debug: last=%f,%f diff=%f,%f", lastPos.x, lastPos.y, diffPos.x, diffPos.y);
		// update lastPos & last Size
		lastPos = node->getPosition();
		lastNodeSize = node->getContentSize();
	}
}


void TDDUIHelper::alignNode(Node *targetNode, TDDAlign align)	// support anchorPoint=(0, 0)
{
	if(targetNode == nullptr) {
		return;
	}
	
	Node *nodeParent = targetNode->getParent();
	if(nodeParent == nullptr) {
		return;
	}
	
	return alignNode(targetNode, nodeParent->getContentSize(), align);
}

void TDDUIHelper::alignNode(Node *targetNode, const Size &parentSize, TDDAlign align)
{
	TDDAlign vert;
	TDDAlign hori;
	resolveAlign(align, vert, hori);
	
	
	Vec2 anchorPoint = targetNode->getAnchorPoint();
	log("Anchor Point: %f,%f", anchorPoint.x, anchorPoint.y);
	
	float x, y;
	
	
	Size size = targetNode->getContentSize();
	// Vec2 anchorDiff = targetNode->getAnchorPoint() * Vec2(
	
	// Find x;
	if(eTDDRight == hori) {
		x = parentSize.width - size.width * (1 - anchorPoint.x);
	} else if(eTDDCenter == hori) {
		x = parentSize.width / 2 - size.width  * (0.5 - anchorPoint.x);
	} else {	// Left
		x = size.width  * anchorPoint.x;
	}
	
	
	// Find y;
	if(eTDDTop == vert) {
		y = parentSize.height - size.height * (1 - anchorPoint.y);
	} else if(eTDDMiddle == vert) {
		y = parentSize.height /2 - size.height * (0.5 - anchorPoint.y);
	} else {
		y = size.height * anchorPoint.y;
	}
	
//	log("debug: align=%s", getAlignName(align).c_str());
//	log("debug: targetSize=%f,%f parentSize=%f,%f", size.width, size.height,
//		parentSize.width, parentSize.height);
//	log("debug: x=%f y=%f  hori=%d vert=%d", x, y, hori, vert);
	
	
	// Set position
	targetNode->setPosition(Vec2(x, y));
}


void TDDUIHelper::resolveAlign(TDDAlign align, TDDAlign &verticalAlign, TDDAlign &horizontalAlign)
{
	verticalAlign = (TDDAlign) (align & 0x0003);		// 0011	 (last two bit)
	horizontalAlign = (TDDAlign) (align & 0x000C);		// 1100  (3rd,4th bit)
}

std::string TDDUIHelper::getAlignName(TDDAlign align)
{
	TDDAlign vert;
	TDDAlign hori;
	
	resolveAlign(align, vert, hori);
	
	log("debug: vert=%d hori=%d", vert, hori);
	
	std::string vertialPart = nameOfAlign(vert);
	std::string horizontalPart = nameOfAlign(hori);
	
	std::string sep = (vertialPart.empty() || horizontalPart.empty()) ? "" : "_";
	
	return vertialPart + sep + horizontalPart;
}
