#include "CFigure.h"
#include<fstream>
#include<string>

unsigned int CFigure::IDcounter = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID = ++IDcounter;
}
CFigure::CFigure()
{
	Selected = false;
}

GfxInfo CFigure::getGfxInfo() const
{
	if (FigGfxInfo.FillClr != UI.HighlightColor)
		return FigGfxInfo;
	else
		return OldFigGfxInfo;
}

color CFigure::getFillClr() const
{	return FigGfxInfo.FillClr; }

color CFigure::getDrawClr() 
{
	return FigGfxInfo.DrawClr;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IsFilled() const
{	
	if (FigGfxInfo.FillClr != UI.HighlightColor)
		return FigGfxInfo.isFilled; 
	else
		return OldFigGfxInfo.isFilled;
}

void CFigure::ChngDrawClr(color Dclr)
{	
	OldFigGfxInfo.DrawClr = FigGfxInfo.DrawClr;
	FigGfxInfo.DrawClr = Dclr; 
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}

void CFigure::ChngSelectedDraw()
{	FigGfxInfo.DrawClr = OldFigGfxInfo.DrawClr; }

void CFigure::SetIsFilled(bool Fill)
{
	FigGfxInfo.isFilled = Fill;
}

string CFigure::getFillClrStr() const
{
	if (FigGfxInfo.isFilled == false)
		return "NOTFILLED";
	if (FigGfxInfo.FillClr == BLACK)
		return "BLACK";
	if (FigGfxInfo.FillClr == YELLOW)
		return "YELLOW";
	if (FigGfxInfo.FillClr == ORANGE)
		return "ORANGE";
	if (FigGfxInfo.FillClr == RED)
		return "RED";
	if (FigGfxInfo.FillClr == BLUE)
		return "BLUE";
	if (FigGfxInfo.FillClr == GREEN)
		return "GREEN";
	return "NOTFILLED";
}

string CFigure::getDrawClrStr() const
{
	if (FigGfxInfo.DrawClr == BLACK)
		return "BLACK";
	if (FigGfxInfo.DrawClr == YELLOW)
		return "YELLOW";
	if (FigGfxInfo.DrawClr == ORANGE)
		return "ORANGE";
	if (FigGfxInfo.DrawClr == RED)
		return "RED";
	if (FigGfxInfo.DrawClr == BLUE)
		return "BLUE";
	if (FigGfxInfo.DrawClr == GREEN)
		return "GREEN";
}
