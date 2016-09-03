#ifdef ENABLE_TDD
//
//  EditBoxTest.m
//	TDD Framework 
//
//
#include "EditBoxTest.h"
#include "TDDHelper.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

void EditBoxTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void EditBoxTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void EditBoxTest::defineTests()
{
	ADD_TEST(testEditBoxStyle);
	ADD_TEST(testEditBox);
	ADD_TEST(testDelegate);
	ADD_TEST(testFontSize);
}

#pragma mark -
#pragma mark Sub Test Definition
void EditBoxTest::testEditBox()
{
	log("testEditBox");
//	EditBox::cr
	Scale9Sprite *bg = Scale9Sprite::create();
	//const Size& size, Scale9Sprite* pNormal9SpriteBg, Scale9Sprite* pPressed9SpriteBg/* = NULL*/, Scale9Sprite* pDisabled9SpriteBg/* = NULL*/)
	EditBox *edit = EditBox::create(Size(200, 60), bg, NULL, NULL);
	edit->setText("testing");
	edit->setPosition(Point(100, 100));
	addChild(edit);
}

void EditBoxTest::testEditBoxStyle()
{
	log("testEditBox");
	//	EditBox::cr
	Scale9Sprite *bg = Scale9Sprite::create();
	bg->addChild(LayerColor::create(Color4B::WHITE, 200, 60));
	
	//const Size& size, Scale9Sprite* pNormal9SpriteBg, Scale9Sprite* pPressed9SpriteBg/* = NULL*/, Scale9Sprite* pDisabled9SpriteBg/* = NULL*/)
	EditBox *edit = EditBox::create(Size(200, 60), bg, NULL, NULL);
	edit->setText("testing");
	edit->setPosition(Point(200, 100));
	edit->setFont("GillSans", 15);
	edit->setFontColor(Color3B::BLACK);
	
	addChild(edit);
}

void EditBoxTest::testDelegate()
{
	log("testEditBox");
	//	EditBox::cr
	Scale9Sprite *bg = Scale9Sprite::create();
	bg->addChild(LayerColor::create(Color4B::WHITE, 200, 60));
	
	//const Size& size, Scale9Sprite* pNormal9SpriteBg, Scale9Sprite* pPressed9SpriteBg/* = NULL*/, Scale9Sprite* pDisabled9SpriteBg/* = NULL*/)
	EditBox *edit = EditBox::create(Size(200, 60), bg, NULL, NULL);
	edit->setText("testing");
	edit->setPosition(Point(200, 100));
	edit->setFont("GillSans", 15);
	edit->setFontColor(Color3B::BLACK);
	edit->setDelegate(this);
	
	addChild(edit);
}

void EditBoxTest::editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox)
{
	log("editBox edit begin");
}
void EditBoxTest::editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox)
{
	log("editBox edit end");
}
void EditBoxTest::editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text)
{
	log("editBox change to [%s]", text.c_str());
}
void EditBoxTest::editBoxReturn(cocos2d::extension::EditBox* editBox)
{
	log("editBox edit return hit");
}

void EditBoxTest::testFontSize()
{
	EditBox *edit;
	
	int fontSize[3] = {
		8, 10, 13
	};
	
	Size size = Size(100, 60);
	
	
	//	EditBox::cr
	
	
	Scale9Sprite *bg;
	int y = 280;
	
	for(int i=0; i<3; i++) {
		int fsize = fontSize[i];
		bg = Scale9Sprite::create();
		bg->addChild(LayerColor::create(Color4B::WHITE, 200, 60));
		
		Vec2 pos = Vec2(100, y);
		
		// with text
		edit = EditBox::create(size, bg, NULL, NULL);
		edit->setFont("Arial", fsize);		// this is important
		edit->setText("Text");
		edit->setPosition(pos);
		edit->setFontColor(Color3B::BLACK);
		edit->setFontSize(fsize);			// only this not working
		addChild(edit);
		
		
		//
		pos.x += size.width + 50;
		
		// only placeholder
		bg = Scale9Sprite::create();
		bg->addChild(LayerColor::create(Color4B::WHITE, 200, 60));
		
		edit = EditBox::create(size, bg, NULL, NULL);
		edit->setFont("Arial", fsize);
		edit->setPlaceholderFont("Arial", fsize);		// this is important
		edit->setPlaceholderFontSize(fsize);
		edit->setPlaceHolder("Place Holder");
		edit->setPosition(pos);
		edit->setFontColor(Color3B::BLACK);
		addChild(edit);
		
		
		// next line
		y -= (size.height + 30);
	}
}

#endif
