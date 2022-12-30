#include "CRectangle.h"
#include<fstream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	width = abs(Corner1.x - Corner2.x);
	height = abs(Corner1.y - Corner2.y);
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
}

CRectangle::CRectangle()
{
	GfxInfo FigGFxInfo;
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

void CRectangle::move(int x, int y)
{
	Corner1.x = x - width / 2;
	Corner2.x = x + width / 2;
	Corner1.y = y + height / 2;
	Corner2.y = y - height / 2;
	Center.x = x;
	Center.y = y;
}

Point CRectangle::GetCenter() const
{	return Center; }

void CRectangle::Save(ofstream& outfile)
{
	outfile << "RECT" << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}

void CRectangle::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Height: "
		<< height << " Width:" << width << "Fill Color:" << getFillClrStr() << "Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}
void CRectangle::load(ifstream& infile)
{
	int cx, cy, ex, ey, id;
	infile >> id >> cx >> cy >> ex >> ey;
	ID = id;
	Corner1.x = cx;
	Corner1.y = cy;
	Corner2.x = ex;
	Corner2.y = ey;
	width = abs(Corner1.x - Corner2.x);
	height = abs(Corner1.y - Corner2.y);
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