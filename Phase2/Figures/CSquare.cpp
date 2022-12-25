#include "CSquare.h"

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

void CSquare::PrintInfo(Output* pOut) const
{
	//ostringstream oss;
	//oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Height: "
	//	<< abs(Corner1.y - Corner2.y) << " Width:" << abs(Corner1.x - Corner2.x);
	//pOut->PrintMessage(oss.str());
}