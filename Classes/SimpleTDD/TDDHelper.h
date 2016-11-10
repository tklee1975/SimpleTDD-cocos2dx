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
#include "ui/CocosGUI.h"
#include "TDDTypes.h"
#include <string>
#include <vector>
#include "TDDButton.h"

#define kButtonUp		1
#define kButtonDown		2
#define kButtonLeft		3
#define kButtonRight	4

USING_NS_CC;

using namespace std;

class TDDButton;

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
	static void scrollToTop(cocos2d::extension::ScrollView *scrollView);
	static Point getCenter(Size &parentSize, Size &nodeSize);
	
	static ui::EditBox *createEditBox(Node *parent, Point position, Size size);
	
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

	
#pragma mark - Helper for String
	
// Macro Function
#define TDD_SIZE_TO_STR(_size_)	StringUtils::format("(%f,%f)", _size_.width, _size_.height)
#define TDD_VEC2_TO_STR(_v2_)	StringUtils::format("(%f,%f)", _v2_.x, _v2_.y)
	static std::string format(const char * format, ...);
	static std::string formatVAList(const char *format, va_list args);
	
#pragma mark - helping node 
	static void addAnchorPoint(Node *node, const Color4B &color = Color4B(255, 0, 0, 200));
	static void addBoundingBox(Node *node, const Color4B &color = Color4B(255, 0, 0, 200));
	
#pragma mark - Save/Load Data
	static void saveStringToDevice(const std::string &key, const std::string &content);
	static std::string loadStringFromDevice(const std::string &key);


#pragma mark - New UI Helper
	static ui::EditBox *createEditBox(const Size &size,
									  const Color4B &bgColor, const Color3B &textColor,
									  const std::string &fontName, float fontSize);
	
	
	static ui::Button *addButtonWithBackground(Node *parent,
											   const Vec2 &pos,
											   const Size &size,
											   const std::string &title,
											   const Color3B &titleColor,
											   const Color4B &bgColor);


	static void alignNode(Node *targetNode, TDDAlign align);
	static void alignNode(Node *targetNode, const Size &parentSize, TDDAlign align);

	static void resolveAlign(TDDAlign align, TDDAlign &verticalAlign, TDDAlign &horizontalAlign);
	
	static std::string getAlignName(TDDAlign align);
	
	static std::vector<TDDAlign> getAlignList();
	
	
	static TDDButton *addTDDButton(Node *parent,
								   const Vec2 &pos,
								   const Size &size,
								   const std::string &title,
								   const Color3B &titleColor,
								   const Color4B &bgColor,
								   const float titleSize=12.0f);

	static void showToastAlert(const std::string &title, const Vec2 &pos, Node *parent = nullptr);
	
	
};

#endif /* defined(__Dg__TDDHelper__) */
