#include "mainmenu.h"
#include <easydraw.h>
#include <easyinput.h>

MainMenu::MainMenu(EASYDRAW *DDraw, EASYINPUT *DInput) : DInput(DInput), DDraw(DDraw)
{}

unsigned MainMenu::Show()
{
	while (true)
	{
		DDraw->ClearScreen();
		DDraw->DrawString(10, 10, "press start");
		DDraw->Swap();

		if (DInput->KeyDown(DIK_RETURN))
			break;
	}

	return START;
}