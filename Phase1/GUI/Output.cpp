#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	pWind->SetPen(WHITE, UI.ToolBarHeight);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);
	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_SHAPE] = "images\\MenuItems\\shapes.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_FillCol] = "images\\MenuItems\\highlight_color.jpg";
	MenuItemImages[ITM_DrawCol] = "images\\MenuItems\\border_color.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\move.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\delete_selected.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\undo 2.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\redo 2.jpg";
	MenuItemImages[ITM_CLEAR] = "images\\MenuItems\\delete_all.jpg";
	MenuItemImages[ITM_StartRec] = "images\\MenuItems\\record.jpg";
	MenuItemImages[ITM_StopRec] = "images\\MenuItems\\stop.jpg";
	MenuItemImages[ITM_PlayRec] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_SwitchPlay] = "images\\MenuItems\\play_mode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\exit.jpg";
	string ShapeImages[NUM_SHAPES];
	string ColorImages[NUM_COL];
	if (UI.InterfaceMode == MODE_SHAPE)
	{
		ShapeImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
		ShapeImages[ITM_SQR] = "images\\MenuItems\\square.jpg";
		ShapeImages[ITM_TRI] = "images\\MenuItems\\triangle.jpg";
		ShapeImages[ITM_CRCL] = "images\\MenuItems\\circle.jpg";
		ShapeImages[ITM_HEX] = "images\\MenuItems\\hexagon.jpg";
		ShapeImages[SHAPE_BACK] = "images\\MenuItems\\back.jpg";
	}
	else if (UI.InterfaceMode == MODE_COL)
	{
		ColorImages[CLR_BLACK] = "images\\MenuItems\\black.jpg";
		ColorImages[CLR_YELLOW] = "images\\MenuItems\\yellow 2.jpg";
		ColorImages[CLR_ORANGE] = "images\\MenuItems\\orange.jpg";
		ColorImages[CLR_RED] = "images\\MenuItems\\red.jpg";
		ColorImages[CLR_BLUE] = "images\\MenuItems\\blue.jpg";
		ColorImages[CLR_GREEN] = "images\\MenuItems\\green.jpg";
		ColorImages[CLR_BACK] = "images\\MenuItems\\back.jpg";
	}
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0, j = 0; i < DRAW_ITM_COUNT; i++)
	{
		if (UI.InterfaceMode == MODE_SHAPE && i == 1)
		{
			for (int k = 0; k < NUM_SHAPES; k++)
				pWind->DrawImage(ShapeImages[k], j++ * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		}
		if (UI.InterfaceMode == MODE_COL && i == ITM_DrawCol + 1)
		{
			for (int k = 0; k < NUM_COL; k++)
				pWind->DrawImage(ColorImages[k], j++ * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		}
		pWind->DrawImage(MenuItemImages[i], j++ * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	pWind->SetPen(WHITE, UI.ToolBarHeight);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[PLAY_ITM_TYPE] = "images\\MenuItems\\by_shape.jpg";
	MenuItemImages[PLAY_ITM_FILL] = "images\\MenuItems\\by_color.jpg";
	MenuItemImages[PLAY_ITM_TypeFill] = "images\\MenuItems\\by_both.jpg";
	MenuItemImages[PLAY_ITM_SwitchDraw] = "images\\MenuItems\\draw_mode.jpg";
	MenuItemImages[PLAY_ITM_EXIT] = "images\\MenuItems\\exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}
void Output::DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected) const
{
	Point P2;
	float length = 40.0;
	P2.x = P1.x - length;
	P2.y = P1.y - length;
	Point P3;
	P3.x = P1.x + length;
	P3.y = P1.y + length;	
	DrawRect(P2, P3, SquareGfxInfo, selected);
}
void Output::DrawTriangle(Point P1, Point P2, Point P3, GfxInfo TriangleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriangleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}
void Output::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;
	float radius = sqrt(pow((P1.x - P2.x), 2) + pow((P1.y - P2.y), 2));
	pWind->DrawCircle(P1.x, P1.y, radius, style);
}
void Output::DrawHex(Point C, GfxInfo HexGfxInfo, bool selected) const
{
	color DrawingClr;
	int l = 80;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexGfxInfo.FillClr);
	}
	else
		style = FRAME;

	int X[6], Y[6];
	X[0] = C.x - l / 2; X[1] = X[5] = C.x - (l / 4); X[2] = X[4] = C.x + (l / 4); X[3] = C.x + l / 2;
	Y[0] = Y[3] = C.y; Y[1] = Y[2] = C.y + (l/2); Y[4] = Y[5] = C.y -( l/2);
	pWind->DrawPolygon(X, Y, 6, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

