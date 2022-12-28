#include "CCircle.h"
#include<fstream>
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
	Edge.x = x + Radius;
	Edge.y = Center.y;
}

Point CCircle::GetCenter() const
{	return Center; }

void CCircle::PrintInfo(Output* pOut) const
{
	ostringstream oss;
	oss << "ID:" << ID << "\t Center:(" << Center.x << "," << Center.y << ")  Radius: "
		<< Radius << " Area:" << 3.14 * pow(Radius, 2)
		<< " Fill Color:" << getFillClrStr() << " Draw Color:" << getDrawClrStr();
	pOut->PrintMessage(oss.str());
}

void CCircle::Save(ofstream& outfile)
{
	outfile << "CIRC" << " " << ID << " " << Center.x << " " << Center.y << " " << Edge.x << " " << Edge.y << " "
		<< getDrawClrStr() << " " << getFillClrStr() << endl;
}