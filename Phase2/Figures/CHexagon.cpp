#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
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
void CHexagon::Save(ofstream& outfile)
{
	outfile << "HEXA" << " " << ID << " " << Center.x << " " << Center.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;

}

void CHexagon::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Center:(" << Center.x << "," << Center.y << ")  Length: "
		<< 88 << " Fill Color:" << getFillClrStr() << " Draw Color:" << getDrawClrStr();
	//pOut->PrintMessage(oss.str());
}