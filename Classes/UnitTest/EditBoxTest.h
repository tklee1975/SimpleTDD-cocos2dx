#ifdef ENABLE_TDD
//
//  EditBoxTest.h
//
//
#ifndef __TDD_EditBoxTest__
#define __TDD_EditBoxTest__

// Include Header

#include "TDDBaseTest.h"

// Class Declaration 
class EditBoxTest : public TDDBaseTest,
		public cocos2d::extension::EditBoxDelegate
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	
	// public cocos2d::extension::EditBoxDelegate
	virtual void editBoxEditingDidBegin(cocos2d::extension::EditBox* editBox);
    virtual void editBoxEditingDidEnd(cocos2d::extension::EditBox* editBox);
    virtual void editBoxTextChanged(cocos2d::extension::EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(cocos2d::extension::EditBox* editBox);
private:
	void testEditBox();
	void testEditBoxStyle();
	void testDelegate();
	void testFontSize();
}; 

#endif

#endif
