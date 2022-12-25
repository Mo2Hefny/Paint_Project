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

GfxInfo CFigure::getGfxInfo() const
{
	return FigGfxInfo;
}

color CFigure::getFillClr() const
{
	return FigGfxInfo.FillClr;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

bool CFigure::IsFilled() const
{	return FigGfxInfo.isFilled; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::ChngFill(bool c)
{
	FigGfxInfo.isFilled = c;
}