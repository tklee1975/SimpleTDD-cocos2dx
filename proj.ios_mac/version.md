Version Note about Simple TDD

Version 2.2.0 
---------------------
- TODO: Android build

Version 2.1.0 * 
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