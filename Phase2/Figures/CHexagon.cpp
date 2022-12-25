#include "CHexagon.h"
#include<fstream>
CHexagon::CHexagon(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
}


void CHexagon::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawHex(Center, FigGfxInfo, Selected);
}
void CHexagon::Save(ofstream& outfile)
{
	outfile << "HEXA" << " " << Center.x << " " << Center.y << " ";
	if (FigGfxInfo.DrawClr == YELLOW)
		outfile << "YELLOW" << " ";
	if (FigGfxInfo.DrawClr == RED)
		outfile << "RED" << " ";
	if (FigGfxInfo.DrawClr == BLACK)
		outfile << "BLACK" << " ";
	if (FigGfxInfo.DrawClr == ORANGE)
		outfile << "ORANGE" << " ";
	if (FigGfxInfo.DrawClr == BLUE)
		outfile << "BLUE" << " ";
	if (FigGfxInfo.DrawClr == GREEN)
		outfile << "GREEN" << " ";
	if (FigGfxInfo.isFilled)
	{
		if (FigGfxInfo.FillClr == YELLOW)
			outfile << "YELLOW" << endl;
		if (FigGfxInfo.FillClr == RED)
			outfile << "RED" << endl;
		if (FigGfxInfo.FillClr == BLACK)
			outfile << "BLACK" << endl;
		if (FigGfxInfo.FillClr == ORANGE)
			outfile << "ORANGE" << endl;
		if (FigGfxInfo.FillClr == BLUE)
			outfile << "BLUE" << endl;
		if (FigGfxInfo.FillClr == GREEN)
			outfile << "GREEN" << endl;
	}
	else
		outfile << "NOTFILLED" << endl;

}