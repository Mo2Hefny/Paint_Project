#include "CCircle.h"
#include<fstream>
CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Center = P1;
	Edge = P2;
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
void CCircle::Save(ofstream& outfile)
{
	outfile << "CIRC" << " " << Center.x << " " << Center.y << " " << Edge.x << " " << Edge.y << " ";
	if (FigGfxInfo.DrawClr == YELLOW)
		outfile << "YELLOW"<<" ";
	if (FigGfxInfo.DrawClr == RED)
		outfile << "RED"<<" ";
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


void CCircle::PrintInfo(Output* pOut) const
{
	//ostringstream oss;
	//oss << "ID:" << ID << "\t Corner1:(" << Corner1.x << "," << Corner1.y << ")  Corner2:(" << Corner2.x << "," << Corner2.y << ")  Height: "
	//	<< abs(Corner1.y - Corner2.y) << " Width:" << abs(Corner1.x - Corner2.x);
	//pOut->PrintMessage(oss.str());
}