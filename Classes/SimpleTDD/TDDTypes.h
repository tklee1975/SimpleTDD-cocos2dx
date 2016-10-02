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


typedef enum
{
	eTDDTop				= 1,		
	eTDDMiddle			= 2,
	eTDDBottom			= 3,

	eTDDLeft			= 1 << 2,		
	eTDDCenter			= 2 << 2,
	eTDDRight			= 3 << 2,

	eTDDTopLeft			= (eTDDTop | eTDDLeft),
	eTDDTopCenter		= (eTDDTop | eTDDCenter),
	eTDDTopRight		= (eTDDTop | eTDDRight),

	eTDDMidLeft			= (eTDDMiddle | eTDDLeft),
	eTDDMidCenter		= (eTDDMiddle | eTDDCenter),
	eTDDMidRight		= (eTDDMiddle | eTDDRight),

	eTDDBottomLeft		= (eTDDBottom | eTDDLeft),
	eTDDBottomCenter	= (eTDDBottom | eTDDCenter),
	eTDDBottomRight		= (eTDDBottom | eTDDRight),
	
	// Combined
//	eTDDTopLeft,
//	eTDDTopRight,
//	eTDDBottomLeft,
//	eTDDBottomRight,
} TDDAlign;

typedef enum
{
	eDirVertical		= 1,
	eDirHorizontal		= 2,
	eDirUnknown			= 3,
} TDDDirection;

//enum TDDMenuMode {
//	TDDMenuModeAll = 0,
//	TDDMenuModeHistory = 1,
//};

typedef enum {
	TDDSearchAll,
	TDDSearchRecent,
}TDDSearchType ;


//#define kDefaultFont				"Arial"
//#define kDefaultFontSize			20
#define kDefaultToolbarHeight		44
#define kDefaultMenuRowHeight		35

#endif
