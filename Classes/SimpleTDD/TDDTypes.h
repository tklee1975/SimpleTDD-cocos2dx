//
//  TDDTypes.h
//  TDDLib
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef TDDLib_TDDTypes_h
#define TDDLib_TDDTypes_h

// C++ includes
#include <map>
#include <functional>
#include <string>

// TDD includes


enum TDDAlign
{
	eTDDTop				= 1,
	eTDDMiddle			= 2,
	eTDDBottom			= 3,

	eTDDLeft			= 1 << 2,
	eTDDCenter			= 2 << 2,
	eTDDRight			= 3 << 2,

	
	// Combined
//	eTDDTopLeft,
//	eTDDTopRight,
//	eTDDBottomLeft,
//	eTDDBottomRight,
};

enum TDDMenuMode {
	TDDMenuModeAll = 0,
	TDDMenuModeHistory = 1,
};


//#define kDefaultFont				"Arial"
//#define kDefaultFontSize			20
#define kDefaultToolbarHeight		44
#define kDefaultMenuRowHeight		35

#endif
