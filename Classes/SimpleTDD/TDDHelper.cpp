//
//  TDDHelper.cpp
//  TDDLib
//
//  Created by Ken Lee on 13/12/13.
//
//

#include "TDDHelper.h"
#include "TDDSuite.h"
#include "TDDConstant.h"

//#include "GUIHelper.h"

#define kLibName			"TDDLib+cocos2dx"
#define kLibVersion			"0.1"


#ifdef ENABLE_TDD
#define HAS_TDD		true
#else
#define HAS_TDD		false
#endif

#define kTDDFilterKey	"tdd.filter.pattern"

#define BEST_WIDTH	800
#define BEST_HEIGHT	480

static std::string sFilterPattern("");

Size TDDHelper::getScreenSize()
{
	auto glView = Director::getInstance()->getOpenGLView();
	return glView->getDesignResolutionSize();
}

Point TDDHelper::getAlignPoint(float x, float y, TDDAlign halign, TDDAlign valign)
{
	Size size = getScreenSize();
	
	// Horizon
	if(halign == eTDDLeft) {
		x = size.width - x;
	} else if (halign == eTDDCenter) {
		x = size.width / 2 + x;
	}
	
	log("getAlignPoint: h=%f w=%f", size.height, size.width);
	
	// Vertical
	if(valign == eTDDTop) {
		y = size.height - y;
	} else if (valign == eTDDMiddle) {
		y = size.height / 2 + y;
	}
	
	 log("getAlignPoint: x=%f y=%f", x, y);
	
	return Point(x, y);
}

void TDDHelper::showTests()
{
#ifdef ENABLE_TDD
	Scene *scene = new TDDSuiteScene();
	
	Director::getInstance()->pushScene(scene);
	
	scene->release();
#endif
}

#pragma mark - GUI Helper

MenuItem *TDDHelper::createMenuItem(const char *name, const ccMenuCallback& callback)
{
	int fontSize = (int)(getBestScale() * TDD_FONT_SIZE1);
	auto label = LabelTTF::create(name, TDD_FONT_NAME, fontSize);
	
	auto menuItem = MenuItemLabel::create(label, callback);
	
	return menuItem;
}

MenuItem *TDDHelper::createMenuItemWithFont(const char *name,
											const char *font,
											Color3B color,
											const ccMenuCallback& callback)
{
//	Label *label = Label::createWithSystemFont(value, _fontName, _fontSize);
//    if (MenuItemLabel::initWithLabel(label, callback))

	
	// LabelTTF *label = LabelTTF::create(name, kDefaultFont, kDefaultFontSize);
	float scale = getBestScale();
	int fontSize = (int)(getBestScale() * TDD_FONT_SIZE1);
	
	Label *label = Label::createWithSystemFont(name, font, fontSize );
	setLabelColor(label, color);
	
	return MenuItemLabel::create(label, callback);

}


MenuItem *TDDHelper::createMenuItemWithFont(const char *name, const char *font,
											const ccMenuCallback& callback)
{
	int fontSize = (int)(getBestScale() * TDD_FONT_SIZE1);
	Label *label = Label::createWithSystemFont(name, font, fontSize);
	setLabelColor(label, TDD_COLOR_BLUE2);
	
	return MenuItemLabel::create(label, callback);
}


Menu *TDDHelper::createMenu(Point pos, const char *name, const ccMenuCallback& callback)
{
	
	auto menuItem = createMenuItemWithFont(name, TDD_FONT_NAME, Color3B::WHITE, callback);
	Menu *menu = Menu::create(menuItem, NULL);
	menu->setPosition(pos);
	
	return menu;
}

void TDDHelper::addTestButton(Node *parent, Point pos)
{
	if(HAS_TDD == false) {
		log("ERROR: TDD Framework is disable!");
		return;
	}
	
	
	if(parent == NULL) {
		log("ERROR: addTestButton: parent is NULL");		// or use Assert
		return;
	}
	
	Menu *menu = createMenu(pos, "Test!", [](Ref *sender) {
												TDDHelper::showTests();
											}
							);
	
	parent->addChild(menu);
}


EditBox * TDDHelper::createEditBox(Node *parent, Point position, Size size)
{
	Scale9Sprite *bg = Scale9Sprite::create();	// empty sprite 9
	bg->addChild(LayerColor::create(Color4B::WHITE, size.width, size.height));
	
	// Add the background layer
	Point layerPos = Point(position);
	layerPos.x -= size.width / 2;
	layerPos.y -= size.height / 2;
	
	float scale = getBestScale();
	
	// Add the Edit box
	EditBox *edit = EditBox::create(size, bg);
	edit->setPosition(position);
	
	edit->setFont(TDD_FONT_NAME, (int)(scale * TDD_EDITBOX_FONT_SIZE));
	edit->setFontColor(TDD_EDITBOX_TEXT_COLOR);
	
	if(parent != NULL) {
		parent->addChild(edit);
	}
	
	return edit;
}


bool TDDHelper::isLandscape()
{
	Size screenSize = getScreenSize();
	
	return screenSize.width > screenSize.height;
}

void TDDHelper::scrollToTop(ScrollView *scrollView)
{
	Size containerSize = scrollView->getContainer()->getContentSize();
	
	Point offset = Point(0, -containerSize.height + scrollView->getViewSize().height);
	
	// log("containerH=%f scrollH=%f", containerSize.height, scrollView->getViewSize().height);
	
	//[scrollView setContentOffset:offset animated:NO];
	scrollView->setContentOffset(offset);
}


Point TDDHelper::getCenter(Size &parentSize, Size &nodeSize)
{
	float x = (parentSize.width - nodeSize.width) / 2;
	float y = (parentSize.height - nodeSize.height) / 2;
	
	return Point(x, y);
}

#pragma mark - User Default
void TDDHelper::saveStringToDevice(const std::string &key, const std::string &content)
{
	CCUserDefault::getInstance()->setStringForKey(key.c_str(), content);
	
	CCUserDefault::getInstance()->flush();
}

std::string TDDHelper::loadStringFromDevice(const std::string &key)
{
	return CCUserDefault::getInstance()->getStringForKey(key.c_str());
}


void TDDHelper::saveFilter(const char *pattern)
{
	sFilterPattern = pattern;
	
	CCUserDefault::getInstance()->setStringForKey(kTDDFilterKey, pattern);
	log("Save filter %s for key=%s", pattern, kTDDFilterKey);

	CCUserDefault::getInstance()->flush();
}

const char *TDDHelper::getFilter()
{
	sFilterPattern = CCUserDefault::getInstance()->getStringForKey(kTDDFilterKey);
	
	//log("Load filter for key=%s result=%s",  kTDDFilterKey, sFilterPattern.c_str());
	
	return sFilterPattern.c_str();
}

std::string TDDHelper::getVersion()
{
	return kLibVersion;
}

std::string TDDHelper::getLibraryName()
{
	return kLibName;
}

void TDDHelper::addAnchorPoint(Node *node, const Color4B &color)
{
//	node->add
	if(node == NULL) {
		return;
	}
	
	GLfloat pointSize = 4;
	
	Layer *layer = LayerColor::create(color, pointSize, pointSize);
	Size size = node->getContentSize();
	Vec2 anchorRatio = node->getAnchorPoint();
	
	float x = size.width * anchorRatio.x - pointSize/2;
	float y = size.height * anchorRatio.y - pointSize/2;
	
	layer->setPosition(Vec2(x, y));
	
	node->addChild(layer);
}

void TDDHelper::addBoundingBox(Node *node, const Color4B &color)
{
	//	node->add
	if(node == NULL) {
		return;
	}
	
//	GLfloat pointSize = 4;
//	
//	Layer *layer = LayerColor::create(color, pointSize, pointSize);
//	Size size = node->getContentSize();
//	Vec2 anchorRatio = node->getAnchorPoint();
//	
//	float x = size.width * anchorRatio.x - pointSize/2;
//	float y = size.height * anchorRatio.y - pointSize/2;
//	
//	layer->setPosition(Vec2(x, y));
//	
//	node->addChild(layer);
}


/*
Layer *TDDHelper::createKeyPadLayer(Object *target, Control::Handler handler)
{
	Layer *layer = Layer::create();
	std::vector<Node *> nodeArray;
	
	Size size = Size(40, 40);
	Point buttonPos[4] = {
		Point(0, 40),
		Point(0, -40),
		Point(-40, 0),
		Point(40, 0),
	};
	
	ControlButton *button;
	
	button = GUIHelper::createButton("UP", target, handler, kButtonUp);
	button->setPreferredSize(size);
	button->setPosition(buttonPos[0]);
	layer->addChild(button);
	
	button = GUIHelper::createButton("DN", target, handler, kButtonDown);
	button->setPreferredSize(size);
	button->setPosition(buttonPos[1]);
	layer->addChild(button);
	
	button = GUIHelper::createButton("LT", target, handler, kButtonLeft);
	button->setPreferredSize(size);
	button->setPosition(buttonPos[2]);
	layer->addChild(button);
	
	button = GUIHelper::createButton("RT", target, handler, kButtonRight);
	button->setPreferredSize(size);
	button->setPosition(buttonPos[3]);
	layer->addChild(button);

	return layer;
} */




const Size TDDHelper::alignMenuItem(Menu *menu, int parentWidth, int numCol, int lineSpace)
{
	Vector<Node *> childrenNode = menu->getChildren();
	
	int width = parentWidth;
	int colWidth = width/numCol;
	
	int x;
	int y = 0;
	int maxH = 0;
	int spacing = lineSpace;
	int totalH = 0;
	int firstX = colWidth/2 + (numCol - 1) * colWidth;
	
	int count = (int) childrenNode.size();
	int remain = (count - 1) % numCol;
	x = remain * colWidth + colWidth/2;
	
	for(int i=(count-1); i>=0; i--) {
		Node *node = childrenNode.at(i);
		MenuItem *item = dynamic_cast<MenuItem *>(node);
		if(item == NULL) {
			continue;
		}
		
		Size itemSize = item->getContentSize();
		// log("menuItem: %f x %f", itemSize.width, itemSize.height);
		
		item->setAnchorPoint(Point(0.5, 0));
		item->setPosition(Point(x, y));
		
		// log("menuItem: %f x %f pos: x=%d y=%d", itemSize.width, itemSize.height, x, y);
		
		x -= colWidth;
		maxH = MAX(maxH, itemSize.height);
		
		if(x < 0) {
			totalH += maxH + spacing;
			y += (maxH + spacing);
			x = firstX;
		}
	}
	
	
	return Size(width, totalH);
}

void TDDHelper::setLabelColor(Label *label, const Color3B &textColor)
{
	label->setColor(textColor);
	label->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
}

void TDDHelper::setAlphaPremultiplied(Node *node)
{
	if(node == NULL) {
		return;
	}
	
	BlendProtocol *ptr = dynamic_cast<BlendProtocol *>(node);
	if(ptr == NULL) {
		return;
	}
	
	ptr->setBlendFunc(BlendFunc::ALPHA_PREMULTIPLIED);
}

#pragma mark - String

std::string TDDHelper::trimString(const std::string &input)
{
	int first = 0;
	unsigned long last = input.size() - 1;
	
	while (first <= last && isspace(input[first])) { first++; }
	while (last >= first && isspace(input[last])) { last--; }
	
	return input.substr(first, (last - first + 1));
}

std::string TDDHelper::replaceString(const std::string &src,
									 const std::string &find,
									 const std::string &replacement)
{
    int i = 0;
    unsigned long len = find.length();
    
    if (len == 0) {
        return src;
    }
    
    string result;
    while(true)
    {
        int start = i;
        i = (int) src.find(find, i);
        
        if(i < 0)
        {
            result += src.substr(start);
            break;
        }
        result += src.substr(start, i - start);
        result += replacement;
        i += len;
    }
	
    return result;
}

std::vector<std::string> TDDHelper::splitString(const std::string& text,
												const char delim, const int numToken)
{
	std::stringstream ss(text);
    std::string item;
	std::string lastToken("");
	std::vector<std::string> tokens;
	int count = 0;
	
	const char delimStr[2] = {delim, '\0'};		// make const char for later use
	
	while (std::getline(ss, item, delim)) {
		if (numToken <= 0 || count < (numToken - 1)) {		// cond1: don't bound the token
			tokens.push_back(item);							// cond2:
		} else {
			if(lastToken.length() == 0) {
				lastToken.append(delimStr);
			}
			lastToken.append(item);
		}
	}
	tokens.push_back(lastToken);
    
	return tokens;
}

std::string TDDHelper::joinString(const std::vector<std::string> &strArray,
										const std::string &sep)
{
	std::string result = "";
	
	for(int i=0; i<strArray.size(); i++) {
		if(i > 0) {
			result.append(sep);
		}
		
		result.append(strArray[i]);
	}
	
	return result;
}

#pragma mark - Scale
float TDDHelper::getBestScale()
{
	
	float designValue = BEST_WIDTH;	// longer one
	Size screenSize = getScreenSize();
	float screenValue = isLandscape() ? screenSize.width : screenSize.height;
	
	return screenValue / designValue;
}

#pragma mark - UI

Label *TDDHelper::createLabel(const std::string &text, const int fontSize, const Color3B &color)
{
	Label *label = Label::createWithSystemFont(text, TDD_FONT_NAME, fontSize);

	setLabelColor(label, color);

	return label;
}