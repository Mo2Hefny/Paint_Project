#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
	ID = IDcounter;
}

bool CHexagon::IsPointInFigure(int x, int y) const
{
	int Dx = abs(Center.x - x);
	int Dy = abs(Center.y - y);
	if (Dx > 23 * 2 || Dy > 46) return false;
	return (46 * 2 * 30 - 46 * Dx - 2 * 30 * Dy >= 0);
}
void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}

void CHexagon::move(int x, int y)
{
	Center.x = x;
	Center.y = y;
}

Point CHexagon::GetCenter() const
{	return Center; }

void CHexagon::Save(ofstream& outfile)
{
	outfile << "HEXA" << " " << ID << " " << Center.x << " " << Center.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;

}
CHexagon::CHexagon()
{
	GfxInfo FigGFxInfo;
}

void CHexagon::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Center:(" << Center.x << "," << Center.y << ")  Length: "
		<< 88 << " Fill Color:" << getFillClrStr() << " Draw Color:" << getDrawClrStr();
	//pOut->PrintMessage(oss.str());
}
void CHexagon::load(ifstream& infile)
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
