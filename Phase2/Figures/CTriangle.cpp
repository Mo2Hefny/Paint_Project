#include "CTriangle.h"
#include<fstream>
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
}


void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}
void CTriangle::Save(ofstream& outfile)
{
	outfile << "TRI" << " " << Vertix1.x << " " << Vertix1.y << " " << Vertix2.x << " " << Vertix2.y << " " << Vertix3.x << " " << Vertix3.y << " ";
	if (FigGfxInfo.DrawClr == YELLOW)
		outfile << "YELLOW" << " ";
	if (FigGfxInfo.DrawClr == RED)
		outfile << "RED" << " ";
	if (FigGfxInfo.DrawClr == BLACK)
		outfile << "BLACK" << " ";
	if (FigGfxInfo.DrawClr == ORANGE)
		outfile << "ORANGE" << " ";
	if (FigGfxInfo.DrawClr == BLUE)
		outfile << "BLUE" << " ";
	if (FigGfxInfo.DrawClr == GREEN)
		outfile << "GREEN" << " ";
	if (FigGfxInfo.FillClr == YELLOW)
		outfile << "YELLOW" << endl;
	if (FigGfxInfo.FillClr == RED)
		outfile << "RED" << endl;
	if (FigGfxInfo.FillClr == BLACK)
		outfile << "BLACK" << endl;
	if (FigGfxInfo.FillClr == ORANGE)
		outfile << "ORANGE" << endl;
	if (FigGfxInfo.FillClr == BLUE)
		outfile << "BLUE" << endl;
	if (FigGfxInfo.FillClr == GREEN)
		outfile << "GREEN" << endl;
}