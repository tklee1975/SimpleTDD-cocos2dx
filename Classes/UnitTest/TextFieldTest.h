#ifdef ENABLE_TDD
//
//  TextFieldTest.h
//
//
#ifndef __TDD_TextFieldTest__
#define __TDD_TextFieldTest__

// Include Header

#include "TDDBaseTest.h"


#include "ui/CocosGUI.h"


// Class Declaration
class TextFieldTest : public TDDBaseTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void defineTests();
	virtual void willRunTest(const std::string &name);	// before run a test
	virtual void didRunTest(const std::string &name);	// after run a test
	
private:
	void testSample();
	void testCustomTextField();
	void testClearText();
	
private:
	ui::TextField *mTextField;
};

#endif

#endif
