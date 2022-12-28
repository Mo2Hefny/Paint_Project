#include "CCircle.h"
#include<fstream>
#include <string>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Edge = P2;
	Radius = sqrt(pow(Center.x - Edge.x, 2) + pow(Center.y - Edge.y, 2));
}

bool CCircle::IsPointInFigure(int x, int y) const
{
	return (pow(Center.x - x, 2) + pow(Center.y - y, 2) <= pow(Center.x - Edge.x, 2) + pow(Center.y - Edge.y, 2));
}

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawCircle(Center, Edge, FigGfxInfo, Selected);
}

void CCircle::move(int x, int y)
{
	Center.x = x;
	Center.y = y;
}
CCircle::CCircle()
{
	GfxInfo FigGFxInfo;
}

Point CCircle::GetCenter() const
{	return Center; }

void CCircle::Save(ofstream& outfile)
{
	outfile << "CIRC" << " " << ID << " " << Center.x << " " << Center.y << " " << Edge.x << " " << Edge.y << " ";
	outfile	<< getDrawClrStr() << " " << getFillClrStr() << endl;
	
	
}


void CCircle::PrintInfo(Output* pOut) const
{
	//ostringstream oss;
	//oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Height: "
	//	<< abs(Corner1.y - Corner2.y) << " Width:" << abs(Corner1.x - Corner2.x);
	//pOut->PrintMessage(oss.str());
}
void CCircle::load(ifstream& infile)
{
	int cx, cy, ex, ey, id;
	infile >> id >> cx >> cy >> ex >> ey;
	ID = id;
	Center.x = cx;
	Center.y = cy;
	Edge.x = ex;
	Edge.y = ey;
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