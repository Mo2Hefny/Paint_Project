#include "CFigure.h"
#include<fstream>
#include<string>

unsigned int CFigure::IDcounter = 0;

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	Hidden = false;
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
{	
	Selected = s; 
	if (s)
	{
		OldFigGfxInfo.DrawClr = FigGfxInfo.DrawClr;
		FigGfxInfo.DrawClr = UI.HighlightColor;
	}
	else if (FigGfxInfo.DrawClr == UI.HighlightColor)
		FigGfxInfo.DrawClr = OldFigGfxInfo.DrawClr;
	else
		OldFigGfxInfo.DrawClr = FigGfxInfo.DrawClr;
}

void CFigure::Hide(bool mode)
{
	Hidden = mode;
	if (mode)
	{
		OldFigGfxInfo = FigGfxInfo;
		FigGfxInfo.isFilled = false;
		FigGfxInfo.DrawClr = UI.BkGrndColor;
	}
	else
	{
		FigGfxInfo = OldFigGfxInfo;
	}
}

void CFigure::Hide(bool mode)
{	Hidden = mode; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IsFilled() const
{	return FigGfxInfo.isFilled; }

bool CFigure::IsHidden() const
{	return Hidden; }

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

void CFigure::SetIsFilled(bool Fill)
{	FigGfxInfo.isFilled = Fill; }

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

int CFigure::get_ID() const
{
	return ID;
}

string CFigure::getDrawClrStr() const
{
	color Draw;
	if (FigGfxInfo.DrawClr == UI.HighlightColor)
	{
		Draw = OldFigGfxInfo.DrawClr;
	}
	else
		Draw = FigGfxInfo.DrawClr;
	if (Draw == BLACK)
		return "BLACK";
	if (Draw == YELLOW)
		return "YELLOW";
	if (Draw == ORANGE)
		return "ORANGE";
	if (Draw == RED)
		return "RED";
	if (Draw == BLUE)
		return "BLUE";
	if (Draw == GREEN)
		return "GREEN";
}
