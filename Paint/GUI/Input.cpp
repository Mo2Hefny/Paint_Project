#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQR: return DRAW_SQR;
			case ITM_TRI: return DRAW_TRI;
			case ITM_CRCL: return DRAW_CRCL;
			case ITM_HEX:	return DRAW_HEX;
			case ITM_SELECT:	return DRAW_SELECT;
			case ITM_FillCol:	return DRAW_FillCol;
			case ITM_DrawCol:	return DRAW_DrawCol;
			case CLR_BLACK:	return DRAW_BLACK;
			case CLR_YELLOW:	return DRAW_YELLOW;
			case CLR_ORANGE:	return DRAW_ORANGE;
			case CLR_RED:	return DRAW_RED;
			case CLR_BLUE:	return DRAW_BLUE;
			case CLR_GREEN:	return DRAW_GREEN;
			case ITM_MOVE:	return DRAW_MOVE;
			case ITM_DEL: return DRAW_DEL;
			case ITM_UNDO: return DRAW_UNDO;
			case ITM_REDO: return DRAW_REDO;
			case ITM_CLEAR: return DRAW_CLEAR;
			case ITM_StartRec:	return DRAW_StartRec;
			case ITM_StopRec:	return DRAW_StopRec;
			case ITM_PlayRec:	return DRAW_PlayRec;
			case ITM_SAVE:	return DRAW_SAVE;
			case ITM_LOAD:	return DRAW_LOAD;
			case ITM_SwitchPlay:	return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		///TODO:
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case PLAY_ITM_TYPE:	return PLAY_TYPE;
			case PLAY_ITM_FILL:	return PLAY_FILL;
			case PLAY_ITM_TypeFill:	return PLAY_TypeFill;
			case PLAY_ITM_SwitchDraw:	return TO_DRAW;
			case PLAY_ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}
/////////////////////////////////

Input::~Input()
{
}
