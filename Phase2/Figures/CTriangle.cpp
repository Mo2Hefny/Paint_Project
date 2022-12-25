#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertix1 = P1;
	Vertix2 = P2;
	Vertix3 = P3;
}

bool CTriangle::IsPointInFigure(int x, int y) const
{
	return ((x - Vertix2.x) * (Vertix2.x - x) > 0 && (Vertix2.y - y) * (y - Vertix2.y));
}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawTriangle(Vertix1, Vertix2, Vertix3, FigGfxInfo, Selected);
}

void CTriangle::PrintInfo(Output* pOut) const
{
	//ostringstream oss;
	//oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Height: "
	//	<< abs(Corner1.y - Corner2.y) << " Width:" << abs(Corner1.x - Corner2.x);
	//pOut->PrintMessage(oss.str());
}