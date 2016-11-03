//
//  TDDButton.hpp
//  SimpleTDD
//
//  Created by Ken Lee on 31/10/2016.
//
//

#ifndef TDDButton_hpp
#define TDDButton_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

class CC_GUI_DLL TDDButton : public Layout
{
public:
	CREATE_FUNC(TDDButton);
	
	/**
	 * Default constructor.
	 */
	TDDButton();
	
	/**
	 * Default destructor.
	 *
	 * @lua NA
	 */
	virtual ~TDDButton();
	
	
	virtual bool init() override;
	
	/**
	 * Change the content of button's title.
	 *@param text The title in std::string.
	 */
	void setTitleText(const std::string& text);
	
	/**
	 * Query the button title content.
	 *@return Get the button's title content.
	 */
	const std::string getTitleText() const;
	
	virtual void setContentSize(const Size &size);

	/**
	 * Change the color of button's title.
	 *@param color The title color in Color3B.
	 */
	void setTitleColor(const Color3B& color);
	
	/**
	 * Query the button title color.
	 *@return Color3B of button title.
	 */
	Color3B getTitleColor() const;

	
	
	/**
	 * Change the font size of button's title
	 *@param size Title font size in float.
	 */
	void setTitleFontSize(float size);
	
	/**
	 * Query the font size of button title
	 *@return font size in float.
	 */
	float getTitleFontSize() const;
	
protected:
	// svirtual void updateContentSize() override;
	void updateButtonPosition();
	void sendClickToButton(TouchEventType eventType);
	
private:
	//Layout *mBackgroundLayout;
	Button *mButton;
};

#endif /* TDDButton_hpp */
