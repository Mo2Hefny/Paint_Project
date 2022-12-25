#include "CRectangle.h"
#include<fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

bool CRectangle::IsPointInFigure(int x, int y) const
{
	return !((x - Corner1.x) * (Corner2.x - x) < 0 || (Corner2.y - y) * (y - Corner1.y) < 0);
}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

void CRectangle::Save(ofstream& outfile)
{
	outfile << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}

void CRectangle::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Height: "
		<< abs(Corner1.y - Corner2.y) << " Width:" << abs(Corner1.x - Corner2.x) << "Fill Color:" << getFillClrStr() << "Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}