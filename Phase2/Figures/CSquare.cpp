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

void CSquare::move(int x, int y)
{
	Center.x = x;
	Center.y = y;
}

Point CSquare::GetCenter() const
{	return Center; }

void CSquare::Save(ofstream& outfile)
{
	outfile << "SQUARE" << " " << ID << " " << Center.x << " " << Center.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}
CSquare::CSquare()
{
	GfxInfo FigGFxInfo;
}
void CSquare::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Center:(" << Center.x << "," << Center.y << ")  Length: " 
		<< 40 << "Fill Color:" << getFillClrStr() << "Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}
void CSquare::load(ifstream&infile)
{
	int cx, cy, id;
	infile >> id >> cx >> cy;
	ID = id;
	Center.x = cx;
	Center.y = cy;
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