//
//  TDDHelper.h
//  TDDLib
//
//  Created by Ken Lee on 13/12/13.
//
//

#ifndef __TDDLib__TDDHelper__
#define __TDDLib__TDDHelper__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "TDDTypes.h"
#include <string>
#include <vector>

#define kButtonUp		1
#define kButtonDown		2
#define kButtonLeft		3
#define kButtonRight	4

USING_NS_CC;
USING_NS_CC_EXT;

using namespace std;

class TDDHelper
{
public:
	static void addTestButton(Node *parent, cocos2d::Point pos);

	
	static std::string getVersion();
	static std::string getLibraryName();
	
	static Size getScreenSize();
	static Point getAlignPoint(float x, float y, TDDAlign halign, TDDAlign valign);
	
	static void showTests();
	static Menu *createMenu(cocos2d::Point pos, const char *name, const ccMenuCallback& callback);
	static MenuItem *createMenuItem(const char *name, const ccMenuCallback& callback);
	static void scrollToTop(ScrollView *scrollView);
	static Point getCenter(Size &parentSize, Size &nodeSize);
	static EditBox *createEditBox(Node *parent, Point position, Size size);
	static void saveFilter(const char *pattern);
	static const char *getFilter();
	static const Size alignMenuItem(Menu *menu, int parentWidth,
						int numCol=3, int lineSpace=0);
	static MenuItem *createMenuItemWithFont(const char *name, const char *font, const ccMenuCallback& callback);
	static MenuItem *createMenuItemWithFont(const char *name,
												const char *font,
												Color3B color,
												const ccMenuCallback& callback);
	static void setLabelColor(Label *label, const Color3B &textColor);
	
	static void setAlphaPremultiplied(Node *node);

	static std::string trimString(const std::string &input);
	
	static std::string replaceString(const std::string &src,
										 const std::string &find,
										 const std::string &replacement);
	
	static std::vector<std::string> splitString(const std::string& text,
										   const char delim, const int numToken);
	
	static std::string joinString(const std::vector<std::string> &strArray,
											const std::string &sep);
	
	static Label *createLabel(const std::string &text,
								const int fontSize, const Color3B &color);
	// static Layer *createKeyPadLayer(Object *target, Control::Handler handler);

	static bool isLandscape();
	static float getBestScale();
	
	#pragma mark - Save/Load Data
	static void saveStringToDevice(const std::string &key, const std::string &content);
	static std::string loadStringFromDevice(const std::string &key);
};

#endif /* defined(__Dg__TDDHelper__) */
