Version Note about Simple TDD

Version 2.3.0 *  
---------------------
- TODO: Android build
* Easy Touch handling 



Version 2.2.0   
---------------------
- Easy Menu Customisation
	- setMenuSizeByType(MenuSizeType::HalfHeight1);
	  MenuSizeType: SizeTypeHalfHeight, FullHeight, HalfWidth, FullWidth, OneThirdHeight)

- Test Console: A visual panel that help showing the information on the UI
- Remove the usage of "extension/cocos-ext.h" for GUI building


Version 2.1.0 
---------------------
- Add following methods in TDDBaseTest (for better migration)
	- void toggleStat();
	- void clearNodes();

- Add following methods in TDDBaseTest for Menu Customisation
	- void hideMenu();
	- void setMenuVisible(bool flag);
	- void setMenuColor();
	- void alignMenu();
	- void setMenuSize();
	note: see 'TestMenuTest' for the detail 

- Add unit test conversion script 
	./script/convertTest.py (yourUnitTest.h)

- Convert all tests based on TDDBaseTest
- 


Version 2.0.0 
---------------------
- Refactor the architecture
- Polish the Test main GUI