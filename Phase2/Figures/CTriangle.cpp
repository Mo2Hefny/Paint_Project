#include "CTriangle.h"
#include<fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
}

bool CTriangle::IsPointInFigure(int x, int y) const
{
	double Area1 = abs((x * (Vertix1.y - Vertix2.y) + Vertix1.x * (Vertix2.y - y) + Vertix2.x * (y - Vertix1.y)) / 2.0);
	double Area2 = abs((x * (Vertix3.y - Vertix2.y) + Vertix3.x * (Vertix2.y - y) + Vertix2.x * (y - Vertix3.y)) / 2.0);
	double Area3 = abs((x * (Vertix1.y - Vertix3.y) + Vertix1.x * (Vertix3.y - y) + Vertix3.x * (y - Vertix1.y)) / 2.0);
	double AreaT = abs((Vertix3.x * (Vertix1.y - Vertix2.y) + Vertix1.x * (Vertix2.y - Vertix3.y) + Vertix2.x * (Vertix3.y - Vertix1.y)) / 2.0);
	return (AreaT == Area1 + Area2 + Area3);
}

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}

void CTriangle::Save(ofstream& outfile)
{
	outfile << "TRI" << " " << ID << " " << Vertix1.x << " " << Vertix1.y << " " << Vertix2.x << " " << Vertix2.y << " " << Vertix3.x << " " << Vertix3.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}

void CTriangle::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Vertix1:(" << Vertix1.x << "," << Vertix1.y << ")  Vertix2:(" << Vertix2.x << "," << Vertix2.y << ")  Vertix3:(" 
		<< Vertix3.x << "," << Vertix3.y <<  ")  Fill Color: " << getFillClrStr() << " Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}