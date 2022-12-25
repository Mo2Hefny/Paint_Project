#include "CSquare.h"
#include<fstream>
CSquare::CSquare(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}

bool CSquare::IsPointInFigure(int x, int y) const
{
	int length = 40;
	return (abs(Center.x - x) < length && abs(Center.y - y) < length);
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSquare(Center, FigGfxInfo, Selected);
}

void CSquare::Save(ofstream& outfile)
{
	outfile << "SQUARE" << " " << ID << " " << Center.x << " " << Center.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}

void CSquare::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Center:(" << Center.x << "," << Center.y << ")  Length: " 
		<< 40 << "Fill Color:" << getFillClrStr() << "Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}