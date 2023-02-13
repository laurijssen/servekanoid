#ifndef __MAINMENU_H__
#define __MAINMENU_H__

class EASYINPUT;
class EASYDRAW;

class MainMenu
{
	EASYINPUT *DInput;
	EASYDRAW *DDraw;
public:
	enum { QUIT, START };

	MainMenu(EASYDRAW *DDraw, EASYINPUT *DInput);

	unsigned Show();
};

#endif //__MAINMENU_H__