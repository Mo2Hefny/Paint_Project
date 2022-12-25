#include "CFigure.h"

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

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

void CFigure::ChngFill(GfxInfo gfxinfo)
{
	FigGfxInfo.isFilled = gfxinfo.isFilled;
	if (FigGfxInfo.isFilled)
		FigGfxInfo.FillClr = gfxinfo.FillClr;
}