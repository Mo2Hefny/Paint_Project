#include "CTriangle.h"
#include<fstream>

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
	CenterX = (P3.x + P2.x + P1.x) / 3.0;
	CenterY = (P3.y + P2.y + P1.y) / 3.0;
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

void CTriangle::move(int x, int y)
{
	Vertix1.x = x + (Vertix1.x - CenterX);
	Vertix2.x = x + (Vertix2.x - CenterX);
	Vertix3.x = x + (Vertix3.x - CenterX);
	Vertix1.y = y + (Vertix1.y - CenterY);
	Vertix2.y = y + (Vertix2.y - CenterY);
	Vertix3.y = y + (Vertix3.y - CenterY);
	CenterX = x;
	CenterY = y;
}

Point CTriangle::GetCenter() const
{	return Point{ (int)CenterX, (int)CenterY }; }

void CTriangle::Save(ofstream& outfile)
{
	outfile << "TRI" << " " << ID << " " << Vertix1.x << " " << Vertix1.y << " " << Vertix2.x << " " << Vertix2.y << " " << Vertix3.x << " " << Vertix3.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}
CTriangle::CTriangle()
{}
void CTriangle::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Vertix1:(" << Vertix1.x << "," << Vertix1.y << ")  Vertix2:(" << Vertix2.x << "," << Vertix2.y << ")  Vertix3:(" 
		<< Vertix3.x << "," << Vertix3.y <<  ")  Fill Color: " << getFillClrStr() << " Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}
void CTriangle::load(ifstream& infile)
{
	int cx, cy, ex, ey,sx,sy, id;
	infile >> id >> cx >> cy >> ex >> ey >> sx >> sy;
	ID = id;
	Vertix1.x = cx;
	Vertix1.y = cy;
	Vertix2.x = ex;
	Vertix2.y = ey;
	Vertix3.x = sx;
	Vertix3.y = sy;
	CenterX = (Vertix1.x + Vertix2.x + Vertix3.x) / 3.0;
	CenterY = (Vertix1.y + Vertix2.y + Vertix3.y) / 3.0;
	string DrawingColor, FillColor;
	infile >> DrawingColor >> FillColor;
	if (DrawingColor == "RED")
		FigGfxInfo.DrawClr = RED;
	if (DrawingColor == "YELLOW")
		FigGfxInfo.DrawClr = YELLOW;
	if (DrawingColor == "GREEN")
		FigGfxInfo.DrawClr = GREEN;
	if (DrawingColor == "ORANGE")
		FigGfxInfo.DrawClr = ORANGE;
	if (DrawingColor == "BLACK")
		FigGfxInfo.DrawClr = BLACK;
	if (DrawingColor == "BLUE")
		FigGfxInfo.DrawClr = BLUE;
	if (FillColor == "NOTFILLED")
		FigGfxInfo.isFilled = false;
	else
	{
		FigGfxInfo.isFilled = true;
		if (FillColor == "RED")
			FigGfxInfo.FillClr = RED;

		if (FillColor == "YELLOW")
			FigGfxInfo.FillClr = YELLOW;

		if (FillColor == "GREEN")
			FigGfxInfo.FillClr = GREEN;

		if (FillColor == "BLACK")
			FigGfxInfo.FillClr = BLACK;

		if (FillColor == "ORANGE")
			FigGfxInfo.FillClr = ORANGE;

		if (FillColor == "BLUE")
			FigGfxInfo.FillClr = BLUE;
	}
}